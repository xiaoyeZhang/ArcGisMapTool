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

@class AGSPoint;
@class AGSNetworkLocation;

/** @file AGSFacility.h */ //Required for Globals API doc

/** @brief A facility to use in closest facility or service area analysis
 
 Instances of this class represent facilities. Facilities represent locations that can serve as the starting point or ending point of a closest facility analysis, for example, a fire station or a hospital as the location at which to perform a service area analysis.
 
 @see `AGSClosestFacilityTask`
 @since 100.1
 */
@interface AGSFacility : AGSObject <NSCopying>
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

/** Initialize the facility using the provided location
 @param point where the facility is located
 @return A new facility
 @since 100.1
*/
-(instancetype)initWithPoint:(AGSPoint*)point;

/** Initialize the facility using the provided location
 @param point where the facility is located
 @return A new facility
 @since 100.1
 */
+(instancetype)facilityWithPoint:(AGSPoint*)point;

#pragma mark -
#pragma mark properties

/** Specifies the direction a vehicle may arrive at or depart from the facility.
 For example, a school bus must approach and depart a school from its door side so that students entering/exiting the bus will not have to cross the street.
 @since 100.1
 */
@property (nonatomic, assign, readwrite) AGSCurbApproach curbApproach;

/** The distance to the closest location on the underlying network in meters.
 @see `#networkLocation`
 @since 100.1
 */
@property (nonatomic, assign, readonly) double distanceToNetworkLocation;

/** Location of the facility
@since 100.1
*/
@property (nonatomic, strong, readonly) AGSPoint *geometry;

/** Specifies the cutoff beyond which this facility will not be searched. The cutoff is a measure of the attribute specified by `AGSTravelMode#impedanceAttributeName`. If this is not specified, `AGSClosestFacilityParameters#defaultImpedanceCutoff` will be used.
 @since 100.1
 */
@property (nonatomic, assign, readwrite) double impedanceCutoff;

/** The status of facility's location on the underlying network.
 @since 100.1
 @see `#networkLocation`
 */
@property (nonatomic, assign, readonly) AGSLocationStatus locationStatus;

/** Name of the facility
@since 100.1
*/
@property (nonatomic, copy, readwrite) NSString *name;

/** The location on the underlying transportation network where the facility is located.
 @since 100.1
 @see `#locationStatus`
 */
@property (nullable, nonatomic, strong, readwrite) AGSNetworkLocation *networkLocation;

#pragma mark -
#pragma mark methods

/** Gets the added cost value for the given impedance or accumulate attribute
 @param attributeName of the impedance or accumulate attribute
 @return added cost of the attribute
 @since 100.1
 @see `AGSClosestFacilityTaskInfo#costAttributes` for a list of attributes available for closest facility analysis
 */
-(double)addedCostForCostAttribute:(NSString*)attributeName;

/** Sets the added cost value for the given impedance or accumulate attribute
 @param addedCost for the attribute
 @param attributeName of the impedance or accumulate attribute
 @since 100.1
 @see `AGSClosestFacilityTaskInfo#costAttributes` for a list of attributes available for closest facility analysis
 */
 -(void)setAddedCost:(double)addedCost forCostAttribute:(NSString*)attributeName;

NS_ASSUME_NONNULL_END
@end
