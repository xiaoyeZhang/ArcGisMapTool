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

/** @file AGSGlobeCameraController.h */ //Required for Globals API doc

/** @brief A controller to allow free-form roaming of a scene view's camera around the globe
 
 Instances of this class represent a controller which allows free-form positioning, orientation, and movement of a scene view's camera around the globe.
 
 To activate this controller, you need to set it on the scene view using `AGSSceneView#cameraController`.
 
 @since 100.1
 */
@interface AGSGlobeCameraController : AGSCameraController

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

+(instancetype)globeCameraController;

#pragma mark -
#pragma mark properties

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end

