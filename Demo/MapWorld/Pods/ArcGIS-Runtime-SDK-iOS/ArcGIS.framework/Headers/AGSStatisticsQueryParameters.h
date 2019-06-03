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

@class AGSStatisticDefinition;
@class AGSGeometry;
@class AGSOrderBy;
@class AGSTimeExtent;

/** @file AGSStatisticsQueryParameters.h */ //Required for Globals API doc

/** @brief Parameters to perform a statistic query using `AGSFeatureTable`
 
 Instances of this class represent parameters that can be used to perform a statistic query using `AGSFeatureTable#queryStatisticsWithParameters:completion:`.
 
 All parameters related to geometry and spatial queries will be ignored when querying non spatial data.
 @since 100.2
 */
@interface AGSStatisticsQueryParameters : AGSObject

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

/** Intialize the query parameter with the provided statistic definitions
 @param statisticDefinitions describing which statistics are required in the query result
 @return An initialized query parameter
 @since 100.2
 */
-(instancetype)initWithStatisticDefinitions:(NSArray<AGSStatisticDefinition*> *)statisticDefinitions;

/** Intialize the query parameter with the provided statistic definitions
 @param statisticDefinitions describing which statistics are required in the query result
 @return An initialized query parameter
 @since 100.2
 */
+(instancetype)statisticsQueryParametersWithStatisticDefinitions:(NSArray<AGSStatisticDefinition*> *)statisticDefinitions;

#pragma mark -
#pragma mark properties

/** The geometry to use while performing a spatial query. Valid geometry types are `AGSEnvelope`, `AGSPoint`, `AGSMultipoint`, `AGSPolygon`, and `AGSPolyline`. Results of the query will include only those features which conform to the specified `#spatialRelationship` with this geometry.
 @since 100.2
 */
@property (nullable, nonatomic, strong, readwrite) AGSGeometry *geometry;

/** The fields by which statistical query results should be grouped.
 @since 100.2
 */
@property (nonatomic, copy, readwrite) NSArray<NSString*> *groupByFieldNames;

/** Fields by which the results need to be ordered. Note, the service being queried must support advanced queries.
 @since 100.2
 */
@property (nonatomic, copy, readwrite) NSArray<AGSOrderBy*> *orderByFields;

/** The spatial constraint that needs to be applied on the query `#geometry`. Only data satisfying this relationship will be returned as results.
 @since 100.2
 */
@property (nonatomic, assign, readwrite) AGSSpatialRelationship spatialRelationship;

/** The definition of which statistics (input field, output name, statistic type) to include in the results of statistical query.
 @since 100.2
 */
@property (nonatomic, copy, readwrite) NSArray<AGSStatisticDefinition*> *statisticDefinitions;

/** A SQL where clause to filter results for the query. If the where clause includes dates, they must be correctly formatted based on the geodatabase datasource used in the service. Refer to [this](http://resources.arcgis.com/en/help/main/10.2/index.html#//00s500000033000000) document for date formats expected by different datasources.
 @since 100
 */
@property (nonatomic, copy, readwrite) NSString *whereClause;

/** Time extent for the query. Only features that fall within this time period will be returned.
 @since 100.2
 */
@property (nullable, nonatomic, strong, readwrite) AGSTimeExtent *timeExtent;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end
