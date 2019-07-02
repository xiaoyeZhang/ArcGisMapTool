/*
 COPYRIGHT 2019 ESRI
 
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

#import "AGSObject.h"

/** @file AGSSymbolLayer.h */ //Required for Globals API doc

/** @brief A base class to represent symbol layers
 
 A base class to represent symbol layers, which are the fundamental components used to build multilayer symbols.
 
 A symbol can contain one or several symbol layers of the same or different type. A symbol used to render polygons, for example, might contain a fill symbol layer to render the polygon interior, a stroke symbol layer for rendering the polygon outline, and a marker symbol layer to render polygon vertices. A symbol to render a polyline might contain several stroke layers of varying widths. If a symbol contains a layer that cannot render the type of geometry to which it is applied, that symbol layer is ignored when rendering.
 
  @note The available symbol layer types correspond to the primitive geometry they are designed to render: marker layers for point, stroke layers for line, and fill layers for area. Layer types, however, are not applied exclusively to the corresponding geoelement geometry type. A marker symbol layer, for example, could be applied to a polyline feature to render its vertices. Each layer type has a unique set of properties to control its display.
 
 @since 100.5
 */

@interface AGSSymbolLayer : AGSObject

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

#pragma mark -
#pragma mark properties

/**
 Indicates whether or not the symbol layer is color locked.
 If YES, the layer's color will not change.
 @since 100.5
 */
@property (nonatomic, assign, readwrite, getter = isColorLocked) BOOL colorLocked;

/**
 Indicates whether or not the symbol layer is enabled. Layer will be rendered only when enabled.
 @since 100.5
 */
@property (nonatomic, assign, readwrite, getter = isEnabled) BOOL enabled;

/**
 The type of the symbol layer. `AGSSymbolLayerTypeUnknown` is returned when an error occurs
 @since 100.5
 */
@property (nonatomic, assign, readonly) AGSSymbolLayerType type;

#pragma mark -
#pragma mark methods

/**
 Compares whether two symbol layers are equal.
 
 @param other symbol layer to compare this symbol layer to
 @return YES if the symbol layers are equal
 @since 100.5
 */
-(BOOL)isEqualToSymbolLayer:(AGSSymbolLayer*)other;

NS_ASSUME_NONNULL_END

@end



