/*
 COPYRIGHT 2013 ESRI
 
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

#import "AGSLoadableBase.h"
#import "AGSLayerContent.h"

@class AGSEnvelope;
@class AGSSpatialReference;
@class AGSPopupDefinition;
@class AGSItem;

/** @file AGSLayer.h */ //Required for Globals API doc

/** @brief An abstract base class for all layers.
 
 An abstract base class for all types of layers.
 
 @since 100
 */
@interface AGSLayer : AGSLoadableBase <NSCopying, AGSLayerContent>

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

#pragma mark -
#pragma mark properties

/** Attribution information of the layer
 @since 100
 */
@property (nonatomic, copy, readonly) NSString *attribution;

/** The layer's description
 @since 100
 */
@property (nonatomic, copy, readwrite) NSString *layerDescription;

/** Full extent of the layer.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSEnvelope *fullExtent;

/** The layer's ID specified in the webmap item of ArcGIS Online or an on-premises portal.
 @since 100
 */
@property (nonatomic, copy, readwrite) NSString *layerID;

/** The maximum scale at which this layer is visible. If the map or scene is zoomed in
 beyond this scale, the layer will not be visible. A value of 0 means there is no maximum scale threshold and the layer will be visible at the smallest scale available for the map or scene.
 @since 100
 */
@property (nonatomic, assign, readwrite) double maxScale;

/** The minimum scale at which this layer is visible. If the map or scene is zoomed out
 beyond this scale, the layer will not be visible. A value of 0 means there is no minimum scale threshold and the layer will be visible at the largest scale available for the map or scene.
 @since 100
 */
@property (nonatomic, assign, readwrite) double minScale;

/** The name of the layer
 @since 100
 */
@property (nonatomic, copy, readwrite) NSString *name;

/** The opacity of this layer as a value between 0 (fully transparent) and 1 (fully opaque).
 Default value is 1.
 @since 100
 */
@property (nonatomic, assign, readwrite) float opacity;

/** Specifies whether the layer supports identify.
 @since 100
 */
@property (nonatomic, assign, readonly, getter=isIdentifyEnabled) BOOL identifyEnabled;

/** The item the layer has been created from.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSItem *item;

/** The spatial reference of the layer.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSSpatialReference *spatialReference;

#pragma mark -
#pragma mark methods

-(BOOL)isEqualToLayer:(AGSLayer*)other;

NS_ASSUME_NONNULL_END

@end
