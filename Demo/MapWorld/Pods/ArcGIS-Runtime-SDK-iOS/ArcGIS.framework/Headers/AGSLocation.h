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

@class AGSPoint;

/** @file AGSLocation.h */

/** @brief Represents a location update provided by a location datasource
 
 Instance of this class represent a location update that is provided by a location datasource. 
 
 @since 100
 @see AGSLocationDisplay
 @see AGSLocationDataSource
 */
@interface AGSLocation : AGSObject
NS_ASSUME_NONNULL_BEGIN


#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

/** Initializes a location update with provided information.
 @param position The coordinates of the location
 @param horizontalAccuracy The radius of uncertainty for the location, measured in meters.
 @param velocity at which the device is traveling in meters per second
 @param course The direction in which the device is traveling, measured in degrees starting at due north and continuing clockwise around the compass.
 @param lastKnown Indicates whether the information is current or based on a last known update (for example, in the case of deferred location updates).
 @return An initialized representation of a location update
 @since 100
 */
-(instancetype)initWithPosition:(AGSPoint*)position horizontalAccuracy:(double)horizontalAccuracy velocity:(double)velocity course:(double)course lastKnown:(BOOL)lastKnown;

/** Initializes a location update with the provided information
 @param position The coordinates of the location
 @param timestamp The date and time the location was determined
 @param horizontalAccuracy The radius of uncertainty for the location, measured in meters.
 @param verticalAccuracy The accuracy of the vertical component of the location, measured in meters.
 @param velocity at which the device is traveling in meters per second
 @param course The direction in which the device is traveling, measured in degrees starting at due north and continuing clockwise around the compass.
 @param lastKnown Indicates whether the information is current or based on a last known update (for example, in the case of deferred location updates).
 @return An initialized representation of a location update
 @since 100.2.1
 */
-(instancetype)initWithPosition:(AGSPoint*)position
                      timestamp:(NSDate*)timestamp
             horizontalAccuracy:(double)horizontalAccuracy
               verticalAccuracy:(double)verticalAccuracy
                       velocity:(double)velocity
                         course:(double)course
                      lastKnown:(BOOL)lastKnown;

/** Initializes a location update with the provided information
 @param position The coordinates of the location
 @param horizontalAccuracy The radius of uncertainty for the location, measured in meters.
 @param velocity at which the device is traveling in meters per second
 @param course The direction in which the device is traveling, measured in degrees starting at due north and continuing clockwise around the compass.
 @param lastKnown Indicates whether the information is current or based on a last known update (for example, in the case of deferred location updates).
 @return An initialized representation of a location update
 @since 100
 */

+(instancetype)locationWithPosition:(AGSPoint*)position horizontalAccuracy:(double)horizontalAccuracy velocity:(double)velocity course:(double)course lastKnown:(BOOL)lastKnown;

/** Initializes a location update with the provided information
 @param position The coordinates of the location
 @param timestamp The date and time the location was determined
 @param horizontalAccuracy The radius of uncertainty for the location, measured in meters.
 @param verticalAccuracy The accuracy of the vertical component of the location, measured in meters.
 @param velocity at which the device is traveling in meters per second
 @param course The direction in which the device is traveling, measured in degrees starting at due north and continuing clockwise around the compass.
 @param lastKnown Indicates whether the information is current or based on a last known update (for example, in the case of deferred location updates).
 @return An initialized representation of a location update
 @since 100.2.1
 */
+(instancetype)locationWithPosition:(AGSPoint*)position
                          timestamp:(NSDate*)timestamp
                 horizontalAccuracy:(double)horizontalAccuracy
                   verticalAccuracy:(double)verticalAccuracy
                           velocity:(double)velocity
                             course:(double)course
                          lastKnown:(BOOL)lastKnown;

/** Initializes a location update with the provided information
 @note If the provided `CLLocation` has a timestamp more than 30 seconds in the past, the returned `AGSLocation` will have `#lastKnown` set to true, otherwise it will be considered current and `lastKnown` will be false.
 @param cllocation representing the location data generated by `CLLocationManager`
 @return An initialized representation of a location update
 @since 100
 */
+(AGSLocation*)locationWithCLLocation:(CLLocation*)cllocation;

#pragma mark -
#pragma mark properties

/** The direction in which the device is traveling, measured in degrees starting at due north and continuing clockwise around the compass. Thus, north is 0 degrees, east is 90 degrees, south is 180 degrees, and so on. Course values may not be available on all devices. A negative value indicates that the direction is invalid.
 @since 100
 */
@property (nonatomic, assign, readonly) double course;

/** The radius of uncertainty for the location, measured in meters. The location’s `#position` identifies the center of the circle, and this value indicates the radius of that circle. A negative value indicates that the location’s position is invalid.
 @since 100
 */
@property (nonatomic, assign, readonly) double horizontalAccuracy;

/** Indicates whether the location information is current or based on a last known update (for example, in the case of deferred location updates). Last known locations are symbolized differently using `AGSLocationDisplay#acquiringSymbol`.
 @since 100
 */
@property (nonatomic, assign, readonly) BOOL lastKnown;

/** The coordinates of the location
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSPoint *position;

/** The instantaneous speed of the device in meters per second
 @since 100
 */
@property (nonatomic, assign, readonly) double velocity;

/** The time the location was determined.
 @since 100.2.1
 */
@property (nonatomic, strong, readonly) NSDate *timestamp;

/** The accuracy of the location's vertical component, in meters.
 @since 100.2.1
 */
@property (nonatomic, assign, readonly) double verticalAccuracy;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END
@end
