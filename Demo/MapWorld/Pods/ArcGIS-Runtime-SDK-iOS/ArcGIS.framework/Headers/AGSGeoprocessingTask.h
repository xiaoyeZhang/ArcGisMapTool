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

#import "AGSLoadableRemoteResourceBase.h"
#import "AGSLoadableBase.h"

@class AGSGeoprocessingJob;
@class AGSGeoprocessingParameters;
@class AGSGeoprocessingTaskInfo;

/** @file AGSGeoprocessingTask.h */ //Required for Globals API doc

/** @brief A task to perform Geoprocessing
 
 Instances of this class represent a Geoprocessing Task that is used to invoke tasks on a remote ArcGIS Geoprocessing Service. Geoprocessing Services host one or more tasks that allow you to automate your GIS workflows such as spatial analysis and data management.
 
 @since 100
 */
@interface AGSGeoprocessingTask : AGSLoadableBase
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

/** Initialize a geoprocessing task with a URL to a task on a remote ArcGIS Geoprocessing service.
 @param URL to a task on a remote ArcGIS Geoprocessing service. For example, http://sampleserver2.arcgisonline.com/ArcGIS/rest/services/Elevation/ESRI_Elevation_World/GPServer/ProfileService
 @return intialized geoprocessing task
 @since 100
 */
-(instancetype)initWithURL:(NSURL*)URL;

/** Initialize a geoprocessing task with a URL to a task on a remote ArcGIS Geoprocessing service.
 @param URL to a task on a remote ArcGIS Geoprocessing service. For example, http://sampleserver2.arcgisonline.com/ArcGIS/rest/services/Elevation/ESRI_Elevation_World/GPServer/ProfileService
 @return intialized geoprocessing task
 @since 100
 */
+(instancetype)geoprocessingTaskWithURL:(NSURL*)URL;

#pragma mark -
#pragma mark properties

/** Metadata about the geoprocessing task and the inputs that the service expects.
 @since 100.1
 */
@property (nullable, nonatomic, strong, readonly) AGSGeoprocessingTaskInfo *geoprocessingTaskInfo;

#pragma mark -
#pragma mark methods

-(id<AGSCancelable>)defaultGeoprocessingParametersWithCompletion:(void(^)(AGSGeoprocessingParameters * __nullable geoprocessingParams, NSError * __nullable error))completion;

/** Returns a job which can be used to execute geoprocessing tasks
 The result of the job will be of type `AGSGeoprocessingResult`.
 @note The job is dormant and needs to be explicitly started using `AGSGeoprocessingJob#startWithStatusHandler:completion:`
 @param parameters specifying inputs for the geoprocessing job
 @return job representing the progress on the server. The result of the job will be of type `AGSGeoprocessingResult`
 @since 100
 */
-(AGSGeoprocessingJob*)geoprocessingJobWithParameters:(AGSGeoprocessingParameters*)parameters;

NS_ASSUME_NONNULL_END
@end
