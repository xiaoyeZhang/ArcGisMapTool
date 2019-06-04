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

@class AGSGeometry;
@class AGSOfflineMapItemInfo;

/** @file AGSGenerateOfflineMapParameters.h */ //Required for Globals API doc

/** @brief Parameters used with `AGSOfflineMapTask` to take a map offline
 
 Instances of this class represent parameters that are used with `AGSOfflineMapTask#generateOfflineMapJobWithParameters:downloadDirectory:` to create a job that can take a map offline.
 
 @see `AGSOfflineMapTask#defaultGenerateOfflineMapParametersWithAreaOfInterest:completion:` convenience method to get parameters that are initialized with appopriate default values for a map.
 @since 100.1
 */
@interface AGSGenerateOfflineMapParameters : AGSObject

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

/** Initialize the parameters with the provided information for taking a map offline.
 @param areaOfInterest  An `AGSPolygon` or `AGSEnvelope` geometry that defines the geographic area for which the map data (features and tiles) should be taken offline
 @param minScale The minimum scale for which map tiles are needed. There won't be any tiles offline when the map is zoomed out beyond this scale.
 @param maxScale The maximum scale for which map tiles are needed. There won't be any tiles offline when the map is zoomed in beyond this scale.
 @return initialized parameters
 @since 100.1
 */
-(instancetype)initWithAreaOfInterest:(AGSGeometry*)areaOfInterest minScale:(double)minScale maxScale:(double)maxScale;

+(instancetype)generateOfflineMapParameters;

/** Initialize the parameters with the provided information for taking a map offline.
 @param areaOfInterest  An `AGSPolygon` or `AGSEnvelope` geometry that defines the geographic area for which the map data (features and tiles) should be taken offline
 @param minScale The minimum scale for which map tiles are needed. There won't be any tiles offline when the map is zoomed out beyond this scale.
 @param maxScale The maximum scale for which map tiles are needed. There won't be any tiles offline when the map is zoomed in beyond this scale.
 @return initialized parameters
 @since 100.1
 */
+(instancetype)generateOfflineMapParametersWithAreaOfInterest:(AGSGeometry*)areaOfInterest minScale:(double)minScale maxScale:(double)maxScale;


#pragma mark -
#pragma mark properties

/** An `AGSPolygon` or `AGSEnvelope` geometry that defines the geographic area for which the map data (features and tiles) should be taken offline
 @since 100.1
 */
@property (nonatomic, strong, readwrite) AGSGeometry *areaOfInterest;

/** The maximum scale for how far in to extract tiles from tile caches. This also determines the offline map's `AGSMap#maxScale` property. The 0 default means extract the levels down to the most detailed.
 @note This is used as input for levels of detail for `AGSTileCache` and `AGSVectorTileCache`. This is not applicable to offline data in `AGSGeodatabase`. A minScale of 100000 and a maxScale of 500 will select level IDs between 1:500 and 1:100,000 scale. A minScale of 0 and a maxScale of 500 will select all global level IDs down to 1:500 scale. A minScale of 100000 and a maxScale of 0 will select level IDs from 1:100,000 scale to the most detailed available level. If `AGSGenerateOfflineMapParameters` is used in conjunction with `AGSGenerateOfflineMapParameterOverrides`, this property is superseded for individual layers tile caches. However, the max scale will still be used as the offline map's `AGSMap#maxScale` property.
 @since 100.1
 */
@property (nonatomic, assign, readwrite) double maxScale;

/** The minimum scale for how far out data will be in tile caches. This also determines the offline map's `AGSMap#minScale` property. The 0 default means extract all the available detailed levels to global scales.
 @note This is used as input for levels of detail for `AGSTileCache`. This is not applicable to offline data in `AGSVectorTileCache` or `AGSGeodatabase`. A minScale of 100000 and a maxScale of 500 will select level IDs between 1:500 and 1:100,000 scale. A minScale of 0 and a maxScale of 500 will select all global level IDs down to 1:500 scale. A minScale of 100000 and a maxScale of 0 will select level IDs from 1:100,000 scale to the most detailed available level. If `AGSGenerateOfflineMapParameters` is used in conjunction with `AGSGenerateOfflineMapParameterOverrides`, this property is superseded for individual layers tile caches. However, the min scale will still be used as the offline map's `AGSMap#minScale` property.
 @since 100.1
 */
@property (nonatomic, assign, readwrite) double minScale;

/** Metadata about the map that should be persisted when it is taken offline. When using the convenience method `AGSOfflineMapTask#defaultGenerateOfflineMapParametersWithAreaOfInterest:completion:` to get the default parameters, this metadata is initialized based on the map's portal item.
 @since 100.1
 */
@property (nullable, nonatomic, strong, readwrite) AGSOfflineMapItemInfo *itemInfo;

/** Specifies how sync-enabled feature layers in the offline map should be configured to sync attachment data with their originating service. This property should be used in conjunction with `#returnLayerAttachmentOption` to determine which layers should be taken offline with attachments included.
 
 This property is valid when the service resource sync capabilities includes supportsAttachmentsSyncDirection otherwise it is ignored. This property works in conjunction with `returnLayerAttachmentOption` and in some cases may have its value overriden as shown below:
 
 | Layer Attachment Option      | Valid Attachment Sync Direction   | Note                                                                                  |
 | ----------------------       | --------------------------------- | ---------------------------                                                           |
 | None                         | None                              |                                                                                       |
 |                              | Upload                            |                                                                                       |
 | All Layers                   | Upload                            |                                                                                       |
 |                              | Bidirectional                     |                                                                                       |
 | Read Only Layers             | None                              | Layers *with* attachments will treat this as attachmentSyncDirection = Bidirectional  |
 |                              | Upload                            |                                                                                       |
 |                              | Bidirectional                     | Layers *without* attachments will treat this as attachmentSyncDirection = None        |
 | Editable Layers              | None                              | Layers *with* attachments will treat this as attachmentSyncDirection = Bidirectional  |
 |                              | Upload                            |                                                                                       |
 |                              | Bidirectional                     | Layers *without* attachments will treat this as attachmentSyncDirection = None        |
 
 @note If `AGSGenerateOfflineMapParameters` is used in conjunction with `AGSGenerateOfflineMapParameterOverrides` this property is superseded.
 @since 100.1
 */
@property (nonatomic, assign, readwrite) AGSAttachmentSyncDirection attachmentSyncDirection;

/** Indicates whether or not the job should continue running in the event of a failure
 to take a layer offline.
 If this property is true, failure to take a layer or table offline will not fail the job, the failure will be
 exposed in the job result. If this property is false, failure to take a layer or table offline will fail the job
 and no more layers or tables will be taken offline. The layer or table's error will be available as the job's error.
 Default value is `true`
 @since 100.4
 */
@property (nonatomic, assign, readwrite) BOOL continueOnErrors;

/** Specifies whether the basemap should be included when the map is taken offline.
 @note If `AGSGenerateOfflineMapParameters` is used in conjunction with `AGSGenerateOfflineMapParameterOverrides` this property is superseded.
 @since 100.1
 */
@property (nonatomic, assign, readwrite) BOOL includeBasemap;

/**
 A value of true allows the `AGSGenerateOfflineMapJob` to use the SQL where clause in `AGSFeatureLayer#definitionExpression`
 as a filter when generating offline geodatabases. Applying the definition expression may reduce the number of features taken
 offline for display and sync. If the value is false this could result in a larger geodatabase than is required to display the
 feature layer. The default value is true. For tables the definition expression is taken from the property
 `AGSServiceFeatureTable#definitionExpression`.
 @note If `AGSGenerateOfflineMapParameters` is used in conjunction with `AGSGenerateOfflineMapParameterOverrides` this property is superseded.
 @since 100.3
 */
@property (nonatomic, assign, readwrite, getter=isDefinitionExpressionFilterEnabled) BOOL definitionExpressionFilterEnabled;

/** Specifies whether or not to include attachments for feature layers when taking the map offline. Attachments can be included with none of the layers, all of the layers, read only layers or editable layers. This option should be used in conjuction with `#attachmentSyncDirection` to control how the attachments are synced.
 
 For offline maps, a feature layer is considered to be editable if the feature service has capabilities that include any of create, update or delete. A read-only layer is one that supports sync, but does not have any of create, update or delete capability. Service capabilities are accessible from service infos. For more information, see `AGSArcGISFeatureServiceInfo#featureServiceCapabilities` or `AGSArcGISFeatureLayerInfo#capabilities`.
 
 | Layer Attachment Option      | Valid Attachment Sync Direction   | Note                                                                                  |
 | ----------------------       | --------------------------------- | ---------------------------                                                           |
 | None                         | None                              |                                                                                       |
 |                              | Upload                            |                                                                                       |
 | All Layers                   | Upload                            |                                                                                       |
 |                              | Bidirectional                     |                                                                                       |
 | Read Only Layers             | None                              | Layers *with* attachments will treat this as attachmentSyncDirection = Bidirectional  |
 |                              | Upload                            |                                                                                       |
 |                              | Bidirectional                     | Layers *without* attachments will treat this as attachmentSyncDirection = None        |
 | Editable Layers              | None                              | Layers *with* attachments will treat this as attachmentSyncDirection = Bidirectional  |
 |                              | Upload                            |                                                                                       |
 |                              | Bidirectional                     | Layers *without* attachments will treat this as attachmentSyncDirection = None        |
 
 @note If `AGSGenerateOfflineMapParameters` is used in conjunction with `AGSGenerateOfflineMapParameterOverrides` this property is superseded.
 
 @since 100.1
 */
@property (nonatomic, assign, readwrite) AGSReturnLayerAttachmentOption returnLayerAttachmentOption;

/** Specifies whether to only include the schema or also include data for feature layers when taking the map offline.
 @note If `AGSGenerateOfflineMapParameters` is used in conjunction with `AGSGenerateOfflineMapParameterOverrides` this property is superseded.
 @since 100.1
 */
@property (nonatomic, assign, readwrite) BOOL returnSchemaOnlyForEditableLayers;
 
/** Specifies whether tables in relationships will contain all rows or can be filtered to a smaller set of related rows. Setting this to
 `AGSDestinationTableRowFilterRelatedOnly` can substantially reduce the number of rows in offline tables to only those that are related
 to rows from other layers or tables. Only tables present in `AGSMap#tables` are considered as candidates for filtering.
 This does not apply when the table:
 - is the origin of a relationship and not a destination.
 - is a destination of a relationship from a layer or table which is not in the map.
 - is editable and `#returnSchemaOnlyForEditableLayers` is true.
 - has a `AGSServiceFeatureTable#definitionExpression` and `AGSGenerateOfflineMapParameters#definitionExpressionFilterEnabled` is true.
 Default value is `AGSDestinationTableRowFilterRelatedOnly`
 @note The relationships of a table are accessible via `AGSArcGISFeatureTable#layerInfo and the `AGSArcGISFeatureLayerInfo#relationshipInfos` property.
 @since 100.4
 */
@property (nonatomic, assign, readwrite) AGSDestinationTableRowFilter destinationTableRowFilter;

#pragma mark -
#pragma mark methods

@end

NS_ASSUME_NONNULL_END
