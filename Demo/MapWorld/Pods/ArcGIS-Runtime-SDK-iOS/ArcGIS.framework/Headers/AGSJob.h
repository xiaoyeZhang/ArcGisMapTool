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
#import "AGSRemoteResource.h"
@class AGSJobMessage;

/** @file AGSJob.h */ //Required for Globals API doc

/** @brief A long running job on a remote server
 
 Instances of this class represent a long running job on a remote server. 
 
 A job is initiated when it is submitted to the server. When the server accepts the job, it assigns a unique ID to the job which is avialable in `#serverJobID`. The client then periodically polls for the status of the job on the server. If the job completes successfully, the result of the job is downloaded, otherwise an error is provided when the job fails.
 
 @since 100
 */
@interface AGSJob : AGSObject <AGSRemoteResource, AGSJSONSerializable, NSProgressReporting>

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

- (instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** Error encountered during job execution, if any.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) NSError *error;

/** The type of job
 @since 100
 */
@property (nonatomic, assign, readonly) AGSJobType jobType;

/** Informational messages produced during execution of the job.
 @since 100
 */
@property (nonatomic, copy, readonly) NSArray<AGSJobMessage*> *messages;

/** Unique ID of the job on the server on which it is executing.
 @since 100
 */
@property (nonatomic, copy, readonly) NSString *serverJobID;

/** Current status of the job.
 @since 100
 */
@property (nonatomic, assign, readonly) AGSJobStatus status;

/** Result of the job.
  @since 100
  */
@property (nullable, nonatomic, strong, readonly) id result;

/** The progress for this job.
 As a consumer of this progress property, you can observe it's property changes
 and pause, cancel, resume. Do not, however, set the readwrite properties of this progress object. Those are reserved for
 internal use. Setting them externally will corrupt the state and lead to undefined behavior.
 @since 100.1
 */
@property (nonatomic, strong, readonly) NSProgress *progress;

#pragma mark -
#pragma mark methods

-(void)startWithStatusHandler:(nullable void(^)(AGSJobStatus status))statusHandler
                   completion:(void(^)(id __nullable result, NSError * __nullable error))completion;

/** Pauses the job.
 Returns a value indicating whether the job was successfully paused.
 @since 100
 @deprecated 100.1. Please use the `pause` method through the NSProgress API (exposed via `%NSProgressReporting` through the `#progress` property).
*/
-(BOOL)pause __deprecated_msg("Please use the pause method through the NSProgress API (exposed via NSProgressReporting through the progress property)");

/** Cancels the job.
 Returns a value indicating whether the job was successfully canceled.
 @since 100
 @deprecated 100.1. Please use the `cancel` method through the NSProgress API (exposed via `%NSProgressReporting` through the `#progress` property).
 */
-(BOOL)cancel __deprecated_msg("Please use the cancel method through the NSProgress API (exposed via NSProgressReporting through the progress property)");

/*
 Force status check. This method can be called from `application:performFetchWithCompletionHandler:`.
 */
-(id<AGSCancelable>)checkStatusWithCompletion:(void(^)(NSError * __nullable error))completion;

NS_ASSUME_NONNULL_END

@end

