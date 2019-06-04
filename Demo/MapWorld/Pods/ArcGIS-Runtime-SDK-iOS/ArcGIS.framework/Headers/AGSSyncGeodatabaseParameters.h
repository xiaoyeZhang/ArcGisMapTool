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

#import "AGSObject.h"

@class AGSSyncLayerOption;

/** @file AGSSyncGeodatabaseParameters.h */ //Required for Globals API doc

/** @brief Parameters to synchronize data of a sync-enabled geodatabase 
 
 Instances of this class represent parameters that are used with `AGSGeodatabaseSyncTask#syncJobWithParameters:geodatabase:` to synchronize the data of a sync-enabled geodatabase with its originating ArcGIS Feature services.
 
 @note Consider using the convenience method `AGSGeodatabaseSyncTask#getDefaultSyncGeodatabaseParametersForGeodatabase:completion:` to get a properly initialized instance of this class which takes into account the capabilities supported by the ArcGIS Feature service and how the geodatabase was configured when it was generated.
 
 @since 100
 @see `AGSGeodatabaseSyncTask` to synchronize the geodatabase
 @see `AGSGeodatabase` for edit and query operations suppported by the geodatabase
 */
@interface AGSSyncGeodatabaseParameters : AGSObject

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init;

+(instancetype)syncGeodatabaseParameters;

#pragma mark -
#pragma mark properties

/** Specifies the direction in which the entire geodatabase must sync changes with the service. Only applicable if the geodatabase uses a sync model of  `AGSSyncModelGeodatabase`. Otherwise, use `#layerOptions`
 @since 100
 */
@property (nonatomic, assign, readwrite) AGSSyncDirection geodatabaseSyncDirection;

/** Options specifying the direction in which individual layers in the geodatabase must sync changes with the service. Not all layers need to be included in the sync operation. Some of them can be excluded by leaving them out of this list.
 
 Only applicable if the geodatabase uses a sync model of `AGSSyncModelLayer`. Otherwise, use `#geodatabaseSyncDirection`
 @since 100
 */
@property (nonatomic, copy, readwrite) NSArray<AGSSyncLayerOption*> *layerOptions;

/** Specifies whether all edits are rolled back (not applied) if a failure occurs while importing edits on the server. Otherwise, failed edits are skipped and other edits still applied.
 
 @note It only applies to edits uploaded by the client to the server. Does not apply to edits imported by client.
 @since 100
 */
 
@property (nonatomic, assign, readwrite) BOOL rollbackOnFailure;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end
