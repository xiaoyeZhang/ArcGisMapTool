/*
 COPYRIGHT 2016 ESRI
 
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

/** @file AGSMarkerSceneSymbol.h */ //Required for Globals API doc

/** @brief An abstract base class for 3D marker symbols
 
 Subclasses represent 3D marker symbols that can be rendered by `AGSSceneView` in a scene. Symbols describe how graphics and features
 look in a scene. Different symbols are used with different geometry
 types.  Marker symbols are used to display those graphics and features which are based on
 point or multipoint geometries.
 
 @since 100
*/
@interface AGSMarkerSceneSymbol : AGSSymbol

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

#pragma mark -
#pragma mark properties

/** Specifies how the symbol should be anchored in 3D space. Default is `Bottom`.
 @since 100
 */
@property (nonatomic, assign, readwrite) AGSSceneSymbolAnchorPosition anchorPosition;

/** Color of the 3D marker symbol
 @since 100
 */
@property (nonatomic, strong, readwrite) AGSColor *color;

/** Depth of the 3D marker symbol, in meters.
 @since 100
 */
@property (nonatomic, assign, readwrite) double depth;

/** Heading of the 3D marker symbol, degrees. Default value is 0
 @since 100
 */
@property (nonatomic, assign, readwrite) double heading;

/** Height of the 3D marker symbol, in meters.
 @since 100
 */
@property (nonatomic, assign, readwrite) double height;

/** Pitch of the 3D marker symbol, in degrees. Default value is 0.
 @since 100
 */
@property (nonatomic, assign, readwrite) double pitch;

/** Roll of the 3D marker symbol, in degrees. Default value is 0.
 @since 100
 */
@property (nonatomic, assign, readwrite) double roll;

/** Width of the 3D marker symbol, in meters.
 @since 100
 */
@property (nonatomic, assign, readwrite) double width;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end
