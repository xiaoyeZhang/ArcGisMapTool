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

#import "AGSObject.h"

@class AGSRelationshipInfo;
@class AGSOrderBy;

/** @file AGSQueryParameters.h */ //Required for Globals API doc

/** @brief Parameters to perform a related query using `AGSArcGISFeatureTable`
 
 Instances of this class represent parameters that can be used to perform a query using `AGSArcGISFeatureTable#queryRelatedFeaturesForFeature:parameters:completion:`.
 
 @since 100.1
 */
@interface AGSRelatedQueryParameters : AGSObject

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

/** Initialize the parameter with the provided relationship
 @param relationshipInfo specifying the relationship to query on
 @since 100.1
 @return initialized parameter
 */
-(instancetype)initWithRelationshipInfo:(AGSRelationshipInfo *)relationshipInfo;

/** Initialize the parameter with the provided relationship
 @param relationshipInfo specifying the relationship to query on
 @since 100.1
 @return initialized parameter
 */
+(instancetype)relatedQueryParametersWithRelationshipInfo:(AGSRelationshipInfo *)relationshipInfo;

#pragma mark -
#pragma mark properties

/** The maximum number of results that should be returned.
 @note For consistent ordering of results when using pagination, you should also provide a value for `#orderByFields`.
 @since 100.2
 */
@property (nonatomic, assign, readwrite) NSInteger maxFeatures;

/** Fields by which the results need to be ordered. Note, the service being queried must support advanced queries.
 @since 100.1
 */
@property (nonatomic, copy, readwrite) NSArray<AGSOrderBy*> *orderByFields;

/** Information about the relationship that the query is based on
 @since 100.1
 */
@property (nonatomic, strong, readwrite) AGSRelationshipInfo *relationshipInfo;

/** The starting offset of results to fetch. This is useful for paging through results.
 @note If providing a result offset, you must also set `#maxFeatures` otherwise the offset is ignored.
 @since 100.2
 */
@property (nonatomic, assign, readwrite) NSInteger resultOffset;

/** If `YES`, result features will include their geometry. This is needed when you want to display the features on a map or a scene. If non-spatial data is being queried, result features will not contain a geometry.
 @since 100.1
 */
@property (nonatomic, assign, readwrite) BOOL returnGeometry;

/** A SQL where clause to filter results for the query. If the where clause includes dates, they must be correctly formatted based on the geodatabase datasource used in the service. Refer to [this](http://resources.arcgis.com/en/help/main/10.2/index.html#//00s500000033000000) document for date formats expected by different datasources.
 @since 100.1
 */
@property (nonatomic, copy, readwrite) NSString *whereClause;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end

