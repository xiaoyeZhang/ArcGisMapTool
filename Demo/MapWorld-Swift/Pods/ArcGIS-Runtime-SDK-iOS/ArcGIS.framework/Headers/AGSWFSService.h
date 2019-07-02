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

#import "AGSLoadableRemoteResourceBase.h"

NS_ASSUME_NONNULL_BEGIN

@class AGSWFSServiceInfo;

/** @file AGSWFSService.h */ //Required for Globals API doc

/** @brief An object that represents a WFS Service.
 
 Provides an entry point to explore the WFS service metadata via @c AGSWFSServiceInfo.
 @remark Runtime is compatible with OGC Web Feature Service 2.0.0 and 2.0.2.
 @since 100.5
 */
@interface AGSWFSService : AGSLoadableRemoteResourceBase

#pragma mark -
#pragma mark initializers

-(instancetype)init NS_UNAVAILABLE;

/** Creates a @c AGSWFSService with provided URL to the service.
 The URL is the 'GetCapabilities' URL for the WFS service.
 @param URL of the WFS service.
 @since 100.5
 */
-(instancetype)initWithURL:(NSURL*)URL;

/** Creates a @c AGSWFSService with provided URL to the service.
 The URL is the 'GetCapabilities' URL for the WFS service.
 @param URL of the WFS service.
 @since 100.5
 */
+(instancetype)WFSServiceWithURL:(NSURL*)URL;

#pragma mark -
#pragma mark properties

/** Metadata about the service, including name, description, and a list of available layers (feature types).
 The WFS service info is returned as @c AGSWFSServiceInfo type.
 @since 100.5
 */
@property (nullable, nonatomic, strong, readonly) AGSWFSServiceInfo *serviceInfo;

#pragma mark -
#pragma mark methods

@end

NS_ASSUME_NONNULL_END
