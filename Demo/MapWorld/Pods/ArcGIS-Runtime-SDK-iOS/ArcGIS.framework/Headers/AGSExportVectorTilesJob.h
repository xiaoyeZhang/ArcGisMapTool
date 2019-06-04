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

#import "AGSJob.h"

@class AGSExportVectorTilesParameters;
@class AGSExportVectorTilesResult;

/** @file AGSExportVectorTilesJob.h */ //Required for Globals API doc

/** @brief A job to export a tile cache or item resource cache from an ArcGIS Vector Tile service.
 
 Instances of this class represent a long running job on a remote server that can export a tile cache from an ArcGIS Vector Tile service. The job can also export an item resource cache containing custom style resources from a portal item that represents an ArcGIS Vector Tile service.
 
 A job is initiated when it is submitted to the server. See `#startWithStatusHandler:completion:`.
 
 When the server accepts the job, it assigns a unique ID to the job which is avialable in `AGSJob#serverJobID`. The client then periodically polls for the status of the job on the server and provides this information in the status handler. If the job completes successfully, the result of the job is downloaded and provided in the completion handler, otherwise an error is provided when the job fails.
 
 @since 100.2
 */
@interface AGSExportVectorTilesJob : AGSJob

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties


/** Directory where the custom style resources should be saved.
 @since 100.2
 */
@property (nullable, nonatomic, strong, readonly) NSURL *itemResourceCacheDownloadDirectory;

/** Parameters specifying the tiles to export.
 @since 100
 */
@property (nonatomic, strong, readonly) AGSExportVectorTilesParameters *parameters;

/** Result of the job.
 @since 100.2
 */
@property (nullable, nonatomic, strong, readonly) AGSExportVectorTilesResult *result;

/** Location where the tile package should be saved on disk, including the desired file name ending with the .vtpk file extension.
 @since 100.2
 */
@property (nullable, nonatomic, strong, readonly) NSURL *vectorTileCacheDownloadFileURL;

#pragma mark -
#pragma mark methods

/** Start the job by submitting it to the server.
 @param statusHandler is invoked periodically whenever the job's status changes
 @param completion block that is invoked with the result when the job succeeds, or an error if it fails
 @since 100.2
 */
-(void)startWithStatusHandler:(nullable void(^)(AGSJobStatus status))statusHandler
                   completion:(void(^)(AGSExportVectorTilesResult * __nullable result, NSError * __nullable error))completion;

NS_ASSUME_NONNULL_END

@end
