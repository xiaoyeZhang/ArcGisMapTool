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

@class AGSGeoPackageFeatureTable;
@class AGSGeoPackageRaster;

#import "AGSLoadableBase.h"

/** @file AGSGeoPackage.h */ //Required for Globals API doc

/** @brief A GeoPackage on disk
 
 Instances of this class represent a local GeoPackage (.gpkg file) containing geographic datasets.
 A GeoPackage is an open, standards-based, platform-independent, portable, self-describing, compact format for transferring geospatial information. It is a platform-independent SQLite database file that contains the GeoPackage data and metadata tables.
 
 @license{Standard}
 @ingroup licensing
 @since 100.2
 */
@interface AGSGeoPackage : AGSLoadableBase

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

/** Initialze this object based on the given path to a local GeoPackage (.gpkg file) on disk.
 @param fileURL to existing GeoPackage on disk (including .gpkg file extension)
 @since 100.2
 @return A new GeoPackage
 @license{Standard}
 @ingroup licensing
 */
-(instancetype)initWithFileURL:(NSURL*)fileURL;

/** Initialize this object with the name of an existing GeoPackage, excluding the ".gpkg" extension,
 within the application bundle or shared documents directory.
 @param name of the GeoPackage (excluding the .gpkg extension)
 @return A new GeoPackage
 @since 100.2
 @license{Standard}
 @ingroup licensing
 */
-(instancetype)initWithName:(NSString*)name;

/** Initialze this object based on the given path to a local GeoPackage (.gpkg file) on disk.
 @param fileURL to existing GeoPackage on disk (including .gpkg file extension)
 @since 100.2
 @return A new GeoPackage
 @license{Standard}
 @ingroup licensing
 */
+(instancetype)geoPackageWithFileURL:(NSURL*)fileURL;

/** Initialize this object with the name of an existing GeoPackage, excluding the ".gpkg" extension,
 within the application bundle or shared documents directory.
 @param name of the GeoPackage (excluding the .gpkg extension)
 @return A new GeoPackage
 @since 100.2
 @license{Standard}
 @ingroup licensing
 */
+(instancetype)geoPackageWithName:(NSString*)name;

#pragma mark -
#pragma mark properties

/** Path to the GeoPackage on disk
 @since 100.2
 */
@property (nonatomic, strong, readonly) NSURL *fileURL;

/** The feature tables representing the vector-based geographic datasets in this geopackage.
 @since 100.2
 */
@property (nonatomic, copy, readonly) NSArray<AGSGeoPackageFeatureTable*> *geoPackageFeatureTables;

/** The rasters representing the raster-based geographic datasets in this geopackage.
 @since 100.2
 */
@property (nonatomic, copy, readonly) NSArray<AGSGeoPackageRaster*> *geoPackageRasters;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end
