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

/** @file AGSSolidFillSymbolLayer.h */ //Required for Globals API doc

/** @brief A class representing a solid fill symbol layer.
 
 An instance of `AGSSolidFillSymbolLayer` represents a symbol layer that is used to fill a polygon geometry with a solid color. If it is the only symbol layer in a `AGSMultilayerPolygonSymbol`, it will fill the geometry with the specified color.
 
 It is similar to the Web Scene's FillSymbol3DLayer, and the Web Map's esriSFS.
 
 It is like `AGSSimpleFillSymbol` with a solid style. Unlike `AGSSimpleFillSymbol`, which includes hatch fill styles, the solid fill symbol layer is used to symbolize a solid fill exclusively and therefore only exposes a color property.
 
 @since 100.5
 */
@interface AGSSolidFillSymbolLayer : AGSFillSymbolLayer

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

/** Initialize a solid fill symbol layer with the provided parameter
 @param color the desired color for the symbol layer.
 @return Initialized solid fill symbol layer
 @since 100.5
 */
-(instancetype)initWithColor:(AGSColor *)color;

/** Initialize a solid fill symbol layer 
 @return Initialized solid fill symbol layer
 @since 100.5
 */
+(instancetype)solidFillSymbolLayer;

/** Initialize a solid fill symbol layer with the provided parameter
 @param color the desired color for the symbol layer.
 @return Initialized solid fill symbol layer
 @since 100.5
 */
+(instancetype)solidFillSymbolLayerWithColor:(AGSColor *)color;

#pragma mark -
#pragma mark properties

/** The color of a solid fill symbol layer. Defaults to black.
 @since 100.5
 */
@property (nonatomic, strong, readwrite) AGSColor *color;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end

