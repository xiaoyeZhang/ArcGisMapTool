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

@class AGSTransportationNetworkDataset;
@class AGSClosestFacilityTaskInfo;
@class AGSClosestFacilityParameters;
@class AGSClosestFacilityResult;

#import "AGSLoadableRemoteResourceBase.h"

/** @file AGSClosestFacilityTask.h */ //Required for Globals API doc

/** @brief A task to find facilities closest to an incident
 
 Instances of this class represent tasks that can find the closest facilities around any location (incidents) on a network. Finding the closest hospital to an accident, the closest police cars to a crime scene, and the closest store to a customer's address are all examples of closest facility problems. When finding closest facilities, you can specify how many to find and whether the direction of travel is toward or away from them. Once you've found the closest facilities, you can display the best route to or from them, return the travel cost for each route, and display directions to each facility. Additionally, you can specify an impedance cutoff beyond which the task should not search for a facility. For instance, you can set up a closest facility problem to search for hospitals within 15 minutes drive time of the site of an accident. Any hospitals that take longer than 15 minutes to reach will not be included in the results.
 
 The task can be created for an ArcGIS Network Analyst service hosted in the cloud on ArcGIS Online or on-premises with ArcGIS Server. 
 
 @since 100.1
 @licenseExtn{Analysis, when using a network dataset in a local mobile geodatabase}
 @ingroup licensing
 */
 @interface AGSClosestFacilityTask : AGSLoadableRemoteResourceBase
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

/** Initialize the task with a URL to a closest facility layer in an ArcGIS Network Analyst service. The service may be hosted in the cloud on ArcGIS Online or on-premises with ArcGIS Server.
 @param URL to a closest facility layer in an ArcGIS Network Analyst service. For example, http://sampleserver3.arcgisonline.com/ArcGIS/rest/services/Network/USA/NAServer/Closest%20Facility
 @return a new closest facility task
 @since 100.1
 */
-(instancetype)initWithURL:(NSURL*)URL;

/** Initialize the task with a reference to the transportation network dataset available for a map.
 @param dataset transportation network dataset to use
 @return a new closest facility task
 @since 100.2
 @see `AGSMap#transportationNetworks` to get a reference to the transportation network datasets available for a map.
 @licenseExtn{Analysis}
 @ingroup licensing
 */
-(instancetype)initWithDataset:(AGSTransportationNetworkDataset*)dataset;

/** Initialize the task with a path to the geodatabase containing a transportation network dataset, and the name of the transportation network dataset.
 @param fileURLToDatabase URL to the .geodatabase file on disk
 @param networkName name of the transportation network dataset within the geodatabase
 @return a new closest facility task
 @since 100.2
 @licenseExtn{Analysis}
 @ingroup licensing
 */
-(instancetype)initWithFileURLToDatabase:(NSURL*)fileURLToDatabase networkName:(NSString*)networkName;

/** Initialize the task with the name of a geodatabase containing a transportation network dataset, and the name of the dataset.
 @param databaseName name of the geodatabase file (within the application bundle or shared documents directory) without the .geodatabase file extension
 @param networkName name of the transportation network dataset within the geodatabase
 @return a new closest facility task
 @since 100.2
 @licenseExtn{Analysis}
 @ingroup licensing
 */
-(instancetype)initWithDatabaseName:(NSString*)databaseName networkName:(NSString*)networkName;


/** Initialize the task with a URL to a closest facility layer in an ArcGIS Network Analyst service. The service may be hosted in the cloud on ArcGIS Online or on-premises with ArcGIS Server.
 @param URL to a closest facility layer in an ArcGIS Network Analyst service. For example, http://sampleserver3.arcgisonline.com/ArcGIS/rest/services/Network/USA/NAServer//Closest%20Facility
 @return a new closest facility task
 @since 100.1
 */
+(instancetype)closestFacilityTaskWithURL:(NSURL*)URL;

/** Initialize the task with a reference to the transportation network dataset available for a map.
 @param dataset transportation network dataset to use
 @return a new closest facility task
 @since 100.2
 @see `AGSMap#transportationNetworks` to get a reference to the transportation network datasets available for a map.
 @licenseExtn{Analysis}
 @ingroup licensing
 */
+(instancetype)closestFacilityTaskWithDataset:(AGSTransportationNetworkDataset*)dataset;

/** Initialize the task with a path to the geodatabase containing a transportation network dataset, and the name of the transportation network dataset.
 @param fileURLToDatabase URL to the .geodatabase file on disk
 @param networkName name of the transportation network dataset within the geodatabase
 @return a new closest facility task
 @since 100.2
 @licenseExtn{Analysis}
 @ingroup licensing
 */
+(instancetype)closestFacilityTaskWithFileURLToDatabase:(NSURL*)fileURLToDatabase networkName:(NSString*)networkName;

/** Initialize the task with the name of a geodatabase containing a transportation network dataset, and the name of the dataset.
 @param databaseName name of the geodatabase file (within the application bundle or shared documents directory) without the .geodatabase file extension
 @param networkName name of the transportation network dataset within the geodatabase
 @return a new closest facility task
 @since 100.2
 @licenseExtn{Analysis}
 @ingroup licensing
 */
+(instancetype)closestFacilityTaskWithDatabaseName:(NSString*)databaseName networkName:(NSString*)networkName;

#pragma mark -
#pragma mark properties

/**
 Metadata about the ArcGIS Network Analyst service or transportation network dataset being used by the task
 @since 100.1
 */
@property (nullable, nonatomic, strong, readonly) AGSClosestFacilityTaskInfo *closestFacilityTaskInfo;

/** The transportation network dataset being used by this task
 Will be nil if the task is using a service instead of a local geodatabase.
 @since 100.2
 */
@property (nullable, nonatomic, strong, readonly) AGSTransportationNetworkDataset *transportationNetworkDataset;

#pragma mark -
#pragma mark methods

/**  A convenience method to get properly initialized parameters for finding closest facilities. The parameters are initialized with default values based on the `#closestFacilityTaskInfo`
 @param completion block that is invoked when the operation completes. The closest facility parameters are populated if the operation succeeds, else the error is populated if the operation fails.
 @since 100.1
 */
-(id<AGSCancelable>)defaultClosestFacilityParametersWithCompletion:(void(^)(AGSClosestFacilityParameters * __nullable closestFacilityParameters, NSError * __nullable error))completion;

/** Finds closest facilities based on the provided parameters
 @param closestFacilityParameters based on which closest facilities should be found
 @param completion block that is invoked when the operation completes. The result is populated if the operation succeeds, else the error is populated if the operation fails.
 @since 100.1
 */
-(id<AGSCancelable>)solveClosestFacilityWithParameters:(AGSClosestFacilityParameters*)closestFacilityParameters completion:(void(^)(AGSClosestFacilityResult * __nullable closestFacilityResult, NSError * __nullable error))completion;

NS_ASSUME_NONNULL_END
@end
