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

@class AGSLayer;
@class AGSOfflineMapSyncLayerResult;
@class AGSFeatureTable;

/** @file AGSOfflineMapSyncResult.h */ //Required for Globals API doc

/** @brief Result of a sync operation by `AGSOfflineMapSyncJob`
 
 Instances of this class represent results of a sync operation initiated by `AGSOfflineMapSyncJob`
 
 @since 100.1
 */
@interface AGSOfflineMapSyncResult : AGSObject

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

- (instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** Indicates if any sync operations for feature layers and tables in the offline map encountered an error. If `true`, you should inspect `#layerResults` and `#tableResults` to find out which layer or table encountered an error and to get more information about the error.
 @since 100.1
 */
@property (nonatomic, assign, readonly) BOOL hasErrors;

/** Results of the sync operations for feature layers
 @since 100.1
 */
@property (nonatomic, copy, readonly) NSDictionary<AGSLayer *, AGSOfflineMapSyncLayerResult *> *layerResults;

/** Results of the sync operations for feature tables
 @since 100.1
 */
@property (nonatomic, copy, readonly) NSDictionary<AGSFeatureTable *, AGSOfflineMapSyncLayerResult *> *tableResults;

#pragma mark -
#pragma mark methods

@end

NS_ASSUME_NONNULL_END
