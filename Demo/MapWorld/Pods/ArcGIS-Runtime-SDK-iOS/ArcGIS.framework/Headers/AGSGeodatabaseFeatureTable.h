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

#import "AGSArcGISFeatureTable.h"

@class AGSArcGISFeatureTable;
@class AGSGeodatabase;
@class AGSRelationshipInfo;

/** @file AGSGeodatabaseFeatureTable.h */ //Required for Globals API doc

/** @brief A Geodatabase dataset containing geographic features or non-spatial records
 
 Instances of this class respresent a Geodatabase dataset that could include either geographic features or non-spatial records. You can query the dataset using attribute or spatial criteria, and if permitted, also edit the data. Edits are tracked, so you can later retrieve a list of edits. If the dataset contains geographic features you can display them on a map using `AGSFeatureLayer`.
 
 @since 100
 */
@interface AGSGeodatabaseFeatureTable : AGSArcGISFeatureTable
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

-(instancetype)initWithTable:(AGSGeodatabaseFeatureTable *)table
            relationshipInfo:(AGSRelationshipInfo *)relationshipInfo;

+(instancetype)geodatabaseFeatureTableWithTable:(AGSGeodatabaseFeatureTable *)table
                               relationshipInfo:(AGSRelationshipInfo *)relationshipInfo;

#pragma mark -
#pragma mark properties

/** The source geodatabase that contains this dataset
 @since 100
 */
@property (nullable, nonatomic, weak, readonly) AGSGeodatabase *geodatabase;

#pragma mark -
#pragma mark methods

/** Indicates whether any edits (adds/updates/deletes) have been made to the dataset since the specified date.
 @param date specifying which edits should be considered
 @since 100
 @note This method could take a long time to complete for geodatabase containing very large number of features (~50,000+). Do not invoke it on the main thread as it may degrade the responsiveness of your application.
 */
-(BOOL)hasLocalEditsSince:(NSDate *)date;

NS_ASSUME_NONNULL_END
@end
