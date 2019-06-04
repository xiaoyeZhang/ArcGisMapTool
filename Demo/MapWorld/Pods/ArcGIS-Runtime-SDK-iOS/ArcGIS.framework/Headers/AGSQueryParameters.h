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

@class AGSOrderBy;
@class AGSTimeExtent;

/** @file AGSQueryParameters.h */ //Required for Globals API doc

/** @brief Parameters to perform a query using `AGSFeatureTable`
 
 Instances of this class represent parameters that can be used to perform a query using `AGSFeatureTable#queryFeaturesWithParameters:completion:`.
 
 All parameters related to geometry and spatial queries will be ignored when querying non spatial data.
 
 @since 100
 */
@interface AGSQueryParameters : AGSObject

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init;
+(instancetype)queryParameters;

#pragma mark -
#pragma mark properties

/** The geometry to use while performing a spatial query. Valid geometry types are `AGSEnvelope`, `AGSPoint`, `AGSMultipoint`, `AGSPolygon`, and `AGSPolyline`. Results of the query will include only those features which conform to the specified `#spatialRelationship` with this geometry.
 @since 100
 */
@property (nullable, nonatomic, strong, readwrite) AGSGeometry *geometry;

/** The maximum allowable offset used for generalizing geometries returned by the query operation. The default is 0. If 0 is specified the value is not passed to the server in a query. The offset is in the units of the `#outSpatialReference`. If an `outSpatialReference` is not defined, the spatial reference of the service is used.
 @since 100
 */
@property (nonatomic, assign, readwrite) double maxAllowableOffset;

/** The maximum number of results that should be returned.
 @note For consistent ordering of results when using pagination, you should also provide a value for `#orderByFields`.
 @since 100
 */
@property (nonatomic, assign, readwrite) NSInteger maxFeatures;

/** The IDs of features that the query should be restricted to.
 @since 100
 */
@property (nonatomic, copy, readwrite) NSArray<NSNumber*> *objectIDs;

/** Fields by which the results need to be ordered. Note, the service being queried must support advanced queries.
 @since 100
 */
@property (nonatomic, copy, readwrite) NSArray<AGSOrderBy*> *orderByFields;

/** The spatial reference in which result geometries are to be returned. If not specified, geometries are returned in the spatial reference of the service.
 @since 100
 */
@property (nullable, nonatomic, strong, readwrite) AGSSpatialReference *outSpatialReference;

/** The starting offset of results to fetch. This is useful for paging through results.
 @note If providing a result offset, you must also set `#maxFeatures` otherwise the offset is ignored.
 @since 100.2
 */
@property (nonatomic, assign, readwrite) NSInteger resultOffset;

/** If `YES`, result features will include their geometry. This is needed when you want to display the features on a map or a scene. If non-spatial data is being queried, results will not contain geometries.
 @since 100
 */
@property (nonatomic, assign, readwrite) BOOL returnGeometry;

/** The spatial constraint that needs to be applied on the query `#geometry`. Only data satisfying this relationship will be returned as results.
 @since 100
 */
@property (nonatomic, assign, readwrite) AGSSpatialRelationship spatialRelationship;

/** Time extent for the query. Only features that fall within this time period will be returned.
 @since 100.2
 */
@property (nullable, nonatomic, strong, readwrite) AGSTimeExtent *timeExtent;

/** A SQL where clause to filter results for the query. If the where clause includes dates, they must be correctly formatted based on the geodatabase datasource used in the service. Refer to [this](http://resources.arcgis.com/en/help/main/10.2/index.html#//00s500000033000000) document for date formats expected by different datasources.
 @since 100
 */
@property (nonatomic, copy, readwrite) NSString *whereClause;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end
