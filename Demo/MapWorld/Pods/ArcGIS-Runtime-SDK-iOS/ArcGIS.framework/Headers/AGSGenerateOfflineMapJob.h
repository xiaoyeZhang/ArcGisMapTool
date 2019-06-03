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

@class AGSGenerateOfflineMapResult;
@class AGSOfflineMapTask;
@class AGSMap;
@class AGSGenerateOfflineMapParameters;
@class AGSGenerateOfflineMapParameterOverrides;

#import "AGSJob.h"

/** @file AGSGenerateOfflineMapJob.h */ //Required for Globals API doc

/** @brief A job to take a map offline.
 
 Instances of this class represent a long running job that can take an entire map offline. This job is associated with a number of sub-jobs that take the map's layers and tables offline. Feature layers and tables are taken offline using `AGSGenerateGeodatabaseJob`, Tile layers are taken offline using `AGSExportTileCacheJob`.
 
 A job is dormant when it is created. It must be explicitly started using `#startWithStatusHandler:completion:`.
 
 When the server accepts the job, it assigns a unique ID to the job which is avialable in `AGSJob#serverJobID`. The client then periodically polls for the status of the job on the server and provides this information in the status handler. If the job completes successfully, the result of the job is downloaded and provided in the completion handler, otherwise an error is provided when the job fails.
 
 @since 100.1
 */
@interface AGSGenerateOfflineMapJob : AGSJob

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** Directory where the offline map should be saved on disk.
 @since 100.1
 */
@property (nullable, nonatomic, strong, readonly) NSURL *downloadDirectory;

/** Result of the job.
 @since 100.1
 */
@property (nullable, nonatomic, strong, readonly) AGSGenerateOfflineMapResult *result;

/** The map which is to be taken offline.
 @since 100.1
 */
@property (nullable, nonatomic, strong, readonly) AGSMap *onlineMap;

/** The parameters specifying how to take the map offline.
 @since 100.1
 */
@property (nullable, nonatomic, strong, readonly) AGSGenerateOfflineMapParameters *parameters;

/** Overrides used for the parameters. If present, this takes precedence over `#parameters`.
 @since 100.4
 */
@property (nullable, nonatomic, strong, readonly) AGSGenerateOfflineMapParameterOverrides *parameterOverrides;

#pragma mark -
#pragma mark methods

/** Start the job by submitting it to the server
 @param statusHandler is invoked periodically whenever the job's status changes
 @param completion block that is invoked with the result when the job succeeds, or an error if it fails
 @since 100.1
 */
-(void)startWithStatusHandler:(nullable void(^)(AGSJobStatus status))statusHandler
                   completion:(void(^)(AGSGenerateOfflineMapResult * __nullable result, NSError * __nullable error))completion;
@end

NS_ASSUME_NONNULL_END


