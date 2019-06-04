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

@class AGSItem;
@class AGSLoadableBase;
@class AGSLayer;

#import "AGSLoadableBase.h"
#import "AGSRemoteResource.h"
#import "AGSEnumerations.h"


/** @file AGSBasemap.h */ //Required for Globals API doc

/** @brief A basemap for a map or a scene
 
 Instances of this class represent a basemap for a map or a scene.
 
 A basemap helps orient the user and provides a geographical context for the content you want to display in the scene. It is used for locational reference and provides a framework on which you can overlay operational layers. Thus, the basemap serves as a foundation and provides a framework for working with information geographically. It's content is typically static and does not change frequently. For eg, streets, parcel boundaries, or geographic features such as rivers. Some basemaps also contain reference layers, such as labels, which are drawn on top of operational layers.

 
 ArcGIS Online provides a number of ready-to-use basemaps such as `#streetsBasemap`, `#topographicBasemap`, etc, but you can also create your own basemap by mashing up layers. A basemap is composed of a collection of `#baseLayers`, and `#referenceLayers`. Base layers are displayed at the bottom, and reference layers are displayed at the top, with other operational layers sandwiched between them. The content of a basemap is typically static and does not change frequently.
 
 @since 100
 */
@interface AGSBasemap : AGSLoadableBase <AGSJSONSerializable, NSCopying>

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init;

/** Instantiates a new basemap.
 @param item The item on ArcGIS Online or an on-premise portal that represents a basemap
 @since 100
 */
-(instancetype)initWithItem:(AGSItem*)item;

/** Instantiates a new basemap.
 @param layer The layer to be used as the basemap's base layer
 @since 100
 */
-(instancetype)initWithBaseLayer:(AGSLayer*)layer;

/** Instantiates a new basemap.
 @param baseLayers The layers to be used as the basemap's base layers
 @param referenceLayers The layers to be used as the basemap's reference layers
 @since 100
 */
-(instancetype)initWithBaseLayers:(NSArray<AGSLayer*>*)baseLayers referenceLayers:(nullable NSArray<AGSLayer*>*)referenceLayers;

/** Instantiate a basemap with a URL to a portal item which is a web basemap.
 @param URL of the web basemap on ArcGIS Online or an on-premises portal
 @return The basemap created from the URL, or nil if an invalid URL is passed.
 @since 100.4
 */
-(nullable instancetype)initWithURL:(NSURL*)URL;
    
/** Instantiates a new basemap.
 @since 100
 */
+(instancetype)basemap;

/** Instantiates a new basemap.
 @param item The webmap item on ArcGIS Online or an on-premise portal that represents a basemap
 @note The item must be of type `AGSPortalItemTypeWebMap`
 @since 100
 */
+(instancetype)basemapWithItem:(AGSItem*)item;

/** Instantiates a new basemap.
 @param layer The layer to be used as the basemap's base layer
 @since 100
 */
+(instancetype)basemapWithBaseLayer:(AGSLayer*)layer;

/** Instantiates a new basemap.
 @param baseLayers The layers to be used as the basemap's base layers
 @param referenceLayers The layers to be used as the basemap's reference layers
 @since 100
 */
+(instancetype)basemapWithBaseLayers:(NSArray<AGSLayer*>*)baseLayers referenceLayers:(nullable NSArray<AGSLayer*>*)referenceLayers;

/** Instantiate a basemap with a URL to a portal item which is a web basemap.
 @param URL of the web basemap on ArcGIS Online or an on-premises portal
 @return The basemap created from the URL, or nil if an invalid URL is passed.
 @since 100.4
 */
+(nullable instancetype)basemapWithURL:(NSURL*)URL;
    
/** Instantiates a new basemap based on ArcGIS Online [World Street](http://www.arcgis.com/home/item.html?id=3b93337983e9436f8db950e38a8629af ) basemap.
 @since 100
 */
+(instancetype)streetsBasemap;

/** Instantiates a new basemap based on ArcGIS Online [World Topographic](http://www.arcgis.com/home/item.html?id=30e5fe3149c34df1ba922e6f5bbf808f ) basemap.
 @since 100
 */
+(instancetype)topographicBasemap;

/** Instantiates a new basemap based on ArcGIS Online [World Imagery](http://www.arcgis.com/home/item.html?id=10df2279f9684e4a9f6a7f08febac2a9 ) basemap.
 @since 100
 */
+(instancetype)imageryBasemap;

/** Instantiates a new basemap based on ArcGIS Online [Dark Gray Canvas](http://www.arcgis.com/home/item.html?id=850db44b9eb845d3bd42b19e8aa7a024 ) basemap.
 @since 100
 */
+(instancetype)darkGrayCanvasVectorBasemap;

/** Instantiates a new basemap based on ArcGIS Online [Imagery Hybrid](http://www.arcgis.com/home/item.html?id=28f49811a6974659988fd279de5ce39f ) basemap.
 @since 100
 */
+(instancetype)imageryWithLabelsVectorBasemap;

/** Instantiates a new basemap based on ArcGIS Online [Light Gray Canvas](http://www.arcgis.com/home/item.html?id=0e02e6f86d02455091796eaae811d9b5 ) basemap.
 @since 100
 */
+(instancetype)lightGrayCanvasVectorBasemap;

/** Instantiates a new basemap based on ArcGIS Online [World Navigation Map](http://www.arcgis.com/home/item.html?id=dcbbba0edf094eaa81af19298b9c6247 ) basemap.
 @since 100
 */
+(instancetype)navigationVectorBasemap;

/** Instantiates a new basemap based on OpenStreetMap basemap.
 @since 100
 */
+(instancetype)openStreetMapBasemap;

/** Instantiates a new basemap based on ArcGIS Online [World Street Map (Night)](http://www.arcgis.com/home/item.html?id=bf79e422e9454565ae0cbe9553cf6471 ) basemap.
 @since 100
 */
+(instancetype)streetsNightVectorBasemap;

/** Instantiates a new basemap based on ArcGIS Online [World Street Map](http://www.arcgis.com/home/item.html?id=4e1133c28ac04cca97693cf336cd49ad ) basemap.
 @since 100
 */
+(instancetype)streetsVectorBasemap;

/** Instantiates a new basemap based on ArcGIS Online [Streets (with Relief)](http://www.arcgis.com/home/item.html?id=00f90f3f3c9141e4bea329679b257142 ) basemap.
 @since 100
 */
+(instancetype)streetsWithReliefVectorBasemap;

/** Instantiates a new basemap based on ArcGIS Online [Terrain with Labels](http://www.arcgis.com/home/item.html?id=a52ab98763904006aa382d90e906fdd5 ) basemap.
 @since 100
 */
+(instancetype)terrainWithLabelsVectorBasemap;

/** Instantiates a new basemap based on ArcGIS Online [Topographic](http://www.arcgis.com/home/item.html?id=67372ff42cd145319639a99152b15bc3 ) basemap.
 @since 100
 */
+(instancetype)topographicVectorBasemap;

/** Instantiates a new basemap based on ArcGIS Online [Light Gray Canvas](http://www.arcgis.com/home/item.html?id=8b3d38c0819547faa83f7b7aca80bd76 ) basemap.
 @since 100
 */
+(instancetype)lightGrayCanvasBasemap;

/** Instantiates a new basemap based on ArcGIS Online [Oceans](http://www.arcgis.com/home/item.html?id=6348e67824504fc9a62976434bf0d8d5 ) basemap.
 @since 100
 */
+(instancetype)oceansBasemap;

/** Instantiates a new basemap based on ArcGIS Online [National Geographic World](http://www.arcgis.com/home/item.html?id=b9b1b422198944fbbd5250b3241691b6 ) basemap.
 @since 100
 */
+(instancetype)nationalGeographicBasemap;

/** Instantiates a new basemap based on ArcGIS Online [Imagery with Labels](http://www.arcgis.com/home/item.html?id=716b600dbbac433faa4bec9220c76b3a ) basemap.
 @since 100
 */
+(instancetype)imageryWithLabelsBasemap;

/** Instantiates a new basemap based on ArcGIS Online [Terrain with Labels](http://www.arcgis.com/home/item.html?id=fe44cf9a739848939988addfeba473e4 ) basmap.
 @since 100
 */
+(instancetype)terrainWithLabelsBasemap;

#pragma mark -
#pragma mark properties

/** The name of the basemap
 @since 100
 */
@property (nonatomic, copy, readwrite) NSString *name;

/** The portal item that was used to create the basemap
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSItem *item;

/** The base layers of this basemap. Base layers are displayed at the bottom in a mapview, and reference layers are displayed at the top, with the map's operational layers sandwiched between them. The layers are drawn in a bottom-up fashion with the 0th layer in the list drawn first, next layer drawn on top of the previous one, and so on.
 @note This array does not allow duplicate objects.
 @since 100
 */
@property (nonatomic, strong, readonly) NSMutableArray<AGSLayer*> *baseLayers;

/** The reference layers of this basemap. Base layers are displayed at the bottom in a mapview, and reference layers are displayed at the top, with the map's operational layers sandwiched between them. The layers are drawn in a bottom-up fashion with the 0th layer in the list drawn first, next layer drawn on top of the previous one, and so on.
 @note This array does not allow duplicate objects.
 @since 100
 */
@property (nonatomic, strong, readonly) NSMutableArray<AGSLayer*> *referenceLayers;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end
