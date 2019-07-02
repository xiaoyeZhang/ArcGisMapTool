/*
 COPYRIGHT 2018 ESRI
 
 TRADE SECRETS: ESRI PROPRIETARY AND CONFIDENTIAL
 Unpublished material - all rights reserved under the
 Copyright Laws of the United States and applicable international
 laws, treaties, and conventions.
 
 For additional information, contact:
 Environmental Systems Research Institute, Inc.
 Attn: Contracts and Legal Services Department
 380 New York Street
 Redlands, California, 92373
 USA
 
 email: contracts@esri.com
 */

#import "AGSLayer.h"

@interface AGSGroupLayer : AGSLayer

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

/** Initialize the layer with child layers.
 @param childLayers child layers
 @since 100.5
 */
-(instancetype)initWithChildLayers:(NSArray<AGSLayer*> *)childLayers;

/** Initialize the layer
 @since 100.5
 */
+(instancetype)groupLayer;

/** Initialize the layer with child layers.
 @param childLayers child layers
 @since 100.5
 */
+(instancetype)groupLayerWithChildLayers:(NSArray<AGSLayer*> *)childLayers;

#pragma mark -
#pragma mark properties

/** This layer's child layers.
 @note This array does not allow duplicate objects.
 @since 100.5
 */
@property (nonatomic, strong, readonly) NSMutableArray<AGSLayer*> *layers;

/** Show child layers in legend property of the group layer
 @since 100.5
 */
@property (nonatomic, assign, readwrite) BOOL showChildrenInLegend;



#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end


