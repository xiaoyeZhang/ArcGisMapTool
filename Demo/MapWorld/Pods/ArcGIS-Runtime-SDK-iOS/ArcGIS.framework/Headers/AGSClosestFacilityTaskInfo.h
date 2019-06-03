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

@class AGSCostAttribute;
@class AGSRestrictionAttribute;
@class AGSTravelMode;

/** @file AGSClosestFacilityTaskInfo.h */ //Required for Globals API doc

/** @brief Metadata about the network analyst service or dataset used by `AGSClosestFacilityTask`
 
 Instances of this class represent metadata about the network analyst service or dataset used by `AGSClosestFacilityTask`. It provides default values for the parameters created through `AGSClosestFacilityTask#defaultClosestFacilityParametersWithCompletion:`.
 
 @since 100.1
 */
@interface AGSClosestFacilityTaskInfo : AGSObject
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** A list of network attributes that can be accumulated and returned as part of the analysis result. You might want to perform the analysis using a distance-based impedance attribute and accumulate a time-based cost attribute. The results of this kind of analysis are based on distance, but they also specify how long it would take to reach a portion of the service area.
 @since 100.1
 */
@property (nonatomic, copy, readonly) NSArray<NSString*> *accumulateAttributeNames;

/** A list of cost attributes that can be used as a travel mode impedance (`AGSTravelMode#impedanceAttributeName`) to optimize the route. The _key_ in the dictionary represents the name of the cost attribute.
 @since 100.1
 */
@property (nonatomic, copy, readonly) NSDictionary<NSString*,AGSCostAttribute*> *costAttributes;

/** Specifies the default cutoff beyond which incidents or facilities will not be searched. The cutoff is a measure of the attribute specified by `AGSTravelMode#impedanceAttributeName`
 @see `AGSFacility#impedanceCutoff`
 @see `AGSIncident#impedanceCutoff`
 @since 100.1
 */
@property (nonatomic, assign, readonly) double defaultImpedanceCutoff;

/** Specfies the default number of facilities to search for each incident.
 @see `AGSIncident#targetFacilityCount`
 @since 100.1
 */
@property (nonatomic, assign, readonly) NSInteger defaultTargetFacilityCount;

/** The name of travel mode that is used by default
 @since 100.1
 @see `#travelModes`
 */
@property (nonatomic, copy, readonly) NSString *defaultTravelModeName;

/** The linear units used while providing distances for turn-by-turn directions.
 @since 100.1
 */
@property (nonatomic, assign, readonly) AGSUnitSystem directionsDistanceUnits;

/** The language used when computing directions. For example, en, fr, pt-BR, zh-Hans etc.
 @since 100.1
 */
@property (nonatomic, copy, readonly) NSString *directionsLanguage;

/** The style used for providing directions.
 @since 100.1
 */
@property (nonatomic, assign, readonly) AGSDirectionsStyle directionsStyle;

/** Name of the underlying transportation network dataset
 @since 100.1
 */
@property (nonatomic, copy, readonly) NSString *networkName;

/** The spatial reference in which the result geometries are returned, unless `AGSClosestFacilityParameters#outputSpatialReference` is specified.
 @since 100.1
 */
@property (nullable, nonatomic, strong, readonly) AGSSpatialReference *outputSpatialReference;

/** The list of supported restrictions for constraining the analysis. The _key_ in the dictionary represents the name of the restriction attribute.
 @since 100.1
 */
@property (nonatomic, copy, readonly) NSDictionary<NSString*,AGSRestrictionAttribute*> *restrictionAttributes;

/** Specifies the type of route geometry to return in the result `AGSClosestFacilityRoute#routeGeometry`
 @since 100.1
 */
@property (nonatomic, assign, readonly) AGSRouteShapeType routeShapeType;

/** The time the route begins. If not specified, defaults to the time the task is executed.
 @since 100.1
 @see `#startTimeUsage`
 */
@property (nullable, nonatomic, strong, readonly) NSDate *startTime;

/** Determines whether the `#startTime` is used as the time of departing from the facility or incident, or time of arriving at the facility or incident.
 @since 100.1
 */
@property (nonatomic, assign, readonly) AGSStartTimeUsage startTimeUsage;

/** The list of languages supported for generating turn-by-turn driving directions.
 @since 100.1
 */
@property (nonatomic, copy, readonly) NSArray<NSString*> *supportedLanguages;

/** The list of supported restriction parameter values.
 @since 100.1
 */
@property (nonatomic, copy, readonly) NSArray<NSString*> *supportedRestrictionUsageParameterValues;

/** Specifies the direction of travel between facilities and incidents.
 The direction of travel may influence the facilities found if the network contains one-way streets or impedances based on the direction of travel. For instance, it might take 10 minutes to drive from a particular incident to a particular facility, but the journey might take 15 minutes traveling in the other direction, from the facility to the incident, because of one-way streets or different traffic conditions.
 @since 100.1
 */
@property (nonatomic, assign, readonly) AGSTravelDirection travelDirection;

/** Specifies the available travel modes that can be used to customize the route.
 @since 100.1
 */
@property (nonatomic, copy, readonly) NSArray<AGSTravelMode*> *travelModes;

NS_ASSUME_NONNULL_END
@end
