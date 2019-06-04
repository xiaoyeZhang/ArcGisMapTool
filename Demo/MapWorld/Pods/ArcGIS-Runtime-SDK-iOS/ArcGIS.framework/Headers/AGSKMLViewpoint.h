/*
 COPYRIGHT 2018 ESRI
 
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

/** @file AGSKMLViewpoint.h */ //Required for Globals API doc

/** @brief The KML viewpoint specifies a vantage point for looking at a node.
 A KML viewpoint contains information about a viewer's position, either defined as a
 [LookAt](https://developers.google.com/kml/documentation/kmlreference#lookat) relationship to another object or a camera.
 See the guide documentation and samples for information about converting KML viewpoints into Runtime viewpoints.
 
 @since 100.4
 */
@interface AGSKMLViewpoint : AGSObject

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** The altitude mode, which determines how altitude values should be interpreted.
 @since 100.4
 */
@property (nonatomic, assign, readonly) AGSKMLAltitudeMode altitudeMode;

/** The viewpoint's type (camera or LookAt). Camera viewpoints define the position of the camera directly.
 LookAt viewpoints define the position of the camera relative to a point of interest.
 @since 100.4
 */
@property (nonatomic, assign, readonly) AGSKMLViewpointType type;

/** The viewpoint's heading in degrees. Ranges from 0 (North) to 360, with 90 being East.
 @since 100.4
 */
@property (nonatomic, assign, readonly) double heading;

/** The viewpoint's location, which is either the position of the camera or the observed point depending on the `#type`.
 @since 100.4
 */
@property (nonatomic, strong, readonly) AGSPoint *location;

/** The viewpoint's range is the distance in meters between the location and the camera.
 @note Applies to `LookAt` viewpoints only.
 @since 100.4
 */
@property (nonatomic, assign, readonly) double range;

/** The viewpoint's roll is the rotation of the camera around the Z axis. Values range from -180 to 180 degrees.
 @since 100.4
 */
@property (nonatomic, assign, readonly) double roll;

/** The KML viewpoint's pitch is the angle between the camera and the target location. 0 means the camera should point
 straight down towards the Earth. 90 means the camera is looking from/towards the horizon. Values between 90 and 180 indicate
 the camera should point towards the sky.
 @note This correspond to the `tilt` property from the KML specification.
 @since 100.4
 */
@property (nonatomic, assign, readonly) double pitch;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end

