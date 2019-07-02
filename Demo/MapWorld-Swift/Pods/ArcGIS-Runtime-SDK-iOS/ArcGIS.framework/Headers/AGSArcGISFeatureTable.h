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
#import "AGSFeatureTable.h"

@class AGSArcGISFeatureServiceInfo;
@class AGSArcGISFeatureLayerInfo;
@class AGSFeatureQueryResult;
@class AGSFeatureTemplate;
@class AGSFeatureType;
@class AGSField;
@class AGSArcGISFeature;
@class AGSRelatedQueryParameters;
@class AGSRelationshipInfo;
@class AGSRelatedFeatureQueryResult;
@class AGSFeatureSubtype;

/** @file AGSArcGISFeatureTable.h */ //Required for Globals API doc

/** @brief An ArcGIS specific source for dataset containing geographic features or non-spatial records
 
 Subclasses represent an ArcGIS-specific source for dataset that could include either geographic features or non-spatial records. You can query the dataset using attribute or spatial criteria, and if permitted, also edit the data. Edits are tracked, so you can later retrieve a list of edits. If the dataset contains geographic features you can display them on a map using `AGSFeatureLayer`.
 
 @since 100
 */
@interface AGSArcGISFeatureTable : AGSFeatureTable

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

#pragma mark -
#pragma mark properties

/** The code for the default feature subtype. This value is for the field specified in `#subtypeField`
 @see `#featureSubTypes` for the list of feature subtypes available
 @since 100.3
 */
@property (nullable, nonatomic, copy, readonly) id defaultSubtypeCode;

/** Array of @c AGSField objects representing the subset of fields (columns) in the dataset that are editable.
@since 100
 */
@property (nonatomic, copy, readonly) NSArray<AGSField*> *editableAttributeFields;

/** A collection of @c AGSFeatureSubtype objects representing feature sub-types in
 the layer. For example, a @em roads layer may contain 2 feature sub-types : highways
 and streets.
 @since 100.3
 */
@property (nonatomic, copy, readonly) NSArray<AGSFeatureSubtype*> *featureSubtypes;

/** A collection of @c AGSFeatureTemplate objects representing feature templates
 for the layer. Usually only present if the layer does not contain feature
 sub-types. Only applicable if this dataset is based on an ArcGIS Feature
 Service.
 @since 100
 */
@property (nonatomic, copy, readonly) NSArray<AGSFeatureTemplate*> *featureTemplates;

/** A collection of @c AGSFeatureType objects representing feature sub-types in
 the layer. For example, a @em roads layer may contain 2 feature sub-types : highways
 and streets.
 @avail{10.0}
 @since 100
 */
@property (nonatomic, copy, readonly) NSArray<AGSFeatureType*> *featureTypes;

/** The name of field which contains the @em GLOBALID for each feature
 @since 100
 */
@property (nonatomic, copy, readonly) NSString *globalIDField;

/** Indicates whether features may have attachments.
 @since 100
 */
@property (nonatomic, assign, readonly) BOOL hasAttachments;


/** The name of field which contains the @em OBJECTID for each feature
 @since 100
 */
@property (nonatomic, copy, readonly) NSString *objectIDField;


/** The ID of the layer this table corresponds to in the service.
 @since 100
 */
@property (nonatomic, assign, readonly) NSInteger serviceLayerID;

/** The name of the field which contains the sub-type information for each feature.
 @since 100.3
 */
@property (nonatomic, copy, readonly) NSString *subtypeField;


/** Information about the source this dataset originates from. 
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSArcGISFeatureLayerInfo *layerInfo;

/** The name of the field which contains the sub-type information for each feature.
 @avail{10.0}
 @since 100
 */
@property (nonatomic, copy, readonly) NSString *typeIDField;


/** Indicates whether the dataset should be visualized using advanced CIM symbols.
 The default is NO. Servers which don't support this simply ignore
 the parameter and return regular symbols instead.
 @since 100
 @note You cannot change this after the table is successfully loaded.
 */
@property (nonatomic, assign, readwrite) BOOL useAdvancedSymbology;

#pragma mark -
#pragma mark methods

/** Creates a new feature based on the specified feature
 subtype. Note, the new feature is only available in memory at this point,
 it is not commited to the dataset.
 @param featureSubtype The subtype of feature to create.
 @return The new feature.
 @note The feature will need to be explicitly added to the dataset. See `AGSFeatureTable#addFeature:completion:`
 @since 100.3
 */
-(nullable AGSArcGISFeature *)createFeatureWithSubtype:(AGSFeatureSubtype *)featureSubtype;

/** Creates a new feature based on the specified feature
 template. Note, the new feature is only available in memory at this point,
 it is not commited to the dataset.
 @param featureTemplate The feature template to use while creating the feature.
 @return The new feature.
 @note The feature will need to be explicitly added to the dataset. See `AGSFeatureTable#addFeature:completion:`
 @since 100
 */
-(nullable AGSArcGISFeature *)createFeatureWithTemplate:(AGSFeatureTemplate *)featureTemplate;

/** Creates a new feature based on the specified feature
 subtype and geoemtry. Note, the new feature is only available in memory at this point,
 it is not commited to the dataset.
 @param featureSubtype The type of feature to create.
 @param geometry for the feature
 @return The new feature.
 @note The feature will need to be explicitly added to the dataset. See `AGSFeatureTable#addFeature:completion:`
 @since 100.3
 */
-(nullable AGSArcGISFeature *)createFeatureWithSubtype:(AGSFeatureSubtype *)featureSubtype geometry:(AGSGeometry *)geometry;

/** Creates a new feature based on the specified feature
 template and geometry. Note, the new feature is only available in memory at this point,
 it is not commited to the dataset.
 @param featureTemplate The feature template to use while creating the feature.
 @param geometry for the feature
 @return The new feature.
 @note The feature will need to be explicitly added to the dataset. See `AGSFeatureTable#addFeature:completion:`
 @since 100
 */
-(nullable AGSArcGISFeature *)createFeatureWithTemplate:(AGSFeatureTemplate *)featureTemplate geometry:(AGSGeometry *)geometry;

/** Creates a new feature based on the specified feature
 type. Note, the new feature is only available in memory at this point,
 it is not commited to the dataset.
 @param featureType The type of feature to create.
 @return The new feature.
 @note The feature will need to be explicitly added to the dataset. See `AGSFeatureTable#addFeature:completion:`
 @since 100
 */
-(nullable AGSArcGISFeature *)createFeatureWithType:(AGSFeatureType *)featureType;

/** Creates a new feature based on the specified feature
 type and geoemtry. Note, the new feature is only available in memory at this point,
 it is not commited to the dataset.
 @param featureType The type of feature to create.
 @param geometry for the feature
 @return The new feature.
 @note The feature will need to be explicitly added to the dataset. See `AGSFeatureTable#addFeature:completion:`
 @since 100
 */
-(nullable AGSArcGISFeature *)createFeatureWithType:(AGSFeatureType *)featureType geometry:(AGSGeometry *)geometry;

/**
 Set of features that have been locally added to the dataset, but not yet to the originating source.
 @param completion block that is invoked when the operation finishes. The `result` parameter is populated if the operation completed successfully, otherwise the `error` parameter is populated.
 @return operation which can be canceled
 @since 100
 */
-(id<AGSCancelable>)addedFeaturesWithCompletion:(void(^)(AGSFeatureQueryResult * __nullable result, NSError * __nullable error))completion;

/**
 Number of features that have been locally added to the dataset, but not yet to the originating source.
 @param completion block that is invoked when the operation finishes. The `count` parameter is populated if the operation completed successfully, otherwise the `error` parameter is populated.
 @return operation which can be canceled
 @since 100
 */
-(id<AGSCancelable>)addedFeaturesCountWithCompletion:(void(^)(NSInteger count, NSError * __nullable error))completion;

/**
 Set of features that have been locally deleted from the dataset, but not yet from the originating source.
 @param completion block that is invoked when the operation finishes. The `result` parameter is populated if the operation completed successfully, otherwise the `error` parameter is populated.
 @return operation which can be canceled
 @since 100
 */
-(id<AGSCancelable>)deletedFeaturesWithCompletion:(void(^)(AGSFeatureQueryResult * __nullable result, NSError * __nullable error))completion;

/**
 Number of features that have been locally deleted from the dataset, but not yet from the originating source.
 @param completion block that is invoked when the operation finishes. The `count` parameter is populated if the operation completed successfully, otherwise the `error` parameter is populated.
 @return operation which can be canceled
 @since 100
 */
-(id<AGSCancelable>)deletedFeaturesCountWithCompletion:(void(^)(NSInteger count, NSError * __nullable error))completion;

/**
 Set of features that have been locally updated in the dataset, but not yet in the originating source.
 @param completion block that is invoked when the operation finishes. The `result` parameter is populated if the operation completed successfully, otherwise the `error` parameter is populated.
 @return operation which can be canceled
 @since 100
 */
-(id<AGSCancelable>)updatedFeaturesWithCompletion:(void(^)(AGSFeatureQueryResult * __nullable result, NSError * __nullable error))completion;

/**
 Number of features that have been locally updated in the dataset, but not yet in the originating source.
 @param completion block that is invoked when the operation finishes. The `count` parameter is populated if the operation completed successfully, otherwise the `error` parameter is populated.
 @return operation which can be canceled
 @since 100
 */
-(id<AGSCancelable>)updatedFeaturesCountWithCompletion:(void(^)(NSInteger count, NSError * __nullable error))completion;

/** Convenience method to retrieve a feature template given its name
 @param name of feature template
 @return feature template
 @since 100
 */
-(nullable AGSFeatureTemplate *)featureTemplateForName:(NSString *)name;

/** Convenience method to retrieve a feature type given its name
 @param name of feature type
 @return feature type
 @since 100
 */
-(nullable AGSFeatureType *)featureTypeForName:(NSString *)name;

/** The feature tables (spatial or non-spatial) that are related to this feature table through the specified relationship. The related feature tables must be a part of either the map's operational layers collection (`AGSMap#operationalLayers`) through a feature layer if they are spatial, or the map's tables collection (`AGSMap#tables`) directly if they are non-spatial.
 @param relationshipInfo specifying the relationship based on which results should be returned
 @return feature tables that are related to this table through the specified relationship
 @since 100.1
 */
-(nullable NSArray<AGSArcGISFeatureTable*> *)relatedTablesWithRelationshipInfo:(AGSRelationshipInfo *)relationshipInfo;

/** All feature tables (spatial or non-spatial) that are related to this feature table. The related tables must be part of either the map's operational layers collection (`AGSMap#operationalLayers`) through a feature layer if they are spatial, or the map's tables collection (`AGSMap#tables`) directly if they are non-spatial.
 @since 100.1
 */
-(nullable NSArray<AGSArcGISFeatureTable*> *)relatedTables;

-(id<AGSCancelable>)queryRelatedFeatureCountForFeature:(AGSArcGISFeature *)feature
                                            completion:(void(^)(NSInteger count, NSError * __nullable error))completion;

-(id<AGSCancelable>)queryRelatedFeatureCountForFeature:(AGSArcGISFeature *)feature
                                            parameters:(AGSRelatedQueryParameters *)parameters
                                            completion:(void(^)(NSInteger count, NSError * __nullable error))completion;

/** Returns all features (spatial or non-spatial) that are related to the specified feature. The related features must belong to a feature table that is related to this feature table. Also, the related tables must be part of either the map's operational layers collection (`AGSMap#operationalLayers`) through a feature layer if they are spatial, or the map's tables collection (`AGSMap#tables`) directly if they are non-spatial.
 @param feature for which to find related features (spatial and non-spatial)
 @param completion block that is invoked when the operation finishes. The `results` parameter is populated if the operation completed successfully, otherwise the `error` parameter is populated.
 @return operation which can be canceled
 @since 100.1
 */
-(id<AGSCancelable>)queryRelatedFeaturesForFeature:(AGSArcGISFeature *)feature
                                        completion:(void(^)(NSArray<AGSRelatedFeatureQueryResult*> * __nullable results, NSError * __nullable error))completion;

/** Returns features (spatial or non-spatial) that are related to the specified feature based on the provided parameters. The related features must belong to a feature table that is related to this feature table. Also, the related tables must be part of either the map's operational layers collection (`AGSMap#operationalLayers`) through a feature layer if they are spatial, or the map's tables collection (`AGSMap#tables`) directly if they are non-spatial.
 @param feature for which to find related features (spatial and non-spatial)
 @param parameters specifying which related features to query
 @param completion block that is invoked when the operation finishes. The `results` parameter is populated if the operation completed successfully, otherwise the `error` parameter is populated.
 @return operation which can be canceled
 @since 100.1
 */
-(id<AGSCancelable>)queryRelatedFeaturesForFeature:(AGSArcGISFeature *)feature
                                        parameters:(AGSRelatedQueryParameters *)parameters
                                        completion:(void(^)(NSArray<AGSRelatedFeatureQueryResult*> * __nullable results, NSError * __nullable error))completion;

/** Checks to see if performing edit operations (`AGSFeatureTable#addFeature:completion:` or `AGSFeatureTable#updateFeature:completion:`) with the provided feature could lead to a relationship constraint violation. This method makes network calls to query for the related features if they are not present locally

 @note Edit operations such as `AGSFeatureTable#addFeature:completion:`, `AGSFeatureTable#updateFeature:completion:` do not error due to relationship constraint violations. Rather, it is the responsibility of the developer to use this method to explicitly check for violations @b after the edit is performed. Alternatively, you can recover from violations in a back office operation after applying edits or syncing with the service, if you choose to do so. See ArcGIS Desktop [Validate Features](http://desktop.arcgis.com/en/arcmap/10.3/manage-data/editing-attributes/validating-features-and-relationships-in-arcmap.htm) process.
 
 
 The following are types of violations that may be reported:
 * `AGSRelationshipConstraintViolationTypeOrphaned` : In a composite relationship, adding an orphan feature to the destination table without relating it to an origin feature. To recover from this violation, relate the feature to a valid origin feature.
 * `AGSRelationshipConstraintViolationTypeCardinality` - cardinality violations:
   * In 1:1 relationships, if an origin feature is already related to a destination feature, it is a violation to relate another feature to either of them. To recover from this violation, unrelate the feature from the origin feature.
   * In 1:n relationships, it is a violation to relate a destination feature to more than one origin feature. To recover from this violation, unrelate the feature from the origin feature.
 
 
 @param feature for which relationship constraints need to be validated.
 @param completion block that is invoked when the operation finishes. The `relationshipConstraintViolationType` parameter is populated if the operation completed successfully, otherwise the `error` parameter is populated.
 @return operation which can be canceled
 @since 100.1
 @see `AGSArcGISFeature#relateToFeature:` to relate two features
 @see `AGSArcGISFeature#unrelateToFeature:` to unrelate two features
 */
-(id<AGSCancelable>)validateRelationshipConstraintsForFeature:(AGSArcGISFeature *)feature
                                                   completion:(void(^)(AGSRelationshipConstraintViolationType relationshipConstraintViolationType, NSError * __nullable error))completion;

NS_ASSUME_NONNULL_END

@end
