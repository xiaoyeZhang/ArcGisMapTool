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

@class AGSSpatialReference;
@class AGSTravelMode;
@class AGSArcGISFeatureTable;
@class AGSQueryParameters;
@class AGSPointBarrier;
@class AGSPolylineBarrier;
@class AGSPolygonBarrier;
@class AGSStop;

/** @file AGSRouteParameters.h */ //Required for Globals API doc

/** @brief Input parameters for `AGSRouteTask`
 
 Instances of this class represent input parameters for computing routes using `AGSRouteTask`.
 
 @note Consider using the convenience method `AGSRouteTask#defaultRouteParametersWithCompletion:` to get an instance of this class that is initialized with smart default values based on the task's metadata (`AGSRouteTask#routeTaskInfo`)
 
 @since 100
 */
@interface AGSRouteParameters : AGSObject <NSCopying>
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init;
+(instancetype)routeParameters;

#pragma mark -
#pragma mark properties

/** A list of network attributes to be accumulated and returned as part of the route. You might want to perform the analysis using a distance-based impedance attribute and accumulate a time-based cost attribute. Available attributes are specified by `AGSRouteTaskInfo#accumulateAttributeNames`. These attributes represent costs such as Drive Time, Distance, Toll expenses, etc.
 @since 100
 */
@property (nonatomic, copy, readwrite) NSArray<NSString*> *accumulateAttributeNames;

/** The linear units to use while providing distances for turn-by-turn directions.
 @since 100
 */
@property (nonatomic, assign, readwrite) AGSUnitSystem directionsDistanceUnits;

/** The language used when computing directions. For example, en, fr, pt-BR, zh-Hans, etc. The list of languages supported is available in `AGSRouteTaskInfo#supportedLanguages`
 @since 100
 */
@property (nonatomic, copy, readwrite) NSString *directionsLanguage;

/** The style to use for providing directions.
 @since 100
 */
@property (nonatomic, assign, readwrite) AGSDirectionsStyle directionsStyle;

/** Specifies whether or not to optimize the order of the stops in the route.
 @since 100
 @see `#preserveFirstStop`
 @see `#preserveLastStop`
 */
@property (nonatomic, assign, readwrite) BOOL findBestSequence;

/** The time the route begins. If not specified, defaults to the time the task is executed.
 @since 100
 */
@property (nullable, nonatomic, strong, readwrite) NSDate *startTime;

/** The spatial reference in which the result geometries should be returned.
 If nil, the results will be returned in the spatial reference specified by `AGSRouteTaskInfo#outputSpatialReference`.
 @since 100
 */
@property (nullable, nonatomic, strong, readwrite) AGSSpatialReference *outputSpatialReference;

/** If `YES`, keeps the first stop fixed in the sequence even when `#findBestSequence` is enabled.
 Only applicable if `#findBestSequence` is enabled.
 @since 100
 */
@property (nonatomic, assign, readwrite) BOOL preserveFirstStop;

/** If `YES`, keeps the last stop fixed in the sequence even when `#findBestSequence` is enabled.
 Only applicable if `#findBestSequence` is enabled.
 @since 100
 */
@property (nonatomic, assign, readwrite) BOOL preserveLastStop;

/** Specifies whether to return turn-by-turn directions in the result `AGSRoute#directionManeuvers`
 @since 100
 */
@property (nonatomic, assign, readwrite) BOOL returnDirections;

/** Specifies whether to return the point barriers used while computing the route in the result `AGSRouteResult#pointBarriers`
 @since 100
 */
@property (nonatomic, assign, readwrite) BOOL returnPointBarriers;

/** Specifies whether to return the polygon barriers used while computing the route in the result `AGSRouteResult#polygonBarriers`
 @since 100
 */
@property (nonatomic, assign, readwrite) BOOL returnPolygonBarriers;

/** Specifies whether to return the polyline barriers used while computing the route in the result `AGSRouteResult#polylineBarriers`
 @since 100
 */
@property (nonatomic, assign, readwrite) BOOL returnPolylineBarriers;

/** Specifies whether to return routes in the result `AGSRouteResult#routes`
 @since 100
 */
@property (nonatomic, assign, readwrite) BOOL returnRoutes;

/** Specifies whether to return stops along each route in the result `AGSRoute#stops`
 @since 100
 */
@property (nonatomic, assign, readwrite) BOOL returnStops;

/** Specifies the type of route geometry to return in the result `AGSRoute#routeGeometry` 
 @since 100
 */
@property (nonatomic, assign, readwrite) AGSRouteShapeType routeShapeType;

/** Specifies the travel mode to use when computing the routes
 @since 100
 */
@property (nullable, nonatomic, strong, readwrite) AGSTravelMode *travelMode;

#pragma mark -
#pragma mark methods

/** Clear any point barriers that may have been set earlier
 @since 100
 */
-(void)clearPointBarriers;

/** Clear any polygon barriers that may have been set earlier
 @since 100
 */
-(void)clearPolygonBarriers;

/** Clear any polyline barriers that may have been set earlier
 @since 100
 */
-(void)clearPolylineBarriers;

/** Clear any stops that may have been set earlier
 @since 100
 */
-(void)clearStops;

/** Set point barriers to avoid in the result route
 @param pointBarriers barriers to avoid
 @since 100
 */
-(void)setPointBarriers:(NSArray<AGSPointBarrier*>*)pointBarriers;

/** Set point barriers to avoid in the result route
 @param featureTable containing point features to use as barriers
 @param queryParameters to filter which features to use
 @since 100
 */
-(void)setPointBarriersWithFeatureTable:(AGSArcGISFeatureTable*)featureTable queryParameters:(AGSQueryParameters*)queryParameters;

/** Set polygon barriers to avoid in the result route
 @param polygonBarriers barriers to avoid
 @since 100
 */
-(void)setPolygonBarriers:(NSArray<AGSPolygonBarrier*>*)polygonBarriers;

/** Set polygon barriers to avoid in the result route
 @param featureTable containing polygon features to use as barriers
 @param queryParameters to filter which features to use
 @since 100
 */
-(void)setPolygonBarriersWithFeatureTable:(AGSArcGISFeatureTable*)featureTable queryParameters:(AGSQueryParameters*)queryParameters;

/** Set polyline barriers to avoid in the result route
 @param lineBarriers barriers to avoid
 @since 100
 */
-(void)setPolylineBarriers:(NSArray<AGSPolylineBarrier*>*)lineBarriers;

/** Set polyline barriers to avoid in the result route
 @param featureTable containing polyline features to use as barriers
 @param queryParameters to filter which features to use
 @since 100
 */
-(void)setPolylineBarriersWithFeatureTable:(AGSArcGISFeatureTable*)featureTable queryParameters:(AGSQueryParameters*)queryParameters;

/** Set the stops to visit in the result route
 @param stops to visit in the route
 @since 100
 */
-(void)setStops:(NSArray<AGSStop*>*)stops;

/** Set the stops to visit in the result route
 @param featureTable containing point features to use as stops
 @param queryParameters to filter which features to use
 @since 100
 */
-(void)setStopsWithFeatureTable:(AGSArcGISFeatureTable*)featureTable queryParameters:(AGSQueryParameters*)queryParameters;

/** Returns the filter used to specify which network elements stops can be located on.  For example, if you have a network which has multiple sources such as streets, bus lines, air lines, etc., you could specify that stops be located only on certain sources.
 @param sourceName of the network element the filter applies to
 @return The filter specifiying which network elements can stops be located on
 @since 100
 */
-(NSString*)searchWhereClauseForSourceName:(NSString*)sourceName;

/** Specifies which network elements stops can be located on. For example, if you have a network which has multiple sources such as streets, bus lines, air lines, etc., you could specify that stops be located only on certain sources.
 @param searchWhereClause The filter specifiying which network elements can stops be located on
 @param sourceName the network elements the filter applies to
 @since 100
 */
-(void)setSearchWhereClause:(NSString*)searchWhereClause forSourceName:(NSString*)sourceName;

NS_ASSUME_NONNULL_END
@end
