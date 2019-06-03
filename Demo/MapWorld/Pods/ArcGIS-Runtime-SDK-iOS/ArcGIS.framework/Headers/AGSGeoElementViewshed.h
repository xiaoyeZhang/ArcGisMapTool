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

#import "AGSViewshed.h"

@protocol AGSGeoElement;

/** @file AGSGeoElementViewshed.h */ //Required for Globals API doc

/** @brief Analysis of viewshed for a specified geo-element
 
 Instances of this class represent an analysis object that renders a viewshed for a specified geo-element. The viewshed determines visible and non-visible areas in a scene view for an observer defined by the geo-element. The viewshed will be updated as the geo-element's location changes.
 
 @license{Standard}
 @ingroup licensing
 @since 100.2
 */
@interface AGSGeoElementViewshed : AGSViewshed
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

/** Initialize a viewshed analysis object whose observer is defined by the provided geo-element, view angles, and heading/pitch offsets. The provided distance range defines the analysis frustum over which visibility is calculated from the camera/observer location. Terrain and other obstacles between the observer and the minimum distance are excluded from the analysis, as are areas beyond the maximum distance.
 @param geoElement from which the position and orientation of the observer will be determined
 @param horizontalAngle The horizontal angle of the observer's view. Must be greater than zero and less than or equal to 360.
 @param verticalAngle The vertical angle of the observer's view. Must be greater than zero and less than or equal to 360.
 @param minDistance The minimum distance from the observer at which visibility will be evaluated.
 @param maxDistance The maximum distance from the observer at which visibility will be evaluated.
 @param headingOffset An angle offset relative to the heading of the geo-element to determine the direction of the observer's view.
 @param pitchOffset An angle offset relative to the pitch of the geo-element to determine the vertical angle of the observer's view. Valid values range from 0 to 180 degrees.
 @return Initialized viewshed analysis
 @since 100.2
 */
-(instancetype)initWithGeoElement:(id<AGSGeoElement>)geoElement
                  horizontalAngle:(double)horizontalAngle
                    verticalAngle:(double)verticalAngle
                      minDistance:(double)minDistance
                      maxDistance:(double)maxDistance
                    headingOffset:(double)headingOffset
                      pitchOffset:(double)pitchOffset;

/** Initialize a viewshed analysis object whose observer is defined by the provided geo-element, view angles, and heading/pitch offsets. The provided distance range defines the analysis frustum over which visibility is calculated from the camera/observer location. Terrain and other obstacles between the observer and the minimum distance are excluded from the analysis, as are areas beyond the maximum distance.
 @param geoElement from which the position and orientation of the observer will be determined
 @param horizontalAngle The horizontal angle of the observer's view. Must be greater than zero and less than or equal to 360.
 @param verticalAngle The vertical angle of the observer's view. Must be greater than zero and less than or equal to 360.
 @param minDistance The minimum distance from the observer at which visibility will be evaluated.
 @param maxDistance The maximum distance from the observer at which visibility will be evaluated.
 @param headingOffset An angle offset relative to the heading of the geo-element to determine the direction of the observer's view.
 @param pitchOffset An angle offset relative to the pitch of the geo-element to determine the vertical angle of the observer's view. Valid values range from 0 to 180 degrees.
 @return Initialized viewshed analysis
 @since 100.2
 */
+(instancetype)geoElementViewshedWithGeoElement:(id<AGSGeoElement>)geoElement
                                horizontalAngle:(double)horizontalAngle
                                  verticalAngle:(double)verticalAngle
                                    minDistance:(double)minDistance
                                    maxDistance:(double)maxDistance
                                  headingOffset:(double)headingOffset
                                    pitchOffset:(double)pitchOffset;

#pragma mark -
#pragma mark properties

/** Geo-element that represents the observer for the viewshed analysis. The observer's location, heading, and pitch are determined by the location and orientation of this geo-element.
 @since 100.2
 */
@property (nonatomic, strong, readonly) id<AGSGeoElement> geoElement;

/** The offset angle applied to the heading of the geo-element. The observer heading is determined by the geo-element heading plus the heading offset.
 @since 100.2
 */
@property (nonatomic, assign, readwrite) double headingOffset;

/** The offset angle applied to the pitch of the geo-element. The observer pitch is determined by the geo-element pitch plus the pitch offset. Valid values range from 0 to 180 degrees.
 @since 100.2
 */
@property (nonatomic, assign, readwrite) double pitchOffset;

/** The location offset in the X direction that defines the observer relative to the geo-element.
 
 The observer location is determined by the geo-element location plus the offset X,Y,Z values. Any rotations applied to the geo-element will also be applied to the X,Y,Z offsets. This allows the observer to be positioned relative to the geo-element and maintain the relative position even when the geo-element moves and rotates.
 
 @since 100.2
 */
@property (nonatomic, assign, readwrite) double offsetX;

/** The location offset in the Y direction that defines the observer relative to the geo-element.
 
 The observer location is determined by the geo-element location plus the offset X,Y,Z values. Any rotations applied to the geo-element will also be applied to the X,Y,Z offsets. This allows the observer to be positioned relative to the geo-element and maintain the relative position even when the geo-element moves and rotates.
 
 @since 100.2
 */
@property (nonatomic, assign, readwrite) double offsetY;

/** The location offset in the X direction that defines the observer relative to the geo-element.
 
 The observer location is determined by the geo-element location plus the offset X,Y,Z values. Any rotations applied to the geo-element will also be applied to the X,Y,Z offsets. This allows the observer to be positioned relative to the geo-element and maintain the relative position even when the geo-element moves and rotates.
 
 @since 100.2
 */
@property (nonatomic, assign, readwrite) double offsetZ;

NS_ASSUME_NONNULL_END
@end
