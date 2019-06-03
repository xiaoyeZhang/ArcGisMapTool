/*
 COPYRIGHT 2013 ESRI
 
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

@class AGSLayer;
@class AGSPortalItem;
@class AGSBasemap;
@class AGSEnvelope;
@class AGSPortal;
@class AGSPortalFolder;
@class AGSViewpoint;
@class AGSItem;
@class AGSBookmark;
@class AGSTransportationNetworkDataset;
@class AGSFeatureTable;
@class AGSLoadSettings;

/** @file AGSMap.h */ //Required for Globals API doc

/** @brief A map containing 2D geographic content
 
 Instance of this class represent a map. It can be displayed on the screen by `AGSMapView`.
 Thus, a map represents the model in an MVC architecture, and a mapview represents the view.  A map specifies how the geographic data is organized, and a mapview renders the data and allows users to interact with it.
 
 Conceptually, a map's geographic content is derived from its `#basemap` and `#operationalLayers`.
 
 A basemap helps orient the user and provides a geographical context for the content you want to display in the map. It is used for locational reference and provides a framework on which you can overlay operational layers. Thus, the basemap serves as a foundation and provides a framework for working with information geographically. It's content is typically static and does not change frequently. For eg, streets, parcel boundaries, or geographic features such as rivers. Some basemaps also contain reference layers, such as labels, which are drawn on top of operational layers.
 
 Operational layers provide content that is of unique interest to the application and the task at hand. Their content might change frequently. For eg earthquakes, traffic, or the weather.
 
 The map has a `#spatialReference` which specifies how the geographic content from its basemap and operational layers is aligned when combined together.
 
 @see `AGSScene` for 3D geographic content
 @since 100
 */
@interface AGSMap : AGSLoadableBase <AGSJSONSerializable, NSCopying>

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

/** Instantiates an empty map. To add content to the map, refer to `#basemap` and `operationalLayers`
 @since 100
 */
-(instancetype)init;

/** Instantiates an empty map with the given spatial reference. To add content to the map, refer to `#basemap` and `operationalLayers`
 @param spatialReference to instantiate the map with
 @since 100
 */
-(instancetype)initWithSpatialReference:(AGSSpatialReference*)spatialReference;

/** Instantiates a map with the given basemap
 @param basemap to use with the map
 @since 100
 */
-(instancetype)initWithBasemap:(AGSBasemap*)basemap;

/** Instantiate a map based on the given web map item.
 @param item that represents a web map on ArcGIS Online or an on-premises portal. Item's type must be `AGSPortalItemTypeWebMap`
 @since 100
 */
-(instancetype)initWithItem:(AGSItem*)item;

/** Instantiate a map based on the given web map URL.
 The URL you pass can be one of three basic types. Examples of these types are:
   @li Item details page: https://www.arcgis.com/home/item.html?id=66285814d09f43529d1a2be679393afa
   @li Map viewer page: https://www.arcgis.com/home/webmap/viewer.html?webmap=66285814d09f43529d1a2be679393afa
   @li Item's rest endpoint: https://www.arcgis.com/sharing/rest/content/items/66285814d09f43529d1a2be679393afa
 @param URL of the web map on ArcGIS Online or an on-premises portal
 @return The map created from the URL, or nil if an invalid URL is passed.
 @since 100
 */
-(nullable instancetype)initWithURL:(NSURL*)URL;

/** Instantiates a map with a given basemap type, latitude, longitude and level of detail
 @param latitude Latitude for map to start out at initially
 @param longitude Longitude for map to start out at initially
 @param levelOfDetail The level of detail for the map to start out at initially
 @since 100
 */
-(instancetype)initWithBasemapType:(AGSBasemapType)basemapType latitude:(double)latitude longitude:(double)longitude levelOfDetail:(NSInteger)levelOfDetail;

/** Instantiates an empty map. To add content to the map, refer to `#basemap` and `operationalLayers`
 @since 100
 */
+(instancetype)map;

/** Instantiates an empty map with the given spatial reference. To add content to the map, refer to `#basemap` and `operationalLayers`
 @param spatialReference to instantiate the map with
 @since 100
 */
+(instancetype)mapWithSpatialReference:(AGSSpatialReference*)spatialReference;

/** Instantiates a map to use the given basemap
 @param basemap to use with the map
 @since 100
 */
+(instancetype)mapWithBasemap:(AGSBasemap*)basemap;

/** Instantiate a map based on the given web map item.
 @param item that represents a web map on ArcGIS Online or an on-premises portal. Item's type must be `AGSPortalItemTypeWebMap`
 @since 100
 */
+(instancetype)mapWithItem:(AGSItem*)item;

/** Instantiates a map with a given basemap type, latitude, longitude and level of detail
 @param latitude Latitude for map to start out at initially
 @param longitude Longitude for map to start out at initially
 @param levelOfDetail The level of detail for the map to start out at initially
 @since 100
 */
+(instancetype)mapWithBasemapType:(AGSBasemapType)basemapType latitude:(double)latitude longitude:(double)longitude levelOfDetail:(NSInteger)levelOfDetail;

/** Instantiate a map based on the given web map URL.
 The URL you pass can be one of three basic types. Examples of these types are:
   @li Item details page: https://www.arcgis.com/home/item.html?id=66285814d09f43529d1a2be679393afa
   @li Map viewer page: https://www.arcgis.com/home/webmap/viewer.html?webmap=66285814d09f43529d1a2be679393afa
   @li Item's rest endpoint: https://www.arcgis.com/sharing/rest/content/items/66285814d09f43529d1a2be679393afa
 @param URL of the web map on ArcGIS Online or an on-premises portal
 @return The map created from the URL, or nil if an invalid URL is passed.
 @since 100
 */
+(nullable instancetype)mapWithURL:(NSURL*)URL;

#pragma mark -
#pragma mark properties

/** The web map item that was used to create the map (if any)
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSItem *item;

/** The transportation networks associated with the map. Only applies to maps inside a Mobile Map Package (.mmpk file) which also includes transportation networks.
@since 100
*/
@property (nonatomic, copy, readonly) NSArray<AGSTransportationNetworkDataset*> *transportationNetworks;

/** The web map specification version that the output of `#toJSON` will comply with.
 This applies to how the map is persisted.
 @since 100
 */
@property (nonatomic, copy, readonly) NSString *version;

/** The map's basemap
 @since 100
 */
@property (nonatomic, strong, readwrite) AGSBasemap *basemap;

/** The map's operational layers. These layers are displayed in a mapview sandwiched between a basemap's `baseLayers` at the bottom and `referenceLayers` at the top. The layers are drawn in a bottom-up fashion with the 0th layer in the list drawn first, next layer drawn on top of the previous one, and so on.
 @note This array does not allow duplicate objects.
 @since 100
 */
@property (nonatomic, strong, readonly) NSMutableArray<AGSLayer*> *operationalLayers;

/** List of non-spatial tables associated with the map. These tables typically participate in one or more relationships with feature layers in the map's operational layers.
 @see `AGSArcGISFeatureTable#queryRelatedFeaturesForFeature:parameters:completion:` for performing related queries.
 @since 100.1
 */
@property (nonatomic, strong, readonly) NSMutableArray<AGSFeatureTable*> *tables;

/** The minimum scale that this map will be visible at. A value of zero indicates that there is no minimum scale and the user can zoom out indefinitely.
 @since 100
 */
@property (nonatomic, assign, readwrite) double minScale;

/** The maximum scale that this map will be visible at. A value of zero indicates that there is no maximum scale and the user can zoom in indefinitely.
 @since 100
 */
@property (nonatomic, assign, readwrite) double maxScale;

/** The map's spatial reference. 
 
 Spatial references define where coordinates are located on the earth's surface and how the geographic content from the basemap and operational layers is aligned when combined together.
 
 If a spatial reference wasn't provided when the map was instantiated, it is typically derived from the bottom-most base layer in the basemap. If the map does not have a basemap or if the basemap is empty, the spatial reference is derived from the bottom-most operational layer.
 
 If the spatial reference of layers is different from that of the map, the layers must be reprojected to the spatial reference of the map before displaying. Some layers may not be able to re-project their data, for example layers based on tiles that have been pre-generated ahead of time. To maximize performance, avoid reprojection entirely by ensuring all layers have the same spatial reference as the map.
 
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSSpatialReference *spatialReference;

/** The bookmarks associated with the map
 @note This array does not allow duplicate objects.
 @since 100
 */
@property (nonatomic, strong, readonly) NSMutableArray<AGSBookmark*> *bookmarks;

/** The map's initial viewpoint. This is the area initially displayed by an `AGSMapView` when the map is used.
 @since 100
 */
@property (nullable, nonatomic, strong, readwrite) AGSViewpoint *initialViewpoint;

/** Settings that are applied to layers when the map is loaded. Making changes to the settings after the map is already loaded has no effect.
 @since 100.2
 */
@property (nonatomic, strong, readwrite) AGSLoadSettings *loadSettings;

#pragma mark - Save/SaveAs

/** Saves this map as a new web map on the specified portal with the given title in the given folder.
 Once completed, the map's `#item` property will be populated with the new portal item.
 Note that if the map already has a valid item property (either because the map was created using an item or was previously saved),
 that property will be replaced with a new item, effecitively 'duplicating' the map on the portal.
 @param title The title of the map.  Cannot be nil.
 @param portal The portal to save the map to.
 @param tags The tags to be associated with the newly created portal item.
 @param folder The folder in which to save the map. If nil is passed it will be added to the user's root folder.
 @param itemDescription The description of the map.
 @param thumbnail The thumbnail of the map. The recommended thumbnail image size is 200 pixels wide by 133 pixels high. Acceptable image formats are PNG, GIF, and JPEG with a maximum file size of 1 MB
 @param forceSaveToSupportedVersion Flag to indicate whether the map should be saved to the supported webmap version that the API supports (see system requirements). This may cause data loss as unknown data is not saved. If @c YES, unknown data will be removed and the map
 will be saved. If @c NO, the operation will fail if the map contains unknown data that will not be saved. This flag can be used to provide a warning to users that some map data may be lost when the map is saved.
 @param completion The block that is invoked when operation finishes.
 @return operation which can be canceled
 @license{Basic}
 @ingroup licensing
 @since 100
 */
-(id<AGSCancelable>)saveAs:(NSString *)title
                     portal:(AGSPortal *)portal
                       tags:(NSArray<NSString*> *)tags
                     folder:(nullable AGSPortalFolder *)folder
            itemDescription:(NSString*)itemDescription
                  thumbnail:(nullable AGSImage *)thumbnail
forceSaveToSupportedVersion:(BOOL)forceSaveToSupportedVersion
                 completion:(nullable void(^)(NSError * __nullable error))completion;

/** Saves this map back to the item it originated from.  Upon completion, the item's data will have been updated with the map.
 An error will occur if the map does not have a valid `#item` property.  A map has a valid item property if it was created using either `#initWithItem:` or `#initWithURL:`,
 or has been previously saved as a new item using `#saveAs:portal:tags:folder:itemDescription:thumbnail:forceSaveToSupportedVersion:completion:`.
 @warning This will overwrite contents of the existing map item.
 @param forceSaveToSupportedVersion Flag to indicate whether the map should be saved to the supported webmap version that the API supports (see system requirements). This may cause data loss as unknown data is not saved. If @c YES, unknown data will be removed and the map
 will be saved. If @c NO, the operation will fail if the map contains unknown data that will not be saved. This flag can be used to provide a warning to users that some map data may be lost when the map is saved.
 @param completion block that is invoked when operation finishes.
 @return operation which can be canceled
 @license{Basic}
 @ingroup licensing
 @since 100
 */
-(id<AGSCancelable>)saveWithForceSaveToSupportedVersion:(BOOL)forceSaveToSupportedVersion
                                             completion:(nullable void(^)(NSError * __nullable error))completion;

NS_ASSUME_NONNULL_END

@end

