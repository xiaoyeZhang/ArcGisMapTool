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

#import "AGSMarkerSymbol.h"

@class AGSSimpleLineSymbol;

/** @file AGSSimpleMarkerSymbol.h */ //Required for Globals API doc

/** @brief A marker symbol based on simple shapes.
 
 Instances of this class represent simple marker symbols. Symbols describe how
 graphics or features look on the map. Different symbols are used with different
 geometry types. Marker symbols are used to display those graphics and features which are
 based on point or multipoint geometry. Simple marker symbols display simple, predefined markers such as circle, cross, etc. In addition, the
 markers can have an optional outline, which is defined by a line symbol.
 
 @since 100
 */

@interface AGSSimpleMarkerSymbol : AGSMarkerSymbol
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

/** Initialize a simple marker symbol with the specified properties
 @param style of marker
 @param color of symbol
 @param size of symbol in points
 @return Initialized simple marker symbol
 @since 100
 */
-(instancetype)initWithStyle:(AGSSimpleMarkerSymbolStyle)style color:(AGSColor *)color size:(CGFloat)size;

/** Initialize a simple marker symbol with the specified properties
 @param style of marker
 @param color of symbol
 @param size of symbol in points
 @return Initialized simple marker symbol
 @since 100
 */
+(instancetype)simpleMarkerSymbolWithStyle:(AGSSimpleMarkerSymbolStyle)style color:(AGSColor *)color size:(CGFloat)size;


/** Initialize a simple marker symbol
 @return Initialized simple marker symbol
 @since 100
 */
+(instancetype)simpleMarkerSymbol;

#pragma mark -
#pragma mark properties

/** Color of the symbol
 @since 100
 */
@property (nonatomic, strong, readwrite) AGSColor *color;

/** Outline of the symbol
 @since 100
 */
@property (nullable, nonatomic, strong, readwrite) AGSSimpleLineSymbol *outline;

/** Size of the symbol in points (not pixels).
 @since 100
 */
@property (nonatomic, assign, readwrite) CGFloat size;

/** The marker's style
 @since 100
 */
@property (nonatomic, assign, readwrite) AGSSimpleMarkerSymbolStyle style;


#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END
@end
