/*
 COPYRIGHT 2015 ESRI
 
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

#import "AGSSymbol.h"

@class AGSLineSymbol;

/** @file AGSFillSymbol.h */ //Required for Globals API doc

/** @brief An abstract base class for fill symbols.
 
 Subclasses represent fill symbols. Symbols describe how graphics and features
 look on a map. Different symbols are used with different geometry
 types.  Fill symbols are used to display those graphics and features which are based on
 polygon geometries. The symbol can fill the interior of a polygon
 with a solid color. In addition, the symbol can have
 an optional outline which is defined by a line symbol.

 
 @since 100
 */
@interface AGSFillSymbol : AGSSymbol
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

#pragma mark -
#pragma mark properties

/** Color to fill the interior of the polygon feature or graphic
 @since 100
 */
@property (nonatomic, strong, readwrite) AGSColor *color;

/** Outline for the fill symbol
 @since 100
 */ 
@property (nullable, nonatomic, strong, readwrite) AGSLineSymbol *outline;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END
@end
