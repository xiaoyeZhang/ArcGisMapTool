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

#import "AGSRaster.h"
#import "AGSRemoteResource.h"

@class AGSRenderingRule;
@class AGSArcGISImageServiceInfo;

/** @brief A raster dataset based on an ArcGIS Image Service
 
 An instance of this class represents a raster dataset based on an ArcGIS Image Service, for instance, http://sampleserver3.arcgisonline.com/ArcGIS/rest/services/World/MODIS/ImageServer .  Raster data can be displayed on screen in a 2D map or a 3D scene using an `AGSRasterLayer`.
 
 @see `AGSRasterLayer` to display rasters in a map or a scene
 @license{Standard, when raster functions are applied.}
 @ingroup licensing
 @since 100.1
 */
@interface AGSImageServiceRaster : AGSRaster <AGSRemoteResource>

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

/** Initialize the raster with a URL to a remote ArcGIS Image Service, for instance, http://sampleserver3.arcgisonline.com/ArcGIS/rest/services/World/MODIS/ImageServer 
 @param URL to a remote ArcGIS Image Service
 @return Initialized image service raster
 @since 100.1
 */
-(instancetype)initWithURL:(NSURL*)URL;

/** Initialize the raster with a URL to a remote ArcGIS Image Service, for instance, http://sampleserver3.arcgisonline.com/ArcGIS/rest/services/World/MODIS/ImageServer
 @param URL to a remote ArcGIS Image Service
 @return Initialized image service raster
 @since 100.1
 */
+(instancetype)imageServiceRasterWithURL:(NSURL*)URL;

#pragma mark -
#pragma mark properties

/** Rendering rule for how the raster should be rendered. Rendering rules allows you to perform complex processing, such as computing hillshade or slope, on raster data of an ArcGIS Image Service. The source data is not changed. Instead, processing is performed on-the-fly while displaying the raster layer in a map or a scene.
 @since 100.1
 */
@property (nullable, nonatomic, strong, readwrite) AGSRenderingRule *renderingRule;


/** Metadata about the ArcGIS Image Service used by this raster
 @since 100.1
 */
@property (nullable, nonatomic, strong, readonly) AGSArcGISImageServiceInfo *serviceInfo;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end
