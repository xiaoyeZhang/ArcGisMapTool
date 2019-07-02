/*
 COPYRIGHT 2019 ESRI
 
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

@class AGSKMLTour;

NS_ASSUME_NONNULL_BEGIN

/** @file AGSKMLTourController.h */ //Required for Globals API doc

/** @brief The KML tour controller, which can be used to control the playback of KML tours.
 
 @since 100.5
 */
@interface AGSKMLTourController : AGSObject

#pragma mark -
#pragma mark initializers

/** Initialize a new tour controller
 @return A new initialized tour controller
 @remark To monitor the status of the tour, see @c AGSKMLTour#tourStatus.
 @since 100.5
 */
+(instancetype)KMLTourController;

#pragma mark -
#pragma mark properties

/** The total duration of the associated tour. The total duration changes can be monitored using Key-Value Observing (KVO).
 @since 100.5
 */
@property (nonatomic, assign, readonly) NSTimeInterval totalDuration;

/** The associated KML tour.
 @since 100.5
 */
@property (nullable, nonatomic, strong, readwrite) AGSKMLTour *tour;

#pragma mark -
#pragma mark methods

/** Plays the associated tour, which may include audio content.
 @remark If the tour is in the paused state, playing will resume where the tour was left off.
 @since 100.5
 */
-(void)play;

/** Pauses the associated tour.
 @since 100.5
 */
-(void)pause;

/** Resets the associated tour.
 @since 100.5
 */
-(void)reset;

@end

NS_ASSUME_NONNULL_END
