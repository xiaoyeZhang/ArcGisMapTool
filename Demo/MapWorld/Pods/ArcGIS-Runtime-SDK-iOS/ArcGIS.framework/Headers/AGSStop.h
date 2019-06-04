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
@class AGSNetworkLocation;

/** @file AGSStop.h */ //Required for Globals API doc

/** @brief A stop along a route
 
 Instances of this class represent stops - locations that must be visited along a route. Stops are part of  `AGSRouteParameters` which is used as input to `AGSRouteTask#solveRouteWithParameters:completion:`. You need atleast two stops to compute a route, although you can have more.
 
 @since 100
 */
@interface AGSStop : AGSObject <NSCopying>
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

/** Initialize the stop using the provided location
 @param point where the stop should be located
 @return A new stop
 @since 100
 */
-(instancetype)initWithPoint:(AGSPoint*)point;

/** Initialize the stop using the provided location
 @param point where the stop should be located
 @return A new stop
 @since 100
 */
+(instancetype)stopWithPoint:(AGSPoint*)point;

#pragma mark -
#pragma mark properties

/** Specifies the direction a vehicle arrives at this stop.
 @since 100
 */
@property (nonatomic, assign, readonly) AGSCurbApproach arrivalCurbApproach;

/** Specifies the direction a vehicle departs from the stop.
 @since 100
 */
@property (nonatomic, assign, readonly) AGSCurbApproach departureCurbApproach;

/** Specifies the direction a vehicle may arrive at or depart from the stop.
 For example, a school bus must approach and depart a school from its door side so that students entering/exiting the bus will not have to cross the street.

 @since 100
 */
@property (nonatomic, assign, readwrite) AGSCurbApproach curbApproach;

/** The current bearing in degrees.
 @since 100
 */
@property (nonatomic, assign, readwrite) double currentBearing;

/** The current bearing tolerance in degrees.
 @since 100
 */
@property (nonatomic, assign, readwrite) double currentBearingTolerance;

/** The distance to the closest location on the underlying network in meters.
 @since 100
 @see `#networkLocation`
 */
@property (nonatomic, assign, readonly) double distanceToNetworkLocation;

/** Location the stop should be placed.
 @since 100
 */
@property (nullable, nonatomic, strong, readwrite) AGSPoint *geometry;

/** Time of arrival at the stop.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) NSDate *arrivalTime;

/** Time zone shift in minutes for the arrival time.
 @since 100
 */
@property (nonatomic, assign, readonly) double arrivalTimeShift;

/** Time of departure from the stop.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) NSDate *departureTime;

/** Time zone shift in minutes for the departure time.
 @since 100
 */
@property (nonatomic, assign, readonly) double departureTimeShift;

/** The begining time of a permissible time window for the stop. The route will attempt to visit the stop only within its time window, if possible. Can be nil if you don't want to specify a time window constraint.
 @since 100
 @see `#localTimeWindowEnd`
 */
@property (nullable, nonatomic, strong, readwrite) NSDate *timeWindowStart;

/** The ending time of a permissible time window for the stop. The route will attempt to visit the stop only within its time window, if possible. Can be nil if you don't want to specify a time window constraint.
 @since 100
 @see `#localTimeWindowStart`
 */
@property (nullable, nonatomic, strong, readwrite) NSDate *timeWindowEnd;

/** The status of the stop's location on the underlying network.
 @since 100
 @see `#networkLocation`
 */
@property (nonatomic, assign, readonly) AGSLocationStatus locationStatus;

/** Name of the stop
 @since 100
 */
@property (nonatomic, copy, readwrite) NSString *name;

/** Type of stop
 @since 100.1
 */
@property (nonatomic, assign, readwrite) AGSStopType stopType;

/** The navigation latency in seconds.
 @since 100
 */
@property (nonatomic, assign, readwrite) double navigationLatency;

/** The navigation speed in meters per second.
 @since 100
 */
@property (nonatomic, assign, readwrite) double navigationSpeed;

/** The location on the underlying transportation network where the stop is located.
 @since 100
 @see `#locationStatus`
 */
@property (nullable, nonatomic, strong, readwrite) AGSNetworkLocation *networkLocation;

/** Name of the route to which this stop belongs. You can use this to group stops into separate routes.
 @since 100
 */
@property (nonatomic, copy, readwrite) NSString *routeName;

/** The order in which stop is visited along the route.
 A value of 1 implies it is the first stop, and so on.
 @since 100
 */
@property (nonatomic, assign, readonly) NSInteger sequence;

/** The time (in minutes) by which the route arrives later than the permissible time window for the stop.
 This is the difference between `#localArrivalTime` and `#localTimeWindowEnd`
 @since 100
 */
@property (nonatomic, assign, readonly) double violationTime;

/** The time (in minutes) spent at the stop waiting for the time window to open when the route arrives early
 This is the difference between `#localArrivalTime` and `#localTimeWindowStart`
 @since 100
 */
@property (nonatomic, assign, readonly) double waitTime;

#pragma mark -
#pragma mark methods

/** Gets the added cost attribute value for the given attribute
 @param attributeName of the attribute
 @return added cost of the attribute
 @since 100
 */
-(double)addedCostForCostAttribute:(NSString*)attributeName;

/** Sets the added cost attribute value for the given attribute
 @param addedCost for the attribute
 @param attributeName of the attribute
 @since 100
 @see `AGSRouteTaskInfo#costAttributes` for a list of attributes
 */
-(void)setAddedCost:(double)addedCost forCostAttribute:(NSString*)attributeName;

/** Gets the cumulative cost attribute value for the given attribute
 @param attributeName of the attribute
 @return cumulative cost of the attribute
 @since 100
 @see `AGSRouteTaskInfo#costAttributes` for a list of attributes
*/
-(double)cumulativeCostForCostAttribute:(NSString*)attributeName;

NS_ASSUME_NONNULL_END
@end
