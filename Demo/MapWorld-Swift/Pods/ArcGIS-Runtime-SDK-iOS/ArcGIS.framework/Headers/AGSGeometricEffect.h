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

/*@file AGSGeometricEffect.h */

/** @brief A base class for multilayer symbol geometric effect
 
 Geometric effects are components of display rules that dynamically alter the representation of a symbol layer. If a multi layer symbol has multiple layers and an effect is applied to a specific layer, it will alter only that layer of the symbol.
 
 @since 100.5
 */

@interface AGSGeometricEffect : AGSObject

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

#pragma mark -
#pragma mark properties

/** Type of the geometric effect
 @since 100.5
 */
@property (nonatomic, assign, readonly) AGSGeometricEffectType type;

#pragma mark -
#pragma mark methods

/** Compares whether this geometric effect is equal to another
 @param other geometric effect to compare this one to
 @return whether the two geometric effects are equal
 @since 100.5
 */
-(BOOL)isEqualToGeometricEffect:(AGSGeometricEffect*)other;

NS_ASSUME_NONNULL_END

@end

