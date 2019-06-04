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

@class AGSItemResourceCache;
@class AGSVectorTileCache;

/** @file AGSExportVectorTilesResult.h */ //Required for Globals API doc

/** @brief Result of the job to export vector tiles
 
 Instances of this class represent the result of `AGSExportVectorTilesJob` used to export vector tiles.
 
 @since 100.2
 */
@interface AGSExportVectorTilesResult : AGSObject

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** The item resource cache containing custom style resources for the vector tiles. You can use  reuse these style resources with mutliple vector tiled layers.
 @see `AGSArcGISVectorTiledLayer#initWithVectorTileCache:itemResourceCache:`
 @since 100.2
 */
@property (nullable, nonatomic, strong, readonly) AGSItemResourceCache *itemResourceCache;

/** The cache containing the vector tiles exported from the service. You can use `AGSArcGISVectorTiledLayer` to display the tiles in a map or scene.
 @see `AGSArcGISVectorTiledLayer#initWithVectorTileCache:`
 @since 100.2
 */
@property (nullable, nonatomic, strong, readonly) AGSVectorTileCache *vectorTileCache;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end
