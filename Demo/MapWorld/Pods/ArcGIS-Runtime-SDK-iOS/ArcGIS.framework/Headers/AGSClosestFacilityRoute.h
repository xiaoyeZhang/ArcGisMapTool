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

@class AGSPolyline;
@class AGSDirectionManeuver;

/** @file AGSClosestFacilityRoute.h */ //Required for Globals API doc

/** @brief An individual route between a facility and an incident
 
 Instances of this class represent an individual route between a facility and an incident that is available through `AGSClosestFacilityResult#routeForFacilityIndex:incidentIndex` .
 
 @since 100.1
 */
@interface AGSClosestFacilityRoute : AGSObject
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** Side of curb at which the route arrives at the destination
 @since 100.1
 */
@property (nonatomic, assign, readonly) AGSCurbApproach arrivalCurbApproach;

/** Side of curb at which the route departs the origin
 @since 100.1
 */
@property (nonatomic, assign, readonly) AGSCurbApproach departureCurbApproach;

/** Turn-by-turn driving directions along this route.
 Only available if `AGSClosestFacilityParameters#returnDirections` was enabled.
 @since 100.1
 */
@property (nonatomic, copy, readonly) NSArray<AGSDirectionManeuver*> *directionManeuvers;

/** Time when the route ends (arriving at the last stop) in the current locale of the device.
 @since 100.1
 */
@property (nullable, nonatomic, strong, readonly) NSDate *endTime;

/** Time zone shift in minutes (based on the time zone of the last stop) for the end time.
 @since 100.1
 */
@property (nonatomic, assign, readonly) double endTimeShift;

/** The route geometry.
 @since 100.1
 */
@property (nullable, nonatomic, strong, readonly) AGSPolyline *routeGeometry;

/** Time when the route begins (departing from the first stop) in the current locale of the device.
 @since 100.1
 */
@property (nullable, nonatomic, strong, readonly) NSDate *startTime;

/** Time zone shift in minutes (based on the time zone of the last stop) for the start time.
 @since 100.1
 */
@property (nonatomic, assign, readonly) double startTimeShift;

/** Total distance (in meters) covered by the route.
 @since 100.1
 */
@property (nonatomic, assign, readonly) double totalLength;

/** Overall time (in minutes) taken by the route from start to end.
 This includes `#travelTime` and `#waitTime`.
 @since 100.1
 */
@property (nonatomic, assign, readonly) double totalTime;

/** Total time (in minutes) spent travelling along the route.
 @since 100.1
 */
@property (nonatomic, assign, readonly) double travelTime;

#pragma mark -
#pragma mark methods

-(double)costForCostAttribute:(NSString*)attributeName;

NS_ASSUME_NONNULL_END
@end
