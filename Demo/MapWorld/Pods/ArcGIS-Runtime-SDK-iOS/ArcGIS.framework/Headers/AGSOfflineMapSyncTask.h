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

@class AGSMap;
@class AGSOfflineMapSyncJob;
@class AGSOfflineMapSyncParameters;

#import "AGSLoadableBase.h"

/** @file AGSOfflineMapSyncTask.h */ //Required for Globals API doc

/** @brief A task to sync an offline map
 
 Instances of this class represent a task that can be used to synchronize changes between feature layers and tables of an offline map and their originating ArcGIS Feature services.
 
 @see `AGSOfflineMapTask` to take a map offline
 @since 100.1
 */
@interface AGSOfflineMapSyncTask : AGSLoadableBase

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

- (instancetype)init __attribute__((unavailable("init is not available.")));

/** Initialize this task with the provided offline map.
 @param map Offline map whose feature layers and tables need to be synced
 @return initialized task
 @since 100.1
 */
-(instancetype)initWithMap:(AGSMap*)map;

/** Initialize this task with the provided offline map.
 @param map Offline map whose feature layers and tables need to be synced
 @return initialized task
 @since 100.1
 */
+(instancetype)offlineMapSyncTaskWithMap:(AGSMap*)map;

#pragma mark -
#pragma mark properties

/** Offline map whose feature layers and tables need to be synced with their originating service.
 @since 100.1
 */
@property (nonatomic, strong, readonly) AGSMap *map;

#pragma mark -
#pragma mark methods

/** Returns a job which can be used to synchronize the offline map. The result of the job will be an `AGSOfflineMapSyncResult` object.
 @note The job is dormant and needs to be explicitly started using `AGSOfflineMapSyncJob#startWithStatusHandler:completion:`
 @param parameters specifying how the map's feature layers and tables should be synced with the service
 @return job representing the progress on the server. The result of the job will be an `AGSOfflineMapSyncResult` object
 @since 100.1
 @license{Basic, when sync direction is `Bidirectional` or `Upload` with public feature services or when using a private feature service with any sync direction. "Public" feature services means services hosted on the Internet and available anonymously (not secured). "Private" includes all other scenarios such as feature services hosted on a local network within an enterprise or feature services hosted on the Internet but secured}
 @ingroup licensing
 */
-(AGSOfflineMapSyncJob *)offlineMapSyncJobWithParameters:(AGSOfflineMapSyncParameters *)parameters;

@end

NS_ASSUME_NONNULL_END
