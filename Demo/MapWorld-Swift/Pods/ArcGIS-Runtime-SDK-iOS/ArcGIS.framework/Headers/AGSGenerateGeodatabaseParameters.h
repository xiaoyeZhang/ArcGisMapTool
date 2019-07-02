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
@class AGSGeometry;
@class AGSGenerateLayerOption;

/** @file AGSGenerateGeodatabaseParameters.h */ //Required for Globals API doc

/** @brief Parameters to generate a sync-enabled geodatabase
 
 Instances of this class represent parameters that are used with `AGSGeodatabaseSyncTask#generateJobWithParameters:downloadFileURL:` to generate sync-enabled geodatabases from supporting ArcGIS Feature services.
 
 @note Consider using the convenience method `AGSGeodatabaseSyncTask#getDefaultGenerateGeodatabaseParametersWithCompletion:` to get a properly initialized instance of this class which takes into account the capabilities supported by the ArcGIS Feature service and the data it contains.
 
 @since 100
 @see `AGSGeodatabaseSyncTask` to generate the geodatabase
 @see `AGSGeodatabase` for edit and query operations suppported by the geodatabase
 */
@interface AGSGenerateGeodatabaseParameters : AGSObject

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

+(instancetype)generateGeodatabaseParameters;

#pragma mark -
#pragma mark properties

/** Specifies how the geodatabase should be configured to sync attachment data with its originating service.
 @since 100
 */
@property (nonatomic, assign, readwrite) AGSAttachmentSyncDirection attachmentSyncDirection;

/** The geographic extent within which features will be included in the sync-enabled geodatabase. To include non-spatial records, you must properly set up the `#layerOptions` for that layer to include a `AGSGenerateLayerOption#whereClause` and set `AGSGenerateLayerOption#useGeometry` to `NO`
 @since 100
 */
@property (nullable, nonatomic, strong, readwrite) AGSGeometry *extent;

/** Options specifiying how to filter features for inclusion into the sync-enabled geodatabase on a layer-by-layer basis. If not specified, all features within the extent are included. For non-spatial records, you must set `AGSGenerateLayerOption#useGeometry` to NO and provide a `AGSGenerateLayerOption#whereClause`.
 @since 100
 */
@property (nonatomic, copy, readwrite) NSArray<AGSGenerateLayerOption*> *layerOptions;

/** The spatial reference in which you would like the generated geodatabase. If the data on the server is not in this spatial reference, it will be reprojected before being included in the geodatabase.
 @since 100
 */
@property (nullable, nonatomic, strong, readwrite) AGSSpatialReference *outSpatialReference;

/** Indicates whether or not the sync-enabled geodatabase should contain attachments for the features that are included. Only applicable if the feature service supports attachments.
 @since 100
 */
@property (nonatomic, assign, readwrite) BOOL returnAttachments;

/** Specifies whether the geodatabase should be configured to sync with the originating service as a whole or individually on a per layer basis.
 @since 100
 */
@property (nonatomic, assign, readwrite) AGSSyncModel syncModel;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end


