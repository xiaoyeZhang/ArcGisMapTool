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

#import "AGSJob.h"

@class AGSGeoprocessingResult;
@class AGSGeoprocessingParameters;

/** @file AGSGeoprocessingJob.h */ //Required for Globals API doc

/** @brief A job to execute tasks on an ArcGIS Geoprocessing service.
 
 Instances of this class represent a job on a remote server that executes the workflow defined by an ArcGIS Geoprocessing service. A job is initiated when it is submitted to the server using `AGSJob#startWithStatusHandler:completion:`.
 
 When the server accepts the job, it assigns a unique ID to the job which is avialable in `AGSJob#serverJobID`. The client then periodically polls for the status of the job on the server and provides this information in the status handler. If the job completes successfully, the result of the job is provided in the completion handler, otherwise an error is provided when the job fails.
 
 @since 100
 */
@interface AGSGeoprocessingJob : AGSJob

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** The parameters that were passed to this job when it was created using `AGSGeoprocessingTask#geoprocessingJobWithParameters:`
 @since 100.1
 */
@property (nullable, nonatomic, strong, readonly) AGSGeoprocessingParameters *parameters;

/** Result of the job.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSGeoprocessingResult *result;

#pragma mark -
#pragma mark methods

/** Start the job by submitting it to the server
 @param statusHandler is invoked periodically whenever the job's status changes
 @param completion block that is invoked with the result when the job succeeds, or an error if it fails
 @since 100
 */
-(void)startWithStatusHandler:(nullable void(^)(AGSJobStatus status))statusHandler
                   completion:(void(^)(AGSGeoprocessingResult * __nullable result, NSError * __nullable error))completion;

NS_ASSUME_NONNULL_END
@end
