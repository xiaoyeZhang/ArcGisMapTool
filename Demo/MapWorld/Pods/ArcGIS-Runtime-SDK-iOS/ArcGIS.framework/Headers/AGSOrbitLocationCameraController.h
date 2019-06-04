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

#import "AGSCameraController.h"

@class AGSPoint;

/** @file AGSOrbitLocationCameraController.h */ //Required for Globals API doc

/** @brief A controller which allows a scene view's camera to orbit a fixed location
 
 Instances of this class represent a controller which allows a scene view's camera to orbit a stationary target location. Interactions on the scene view will pivot the camera around the target so that the camera is always looking at the target.
 
 To activate this controller, you need to set it on the scene view using `AGSSceneView#cameraController`. Programmatically setting the viewpoint on the scene view will be disabled when this controller is active.
 
 @since 100.1
 */
@interface AGSOrbitLocationCameraController : AGSCameraController

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

/** Initialize the camera controller to orbit around the provided location at the specified distance. The target location cannot be changed once specified.
 @param targetLocation to orbit around
 @param distance in meters from the `targetLocation` at which to orbit
 @return Initialized camera controller
 @since 100.1
 */
-(instancetype)initWithTargetLocation:(AGSPoint *)targetLocation distance:(double)distance;

/** Initialize the camera controller to orbit around the provided location at the specified distance. The target location cannot be changed once specified.
 @param targetLocation to orbit around
 @param distance in meters from the `targetLocation` at which to orbit
 @return Initialized camera controller
 @since 100.1
 */
+(instancetype)orbitLocationCameraControllerWithTargetLocation:(AGSPoint *)targetLocation distance:(double)distance;

/** Initialize the camera controller to orbit around the provided location starting from the specified camera position. The target location cannot be changed once specified.
@param targetLocation to orbit around
@param cameraLocation specifying the position from which to begin the orbit
@return Initialized camera controller
@since 100.3
*/
-(instancetype)initWithTargetLocation:(AGSPoint *)targetLocation cameraLocation:(AGSPoint *)cameraLocation;

/** Initialize the camera controller to orbit around the provided location starting from the specified camera position. The target location cannot be changed once specified.
 @param targetLocation to orbit around
 @param cameraLocation specifying the position from which to begin the orbit
 @return Initialized camera controller
 @since 100.3
 */
+(instancetype)orbitLocationCameraControllerWithTargetLocation:(AGSPoint *)targetLocation cameraLocation:(AGSPoint *)cameraLocation;

#pragma mark -
#pragma mark properties

/** The distance between the camera and the target, in meters. The camera position is derived from this distance plus the camera heading and pitch offsets.
 @since 100.1
 */
@property (nonatomic, assign, readwrite) double cameraDistance;

/** The camera heading offset relative to the target, in degrees. It is a measure of the clockwise angle in the target location's horizontal plane starting from due South. The default value is 0 degrees. 

 If this value is not in the range between `#minCameraHeadingOffset` and `#maxCameraHeadingOffset`, it will be normalized as follows:
 @li if `cameraHeadingOffset` < `minCameraHeadingOffset`, then 360 will be added until the new value is above `minCameraHeadingOffset`. If the new value is less than `maxCameraHeadingOffset`, it will be used. Otherwise, the value will be set to `minCameraHeadingOffset`
 @li if `cameraHeadingOffset` > `maxCameraHeadingOffset`, then 360 will be subtracted until the new value is below `maxCameraHeadingOffset`. If the new value is greater than `minCameraHeadingOffset`, it will be used. Otherwise, the value will be set to `maxCameraHeadingOffset`.

 
 @since 100.1
 */
@property (nonatomic, assign, readwrite) double cameraHeadingOffset;

/** The camera pitch offset relative to the target, in degrees. It is a measure of the counterclockwise angle from the positive Z axis through the target to the target's horizontal plane. The default value is 45 degrees.
 
 The value will be clamped to `#minCameraPitchOffset` and `#maxCameraPitchOffset`.
 @since 100.1
 */
@property (nonatomic, assign, readwrite) double cameraPitchOffset;

/** Indicates if the camera's distance to the target can be changed by user-interaction, for example zooming.
 @since 100.1
 */
@property (nonatomic, assign, readwrite, getter=isCameraDistanceInteractive) BOOL cameraDistanceInteractive;

/** Indicates if the camera's heading relative to the target can be changed by user-interaction, for example panning horizontally.
 @since 100.1
 */
@property (nonatomic, assign, readwrite, getter=isCameraHeadingOffsetInteractive) BOOL cameraHeadingOffsetInteractive;

/** Indicates if the camera's pitch relative to the target can be changed by user-interaction, for example panning vertically.
 @since 100.1
 */
@property (nonatomic, assign, readwrite, getter=isCameraPitchOffsetInteractive) BOOL cameraPitchOffsetInteractive;

/** The maximum distance from the camera to the `#targetLocation` in meters. Interactions and animations obey this limit.
 Serves as the max value for `#cameraDistance`.
 @since 100.1
 */
@property (nonatomic, assign, readwrite) double maxCameraDistance;

/** The maximum camera heading offset relative to the target, in degrees. Default value is 180. Interactions and animations obey this limit.
 Serves as the max value for `#cameraHeadingOffset`.
 @since 100.1
 */
@property (nonatomic, assign, readwrite) double maxCameraHeadingOffset;

/** The maximum camera pitch offset relative to the target, in degrees. Interactions and animations obey this limit.
 Serves as the max value for `#cameraPitchOffset`.
 @since 100.1
 */
@property (nonatomic, assign, readwrite) double maxCameraPitchOffset;

/** The minimum distance from the camera to the `#targetLocation` in meters. Interactions and animations obey this limit.
 Serves as the min value for `#cameraDistance`.
 @since 100.1
 */
@property (nonatomic, assign, readwrite) double minCameraDistance;

/** The minimum camera heading offset relative to the target, in degrees. Default value is -180. Interactions and animations obey this limit.
 Serves as the min value for `#cameraHeadingOffset`.
 @since 100.1
 */
@property (nonatomic, assign, readwrite) double minCameraHeadingOffset;

/** The minimum camera pitch offset relative to the target, in degrees. Interactions and animations obey this limit.
 Serves as the min value for `#cameraPitchOffset`.
 @since 100.1
 */
@property (nonatomic, assign, readwrite) double minCameraPitchOffset;

/** The location that the camera should orbit.
 @since 100.1
 */
@property (nonatomic, strong, readonly) AGSPoint *targetLocation;

#pragma mark -
#pragma mark methods

/** Moves the camera with animation to a new offset position.
 @param distanceDelta the change in distance to apply in the animation, in meters
 @param headingDelta the change in heading to apply in the animation, in degrees
 @param pitchDelta the change in pitch to apply in the animation, in degrees
 @param duration of the animation, in seconds
 @param completion block which is invoked when operation completes. The `finished` argument indicates whether animation finished without any user interruption.
 @note The heading and pitch delta values may be greater than 360 degrees and the angle is not normalized. For example, a heading delta of 720 will make the camera do two circles around the target within the duration time.
 @return operation that can be cancelled
 @since 100.1
 */
 -(id<AGSCancelable>)moveCameraWithDistanceDelta:(double)distanceDelta
                                   headingDelta:(double)headingDelta
                                     pitchDelta:(double)pitchDelta
                                       duration:(NSTimeInterval)duration
                                     completion:(nullable void(^)(BOOL finished))completion;

NS_ASSUME_NONNULL_END

@end

