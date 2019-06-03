/*
 COPYRIGHT 2018 ESRI
 
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
@class AGSServiceFeatureTable;

/** @file AGSOfflineMapParametersKey.h */ //Required for Globals API doc

/** @brief Represents a key associated with a generate offline map parameters overrides, used to get the specific parameters, for a given online service, from one of the dictionaries exposed by an `AGSGenerateOfflineMapParameterOverrides`.
 
 Generate offline map parameters overrides consist of instances of `AGSGenerateGeodatabaseParameters`, `AGSExportTileCacheParameters` and `AGSExportVectorTilesParameters`. Each instance is associated with the service URL that the parameters will be sent to for taking the given data offline. The data type specific parameters can be retrieved from their respective dictionaries on `AGSGenerateOfflineMapParameterOverrides` with an instance of `AGSOfflineMapParametersKey`. A key instance for a particular layer can be constructed by calling `AGSOfflineMapParametersKey#initWithLayer:`. For a service feature table, call `AGSOfflineMapParametersKey#initWithServiceFeatureTable:`. Use the key with the dictionary returned by one of these properties: `AGSGenerateOfflineMapParameterOverrides#generateGeodatabaseParameters`, `AGSGenerateOfflineMapParameterOverrides#exportVectorTilesParameters`, `AGSGenerateOfflineMapParameterOverrides#exportTileCacheParameters`. The particular method to call will be determined by the `AGSOfflineMapParametersKey#type` property. Note that a given parameters key/value pair may be shared by multiple layers in the map: for example a single `AGSGenerateGeodatabaseParameters` object could represent the online settings for multiple feature layers which all access the same underlying feature service.
 
 @since 100.4
 */
@interface AGSOfflineMapParametersKey : AGSObject <NSCopying>

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

/** Initialize the offline map parameters key with a layer.
 @param layer The layer that you want the offline map parameters key for.
 @return initialized parameters key
 @since 100.4
 */
-(instancetype)initWithLayer:(AGSLayer *)layer;

/** Initialize the offline map parameters key with a service feature table.
 @param serviceFeatureTable The service feature table that you want the offline map parameters key for.
 @return initialized parameters key
 @since 100.4
 */
-(instancetype)initWithServiceFeatureTable:(AGSServiceFeatureTable *)serviceFeatureTable;

/** Initialize the offline map parameters key with a layer.
 @param layer The layer that you want the offline map parameters key for.
 @return initialized parameters key
 @since 100.4
 */
+(instancetype)offlineMapParametersKeyWithLayer:(AGSLayer *)layer;

/** Initialize the offline map parameters key with a service feature table.
 @param serviceFeatureTable The service feature table that you want the offline map parameters key for.
 @return initialized parameters key
 @since 100.4
 */
+(instancetype)offlineMapParametersKeyWithServiceFeatureTable:(AGSServiceFeatureTable *)serviceFeatureTable;

#pragma mark -
#pragma mark properties

/** Get service URL of this key.
 The service URL is the URL associated with a data specific parameter object in one of the dictionaries owned by an `AGSGenerateOfflineMapParameterOverrides` instance.
 @since 100.4
 */
@property (nonatomic, strong, readonly) NSURL *serviceURL;

/** Get the parameter type of this key.
 The type of this key indicates which `AGSGenerateOfflineMapParameterOverrides` dictionary this key belongs to.
 @since 100.4
 */
@property (nonatomic, assign, readonly) AGSOfflineMapParametersType type;

#pragma mark -
#pragma mark methods

/** Compares whether this offline map parameters key is equal to another
 @param other key to compare this one to
 @return whether the two keys are equal
 @since 100.4
 */
-(BOOL)isEqualToOfflineMapParametersKey:(AGSOfflineMapParametersKey*)other;

NS_ASSUME_NONNULL_END

@end
