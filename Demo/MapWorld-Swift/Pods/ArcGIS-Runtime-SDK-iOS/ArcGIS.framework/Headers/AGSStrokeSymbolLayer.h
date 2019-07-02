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

#import "AGSSymbolLayer.h"

/** @file AGSStrokeSymbolLayer.h */ //Required for Globals API doc

/** @brief A base class for stroke symbol layers.
 
 A base class representing a symbol layer that, when applied to a polyline geometry, draws a stroke along that geometry. It also controls drawing the outline of a polygon geometry.
 
 Stroke symbol layer controls many common operations vital for working with strokes including cap style and line style 3D. These properties provide the ability to pick between various options for rendering strokes. Line style 3D applies only in 3D, but cap style and width have effects in both 2D and 3D.
 
 @note Applied to a polyline geometry, the stroke symbol layer will draw a segment of stroke adhering to the selected visual properties for each line segment. Similarly, as the outline of a polygon geometry, the stroke symbol layer draws a stroke segment for each line segment of the polygon outline.
 
 @since 100.5
 */

@interface AGSStrokeSymbolLayer : AGSSymbolLayer

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

#pragma mark -
#pragma mark properties

/**
 The cap style of the stroke symbol layer, which controls the rendering of the ends or the caps of the stroke. Defaults to `round` meaning the ends of the stroke are rounded off. Cap styles affect strokes in Map Views, as well as `tube` and `strip` line styles in Scene Views.
 @note In dynamic rendering mode, caps are always rendered with the `butt` style.
 @since 100.5
 */
@property (nonatomic, assign, readwrite) AGSStrokeSymbolLayerCapStyle capStyle;

/**
 The 3D line style of the stroke symbol layer, which controls the rendering of the stroke in 3D. Defaults to `strip` meaning the 3D stroke is flat. 3D line style has no effect on strokes in Map Views, but does affect strokes in Scene Views.
 @note The `#width` is considered to be in DIPs for all styles except `tube` for which it is meters.
 @note Only the `strip` 3D line style is supported in static rendering mode.
 @since 100.5
 */
@property (nonatomic, assign, readwrite) AGSStrokeSymbolLayerLineStyle3D lineStyle3D;

/**
 The width of a stroke symbol layer in DIPs, except when the `lineStyle3D` is `tube`, in which case it is meters. It may be any non-negative number. Defaults to 0. A larger width means a larger stroke.
 @since 100.5
 */
@property (nonatomic, assign, readwrite) CGFloat width;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end


