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

#import "AGSLoadableRemoteResourceBase.h"

@class AGSRouteTaskInfo;
@class AGSRouteParameters;
@class AGSRouteResult;
@class AGSTransportationNetworkDataset;
@class AGSFeatureCollection;
@class AGSPortalItem;

/** @file AGSRouteTask.h */ //Required for Globals API doc

/** @brief A task to compute routes and turn-by-turn directions
 
 Instances of this class represent a task used to compute routes and turn-by-turn directions. It allows you to find a variety of routes between any given locations - the quickest, shortest, most scenic, and so on. The route returned depends on the impedance chosen by you. For example, if the impedance is time, then the best route is the quickest route. Hence, the best route can be defined as the route that has the lowest impedance. 
 
 The task can be created for an ArcGIS Network Analyst service hosted in the cloud on ArcGIS Online or on-premises with ArcGIS Server. The task can also be created for a transportation network dataset stored locally on the device in which case it can used even when the device has no network connectivity.
 
 @since 100
 */
@interface AGSRouteTask : AGSLoadableRemoteResourceBase
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

/** Initialize the task with a reference to the transportation network dataset available for a map.
 @param dataset transportation network dataset to use
 @return a new route task
 @since 100
 @see `AGSMap#transportationNetworks` to get a reference to the transportation network datasets available for a map.
 */
-(instancetype)initWithDataset:(AGSTransportationNetworkDataset*)dataset;

/** Initialize the task with a reference to the transportation network dataset available for a map.
 @param dataset transportation network dataset to use
 @return a new route task
 @since 100
 @see `AGSMap#transportationNetworks` to get a reference to the transportation network datasets available for a map.
 */
+(instancetype)routeTaskWithDataset:(AGSTransportationNetworkDataset*)dataset;

/** Initialize the task with a path to the geodatabase containing a transportation network dataset, and the name of the transportation network dataset.
 @param fileURLToDatabase URL to the .geodatabase file on disk
 @param networkName name of the transportation network dataset within the geodatabase
 @return a new route task
 @since 100
 */
-(instancetype)initWithFileURLToDatabase:(NSURL*)fileURLToDatabase networkName:(NSString*)networkName;

/** Initialize the task with a path to the geodatabase containing a transportation network dataset, and the name of the transportation network dataset.
 @param fileURLToDatabase URL to the .geodatabase file on disk
 @param networkName name of the transportation network dataset within the geodatabase
 @return a new route task
 @since 100
 */
+(instancetype)routeTaskWithFileURLToDatabase:(NSURL*)fileURLToDatabase networkName:(NSString*)networkName;

/** Initialize the task with the name of a geodatabase containing a transportation network dataset, and the name of the dataset.
 @param databaseName name of the geodatabase file (within the application bundle or shared documents directory) without the .geodatabase file extension
 @param networkName name of the transportation network dataset within the geodatabase
 @return a new route task
 @since 100
*/
-(instancetype)initWithDatabaseName:(NSString*)databaseName networkName:(NSString*)networkName;

/** Initialize the task with the name of a geodatabase containing a transportation network dataset, and the name of the dataset.
 @param databaseName name of the geodatabase file (within the application bundle or shared documents directory) without the .geodatabase file extension
 @param networkName name of the transportation network dataset within the geodatabase
 @return a new route task
 @since 100
 */
+(instancetype)routeTaskWithDatabaseName:(NSString*)databaseName networkName:(NSString*)networkName;

/** Initialize the task with a URL to a route layer in an ArcGIS Network Analyst service. The service may be hosted in the cloud on ArcGIS Online or on-premises with ArcGIS Server.
 @param URL to a route layer in an ArcGIS Network Analyst service. For example, http://sampleserver3.arcgisonline.com/ArcGIS/rest/services/Network/USA/NAServer/Route
 @return a new route task
 @since 100
 */
-(instancetype)initWithURL:(NSURL*)URL;

/** Initialize the task with a URL to a route layer in an ArcGIS Network Analyst service. The service may be hosted in the cloud on ArcGIS Online or on-premises with ArcGIS Server.
 @param URL to a route layer in an ArcGIS Network Analyst service. For example, http://sampleserver3.arcgisonline.com/ArcGIS/rest/services/Network/USA/NAServer/Route
 @return a new route task
 @since 100
 */
+(instancetype)routeTaskWithURL:(NSURL*)URL;

#pragma mark -
#pragma mark properties

/** The transportation network dataset being used by this task
 Will be nil if the task is using a service instead of a local geodatabase.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSTransportationNetworkDataset *transportationNetworkDataset;

#pragma mark -
#pragma mark methods

/**
 Metadata about the ArcGIS Network Analyst service or transportation network dataset being used by the task
 @since 100
 */
-(AGSRouteTaskInfo*)routeTaskInfo;

/**  A convenience method to get properly initialized parameters for computing a route. The parameters are initialized with default values based on the `#routeTaskInfo`
 @param completion block that is invoked when the operation completes. The route parameters are populated if the operation succeeds, else the error is populated if the operation fails.
 @since 100
 */
-(id<AGSCancelable>)defaultRouteParametersWithCompletion:(void(^)(AGSRouteParameters * __nullable routeParams, NSError * __nullable error))completion;

/** A convenience method to get properly initialized parameters for computing a route. The parameters are initialized with default values based on the `#routeTaskInfo`, and every feature in the provided feature collection is added as a stop along the desired route.
 @param featureCollection containing the stops
 @param completion block that is invoked when the operation completes. The route parameters are populated if the operation succeeds, else the error is populated if the operation fails.
 @since 100
*/
-(id<AGSCancelable>)routeParametersWithFeatureCollection:(AGSFeatureCollection*)featureCollection
                                              completion:(void(^)(AGSRouteParameters * __nullable routeParams, NSError * __nullable error))completion;

/** A convenience method to get properly initialized parameters for computing a route similar to the one in the portal item.  The item's type must be `AGSPortalItemTypeFeatureCollection` and the item must represent a route layer (i.e the item's `typeKeywords` must contain "Route Layer"). The parameters are initialized with default values based on the `#routeTaskInfo`, and every feature in the provided feature collection is added as a stop along the desired route.
 @param portalItem representing a feature collection that contains stops, route info, and barriers tables. Stops table is required.
 @param completion block that is invoked when the operation completes. The route parameters are populated if the operation succeeds, else the error is populated if the operation fails.
 @since 100.3
 */
-(id<AGSCancelable>)routeParametersWithPortalItem:(AGSPortalItem*)portalItem
                                       completion:(void(^)(AGSRouteParameters * __nullable routeParams, NSError * __nullable error))completion;

/** Imports a pre-planned route result from a portal item. The item's type must be `AGSPortalItemTypeFeatureCollection` and the item must represent a route layer (i.e the item's `typeKeywords` must contain "Route Layer")
 @param portalItem representing a feature collection containing a route result.
 @param completion block that is invoked when the operation completes. The route result is populated if the operation succeeds, else the error is populated if the operation fails.
 @since 100.3
 */
+(id<AGSCancelable>)routeResultWithPortalItem:(AGSPortalItem*)portalItem
                                   completion:(void(^)(AGSRouteResult * __nullable routeResult, NSError * __nullable error))completion;

/** Imports a pre-planned route result from a feature collection.
 @param featureCollection containing a route result.
 @param completion block that is invoked when the operation completes. The route result is populated if the operation succeeds, else the error is populated if the operation fails.
 @since 100.4
 */
+(id<AGSCancelable>)routeResultWithFeatureCollection:(AGSFeatureCollection*)featureCollection
                                          completion:(void(^)(AGSRouteResult * __nullable routeResult, NSError * __nullable error))completion;

/** Computes routes based on the provided route parameters
 @param routeParameters based on which routes should be computed
 @param completion block that is invoked when the operation completes. The result is populated if the operation succeeds, else the error is populated if the operation fails.
 @since 100
 */
-(id<AGSCancelable>)solveRouteWithParameters:(AGSRouteParameters*)routeParameters completion:(void(^)(AGSRouteResult * __nullable routeResult, NSError * __nullable error))completion;

NS_ASSUME_NONNULL_END
@end
