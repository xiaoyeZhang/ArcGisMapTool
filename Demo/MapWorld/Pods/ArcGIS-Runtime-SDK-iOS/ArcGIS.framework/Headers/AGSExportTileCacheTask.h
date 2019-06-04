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

#import "AGSLoadableRemoteResourceBase.h"

@class AGSArcGISMapServiceInfo;
@class AGSExportTileCacheParameters;
@class AGSExportTileCacheJob;
@class AGSEstimateTileCacheSizeJob;

/** @file AGSExportTileCacheTask.h */ //Required for Globals API doc

/** @brief A task to export and download tile packages
 
 Instances of this class represent a task that can be used to download tiles (as a tile package, .tpk file) from supporting tiled ArcGIS Map services. The service could be hosted in the cloud on ArcGIS Online or on-premises with ArcGIS server.
 
 @since 100
 @see `AGSTileCache`
 */

@interface AGSExportTileCacheTask : AGSLoadableRemoteResourceBase

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

/** Initialize the task with a URL to a tiled ArcGIS Map service
 @param URL to a tiled ArcGIS Map service
 @return initialized task
 @since 100
 */
-(instancetype)initWithURL:(NSURL*)URL;

/** Initialize the task with a URL to a tiled ArcGIS Map service
 @param URL to a tiled ArcGIS Map service
 @return initialized task
 @since 100
 */
+(instancetype)exportTileCacheTaskWithURL:(NSURL*)URL;

#pragma mark -
#pragma mark properties

/** Metadata about the ArcGIS Map service that the task is using
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSArcGISMapServiceInfo *mapServiceInfo;

#pragma mark -
#pragma mark methods

/** A convenience method to get properly initialized parameters for exporting tiles. It will calculate 
 the levels of detail (LODs) required based on the specified min and max scale and the tiling scheme of the service.
 
 @param areaOfInterest A polygon or envelope geometry representing the geographic area for which tiles are needed. Point and Polyline geometries are not supported
 @param minScale The minimum map scale for which tiles are needed. There won't be any tiles when the map is zoomed out beyond this scale.
 @param maxScale The maximum map scale for which tiles are needed. There won't be any tiles when the map is zoomed in beyond this scale.
 @param completion block that is invoked when the operation is complete with either the results or an error.
 @return operation which can be canceled
 @since 100
 */
-(id<AGSCancelable>)exportTileCacheParametersWithAreaOfInterest:(AGSGeometry *)areaOfInterest
                                                        minScale:(double)minScale
                                                        maxScale:(double)maxScale
                                                      completion:(void(^)(AGSExportTileCacheParameters * __nullable exportTileCacheParameters, NSError * __nullable error))completion;

/** Returns a job which can be used to get a size estimate of the tile package contaning tiles specified by the parameters. The result of the job will be of type `AGSEstimateTileCacheSizeResult`.
 @note The job is dormant and needs to be explicitly started using `AGSEstimateTileCacheSizeJob#startWithStatusHandler:completion:`
 @param parameters specifying which tiles to include in the tile package
 @return job representing the progress on the server. The result of the job will be of type `AGSEstimateTileCacheSizeResult`
 @since 100
 */
-(AGSEstimateTileCacheSizeJob*)estimateTileCacheSizeJobWithParameters:(AGSExportTileCacheParameters *)parameters;

/** Returns a job which can be used to generate and download a tile package containing tiles specified by the parameters. The result of the job will be of type `AGSTileCache`
 @note The job is dormant and needs to be explicitly started using `AGSExportTileCacheJob#startWithStatusHandler:completion:`
 @param parameters specifying which tiles to include in the tile package
 @param downloadFileURL where the tile package should be saved on disk, including the desired file name ending with the .tpk file extension.  
 @return job representing the progress on the server. The result of the job will be of type `AGSTileCache`
 @since 100
 */
-(AGSExportTileCacheJob*)exportTileCacheJobWithParameters:(AGSExportTileCacheParameters *)parameters
                                          downloadFileURL:(NSURL *)downloadFileURL;

NS_ASSUME_NONNULL_END

@end
