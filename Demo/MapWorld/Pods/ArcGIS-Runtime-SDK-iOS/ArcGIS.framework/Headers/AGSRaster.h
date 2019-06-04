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

#import "AGSLoadableBase.h"

@class AGSRasterFunction;

/** @file AGSRaster.h */ //Required for Globals API doc

/** @brief A raster dataset
 
 An instance of this class represents a raster dataset.  Raster data can be displayed on screen in a 2D map or a 3D scene using an `AGSRasterLayer`.

 In its simplest form, a raster consists of a matrix of cells (or pixels) organized into rows and columns (or a grid) where each cell contains a value representing information, such as temperature. Rasters are digital aerial photographs, imagery from satellites, digital pictures, or even scanned maps.
 
 [Learn more about rasters](http://desktop.arcgis.com/en/arcmap/latest/manage-data/raster-and-images/what-is-raster-data.htm)
 
 The following raster data formats are supported -
 @li ASRP/USRP (Arc Standard Raster Product/ UTM Standard Raster Product)
 @li CIB  (Controlled Image Base)
 @li CADRG/ECRG  (Compressed ARC Digitized Raster Graphics/Enhanced Compressed ARC Digitized Raster Graphics)
 @li DTED (Digital Terrain Elevation Data)
 @li GeoPackage Raster
 @li GeoTIFF/TIFF
 @li HFA (Erdas Imagine)
 @li HRE (High Resolution Elevation)
 @li IMG (Erdas Imagine)
 @li JPEG
 @li JPEG2000
 @li Mosaic Dataset in SQLite
 @li NITF (National Imagery Transmission Format)
 @li PNG
 @li RPF (Raster Product Format)
 @li SRTM (HGT) (Shuttle Radar Topography Mission)
 @li CRF (Cloud Raster Format)
 @li MrSID (Multiresolution seamless image database) - support added at version 100.4
 
 [Learn more about raster data formats](http://desktop.arcgis.com/en/arcmap/latest/manage-data/raster-and-images/supported-raster-dataset-file-formats.htm)
 
 @see `AGSRasterLayer` to display rasters in a map or a scene
 @license{Standard}
 @ingroup licensing
 @since 100
*/
@interface AGSRaster : AGSLoadableBase
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

/** Initialize a raster with a path to the raster dataset on disk.
 @param fileURL to the local raster dataset on disk.
 @since 100
 @return An initialized raster
 @license{Standard}
 @ingroup licensing
 */
-(instancetype)initWithFileURL:(NSURL*)fileURL;

/** Initialize a raster with a path to the raster dataset on disk.
 @param fileURL to the local raster dataset on disk.
 @since 100
 @return An initialized raster
 @license{Standard}
 @ingroup licensing
 */
+(instancetype)rasterWithFileURL:(NSURL*)fileURL;

/** Initialize a raster with a name of a raster dataset within the application bundle or shared documents directory, and its file extension.
 @param name of a raster dataset within the application bundle or shared documents directory.
 @param extension file extension of the raster dataset
 @since 100
 @return An initialized raster
 @license{Standard}
 @ingroup licensing
 */
-(instancetype)initWithName:(NSString*)name extension:(NSString*)extension;

/** Initialize a raster with a name of a raster dataset within the application bundle or shared documents directory, and its file extension.
 @param name of a raster dataset within the application bundle or shared documents directory.
 @param extension file extension of the raster dataset
 @since 100
 @return An initialized raster
 @license{Standard}
 @ingroup licensing
 */
+(instancetype)rasterWithName:(NSString*)name extension:(NSString*)extension;

/** Initialize a raster with a raster function.
 @param rasterFunction whose output is represented by this raster
 @since 100
 @return An initialized raster
 @license{Standard}
 @ingroup licensing
 */
-(instancetype)initWithRasterFunction:(AGSRasterFunction *)rasterFunction;

/** Initialize a raster with a raster function.
 @param rasterFunction whose output is represented by this raster
 @since 100
 @return An initialized raster
 @license{Standard}
 @ingroup licensing
 */
+(instancetype)rasterWithRasterFunction:(AGSRasterFunction *)rasterFunction;

#pragma mark -
#pragma mark properties

/** File URL to the local raster dataset on disk
 @since 100
 */
@property (nonatomic, strong, readonly) NSURL *fileURL;

/** A function to transform the raster
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSRasterFunction *function;

NS_ASSUME_NONNULL_END
@end
