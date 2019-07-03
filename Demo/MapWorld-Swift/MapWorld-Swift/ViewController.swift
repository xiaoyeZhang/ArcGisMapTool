//
//  ViewController.swift
//  MapWorld-Swift
//
//  Created by zhangxiaoye on 2019/6/27.
//  Copyright © 2019 zhangxiaoye. All rights reserved.
//

import UIKit
import ArcGIS
import Masonry

class ViewController: UIViewController {

    lazy var mapView: AGSMapView = {
        
        let tmpMapView = AGSMapView.init()
        
        tmpMapView.callout.delegate = self as? AGSCalloutDelegate
        tmpMapView.touchDelegate = self as? AGSGeoViewTouchDelegate
        tmpMapView.isAttributionTextVisible = false//去掉logo
        
        tmpMapView.interactionOptions.isRotateEnabled  = false // 禁用地图旋转
        
        return tmpMapView
    }()
    
    private var map: AGSMap!
    
    var polyline:GISMapTool!
    
    var featureArr:NSArray!
    
    var TDT_typeDic:NSMutableDictionary!
    
    var locationBtn:UIButton = UIButton()
    
    var MeasuringLengthBtn:UIButton = UIButton()
    var MeasuringAreaBtn:UIButton = UIButton()

    
    var otherBtn:UIButton = UIButton()

//
//    var calloutView:UIView

    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
        
        self.view.addSubview(self.mapView)
        
        mapView.mas_makeConstraints { (make :MASConstraintMaker?) in
            make?.edges.mas_equalTo()
        }
        
        TDT_typeDic = NSMutableDictionary()
        
        self.map = AGSMap()

        self.polyline = GISMapTool.init().initWithAGSMapView(mapView: self.mapView)

        self.loadingSlyMap(type: TianDiTuLayerType.TDT_VECTOR)
        
        locationBtn.setImage(UIImage.init(named: "定位"), for: .normal)
        
//        self.map.operationalLayers.addObjects(from: TDT_typeDic.object(forKey: TianDiTuLayerType.TDT_VECTOR) as! [Any])
//        
//        self.mapView.map = self.map
        
        locationBtn.addTarget(self, action: #selector(LocationClick), for: .touchUpInside)
        self.view.addSubview(locationBtn)

        locationBtn.mas_makeConstraints { (make:MASConstraintMaker?) in
            
            make?.left.mas_equalTo()(14)
            make?.bottom.mas_equalTo()(-25-49)
            make?.width.height().mas_equalTo()(42)
            
        }
        
        self.LocationClick(sender: locationBtn)

        
//        self.MeasuringLengthClick(sender: locationBtn)
        
        self.view.addSubview(MeasuringLengthBtn)
        MeasuringLengthBtn.OperationType = NSString(string: ZXYBtnOperationType.ZXYMapViewOperationTypeLine.rawValue) as String
        MeasuringLengthBtn.OperationGroup = "1";
        MeasuringLengthBtn.setImage(UIImage.init(named: "测量"), for: .normal)
        MeasuringLengthBtn.setImage(UIImage.init(named: "测量-1"), for: .selected)
        MeasuringLengthBtn.addTarget(self, action: #selector(BtnIsClick), for: .touchUpInside)

        MeasuringLengthBtn.mas_makeConstraints { (make:MASConstraintMaker?) in
            
            make?.right.mas_equalTo()(-13)
            make?.top.mas_equalTo()(111)
            make?.width.height().mas_equalTo()(42)
            
        }
        
        self.view.addSubview(MeasuringAreaBtn)
        MeasuringAreaBtn.OperationType = NSString(string: ZXYBtnOperationType.ZXYMapViewOperationTypeArea.rawValue) as String
        MeasuringAreaBtn.OperationGroup = "1";
        MeasuringAreaBtn.setImage(UIImage.init(named: "面积测量"), for: .normal)
        MeasuringAreaBtn.setImage(UIImage.init(named: "面积测量-1"), for: .selected)
        MeasuringAreaBtn.addTarget(self, action: #selector(BtnIsClick), for: .touchUpInside)

        MeasuringAreaBtn.mas_makeConstraints { (make:MASConstraintMaker?) in
            
            make?.right.mas_equalTo()(-13)
            make?.top.mas_equalTo()(MeasuringLengthBtn.mas_bottom)?.offset()(5)
            make?.width.height().mas_equalTo()(42)
            
        }
        
        otherBtn.backgroundColor = UIColor.white

        otherBtn.setTitle("图层", for: .normal)
        otherBtn.setTitleColor(UIColor.black, for: .normal)
        otherBtn.addTarget(self, action: #selector(closest), for: .touchUpInside)
        self.view.addSubview(otherBtn)
        
        otherBtn.mas_makeConstraints { (make:MASConstraintMaker?) in
            
            make?.right.mas_equalTo()(-13)
            make?.top.mas_equalTo()(MeasuringAreaBtn.mas_bottom)?.offset()(5)
            make?.width.height().mas_equalTo()(42)
            
        }
        
        
    }
    
    func loadingSlyMap(type:TianDiTuLayerType) {
        
        let tdtInfo = TianDiTuLayerInfo.init().initwithlayerType(layerType: type, sptype: TianDiTuSpatialReferenceType.TDT_MERCATOR)
        
        let tdtannoInfo = TianDiTuLayerInfo.init().initwithlayerType(layerType: type, lan: TianDiTuLanguageType.TDT_CN, sptype: TianDiTuSpatialReferenceType.TDT_MERCATOR)
        
        let ltl1 = TianDiTuLayer(tiandituLayerInfo: tdtInfo, layerType: type)
        
        let ltl2 = TianDiTuLayer(tiandituLayerInfo: tdtannoInfo, layerType: type)
        
        let ltlArr = [ltl1,ltl2]
        
//        self.map.operationalLayers.addObjects(from: ltlArr)
        
        self.map.basemap.baseLayers.setArray(ltlArr)
        
        self.mapView.map = self.map
        
//        TDT_typeDic.setValue(ltlArr, forKey: "TDT_VECTOR")
        
    }
    
    @objc func BtnIsClick(sender:UIButton) -> Void{
     
        sender.isSelected = !sender.isSelected
        
        for v:UIView in self.view.subviews {

            if v.isKind(of: UIButton.self){

                if (v as! UIButton).OperationType != sender.OperationType{

                    if (v as! UIButton).OperationGroup == sender.OperationGroup {

                        if (v as! UIButton).isSelected{

                            self.polyline.removeObjectForKey(key: (v as! UIButton).OperationType as Any)
                            (v as! UIButton).isSelected = false
                        }
                    }
                }
            }
        }
        
        
        if sender.isSelected {
            
            if sender.OperationType == ZXYBtnOperationType.ZXYMapViewOperationTypeLine.rawValue{
                
                self.mapView.callout.dismiss()
                self.MeasuringLengthClick(sender: sender)
                
            }else if sender.OperationType == ZXYBtnOperationType.ZXYMapViewOperationTypeArea.rawValue{
                
                self.mapView.callout.dismiss()
                self.MeasuringAreaClick(sender: sender)
                
            }else{
                
            }
        }else{
            
            self.polyline.removeObjectForKey(key: sender.OperationType as Any)
        }
        
        
    }
    
    /**
     点击定位
     
     @param sender 点位Btn
     */
    
    @objc func LocationClick(sender:UIButton) -> Void {
        
        self.mapView.setViewpointScale(10000, completion: nil)

        self.mapView.locationDisplay.dataSource.start(completion: nil)

        self.mapView.locationDisplay.autoPanMode = .recenter
        
    }
    
    
    /**
     绘制长度
     
     @param sender 长度Btn
     */
    
    
    @objc func MeasuringLengthClick(sender:UIButton) -> Void {
        
        self.polyline.createPolyline(mapView: self.mapView)

        self.polyline.PolylineBuilderBlock = { (polylineBuilder:AGSPolylineBuilder) in

            let distance:Double = GISMapTool.MeasureDistanceOnTheMapView(polylineBuilder: polylineBuilder)

            if distance > 1000 {
                
                self.polyline.resultTextSymbol(resultText: String(format: "%.2f", Float(distance)/1000) + "千米")
                
            }else{
                self.polyline.resultTextSymbol(resultText: String(format: "%.2f", Float(distance)) + "米")
                
            }
        }

    }

    @objc func MeasuringAreaClick(sender:UIButton) -> Void {
        
        self.polyline.createPolygons(mapView: self.mapView)

        self.polyline.PolygonsBuilderBlock = { (polyBuilder:AGSPolygonBuilder) in


            let area:Double = GISMapTool.MeasureAreaOnTheMapView(polyBuilder: polyBuilder)
            
            if area > 10000 {

                self.polyline.resultTextSymbol(resultText: String(format: "%.2f", Float(area/10000)) + "公顷")

            }else{
                self.polyline.resultTextSymbol(resultText: String(format: "%.2f", Float(area)) + "平方米")

            }


        }

    }
    
    
    @objc func closest(sender:UIButton) -> Void {
       
        self.polyline.removeResourceLayerForKey(key: "1")
        
        self.polyline.AddResourceLayer(mapView: self.mapView, scale: 0, layerId: "1", url: "http://58.215.18.176:6080/arcgis/rest/services/WXNY/YQJS/MapServer/0")
        
        self.polyline.CalloutForGraphicBlock = { (featureArr:NSArray,tapLocation:AGSPoint,featureLayer:AGSFeatureLayer) in
            
            self.showCalloutForGraphic(featureArr: featureArr, tapLocation: tapLocation)
        }

        
    }
    
    func showCalloutForGraphic(featureArr:NSArray,tapLocation:AGSPoint) -> Void {
        
        self.featureArr = featureArr
     
        let field : AGSFeature = self.featureArr.object(at: 0) as! AGSFeature;
        
        self.polyline.showCalloutCustomView(customView: nil, scale: 0, feature: field, tapLocation: field.geometry!.extent.center)
    }
    
}

