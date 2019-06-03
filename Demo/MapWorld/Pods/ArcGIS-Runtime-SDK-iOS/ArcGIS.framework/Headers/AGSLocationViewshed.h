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

@class AGSCamera;
@class AGSPoint;

#import "AGSViewshed.h"

/** @file AGSLocationViewshed.h */ //Required for Globals API doc

/** @brief Analysis of viewshed for a specified location
 
 Instances of this class represent an analysis object that renders a viewshed for a specified location. The viewshed determines visible and non-visible areas in a scene view for an observer.
 
 @license{Standard}
 @ingroup licensing
 @since 100.2
 */
@interface AGSLocationViewshed : AGSViewshed
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

/** Initialize a viewshed analysis object whose observer is defined using a point location of the provided camera. The provided distance range defines the analysis frustum over which visibility is calculated from the camera/observer location. Terrain and other obstacles between the observer and the minimum distance are excluded from the analysis, as are areas beyond the maximum distance.
 @param camera defining the observer's location
 @param minDistance The minimum distance (in meters) from the observer at which visibility will be evaluated.
 @param maxDistance The maximum distance (in meters) from the observer at which visibility will be evaluated.
 @return Initialized viewshed analysis
 @since 100.2
 */
-(instancetype)initWithCamera:(AGSCamera *)camera
                  minDistance:(double)minDistance
                  maxDistance:(double)maxDistance;

/** Initialize a viewshed analysis object whose observer's locaiton is defined using the provided camera. The provided distance range defines the analysis frustum over which visibility is calculated from the camera/observer location. Terrain and other obstacles between the observer and the minimum distance are excluded from the analysis, as are areas beyond the maximum distance.
 @param camera defining the observer's location
 @param minDistance The minimum distance (in meters) from the observer at which visibility will be evaluated.
 @param maxDistance The maximum distance (in meters) from the observer at which visibility will be evaluated.
 @return Initialized viewshed analysis
 @since 100.2
 */
+(instancetype)locationViewshedWithCamera:(AGSCamera *)camera
                              minDistance:(double)minDistance
                              maxDistance:(double)maxDistance;

/** Initialize a viewshed analysis object whose observer is defined using the provided location, heading, pitch, and view angles. The provided distance range defines the analysis frustum over which visibility is calculated from the camera/observer location. Terrain and other obstacles between the observer and the minimum distance are excluded from the analysis, as are areas beyond the maximum distance.
 @param location A geographic point location for the observer.
 @param heading The heading value (azimuth) that defines the observer's view direction
 @param pitch The pitch value (angle) of the observer's view. Valid values are from 0 (looking straight down) to 180 (straight up).
 @param horizontalAngle The horizontal angle of the observer's view. Must be greater than zero and less than or equal to 360.
 @param verticalAngle The vertical angle of the observer's view. Must be greater than zero and less than or equal to 360.
 @param minDistance The minimum distance (in meters) from the observer at which visibility will be evaluated.
 @param maxDistance The maximum distance (in meters) from the observer at which visibility will be evaluated.
 @return Initialized viewshed analysis
 @since 100.2
 */
-(instancetype)initWithLocation:(AGSPoint *)location
                        heading:(double)heading
                          pitch:(double)pitch
                horizontalAngle:(double)horizontalAngle
                  verticalAngle:(double)verticalAngle
                    minDistance:(double)minDistance
                    maxDistance:(double)maxDistance;

/** Initialize a viewshed analysis object whose observer is defined using the provided location, heading, pitch, and view angles. The provided distance range defines the analysis frustum over which visibility is calculated from the camera/observer location. Terrain and other obstacles between the observer and the minimum distance are excluded from the analysis, as are areas beyond the maximum distance.
 @param location A geographic point location for the observer.
 @param heading The heading value (azimuth) that defines the observer's view direction
 @param pitch The pitch value (angle) of the observer's view. Valid values are from 0 (looking straight down) to 180 (straight up).
 @param horizontalAngle The horizontal angle of the observer's view. Must be greater than zero and less than or equal to 360.
 @param verticalAngle The vertical angle of the observer's view. Must be greater than zero and less than or equal to 360.
 @param minDistance The minimum distance (in meters) from the observer at which visibility will be evaluated.
 @param maxDistance The maximum distance (in meters) from the observer at which visibility will be evaluated.
 @return Initialized viewshed analysis
 @since 100.2
 */
+(instancetype)locationViewshedWithLocation:(AGSPoint *)location
                                    heading:(double)heading
                                      pitch:(double)pitch
                            horizontalAngle:(double)horizontalAngle
                              verticalAngle:(double)verticalAngle
                                minDistance:(double)minDistance
                                maxDistance:(double)maxDistance;

#pragma mark -
#pragma mark properties

/** Observer location from which the viewshed is calculated.
 @since 100.2
 */
@property (nonatomic, strong, readwrite) AGSPoint *location;

/** Observer's heading. It represents the azimuth of the observer's direction of view.
 @since 100.2
 */
@property (nonatomic, assign, readwrite) double heading;

/** Pitch of the observer's field of vision. It is the angle of the observer's field of vision relative to the surface.  Valid values are from 0 (looking straight down) to 180 (straight up).
 @since 100.2
 */
@property (nonatomic, assign, readwrite) double pitch;

#pragma mark -
#pragma mark methods


/** Updates the frustum of the viewshed using the properties of the supplied Camera.
 @param camera used to update the position, pitch, and heading of the viewshed frustum.
 @since 100.2
 */
-(void)updateFromCamera:(AGSCamera *)camera;

NS_ASSUME_NONNULL_END
@end
