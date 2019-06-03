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

@class AGSItem;
@class AGSTileCache;

#import "AGSElevationSource.h"
#import "AGSRemoteResource.h"

/** @file AGSArcGISTiledElevationSource.h */ //Required for Globals API doc

/** @brief An elevation source based on tiled elevation data
 
 Instances of this class represent an elevation source based on a tiled ArcGIS Image Service containing elevation data. It can be used in `AGSSurface#elevationSources` to specify the surface of a scene.
 
 @since 100
 @see `AGSScene#baseSurface` to specify the surface of a scene
 
 */
@interface AGSArcGISTiledElevationSource : AGSElevationSource <AGSRemoteResource>

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers
 
/** Initialize a tiled elevation source based on an ArcGIS Image service or a local Tile Package (.tpk file) on disk containing elevation data.
 @param URL to a tiled ArcGIS Image service or a local Tile Package (.tpk file) on disk containing elevation data.
 @return A new tiled elevation source
 @since 100
 */
-(instancetype)initWithURL:(NSURL*)URL;

/** Initialize a tiled elevation source with the name of a local Tile Package (.tpk file) within the application bundle or shared documents directory containing elevation data.
 @param name of local Tile Package (same as the name of the .tpk file without the file extension) containing elevation data.
 @return A new tiled elevation source
 @since 100.1
 */
-(instancetype)initWithName:(NSString*)name;

/** Initialize a tiled elevation source based on an item on ArcGIS Online or ArcGIS Portal representing an ArcGIS Image service containing elevation data.
 @param item representing an ArcGIS Image service containing elevation data.
 @return A new tiled elevation source
 @since 100
 */
-(instancetype)initWithItem:(AGSItem*)item;

/** Initialize a tiled elevation source based on an tile cache containing elevation data.
 @param tileCache containing elevation data.
 @return A new tiled elevation source
 @since 100.1
 */
-(instancetype)initWithTileCache:(AGSTileCache*)tileCache;

/** Initialize a tiled elevation source.
 @since 100
 */
+(instancetype)ArcGISTiledElevationSource;

/** Initialize a tiled elevation source based on an ArcGIS Image service or a local Tile Package (.tpk file) on disk containing elevation data.
 @param URL to a tiled ArcGIS Image service or a local Tile Package (.tpk file) on disk containing elevation data.
 @return A new tiled elevation source
 @since 100
 */
+(instancetype)ArcGISTiledElevationSourceWithURL:(NSURL*)URL;

/** Initialize a tiled elevation source with the name of a local Tile Package (.tpk file) within the application bundle or shared documents directory containing elevation data.
 @param name of local Tile Package (same as the name of the .tpk file without the file extension) containing elevation data.
 @return A new tiled elevation source
 @since 100.1
 */
+(instancetype)ArcGISTiledElevationSourceWithName:(NSString*)name;

/** Initialize a tiled elevation source based on an item on ArcGIS Online or ArcGIS Portal representing an ArcGIS Image service containing elevation data.
 @param item representing an ArcGIS Image service containing elevation data.
 @return A new tiled elevation source
 @since 100
 */
+(instancetype)ArcGISTiledElevationSourceWithItem:(AGSItem*)item;

/** Initialize a tiled elevation source based on an tile cache containing elevation data.
 @param tileCache containing elevation data.
 @return A new tiled elevation source
 @since 100.1
 */
+(instancetype)ArcGISTiledElevationSourceWithTileCache:(AGSTileCache*)tileCache;

#pragma mark -
#pragma mark properties

/** The item being used by the elevation source, if any.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSItem *item;

/** The tile cache being used by the elevation source, if any.
 @since 100.1
 */
@property (nullable, nonatomic, strong, readonly) AGSTileCache *tileCache;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end
