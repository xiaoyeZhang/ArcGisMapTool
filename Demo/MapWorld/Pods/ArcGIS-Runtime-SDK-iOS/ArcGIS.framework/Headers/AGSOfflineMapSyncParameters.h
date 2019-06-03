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

/** @file AGSOfflineMapSyncParameters.h */ //Required for Globals API doc

/** @brief Parameters to synchronize an offline map
 
 Instances of this class represent parameters that are used with `AGSOfflineMapSyncTask#offlineMapSyncJobWithParameters:` to synchronize the data of feature layers and tables in an offline map with their originating ArcGIS Feature services.
 

 @since 100.1
 @see `AGSOfflineMapTask` to take a map offline
 */
@interface AGSOfflineMapSyncParameters : AGSObject

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

+(instancetype)offlineMapSyncParameters;

#pragma mark -
#pragma mark properties

/** Specifies whether all edits are rolled back (not applied) if a failure occurs while importing edits on the server. Otherwise, failed edits are skipped and other edits still applied.
 @note It only applies to edits uploaded by the client to the server. Does not apply to edits imported by client.
 @since 100.1
 */
@property (nonatomic, assign, readwrite) BOOL rollbackOnFailure;


/** Direction in which to synchronize the data of feature layers and tables in the offline map with the originating ArcGIS Feature service.
 @since 100.1
 */
@property (nonatomic, assign, readwrite) AGSSyncDirection syncDirection;

#pragma mark -
#pragma mark methods

@end

NS_ASSUME_NONNULL_END
