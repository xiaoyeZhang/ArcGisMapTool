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

#import "AGSFillSymbol.h"

@class AGSSimpleLineSymbol;

/** @file AGSSimpleFillSymbol.h */ //Required for Globals API doc

/** @brief A fill symbol based on simple patterns.
 
 Instances of this class represent simple fill symbols. Symbols describe how
 graphics and features look on a map. Different symbols are used with different
 geometry types.  Fill symbols are used with graphics and features which are based
 on a polygon geometries. The symbol can fill the interior of a polygon
 with a solid color. In addition, the symbol can have
 an optional outline which is defined by a line symbol.
 
 @since 100
 */
@interface AGSSimpleFillSymbol : AGSFillSymbol
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

/** Initialize a simple fill symbol based on the provided parameters
 @param style of fill pattern used by the symbol
 @param color of fill used by the symbol
 @param outline of the symbol
 @return Initialized simple fill symbol
 @since 100
 */
-(instancetype)initWithStyle:(AGSSimpleFillSymbolStyle)style color:(AGSColor *)color outline:(nullable AGSSimpleLineSymbol*)outline;

/** Initialize a simple fill symbol based on the provided parameters
 @param style of fill pattern used by the symbol
 @param color of fill used by the symbol
 @param opacity of the symbol
 @param outline of the symbol
 @return Initialized simple fill symbol
 @since 100
 */
+(instancetype)simpleFillSymbolWithStyle:(AGSSimpleFillSymbolStyle)style color:(AGSColor *)color outline:(nullable AGSSimpleLineSymbol*)outline;

#pragma mark -
#pragma mark properties

/** Style of the symbol's fill pattern
 @since 100
 */
@property (nonatomic, assign, readwrite) AGSSimpleFillSymbolStyle style;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END
@end
