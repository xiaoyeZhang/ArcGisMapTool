/*
 COPYRIGHT 2014 ESRI
 
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

#import "AGSObject.h"

@class AGSEnvelope;
@class AGSPoint;
@class AGSSpatialReference;
@class AGSLevelOfDetail;

/** @file AGSTileInfo.h */ //Required for Globals API doc

/** @brief The tiling scheme of a tiled layer.
 
 This object represents the tiling scheme used by a cached map service. For
 example, ArcGIS Server cached map service, Bing Maps, etc. The tiling scheme
 contains information about how a map is broken up into tiles of images and how
 a client can use these tiles to display a map.
 
 @since 100
 */
@interface AGSTileInfo : AGSObject
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

/** Initialize a tile info to represent the tiling scheme.
 @param DPI The dots per inch of the tile images
 @param format The format of the tile images
 @param levelsOfDetail representing the scale levels in the tiling scheme.
 @param origin Starting location of Row 0 and Column 0 of the tiling scheme
 @param spatialReference The spatial reference of the tiling scheme
 @param tileHeight in points of each tile
 @param tileWidth in points of each tile
 @return An initialized <code>%AGSTileInfo</code> object.
 @since 100
 */
+ (instancetype)tileInfoWithDPI:(NSInteger)DPI
                         format:(AGSTileImageFormat)format
                 levelsOfDetail:(NSArray<AGSLevelOfDetail*> *)levelsOfDetail
                         origin:(AGSPoint *)origin
               spatialReference:(AGSSpatialReference *)spatialReference
                     tileHeight:(NSInteger)tileHeight
                      tileWidth:(NSInteger)tileWidth;

/** Initialize a tile info to represent the tiling scheme.
 @param DPI The dots per inch of the tile images
 @param format The format of the tile images
 @param levelsOfDetail representing the scale levels in the tiling scheme.
 @param origin Starting location of Row 0 and Column 0 of the tiling scheme
 @param spatialReference The spatial reference of the tiling scheme
 @param tileHeight in points of each tile
 @param tileWidth in points of each tile
 @return An initialized <code>%AGSTileInfo</code> object.
 @since 100
 */
- (instancetype)initWithDPI:(NSInteger)DPI
                     format:(AGSTileImageFormat)format
             levelsOfDetail:(NSArray<AGSLevelOfDetail*> *)levelsOfDetail
                     origin:(AGSPoint *)origin
           spatialReference:(AGSSpatialReference *)spatialReference
                 tileHeight:(NSInteger)tileHeight
                  tileWidth:(NSInteger)tileWidth;

#pragma mark -
#pragma mark properties

/** Width (in points) of an individual tile image
 @since 100
 */
@property (nonatomic, assign, readonly) NSInteger tileWidth;

/** Height (in points) of an individual tile image
 @since 100
 */
@property (nonatomic, assign, readonly) NSInteger tileHeight;

/** The Dots-Per-Inch (DPI) resolution of tiled images.
 @since 100
 */
@property (nonatomic, assign, readonly) NSInteger DPI;

@property (nonatomic, assign, readonly) AGSTileImageFormat format;

/** The tiling scheme origin which specifies the starting location of Row 0 and Column 0.
 @since 100
 */
@property (nonatomic, strong, readonly) AGSPoint *origin;

/** The compression quality of the tile images. The compression quality controls
 how much loss the image will be subjected to by the compression algorithm. The values of
 the pixels of an image compressed with a higher compression quality will be closer to
 those of the original image. The valid range of compression quality values is from 1 to 100.
 @since 100
 */
@property (nonatomic, assign, readonly) float compressionQuality;

/** The spatial reference of the tiling scheme.
 @since 100
 */

@property (nonatomic, strong, readonly) AGSSpatialReference *spatialReference;

/** Array of @c AGSLevelOfDetail objects representing the scale levels (Levels of Detail)
 in the tiling scheme.
 @since 100
 */
@property (nonatomic, copy, readonly) NSArray<AGSLevelOfDetail*> *levelsOfDetail;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END
@end
