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

@class AGSArcGISFeatureTable;
@class AGSQueryParameters;
@class AGSPointBarrier;
@class AGSPolylineBarrier;
@class AGSPolygonBarrier;
@class AGSTravelMode;
@class AGSFacility;
@class AGSIncident;

/** @file AGSClosestFacilityParameters.h */ //Required for Globals API doc

/** @brief Input parameters for `AGSClosestFacilityTask`
 
 Instances of this class represent input parameters for finding closest facilities using `AGSClosestFacilityTask`.
 
 @note Consider using the convenience method `AGSClosestFacilityTask#defaultClosestFacilityParametersWithCompletion:` to get an instance of this class that is initialized with smart default values based on the task's metadata (`AGSClosestFacilityTask#closestFacilityTaskInfo`)
 
 @since 100.1
 */
@interface AGSClosestFacilityParameters : AGSObject
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** A list of network attributes to be accumulated and returned as part of the result. You might want to perform the analysis using a distance-based impedance attribute and accumulate a time-based cost attribute. Available attributes are specified by `AGSClosestFacilityTaskInfo#accumulateAttributeNames`. These attributes represent costs such as Drive Time, Distance, Toll expenses, etc.
 @since 100.1
 */
@property (nonatomic, copy, readwrite) NSArray<NSString*> *accumulateAttributeNames;

/** Specifies the default cutoff beyond which incidents or facilities will not be searched. Each facility or incident can specify its own cutoff value, but if they don't, this default will be used. The cutoff is a measure of the attribute specified by `AGSTravelMode#impedanceAttributeName`
 @see `AGSFacility#impedanceCutoff`
 @see `AGSIncident#impedanceCutoff`
 @since 100.1
 */
@property (nonatomic, assign, readwrite) double defaultImpedanceCutoff;

/** Specfies the default number of facilities to search for each incident. Each incident can specify its own value, but if they don't, this default will be used.
 @see `AGSIncident#targetFacilityCount`
 @since 100.1
 */
@property (nonatomic, assign, readwrite) NSInteger defaultTargetFacilityCount;

/** The linear units to use while providing distances for turn-by-turn directions.
 @since 100.1
 */
@property (nonatomic, assign, readwrite) AGSUnitSystem directionsDistanceUnits;

/** The language used when computing directions. For example, en, fr, pt-BR, zh-Hans, etc. The list of languages supported is available in `AGSClosestFacilityTaskInfo#supportedLanguages`
 @since 100.1
 */
@property (nonatomic, copy, readwrite) NSString *directionsLanguage;

/** The style to use for providing directions.
 @since 100.1
 */
@property (nonatomic, assign, readwrite) AGSDirectionsStyle directionsStyle;

/** The spatial reference in which the result geometries should be returned.
 If nil, the results will be returned in the spatial reference specified by `AGSClosestFacilityTaskInfo#outputSpatialReference`.
 @since 100.1
 */
@property (nullable, nonatomic, strong, readwrite) AGSSpatialReference *outputSpatialReference;

/** Specifies whether to return turn-by-turn directions in the result `AGSClosestFacilityRoute#directionManeuvers`
 @since 100.1
 */
@property (nonatomic, assign, readwrite) BOOL returnDirections;

/** Specifies whether to return the point barriers used while computing the result. 
 The barriers will be returned in  `AGSClosestFacilityResult#pointBarriers`
 @since 100.1
 */
@property (nonatomic, assign, readwrite) BOOL returnPointBarriers;

/** Specifies whether to return the polygon barriers used while computing the result.
 The barriers will be returned in  `AGSClosestFacilityResult#polygonBarriers`
 @since 100.1
 */
@property (nonatomic, assign, readwrite) BOOL returnPolygonBarriers;

/** Specifies whether to return the polyline barriers used while computing the result.
 The barriers will be returned in  `AGSClosestFacilityResult#polylineBarriers`
 @since 100.1
 */
@property (nonatomic, assign, readwrite) BOOL returnPolylineBarriers;

/** Specifies whether to return routes in the result `AGSClosestFacilityResult#routeForFacilityIndex:incidentIndex:`
 @since 100.1
 */
@property (nonatomic, assign, readwrite) BOOL returnRoutes;

/** Specifies the type of route geometry to return
 @since 100.1
 */
@property (nonatomic, assign, readwrite) AGSRouteShapeType routeShapeType;

/** The time the route begins. If not specified, defaults to the time the task is executed.
 @since 100.1
 @see `#startTimeUsage`
 */
@property (nullable, nonatomic, strong, readwrite) NSDate *startTime;

/** Determines whether the `#startTime` is used as the time of departing from the facility or incident, or time of arriving at the facility or incident.
 @since 100.1
*/
@property (nonatomic, assign, readwrite) AGSStartTimeUsage startTimeUsage;

/** Specifies the direction of travel between facilities and incidents. 
The direction of travel may influence the facilities found if the network contains one-way streets or impedances based on the direction of travel. For instance, it might take 10 minutes to drive from a particular incident to a particular facility, but the journey might take 15 minutes traveling in the other direction, from the facility to the incident, because of one-way streets or different traffic conditions.
 @since 100.1
 */
@property (nonatomic, assign, readwrite) AGSTravelDirection travelDirection;

/** Specifies the travel mode to use when computing the routes. A travel mode represents a collection of network settings, such as travel restrictions and U-turn policies, that determine how a pedestrian, car, truck, or other medium of transportation moves through the network.
 @since 100.1
 */
@property (nullable, nonatomic, strong, readwrite) AGSTravelMode *travelMode;

#pragma mark -
#pragma mark methods

/** Clear any facilities that may have been set earlier
 @since 100.1
 */
-(void)clearFacilities;

/** Clear any incidents that may have been set earlier
 @since 100.1
 */
-(void)clearIncidents;

/** Clear any point barriers that may have been set earlier
 @since 100.1
 */
-(void)clearPointBarriers;

/** Clear any polygon barriers that may have been set earlier
 @since 100.1
 */
-(void)clearPolygonBarriers;

/** Clear any polyline barriers that may have been set earlier
 @since 100.1
 */
-(void)clearPolylineBarriers;

/** Returns the filter used to specify which network elements stops can be located on.  For example, if you have a network which has multiple sources such as streets, bus lines, air lines, etc., you could specify that facilities and incidents be located only on certain sources.
 @param sourceName of the network element the filter applies to
 @return The filter specifiying which network elements can facilities and incidents be located on
 @since 100.1
 */
-(NSString*)searchWhereClauseForSourceName:(NSString*)sourceName;


/** Specifies which network elements facilities and incidents can be located on. For example, if you have a network which has multiple sources such as streets, bus lines, air lines, etc., you could specify that facilities and incidents be located only on certain sources.
 @param searchWhereClause The filter specifiying which network elements facilities and incidents can be located on
 @param sourceName the network elements the filter applies to
 @since 100.1
 */
-(void)setSearchWhereClause:(NSString*)searchWhereClause forSourceName:(NSString*)sourceName;

/** Set the facilities to use in the analysis
 @param facilities to use
 @since 100.1
 */
-(void)setFacilities:(NSArray<AGSFacility*>*)facilities;

/** Set the facilities to use in the analysis
 @param featureTable containing point features to use as facilities
 @param queryParameters specifying which features to use
 @since 100.1
 */
-(void)setFacilitiesWithFeatureTable:(AGSArcGISFeatureTable*)featureTable queryParameters:(AGSQueryParameters*)queryParameters;

/** Set the incidents to use in the analysis
 @param incidents to use
 @since 100.1
 */
-(void)setIncidents:(NSArray<AGSIncident*>*)incidents;

/** Set the incidents to use in the analysis
 @param featureTable containing point features to use as incidents
 @param queryParameters to filter which features to use
 @since 100.1
 */
-(void)setIncidentsWithFeatureTable:(AGSArcGISFeatureTable*)featureTable queryParameters:(AGSQueryParameters*)queryParameters;

/** Set point barriers to avoid in the result route
 @param pointBarriers barriers to avoid
 @since 100.1
 */
-(void)setPointBarriers:(NSArray<AGSPointBarrier*>*)pointBarriers;

/** Set point barriers to avoid in the result route
 @param featureTable containing point features to use as barriers
 @param queryParameters to filter which features to use
 @since 100.1
 */
-(void)setPointBarriersWithFeatureTable:(AGSArcGISFeatureTable*)featureTable queryParameters:(AGSQueryParameters*)queryParameters;


/** Set polygon barriers to avoid in the result route
 @param polygonBarriers barriers to avoid
 @since 100.1
 */
-(void)setPolygonBarriers:(NSArray<AGSPolygonBarrier*>*)polygonBarriers;

/** Set polygon barriers to avoid in the result route
 @param featureTable containing polygon features to use as barriers
 @param queryParameters to filter which features to use
 @since 100.1
 */
-(void)setPolygonBarriersWithFeatureTable:(AGSArcGISFeatureTable*)featureTable queryParameters:(AGSQueryParameters*)queryParameters;


/** Set polyline barriers to avoid in the result route
 @param lineBarriers barriers to avoid
 @since 100.1
 */
-(void)setPolylineBarriers:(NSArray<AGSPolylineBarrier*>*)lineBarriers;

/** Set polyline barriers to avoid in the result route
 @param featureTable containing polyline features to use as barriers
 @param queryParameters to filter which features to use
 @since 100.1
 */
-(void)setPolylineBarriersWithFeatureTable:(AGSArcGISFeatureTable*)featureTable queryParameters:(AGSQueryParameters*)queryParameters;

NS_ASSUME_NONNULL_END
@end
