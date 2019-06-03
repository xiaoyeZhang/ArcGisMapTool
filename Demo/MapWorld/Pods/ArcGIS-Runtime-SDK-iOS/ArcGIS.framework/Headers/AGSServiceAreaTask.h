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

#import "AGSObject.h"
#import "AGSLoadableRemoteResourceBase.h"

@class AGSTransportationNetworkDataset;
@class AGSServiceAreaTaskInfo;
@class AGSServiceAreaParameters;
@class AGSTask;
@class AGSServiceAreaResult;

/** @file AGSServiceAreaTask.h */ //Required for Globals API doc

/** @brief A task to calculate service areas
 
 Instances of this class represent tasks that can calculate service areas. Service areas show which roads can be reached within a given distance or travel time. A service area can help you answer the following types of questions:
 
 @li How far can I drive from here in 5 minutes?
 @li What areas are covered within a 3-mile drive distance of my stores?
 @li What areas are within 4 minutes of our hospitals?
 
 Creating a service area is like buffering a point. However, when you buffer a point, you specify a straight-line distance, and a circle is created to show the area that is within that distance. In contrast, when you create a service area around a point, it represents the maximum distance that can be traveled along a network, such as a road network. The result is a service area covering the roads that can be reached within the distance you specified.
 
 
 The task can be created for an ArcGIS Network Analyst service hosted in the cloud on ArcGIS Online or on-premises with ArcGIS Server.
 
 @since 100.1
 @licenseExtn{Analysis, when using a network dataset in a local mobile geodatabase}
 @ingroup licensing
 */
@interface AGSServiceAreaTask : AGSLoadableRemoteResourceBase

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

/** Initialize the task with a URL to a service area layer in an ArcGIS Network Analyst service. The service may be hosted in the cloud on ArcGIS Online or on-premises with ArcGIS Server.
 @param URL to a service area layer in an ArcGIS Network Analyst service. For example, http://sampleserver3.arcgisonline.com/ArcGIS/rest/services/Network/USA/NAServer/Service%20Area
 @return a new service area task
 @since 100.1
 */
-(instancetype)initWithURL:(NSURL *)URL;

/** Initialize the task with a URL to a service area layer in an ArcGIS Network Analyst service. The service may be hosted in the cloud on ArcGIS Online or on-premises with ArcGIS Server.
 @param URL to a service area layer in an ArcGIS Network Analyst service. For example, http://sampleserver3.arcgisonline.com/ArcGIS/rest/services/Network/USA/NAServer/Service%20Area
 @return a new service area task
 @since 100.1
 */
+(instancetype)serviceAreaTaskWithURL:(NSURL *)URL;

/** Initialize the task with a reference to the transportation network dataset available for a map.
 @param dataset transportation network dataset to use
 @return a new service area task
 @since 100.2
 @see `AGSMap#transportationNetworks` to get a reference to the transportation network datasets available for a map.
 @licenseExtn{Analysis}
 @ingroup licensing
 */
-(instancetype)initWithDataset:(AGSTransportationNetworkDataset *)dataset;

/** Initialize the task with a reference to the transportation network dataset available for a map.
 @param dataset transportation network dataset to use
 @return a new service area task
 @since 100.2
 @see `AGSMap#transportationNetworks` to get a reference to the transportation network datasets available for a map.
 @licenseExtn{Analysis}
 @ingroup licensing
 */
+(instancetype)serviceAreaTaskWithDataset:(AGSTransportationNetworkDataset *)dataset;

/** Initialize the task with the name of a geodatabase containing a transportation network dataset, and the name of the dataset.
 @param databaseName name of the geodatabase file (within the application bundle or shared documents directory) without the .geodatabase file extension
 @param networkName name of the transportation network dataset within the geodatabase
 @return a new service area task
 @since 100.2
 @licenseExtn{Analysis}
 @ingroup licensing
 */
-(instancetype)initWithDatabaseName:(NSString*)databaseName networkName:(NSString*)networkName;

/** Initialize the task with the name of a geodatabase containing a transportation network dataset, and the name of the dataset.
 @param databaseName name of the geodatabase file (within the application bundle or shared documents directory) without the .geodatabase file extension
 @param networkName name of the transportation network dataset within the geodatabase
 @return a new service area task
 @since 100.2
 @licenseExtn{Analysis}
 @ingroup licensing
*/
+(instancetype)serviceAreaTaskWithDatabaseName:(NSString*)databaseName networkName:(NSString*)networkName;


/** Initialize the task with a path to the geodatabase containing a transportation network dataset, and the name of the transportation network dataset.
 @param fileURLToDatabase URL to the .geodatabase file on disk
 @param networkName name of the transportation network dataset within the geodatabase
 @return a new service area task
 @since 100.2
 @licenseExtn{Analysis}
 @ingroup licensing
 */
-(instancetype)initWithFileURLToDatabase:(NSURL *)fileURLToDatabase networkName:(NSString *)networkName;

/** Initialize the task with a path to the geodatabase containing a transportation network dataset, and the name of the transportation network dataset.
 @param fileURLToDatabase URL to the .geodatabase file on disk
 @param networkName name of the transportation network dataset within the geodatabase
 @return a new service area task
 @since 100.2
 @licenseExtn{Analysis}
 @ingroup licensing
 */
+(instancetype)serviceAreaTaskWithFileURLToDatabase:(NSURL *)fileURLToDatabase networkName:(NSString *)networkName;

#pragma mark -
#pragma mark properties

/**
 Metadata about the ArcGIS Network Analyst service or transportation network dataset being used by the task
 @since 100.1
 */
@property (nullable, nonatomic, strong, readonly) AGSServiceAreaTaskInfo *serviceAreaTaskInfo;

/** The transportation network dataset being used by this task
 Will be nil if the task is using a service instead of a local geodatabase.
 @since 100.2
 */
@property (nullable, nonatomic, strong, readonly) AGSTransportationNetworkDataset *transportationNetworkDataset;

#pragma mark -
#pragma mark methods

/**  A convenience method to get properly initialized parameters for calculating service areas. The parameters are initialized with default values based on the `#serviceAreaTaskInfo`
 @param completion block that is invoked when the operation completes. The service area parameters are populated if the operation succeeds, else the error is populated if the operation fails.
 @since 100.1
 */
-(id<AGSCancelable>)defaultServiceAreaParametersWithCompletion:(void(^)(AGSServiceAreaParameters * __nullable serviceAreaParams, NSError * __nullable error))completion;

/** Calculates service areas based on the provided parameters
 @param serviceAreaParameters based on which service areas should be calculated
 @param completion block that is invoked when the operation completes. The result is populated if the operation succeeds, else the error is populated if the operation fails.
 @since 100.1
 */
-(id<AGSCancelable>)solveServiceAreaWithParameters:(AGSServiceAreaParameters*)serviceAreaParameters completion:(void(^)(AGSServiceAreaResult * __nullable serviceAreaResult, NSError * __nullable error))completion;

NS_ASSUME_NONNULL_END

@end

