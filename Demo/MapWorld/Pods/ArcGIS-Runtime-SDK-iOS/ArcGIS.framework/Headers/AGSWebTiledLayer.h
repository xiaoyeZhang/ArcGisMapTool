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

#import "AGSObject.h"
#import "AGSServiceImageTiledLayer.h"


/** @file AGSWebTiledLayer.h */ //Required for Globals API doc

/** @brief A layer based on non-ArcGIS map tiles
 
 An instance of this class provides a simple way to add non-ArcGIS map tiles as a layer.
 
The tiles are fetched through a template URL such as http://{subDomain}.host.com/{level}/{col}/{row}.png where {level} corresponds to a zoom level, and {col} and {row} represent tile column and row, respectively. The file extension may change depending upon the image format used by the service, and {subDomain} may not be present. This pattern is not required, but is the most common one on the web currently and used by Map Quest, Open Cycle Map, Stamen, Bing, etc.
The template URL should be arranged to reflect how the tiles are arranged in the cache or on the server, and can point to a web server (http://) or to a local file cache (file://).
 
 @since 100.1
 */
 @interface AGSWebTiledLayer : AGSServiceImageTiledLayer

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

/** Initialize a web tiled layer based on the provided parameters
 @note The tiles are assumed to be in the OpenStreetMap tiling scheme, with 256x256 PNG tiles at 96 DPI, the Web Mercator projection, and a full extent of the entire world
 @param URLTemplate of the tile service such as http://{subDomain}.host.com/{level}/{col}/{row}.png where {level} corresponds to a zoom level, and {col} and {row} represent tile column and row, respectively. The file extension may change depending upon the image format used by the service, and {subDomain} may not be present. This pattern is not required, but is the most common one on the web currently and used by Map Quest, Open Cycle Map, Stamen, Bing, etc.
 @return initialized web tile layer
 @since 100.1
 */
-(instancetype)initWithURLTemplate:(NSString*)URLTemplate;

/** Initialize a web tiled layer based on the provided parameters
 @note The tiles are assumed to be in the OpenStreetMap tiling scheme, with 256x256 PNG tiles at 96 DPI, the Web Mercator projection, and a full extent of the entire world
 @param URLTemplate of the tile service such as http://{subDomain}.host.com/{level}/{col}/{row}.png where {level} corresponds to a zoom level, and {col} and {row} represent tile column and row, respectively. The file extension may change depending upon the image format used by the service, and {subDomain} may not be present. This pattern is not required, but is the most common one on the web currently and used by Map Quest, Open Cycle Map, Stamen, Bing, etc.
 @param subDomains used for load balancing tile requests if supported by the service, for eg. a,b,c for Open Cycle Map. If nil the `URLTemplate` should not contain {subDomain}
 @return initialized web tile layer
 @since 100.1
 */
-(instancetype)initWithURLTemplate:(NSString*)URLTemplate subDomains:(nullable NSArray<NSString*>*)subDomains;

/** Initialize a web tiled layer based on the provided parameters
 @param URLTemplate of the tile service such as http://{subDomain}.host.com/{level}/{col}/{row}.png where {level} corresponds to a zoom level, and {col} and {row} represent tile column and row, respectively. The file extension may change depending upon the image format used by the service, and {subDomain} may not be present. This pattern is not required, but is the most common one on the web currently and used by Map Quest, Open Cycle Map, Stamen, Bing, etc.
 @param tileInfo defining the tiling scheme; if nil the Open Street Map tiling scheme is used.
 @param fullExtent of the tiles; if nil the extent of the world in web mercator is used.
 @return initialized web tile layer
 @since 100.1
 */
-(instancetype)initWithURLTemplate:(NSString*)URLTemplate tileInfo:(nullable AGSTileInfo*)tileInfo fullExtent:(nullable AGSEnvelope*)fullExtent;

/** Initialize a web tiled layer based on the provided parameters
 @param URLTemplate of the tile service such as http://{subDomain}.host.com/{level}/{col}/{row}.png where {level} corresponds to a zoom level, and {col} and {row} represent tile column and row, respectively. The file extension may change depending upon the image format used by the service, and {subDomain} may not be present. This pattern is not required, but is the most common one on the web currently and used by Map Quest, Open Cycle Map, Stamen, Bing, etc.
 @param subDomains used for load balancing tile requests if supported by the service, for eg. a,b,c for Open Cycle Map. If nil the `URLTemplate` should not contain {subDomain}
 @param tileInfo defining the tiling scheme; if nil the Open Street Map tiling scheme is used.
 @param fullExtent of the tiles; if nil the extent of the world in web mercator is used.
 @return initialized web tile layer
 @since 100.1
 */
-(instancetype)initWithURLTemplate:(NSString*)URLTemplate subDomains:(nullable NSArray<NSString*>*)subDomains tileInfo:(nullable AGSTileInfo*)tileInfo fullExtent:(nullable AGSEnvelope*)fullExtent;

/** Initialize a web tiled layer based on the provided parameters
 @note The tiles are assumed to be in the OpenStreetMap tiling scheme, with 256x256 PNG tiles at 96 DPI, the Web Mercator projection, and a full extent of the entire world
 @param URLTemplate of the tile service such as http://{subDomain}.host.com/{level}/{col}/{row}.png where {level} corresponds to a zoom level, and {col} and {row} represent tile column and row, respectively. The file extension may change depending upon the image format used by the service, and {subDomain} may not be present. This pattern is not required, but is the most common one on the web currently and used by Map Quest, Open Cycle Map, Stamen, Bing, etc.
 @return initialized web tile layer
 @since 100.1
 */
+(instancetype)webTiledLayerWithURLTemplate:(NSString*)URLTemplate;

/** Initialize a web tiled layer based on the provided parameters
 @note The tiles are assumed to be in the OpenStreetMap tiling scheme, with 256x256 PNG tiles at 96 DPI, the Web Mercator projection, and a full extent of the entire world
 @param URLTemplate of the tile service such as http://{subDomain}.host.com/{level}/{col}/{row}.png where {level} corresponds to a zoom level, and {col} and {row} represent tile column and row, respectively. The file extension may change depending upon the image format used by the service, and {subDomain} may not be present. This pattern is not required, but is the most common one on the web currently and used by Map Quest, Open Cycle Map, Stamen, Bing, etc.
 @param subDomains used for load balancing tile requests if supported by the service, for eg. a,b,c for Open Cycle Map. If nil the `URLTemplate` should not contain {subDomain}
 @return initialized web tile layer
 @since 100.1
 */
+(instancetype)webTiledLayerWithURLTemplate:(NSString*)URLTemplate subDomains:(nullable NSArray<NSString*>*)subDomains;

/** Initialize a web tiled layer based on the provided parameters
 @param URLTemplate of the tile service such as http://{subDomain}.host.com/{level}/{col}/{row}.png where {level} corresponds to a zoom level, and {col} and {row} represent tile column and row, respectively. The file extension may change depending upon the image format used by the service, and {subDomain} may not be present. This pattern is not required, but is the most common one on the web currently and used by Map Quest, Open Cycle Map, Stamen, Bing, etc.
 @param tileInfo defining the tiling scheme; if nil the Open Street Map tiling scheme is used.
 @param fullExtent of the tiles; if nil the extent of the world in web mercator is used.
 @return initialized web tile layer
 @since 100.1
 */
 +(instancetype)webTiledLayerWithURLTemplate:(NSString*)URLTemplate tileInfo:(nullable AGSTileInfo*)tileInfo fullExtent:(nullable AGSEnvelope*)fullExtent;

/** Initialize a web tiled layer based on the provided parameters
 @param URLTemplate of the tile service such as http://{subDomain}.host.com/{level}/{col}/{row}.png where {level} corresponds to a zoom level, and {col} and {row} represent tile column and row, respectively. The file extension may change depending upon the image format used by the service, and {subDomain} may not be present. This pattern is not required, but is the most common one on the web currently and used by Map Quest, Open Cycle Map, Stamen, Bing, etc.
 @param subDomains used for load balancing tile requests if supported by the service, for eg. a,b,c for Open Cycle Map. If nil the `URLTemplate` should not contain {subDomain}
 @param tileInfo defining the tiling scheme; if nil the Open Street Map tiling scheme is used.
 @param fullExtent of the tiles; if nil the extent of the world in web mercator is used.
 @return initialized web tile layer
 @since 100.1
 */
+(instancetype)webTiledLayerWithURLTemplate:(NSString*)URLTemplate subDomains:(nullable NSArray<NSString*>*)subDomains tileInfo:(nullable AGSTileInfo*)tileInfo fullExtent:(nullable AGSEnvelope*)fullExtent;

#pragma mark -
#pragma mark properties

/** SubDomains used for load balancing tile requests if supported by the service, for eg. a,b,c for Open Cycle Map. If the service does not support subDomains, `URLTemplate` should not contain {subDomain}
 @since 100.1
 */
@property (nonatomic, copy, readonly) NSArray<NSString*> *subDomains;

/** URLTemplate of the tile service such as http://{subDomain}.host.com/{level}/{col}/{row}.png where {level} corresponds to a zoom level, and {col} and {row} represent tile column and row, respectively. The file extension may change depending upon the image format used by the service, and {subDomain} may not be present. This pattern is not required, but is the most common one on the web currently and used by Map Quest, Open Cycle Map, Stamen, Bing, etc. The template URL should be arranged to reflect how the tiles are arranged in the cache or on the server, and can point to a web server (http://) or to a local file cache (file://).

 @since 100.1
 */
@property (nonatomic, copy, readonly) NSString *URLTemplate;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end
