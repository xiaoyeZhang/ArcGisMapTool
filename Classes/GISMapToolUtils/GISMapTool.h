//
//  GISMapTool.h
//  WuxiAgriculture
//
//  Created by zhangxiaoye on 2019/1/28.
//  Copyright © 2019年 zhangxiaoye. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Marco.h"

NS_ASSUME_NONNULL_BEGIN

@interface GISMapTool : NSObject

/** 线颜色 */
@property(nonatomic,strong)UIColor *lineColor;
/** 线宽 */
@property(nonatomic,assign)CGFloat lineWidth;
/** 节点图标 */
@property(nonatomic,strong)UIImage *nodeIconImg;

/** 用于在选定内容周围绘制光环的颜色。默认为青色。 */
@property(nonatomic,strong)UIColor *selectionColor;

/**  返回AGSPolylineBuilder 类型(画线)*/
@property (copy, nonatomic) void(^PolylineBuilderBlock)(AGSPolylineBuilder *polylineBuilder);

/**  返回AGSPolygonBuilder 类型 (画多边形) */
@property (copy, nonatomic) void(^PolygonsBuilderBlock)(AGSPolygonBuilder *polyBuilder);

/**  返回点击图层资源数组 类型*/
@property (copy, nonatomic) void(^CalloutForGraphicBlock)(NSArray *featureArr,AGSPoint *tapLocation,AGSFeatureLayer *featureLayer);

/**  返回点击地点结果 */
@property (copy, nonatomic) void(^GraphicsOverlayBlock)(NSArray *featureArr,AGSPoint *tapLocation);

/**  返回搜索地点周边结果 */
@property (copy, nonatomic) void(^SearchPointBlock)(NSArray *DataArray);

#pragma mark 初始化类
-(instancetype)initWithAGSMapView:(AGSMapView *)mapView;

#pragma mark 手动添加点
- (void)setAddressLayers:(AGSMapView *)mapView Overlay:(AGSGraphicsOverlay *)Overlay;

#pragma mark 画线
- (void )createPolyline:(AGSMapView *)mapView;

#pragma mark 画多边形
- (void )createPolygons:(AGSMapView *)mapView;

#pragma mark 距离:面积显示图层
- (void)resultTextSymbol:(NSString *)resultText;

#pragma mark 测量距离
+ (double )MeasureDistanceOnTheMapView:(AGSPolylineBuilder *)polylineBuilder;

#pragma mark 测量面积
+ (double )MeasureAreaOnTheMapView:(AGSPolygonBuilder *)polyBuilder;

/**
 添加资源图层

 @param mapView 需要添加图层的地图
 @param scale 放大比例 (传入大于0的数字, 存入0或者小于0 默认比例为2041428)
 @param layerId 图层ID(便于区分)
 @param url 图层URL地址
 */
#pragma mark 添加单资源图层
- (void)AddResourceLayer:(AGSMapView *)mapView MapViewScale:(double)scale ResourceLayerId:(NSString *)layerId ResourceLayerUrl:(NSString *)url;

#pragma mark 添加多层资源图层
 /*
添加多层资源图层
@param mapView 需要添加图层的地图
@param mapLayers 图层数组.（字典格式 {@"Name"：@“ ”，@“Url”：@” “}）
 */
- (void)AddResourceLayer:(AGSMapView *)mapView ResourceLayers:(NSArray <NSDictionary *>*)mapLayers;


#pragma mark 搜索图层周边
/*
@param selectedPoint 搜索点(使用投影坐标)
@param featureTable 图层
@param searchExtent 搜索范围
*/
- (void)searchMapDataPoint:(AGSPoint *)selectedPoint FeatureTable:(AGSServiceFeatureTable *)SearchFeatureTable SearchExtent:(double)searchExtent;

#pragma mark 移除资源图层
- (void)removeResourceLayerForKey:(id)key;

#pragma mark 移除所有
- (void)removeAllObjects;

#pragma mark 移除某一个
- (void)removeObjectForKey:(id)key;

/**
 弹出气泡
 
 @param customView 自定义视图
 @param scale 放大比例 (传入大于0的数字, 存入0或者小于0 默认比例为10000)
 @param feature 需要显示的资源
 @param tapLocation 气泡弹出位置

 */
#pragma mark 弹出气泡
- (void)showCalloutCustomView:(UIView *__nullable)customView MapViewScale:(double)scale ForGraphic:(AGSFeature *)feature tapLocation:(AGSPoint *)tapLocation;


@end

NS_ASSUME_NONNULL_END
