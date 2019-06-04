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

@protocol AGSGeoElement;

/** @file AGSOrbitGeoElementCameraController.h */ //Required for Globals API doc

/** @brief A controller which allows a scene view's camera to orbit a geo-element
 
 Instances of this class represent a controller which allows a scene view's camera to orbit a stationary or moving target geo-element. Interactions on the scene view will pivot the camera around the target so that the camera is always looking at the target. The camera will move to maintain a fixed relative distance from a moving target, and it can even adjust its heading, pitch, and roll based on changes to geo-element's heading, pitch, and roll.
 
 To activate this controller, you need to set it on the scene view using `AGSSceneView#cameraController`. Programmatically setting the viewpoint on the scene view will be disabled when this controller is active.

 
 @since 100.1
 */
@interface AGSOrbitGeoElementCameraController : AGSCameraController

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

/** Initialize the camera controller to orbit around the provided geo-element at the specified distance. When the target moves, the camera will move with the target to maintain its relative position.
 @param targetGeoElement to orbit around
 @param distance in meters from the `targetGeoElement` at which to orbit
 @return Initialized camera controller
 @since 100.1
 */
-(instancetype)initWithTargetGeoElement:(id<AGSGeoElement>)targetGeoElement distance:(double)distance;

/** Initialize the camera controller to orbit around the provided geo-element at the specified distance. When the target moves, the camera will move with the target to maintain its relative position.
 @param targetGeoElement to orbit around
 @param distance in meters from the `targetGeoElement` at which to orbit
 @return Initialized camera controller
 @since 100.1
 */
+(instancetype)orbitGeoElementCameraControllerWithTargetGeoElement:(id<AGSGeoElement>)targetGeoElement distance:(double)distance;

#pragma mark -
#pragma mark properties

/** The distance between the camera and the target, in meters. The camera position is derived from this distance plus the camera heading and pitch offsets.
 @since 100.1
 */
@property (nonatomic, assign, readwrite) double cameraDistance;

/** The camera heading offset relative to the target's symbol, in degrees. It is a measure of the clockwise angle in the target symbol's horizontal plane starting directly behind the symbol. The default value is 0 degrees.
 
 If this value is not in the range between `#minCameraHeadingOffset` and `#maxCameraHeadingOffset`, it will be normalized as follows:
 @li if `cameraHeadingOffset` < `minCameraHeadingOffset`, then 360 will be added until the new value is above `minCameraHeadingOffset`. If the new value is less than `maxCameraHeadingOffset`, it will be used. Otherwise, the value will be set to `minCameraHeadingOffset`
 @li if `cameraHeadingOffset` > `maxCameraHeadingOffset`, then 360 will be subtracted until the new value is below `maxCameraHeadingOffset`. If the new value is greater than `minCameraHeadingOffset`, it will be used. Otherwise, the value will be set to `maxCameraHeadingOffset`.
 
 @see `#autoHeadingEnabled` to maintain the same camera heading relative to the target's symbol even when the target's heading changes.
 @since 100.1
 */
@property (nonatomic, assign, readwrite) double cameraHeadingOffset;

/** The camera pitch offset relative to the target's symbol, in degrees. It is a measure of the counterclockwise angle from the positive Z axis of the target's symbol to the symbol's horizontal plane. The default value is 45 degrees.

 The value will be clamped to `#minCameraPitchOffset` and `#maxCameraPitchOffset`.
 @see `#autoPitchEnabled` to keep the same relative pitch to the target's symbol even when the target changes its pitch
 @since 100.1
 */
@property (nonatomic, assign, readwrite) double cameraPitchOffset;

/** Indicates whether the camera's position changes in sync with the target's heading to keep that same `#cameraHeadingOffset` relative to the target's symbol.
 Default value is `true`. If set to `false`, you'll notice changes in the target's heading, otherwise the target's heading will appear constant even when it changes because the camera will re-position to offset it.
 @since 100.1
 */
@property (nonatomic, assign, readwrite, getter=isAutoHeadingEnabled) BOOL autoHeadingEnabled;

/** Indicates whether the camera's position changes in sync with the target's pitch to keep that same `#cameraPitchOffset` relative to the target's symbol. The default value is `true`. If set to `false`, you'll notice changes in the target's pitch, otherwise the target's pitch will appear constant even when it changes because the camera will re-position to offset it.
 @since 100.1
 */
@property (nonatomic, assign, readwrite, getter=isAutoPitchEnabled) BOOL autoPitchEnabled;

/** Indidates whether the camera's roll changes in sync with the target's roll. The default value is `true`. If set to `false`, you'll notice changes in the target's roll, otherwise the target's roll will appear constant even when it changes because the camera will offset it.
 @since 100.1
 */
@property (nonatomic, assign, readwrite, getter=isAutoRollEnabled) BOOL autoRollEnabled;

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

/** The maximum distance from the camera to the `#targetGeoElement` in meters. Interactions and animations obey this limit.
 Serves as the max value for `#cameraDistance`.
 @since 100.1
 */
@property (nonatomic, assign, readwrite) double maxCameraDistance;

/** The maximum camera heading offset relative to the target's symbol, in degrees. Default value is 180. Interactions and animations obey this limit.
 Serves as the max value for `#cameraHeadingOffset`.
 @since 100.1
 */
@property (nonatomic, assign, readwrite) double maxCameraHeadingOffset;

/** The maximum camera pitch offset relative to the target's symbol, in degrees. Interactions and animations obey this limit.
 Serves as the max value for `#cameraPitchOffset`.
 @since 100.1
 */
@property (nonatomic, assign, readwrite) double maxCameraPitchOffset;

/** The minimum distance from the camera to the `#targetGeoElement` in meters. Interactions and animations obey this limit.
 Serves as the min value for `#cameraDistance`.
 @since 100.1
 */
@property (nonatomic, assign, readwrite) double minCameraDistance;

/** The minimum camera heading offset relative to the target's symbol, in degrees. Default value is -180. Interactions and animations obey this limit.
 Serves as the min value for `#cameraHeadingOffset`.
 @since 100.1
 */
@property (nonatomic, assign, readwrite) double minCameraHeadingOffset;

/** The minimum camera pitch offset relative to the target's symbol, in degrees. Interactions and animations obey this limit.
 Serves as the min value for `#cameraPitchOffset`.
 @since 100.1
 */
@property (nonatomic, assign, readwrite) double minCameraPitchOffset;

/** The geo-element that the camera should orbit.
 @since 100.1
 */
@property (nonatomic, strong, readonly) id<AGSGeoElement> targetGeoElement;

/** Specifies the vertical position of the target on the screen. Allowed values range from 0 (bottom of screen) to 1 (top).
 Default value is 0.5; target is centered vertically on the screen.
 @since 100.1
 */
@property (nonatomic, assign, readwrite) float targetVerticalScreenFactor;

/** Specifies an offset of the target focus point relative to the target object in the X axis in the symbol coordinate system. A non-zero value offsets the camera target from the `#targetGeoElement` along the X axis. Default value is 0.
 @since 100.1
 */
@property (nonatomic, assign, readwrite) double targetOffsetX;

/** Specifies an offset of the target focus point relative to the target object in the Y axis in the symbol coordinate system. A non-zero value offsets the camera target from the `#targetGeoElement` along the Y axis. Default value is 0.
 @since 100.1
 */
@property (nonatomic, assign, readwrite) double targetOffsetY;

/** Specifies an offset of the target focus point relative to the target object in the Z axis in the symbol coordinate system. A non-zero value offsets the camera target from the `#targetGeoElement` along the Z axis. Default value is 0.
 @since 100.1
 */
@property (nonatomic, assign, readwrite) double targetOffsetZ;

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

/** Moves the camera with animation to focus on the target, offset by specified values.
 By default the camera focuses on the center of geo-element's geometry. The offsets move the focal point to a new position relative to that center.
 @param x offset along x-axis, in meters
 @param y offset along y-axis, in meters
 @param z offset along z-axis, in meters
 @param duration of the animation, in seconds
 @param completion block which is invoked when operation completes. The `finished` argument indicates whether animation finished without any user interruption.
 @return operation that can be cancelled
 @since 100.1
 */
-(id<AGSCancelable>)setTargetOffsetX:(double)x
                       targetOffsetY:(double)y
                       targetOffsetZ:(double)z
                            duration:(NSTimeInterval)duration
                          completion:(nullable void(^)(BOOL finished))completion;

NS_ASSUME_NONNULL_END

@end

