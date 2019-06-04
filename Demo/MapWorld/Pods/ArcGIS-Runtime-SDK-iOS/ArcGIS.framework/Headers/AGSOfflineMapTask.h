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

@class AGSMap;
@class AGSPortalItem;
@class AGSGenerateOfflineMapJob;
@class AGSGenerateOfflineMapParameters;
@class AGSOfflineMapCapabilities;
@class AGSDownloadPreplannedOfflineMapJob;
@class AGSPreplannedMapArea;
@class AGSDownloadPreplannedOfflineMapParameters;
@class AGSGenerateOfflineMapParameterOverrides;

#import "AGSLoadableBase.h"

/** @file AGSOfflineMapTask.h */ //Required for Globals API doc

/** @brief A task to take a map offline
 
 Instances of this class represent a task that can be used to take a map offline. Taking a map offline involves downloading the map's metadata, its constituent layers, and their data.
 
 @since 100.1
 */
@interface AGSOfflineMapTask : AGSLoadableBase

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

/** Initialize the task with the provided map to take offline. The map must be a webmap either on ArcGIS Online or an on-premises ArcGIS Portal.
 @param onlineMap to take offline
 @return a new intitalized task
 @since 100.1
 */
-(instancetype)initWithOnlineMap:(AGSMap *)onlineMap;

/** Initialize the task with the provided portal item. The item must represent a webmap (item type should be `AGSPortalItemTypeWebMap`) either on ArcGIS Online or an on-premises ArcGIS Portal.
 @param portalItem specifying a map to take offline
 @return a new intitalized task
 @since 100.1
 */
-(instancetype)initWithPortalItem:(AGSPortalItem *)portalItem;

/** Initialize the task with the provided map to take offline. The map must be a webmap either on ArcGIS Online or an on-premises ArcGIS Portal.
 @param onlineMap to take offline
 @return a new intitalized task
 @since 100.1
 */
+(instancetype)offlineMapTaskWithOnlineMap:(AGSMap *)onlineMap;

/** Initialize the task with the provided portal item. The item must represent a webmap (item type should be `AGSPortalItemTypeWebMap`) either on ArcGIS Online or an on-premises ArcGIS Portal.
 @param portalItem specifying a map to take offline
 @return a new intitalized task
 @since 100.1
 */
+(instancetype)offlineMapTaskWithPortalItem:(AGSPortalItem *)portalItem;

#pragma mark -
#pragma mark properties

/** The map to take offline. The map must be a webmap either on ArcGIS Online or an on-premises ArcGIS Portal.
 @since 100.1
 */
@property (nullable, nonatomic, strong, readonly) AGSMap *onlineMap;

/** Portal item specifying the map to take offline. The item must represent a webmap (item type should be `AGSPortalItemTypeWebMap`) either on ArcGIS Online or an on-premises ArcGIS Portal.
 @since 100.1
 */
@property (nullable, nonatomic, strong, readonly) AGSPortalItem *portalItem;

#pragma mark -
#pragma mark methods

/** Returns a job which can be used to generate an offline map using the specified parameters. The result of the job will be of type `AGSGenerateOfflineMapResult`.
 @note The job is dormant and needs to be explicitly started using `AGSGenerateOfflineMapJob#startWithStatusHandler:completion:`
 @param parameters specifying how to take a map offline
 @param downloadDirectory where the offline map should be saved on disk. If the directory exists it should be empty otherwise the operation will fail. If the directory doesn't exist, it will be created by the job.
 @return job to generate an offline map. The result of the job will be of type `AGSGenerateOfflineMapResult`. The job will fail if download directory cannot be created or is not empty.
 @since 100.1
 */
-(AGSGenerateOfflineMapJob *)generateOfflineMapJobWithParameters:(AGSGenerateOfflineMapParameters *)parameters
                                               downloadDirectory:(NSURL *)downloadDirectory;

/** Returns a job that is used to generate an offline map using the specified parameters and overrides.
 @note The job that is returned is dormant and needs to be explicitly started. The job will fail if the last directory in the download directory path cannot be created or is not empty. The `AGSGenerateOfflineMapParameterOverrides` allows more control over the extracted data. To create an instance `AGSGenerateOfflineMapParameterOverrides` use `AGSOfflineMapTask#generateOfflineMapParameterOverridesWithParameters:completion:`. Some properties on `AGSGenerateOfflineMapParameters` will be ignored when using `AGSGenerateOfflineMapParameterOverrides` and replaced with equivalent properties for each service. The overridden properties are `AGSGenerateOfflineMapParameters#includeBasemap`, `AGSGenerateOfflineMapParameters#returnLayerAttachmentOption`, `AGSGenerateOfflineMapParameters#attachmentSyncDirection`, `AGSGenerateOfflineMapParameters#returnSchemaOnlyForEditableLayers` and `AGSGenerateOfflineMapParameters#isDefinitionExpressionFilterEnabled`.
 @param parameters The parameters specifying how to take a map offline. For example, specify the area of interest, min and max scale, layer attachment options
 @param parameterOverrides The overrides to the parameters
 @param downloadDirectory where the offline map should be saved on disk. If the directory exists it should be empty otherwise the operation will fail. If the directory doesn't exist, it will be created by the job.
 @return job to generate an offline map. The result of the job will be of type `AGSGenerateOfflineMapResult`. The job will fail if download directory cannot be created or is not empty.
 @since 100.4
 */
-(AGSGenerateOfflineMapJob *)generateOfflineMapJobWithParameters:(AGSGenerateOfflineMapParameters *)parameters
                                              parameterOverrides:(AGSGenerateOfflineMapParameterOverrides *)parameterOverrides
                                               downloadDirectory:(NSURL *)downloadDirectory;

/** A convenience method to get properly initialized parameters for generating an offline map.
 
 This will populate the parameters with values matching what the service supports. For example if the service does not support `PER_LAYER` sync  model then `PER_GEODATABASE` will be used. All layers from the service will be included. The extent will be the service's full extent. Attachments are included by default, but related tables/layers are not included.
 
 The returned parameter's min scale and max scale are zero and that'll include tiles for the full range of scales the tiled layers support when taking the map offline. The  `itemInfo` property of the parameter is initialized based this task's portal item, if that is set, and will include the item's thumbnail.
 
 @param areaOfInterest An `AGSPolygon` or `AGSEnvelope` geometry that defines the geographic area for which the map data should be taken offline 
 @param completion block that is invoked with the initialized params if the method succeeds, or an error if it fails
 @return operation that can be canceled
 @since 100.1
 */
-(id<AGSCancelable>)defaultGenerateOfflineMapParametersWithAreaOfInterest:(AGSGeometry *)areaOfInterest
                                                               completion:(void(^)(AGSGenerateOfflineMapParameters * __nullable params, NSError * __nullable error))completion;

/** Provides parameters to generate an offline map with the specified area of interest, min scale and max scale.
 @note The area of interest must have a spatial reference. The returned `AGSGenerateOfflineMapParameters` has its `itemInfo` property initialized from the offline map task's portal item, if that is set. The `itemInfo`'s thumbnail will be copied from the portal item's thumbnail.
 @param areaOfInterest An `AGSPolygon` or `AGSEnvelope` geometry that defines the geographic area for which the map data should be taken offline
 @param minScale The minimum scale for the offline map and offline tile caches. Use 0 for all far out levels. See the property `AGSGenerateOfflineMapParameters#minScale`
 @param maxScale The maximum scale for the offline map and offline tile caches. Use 0 for all closer in detailed levels. Sets the property `AGSGenerateOfflineMapParameters#maxScale`.
 @param completion block that is invoked with the initialized params if the method succeeds, or an error if it fails
 @return operation that can be canceled
 @since 100.4
 */
-(id<AGSCancelable>)defaultGenerateOfflineMapParametersWithAreaOfInterest:(AGSGeometry *)areaOfInterest
                                                                 minScale:(double)minScale
                                                                 maxScale:(double)maxScale
                                                               completion:(void(^)(AGSGenerateOfflineMapParameters * __nullable params, NSError * __nullable error))completion;

/** Provides overrides for `AGSGenerateOfflineMapParameters`.
 Upon successful completion, a `AGSGenerateOfflineMapParameterOverrides` instance will be populated reflecting the values in the `AGSGenerateOfflineMapParameters` parameters. The overrides may be inspected and modified to change the offline data before passing onto creating a job with `AGSOfflineMapTask#generateOfflineMapJobWithParameters:parameterOverrides:downloadDirectory:`.
 @since 100.4
 */
-(id<AGSCancelable>)generateOfflineMapParameterOverridesWithParameters:(AGSGenerateOfflineMapParameters*)parameters
                                                            completion:(void(^)(AGSGenerateOfflineMapParameterOverrides * __nullable parameterOverrides, NSError * __nullable error))completion;

/** Provides information about offline capabilities of the map, such as which layers can be taken offline.
 @param parameters specifying how to take the map offline
 @param completion block that is invoked with offline capabilities of the map if the operation succeeds, or an error if it fails
 @return operation that can be canceled
 @since 100.1
 */
-(id<AGSCancelable>)getOfflineMapCapabilitiesWithParameters:(AGSGenerateOfflineMapParameters *)parameters
                                                 completion:(void(^)(AGSOfflineMapCapabilities * __nullable params, NSError * __nullable error))completion;

/** Returns a job which can be used to download an offline map for a preplanned map area. The result of the job will be of type `AGSDownloadPreplannedOfflineMapResult`.
 @note The job is dormant and needs to be explicitly started using `AGSGenerateOfflineMapJob#startWithStatusHandler:completion:`
 @param preplannedMapArea map area for which the data has already been pacakged and staged for download
 @param downloadDirectory directory to download the offline map and its contents to
 @return job to download the offline map. The job will fail if download directory cannot be created or is not empty.
 @since 100.2
 @see `#getPreplannedMapAreasWithCompletion:` to get a list of preplanned map areas for the map this task's `#onlineMap`
 */
-(AGSDownloadPreplannedOfflineMapJob*)downloadPreplannedOfflineMapJobWithArea:(AGSPreplannedMapArea *)preplannedMapArea
                                                            downloadDirectory:(NSURL *)downloadDirectory;

/** Returns a job which can be used to download an offline map for a preplanned map area. The result of the job will be of type `AGSDownloadPreplannedOfflineMapResult`. If you exclude the map's basemap from the download the offline map's size will be smaller and consequently the download process will be faster. If you already have a basemap stored locally on your device you can add that to the offline map.
 @note The job is dormant and needs to be explicitly started using `AGSGenerateOfflineMapJob#startWithStatusHandler:completion:`
 @param preplannedMapArea map area for which the data has already been pacakged and staged for download
 @param downloadDirectory directory to download the offline map and its contents to
 @param excludeBasemap indicating whether or not to exclude the basemap in the offline map
 @return job to download the offline map. The job will fail if download directory cannot be created or is not empty. Excluding the basemap will override the authored settings of preplanned map area and always exclude the basemap content.
 @since 100.2
 @see `#getPreplannedMapAreasWithCompletion:` to get a list of preplanned map areas for the map this task's `#onlineMap`
 */
-(AGSDownloadPreplannedOfflineMapJob*)downloadPreplannedOfflineMapJobWithArea:(AGSPreplannedMapArea *)preplannedMapArea
                                                            downloadDirectory:(NSURL *)downloadDirectory
                                                               excludeBasemap:(BOOL)excludeBasemap;

/** Returns a job which can be used to download an offline map for a preplanned map area using the specified parameters. The result of the job will be of type `AGSDownloadPreplannedOfflineMapResult`.
 @note The job is dormant and needs to be explicitly started using `AGSGenerateOfflineMapJob#startWithStatusHandler:completion:`
 @param parameters `AGSDownloadPreplannedOfflineMapParameters` specify how to take a map offline. For example, specify the area of interest, min and max scale, layer attachment options
 @param downloadDirectory directory to download the offline map and its contents to
 @return job to download the offline map. The job will fail if download directory cannot be created or is not empty.
 @since 100.4
 @see `#getPreplannedMapAreasWithCompletion:` to get a list of preplanned map areas for the map this task's `#onlineMap`
 */
-(AGSDownloadPreplannedOfflineMapJob*)downloadPreplannedOfflineMapJobWithParameters:(AGSDownloadPreplannedOfflineMapParameters *)parameters
                                                                  downloadDirectory:(NSURL *)downloadDirectory;

/** Get a list of preplanned map areas that are available for this task's `#onlineMap`. Preplanned map areas already have the map data packaged and staged for download which speeds up taking a map offline.
 @param completion block that is invoked with the list of preplanned map areas if the operation succeeds, or an error if it fails
 @return operation that can be canceled
 @since 100.2
 */
-(id<AGSCancelable>)getPreplannedMapAreasWithCompletion:(void(^)(NSArray<AGSPreplannedMapArea*> * __nullable preplannedMapAreas, NSError * __nullable error))completion;

@end

NS_ASSUME_NONNULL_END


