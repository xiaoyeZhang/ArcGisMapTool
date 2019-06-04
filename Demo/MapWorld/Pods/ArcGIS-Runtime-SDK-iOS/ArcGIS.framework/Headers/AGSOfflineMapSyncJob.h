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

@class AGSOfflineMapSyncResult;
@class AGSOfflineMapSyncParameters;

#import "AGSJob.h"

/** @file AGSOfflineMapSyncJob.h */ //Required for Globals API doc

/** @brief A job to sync an offline map.
 
 Instances of this class represent a long running job that can synchronize an offline map's feature layers and tables with their originating ArcGIS Feature service. This job is associated with a number of sub-jobs that sync the feaure layers and tables using `AGSSyncGeodatabaseJob`.
 
 A job is dormant when it is created. It must be explicitly started using `#startWithStatusHandler:completion:`.
 
 When the server accepts the job, it assigns a unique ID to the job which is avialable in `AGSJob#serverJobID`. The client then periodically polls for the status of the job on the server and provides this information in the status handler. If the job completes successfully, the result of the job is downloaded and provided in the completion handler, otherwise an error is provided when the job fails.
 
 @since 100.1
 @license{Basic, when sync direction is `Bidirectional` or `Upload` with public feature services or when using a private feature service with any sync direction. "Public" feature services means services hosted on the Internet and available anonymously (not secured). "Private" includes all other scenarios such as feature services hosted on a local network within an enterprise or feature services hosted on the Internet but secured}
 @ingroup licensing
*/
@interface AGSOfflineMapSyncJob : AGSJob

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

- (instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** Result of the job
 @since 100.1
 */
@property (nullable, nonatomic, strong, readonly) AGSOfflineMapSyncResult *result;

/** The parameters used to kick off this job.
 @since 100.2
 */
@property (nonatomic, strong, readonly) AGSOfflineMapSyncParameters *parameters;

#pragma mark -
#pragma mark methods

/** Start the job by submitting it to the server
 @param statusHandler is invoked periodically whenever the job's status changes
 @param completion block that is invoked with the result when the job succeeds, or an error if it fails
 @since 100.1
 @license{Basic, when sync direction is `Bidirectional` or `Upload` with public feature services or when using a private feature service with any sync direction. "Public" feature services means services hosted on the Internet and available anonymously (not secured). "Private" includes all other scenarios such as feature services hosted on a local network within an enterprise or feature services hosted on the Internet but secured}
 */
-(void)startWithStatusHandler:(nullable void(^)(AGSJobStatus status))statusHandler
                   completion:(void(^)(AGSOfflineMapSyncResult * __nullable result, NSError * __nullable error))completion;

@end

NS_ASSUME_NONNULL_END
