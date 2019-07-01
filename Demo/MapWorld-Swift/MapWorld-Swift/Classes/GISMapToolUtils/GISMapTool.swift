//
//  GISMapTool.swift
//  MapWorld-Swift
//
//  Created by zhangxiaoye on 2019/6/27.
//  Copyright © 2019 zhangxiaoye. All rights reserved.
//

import UIKit
import ArcGIS

typealias PolylineBuilderBlock = (AGSPolylineBuilder) ->()

typealias PolygonsBuilderBlock = (AGSPolygonBuilder) ->()

typealias CalloutForGraphicBlock = (NSArray,AGSPoint,AGSFeatureLayer) ->()

typealias GraphicsOverlayBlock = (NSArray,AGSPoint) ->()

class GISMapTool: NSObject,AGSGeoViewTouchDelegate,AGSCalloutDelegate{

    var lineColor:UIColor!  /** 线颜色 */
    var lineWidth:CGFloat!  /** 线宽 */
    var nodeIconImg:UIImage!  /** 节点图标 */
    var selectionColor:UIColor!  /** 用于在选定内容周围绘制光环的颜色。默认为青色。 */

    var PolylineBuilderBlock:PolylineBuilderBlock!   /**  返回AGSPolylineBuilder 类型(画线)*/
    
    var PolygonsBuilderBlock:PolygonsBuilderBlock!   /**  返回AGSPolygonBuilder 类型 (画多边形) */

    var CalloutForGraphicBlock:CalloutForGraphicBlock!   /**  返回点击图层资源数组 类型*/

    var GraphicsOverlayBlock:GraphicsOverlayBlock!   /**  返回点击地点结果 */
    
    private var mapView:AGSMapView!
    private var OperationTypeArr:NSMutableArray!
    private var OperationTypeDic:NSMutableDictionary!
    private var AdressOverlayer:AGSGraphicsOverlay!
    private var overlayer:AGSGraphicsOverlay!
    private var StartOverlayer:AGSGraphicsOverlay!
    private var EndOverlayer:AGSGraphicsOverlay!

    private var TextOverlayer:AGSGraphicsOverlay!
    private var LineGraphicsOverlay:AGSGraphicsOverlay!
    private var PolyGraphicsOverlay:AGSGraphicsOverlay!
    
    private var featureLayer:AGSFeatureLayer!
    private var featureTable:AGSServiceFeatureTable!
    private var featureArr:NSArray!
    
    
    func initWithAGSMapView(mapView:AGSMapView) -> GISMapTool {
        
        self.featureArr = NSArray()
        self.OperationTypeArr = NSMutableArray()
        self.overlayer = AGSGraphicsOverlay()
        self.StartOverlayer = AGSGraphicsOverlay()
        self.EndOverlayer = AGSGraphicsOverlay()
        self.TextOverlayer = AGSGraphicsOverlay()
        self.LineGraphicsOverlay = AGSGraphicsOverlay()
        self.PolyGraphicsOverlay = AGSGraphicsOverlay()
        self.OperationTypeDic = NSMutableDictionary()
        
        return self;
    }
    
    
    func createPolyline(mapView:AGSMapView) -> Void {
        
        self.setInstanceMapView(mapView: mapView)
        
        self.OperationTypeArr.add(ZXYBtnOperationType.ZXYMapViewOperationTypeLine.rawValue)
        
    }
    
    func createPolygons(mapView:AGSMapView) -> Void {
        
        self.setInstanceMapView(mapView: mapView)

        self.OperationTypeArr.add(ZXYBtnOperationType.ZXYMapViewOperationTypeArea.rawValue)
    
    }
    
    func setInstanceMapView(mapView:AGSMapView) -> Void {
        
        self.mapView = mapView
        self.mapView.touchDelegate = self
        self.mapView.callout.delegate = self
        
        self.mapView.graphicsOverlays.addObjects(from: [self.overlayer!,self.StartOverlayer!,self.EndOverlayer!,self.LineGraphicsOverlay!,self.PolyGraphicsOverlay!,self.TextOverlayer!])
    }
    
    func createPolyline() {
        
        let polylineBuilder:AGSPolylineBuilder = AGSPolylineBuilder.init(spatialReference: self.mapView.spatialReference)
        
        for index in self.overlayer!.graphics {
            
            let point:AGSPoint = (index as! AGSGraphic).geometry as! AGSPoint
            
            polylineBuilder.add(point)
            
        }
        
        
        let lineColor:UIColor = (self.lineColor != nil) ? self.lineColor:UIColor.blue
        let lineWidth:CGFloat = (self.lineWidth != nil) ? self.lineWidth:2.0
        
        let lineSymbol:AGSSimpleLineSymbol = AGSSimpleLineSymbol.init(style: .solid, color: lineColor, width: lineWidth)
        
        let lineGraphic:AGSGraphic = AGSGraphic.init(geometry: polylineBuilder.toGeometry(), symbol: lineSymbol, attributes: nil)
        
        self.LineGraphicsOverlay.graphics.add(lineGraphic)
        
        if let _ = PolylineBuilderBlock{
            PolylineBuilderBlock(polylineBuilder)
        }

        
    }
    
    func createPolygons() {
        
        self.PolyGraphicsOverlay.graphics.removeAllObjects()
        
        let polyBuilder:AGSPolygonBuilder = AGSPolygonBuilder.init(spatialReference: self.mapView.spatialReference)
        
        for index in self.overlayer!.graphics {

            let point:AGSPoint = (index as! AGSGraphic).geometry as! AGSPoint

            polyBuilder.add(point)
            
        }
        
        let lineColor:UIColor = (self.lineColor != nil) ? self.lineColor:UIColor.blue
        let lineWidth:CGFloat = (self.lineWidth != nil) ? self.lineWidth:2.0
        
        let lineSymbol:AGSSimpleLineSymbol = AGSSimpleLineSymbol.init(style: .solid, color: lineColor, width: lineWidth)
        
        let fillSymbol1:AGSSimpleFillSymbol = AGSSimpleFillSymbol.init(style: .solid, color: UIColor.init(red: 233.0/255, green: 233.0/255, blue: 233.0/255, alpha: 0.6), outline: lineSymbol)
        
        let fillGraphic:AGSGraphic = AGSGraphic.init(geometry: polyBuilder.toGeometry(), symbol: fillSymbol1, attributes: nil)
        
        self.PolyGraphicsOverlay.graphics.add(fillGraphic)
        
        
        if let _ = PolygonsBuilderBlock{
            PolygonsBuilderBlock(polyBuilder)
        }
        
    }

    /// --------------------  起点图标 ------------------
    func StartPoint(point:AGSPoint) {
        
        self.StartOverlayer.graphics.removeAllObjects()
        
        let StartPoint:AGSPoint = AGSPoint.init(x: point.x, y: point.y, spatialReference: self.mapView.spatialReference)
        
        let StartSymbol:AGSPictureMarkerSymbol = AGSPictureMarkerSymbol(image: UIImage(named: "luxian_dw1")!)
        let StartGraphicl:AGSGraphic = AGSGraphic.init(geometry: StartPoint, symbol: StartSymbol, attributes: nil)
        
        self.StartOverlayer.graphics.add(StartGraphicl)
        
    }

    /// --------------------  终点图标 ------------------
    func EndPoint() {
        
        self.EndOverlayer.graphics.removeAllObjects()
        
        let point:AGSPoint = (self.overlayer.graphics.lastObject as! AGSGraphic).geometry as! AGSPoint
        
        let EndPoint:AGSPoint = AGSPoint.init(x: point.x, y: point.y, spatialReference: self.mapView.spatialReference)
        
        let EndSymbol:AGSPictureMarkerSymbol = AGSPictureMarkerSymbol.init(image: UIImage(named: "luxian_dw")!)
        let EndGraphicl:AGSGraphic = AGSGraphic.init(geometry: EndPoint, symbol: EndSymbol, attributes: nil)
        
        self.EndOverlayer.graphics.add(EndGraphicl)
        
    }
    /// --------------------  距离:面积显示图层 ------------------

    func resultTextSymbol(resultText: String) -> Void {
        
        if self.TextOverlayer != nil {
            
            self.TextOverlayer.graphics.removeAllObjects()
            
        }
        
        let point:AGSPoint = (self.overlayer.graphics.lastObject as! AGSGraphic).geometry as! AGSPoint

        let distanceSymbol:AGSTextSymbol = AGSTextSymbol(text: resultText, color: UIColor.red, size: 15, horizontalAlignment: .center, verticalAlignment: .middle)
        
        var setY:Double = 10.0
        
        if self.overlayer.graphics.count >= 2 {
            
            let pointl: AGSPoint = (self.overlayer.graphics.object(at: self.overlayer.graphics.count - 2) as! AGSGraphic).geometry as! AGSPoint
            
            if pointl.y > point.y {
                setY = -10
            }else{
                setY = 10
            }
        }else{

            setY = 10

        }
        
        distanceSymbol.offsetX = CGFloat(setY)
        
        let locationGraphic:AGSGraphic = AGSGraphic.init(geometry: point, symbol: distanceSymbol, attributes: nil)
        
        if resultText.prefix(4) == "0.00" {
        
            self.TextOverlayer.graphics.add(locationGraphic)
        }
        
    }
    
    
    func AddResourceLayer(mapView:AGSMapView,scale:Double,layerId:String,url:String) -> Void {
        
        if ((self.mapView?.callout) != nil) {
           
            self.mapView.callout.dismiss()

        }
        
        if self.featureArr.count > 0{
            self.featureLayer.unselectFeatures(self.featureArr as! [AGSFeature])
        }
        
        var Scale = scale

        self.mapView = mapView;

        self.mapView.touchDelegate = self;
        self.mapView.callout.delegate = self;
        
        
        self.featureTable = AGSServiceFeatureTable.init(url: NSURL(string: url)! as URL)
        
        self.featureLayer = AGSFeatureLayer.init(featureTable: self.featureTable)
        
        if (self.selectionColor != nil) {
            
            
            if (self.isPropertyExist(propertyStr: "selectionProperties", myClass: AGSGeoView.self)) {

                self.mapView.selectionProperties.color = self.selectionColor

            }else{

                self.featureLayer.selectionColor = UIColor.cyan

            }
        }

        self.OperationTypeDic.setObject(self.featureLayer!, forKey: layerId as NSCopying)
        
        self.OperationTypeArr.add(layerId)
        
        self.mapView.map?.operationalLayers.add(self.featureLayer!)
        
        if (Scale > 0) {

        }else{

            Scale = 2041428;
        }
        
//        self.mapView.setViewpointCenter(self.mapView.locationDisplay.mapLocation!, scale: Scale) { (finished: Bool) in
//
//        }
        
    }
    
    /**
     设置地点
     */
    
    func setAddressLayers(mapView:AGSMapView,Overlay:AGSGraphicsOverlay) -> Void {
        self.AdressOverlayer = Overlay
        
        self.setInstanceMapView(mapView: mapView)
        
        self.OperationTypeArr.remove(ZXYBtnOperationType.ZXYMapViewOperationTypeAdress.rawValue)
        
        self.OperationTypeArr.add(ZXYBtnOperationType.ZXYMapViewOperationTypeAdress.rawValue)
    }
    
    class func MeasureDistanceOnTheMapView(polylineBuilder:AGSPolylineBuilder) -> Double {
        
        return AGSGeometryEngine.geodeticLength(of: polylineBuilder.toGeometry(), lengthUnit: .meters(), curveType: .loxodrome)
    }
    
    class func MeasureAreaOnTheMapView(polyBuilder:AGSPolygonBuilder) -> Double {
        
        return AGSGeometryEngine.geodeticArea(of: polyBuilder.toGeometry(), areaUnit: .squareMeters(), curveType: .loxodrome)
    }
    
    func removeAllObjects() {
        self.overlayer.graphics.removeAllObjects()
        self.StartOverlayer.graphics.removeAllObjects()

        self.EndOverlayer.graphics.removeAllObjects()
        self.TextOverlayer.graphics.removeAllObjects()
        self.LineGraphicsOverlay.graphics.removeAllObjects()

        self.PolyGraphicsOverlay.graphics.removeAllObjects()
        self.OperationTypeArr.removeAllObjects()

    }
    
    func removeResourceLayerForKey(key:Any) {
        
        if (self.OperationTypeDic.object(forKey: key) != nil) {
            
        }else{
            
            self.mapView.map?.operationalLayers.removeAllObjects()
        }
    }
    
    func removeObjectForKey(key:Any) {
        
        
        self.featureLayer.resetRenderer()
        
        if self.OperationTypeArr.contains(key) {
            
            self.OperationTypeArr.remove(key)
        }else{
            
        }
        
        self.StartOverlayer.graphics.removeAllObjects()
        self.EndOverlayer.graphics.removeAllObjects()
        self.TextOverlayer.graphics.removeAllObjects()
        
        // 移除相应的Overlay
        
        
        if (key as! String == ZXYBtnOperationType.ZXYMapViewOperationTypeLine.rawValue){
            
            self.LineGraphicsOverlay.graphics.removeAllObjects();

        }else if (key as! String  == ZXYBtnOperationType.ZXYMapViewOperationTypeArea.rawValue){
        
            self.PolyGraphicsOverlay.graphics.removeAllObjects();

        }else{
        }
        
        // 移除 点 Overlay
        
        if !self.OperationTypeArr.contains(ZXYBtnOperationType.ZXYMapViewOperationTypeLine.rawValue) &&  !self.OperationTypeArr.contains(ZXYBtnOperationType.ZXYMapViewOperationTypeArea.rawValue){
            self.overlayer.graphics.removeAllObjects()
        }
    }
    
    func displayGraphicAtPoint(Point:AGSPoint) -> Void {
        
//        let tempImg:UIImage! = UIImage(named: "location")
        
//        if (self.nodeIconImg != nil) {
//
//            tempImg = self.nodeIconImg
//        }
        
//        let locationSymbol:AGSPictureMarkerSymbol! = AGSPictureMarkerSymbol.init(image: tempImg)
        let locationGraphic:AGSGraphic = AGSGraphic.init(geometry: Point, symbol: nil, attributes: nil)
        self.overlayer.graphics.add(locationGraphic)
        
    }
    
    func geoView(_ geoView: AGSGeoView, didTapAtScreenPoint screenPoint: CGPoint, mapPoint: AGSPoint) {

        
        if self.OperationTypeArr.count > 0 {
            
            for value in self.OperationTypeArr{
            
                if (value as! String == ZXYBtnOperationType.ZXYMapViewOperationTypeLine.rawValue){

                    self.displayGraphicAtPoint(Point: mapPoint)
                    if self.overlayer.graphics.count >= 2 {

                        self.createPolyline()

                    }else{

                        self.StartPoint(point: mapPoint)

                    }

                }
//
                if (value as! String == ZXYBtnOperationType.ZXYMapViewOperationTypeArea.rawValue){
                    self.displayGraphicAtPoint(Point: mapPoint)

                    self.createPolygons()
                    
                    if self.overlayer.graphics.count == 1 {
                        self.StartPoint(point: mapPoint)
                    }else if self.overlayer.graphics.count >= 3 {
                        
                    }else{
                        
                    }
                }
                
                if !self.OperationTypeArr.contains(ZXYBtnOperationType.ZXYMapViewOperationTypeLine.rawValue) &&  !self.OperationTypeArr.contains(ZXYBtnOperationType.ZXYMapViewOperationTypeArea.rawValue){

                    if self.OperationTypeArr.contains(ZXYBtnOperationType.ZXYMapViewOperationTypeAdress) {
                    
                        self.GraphicsOverlay(screenPoint: screenPoint, mapPoint: mapPoint)
                    }else{
                        
                        self.GoVectorLayer(screenPoint: screenPoint, mapPoint: mapPoint)
                    }
                }
                
            }
        }
    }
    
    func GraphicsOverlay(screenPoint:CGPoint,mapPoint:AGSPoint) -> Void {
        
        self.mapView.identify(self.AdressOverlayer, screenPoint: screenPoint, tolerance: 12, returnPopupsOnly: false) { (identifyResult: AGSIdentifyGraphicsOverlayResult) in
            
            if (identifyResult.error != nil){
                
            }else if (identifyResult.graphics.count > 0){

                if let _  = self.GraphicsOverlayBlock{
                    
                    self.GraphicsOverlayBlock(identifyResult.graphics as NSArray,mapPoint)
                }
            }else{
                
                self.GraphicsOverlay(screenPoint: screenPoint, mapPoint: mapPoint)
            }
            
        }
    }
    
    func GoVectorLayer(screenPoint:CGPoint,mapPoint:AGSPoint) -> Void {
     
        self.mapView.callout.dismiss()
        
        let tolerance:Double = 12
        let mapTolerance = tolerance * self.mapView.unitsPerPoint
        
        let envelope:AGSEnvelope = AGSEnvelope.init(xMin: mapPoint.x - mapTolerance, yMin: mapPoint.y - mapTolerance, xMax: mapPoint.x + mapTolerance, yMax: mapPoint.y + mapTolerance, spatialReference: self.mapView.spatialReference)

        let queryParams:AGSQueryParameters = AGSQueryParameters()
        
        queryParams.geometry = envelope
        
        
        for index in self.OperationTypeDic.allValues {
            
            (index as! AGSFeatureLayer).selectFeatures(withQuery: queryParams, mode: .new) { (featureQueryResult:AGSFeatureQueryResult?, error:Error?) in
            
                if (error != nil){
                    
                }
                
                self.mapView.identifyLayer((index as! AGSFeatureLayer), screenPoint: screenPoint, tolerance: 15, returnPopupsOnly: false, maximumResults: 10, completion: { (identifyResult:AGSIdentifyLayerResult) in
                    
                    if identifyResult.geoElements.count > 0{
                     
                        if let _ = self.CalloutForGraphicBlock{
                        
                            self.featureArr = identifyResult.geoElements as NSArray
                            self.featureLayer.select((identifyResult.geoElements as NSArray) as! [AGSFeature])
                        
                            self.CalloutForGraphicBlock(identifyResult.geoElements as NSArray,mapPoint,(index as! AGSFeatureLayer))
                            
                            return
                        }
                    }else{
                        
                        (index as! AGSFeatureLayer).resetRenderer()
                    }
                    
                })
            }
            
        }
    }
    
    //----------  弹出气泡   ------------

    func showCalloutCustomView(customView:UIView!,scale:Double,feature:AGSFeature,tapLocation:AGSPoint) -> Void {
        
        self.mapView.callout.dismiss()

        var Scale = scale

        if (customView != nil && self.mapView.callout.isHidden )
        {
            
            self.mapView.callout.customView = customView;
        }
        
        self.mapView.callout.show(for: feature, tapLocation: feature.geometry?.extent.center, animated: false)
        
        
        if (Scale > 0) {
            
        }else{
            
            Scale = 2041428;
        }
        
        
        self.mapView.setViewpointCenter(self.mapView.callout.mapLocation!, scale: Scale) { (finished: Bool) in

        }
    }
    
    func isPropertyExist(propertyStr:String,myClass:AnyClass) -> Bool {

        var outCount: UInt32 = 0

        let properties = class_copyPropertyList(myClass,&outCount)

        var isExist:Bool = false
        
        for i in 0..<Int(outCount) {
            
            let pty = properties![i]
            
            let cName = property_getName(pty)
            
            let tempPropertyName = String(utf8String: cName)
            
            if(tempPropertyName == propertyStr){
                
                free(properties)
                isExist = true
                
                return isExist
            }
        }
        
        return isExist
        
    }

}
