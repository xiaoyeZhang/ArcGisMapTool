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

#import "AGSFillSymbolLayer.h"

@class AGSMultilayerPolylineSymbol;

/** @file AGSHatchFillSymbolLayer.h */ //Required for Globals API doc

/** @brief A class representing a hatch fill symbol layer inside of the geometry attached to a multilayer polygon symbol.
 
 This class represents a polygon geometry filled with hatch lines. "Hatch lines" are uniformly spaced parallel lines. An instance of `AGSHatchFillSymbolLayer`, in a multilayer polygon symbol, fills the geometry of the symbol with the specified hatch lines. Each hatch line is itself a multilayer polyline symbol. You can define a custom hatch line through `#polyline` that is repeated in parallel throughout the inside of the geometry attached to a multilayer polygon symbol's geometry.
 
 It provides a similar experience to `AGSSimpleFillSymbol`, but with more customizability. While you can select from a list of predefined hatch fill styles for `AGSSimpleFillSymbol`, the `AGSHatchFillSymbolLayer` allows you to specify a fully-customized symbol to use as the hatch line. You can also adjust line angle, offset, and separation distance.
 
 @since 100.5
 */
@interface AGSHatchFillSymbolLayer : AGSFillSymbolLayer

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

/** Initialize a hatch fill symbol layer with the provided parameters
 @param multilayerPolylineSymbol An instance of `AGSMultilayerPolylineSymbol` to use as the hatch line of the symbol layer.
 @param angle The angle to rotate the hatch lines, in degrees measured counterclockwise from East
 @return Initialized hatch fill symbol layer
 @since 100.5
 */
-(instancetype)initWithMultilayerPolylineSymbol:(AGSMultilayerPolylineSymbol *)multilayerPolylineSymbol
                                          angle:(double)angle;

/** Initialize a hatch fill symbol layer
 @return Initialized hatch fill symbol layer
 @since 100.5
 */
+(instancetype)hatchFillSymbolLayer;

/** Initialize a hatch fill symbol layer with the provided parameters
 @param multilayerPolylineSymbol An instance of `AGSMultilayerPolylineSymbol` to use as the hatch line of the symbol layer.
 @param angle The angle to rotate the hatch lines, in degrees measured counterclockwise from East
 @return Initialized hatch fill symbol layer
 @since 100.5
 */
+(instancetype)hatchFillSymbolLayerWithMultilayerPolylineSymbol:(AGSMultilayerPolylineSymbol *)multilayerPolylineSymbol angle:(double)angle;

#pragma mark -
#pragma mark properties

/** The polyline symbol used to symbolize the hatch line. If there is no polyline set, the method returns a default polyline. That default polyline has a single `AGSSolidStrokeSymbolLayer` object, with width of 1.3333 DIPs (1.0 points) and opaque black color.
 @since 100.5
 */
@property (nonatomic, strong, readwrite) AGSMultilayerPolylineSymbol *polyline;

/** The angle of the hatch line rotation, in degrees measured counterclockwise from East.
 @since 100.5
 */
@property (nonatomic, assign, readwrite) double angle;

/** The distance between the hatch lines, in DIPs. If there is no separation set, the method returns 5.3333 DIPs, converted from the internal default 4.0 points. Separation values must be non-negative. 
 @since 100.5
 */
@property (nonatomic, assign, readwrite) CGFloat separation;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end

