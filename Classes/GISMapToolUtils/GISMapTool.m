//
//  GISMapTool.m
//  WuxiAgriculture
//
//  Created by zhangxiaoye on 2019/1/28.
//  Copyright © 2019年 zhangxiaoye. All rights reserved.
//

#import "GISMapTool.h"
#import <objc/runtime.h>


@interface GISMapTool()<AGSGeoViewTouchDelegate,AGSCalloutDelegate>

@property (strong, nonatomic) AGSMapView *mapView;

@property (strong, nonatomic) NSMutableArray *OperationTypeArr;

@property (strong, nonatomic) NSMutableDictionary *OperationTypeDic;

@property (strong, nonatomic) AGSGraphicsOverlay *AdressOverlayer;

@property (strong, nonatomic) AGSGraphicsOverlay *overlayer;

@property (strong, nonatomic) AGSGraphicsOverlay *StartOverlayer;

@property (strong, nonatomic) AGSGraphicsOverlay *EndOverlayer;

@property (strong, nonatomic) AGSGraphicsOverlay *TextOverlayer;

@property (strong, nonatomic) AGSGraphicsOverlay *LineGraphicsOverlay;

@property (strong, nonatomic) AGSGraphicsOverlay *PolyGraphicsOverlay;

@property (strong, nonatomic) AGSFeatureLayer *featureLayer;

@property (strong, nonatomic) AGSServiceFeatureTable *featureTable;

@property (copy, nonatomic) NSArray *featureArr;

@end

@implementation GISMapTool

- (void)createPolyline{

    AGSPolylineBuilder *polylineBuilder = [[AGSPolylineBuilder alloc]initWithSpatialReference:self.mapView.spatialReference];
    
    for (AGSGraphic *graphic in self.overlayer.graphics) {
        
        AGSPoint *stop = (AGSPoint *)graphic.geometry;
        [polylineBuilder addPoint:stop];
    }
    
    UIColor *lineColor = self.lineColor ? self.lineColor:[UIColor blueColor];
    CGFloat lineWidth = self.lineWidth?self.lineWidth:2.0;
    
    AGSSimpleLineSymbol *lineSymbol = [[AGSSimpleLineSymbol alloc]initWithStyle:AGSSimpleLineSymbolStyleSolid color:lineColor width:lineWidth];
    AGSGraphic *lineGraphic = [[AGSGraphic alloc]initWithGeometry:polylineBuilder.toGeometry symbol:lineSymbol attributes:nil];
    
    [self.LineGraphicsOverlay.graphics addObjectsFromArray:@[lineGraphic]];
    
    if (self.PolylineBuilderBlock) {
        
        self.PolylineBuilderBlock(polylineBuilder);
        
    }
    
}

- (void)createPolygons{
    
    [self.PolyGraphicsOverlay.graphics removeAllObjects];
    
    AGSPolygonBuilder *polyBuilder = [[AGSPolygonBuilder alloc]initWithSpatialReference:self.mapView.spatialReference];
    
    for (AGSGraphic *graphic in self.overlayer.graphics) {
        
        AGSPoint *stop = (AGSPoint *)graphic.geometry;
        [polyBuilder addPoint:stop];
        
    }
    
    UIColor *lineColor = self.lineColor ? self.lineColor:[UIColor blueColor];
    CGFloat lineWidth = self.lineWidth?self.lineWidth:2.0;
    
    AGSSimpleLineSymbol *lineSymbol = [[AGSSimpleLineSymbol alloc]initWithStyle:AGSSimpleLineSymbolStyleSolid color:lineColor width:lineWidth];
    
    AGSSimpleFillSymbol *fillSymbol1 = [[AGSSimpleFillSymbol alloc]initWithStyle:AGSSimpleFillSymbolStyleSolid color:[UIColor colorWithRed:233.0/255 green:233.0/255 blue:233.0/255 alpha:0.6] outline:lineSymbol];
    
    AGSGraphic *fillGraphic = [[AGSGraphic alloc]initWithGeometry:polyBuilder.toGeometry symbol:fillSymbol1 attributes:nil];
    
    [self.PolyGraphicsOverlay.graphics addObject:fillGraphic];
    
    if (self.PolygonsBuilderBlock) {
        self.PolygonsBuilderBlock(polyBuilder);
    }
}

#pragma mark 起点图标
- (void)StartPoint:(AGSPoint *)point{
    /// --------------------  起点图标 ------------------
    
    [self.StartOverlayer.graphics removeAllObjects];
    
    AGSPoint *StartPoint = [AGSPoint pointWithX:point.x y:point.y spatialReference:self.mapView.spatialReference];
    
    AGSPictureMarkerSymbol *StartSymbol = [[AGSPictureMarkerSymbol alloc]initWithImage:[UIImage imageNamed:@"luxian_dw1"]];
    AGSGraphic *StartGraphicl = [[AGSGraphic alloc]initWithGeometry:StartPoint symbol:StartSymbol attributes:nil];
    [self.StartOverlayer.graphics addObject:StartGraphicl];
    
}

#pragma mark 终点图标
- (void)EndPoint{
    /// --------------------  终点图标 ------------------

    [self.EndOverlayer.graphics removeAllObjects];
    
    AGSPoint *point = (AGSPoint *)self.overlayer.graphics.lastObject.geometry;
    
    AGSPoint *EndPoint = [AGSPoint pointWithX:point.x y:point.y spatialReference:self.mapView.spatialReference];
    
    AGSPictureMarkerSymbol *EndSymbol = [[AGSPictureMarkerSymbol alloc]initWithImage:[UIImage imageNamed:@"luxian_dw"]];
    
    AGSGraphic *EndGraphicl = [[AGSGraphic alloc]initWithGeometry:EndPoint symbol:EndSymbol attributes:nil];
    
    [self.EndOverlayer.graphics addObject:EndGraphicl];
    
}
#pragma mark 距离:面积显示图层
- (void)resultTextSymbol:(NSString *)resultText{
    
    [self.TextOverlayer.graphics removeAllObjects];
    
    AGSPoint *point = (AGSPoint *)self.overlayer.graphics.lastObject.geometry;
    
    AGSTextSymbol *distanceSymbol = [[AGSTextSymbol alloc]initWithText:resultText color:[UIColor redColor] size:15 horizontalAlignment:AGSHorizontalAlignmentCenter verticalAlignment:AGSVerticalAlignmentMiddle];
    
    CGFloat setY = 10.0;
    if ([self.overlayer.graphics count] >= 2) {
        AGSPoint *pointl = (AGSPoint *)([self.overlayer.graphics objectAtIndex:(self.overlayer.graphics.count - 2)]).geometry;
        
        if (pointl.y > point.y) {
            
            setY = -10;
            
        }else{
            
            setY = 10;
            
        }
    }else{
        
        setY = 10;
        
    }
    
    distanceSymbol.offsetY = setY;
    
    AGSGraphic *locationGraphic = [[AGSGraphic alloc]initWithGeometry:point symbol:distanceSymbol attributes:nil];
    
    if (![[resultText substringToIndex:4] isEqualToString:@"0.00"]) {
        
        [self.TextOverlayer.graphics addObject:locationGraphic];
        
    }
    
}

- (void)AddResourceLayer:(AGSMapView *)mapView MapViewScale:(double)scale ResourceLayerId:(NSString *)layerId ResourceLayerUrl:(NSString *)url{
        
    [self.mapView.callout dismiss];

    if ([self.featureArr count] > 0) {
     
        [self.featureLayer unselectFeatures:self.featureArr];

    }
    
    self.mapView = mapView;
    
    self.mapView.touchDelegate = self;
    self.mapView.callout.delegate = self;
    
    self.featureTable = [AGSServiceFeatureTable serviceFeatureTableWithURL:[NSURL URLWithString:url]];
    
    self.featureLayer = [AGSFeatureLayer featureLayerWithFeatureTable:self.featureTable];

    if (self.selectionColor != nil) {
       
        if ([self isPropertyExist:@"selectionProperties" Class:[AGSGeoView class]]) {
            
            self.mapView.selectionProperties.color = self.selectionColor;

        }else{
            
            self.featureLayer.selectionColor = [UIColor cyanColor];

        }
    }

    [self.OperationTypeDic setValue:self.featureLayer forKey:layerId];
    
    [self.OperationTypeArr addObject:layerId];
    
    [self.mapView.map.operationalLayers addObject:self.featureLayer];
    
    if (scale > 0) {
        
    }else{
        
        scale = 2041428;
    }
    
    [self.mapView setViewpointCenter:self.mapView.locationDisplay.mapLocation scale:scale completion:^(BOOL finished) {
        
    }];
    
    
}

/**
 设置地点
 */
- (void)setAddressLayers:(AGSMapView *)mapView Overlay:(nonnull AGSGraphicsOverlay *)Overlay{
    
    self.AdressOverlayer = Overlay;
    
    [self setInstanceMapView:mapView];
    
    [self.OperationTypeArr removeObject:ZXYMapViewOperationTypeAdress];
    [self.OperationTypeArr addObject:ZXYMapViewOperationTypeAdress];
    
}

+ (double)MeasureDistanceOnTheMapView:(AGSPolylineBuilder *)polylineBuilder{
    
    return [AGSGeometryEngine geodeticLengthOfGeometry:polylineBuilder.toGeometry lengthUnit:AGSLinearUnit.meters curveType:AGSGeodeticCurveTypeLoxodrome];
}

+ (double)MeasureAreaOnTheMapView:(AGSPolygonBuilder *)polyBuilder{
    
    return [AGSGeometryEngine geodeticAreaOfGeometry:polyBuilder.toGeometry areaUnit:AGSAreaUnit.squareMeters curveType:AGSGeodeticCurveTypeLoxodrome];
    
}

- (id)initWithAGSMapView:(AGSMapView *)mapView{
    
    self = [super init];
    
    if(self){
        
        self.featureArr = [NSArray array];
        
        self.OperationTypeArr = [[NSMutableArray alloc]init];
        
        self.overlayer = [[AGSGraphicsOverlay alloc]init];
        
        self.StartOverlayer = [[AGSGraphicsOverlay alloc]init];
        
        self.EndOverlayer = [[AGSGraphicsOverlay alloc]init];
        
        self.TextOverlayer = [[AGSGraphicsOverlay alloc]init];
        
        self.LineGraphicsOverlay = [[AGSGraphicsOverlay alloc]init];
        
        self.PolyGraphicsOverlay = [[AGSGraphicsOverlay alloc]init];
        
        self.OperationTypeDic = [NSMutableDictionary dictionary];
        
    }
    
    return self;
    
}

- (void)createPolyline:(AGSMapView *)mapView{
    
    [self setInstanceMapView:mapView];
    
    [self.OperationTypeArr addObject:ZXYMapViewOperationTypeLine];
}

- (void)createPolygons:(AGSMapView *)mapView{
    
    [self setInstanceMapView:mapView];
    
    [self.OperationTypeArr addObject:ZXYMapViewOperationTypeArea];
    
}

- (void)setInstanceMapView:(AGSMapView *)mapView{
    
    self.mapView = mapView;
    self.mapView.touchDelegate = self;
    self.mapView.callout.delegate = self;
    
    [self.mapView.graphicsOverlays addObjectsFromArray:@[self.overlayer,self.StartOverlayer,self.EndOverlayer,self.LineGraphicsOverlay,self.PolyGraphicsOverlay,self.TextOverlayer]];
    
}

- (void)removeAllObjects{
    
    [self.overlayer.graphics removeAllObjects];
    [self.StartOverlayer.graphics removeAllObjects];
    [self.EndOverlayer.graphics removeAllObjects];
    [self.TextOverlayer.graphics removeAllObjects];
    [self.LineGraphicsOverlay.graphics removeAllObjects];
    [self.PolyGraphicsOverlay.graphics removeAllObjects];
    
    [self.OperationTypeArr removeAllObjects];
    
}

- (void)removeResourceLayerForKey:(id)key{
    
    if ([[self.OperationTypeDic allKeys] containsObject:key]) {
        
        
    }else{
        
        [self.mapView.map.operationalLayers removeAllObjects];

        [self.OperationTypeDic removeAllObjects];
    }
    
}

- (void)removeObjectForKey:(id)key{
    
    //    [self.mapView.callout dismiss];
    [self.featureLayer resetRenderer];// 将渲染器，恢复到原始状态
    //  从OperationTypeArr数组中移除相应的地图操作
    if ([self.OperationTypeArr containsObject:key]) {
        
        [self.OperationTypeArr removeObject:key];
        
    }else{
        
    }
    
    [self.StartOverlayer.graphics removeAllObjects];
    [self.EndOverlayer.graphics removeAllObjects];
    [self.TextOverlayer.graphics removeAllObjects];
    
    // 移除相应的Overlay
    if ([key isEqualToString:ZXYMapViewOperationTypeLine]) {
        
        [self.LineGraphicsOverlay.graphics removeAllObjects];
        
    }else if ([key isEqualToString:ZXYMapViewOperationTypeArea]){
        
        [self.PolyGraphicsOverlay.graphics removeAllObjects];
        
    }else{
        
    }
    
    // 移除 点 Overlay
    if (![self.OperationTypeArr containsObject:ZXYMapViewOperationTypeLine] && ![self.OperationTypeArr containsObject:ZXYMapViewOperationTypeArea]) {
        
        [self.overlayer.graphics removeAllObjects];
        
    }
}

- (void)geoView:(AGSGeoView *)geoView didTapAtScreenPoint:(CGPoint)screenPoint mapPoint:(AGSPoint *)mapPoint{
    
    
    if (self.OperationTypeArr.count > 0) {
        
        for (NSString *key in self.OperationTypeArr) {
            
            if ([key isEqualToString:ZXYMapViewOperationTypeLine]) {
                
                [self displayGraphicAtPoint:mapPoint];
                
                if (self.overlayer.graphics.count >= 2) {
                    
                    [self createPolyline];
                    
                }else{
                    
                    [self StartPoint:mapPoint];
                    
                }
                
            }
            if ([key isEqualToString:ZXYMapViewOperationTypeArea]){
                
                [self displayGraphicAtPoint:mapPoint];
                
                [self createPolygons];
                
                if ([self.overlayer.graphics count] == 1) {
                    
                    [self StartPoint:mapPoint];
                    
                }else if ([self.overlayer.graphics count] >= 3) {
                    
                }else{
                    
                    
                }
                
            }else{
                
            }
            
            if (![self.OperationTypeArr containsObject:ZXYMapViewOperationTypeLine] && ![self.OperationTypeArr containsObject:ZXYMapViewOperationTypeArea]) {
     
                
                if ([self.OperationTypeArr containsObject:ZXYMapViewOperationTypeAdress]) {
                    
                    [self GraphicsOverlay:screenPoint mapPoint:mapPoint];
                    
                }else{
                    
                    [self GoVectorLayer:screenPoint mapPoint:mapPoint];
                    
                }
                
            }
            
        }
        
    }
}

- (void)GraphicsOverlay:(CGPoint)screenPoint mapPoint:(AGSPoint *)mapPoint{
    
    
    [self.mapView identifyGraphicsOverlay:self.AdressOverlayer screenPoint:screenPoint tolerance:12 returnPopupsOnly:false completion:^(AGSIdentifyGraphicsOverlayResult * _Nonnull identifyResult) {
        
        if (identifyResult.error) {
            
            
        }else if (identifyResult.graphics.count > 0){
            
            if (self.GraphicsOverlayBlock) {
                self.GraphicsOverlayBlock(identifyResult.graphics, mapPoint);
            }
            
        }else{
            
            [self GoVectorLayer:screenPoint mapPoint:mapPoint];
            
        }
        
    }];
    
}

- (void)GoVectorLayer:(CGPoint)screenPoint mapPoint:(AGSPoint *)mapPoint{
    
    [self.mapView.callout dismiss];
    
    double tolerance = 12;
    double mapTolerance = tolerance * self.mapView.unitsPerPoint;
    
    AGSEnvelope *envelope = [AGSEnvelope envelopeWithXMin:mapPoint.x - mapTolerance yMin:mapPoint.y - mapTolerance xMax:mapPoint.x + mapTolerance yMax:mapPoint.y + mapTolerance spatialReference:self.mapView.map.spatialReference];
    
    AGSQueryParameters *queryParams = [AGSQueryParameters new];
    
    queryParams.geometry = envelope;
    
    for (AGSFeatureLayer * featureLayer in [self.OperationTypeDic allValues]) {
        
        [featureLayer selectFeaturesWithQuery:queryParams mode:AGSSelectionModeNew completion:^(AGSFeatureQueryResult * _Nullable featureQueryResult, NSError * _Nullable error) {
            
            if (error) {
                
            }
            
            //。点击面
            [self.mapView identifyLayer:featureLayer screenPoint:screenPoint tolerance:15 returnPopupsOnly:false maximumResults:10 completion:^(AGSIdentifyLayerResult * _Nonnull identifyResult) {
                
                if (identifyResult.geoElements.count > 0) {
                    
                    if (self.CalloutForGraphicBlock) {
                        
                        self.featureArr = identifyResult.geoElements;
                        
                        [self.featureLayer selectFeatures:identifyResult.geoElements];

                        self.CalloutForGraphicBlock(identifyResult.geoElements, mapPoint, featureLayer);
                        
                        return ;
                    }
                }else{
                    
                    [featureLayer resetRenderer];
                    
                }
                
            }];
            
        }];
    }
    
}

- (void)displayGraphicAtPoint:(AGSPoint *)Point{
    
    UIImage *tempImg = [UIImage imageNamed:@"location"];
    if(self.nodeIconImg)
    {
        tempImg = self.nodeIconImg;
    }
    
    AGSPictureMarkerSymbol *locationSymbol = [[AGSPictureMarkerSymbol alloc]initWithImage:tempImg];
    AGSGraphic *locationGraphic = [[AGSGraphic alloc]initWithGeometry:Point symbol:locationSymbol attributes:nil];
    [self.overlayer.graphics addObject:locationGraphic];
}

- (void)showCalloutCustomView:(UIView *)customView MapViewScale:(double)scale ForGraphic:(AGSFeature *)feature tapLocation:(AGSPoint *)tapLocation{
    
    [self.mapView.callout dismiss];

    if (customView != nil && self.mapView.callout.isHidden) {
        
        self.mapView.callout.customView = customView;
        
    }
    
    [self.mapView.callout showCalloutForFeature:feature tapLocation:feature.geometry.extent.center animated:NO];
    
    if (scale > 0) {
        
    }else{
        
        scale = 10000;
    }
    
    [self.mapView setViewpointCenter:self.mapView.callout.mapLocation scale:scale completion:^(BOOL finished) {
        
    }];

}

- (BOOL)isPropertyExist:(NSString *)propertyStr Class:(Class)myClass{
    
    unsigned int outCount, i;
    // 获取对象里的属性列表
    objc_property_t * properties = class_copyPropertyList(myClass, &outCount);
    
    BOOL isExist = NO;
    for (i = 0; i < outCount; i++) {
        objc_property_t property =properties[i];
        // 属性名转成字符串
        NSString *tempPropertyName = [[NSString alloc] initWithCString:property_getName(property) encoding:NSUTF8StringEncoding];
        // 判断该属性是否存在
        if ([tempPropertyName isEqualToString:propertyStr]) {
            free(properties);
            
            isExist = YES;
            return isExist;
        }
        
    }
    
    return isExist;
}

@end
