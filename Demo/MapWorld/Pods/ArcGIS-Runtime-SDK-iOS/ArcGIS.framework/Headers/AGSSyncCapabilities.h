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

/** @file AGSSyncCapabilities.h */ //Required for Globals API doc

/** @brief Capabilities supported by a sync-enabled service
 
 Instances of this class represent capabilities supported by a sync-enabled service.
 
 @since 100
 */
@interface AGSSyncCapabilities : AGSObject

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** Indicates whether the service supports asynchronous operations. This avoids server timeouts.
 @since 100
 */
@property (nonatomic, assign, readonly) BOOL supportsAsync;

@property (nonatomic, assign, readonly) BOOL supportsAttachmentsSyncDirection;

/** Indicates whether the service supports registering existing datasets (*.geodatabase file)
 as new a sync-enabled geodatabase. This is useful when you already have a geodatabase that you want to sync
 on multiple devices independently without affecting each other.
 @since 100
 */
@property (nonatomic, assign, readonly) BOOL supportsRegisteringExistingData;

/** Indicates whether the service supports rolling back edits in case of a failure during sync operations.
 @since 100
 */
@property (nonatomic, assign, readonly) BOOL supportsRollbackOnFailure;

/** Indicates whether the service allows the client application to control direction of
 sync - upload only, download only, or bi-directional.
 @since 100
 */
@property (nonatomic, assign, readonly) BOOL supportsSyncDirectionControl;

/** Indicates whether the service supports sync capabilities for the entire sync-enabled geodatabase.
 All layers in the geodatabase will be synchronized together in the same direction.
 @since 100
 */
@property (nonatomic, assign, readonly) BOOL supportsSyncModelGeodatabase;

/** Indicates whether the service supports sync capabilities independently on a layer-by-layer basis in
 the sync-enabled geodatabase. For example, one layer can upload changes while another downloads during sync. A perLayer sync model also allows clients to limit the sync to a subset of layers in the geodatabase.
 @since 100
 */
@property (nonatomic, assign, readonly) BOOL supportsSyncModelLayer;

@property (nonatomic, assign, readonly) BOOL supportsSyncModelNone;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end
