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

#import "AGSLoadableBase.h"

@class AGSFeatureServiceCapabilities;
@class AGSEnvelope;
@class AGSUnit;
@class AGSServiceDocumentInfo;
@class AGSSyncCapabilities;
@class AGSEditorTrackingInfo;
@class AGSIDInfo;

/** @file AGSArcGISFeatureServiceInfo.h */ //Required for Globals API doc

/** @brief information about an ArcGIS Feature service
 
 Instances of this class represent information about an ArcGIS Feature service.

 @since 100
 */
@interface AGSArcGISFeatureServiceInfo : AGSObject

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** The URL of the ArcGIS Feature service.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) NSURL *URL;

/** Indicates whether the layer allows geometries of features to be updated.
 You should check this property before allowing the ability to update a feature's geometry in your app.
 @since 100
 */
@property (nonatomic, assign, readonly) BOOL allowGeometryUpdates;

/** Copyright information of the service.
 @since 100
 */
@property (nonatomic, copy, readonly) NSString *attribution;

/** Specifies the version of this particular service.
 @since 100
 */
@property (nonatomic, copy, readonly) NSString *version;

/** Description of the service
 @since 100
 */
@property (nonatomic, copy, readonly) NSString *dataFrameDescription;

/** Information about the backing map document used to create the service.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSServiceDocumentInfo *documentInfo;

/** information about the service's editor tracking configuration
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSEditorTrackingInfo *editorTrackingInfo;

/** Indicates whether service supports default values for 3D geometries.
 @since 100
 */
@property (nonatomic, assign, readonly) BOOL zDefaultsEnabled;

/** The default extent of geographic data available in the service
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSEnvelope *fullExtent;

/** indicates if the service has static data
 @since 100
 */
@property (nonatomic, assign, readonly) BOOL hasStaticData;

/** Indicates whether the service is backed by versioned data.
 @since 100
 */
@property (nonatomic, assign, readonly) BOOL hasVersionedData;

/** The default extent of geographic data available in the service
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSEnvelope *initialExtent;

/** Information about sub-layers in the service
 @since 100
 */
@property (nonatomic, copy, readonly) NSArray<AGSIDInfo*> *layerInfos;

/** The maximum number of features that will be returned by the service for
 any query operation. Applications should handle re-querying the omitted results when
 this limit is reached.
 @since 100
 */
@property (nonatomic, assign, readonly) NSInteger maxRecordCount;

/** The editing operations that are allow by the service: Query, Create, Delete, Update, Uploads, Editing
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSFeatureServiceCapabilities *featureServiceCapabilities;

/** User-friendly description about the service.
 @since 100
 */
@property (nonatomic, copy, readonly) NSString *serviceDescription;

/** Spatial reference of geographic data available in the service.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSSpatialReference *spatialReference;

/** Indicates if disconnected editing is supported
 @since 100
 */
@property (nonatomic, assign, readonly) BOOL supportsDisconnectedEditing;

/** Information about sync related capabilities of the service.
 This will be nil if the service does not support sync.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSSyncCapabilities *syncCapabilities;

/** Indicates if sync is enabled
 @since 100
 */
@property (nonatomic, assign, readonly, getter=isSyncEnabled) BOOL syncEnabled;

/** Information about (non-spatial) tables in the service
 @since 100
 */
@property (nonatomic, copy, readonly) NSArray<AGSIDInfo*> *tableInfos;

/** default z value
 @since 100
 */
@property (nonatomic, assign, readonly) double zDefault;

@property (nonatomic, strong, readonly) AGSUnit *unit;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end
