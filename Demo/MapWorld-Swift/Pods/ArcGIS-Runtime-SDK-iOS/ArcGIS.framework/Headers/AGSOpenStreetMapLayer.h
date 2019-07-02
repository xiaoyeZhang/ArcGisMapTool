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

#import "AGSServiceImageTiledLayer.h"

/** @file AGSOpenStreetMapLayer.h */ //Required for Globals API doc

/** @brief A layer based on OpenStreetMap
 
 An instance of this class represents an OpenStreetMap layer.
 
 The layer displays map content from an OpenStreetMap web service which provides access to static map tiles.
 
 @since 100.1
 */
@interface AGSOpenStreetMapLayer : AGSServiceImageTiledLayer

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

+(instancetype)openStreetMapLayer;

#pragma mark -
#pragma mark properties

#pragma mark -
#pragma mark methods

@end

NS_ASSUME_NONNULL_END
