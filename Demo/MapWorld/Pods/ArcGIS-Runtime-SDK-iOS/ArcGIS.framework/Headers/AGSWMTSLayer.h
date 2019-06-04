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

#import "AGSImageTiledLayer.h"
#import "AGSRemoteResource.h"

@class AGSWMTSLayerInfo;
@class AGSWMTSTileMatrixSet;

/** @file AGSWMTSLayer.h */ //Required for Globals API doc

/** @brief A layer based on an OGC-WMTS map service
 
 An instance of this class allows you to display maps from a WMTS map service. For example, http://v2.suite.opengeo.org/geoserver/gwc/service/wmts .
 
 A WMTS service uses a cache of pre-generated tiles to serve maps instead of dynamically generating map images. If the service permits requests in the RESTful style, the layer will make tile requests in this manner, otherwise requests will be made using KVP.
 
 @since 100.1
 */
@interface AGSWMTSLayer : AGSImageTiledLayer <AGSRemoteResource>

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

/** Initialize a WMTS layer based on the provided parameters
 @param URL to a WMTS Service
 @param layerID Identifier of a \<Layer> element in the WMTS service
 @return A new initialized WMTS layers
 @since 100.1
 */
-(instancetype)initWithURL:(NSURL *)URL layerID:(NSString *)layerID;

/** Initialize a WMTS layer based on the provided parameters
 @param URL to a WMTS Service
 @param layerID Identifier of a \<Layer> element in the WMTS service
 @param preferredImageFormat The image format to use if it is supported by the service for the specified layer
 @return A new initialized WMTS layers
 @since 100.1
 */
-(instancetype)initWithURL:(NSURL *)URL layerID:(NSString *)layerID preferredImageFormat:(AGSTileImageFormat)preferredImageFormat;

/** Initialize a WMTS layer based on the provided parameters
 @param URL to a WMTS Service
 @param layerID Identifier of a \<Layer> element in the WMTS service
 @param matrixSetID Identifier of a \<TileMatrixSet> element for the layer to use
 @return A new initialized WMTS layers
 @since 100.1
 */
-(instancetype)initWithURL:(NSURL *)URL layerID:(NSString *)layerID matrixSetID:(NSString *)matrixSetID;

/** Initialize a WMTS layer based on the provided parameters
 @param URL to a WMTS Service
 @param layerID Identifier of a \<Layer> element in the WMTS service
 @param matrixSetID Identifier of a \<TileMatrixSet> element for the layer to use
 @param preferredImageFormat The image format to use if it is supported by the service for the specified layer
 @return A new initialized WMTS layers
 @since 100.1
 */
-(instancetype)initWithURL:(NSURL *)URL layerID:(NSString *)layerID matrixSetID:(NSString *)matrixSetID preferredImageFormat:(AGSTileImageFormat)preferredImageFormat;

/** Initialize a WMTS layer based on the provided parameters
 @param layerInfo specifying which layer to use in the service
 @return A new initialized WMTS layers
 @since 100.1
 */
-(instancetype)initWithLayerInfo:(AGSWMTSLayerInfo *)layerInfo;

/** Initialize a WMTS layer based on the provided parameters
 @param layerInfo specifying which layer to use in the service
 @param preferredImageFormat The image format to use if it is supported by the service for the specified layer
 @return A new initialized WMTS layers
 @since 100.1
 */
-(instancetype)initWithLayerInfo:(AGSWMTSLayerInfo *)layerInfo preferredImageFormat:(AGSTileImageFormat)preferredImageFormat;

/** Initialize a WMTS layer based on the provided parameters
 @param layerInfo specifying which layer to use in the service
 @param tileMatrixSet The TileMatrixSet to use for the specified layer
 @return A new initialized WMTS layers
 @since 100.1
 */
-(instancetype)initWithLayerInfo:(AGSWMTSLayerInfo *)layerInfo tileMatrixSet:(AGSWMTSTileMatrixSet *)tileMatrixSet;

/** Initialize a WMTS layer based on the provided parameters
 @param layerInfo specifying which layer to use in the service
 @param tileMatrixSet The TileMatrixSet to use for the specified layer
 @param preferredImageFormat The image format to use if it is supported by the service for the specified layer
 @return A new initialized WMTS layers
 @since 100.1
 */
-(instancetype)initWithLayerInfo:(AGSWMTSLayerInfo *)layerInfo tileMatrixSet:(AGSWMTSTileMatrixSet *)tileMatrixSet preferredImageFormat:(AGSTileImageFormat)preferredImageFormat;

/** Initialize a WMTS layer based on the provided parameters
 @param URL to a WMTS Service
 @param layerID Identifier of a \<Layer> element in the WMTS service
 @return A new initialized WMTS layers
 @since 100.1
 */
+(instancetype)WMTSLayerWithURL:(NSURL *)URL layerID:(NSString *)layerID;

/** Initialize a WMTS layer based on the provided parameters
 @param URL to a WMTS Service
 @param layerID Identifier of a \<Layer> element in the WMTS service
 @param preferredImageFormat The image format to use if it is supported by the service for the specified layer
 @return A new initialized WMTS layers
 @since 100.1
 */
+(instancetype)WMTSLayerWithURL:(NSURL *)URL layerID:(NSString *)layerID preferredImageFormat:(AGSTileImageFormat)preferredImageFormat;

/** Initialize a WMTS layer based on the provided parameters
 @param URL to a WMTS Service
 @param layerID Identifier of a \<Layer> element in the WMTS service
 @param matrixSetID Identifier of a \<TileMatrixSet> element for the layer to use
 @return A new initialized WMTS layers
 @since 100.1
 */
+(instancetype)WMTSLayerWithURL:(NSURL *)URL layerID:(NSString *)layerID matrixSetID:(NSString *)matrixSetID;

/** Initialize a WMTS layer based on the provided parameters
 @param URL to a WMTS Service
 @param layerID Identifier of a \<Layer> element in the WMTS service
 @param matrixSetID Identifier of a \<TileMatrixSet> element for the layer to use
 @param preferredImageFormat The image format to use if it is supported by the service for the specified layer
 @return A new initialized WMTS layers
 @since 100.1
 */
+(instancetype)WMTSLayerWithURL:(NSURL *)URL layerID:(NSString *)layerID matrixSetID:(NSString *)matrixSetID preferredImageFormat:(AGSTileImageFormat)preferredImageFormat;

/** Initialize a WMTS layer based on the provided parameters
 @param layerInfo specifying which layer to use in the service
 @return A new initialized WMTS layers
 @since 100.1
 */
+(instancetype)WMTSLayerWithLayerInfo:(AGSWMTSLayerInfo *)layerInfo;

/** Initialize a WMTS layer based on the provided parameters
 @param layerInfo specifying which layer to use in the service
 @param preferredImageFormat The image format to use if it is supported by the service for the specified layer
 @return A new initialized WMTS layers
 @since 100.1
 */
+(instancetype)WMTSLayerWithLayerInfo:(AGSWMTSLayerInfo *)layerInfo preferredImageFormat:(AGSTileImageFormat)preferredImageFormat;

/** Initialize a WMTS layer based on the provided parameters
 @param layerInfo specifying which layer to use in the service
 @param tileMatrixSet The TileMatrixSet to use for the specified layer
 @return A new initialized WMTS layers
 @since 100.1
 */
+(instancetype)WMTSLayerWithLayerInfo:(AGSWMTSLayerInfo *)layerInfo tileMatrixSet:(AGSWMTSTileMatrixSet *)tileMatrixSet;

/** Initialize a WMTS layer based on the provided parameters
 @param layerInfo specifying which layer to use in the service
 @param tileMatrixSet The TileMatrixSet to use for the specified layer
 @param preferredImageFormat The image format to use if it is supported by the service for the specified layer
 @return A new initialized WMTS layers
 @since 100.1
 */
+(instancetype)WMTSLayerWithLayerInfo:(AGSWMTSLayerInfo *)layerInfo tileMatrixSet:(AGSWMTSTileMatrixSet *)tileMatrixSet preferredImageFormat:(AGSTileImageFormat)preferredImageFormat;

#pragma mark -
#pragma mark properties

/** URL to an OGC-WMTS service. For example http://v2.suite.opengeo.org/geoserver/gwc/service/wmts or https://sampleserver6.arcgisonline.com/arcgis/rest/services/WorldTimeZones/MapServer/WMTS
 @since 100.1
 */
@property (nullable, nonatomic, strong, readonly) NSURL *URL;

/** The image format to use if it is supported by the service for the specified layer
 @since 100.1
 */
@property (nonatomic, assign, readonly) AGSTileImageFormat preferredImageFormat;

/** Information about an individual layer in the WMTS service that will be displayed by this layer
 @since 100.1
 */
@property (nullable, nonatomic, strong, readonly) AGSWMTSLayerInfo *layerInfo;

/** The tile matrix set to use for the specified layer
 @since 100.1
 */
@property (nullable, nonatomic, strong, readonly) AGSWMTSTileMatrixSet *tileMatrixSet;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end
