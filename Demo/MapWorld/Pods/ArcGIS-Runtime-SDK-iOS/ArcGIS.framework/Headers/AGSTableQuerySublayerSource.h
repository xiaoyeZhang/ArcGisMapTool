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

#import "AGSSublayerSource.h"

@class AGSSpatialReference;

/** @file AGSTableQuerySublayerSource.h */ //Required for Globals API doc

/** @brief A source for `AGSArcGISMapImageSublayer` based on a SQL query of a dataset in a registered workspace
 
 Instances of this class represent a source for `AGSArcGISMapImageSublayer` based on a SQL query of dataset, such as non-spatial table, feature class, or raster, that resides in a registered workspace of the ArcGIS Map Service. The workspace can be either a folder or geodatabase.
 
 @since 100.1
 @see `AGSArcGISMapImageSublayer#initWithID:source:`
 */
@interface AGSTableQuerySublayerSource : AGSSublayerSource

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

/** Initialize the source with the provided parameters.
 @param workspaceID ID of a registered workspace for the ArcGIS Map Service. The workspace can be either a folder or geodatabase.
 @param SQLQuery specifying which dataset and features/rows to include in the source
 @param objectIDFieldNames List of field names specifying which fields should be combined to generate a unique identifier for each feature/row provided by the source. Field types supported are Integer, String, GUID, and Date.
 @since 100.1
 @return A new initialized source
 */
-(instancetype)initWithWorkspaceID:(NSString *)workspaceID
                          SQLQuery:(NSString *)SQLQuery
                objectIDFieldNames:(NSArray<NSString*> *)objectIDFieldNames;

/** Initialize the source with the provided parameters.
 @param workspaceID ID of a registered workspace for the ArcGIS Map Service. The workspace can be either a folder or geodatabase.
 @param SQLQuery specifying which dataset and features/rows to include in the source
 @param objectIDFieldNames List of field names specifying which fields should be combined to generate a unique identifier for each feature/row provided by the source. Field types supported are Integer, String, GUID, and Date.
 @since 100.1
 @return A new initialized source
 */
+(instancetype)tableQuerySublayerSourceWithWorkspaceID:(NSString *)workspaceID
                                              SQLQuery:(NSString *)SQLQuery
                                    objectIDFieldNames:(NSArray<NSString*> *)objectIDFieldNames;

#pragma mark -
#pragma mark properties

/** SQL query specifying which dataset and features/rows to include in the source
 @since 100.1
 */
@property (nonatomic, copy, readonly) NSString *SQLQuery;

/** The type of geometry used by features belonging to the dataset.
 @since 100.1
 */
@property (nonatomic, assign, readwrite) AGSGeometryType geometryType;

/** List of field names specifying which fields should be combined to generate a unique identifier for each feature/row provided by the source. Field types supported are Integer, String, GUID, and Date.
 
 If a single integer field is specified, the service uses the values in that field directly to uniquely identify all features and rows returned from a queryTable. However, if a single string field or a group of fields is used as the unique identifier, map server maps those unique values to an integer.
 Since the value in the unique identifier field uniquely identifies a row or feature object, values in that field must always be unique and not null.  Operations will behave unpredictably when non-unique or null values are encountered. It is your responsibility to guarantee that values in this field meet this requirement. The service does not enforce the uniqueness of values in the unique identifier field of a queryTable. If multiple fields are chosen, the values in these fields will be used as a key to generate a unique integer value. This resultant field is always called ESRI_OID unless a field of that name already exists.
 @since 100.1
 */
 @property (nonatomic, copy, readonly) NSArray<NSString*> *objectIDFieldNames;

/** The spatial reference of features' geometry
 @since 100.1
 */
@property (nullable, nonatomic, strong, readwrite) AGSSpatialReference *spatialReference;

/** ID of a registered workspace for the ArcGIS Map Service. The workspace can be either a folder or geodatabase.
 @since 100.1
 */
@property (nonatomic, copy, readonly) NSString *workspaceID;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end

