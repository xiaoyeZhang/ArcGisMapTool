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

#import "AGSFeatureSet.h"

@class AGSArcGISFeature;
@class AGSArcGISFeatureTable;
@class AGSRelationshipInfo;

/** @file AGSRelatedFeatureQueryResult.h */ //Required for Globals API doc

/** @brief Result of relationship based queries that return features.
 
 Instances of this class represent results of relationship based queries that return features.  This class has methods that can be used to iterate over the collection of features.
 The @c AGSFeatureEnumerator class conforms to `%NSFastEnumeration` which permits the collection to be enumerated conveniently using a for-in loop. For example -
 
 ```
 let result:AGSRelatedFeatureQueryResult = ... //A related feature query result instance
 let enumr = result.featureEnumerator()
 for feature in enumr {
 //do something
 }
 ```
 
 @since 100.1
 */
@interface AGSRelatedFeatureQueryResult : AGSObject <AGSFeatureSet>

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** Indicates if the results do not include all the features matched by the query. Mostly relevant to queries executed against an ArcGIS Service which typically only return only upto a 1000 results even if the query matched more features.
 @since 100.1
 */
@property (nonatomic, assign, readonly, getter=isTransferLimitExceeded) BOOL transferLimitExceeded;

/** Feature that the result features are related to.
 @since 100.1
 */
@property (nullable, nonatomic, strong, readonly) AGSArcGISFeature *feature;

/** Feature table that the result features belong to.
 @since 100.1
 */
@property (nullable, nonatomic, strong, readonly) AGSArcGISFeatureTable *relatedTable;

/** Relationship that the query results are based on.
 @since 100.1
 */
@property (nullable, nonatomic, strong, readonly) AGSRelationshipInfo *relationshipInfo;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end

