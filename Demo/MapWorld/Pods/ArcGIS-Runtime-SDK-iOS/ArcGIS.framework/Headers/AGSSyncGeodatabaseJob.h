/*
 COPYRIGHT 2016 ESRI
 
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

@class AGSSyncLayerResult;

#import "AGSJob.h"

/** @brief A job to synchronize changes between a geodatabase and an ArcGIS Feature service.
 
 Instances of this class represent a long running job on a remote server that can synchronize changes between a geodatabase and an ArcGIS Feature service.
 
 A job is initiated when it is submitted to the server. See `#startWithStatusHandler:completion:`.
 
 When the server accepts the job, it assigns a unique ID to the job which is avialable in `#serverJobID`. The client then periodically polls for the status of the job on the server and provides this information in the status handler. If the job completes successfully, the result of the job is provided in the completion handler, otherwise an error is provided when the job fails.
 
 @since 100
 @license{Basic, when sync direction is `Bidirectional` or `Upload` with public feature services or when using a private feature service with any sync direction. "Public" feature services means services hosted on the Internet and available anonymously (not secured). "Private" includes all other scenarios such as feature services hosted on a local network within an enterprise or feature services hosted on the Internet but secured}
 @ingroup licensing
 */
@interface AGSSyncGeodatabaseJob : AGSJob
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

#pragma mark -
#pragma mark properties

/** Result of the job.
@note The result only contains entries for layers or tables that encountered edit errors during the sync process. If all edits of a layer or table could be synchronized without errors, it is not included in the result array. Also, if the entire sync operation failed, for example due to network interruption, the result is nil, and the `#error` argument is populated instead.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) NSArray<AGSSyncLayerResult*> *result;

#pragma mark -
#pragma mark methods

/** Start the job by submitting it to the server
 @param statusHandler is invoked periodically whenever the job's status changes
 @param completion block that is invoked with the result when the job succeeds, or an error if it fails
 @note The `result` array only contains entries for layers or tables that encountered edit errors during the sync process. If all edits of a layer or table could be synchronized without errors, it is not included in the result array. Also, if the entire sync operation failed, for example due to network interruption, the result array is nil, and the `error` argument is populated instead.
 @since 100
 @license{Basic, when sync direction is `Bidirectional` or `Upload` with public feature services or when using a private feature service with any sync direction. "Public" feature services means services hosted on the Internet and available anonymously (not secured). "Private" includes all other scenarios such as feature services hosted on a local network within an enterprise or feature services hosted on the Internet but secured}
 */
-(void)startWithStatusHandler:(nullable void(^)(AGSJobStatus status))statusHandler
                   completion:(void(^)(NSArray<AGSSyncLayerResult*>  * __nullable result, NSError * __nullable error))completion;

NS_ASSUME_NONNULL_END
@end
