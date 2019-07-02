/*
 COPYRIGHT 2017 ESRI
 
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
#import "AGSMultilayerSymbol.h"

@class AGSSymbolLayer;

/** @file AGSMultilayerPointSymbol.h */ //Required for Globals API doc

/** @brief A multilayer point symbol
 
 Instances of this class represent multilayer point symbols. These symbols are composed of multiple layers of symbols which are rendered as one symbol with a point geometry. Each symbol layer has its own properties like offset, anchor, rotation which can be combined to create a point symbol with special effects. e.g concentric circles or a pushpin effect.
 
 @since 100.2
 */
@interface AGSMultilayerPointSymbol : AGSMultilayerSymbol

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init NS_UNAVAILABLE;

/** Initialize a multilayer point symbol based on the provided parameter
 @param symbolLayers A collection of symbol layers that make up the symbol.
 @return Initialized multilayer point symbol
 @since 100.5
 */
-(instancetype)initWithSymbolLayers:(NSArray<AGSSymbolLayer*>*)symbolLayers;

/** Initialize a multilayer point symbol based on the provided parameter
 @param symbolLayers A collection of symbol layers that make up the symbol.
 @return Initialized multilayer point symbol
 @since 100.5
 */
+(instancetype)multilayerPointSymbolWithSymbolLayers:(NSArray<AGSSymbolLayer*>*)symbolLayers;

#pragma mark -
#pragma mark properties

/** The amount, in degrees, by which the symbol should be rotated. The angle is measured in degrees counterclockwise from the east, from 0 to 360. The angle for a multilayer point symbol defaults to 0. Marker symbol layers can have their own angle value defined (which is also 0 by default). Setting an angle for a marker symbol layer does not affect the angle of the point symbol. However, when a new angle value is set for the point symbol, the difference between the old value and new value is applied uniformly to all the marker symbol layers so that they maintain the same orientation relative to the symbol. Clients use the angle provided for the symbol layers when rendering the multilayer symbol
 @since 100.2
 */
@property(nonatomic, assign, readwrite) float angle;

/** The size, in points, for the symbol. The value reported is the largest size of all the symbol layers the point symbol contains. The size of the symbol is updated when its consituent symbol layers size changes (if there is a new largest layer size). When setting a new size, the size of the largest symbol layer is given the provided value, and all the smaller layers are sized proportionately. An individual symbol layer can be given a specific size without affecting the other layers.
 @since 100.2
 */
@property(nonatomic, assign, readwrite) CGFloat size;

/** Angle alignment of the multilayer point symbol.
 @since 100.2
 */
@property(nonatomic, assign, readwrite) AGSMarkerSymbolAngleAlignment angleAlignment;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end

