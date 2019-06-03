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

#import "AGSObject.h"
@class AGSPoint;

/*@file AGSCamera.h */

/** @brief A camera to represent 3D viewpoints of a secene
 
 Instances of this class represent a camera used to specify 3D viewpoints for `AGSSceneView`. It defines the perspective of a scene. 
 
 A Camera object can be thought of as a physical camera that one would look through to see a viewable extent and perspective of the Earth. Depending on how you hold the camera and how far away from the ground will determine what you can see. These positions of holding the camera represent the various properties that you can set on the camera. A camera has a location, heading, and a pitch.
 
 <ul>
  <li>Location - the 3D point in space where the Camera is located. The Camera cannot be located at heights below the `AGSScene#baseSurface`.
  <li>Heading - a value from 0 to 360. Represents the angle clockwise from north in a ENU (East, North, Up Ground reference frames). Negative headings are allowed and heading can wrap around (i.e 361 wraps to a value of 1).
  <li>Pitch - a value from 0 to 180. Represents the angle applied to the camera when rotating around its Y axis in a ENU. 0 is looking straight down towards the center of the planet, 180 looking straight up (sky). Negative pitches are not allowed and values do not wrap around.
 </ul>

 A camera can be created from scratch by specifying location, heading and pitch values. It is immutable which means once it is created it cannot be modified. For convenience, you can produce new cameras by applying offset values to an existing camera.
 
 @since 100
 */
@interface AGSCamera : AGSObject

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

/** Initialize a new camera based on the provided arguments.
 @param latitude component of the camera's coordinates
 @param longitude component of the camera's coordinates
 @param altitude the camera's height in meters from the sea level, may be negative
 @param heading in degrees, may be negative. This is the angle, clockwise, from North in an ENU.
 @param pitch in degrees, may not be negative. This is the angle of rotation around the Y-axis in an ENU.
 @param roll in degrees. This is the angle of rotation around the X-axis in an ENU.
 @return An intialized camera
 @since 100
 */
-(instancetype)initWithLatitude:(double)latitude longitude:(double)longitude altitude:(double)altitude heading:(double)heading pitch:(double)pitch roll:(double)roll;

/** Initialize a new camera based on the provided arguments.
 @param latitude component of the camera's coordinates
 @param longitude component of the camera's coordinates
 @param altitude the camera's height in meters from the sea level, may be negative
 @param heading in degrees, may be negative. This is the angle, clockwise, from North in an ENU.
 @param pitch in degrees, may not be negative. This is the angle of rotation around the Y-axis in an ENU.
 @param roll in degrees. This is the angle of rotation around the X-axis in an ENU.
 @return An intialized camera
 @since 100
 */
+(instancetype)cameraWithLatitude:(double)latitude longitude:(double)longitude altitude:(double)altitude heading:(double)heading pitch:(double)pitch roll:(double)roll;

/** Initialize a new camera based on the provided arguments.
 @param locationPoint specifying the camera's coordinates
 @param heading in degrees, may be negative. This is the angle, clockwise, from North in an ENU.
 @param pitch in degrees, may not be negative. This is the angle of rotation around the Y-axis in an ENU.
 @param roll in degrees. This is the angle of rotation around the X-axis in an ENU.
 @return An intialized camera
 @since 100
 */
-(instancetype)initWithLocation:(AGSPoint *)locationPoint heading:(double)heading pitch:(double)pitch roll:(double)roll;

/** Initialize a new camera based on the provided arguments.
 @param locationPoint specifying the camera's coordinates
 @param heading in degrees, may be negative. This is the angle, clockwise, from North in an ENU.
 @param pitch in degrees, may not be negative. This is the angle of rotation around the Y-axis in an ENU.
 @param roll in degrees. This is the angle of rotation around the X-axis in an ENU.
 @return An intialized camera
 @since 100
 */
+(instancetype)cameraWithLocation:(AGSPoint *)locationPoint heading:(double)heading pitch:(double)pitch roll:(double)roll;

/** Initialize a new camera based on the provided arguments and a location to look at.
 @note the given `lookAtPoint` may not be always visible on screen. You can check its visibility using `AGSSceneView#locationToScreen:`.
 @param lookAtPoint coordinates of the location for the camera to look at
 @param distance of the camera from the look at point, in meters; may not be negative
 @param heading in degrees, may be negative. This is the angle, clockwise, from North in an ENU.
 @param pitch in degrees, may not be negative. This is the angle of rotation around the Y-axis in an ENU.
 @param roll in degrees. This is the angle of rotation around the X-axis in an ENU.
 @return An intialized camera
 @since 100
 */
-(instancetype)initWithLookAtPoint:(AGSPoint *)lookAtPoint distance:(double)distance heading:(double)heading pitch:(double)pitch roll:(double)roll;

/** Initialize a new camera based on the provided arguments and a location to look at.
 @note the given `lookAtPoint` may not be always visible on screen. You can check its visibility using `AGSSceneView#locationToScreen:`.
 @param lookAtPoint coordinates of the location for the camera to look at
 @param distance of the camera from the look at point, in meters; may not be negative
 @param heading in degrees, may be negative. This is the angle, clockwise, from North in an ENU.
 @param pitch in degrees, may not be negative. This is the angle of rotation around the Y-axis in an ENU.
 @param roll in degrees. This is the angle of rotation around the X-axis in an ENU.
 @return An intialized camera
 @since 100
 */
+(instancetype)cameraWithLookAtPoint:(AGSPoint *)lookAtPoint distance:(double)distance heading:(double)heading pitch:(double)pitch roll:(double)roll;

#pragma mark -
#pragma mark properties

/** The camera's heading in degrees. This is the angle, clockwise, from North in an ENU.
 Value ranges from 0 to 360 degrees. The heading property can be thought of as a rotation value assuming that you were having the lens of the camera pointing directly at the ground. As you adjust the heading from 0 to 360 degrees, you would rotate (aka. spin) the camera in a counter-clockwise fashion.
 @since 100
 */
@property (nonatomic, assign, readonly) double heading;

/** The camera's location in space. It can be thought of as the physical position on/above the Earth that the camera is sitting when you look though it. If the `Z` value of the point is 0, that would mean the camera is sitting directly on the surface of the Earth, otherwise the value is assumed to signify meters above sea level.
 @since 100
 */
@property (nonatomic, strong, readonly) AGSPoint* location;

/** The camera's pitch in degrees. This is the angle of rotation around the Y-axis in an ENU.
 Value ranges from 0 to 180 degrees, where 0 is looking straight down (center of the earth) and 180 looking straight up (towards outer space).
 
 @since 100
 */
@property (nonatomic, assign, readonly) double pitch;

/** The camera's roll in degrees. This is the angle of rotation around the X-axis in an ENU.
 Value ranges from 0 to 360 degrees, where 0 is horizontal.
 @since 100
 */
@property (nonatomic, assign, readonly) double roll;

#pragma mark -
#pragma mark methods

/** Creates a new camera that is based on the current camera after adjusting its elevation.
 @param deltaAltitude that elevation change in meters; can be positive or negative, however the camera will only move as low as the `AGSScene#baseSurface` allows.
 @return a new camera
 @since 100
 */
-(AGSCamera*)elevateWithDeltaAltitude:(double)deltaAltitude;

/** Creates a new camera that is based on the current camera after moving its location in the direction the camera is facing.
 @param distance to move in meters, may not be negative
 @return a new camera
 @since 100
 */
-(AGSCamera*)moveForwardWithDistance:(double)distance;

/** Create a new camera that is based on the current camera after changing its location.
 @param location for the new camera
 @return a new camera
 @since 100
 */
-(AGSCamera*)moveToLocation:(AGSPoint*)location;


/** Create a new camera that is based on the current camera after moving its location in the direction of the given target point.
 @param targetPoint location to move towards
 @param distance to move in meters, may not be negative
 @return a new camera
 @since 100
 */
-(AGSCamera*)moveTowardTargetPoint:(AGSPoint *)targetPoint distance:(double)distance;

/** Create a new camera that is based on the current camera after rotating around the target point.
 The target point will not change on the screen if it was on the screen to begin with. The distance between
 the previous camera location and the target point will be the same as between the new camera location and the target point.
 @param targetPoint to rotate around
 @param deltaHeading the heading change in degrees, may be negative
 @param deltaPitch the pitch change in degrees, may be negative
 @param deltaRoll the roll change in degrees
 @return a new camera
 @since 100
 */
-(AGSCamera*)rotateAroundTargetPoint:(AGSPoint*)targetPoint deltaHeading:(double)deltaHeading deltaPitch:(double)deltaPitch deltaRoll:(double)deltaRoll;

/** Create a new camera that is based on the current camera after changing its heading, pitch, and roll.
 @param heading for the new camera
 @param pitch for the new camera
 @param roll for the new camera
 @return a new camera
 @since 100
 */
-(AGSCamera*)rotateToHeading:(double)heading pitch:(double)pitch roll:(double)roll;

/** Create a new camera that is based on the current camera after moving its location in the direction of the given target point by the specified zoom factor.
 @param targetPoint location to move towards
 @param factor specifiying how much to move the new camera based on the distance between the current camera location and the target point. For e.g. a factor of 2 will divide that distance in half for the new camera. Negative values will have no effect.
 @return a new camera
 @since 100
 */
-(AGSCamera*)zoomTowardTargetPoint:(AGSPoint*)targetPoint factor:(double)factor;

NS_ASSUME_NONNULL_END

@end
