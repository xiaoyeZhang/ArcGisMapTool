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

/** @file AGSWFSServiceInfo.h */ //Required for Globals API doc

#import "AGSObject.h"

@class AGSWFSLayerInfo;

NS_ASSUME_NONNULL_BEGIN

/** @brief An object that represents the service metadata for an WFS Service.
 
 Provides metadata (e.g name, title, description, and more) about a WFS service, and lists the available WFS layers (feature types).
 @since 100.5
 */
@interface AGSWFSServiceInfo : AGSObject

#pragma mark -
#pragma mark initializers

-(instancetype)init NS_UNAVAILABLE;

#pragma mark -
#pragma mark properties

/** The service's description.
 @since 100.5
 */
@property (nonatomic, copy, readonly) NSString *serviceDescription;

/** The keywords describing the WFS service.
 The keywords are returned in an @c NSArray<T> of @c NSString.
 @since 100.5
 */
@property (nonatomic, copy, readonly) NSArray<NSString*> *keywords;

/** Information about the layers provided by the service.
 This property can be used to discover the layers (feature types) exposed by a WFS service in support of a browsing experience.
 @since 100.5
 */
@property (nonatomic, copy, readonly) NSArray<AGSWFSLayerInfo*> *layerInfos;

/** The service's human-readable title.
 @since 100.5
 */
@property (nonatomic, copy, readonly) NSString *title;

#pragma mark -
#pragma mark methods

@end

NS_ASSUME_NONNULL_END

