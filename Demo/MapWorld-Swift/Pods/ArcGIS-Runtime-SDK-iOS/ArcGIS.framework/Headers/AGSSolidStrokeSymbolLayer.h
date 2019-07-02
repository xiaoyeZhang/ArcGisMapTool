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

#import "AGSStrokeSymbolLayer.h"

@class AGSGeometricEffect;

/** @file AGSSolidStrokeSymbolLayer.h */ //Required for Globals API doc

/** @brief A class for stroke symbol layers with customized geometric effects
 
 A class for stroke symbol layers with customized geometric effects. It represents a polyline geometry symbolized with a solid color. It's used in line symbols to describe the appearance of the line, or in polygon symbols as an outline. Currently it supports only dash effects.
 
 This symbol layer, in a `AGSMultilayerPolylineSymbol` colors the geometry of the line with the specified solid color. It also allows setting a collection of geometric effects, which modify the stroke in various ways (see documentation for geometric effects).
 
It is used to represent the Web Scene specification's LineSymbol3DLayer and PathSymbol3DLayer. LineSymbol3DLayer maps to the `strip` 3D line style, and PathSymbol3DLayer maps to the `tube` 3D line style.
 
It provides a similar user experience to `AGSSimpleLineSymbol`, but since it is a symbol layer, it can also be used in a `AGSMultilayerSymbol`. The simple line styles of `AGSSimpleLineSymbol` are represented here by the `AGSDashGeometricEffect`, but all dash patterns are custom. A solid stroke symbol layer in a multilayer polygon symbol will act as the outline of the fill.
 
 @since 100.5
 @see `AGSGeometricEffect.h`
 */

@interface AGSSolidStrokeSymbolLayer : AGSStrokeSymbolLayer

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

/** Initialize a solid stroke symbol layer with the provided parameters
 @param width the desired width of the layer in DIPs, except when the `lineStyle3D` is `tube`, in which case it is meters
 @param color the desired color for the layer
 @return Initialized solid stroke symbol layer
 @since 100.5
 */
-(instancetype)initWithWidth:(CGFloat)width
                       color:(AGSColor *)color;

/** Initialize a solid stroke symbol layer with the provided parameters
 @param width the desired width of the layer in DIPs, except when the `lineStyle3D` is `tube`, in which case it is meters
 @param color the desired color for the layer
 @return Initialized solid stroke symbol layer
 @since 100.5
 */
+(instancetype)solidStrokeSymbolLayerWithWidth:(CGFloat)width
                                         color:(AGSColor *)color;

/** Initialize a solid stroke symbol layer with the provided parameters
 @param width the desired width of the layer in DIPs, except when the `lineStyle3D` is `tube`, in which case it is meters
 @param color the desired color for the layer
 @param geometricEffects the effects to be applied to the layer. For example, dash patterns
 @return Initialized solid stroke symbol layer
 @since 100.5
 */
-(instancetype)initWithWidth:(CGFloat)width
                       color:(AGSColor *)color
            geometricEffects:(NSArray<AGSGeometricEffect*>*)geometricEffects;

/** Initialize a solid stroke symbol layer with the provided parameters
 @param width the desired width of the layer in DIPs, except when the `lineStyle3D` is `tube`, in which case it is meters
 @param color the desired color for the layer
 @param geometricEffects the effects to be applied to the layer. For example, dash patterns
 @return Initialized solid stroke symbol layer
 @since 100.5
 */
+(instancetype)solidStrokeSymbolLayerWithWidth:(CGFloat)width
                                         color:(AGSColor *)color
                              geometricEffects:(NSArray<AGSGeometricEffect*>*)geometricEffects;

/** Initialize a solid stroke symbol layer with the provided parameters
 @param width the desired width of the layer in DIPs, except when the `lineStyle3D` is `tube`, in which case it is meters
 @param color the desired color for the layer
 @param geometricEffects the effects to be applied to the layer. For example, dash patterns
 @param the desired 3D line style
 @return Initialized solid stroke symbol layer
 @since 100.5
 */
-(instancetype)initWithWidth:(CGFloat)width
                       color:(AGSColor *)color
            geometricEffects:(NSArray<AGSGeometricEffect *> *)geometricEffects
                 lineStyle3D:(AGSStrokeSymbolLayerLineStyle3D)lineStyle3D;

/** Initialize a solid stroke symbol layer with the provided parameters
@param width the desired width of the layer in DIPs, except when the `lineStyle3D` is `tube`, in which case it is meters
@param color the desired color for the layer
@param geometricEffects the effects to be applied to the layer. For example, dash patterns
@param the desired 3D line style
@return Initialized solid stroke symbol layer
@since 100.5
*/
+(instancetype)solidStrokeSymbolLayerWithWidth:(CGFloat)width
                                         color:(AGSColor *)color
                              geometricEffects:(NSArray<AGSGeometricEffect *> *)geometricEffects
                                   lineStyle3D:(AGSStrokeSymbolLayerLineStyle3D)lineStyle3D;

#pragma mark -
#pragma mark properties

/** Color of the solid stroke symbol layer. Defaults to Black
 @since 100.5
 */
@property (nonatomic, strong, readwrite) AGSColor *color;

/** Collection of geometric effects held by a solid stroke symbol layer.
 @since 100.5
 */
@property (nonatomic, copy, readwrite) NSArray<AGSGeometricEffect*> *geometricEffects;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end

