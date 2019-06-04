/*
 COPYRIGHT 2016 ESRI
 
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

/** @file AGSRasterRenderer.h */ //Required for Globals API doc

/** @brief A base class for raster renderers
 
 A base class for renderers that can help visualize raster data.
 
 @since 100
 */
@interface AGSRasterRenderer : AGSObject
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init;
+(instancetype)rasterRenderer;

NS_ASSUME_NONNULL_END
@end
