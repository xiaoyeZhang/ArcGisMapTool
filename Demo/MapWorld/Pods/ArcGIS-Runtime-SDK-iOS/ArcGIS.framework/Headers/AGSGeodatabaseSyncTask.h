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

@class AGSArcGISFeatureServiceInfo;
@class AGSGenerateGeodatabaseJob;
@class AGSSyncGeodatabaseJob;
@class AGSGenerateGeodatabaseParameters;
@class AGSSyncGeodatabaseParameters;
@class AGSGeodatabase;
@class AGSSyncLayerResult;

#import "AGSLoadableRemoteResourceBase.h"

/** @file AGSGeodatabaseSyncTask.h */ //Required for Globals API doc

/** @brief A task to download and synchronize a sync-enabled geodatabase
 
 Instances of this class represent a task that can be used to create, download, and synchronize a sync-enabled geodatabase from a sync-enabled ArcGIS Feature service. The service could be hosted in the cloud on ArcGIS Online or on-premises with ArcGIS servers.
 
 Geodatabases generated from an ArcGIS feature service can be used for querying and viewing feature data when the application is offline. Geodatabases can also be edited when offline. Geodatabases for editing can only be requested if the service supports synchronization.
 
 Geodatabases can be synchronized with the service when the application is able to connect to a network again. Synchronization can perform two tasks:
 
 - upload to the service changes made while offline
 - download changes made on the service to the geodatabase
 
 @since 100
 @see `AGSGeodatabase`
 */
@interface AGSGeodatabaseSyncTask : AGSLoadableRemoteResourceBase
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

/** Initialize the task with a URL to a sync-enabled ArcGIS Feature service
 @param URL to a sync-enabled ArcGIS Feature service
 @return initialized task
 @since 100
 */
-(instancetype)initWithURL:(NSURL *)URL;

/** Initialize the task with a URL to a sync-enabled ArcGIS Feature service
 @param URL to a sync-enabled ArcGIS Feature service
 @return initialized task
 @since 100
 */
+(instancetype)geodatabaseSyncTaskWithURL:(NSURL *)URL;

#pragma mark -
#pragma mark properties

/** Metadata about the ArcGIS Feature service that the task is using
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSArcGISFeatureServiceInfo *featureServiceInfo;

#pragma mark -
#pragma mark methods

/** A convenience method to get properly initialized parameters for generating a geodatabase.
 
 This will populate the parameters with values matching what the service supports. For example if the service does not support `PER_LAYER` sync  model then `PER_GEODATABASE` will be used. All layers from the service will be included. The extent will be the service's full extent. Attachments are included by default, but related tables/layers are not included.
 
 @param completion block that is invoked with the initialized params if the method succeeds, or an error if it fails
 @return operation that can be canceled
 @since 100
 */
-(id<AGSCancelable>)defaultGenerateGeodatabaseParametersWithExtent:(AGSGeometry*)extent
                                                         completion:(nullable void(^)(AGSGenerateGeodatabaseParameters * __nullable params, NSError * __nullable error))completion;


/**  A convenience method to get properly initialized parameters for synchronizing a geodatabase with its service.
 
 This will populate the parameters with values matching what the service and the geodatabase support. For a geodatabase with `PER_LAYER` sync model, all geodatabase layers will be included. If the service is read-only then the sync direction will be `DOWNLOAD`. Otherwise the sync direction will be `BIDIRECTIONAL`.
 
 @param geodatabase that needs to be synchronized with its service
 @param completion block that is invoked with the initialized params if the method succeeds, or an error if it fails
 @return operation that can be canceled
 @since 100
 */
-(id<AGSCancelable>)defaultSyncGeodatabaseParametersWithGeodatabase:(AGSGeodatabase*)geodatabase
                                                          completion:(nullable void(^)(AGSSyncGeodatabaseParameters * __nullable params, NSError * __nullable error))completion;

/**  A convenience method to get properly initialized parameters for synchronizing a geodatabase with its service.
 Returns a parameters object with the given sync direction. Other parameters are populated with default values.
 @param geodatabase that needs to be synchronized with its service
 @param syncDirection the sync direction to use
 @param completion block that is invoked with the initialized params if the method succeeds, or an error if it fails
 @return operation that can be canceled
 @since 100.3
 */
-(id<AGSCancelable>)defaultSyncGeodatabaseParametersWithGeodatabase:(AGSGeodatabase*)geodatabase
                                                      syncDirection:(AGSSyncDirection)syncDirection
                                                         completion:(nullable void(^)(AGSSyncGeodatabaseParameters * __nullable params, NSError * __nullable error))completion;

/** Import changes from a delta file (*.gdb file) into the geodatabase. This is useful in workflows where the client does not directly connect to the originating service to synchronize changes with the server (either because the client does not have access to the service, or to improve scalability where it is impractical for a large number of clients to depend upon the service). Rather, the changes from the sync-enabled service are made available as a delta file (*.gdb file) to all clients which then import them into their copy of the geodatabase.
 @param geodatabase into which to import the delta
 @param inputPath of the delta file (*.gdb file) containing the changes from the sync-enabled feature service.
 @param completion block that is invoked when the operation completes successfully or encounters an error
 @since 100
 @deprecated 100.3. Use class method `#importDeltaWithGeodatabase:inputPath:completion:` instead.
 */
-(id<AGSCancelable>)importDeltaWithGeodatabase:(AGSGeodatabase*)geodatabase inputPath:(NSString*)inputPath completion:(void(^)(NSArray<AGSSyncLayerResult*>  * __nullable result, NSError * __nullable error))completion;

/** Import changes from a delta file (*.gdb file) into the geodatabase. This is useful in workflows where the client does not directly connect to the originating service to synchronize changes with the server (either because the client does not have access to the service, or to improve scalability where it is impractical for a large number of clients to depend upon the service). Rather, the changes from the sync-enabled service are made available as a delta file (*.gdb file) to all clients which then import them into their copy of the geodatabase.
 @param geodatabase into which to import the delta
 @param deltaPath of the delta file (*.gdb file) containing the changes from the sync-enabled feature service.
 @param completion block that is invoked when the operation completes successfully or encounters an error
 @since 100.3
 */
+(id<AGSCancelable>)importDeltaWithGeodatabase:(AGSGeodatabase*)geodatabase deltaPath:(NSURL *)deltaPath completion:(void(^)(NSArray<AGSSyncLayerResult*>  * __nullable result, NSError * __nullable error))completion;


/** Register an existing sync-enabled geodatabase as a new sync-enabled geodatabase with the originating service. The geodatabase can then sync changes with the service indepedently of any other copies of the geodatabase that may exist.
 @param geodatabase The sync-enabled geodatabase to register as a new replica with the originating service.
 @param completion block that is invoked when the operation completes successfully or encounters an error
 @return operation that can be canceled
 @since 100
 */
-(id<AGSCancelable>)registerSyncEnabledGeodatabase:(AGSGeodatabase*)geodatabase completion:(nullable void(^)(NSError * __nullable error))completion;

/** Returns a job which can be used to generate a geodatabase from an ArcGIS Feature service using the specified parameters. The result of the job will be of type `AGSGeodatabase`.
 @note The job is dormant and needs to be explicitly started using `AGSGenerateGeodatabaseJob#startWithStatusHandler:completion:`
 @param parameters specifying what data to include in the generated geodatabase
 @param downloadFileURL where the geodatabase should be saved on disk, including the desired file name ending with the .geodatabase file extension.
 @return job representing the progress on the server. The result of the job will be of type `AGSGeodatabase`.
 @since 100
 */
-(AGSGenerateGeodatabaseJob*)generateJobWithParameters:(AGSGenerateGeodatabaseParameters *)parameters
                                       downloadFileURL:(NSURL *)downloadFileURL;

/** Returns a job which can be used to synchronize a geodatabase with its originating ArcGIS Feature service using the specified parameters. The result of the job will be a list of `AGSSyncLayerResult` objects.
 @note The job is dormant and needs to be explicitly started using `AGSSyncGeodatabaseJob#startWithStatusHandler:completion:`
 @param parameters specifying how data should be synchronized with the service
 @param geodatabase whose data needs to be synchronized
 @return job representing the progress on the server. The result of the job will be a list of `AGSSyncLayerResult` objects
 @license{Basic, when sync direction is `Bidirectional` or `Upload` with public feature services or when using a private feature service with any sync direction. "Public" feature services means services hosted on the Internet and available anonymously (not secured). "Private" includes all other scenarios such as feature services hosted on a local network within an enterprise or feature services hosted on the Internet but secured}
 @ingroup licensing
 @since 100
 */
-(AGSSyncGeodatabaseJob*)syncJobWithParameters:(AGSSyncGeodatabaseParameters *)parameters
                                   geodatabase:(AGSGeodatabase *)geodatabase;

/** Returns a job which can be used to synchronize a geodatabase with its originating ArcGIS Feature service using the specified options. The result of the job will be a list of `AGSSyncLayerResult` objects.
     
 This method provides convenience over `#syncJobWithParameters:geodatabase` by not requiring a parameters object to be first created, and also by correctly applying the `syncDirection` to either the geodatabase as a whole or individually to each layer inside the geodatabase depending upon which sync model is used by the geodatabase. If the given sync direction is not compatible with the sync task's feature service, the returned job will fail.
 @note The job is dormant and needs to be explicitly started using `AGSSyncGeodatabaseJob#startWithStatusHandler:completion:`
 @param syncDirection to be used
 @param rollbackOnFailure whether or not edits are rolled back if sync fails
 @param geodatabase whose data needs to be synchronized
 @return job representing the progress on the server. The result of the job will be a list of `AGSSyncLayerResult` objects
 @license{Basic, when sync direction is `Bidirectional` or `Upload` with public feature services or when using a private feature service with any sync direction. "Public" feature services means services hosted on the Internet and available anonymously (not secured). "Private" includes all other scenarios such as feature services hosted on a local network within an enterprise or feature services hosted on the Internet but secured}
 @ingroup licensing
 @since 100.3
 */
-(AGSSyncGeodatabaseJob*)syncJobWithSyncDirection:(AGSSyncDirection)syncDirection
                                rollbackOnFailure:(BOOL)rollbackOnFailure
                                      geodatabase:(AGSGeodatabase *)geodatabase;

/** Unregister an existing sync-enabled geodatabase from its originating service. This removes the geodatabase's replica ID from the service which means it can no longer be synchronized. The local geodatabase will be left behind, but all information about the geodatabase on the service will be removed.
 @note Once a sync-enabled geodatabase is unregistered, it cannot be re-registered with the service.
 @param geodatabase to unregister
 @param completion block that is invoked when the operation completes successfully or encounters an error
 @return operation that can be canceled
 @since 100
 */
-(id<AGSCancelable>)unregisterGeodatabase:(AGSGeodatabase *)geodatabase completion:(nullable void(^)(NSError * __nullable error))completion;


/** Unregister an existing sync-enabled geodatabase from its originating service. This removes the geodatabase's replica ID from the service which means it can no longer be synchronized. This overload uses the geodatabase's sync ID rather than a reference to the geodatabase itself which is commonly used to enable cleanup of the service after the local geodatabase has already been deleted.
 @note Once a sync-enabled geodatabase is unregistered, it cannot be re-registered with the service.
 @param syncID of the geodatabase to unregister
 @param completion block that is invoked when the operation completes successfully or encounters an error
 @return operation that can be canceled
 @since 100.2
 */
-(id<AGSCancelable>)unregisterGeodatabaseWithSyncID:(NSUUID*)syncID completion:(nullable void(^)(NSError * __nullable error))completion;

NS_ASSUME_NONNULL_END
@end




