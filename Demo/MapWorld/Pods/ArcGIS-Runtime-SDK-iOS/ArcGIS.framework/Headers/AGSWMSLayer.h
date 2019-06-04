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

#import "AGSImageAdjustmentLayer.h"
#import "AGSRemoteResource.h"
#import "AGSTimeAware.h"

@class AGSWMSLayerInfo;
@class AGSWMSSublayer;
@class AGSItem;

/** @file AGSWMSLayer.h */ //Required for Globals API doc

/** @brief A layer based on an OGC-WMS service
 
 An instance of this class allows you to display maps from an OGC WMS service. The service may be hosted in the cloud on ArcGIS Online, on a third party server, or on-premise with ArcGIS Enterprise.

 @since 100.2
 */
@interface AGSWMSLayer : AGSImageAdjustmentLayer <AGSRemoteResource, AGSTimeAware>

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

/** Initialize the layer with a collection of layers to render in the WMS service.
 @param layerInfos representing the layers to display
 @return Initialized layer
 @since 100.2
 */
-(instancetype)initWithLayerInfos:(NSArray<AGSWMSLayerInfo*> *)layerInfos;

/** Initialize the layer with a URL to a WMS service. The URL can be the `GetCapabilities` URL for the service, for example - https://sampleserver6.arcgisonline.com/arcgis/services/SampleWorldCities/MapServer/WMSServer?request=GetCapabilities&service=WMS , or it could be a URL that just points to the service endpoint where the `GetCapabilities` request can be issued, such as - https://sampleserver6.arcgisonline.com/arcgis/services/SampleWorldCities/MapServer/WMSServer.
 
 Runtime supports WMS versions 1.3.0, 1.1.1, and 1.1.0. The latest supported WMS version is set as the default. To specify a preferred WMS version, set the `VERSION` parameter in the `GetCapabilities` URL for the service.
 @param URL to WMS layer
 @param layerNames list of layers in the service to display
 @return Initialized layer
 @since 100.2
 */
-(instancetype)initWithURL:(NSURL *)URL layerNames:(NSArray<NSString*> *)layerNames;

/** Initialize the layer with an item representing a WMS service. The item's type should be `AGSPortalItemTypeWMS`
 @param item representing a WMS service
 @return Initialized layer
 @since 100.2
 */
-(instancetype)initWithItem:(AGSItem *)item;

/** Initialize the layer with a collection of layers to render in the WMS service.
 @param layerInfos representing the layers to display
 @return Initialized layer
 @since 100.2
 */
+(instancetype)WMSLayerWithLayerInfos:(NSArray<AGSWMSLayerInfo*> *)layerInfos;

/** Initialize the layer with a URL to a WMS service. The URL can be the `GetCapabilities` URL for the service, for example - https://sampleserver6.arcgisonline.com/arcgis/services/SampleWorldCities/MapServer/WMSServer?request=GetCapabilities&service=WMS , or it could be a URL that just points to the service endpoint where the `GetCapabilities` request can be issued, such as - https://sampleserver6.arcgisonline.com/arcgis/services/SampleWorldCities/MapServer/WMSServer.
     
 Runtime supports WMS versions 1.3.0, 1.1.1, and 1.1.0. The latest supported WMS version is set as the default. To specify a preferred WMS version, set the `VERSION` parameter in the `GetCapabilities` URL for the service.
 @param URL to WMS layer
 @param layerNames list of layers in the service to display
 @return Initialized layer
 @since 100.2
 */
+(instancetype)WMSLayerWithURL:(NSURL *)URL layerNames:(NSArray<NSString*> *)layerNames;

/** Initialize the layer with an item representing a WMS service. The item's type should be `AGSPortalItemTypeWMS`
 @param item representing a WMS service
 @return Initialized layer
 @since 100.2
 */
+(instancetype)WMSLayerWithItem:(AGSItem *)item;

#pragma mark -
#pragma mark properties

/** A collection of layer info objects representing the layers in the WMS service
 @since 100.2
 */
@property (nonatomic, strong, readonly) NSMutableArray<AGSWMSLayerInfo*> *layerInfos;

/** Names of layers in the WMS service
 @since 100.2
 */
@property (nonatomic, strong, readonly) NSMutableArray<NSString*> *layerNames;

/** The preferred image format for rendering the layer
 @since 100.2
 */
@property (nonatomic, assign, readwrite) AGSMapServiceImageFormat preferredImageFormat;

/** A collection of sublayers, one for each layer in the WMS service that is represented in `#layerInfos`.
 @since 100.2
 */
@property (nonatomic, strong, readonly) NSMutableArray<AGSWMSSublayer*> *sublayers;

/** Time interval (in seconds) specifying how often the layer should auto-refresh its contents. If 0 or less is specified, the layer will not auto-refresh.
 @since 100.2
 */
@property (nonatomic, assign, readwrite) NSTimeInterval refreshInterval;

/** The version of the WMS layer.
 Runtime supports WMS versions 1.3.0, 1.1.1, and 1.1.0. The latest supported WMS version is set as the default. To specify a preferred WMS version, set the `VERSION` parameter in the `GetCapabilities` URL for the service.
 @since 100.2.1
 */
@property (nonatomic, assign, readonly) AGSWMSVersion version;

/** These parameters are appended to `GetMap` and `GetFeatureInfo` requests issued to the WMS service. If a parameter with the same name is defined in the service's custom parameters, then layer-specific values take precedence over service-wide values.
 @since 100.3
 */
@property (nonatomic, copy, readwrite) NSDictionary<NSString*,NSString*> *customParameters;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end

