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

#import "AGSLayer.h"
#import "AGSRemoteResource.h"

@class AGSItem;
@class AGSVectorTileSourceInfo;
@class AGSVectorTileStyle;
@class AGSVectorTileCache;
@class AGSItemResourceCache;

/** @file AGSArcGISVectorTiledLayer.h */ //Required for Globals API doc

/** @brief A layer that can display maps using vector tiles
 
 An instance of this class allows you to display maps from an ArcGIS Vector Tile source, a Vector Tile Style Sheet, or a local Vector Tile Package(.VTPK file). It uses a cache of pre-generated vector tiles to assemble a map instead of dynamically generating map images.
 
 @since 100
 */
@interface AGSArcGISVectorTiledLayer : AGSLayer <AGSRemoteResource>
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

/** Initialize this layer with an item on ArcGIS Online or ArcGIS Portal representing an ArcGIS Vector Tile layer.
 @param item representing an ArcGIS Vector Tile layer.
 @return A new vector tiled layer
 @since 100
 */
-(instancetype)initWithItem:(AGSItem *)item;

/** Initialize this layer with a URL to an ArcGIS Vector Tile source/stylesheet or .vtpk file on disk. The following URL formats are supported -
 
 @li URL to a vector tile service -  http://basemaps.arcgis.com/b2/arcgis/rest/services/World_Basemap/VectorTileServer
 @li URL to a vector tile layer stylesheet - http://basemaps.arcgis.com/b2/arcgis/rest/services/World_Basemap/VectorTileServer/resources/styles/root.json
 @li URL to a portal item that represents a vector tile layer - http://www.arcgis.com/home/item.html?id=850db44b9eb845d3bd42b19e8aa7a024
 @li URL to a .vtpk file - file:///VectorTilePackages/Redlands.vtpk
 
 @param url to an ArcGIS Vector Tile source/stylesheet or .vtpk file on disk.
 @return A new vector tiled layer
 @since 100
 */
-(instancetype)initWithURL:(NSURL *)url;

/** Initialize this layer with a name of a Vector Tile Package (.VTPK file), excluding the ".vtpk" extension,
 within the application bundle or shared documents directory.
 @param name of the Vector Tile Package (excluding the .vtpk extension)
 @return A new vector tiled layer
 @since 100
 */
-(instancetype)initWithName:(NSString*)name;

/** Initialize this layer with a tile cache representing a local Vector Tile Package (.vtpk file)
 @param vectorTileCache representing a local Vector Tile Package (.vtpk file)
 @return A new tiled layer object
 @since 100.2
 */
-(instancetype)initWithVectorTileCache:(AGSVectorTileCache *)vectorTileCache;

/** Initialize this layer with a tile cache representing a local Vector Tile Package (.vtpk file) and resource cache containing custom style resources
 @param vectorTileCache representing a local Vector Tile Package (.vtpk file)
 @param itemResourceCache containing custom style resources
 @return A new tiled layer object
 @since 100.2
 */
-(instancetype)initWithVectorTileCache:(AGSVectorTileCache *)vectorTileCache itemResourceCache:(nullable AGSItemResourceCache*)itemResourceCache;

/** Initialize this layer with an item on ArcGIS Online or ArcGIS Portal representing an ArcGIS Vector Tile layer.
 @param item representing an ArcGIS Vector Tile layer.
 @return A new vector tiled layer
 @since 100
 */
+(instancetype)ArcGISVectorTiledLayerWithItem:(AGSItem *)item;

/** Initialize this layer with a URL to an ArcGIS Vector Tile source/stylesheet or .vtpk file on disk. The following URL formats are supported -
 
 @li URL to a vector tile service -  http://basemaps.arcgis.com/b2/arcgis/rest/services/World_Basemap/VectorTileServer
 @li URL to a vector tile layer stylesheet - http://basemaps.arcgis.com/b2/arcgis/rest/services/World_Basemap/VectorTileServer/resources/styles/root.json
 @li URL to a portal item that represents a vector tile layer - http://www.arcgis.com/home/item.html?id=850db44b9eb845d3bd42b19e8aa7a024
 @li URL to a .vtpk file - file:///VectorTilePackages/Redlands.vtpk
 
 @param url to an ArcGIS Vector Tile source/stylesheet or .vtpk file on disk.
 @return A new vector tiled layer
 @since 100
 */
+(instancetype)ArcGISVectorTiledLayerWithURL:(NSURL *)url;

/** Initialize this layer with a name of a Vector Tile Package (.VTPK file), excluding the ".vtpk" extension,
 within the application bundle or shared documents directory.
 @param name of the Vector Tile Package (excluding the .vtpk extension)
 @return A new vector tiled layer
 @since 100
 */
+(instancetype)ArcGISVectorTiledLayerWithName:(NSString*)name;

+(instancetype)ArcGISVectorTiledLayerWithVectorTileCache:(AGSVectorTileCache *)vectorTileCache;

+(instancetype)ArcGISVectorTiledLayerWithVectorTileCache:(AGSVectorTileCache *)vectorTileCache itemResourceCache:(nullable AGSItemResourceCache*)itemResourceCache;

#pragma mark -
#pragma mark properties

/** Metadata about the source of vector tiles
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSVectorTileSourceInfo *sourceInfo;

/** Style used to display the vector tiles
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSVectorTileStyle *style;

@property (nullable, nonatomic, strong, readonly) AGSVectorTileCache *vectorTileCache;

@property (nullable, nonatomic, strong, readonly) AGSItemResourceCache *itemResourceCache;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END
@end

