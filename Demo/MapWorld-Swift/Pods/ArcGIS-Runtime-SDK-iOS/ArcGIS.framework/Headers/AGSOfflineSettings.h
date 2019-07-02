/*
 COPYRIGHT 2019 ESRI
 
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

/** @file AGSOfflineSettings.h */ //Required for Globals API doc

/** @brief
 
 Represents settings in an online web map which the author has configured for offline use.

 Offline settings can be configured by a web map author to provide default values which are appropriate for taking a map offline. Applications which take the map offline can choose to ignore these offline settings when setting parameters for an `AGSOfflineMapTask`.
 
 The following methods will use the offline settings to set default parameter values: 
 - @c AGSOfflineMapTask#defaultDownloadPreplannedOfflineMapParametersWithArea:completion:
 - @c AGSOfflineMapTask#defaultGenerateOfflineMapParametersWithAreaOfInterest:completion:
 - @c AGSOfflineMapTask#defaultGenerateOfflineMapParametersWithAreaOfInterest:minScale:maxScale:completion:
 
 @since 100.5
 */
@interface AGSOfflineSettings : AGSObject

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init NS_UNAVAILABLE;

#pragma mark -
#pragma mark properties

/** A setting configured by the web map author that provides guidance for how attachments should be synced when working offline.
 - If this setting is @c AGSAttachmentSyncDirectionNone, then attachements should never be uploaded
 or downloaded when performing a sync operation.
 - If this setting is @c AGSAttachmentSyncDirectionUpload, then attachments should be uploaded when performing sync.
 - If this setting is @c AGSAttachmentSyncDirectionBidirectional, then attachments should be uploaded and downloaded when performing sync.
 
 This value can be used to set a default for @c AGSGenerateOfflineMapParameters#attachmentSyncDirection.
 Alternatively, using @c AGSOfflineMapTask#createDefaultGenerateOfflineMapParametersWithAreaOfInterest:completion: will pre-populate the parameters using this property.
 @since 100.5
 */
@property (nonatomic, assign, readonly) AGSAttachmentSyncDirection attachmentSyncDirection;

/**
 The name of a local basemap file which can be used instead of downloading a basemap when taking this map offline.
 
 Supported basemap formats are:
    - .tpk
    - .tpkx
    - .vtpk The webmap author sets this property to denote an appropriate basemap file. Client code is responsible for ensuring that the basemap has been correctly side-loaded to the device.
 
 @since 100.5
 */
@property (nonatomic, copy, readonly) NSString *referenceBasemapFilename;

/** A setting configured by the web map author that indicates which feature layers should include attachments when taken offline.
 Based on the value of this setting, attachments should be included with:
 - none of the layers when the value is @c AGSReturnLayerAttachmentOptionNone.
 - all of the layers when the value is @c AGSReturnLayerAttachmentOptionAllLayers.
 - read only layers when the value is @c AGSReturnLayerAttachmentOptionReadOnlyLayers.
 - editable layers when the value is @c AGSReturnLayerAttachmentOptionEditableLayers.
 
 This value can be used to set a default for @c AGSGenerateOfflineMapParameters#returnLayerAttachmentOption.
 Alternatively, using @c AGSOfflineMapTask#createDefaultGenerateOfflineMapParametersWithAreaOfInterest:completion: will pre-populate the parameters using this property.
 @since 100.5
 */
@property (nonatomic, assign, readonly) AGSReturnLayerAttachmentOption returnLayerAttachmentOption;

/** A setting configured by the web map author that indicates whether or not feature layers taken offline should be schema only and contain no data.
 - If TRUE, this setting means that feature layers should be taken offline with no existing data in them.
 - If FALSE, this setting means that existing features should be included when taking data offline
 for an editing workflow.
 
 This value can be used to set a default for @c AGSGenerateOfflineMapParameters#returnSchemaOnlyForEditableLayers.
 Alternatively, using @c AGSOfflineMapTask#createDefaultGenerateOfflineMapParametersWithAreaOfInterest:completion: will pre-populate the parameters using this property.
 @since 100.5
 */
@property (nonatomic, assign, readonly) BOOL returnSchemaOnlyForEditableLayers;



#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end
