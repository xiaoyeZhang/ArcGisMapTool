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

#import "AGSLoadableBase.h"
#import "AGSRemoteResource.h"

@class AGSWMSServiceInfo;

/** @file AGSWMSService.h */ //Required for Globals API doc

/** @brief An OGC-WMS service
 
 An instance of this class represents an OGC-WMS service.
 
Runtime supports WMS versions 1.3.0, 1.1.1, and 1.1.0. The latest supported WMS version is set as the default. To specify a preferred WMS version, set the `VERSION` parameter in the `GetCapabilities` URL for the service.
 
 @since 100.2
 */
@interface AGSWMSService : AGSLoadableBase <AGSRemoteResource>

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

/** Initialize this object with a URL to a WMS service. The URL can be the `GetCapabilities` URL for the service, for example - https://sampleserver6.arcgisonline.com/arcgis/services/SampleWorldCities/MapServer/WMSServer?request=GetCapabilities&service=WMS , or it could be a URL that just points to the service endpoint where the `GetCapabilities` request can be issued, such as - https://sampleserver6.arcgisonline.com/arcgis/services/SampleWorldCities/MapServer/WMSServer
 
 Runtime supports WMS versions 1.3.0, 1.1.1, and 1.1.0. The latest supported WMS version is set as the default. To specify a preferred WMS version, set the `VERSION` parameter in the `GetCapabilities` URL for the service.
 
 @param URL to WMS service
 @return Initialized service
 @since 100.2
 */
-(instancetype)initWithURL:(NSURL *)URL;

/** Initialize this object with a URL to a WMS service. The URL can be the `GetCapabilities` URL for the service, for example - https://sampleserver6.arcgisonline.com/arcgis/services/SampleWorldCities/MapServer/WMSServer?request=GetCapabilities&service=WMS , or it could be a URL that just points to the service endpoint where the `GetCapabilities` request can be issued, such as - https://sampleserver6.arcgisonline.com/arcgis/services/SampleWorldCities/MapServer/WMSServer
 
 Runtime supports WMS versions 1.3.0, 1.1.1, and 1.1.0. The latest supported WMS version is set as the default. To specify a preferred WMS version, set the `VERSION` parameter in the `GetCapabilities` URL for the service.
 
 @param URL to WMS service
 @return Initialized service
 @since 100.2
 */
+(instancetype)WMSServiceWithURL:(NSURL *)URL;

#pragma mark -
#pragma mark properties

/** Metadata of the WMS service
 @since 100.2
 */
@property (nullable, nonatomic, strong, readonly) AGSWMSServiceInfo *serviceInfo;

/** The version of the WMS service.
 Runtime supports WMS versions 1.3.0, 1.1.1, and 1.1.0. The latest supported WMS version is set as the default. To specify a preferred WMS version, set the `VERSION` parameter in the `GetCapabilities` URL for the service.
 @since 100.2.1
 */
@property (nonatomic, assign, readonly) AGSWMSVersion version;

/** These parameters are appended to `GetCapabilities`, `GetMap`, and `GetFeatureInfo` requests issued to the WMS service. If a parameter with the same name is defined in the service's custom parameters, then layer-specific values take precedence over service-wide values. Parameters intended for `GetCapabilities` requests should be set before the service is loaded
 @since 100.3
 */
@property (nonatomic, copy, readwrite) NSDictionary<NSString*,NSString*> *customParameters;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end

