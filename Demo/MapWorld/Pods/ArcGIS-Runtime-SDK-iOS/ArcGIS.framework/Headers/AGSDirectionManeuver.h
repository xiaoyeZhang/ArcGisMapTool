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

@class AGSGeometry;
@class AGSDirectionMessage;
@class AGSDirectionEvent;

/** @file AGSDirectionManeuver.h */ //Required for Globals API doc

/** @brief A single maneuver in a series of driving direction
 
 Instances of this class represent an individual maneuver in a series of turn-by-turn driving directions.
 
 @since 100
 */
@interface AGSDirectionManeuver : AGSObject
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** Events along the maneuver
 @since 100
 */
@property (nonatomic, copy, readonly) NSArray<AGSDirectionEvent*> *directionEvents;

/** User-friendly text describing the maneuver
 @since 100
 */
@property (nonatomic, copy, readonly) NSString *directionText;

/** Estimated time of arrival at the destination of this manuever in the current locale of the device.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) NSDate *estimatedArriveTime;

/** Time zone shift in minutes (based on the destination of this manuever) for the estimated arrival time.
 @since 100
 */
@property (nonatomic, assign, readonly) double estimatedArrivalTimeShift;

/** The detailed messages describing this manuever
 @since 100
 */
@property (nonatomic, copy, readonly) NSArray<AGSDirectionMessage*> *maneuverMessages;

/** The logical level at the start of the maneuver.
 The `fromLevel` and `toLevel` properties are defined to provide a way to filter directions based on logical level division. For example, a 3D routing application might render a 2D map with route lines
 filtered by vertical level instead of displaying overlapping lines on different levels.
 The `fromLevel` and `toLevel` properties are populated from source data and not calculated
 by the directions engine. If the source data does not contain "LevelFrom" and "LevelTo" fields, the
 properties will be populated with -1 values
 @since 100.2
 */
@property (nonatomic, assign, readonly) NSInteger fromLevel;

/** Geometry representing the maneuver, be it a turn or travelling in a straight line.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSGeometry *geometry;

/** The maneuver type
 @since 100
 */
@property (nonatomic, assign, readonly) AGSDirectionManeuverType maneuverType;

/** The logical level at the end of the maneuver.
 The `fromLevel` and `toLevel` properties are defined to provide a way to filter directions based on logical level division. For example, a 3D routing application might render a 2D map with route lines
 filtered by vertical level instead of displaying overlapping lines on different levels.
 The `fromLevel` and `toLevel` properties are populated from source data and not calculated
 by the directions engine. If the source data does not contain "LevelFrom" and "LevelTo" fields, the
 properties will be populated with -1 values
 @since 100.2
 */
@property (nonatomic, assign, readonly) NSInteger toLevel;

/** Length (in meters) of the maneuver
 @since 100
 */
@property (nonatomic, assign, readonly) double length;

/** Duration (in minutes) of the maneuver
 @since 100
 */
@property (nonatomic, assign, readonly) double duration;

NS_ASSUME_NONNULL_END
@end
