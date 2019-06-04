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

#import "AGSLineSymbol.h"

/** @file AGSSimpleLineSymbol.h */ //Required for Globals API doc

/** @brief A line symbol based on simple patterns.
 
 Instances of this class represent simple line symbols. Symbols describe how
 graphics and features look on a map. Different symbols are used with different
 geometry types. Line symbols are used to display graphics and features which are based
 on polyline geometries. Simple line symbols display predefined
 line style patterns such as solid, dash, dot, etc.
 
 @since 100
 */
@interface AGSSimpleLineSymbol : AGSLineSymbol
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

/** Initialize a simple line symbol with the provided parameters
 @param style of the line
 @param color of the line
 @param width of the line in points (not pixels)
 @return Initialized simple line symbol
 @since 100
 */
-(instancetype)initWithStyle:(AGSSimpleLineSymbolStyle)style color:(AGSColor *)color width:(CGFloat)width;

/** Initialize a simple line symbol with the provided parameters
 @param style of the line
 @param color of the line
 @param width of the line in points (not pixels)
 @return Initialized simple line symbol
 @since 100
 */
+(instancetype)simpleLineSymbolWithStyle:(AGSSimpleLineSymbolStyle)style color:(AGSColor *)color width:(CGFloat)width;

/** Initialize a simple line symbol with the provided parameters
 @param style of the line
 @param color of the line
 @param width of the line in points (not pixels)
 @param markerStyle specifying the type of markers for the line
 @param markerPlacement specifying the placement of markers for the line endings
 @return Initialized simple line symbol
 @since 100.2
 */
-(instancetype)initWithStyle:(AGSSimpleLineSymbolStyle)style color:(AGSColor *)color width:(CGFloat)width markerStyle:(AGSSimpleLineSymbolMarkerStyle)markerStyle markerPlacement:(AGSSimpleLineSymbolMarkerPlacement)markerPlacement;

/** Initialize a simple line symbol with the provided parameters
 @param style of the line
 @param color of the line
 @param width of the line in points (not pixels)
 @param markerStyle specifying the type of markers for the line endings
 @param markerPlacement specifying the placement of markers for the line endings
 @return Initialized simple line symbol
 @since 100.2
 */
+(instancetype)simpleLineSymbolWithStyle:(AGSSimpleLineSymbolStyle)style color:(AGSColor *)color width:(CGFloat)width markerStyle:(AGSSimpleLineSymbolMarkerStyle)markerStyle markerPlacement:(AGSSimpleLineSymbolMarkerPlacement)markerPlacement;

#pragma mark -
#pragma mark properties

/** The line style
 @since 100
 */
@property (nonatomic, assign, readwrite) AGSSimpleLineSymbolStyle style;

/** The placement of markers on the line endings
 @since 100.2
 */
@property (nonatomic, assign, readwrite) AGSSimpleLineSymbolMarkerPlacement markerPlacement;

/** The style of markers on the line endings
 @since 100.2
 */
@property (nonatomic, assign, readwrite) AGSSimpleLineSymbolMarkerStyle markerStyle;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END
@end
