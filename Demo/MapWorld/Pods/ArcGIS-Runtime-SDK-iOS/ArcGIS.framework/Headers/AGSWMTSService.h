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

#import "AGSObject.h"
#import "AGSLoadableBase.h"
#import "AGSRemoteResource.h"

@class AGSWMTSServiceInfo;

/** @file AGSWMTSService.h */ //Required for Globals API doc

/** @brief An OGC-WMTS map service
 
 Instances of this class represent an OGC-WMTS map service. For example, http://v2.suite.opengeo.org/geoserver/gwc/service/wmts .
 
 A WMTS service uses a cache of pre-generated tiles to serve maps instead of dynamically generating map images.
  
 @since 100.1
 */
@interface AGSWMTSService : AGSLoadableBase <AGSRemoteResource>

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

/** Initialize a WMTS Service based on the provided parameters
 @param URL to a WMTS Service
 @return Initialized WMTS service
 @since 100.1
 */
-(instancetype)initWithURL:(NSURL *)URL;

#pragma mark -
#pragma mark properties

/** URL to an OGC-WMTS service. For example http://v2.suite.opengeo.org/geoserver/gwc/service/wmts or https://sampleserver6.arcgisonline.com/arcgis/rest/services/WorldTimeZones/MapServer/WMTS
 @since 100.1
 */
@property (nullable, nonatomic, strong, readonly) NSURL *URL;


/** Metadata about the WMTS service.
 @since 100.1
 */
@property (nullable, nonatomic, strong, readonly) AGSWMTSServiceInfo *serviceInfo;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end
