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

/** @file AGSMultilayerPointSymbol.h */ //Required for Globals API doc

/** @brief A multilayer point symbol
 
 Instances of this class represent multilayer point symbols. These symbols are composed of multiple layers of symbols which are rendered as one symbol with a point geometry. Each symbol layer has its own properties like offset, anchor, rotation which can be combined to create a point symbol with special effects. e.g concentric circles or a pushpin effect.
 
 @since 100.2
 */
@interface AGSMultilayerPointSymbol : AGSMultilayerSymbol

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** The amount, in degrees, by which the symbol should be rotated. Rotation is performed starting from North in a clockwise direction where North is the 0° axis
 @since 100.2
 */
@property(nonatomic, assign, readwrite) float angle;

/** The size, in points, for the symbol
 @since 100.2
 */
@property(nonatomic, assign, readwrite) CGFloat size;

@property(nonatomic, assign, readwrite) AGSMarkerSymbolAngleAlignment angleAlignment;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end

