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

/** @file AGSLineSymbol.h */ //Required for Globals API doc

/** @brief An abstract base class for line symbols.
 
 Subclasses represent line symbols. Symbols describe how graphics and features
 look on a map. Different symbols are used with different geometry
 types.  Line symbols are used to display graphics and features which are based on
 polyline geometries.
 
 @since 100
 */

@interface AGSLineSymbol : AGSSymbol
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

#pragma mark -
#pragma mark properties

/** Color of the line
 @since 100
 */
@property (nonatomic, strong, readwrite) AGSColor *color;

/** Width of the line, in points (not pixels)
 @since 100
 */
@property (nonatomic, assign, readwrite) CGFloat width;

/** Whether the line should be anti-aliased. Defaults to true.
 @since 100
 */
@property (nonatomic, assign, readwrite) BOOL antialias;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END
@end
