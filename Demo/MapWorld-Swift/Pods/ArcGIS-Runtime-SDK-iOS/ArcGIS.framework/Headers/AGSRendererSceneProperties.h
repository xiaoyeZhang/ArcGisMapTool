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

#import "AGSObject.h"

/** @file AGSRendererSceneProperties.h */ //Required for Globals API doc

/** @brief Renderer properties that apply only to graphics or features in 3D Scenes
 
 Instances of this class represent properties of a renderer that only apply when features or graphics are visualized through `AGSSceneView`.
 
 
 @since 100
 */
@interface AGSRendererSceneProperties : AGSObject

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

/** Initialize renderer scene properties with provided parameters
 @param extrusionExpression specifying how much the data should be extruded for display
 @param extrusionMode specifying how the data should be extruded
 @return Initialized renderer scene properties
 @since 100
 */
-(instancetype)initWithExtrusionExpression:(NSString *)extrusionExpression extrusionMode:(AGSExtrusionMode)extrusionMode;

/** Initialize renderer scene properties with provided parameters
 @param headingExpression specifying how much to adjust the heading of data for display
 @param pitchExpression specifying how much to adjust the pitch of data for display
 @param rollExpression specifying how much to adjust the roll of data for display
 @return Initialized renderer scene properties
 @since 100
 */
-(instancetype)initWithHeadingExpression:(NSString *)headingExpression pitchExpression:(NSString *)pitchExpression rollExpression:(NSString *)rollExpression;
+(instancetype)rendererSceneProperties;

/** Initialize renderer scene properties with provided parameters
 @param extrusionExpression specifying how much the data should be extruded for display
 @param extrusionMode specifying how the data should be extruded
 @return Initialized renderer scene properties
 @since 100
 */
+(instancetype)rendererScenePropertiesWithExtrusionExpression:(NSString *)extrusionExpression extrusionMode:(AGSExtrusionMode)extrusionMode;

/** Initialize renderer scene properties with provided parameters
 @param headingExpression specifying how much to adjust the heading of data for display
 @param pitchExpression specifying how much to adjust the pitch of data for display
 @param rollExpression specifying how much to adjust the roll of data for display
 @return Initialized renderer scene properties
 @since 100
 */
+(instancetype)rendererScenePropertiesWithHeadingExpression:(NSString *)headingExpression pitchExpression:(NSString *)pitchExpression rollExpression:(NSString *)rollExpression;

#pragma mark -
#pragma mark properties

/** Expression specifying how to extrude the geo-elements for display. The expression can contain the name of the
 attribute of the feature or graphic. For example, the expression `storeys * 3.5` indicates that the renderer
 will look up the value of the "storeys" attribute and multiply it by 3.5, and then use that value to extrude the data in z-direction. The value is interpreted to be in meters.
 
 When extrusion is applied to points, they are always extruded as cylinders irrespective of the style.
 @since 100
 @see `#extrusionMode`
 */
@property (nonatomic, copy, readwrite) NSString * extrusionExpression;

/** Mode specifying how the data should be extruded.
 @since 100
 @see  `#extrusionExpression`
 */
@property (nonatomic, assign, readwrite) AGSExtrusionMode extrusionMode;

/** Expression specifying how to adjust the heading of geo-elements for display. Heading is the angle, clockwise, from North in an ENU (East, North, Up Ground reference frames). Values range from 0 to 360 degrees.
 
 The expression can contain the name of an attribute of the feature or graphic. For example, the expression "[heading] + 15" indicates that the renderer will look up the value of the "heading" attribute and add 15 to it, and then use that value to set the heading of the geo-element.
 @since 100
 */
@property (nonatomic, copy, readwrite) NSString * headingExpression;

/** Expression specifying how to adjust the pitch of geo-elements. Pitch is the angle of rotation around the Y-axis in an ENU (East, North, Up Ground reference frames). Value ranges from 0 to 180 degrees, where 0 is looking straight down (center of the earth) and 180 looking straight up (towards outer space).
 
 The expression can contain the name of an attribute of the feature or graphic. For example, the expression "[tilt] - 90" indicates that the renderer will look up the value of the "tilt" attribute and subtract 90 from it, and then use that value to set the pitch of the geo-element.

 @since 100
 */
@property (nonatomic, copy, readwrite) NSString * pitchExpression;

/** Expression specifying how to adjust the roll of geo-elements for display. Roll is the angle of rotation around the X-axis in an ENU (East, North, Up Ground reference frames). Value ranges from 0 to 360 degrees, where 0 is horizontal.

 
 The expression can contain the name of an attribute of the feature or graphic. For example, the expression "[bank] - 180" indicates that the renderer will look up the value of the "bank" attribute and subtract 180 from it, and then use that value to set the roll of the geo-element.
 @since 100
 */
@property (nonatomic, copy, readwrite) NSString * rollExpression;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end

