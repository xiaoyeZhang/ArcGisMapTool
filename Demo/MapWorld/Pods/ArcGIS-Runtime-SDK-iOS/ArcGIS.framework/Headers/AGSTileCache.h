/*
 COPYRIGHT 2015 ESRI
 
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

/** @file AGSTileInfo.h */ //Required for Globals API doc

@class AGSTileInfo;
@class AGSEnvelope;

NS_ASSUME_NONNULL_BEGIN

/** @brief A cache of map tiles in a Tile Package
 
 Instances of this class represent a cache of map tiles in a local Tile Package (.tpk file)
 
 @since 100
 @see `AGSArcGISTiledLayer` to display the contents of the tile cache as a layer in a map
 */
@interface AGSTileCache : AGSLoadableBase <NSCopying>

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

/** Initialize this object with a path to a local Tile Package (.tpk file)
 @param fileURL to a local Tile Package (.tpk file)
 @return initialized tile cache
 @since 100
 */
-(instancetype)initWithFileURL:(NSURL*)fileURL;

/** Initialize this object with the name of a local Tile Package (.tpk file) within the application bundle or shared documents directory.
 @param name of local Tile Package (same as the name of the .tpk file without the file extension)
 @return initialized tile cache
 @since 100
 */
-(instancetype)initWithName:(NSString*)name;

/** Initialize this object with a path to a local Tile Package (.tpk file)
 @param fileURL to a local Tile Package (.tpk file)
 @return initialized tile cache
 @since 100
 */
+(instancetype)tileCacheWithFileURL:(NSURL*)fileURL;

/** Initialize this object with the name of a local Tile Package (.tpk file) within the application bundle or shared documents directory.
 @param name of local Tile Package (same as the name of the .tpk file without the file extension)
 @return initialized tile cache
 @since 100
 */
+(instancetype)tileCacheWithName:(NSString*)name;

#pragma mark -
#pragma mark properties

/** Specifies the antialiasing flag of the cache.
 @since 100
 */
@property (nonatomic, assign, readonly) BOOL antialiasing;

/** Specifies the storage format of the cache.
 @since 100
 */
@property (nonatomic, assign, readonly) AGSCacheStorageFormat cacheStorageFormat;

/** The file URL of the Tile Package (.tpk file) being used by this tile cache
 @since 100
 */
@property (nonatomic, strong, readonly) NSURL *fileURL;

/** The thumbnail image of the cache.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSImage *thumbnail;

/** Tiling scheme used by the cache
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSTileInfo *tileInfo;

/** The full extent covered by all tiles in the cache.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSEnvelope *fullExtent;

#pragma mark -
#pragma mark methods

@end

NS_ASSUME_NONNULL_END
