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

@class AGSFacility;
@class AGSIncident;
@class AGSPointBarrier;
@class AGSPolygonBarrier;
@class AGSPolylineBarrier;
@class AGSClosestFacilityRoute;

/** @file AGSClosestFacilityResult.h */ //Required for Globals API doc

/** @brief Result returned by `AGSClosestFacilityTask`
 
 Instances of this class represent the result of `AGSClosestFacilityTask#solveClosestFacilityWithParameters:completion:`.
 The result is a collection of computed routes between incidents and facilities, barriers used in the computation, and messages generated during the process.
 
 @since 100.1
 */
@interface AGSClosestFacilityResult : AGSObject
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** The language used when computing directions. For example, en, fr, pt-BR, zh-Hans, etc. The list of languages supported is available in `AGSClosestFacilityTaskInfo#supportedLanguages`
 @since 100.1
 @see `AGSClosestFacilityParameters#directionsLanguage` to specify which language to use
 */
@property (nonatomic, copy, readonly) NSString *directionsLanguage;

/** Facilities used in the analysis
 @since 100.1
 */
@property (nonatomic, copy, readonly) NSArray<AGSFacility*> *facilities;

/** Incidents used in the analysis
 @since 100.1
 */
@property (nonatomic, copy, readonly) NSArray<AGSIncident*> *incidents;

/** Informational messages that were generated while computing routes.
 @since 100.1
 */
@property (nonatomic, copy, readonly) NSArray<NSString*> *messages;

/** Point barriers used in the route computation. Only available if `AGSClosestFacilityParameters#returnPointBarriers` was enabled.
 @since 100.1
 @see `AGSClosestFacilityParameters#setPointBarriers:` or `AGSClosestFacilityParameters#setPointBarriersWithFeatureTable:queryParameters:` to specify the barriers to use
 */
@property (nonatomic, copy, readonly) NSArray<AGSPointBarrier*> *pointBarriers;

/** Polygon barriers used in the route computation. Only available if `AGSClosestFacilityParameters#returnPolygonBarriers` was enabled.
 @since 100.1
 @see `AGSClosestFacilityParameters#setPolygonBarriers:` or `AGSClosestFacilityParameters#setPolygonBarriersWithFeatureTable:queryParameters:` to specify the barriers to use
 */
@property (nonatomic, copy, readonly) NSArray<AGSPolygonBarrier*> *polygonBarriers;

/** Polyline barriers used in the route computation. Only available if `AGSClosestFacilityParameters#returnPolylineBarriers` was enabled.
 @since 100.1
 @see `AGSClosestFacilityParameters#setPolylineBarriers:` or `AGSClosestFacilityParameters#setPolylineBarriersWithFeatureTable:queryParameters:` to specify the barriers to use
 */
@property (nonatomic, copy, readonly) NSArray<AGSPolylineBarrier*> *polylineBarriers;

#pragma mark -
#pragma mark methods

/** Returns the cost for the specified facility attribute
 @param attributeName name of the desired attribute
 @param facilityIndex index of the desired facility in the `#facilities` collection
 @since 100.1
 */
-(nullable NSArray<NSNumber*>*)facilityCostsForAttributeName:(NSString *)attributeName facilityIndex:(NSInteger)facilityIndex;

/** Returns an ordered list of facilities for a given incident. Facilities and Incidents are identified by indexes based on the `#facilities` and `#incidents` collections.
 The first element in the list is the closest facility, the second element is the next closest, etc. Multiple properties can effect the number of facilities returned for each incident.
 @param incidentIndex index of the desired incident in the `#incidents` collection
 @since 100.1
 */
-(nullable NSArray<NSNumber*>*)rankedFacilityIndexesForIncidentIndex:(NSInteger)incidentIndex;

/** Returns a route between an incident and a facility
 @param facilityIndex index of the desired facility in the `#facilities` collection
 @param incidentIndex index of the desired incident in the `#incidents` collection
 @since 100.1
 */
-(nullable AGSClosestFacilityRoute*)routeForFacilityIndex:(NSInteger)facilityIndex incidentIndex:(NSInteger)incidentIndex;

NS_ASSUME_NONNULL_END
@end
