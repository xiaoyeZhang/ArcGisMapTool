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

/** @file AGSDirectionEvent.h */ //Required for Globals API doc

/** @brief An event along an `AGSDirectionManeuver`
 
 Instances of this class represent an event along an `AGSDirectionManeuver` for a given `AGSRoute`. Events are notifications about things that happen along a route (e.g. crossing an administrative border, violating some restriction such as a toll road or when time zone changes) but do not require any action from the user.
 @since 100
 */
@interface AGSDirectionEvent : AGSObject
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** Estimated time of arrival at the event location in the current locale of the device.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) NSDate *estimatedArrivalTime;

/** Time zone shift in minutes (based on the event location) for the estimated arrival time.
 @since 100
 */
@property (nonatomic, assign, readonly) double estimatedArrivalTimeShift;

/** Informational messages about this event
 @since 100
 */
@property (nonatomic, copy, readonly) NSArray<NSString*> *eventMessages;

/** Text describing the event
 @since 100
 */
@property (nonatomic, copy, readonly) NSString *eventText;

/** Location of the event
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSPoint *geometry;

NS_ASSUME_NONNULL_END
@end
