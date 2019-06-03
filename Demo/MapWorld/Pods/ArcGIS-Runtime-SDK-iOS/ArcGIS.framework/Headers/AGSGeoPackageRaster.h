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

@class AGSGeoPackage;

#import "AGSRaster.h"

/** @file AGSGeoPackageRaster.h */ //Required for Globals API doc

/** @brief A raster dataset within a GeoPackage
 
 An instance of this class represents a raster dataset within a GeoPackage.  It represents images of types PNG or JPEG. Note that a GeoPackage can store multiple raster and tile pyramid datasets in different tables or views in the same container.
 
 Raster data can be displayed on screen in a 2D map or a 3D scene using an `AGSRasterLayer`.
 
 @see `AGSGeoPackage`
 @since 100.2
 */
@interface AGSGeoPackageRaster : AGSRaster

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** Description of the dataset
 @since 100.2
 */
@property (nonatomic, copy, readonly) NSString *rasterDescription;

/** The GeoPackage to which this dataset belongs.
 @since 100.2
 */
@property (nullable, nonatomic, weak, readonly) AGSGeoPackage *geoPackage;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end

