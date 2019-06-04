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

#import "AGSLoadableBase.h"

@class AGSVectorTileSourceInfo;

/** @file AGSVectorTileCache.h */ //Required for Globals API doc

/** @brief A cache of tiles in a Vector Tile Package
 
 Instances of this class represent a cache of tiles in a local Vector Tile Package (.vtpk file). Local tile caches are ideal for providing basemaps or less frequently changing contextual layers, where network access is limited or non-existent. They can be created and downloaded onto a device by using an `AGSExportVectorTilesTask`, or alternatively can be provisioned directly to local storage.
 
 @since 100.2
 */
@interface AGSVectorTileCache : AGSLoadableBase

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

/** Initialize this object with a path to a local Vector Tile Package (.vtpk file)
 @param fileURL to a local Vector Tile Package (.vtpk file)
 @return initialized vector tile cache
 @since 100.2
 */
-(instancetype)initWithFileURL:(NSURL*)fileURL;

/** Initialize this object with the name of a local Vector Tile Package (.vtpk file) within the application bundle or shared documents directory.
 @param name of local Vector Tile Package (same as the name of the .vtpk file without the file extension)
 @return initialized vector tile cache
 @since 100.2
 */
-(instancetype)initWithName:(NSString*)name;

/** Initialize this object with a path to a local Vector Tile Package (.vtpk file)
 @param fileURL to a local Vector Tile Package (.vtpk file)
 @return initialized vector tile cache
 @since 100.2
 */
+(instancetype)vectorTileCacheWithFileURL:(NSURL*)fileURL;

/** Initialize this object with the name of a local Vector Tile Package (.vtpk file) within the application bundle or shared documents directory.
 @param name of local Vector Tile Package (same as the name of the .vtpk file without the file extension)
 @return initialized vector tile cache
 @since 100.2
 */
+(instancetype)vectorTileCacheWithName:(NSString*)name;

#pragma mark -
#pragma mark properties

/** The file URL of the Vector Tile Package (.vtpk file) being used by this tile cache
 @since 100.2
 */
@property (nonatomic, strong, readonly) NSURL *fileURL;

/** Metadata about the source of vector tiles
 @since 100.2
 */
@property (nullable, nonatomic, strong, readonly) AGSVectorTileSourceInfo *sourceInfo;

/** The thumbnail image of the cache.
 @since 100.2
 */
@property (nullable, nonatomic, strong, readonly) AGSImage *thumbnail;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end

