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

@class AGSDownloadPreplannedOfflineMapResult;
@class AGSOfflineMapTask;
@class AGSMap;
@class AGSPreplannedMapArea;
@class AGSDownloadPreplannedOfflineMapParameters;

/** @file AGSDownloadPreplannedOfflineMapJob.h */ //Required for Globals API doc

/** @brief A job to download a map's preplanned area.
 
 Instances of this class represent a long running job that can take an entire map offline based on its preplanned map area. This job is associated with a number of sub-jobs that take the map's layers and tables offline.
 
 A job is dormant when it is created. It must be explicitly started using `#startWithStatusHandler:completion:`.
 
 When the server accepts the job, it assigns a unique ID to the job which is avialable in `AGSJob#serverJobID`. The client then periodically polls for the status of the job on the server and provides this information in the status handler. If the job completes successfully, the result of the job is downloaded and provided in the completion handler, otherwise an error is provided when the job fails.
 
 @since 100.2
 */
@interface AGSDownloadPreplannedOfflineMapJob : AGSJob

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** Directory to download the offline map to
 @since 100.2
 */
@property (nullable, nonatomic, strong, readonly) NSURL *downloadDirectory;

/** Indicates whether or not to exclude the basemap in the offline map. Excluding the basemap will override the authored settings of preplanned map area and always exclude the basemap content.
 @since 100.2
 */
@property (nonatomic, assign, readonly) BOOL excludeBasemap;

/** The map which is to be taken offline.
 @since 100.2
 */
@property (nonatomic, strong, readonly) AGSMap *onlineMap;

/** The preplanned map parameters used to create this job.
 @since 100.4
 */
@property (nullable, nonatomic, strong, readonly) AGSDownloadPreplannedOfflineMapParameters *parameters;

/** The preplanned map area for the `#onlineMap` which is to be downloaded
 @since 100.2
 */
@property (nonatomic, strong, readonly) AGSPreplannedMapArea *preplannedMapArea;

/** Result of the job
 @since 100.2
 */
@property (nullable, nonatomic, strong, readonly) AGSDownloadPreplannedOfflineMapResult *result;

#pragma mark -
#pragma mark methods

/** Start the job by submitting it to the server
 @param statusHandler is invoked periodically whenever the job's status changes
 @param completion block that is invoked with the result when the job succeeds, or an error if it fails
 @since 100.2
 */
-(void)startWithStatusHandler:(nullable void(^)(AGSJobStatus status))statusHandler
                   completion:(void(^)(AGSDownloadPreplannedOfflineMapResult * __nullable result, NSError * __nullable error))completion;

NS_ASSUME_NONNULL_END

@end
