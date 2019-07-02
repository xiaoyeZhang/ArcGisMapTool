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

/** @file AGSElevationServiceInfo.h */ // Required for Globals API doc.

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 A type of layer for an elevation service.
 
 @since 100.5
 */
typedef NSString *AGSElevationServiceLayerType NS_TYPED_ENUM NS_SWIFT_NAME(AGSElevationServiceInfo.LayerType);

/**
 An @c ArcGISTiledElevationServiceLayer layer.
 
 @since 100.5
 */
FOUNDATION_EXTERN AGSElevationServiceLayerType const AGSElevationServiceLayerTypeArcGISTiled;

/**
 Represents a Limited Error Raster Compression (LERC) elevation service that is
 provided by the portal.
 
 @since 100.5
 */
__attribute__((objc_subclassing_restricted))
@interface AGSElevationServiceInfo : NSObject

- (instancetype)init NS_UNAVAILABLE;

/**
 A unique identifying string for the service.
 
 @since 100.5
 */
@property (nonatomic, copy, readonly) NSString *serviceID;
/**
 The type of layer for the service.
 
 @since 100.5
 */
@property (nonatomic, copy, readonly) AGSElevationServiceLayerType layerType;
/**
 The URL of the service.
 
 @since 100.5
 */
@property (nonatomic, readonly) NSURL *URL;

@end

NS_ASSUME_NONNULL_END
