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

@class AGSPortalItem;
@class NSURL;
@class AGSVectorTileSourceInfo;
@class AGSExportVectorTilesParameters;
@class AGSExportVectorTilesJob;

#import "AGSLoadableRemoteResourceBase.h"

/** @file AGSExportVectorTilesTask.h */ //Required for Globals API doc

/** @brief A task used to export vector tiles and optionally a portal item's vector tile style resources
 
 Instances of this class represent a task that can be used to download vector tiles and their associated style resources (as a vector tile package, .vtpk file) from supporting ArcGIS Vector Tile services. The service could be hosted in the cloud on ArcGIS Online or on-premises with ArcGIS Enterprise.
 
 You can use `#hasStyleResources` to check if the portal item representing the ArcGIS Vector tile service has any custom style resources that override the default style associated with the service. The custom style resources can be exported separately using `#exportStyleResourceCacheJobWithDownloadDirectory:completion:`
 
 @since 100.2
 */
@interface AGSExportVectorTilesTask : AGSLoadableRemoteResourceBase

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

/** Initialize the task with an item on ArcGIS Online or ArcGIS Portal representing an ArcGIS Vector Tile layer. The item's type must be `AGSPortalItemTypeVectorTileService`
 @note The Vector Tile service referred to by the item must have the export tiles capability enabled. See `AGSVectorTileSourceInfo#exportTilesAllowed`
 @param portalItem representing an ArcGIS Vector Tile layer.
 @return initialized task
 @since 100.2
 */
-(instancetype)initWithPortalItem:(AGSPortalItem *)portalItem;

/** Initialize the task with a URL to an ArcGIS Vector Tile service.
 @note The service must have the export tiles capability enabled or the task will fail to load. See `AGSVectorTileSourceInfo#exportTilesAllowed`.
 @param URL to an ArcGIS Vector Tile service. A vector tile service URL ends in 'VectorTileServer' (e.g. https://basemaps.arcgis.com/arcgis/rest/services/World_Basemap_v2/VectorTileServer).
 @return initialized task
 @since 100.2
 */
-(instancetype)initWithURL:(NSURL *)URL;

/** Initialize the task with an item on ArcGIS Online or ArcGIS Portal representing an ArcGIS Vector Tile layer. The item's type must be `AGSPortalItemTypeVectorTileService` or the task will fail to load.
 @note The Vector Tile service referred to by the item must have the export tiles capability enabled. See `AGSVectorTileSourceInfo#exportTilesAllowed`
 @param portalItem representing an ArcGIS Vector Tile layer.
 @return initialized task
 @since 100.2
 */
+(instancetype)exportVectorTilesTaskWithPortalItem:(AGSPortalItem *)portalItem;

/** Initialize the task with a URL to an ArcGIS Vector Tile service.
 @note The service must have the export tiles capability enabled. See `AGSVectorTileSourceInfo#exportTilesAllowed`
 @param URL to an ArcGIS Vector Tile service.
 @return initialized task
 @since 100.2
 */
+(instancetype)exportVectorTilesTaskWithURL:(NSURL *)URL;

#pragma mark -
#pragma mark properties
/** Indicates if the task's portal item has any associated style resources. These resources are typically used to override the service's default style.
 @note Use `#exportStyleResourceCacheJobWithDownloadDirectory:` to download the style without any tiles. Use `#exportVectorTilesJobWithParameters:vectorTileCacheDownloadFileURL:itemResourceCacheDownloadDirectory:` to download the style and the tiles.
 @note This is only true if the task has loaded from a portal item and that portal item has associated style resources.
 @since 100.2
 */
@property (nonatomic, assign, readonly) BOOL hasStyleResources;

/** Portal item representing an ArcGIS vector tile service. The item's type must be `AGSPortalItemTypeVectorTileService`
 @note The portal item can also contain custom style resources. See `#hasStyleResources`.
 @note This will be nil if the task was initialized with a URL.
 @since 100.2
 */
@property (nullable, nonatomic, strong, readonly) AGSPortalItem *portalItem;

/** Information about the source of vector tiles that this task will extract tiles from.
 `AGSVectorTileSourceInfo#exportTilesAllowed` should permit the tiles to be exported.
 @since 100.2
 */
@property (nullable, nonatomic, strong, readonly) AGSVectorTileSourceInfo *vectorTileSourceInfo;

#pragma mark -
#pragma mark methods

/** A convenience method to get properly initialized parameters for exporting tiles. It will calculate
 the levels of detail (LODs) required based on the specified max scale and the tiling scheme of the service.  Be careful when you provide a large area of interest or a small maximum scale value as this could result in a large number of tiles being requested.
 
 @param areaOfInterest A polygon or envelope geometry representing the geographic area for which tiles are needed. Point and Polyline geometries are not supported
 @param maxScale The maximum map scale for which tiles are needed. There won't be any tiles when the map is zoomed in beyond this scale. Set the value to 0 to include all levels of detail in the service.
 @param completion block that is invoked when the operation is complete with either the results or an error.
 @return operation which can be canceled
 @since 100
 @since 100.2
 */
-(id<AGSCancelable>)defaultExportVectorTilesParametersWithAreaOfInterest:(AGSGeometry *)areaOfInterest
                                                                maxScale:(double)maxScale
                                                               completion:(void(^)(AGSExportVectorTilesParameters * __nullable params, NSError * __nullable error))completion;


/** Returns a job which can be used to separately download any associated custom style resources for the vector tiles. Note, it does not download the vector tiles. This is useful if you want to download the style resources once and then re-use them with multiple tile packages containing only the data tiles which keeps their size to a minimum. Only applicable if `#hasStyleResources` is true indicating that the task's portal item contains style resources.
 @see `AGSExportVectorTilesResult#itemResourceCache` representing the cache that will contain the custom style resources
 @note The job is dormant and needs to be explicitly started using `AGSExportVectorTilesJob#startWithStatusHandler:completion:`
 @param downloadDirectory where the cutom style resources will be saved
 @return job representing the progress on the server. The result of the job will be of type `AGSExportVectorTilesResult`
 @since 100.2
 */
-(AGSExportVectorTilesJob*)exportStyleResourceCacheJobWithDownloadDirectory:(NSURL*)downloadDirectory;


/** Returns a job which can be used to generate and download a vector tile package containing tiles and the default style resources associated with the service. The result of the job will be of type `AGSExportVectorTilesResult`. Note, if this task is based on a portal item that has custom style overrides (`#hasStyleResources` = true), the custom style will not be downloaded and as a result the exported vector tiles may look different when viewed in a map. To download the custom styles, consider using `#exportStyleResourceCacheJobWithDownloadDirectory:` or `#exportVectorTilesJobWithParameters:vectorTileCacheDownloadFileURL:itemResourceCacheDownloadDirectory:` .
 @see `AGSExportVectorTilesResult#vectorTileCache` representing the cache that will contain the vector tiles
 @note The job is dormant and needs to be explicitly started using `AGSExportVectorTilesJob#startWithStatusHandler:completion:`
 @param parameters specifying which tiles to include in the tile package
 @param downloadFileURL where the tile package should be saved on disk, including the desired file name ending with the .vtpk file extension.
 @return job representing the progress on the server. The result of the job will be of type `AGSExportVectorTilesResult`
 @since 100.2
 */
-(AGSExportVectorTilesJob*)exportVectorTilesJobWithParameters:(AGSExportVectorTilesParameters*)parameters
                                              downloadFileURL:(NSURL *)downloadFileURL;


/** Returns a job which can be used to generate and download a vector tile package containing the tiles specified by the parameters. The task portal item's associated style resources will be downloaded and saved separately to `itemResourceCacheDownloadDirectory`. Only applicable if `#hasStyleResources` is true indicating that the task's portal item contains style resources. The result of the job will be of type `AGSExportVectorTilesResult`
 @see `AGSExportVectorTilesResult#vectorTileCache` representing the cache that will contain the vector tiles
 @see `AGSExportVectorTilesResult#itemResourceCache` representing the cache that will contain the custom style resources
 @note The job is dormant and needs to be explicitly started using `AGSExportVectorTilesJob#startWithStatusHandler:completion:`
 @param parameters specifying which tiles to include in the tile package
 @param vectorTileCacheDownloadFileURL where the tile package should be saved on disk, including the desired file name ending with the .vtpk file extension.
 @param itemResourceCacheDownloadDirectory where the custom style resources will be saved
 @return job representing the progress on the server. The result of the job will be of type `AGSExportVectorTilesResult`
 @since 100.2
 */
-(AGSExportVectorTilesJob*)exportVectorTilesJobWithParameters:(AGSExportVectorTilesParameters*)parameters
                               vectorTileCacheDownloadFileURL:(NSURL *)vectorTileCacheDownloadFileURL
                           itemResourceCacheDownloadDirectory:(NSURL*)itemResourceCacheDownloadDirectory;

NS_ASSUME_NONNULL_END

@end
