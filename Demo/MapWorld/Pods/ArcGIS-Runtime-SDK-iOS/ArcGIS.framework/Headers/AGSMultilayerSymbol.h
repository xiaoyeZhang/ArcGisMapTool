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
#import "AGSSymbol.h"

@class AGSColor;

/** @file AGSMultilayerSymbol.h */ //Required for Globals API doc

/** @brief A base class for multilayer symbols
 
 A base class for multilayer symbols. Multilayer symbols define how a symbol can be composed of multiple layers of different symbol types. Final symbol will be rendered with the type of geometry type and actual symbol type.
 
 @since 100.2
 */
@interface AGSMultilayerSymbol : AGSSymbol

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

#pragma mark -
#pragma mark properties

/** The color to be applied to each layer of the multilayer symbol whose color is not locked.
 @since 100.2
 */
@property(nonatomic, strong, readwrite) AGSColor *color;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end

