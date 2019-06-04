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

#import "AGSServiceImageTiledLayer.h"

@class AGSPortal;

/** @file AGSBingMapsLayer.h */ //Required for Globals API doc

/** @brief A layer based on Bing Maps
 
 An instance of this class represents a Bing maps layer.
 
 A Bing maps layer displays map content from a Bing Maps web service. The service provides access to static map tiles and imagery meta-data. The service requires a Bing maps key. There are 2 ways to specify the Bing maps key to use -
 
 @li From a portal which contains the Bing maps key.
 @li From a developer setting the Bing maps key into the layer.
 
 If the layer does not have a Bing maps key or a Portal where it can get the key, the layer will fail to load. The developer must set the Bing maps key or portal and then retry loading so the layer can get the Bing map key.
 
 @note Usage of Bing Maps layer in ArcGIS Runtime requires adherence to [Microsoft's Mobile Brand Guidelines](http://links.esri.com/runtime/bing_guidelines)
 
 @since 100.1
 @see  [Information about Portal having a Bing maps Key](http://resources.arcgis.com/en/help/arcgis-rest-api/index.html#//02r3000001m7000000)
 */
 @interface AGSBingMapsLayer : AGSServiceImageTiledLayer
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

/** Initialize the layer with the provided Bing Maps key and map style
@param key to access the Bing Maps service
@param style The map style
@returns An initialized Bing Maps layers
@since 100.1
*/
-(instancetype)initWithKey:(NSString*)key style:(AGSBingMapsLayerStyle)style;

/** Initialize the layer with the provided ArcGIS portal and map style
 @param portal containing a key to access the Bing Maps service
 @param style The map style
 @returns An initialized Bing Maps layers
 @since 100.1
 */
-(instancetype)initWithPortal:(AGSPortal*)portal style:(AGSBingMapsLayerStyle)style;

/** Initialize the layer with the provided Bing Maps key and map style
 @param key to access the Bing Maps service
 @param style The map style
 @returns An initialized Bing Maps layers
 @since 100.1
 */
+(instancetype)bingMapsLayerWithKey:(NSString*)key style:(AGSBingMapsLayerStyle)style;

/** Initialize the layer with the provided ArcGIS portal and map style
 @param portal containing a key to access the Bing Maps service
 @param style The map style
 @returns An initialized Bing Maps layers
 @since 100.1
 */
+(instancetype)bingMapsLayerWithPortal:(AGSPortal*)portal style:(AGSBingMapsLayerStyle)style;

#pragma mark -
#pragma mark properties

/** The locale in which to display map labels.
@since 100.1
*/
@property (nonatomic, strong, readwrite) NSLocale *locale;

/** Key to access the Bing Maps service.
 @since 100.1
 */
@property (nonatomic, copy, readwrite) NSString *key;

/** ArcGIS Portal containing a key to access the Bing Maps service
 @since 100.1
 */
@property (nullable, nonatomic, strong, readonly) AGSPortal *portal;

/** The layer's map style
 @since 100.1
 */
@property (nonatomic, assign, readonly) AGSBingMapsLayerStyle style;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END
@end
