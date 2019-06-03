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

@class AGSPolyline;
@class AGSDirectionManeuver;
@class AGSStop;

/** @file AGSRoute.h */ //Required for Globals API doc

/** @brief An individual route between stops
 
 Instances of this class represent an individual route between stops that is accessible from `AGSRouteResult#routes`
 
 @since 100
 */
@interface AGSRoute : AGSObject
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** Turn-by-turn driving directions along this route.
 Only available if `AGSRouteParameters#returnDirections` was enabled.
 @since 100
 */
@property (nonatomic, copy, readonly) NSArray<AGSDirectionManeuver*> *directionManeuvers;

/** Time when the route begins (departing from the first stop) in the current locale of the device.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) NSDate *startTime;

/** Time zone shift in minutes (based on the time zone of the last stop) for the start time.
 @since 100
 */
@property (nonatomic, assign, readonly) double startTimeShift;

/** Time when the route ends (arriving at the last stop) in the current locale of the device.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) NSDate *endTime;

/** Time zone shift in minutes (based on the time zone of the last stop) for the end time.
 @since 100
 */
@property (nonatomic, assign, readonly) double endTimeShift;

/** Total distance (in meters) covered by the route.
 @since 100
 */
@property (nonatomic, assign, readonly) double totalLength;

/** The route geometry.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSPolyline *routeGeometry;

/** Name of the route. 
 Same as `AGSStop#routeName` of stops included in this route.
 @since 100
 */
@property (nonatomic, copy, readonly) NSString *routeName;

/** The stops visited along this route.
 Only available if `AGSRouteParameters#returnStops` was enabled.
 @note The sequence stops are visited in the route may be different from the order they are present in the list if `AGSRouteParameters#findBestSequence` is enabled.
 @since 100
 @see `AGSStop#sequence` for the sequence in which stops are visited by a route.
 */
@property (nonatomic, copy, readonly) NSArray<AGSStop*> *stops;

/** Overall time (in minutes) taken by the route from start to end.
 This includes `#travelTime` and `#waitTime`.
 @since 100
 */
@property (nonatomic, assign, readonly) double totalTime;

/** Total time (in minutes) spent travelling along the route.
 @since 100
 */
@property (nonatomic, assign, readonly) double travelTime;

/** Total time (in munutes) that the route was late in arriving within permissible time windows for stops.
 Only applicable if time windows were specified for stops.
 @see `AGSStop#localTimeWindowStart` and `AGSStop#localTimeWindowEnd` for specifying time windows
 @since 100
 */
@property (nonatomic, assign, readonly) double violationTime;

/** Total time (in minutes) spent at stops waiting for time windows to open.
 Only applicable if time windows were specified for stops.
 @since 100
 @see `AGSStop#localTimeWindowStart` and `AGSStop#localTimeWindowEnd` for specifying time windows
 */
@property (nonatomic, assign, readonly) double waitTime;

#pragma mark -
#pragma mark methods

-(double)costForCostAttribute:(NSString*)attributeName;

NS_ASSUME_NONNULL_END
@end
