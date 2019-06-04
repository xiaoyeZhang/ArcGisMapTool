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

@class AGSVectorTileStyle;
@class AGSEnvelope;
@class AGSPoint;
@class AGSSpatialReference;
@class AGSLevelOfDetail;

/** @file AGSVectorTileSourceInfo.h */ //Required for Globals API doc

/** @brief Metadata about a source of vector tiles
 
 Instances of this class contain metadata about the source of vector tiles
 
 @since 100
 */

@interface AGSVectorTileSourceInfo : AGSObject
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** URL to an ArcGIS Vector Tile service or stylesheet.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) NSURL *URL;

/** URL to the default stylesheet used by the source
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) NSURL *defaultStyleURL;

/** Default style used by the source
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSVectorTileStyle *defaultStyle;

/** Whether the source allows tiles to be exported out into a Vector Tile Package (.VTPK file)
 @since 100
 */
@property (nonatomic, assign, readonly) BOOL exportTilesAllowed;

/** Entire geographic area covered by the source
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSEnvelope *fullExtent;

/** Initial geographic area covered by the source
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSEnvelope *initialExtent;

/** Array of @c AGSLevelOfDetail objects representing the scale levels (Levels of Detail)
 in the tiling scheme.
 @since 100.1
 */
@property (nonatomic, copy, readonly) NSArray<AGSLevelOfDetail*> *levelsOfDetail;

/** The maximum number of tiles that can be exported from the service.
 @since 100.3
 */
@property (nonatomic, assign, readonly) NSInteger maxExportTilesCount;

/** The maximum map scale at which the source is visible. If the map is zoomed in beyond this scale, the tiles will not be visible.
 @since 100
 */
@property (nonatomic, assign, readonly) double maxScale;

/** The minimum map scale at which the source is visible. If the map is zoomed out beyond this scale, the tiles will not be visible.
 @since 100
 */
@property (nonatomic, assign, readonly) double minScale;

/** Name of the source
 @since 100
 */
@property (nonatomic, copy, readonly) NSString *name;

/** The source's tiling scheme origin which specifies the geographic location of Row 0 and Column 0.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSPoint *origin;

/** The spatial reference of the tiling scheme.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSSpatialReference *spatialReference;

/** Version number of the source
 @since 100
 */
@property (nonatomic, copy, readonly) NSString *version;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END
@end

