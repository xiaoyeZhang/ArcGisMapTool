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
    
//    var locationBtn:UIButton
//    
//    var calloutView:UIView

    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
        
        self.view.addSubview(self.mapView)
        
        mapView.mas_makeConstraints { (make :MASConstraintMaker?) in
            make?.edges.mas_equalTo()
        }
        
        self.map = AGSMap()
        
        self.loadingSlyMap(type: TianDiTuLayerType.TDT_VECTOR)
        
        
        let ddd:UIButton = UIButton()
        
        self.LocationClick(sender: ddd)

        self.polyline = GISMapTool.init().initWithAGSMapView(mapView: self.mapView)
        
        self.MeasuringLengthClick(sender: ddd)
     
    }
    
    func loadingSlyMap(type:TianDiTuLayerType) {
        
        let tdtInfo = TianDiTuLayerInfo.init().initwithlayerType(layerType: type, sptype: TianDiTuSpatialReferenceType.TDT_MERCATOR)
        
        let tdtannoInfo = TianDiTuLayerInfo.init().initwithlayerType(layerType: type, lan: TianDiTuLanguageType.TDT_CN, sptype: TianDiTuSpatialReferenceType.TDT_MERCATOR)
        
        let ltl1 = TianDiTuLayer(tiandituLayerInfo: tdtInfo, layerType: type)
        
        let ltl2 = TianDiTuLayer(tiandituLayerInfo: tdtannoInfo, layerType: type)
        
        self.map.operationalLayers.addObjects(from: [ltl1,ltl2])
        
        self.mapView.map = self.map
        
    }
    
    /**
     点击定位
     
     @param sender 点位Btn
     */
    
    func LocationClick(sender:UIButton) -> Void {
        
        self.mapView.setViewpointScale(10000, completion: nil)
        
        self.mapView.locationDisplay.dataSource.start(completion: nil)
        
        self.mapView.locationDisplay.autoPanMode = .recenter
    }
    
    /**
     绘制长度
     
     @param sender 长度Btn
     */
    
    
    func MeasuringLengthClick(sender:UIButton) -> Void {
        
//        self.polyline.createPolyline(mapView: self.mapView)
//
//        self.polyline.PolylineBuilderBlock = { (polylineBuilder:AGSPolylineBuilder) in
//
//
//            let distance:Double = GISMapTool.MeasureDistanceOnTheMapView(polylineBuilder: polylineBuilder)
//
//
//            print(distance)
//
//            self.polyline.resultTextSymbol(resultText: "distance as! String")
//
//        }
//
        
//        self.polyline.removeResourceLayerForKey(key: "1")
        
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

