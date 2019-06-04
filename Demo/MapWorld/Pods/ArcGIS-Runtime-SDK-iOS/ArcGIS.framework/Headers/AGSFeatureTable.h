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
#import "AGSLoadableBase.h"
#import "AGSPopupSource.h"

@class AGSEnvelope;
@class AGSField;
@class AGSQueryParameters;
@class AGSFeature;
@class AGSFeatureQueryResult;
@class AGSEditResult;
@class AGSFeatureLayer;
@class AGSStatisticsQueryParameters;
@class AGSStatisticsQueryResult;

/** @file AGSFeatureTable.h */ //Required for Globals API doc

/** @brief A source for dataset containing geographic features or non-spatial records
 
 Subclasses represent a source for dataset that could include either geographic features or non-spatial records. You can query the dataset using attribute or spatial criteria, and if permitted, also edit the data. If the dataset contains geographic features you can display them on a map using `AGSFeatureLayer`.
 
 @since 100
 */
@interface AGSFeatureTable : AGSLoadableBase <AGSPopupSource>

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

#pragma mark -
#pragma mark properties

/**
 The extent of the dataset.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSEnvelope *extent;

/** The feature layer created with this table, if any.
 @since 100
 */
@property (nullable, nonatomic, weak, readonly) AGSFeatureLayer *featureLayer;

/**
 Array of @c AGSField objects representing the fields (columns) in the dataset.
 @since 100
 */
@property (nonatomic, copy, readonly) NSArray<AGSField*> *fields;

/** The type of geometry used by geographic feautres. Only applicable if `#hasGeometry` is true.
 @since 100
 */
@property (nonatomic, assign, readonly) AGSGeometryType geometryType;

/**
 Indicates whether the dataset contains a geometry field (column).
 If YES, the dataset contains geographic features.
 If NO, the dataset contains non-spatial records, similar to a database table.
 @since 100
 */
@property (nonatomic, assign, readonly) BOOL hasGeometry;

/** Indicates whether features may contain M values
 @since 100.2
 */
@property (nonatomic, assign, readonly) BOOL hasM;

/** Indicates whether features may contain Z values
 @since 100.2
 */
@property (nonatomic, assign, readonly) BOOL hasZ;

/**
 Indicates whether the dataset can be edited.
 For details on which fine-grained editing capabilites are supported, refer to `#canUpdateFeature:` and `#canDeleteFeature:`
 @since 100
 */
@property (nonatomic, assign, readonly, getter=isEditable) BOOL editable;

/** Indicates whether the source supports adding new features.
 @since 100
 */
@property (nonatomic, assign, readonly) BOOL canAddFeature;

/** Indicates whether the source supports updating geometry of existing features.
 @since 100
 */
@property (nonatomic, assign, readonly) BOOL canEditGeometry;

/**
The total number of features or records in the dataset.
@since 100
*/
@property (nonatomic, assign, readonly) NSInteger numberOfFeatures;

/**
 The spatial reference of the dataset.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSSpatialReference *spatialReference;

/**
 Name of the dataset.
 @since 100
 */
@property (nonatomic, copy, readonly) NSString *tableName;

/** User-friendly name that can be displayed in the UI (for example in a Table of Contents)
 @since 100.3
 */
@property (nonatomic, copy, readonly) NSString *displayName;

#pragma mark -
#pragma mark methods


/** Add the specified feature to the dataset.
 @param feature to add.
 @param completion block that is invoked when the operation is complete
 @return operation which can be canceled
 @license{Basic, when editing a local mobile geodatabase or a private feature service. "Public" feature services means services hosted on the Internet and available anonymously (not secured). "Private" includes all other scenarios such as feature services hosted on a local network within an enterprise or feature services hosted on the Internet but secured}
 @ingroup licensing
 @since 100
 */
-(id<AGSCancelable>)addFeature:(AGSFeature *)feature completion:(nullable void(^)(NSError *__nullable error))completion;

/** Add the specified features to the dataset.
 If one of the features fails, all will be rolled back. The error will contain the objectID of the feature that failed.
 @param features to add.
 @param completion block that is invoked when the operation is complete
 @return operation which can be canceled
 @license{Basic, when editing a local mobile geodatabase or a private feature service. "Public" feature services means services hosted on the Internet and available anonymously (not secured). "Private" includes all other scenarios such as feature services hosted on a local network within an enterprise or feature services hosted on the Internet but secured}
 @ingroup licensing
 @since 100
 */
-(id<AGSCancelable>)addFeatures:(NSArray<AGSFeature*> *)features completion:(nullable void(^)(NSError *__nullable error))completion;

/** Indicates whether the source allows this particular feature to be deleted. The method first checks to verify if the source is capable of deleting any features in general. It also checks specific ownership-based access control policies of the source to see if the  user attempting to perform the operation has persmissions to delete this particular feature.
 @param feature Can be nil, in which case, this method only checks if the source is capable of deleting any features in general
 @return A boolean value
 @since 100
 */
-(BOOL)canDeleteFeature:(AGSFeature *)feature;

/** Indicates whether the source allows updating this particular feature. The method first checks to verify if the source is capable of updating any features in general. It also checks specific ownership-based access control policies of the source to see if the user attempting to perform the operation has persmissions to edit this patricular feature.
 @param feature Can be nil, in which case, this method only checks if the source is capable of updating any features in general
 @return A boolean value
 @since 100
 */
-(BOOL)canUpdateFeature:(AGSFeature *)feature;

/** Create a new, empty feature. Note, the new feature is only available in memory at this point,
 it is not commited to the dataset.
 @return emtpy feature
 @since 100
 @note The feature will need to be explicitly added to the dataset. See `#addFeature:completion:`
 */
-(AGSFeature *)createFeature;

/** Create a new feature with the provided attribute values and, optionally, geometry. Note, the new feature is only available in memory at this point,
 it is not commited to the dataset.
 @param attributes for the feature
 @param geometry for the feature
 @return feature
 @since 100
 @note The feature will need to be explicitly added to the dataset. See `#addFeature:completion:`
 */
-(AGSFeature *)createFeatureWithAttributes:(NSDictionary<NSString*,id> *)attributes geometry:(nullable AGSGeometry *)geometry;

/** Delete the specified feature in the dataset.
 @param feature to delete.
 @param completion block that is invoked when the operation is complete
 @return operation which can be canceled
 @license{Basic, when editing a local mobile geodatabase or a private feature service. "Public" feature services means services hosted on the Internet and available anonymously (not secured). "Private" includes all other scenarios such as feature services hosted on a local network within an enterprise or feature services hosted on the Internet but secured}
 @ingroup licensing
 @since 100
 @see @c #canDeleteFeature: to check if a particular feature can be deleted based on the source's ownership-based access control policies
 */
-(id<AGSCancelable>)deleteFeature:(AGSFeature *)feature completion:(nullable void(^)(NSError *__nullable error))completion;

/** Delete the specified features in the dataset.
 If one of the features fails, all will be rolled back. The error will contain the objectID of the feature that failed.
 @param features to delete.
 @param completion block that is invoked when the operation is complete
 @return operation which can be canceled
 @license{Basic, when editing a local mobile geodatabase or a private feature service. "Public" feature services means services hosted on the Internet and available anonymously (not secured). "Private" includes all other scenarios such as feature services hosted on a local network within an enterprise or feature services hosted on the Internet but secured}
 @ingroup licensing
 @since 100
 @see @c #canDeleteFeature: to check if a particular feature can be deleted based on the source's ownership-based access control policies
 */
-(id<AGSCancelable>)deleteFeatures:(NSArray<AGSFeature*> *)features completion:(nullable void(^)(NSError *__nullable error))completion;

/** Convenience method to getting a field object given its name
 @param fieldName The name of the field.
 @return field
 @since 100
 */
-(nullable AGSField *)fieldForName:(NSString *)fieldName;

/**
 Query the dataset to find specific features or records.
 @param parameters representing the query criteria
 @param completion The block that is called when the query is complete
 @return operation which can be canceled
 @since 100
 */
-(id<AGSCancelable>)queryFeaturesWithParameters:(AGSQueryParameters *)parameters
                                     completion:(nullable void(^)(AGSFeatureQueryResult *__nullable result, NSError *__nullable error))completion;

/** Query the dataset to find the geographic extent covering matched features or records.
 @param parameters representing the query criteria
 @param completion The block that is called when the query is complete
 @return operation which can be canceled
 @since 100.2
 */
-(id<AGSCancelable>)queryExtentWithParameters:(AGSQueryParameters *)parameters
                                   completion:(void(^)(AGSEnvelope *__nullable extent, NSError *__nullable error))completion;

/** Query the dataset to find the number of matched features or records.
 @param parameters representing the query criteria
 @param completion The block that is called when the query is complete
 @return operation which can be canceled
 @since 100.2
 */
-(id<AGSCancelable>)queryFeatureCountWithParameters:(AGSQueryParameters *)parameters
                                         completion:(void(^)(NSInteger count, NSError *__nullable error))completion;

/** Query the dataset to compute statistics on matched features or records.
 @param parameters representing the query criteria
 @param completion The block that is called when the query is complete
 @return operation which can be canceled
 @since 100.2
 */
-(id<AGSCancelable>)queryStatisticsWithParameters:(AGSStatisticsQueryParameters *)parameters
                                       completion:(void(^)(AGSStatisticsQueryResult *__nullable result, NSError *__nullable error))completion;

/** Update the specified feature in the dataset.
 @param feature to update.
 @param completion block that is invoked when the operation is complete
 @return operation which can be canceled
 @license{Basic, when editing a local mobile geodatabase or a private feature service. "Public" feature services means services hosted on the Internet and available anonymously (not secured). "Private" includes all other scenarios such as feature services hosted on a local network within an enterprise or feature services hosted on the Internet but secured}
 @ingroup licensing
 @since 100
 @see @c #canUpdateFeature: to check if a particular feature can be updated based on the source's ownership-based access control policies
 */
-(id<AGSCancelable>)updateFeature:(AGSFeature *)feature completion:(nullable void(^)(NSError *__nullable error))completion;

/** Update the specified features in the dataset.
 If one of the features fails, all will be rolled back. The error will contain the objectID of the feature that failed.
 @param features to update.
 @param completion block that is invoked when the operation is complete
 @return operation which can be canceled
 @license{Basic, when editing a local mobile geodatabase or a private feature service. "Public" feature services means services hosted on the Internet and available anonymously (not secured). "Private" includes all other scenarios such as feature services hosted on a local network within an enterprise or feature services hosted on the Internet but secured}
 @ingroup licensing
 @since 100
 @see @c #canUpdateFeature: to check if a particular feature can be updated based on the source's ownership-based access control policies
 */
-(id<AGSCancelable>)updateFeatures:(NSArray<AGSFeature*> *)features completion:(nullable void(^)(NSError *__nullable error))completion;

NS_ASSUME_NONNULL_END

@end
