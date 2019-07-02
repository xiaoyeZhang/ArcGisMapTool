/*
 COPYRIGHT 2019 ESRI
 
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

@class AGSGeometry;
@class AGSMultilayerSymbol;

/** @file AGSVectorMarkerSymbolElement.h */ //Required for Globals API doc

/** @brief A class representing a component of a vector marker. A single instance of `AGSVectorMarkerSymbolElement` is a combination of a symbol and a geometry.
 
 The symbol held by the element is itself an instance of `AGSMultilayerSymbol`. The geometry of the element does not pertain to the geography of the Map or Scene. Rather, the geometry property describes the shape of the `#symbol`. The coordinate values defining the geometry are in points. This behavior facilitates creating a custom vector marker symbol element of custom shape and symbol, then combining it with zero or more other elements to form a vector marker.
 
 When rendering, the symbol draws according to the shape of the geometry, which is defined relative to other elements in the layer. (The coordinates used to define element geometry are not in real units.)
 
 To create a red square, for example, construct an instance `AGSVectorMarkerSymbolElement` with a `AGSMultilayerPolygonSymbol` that contains a red `AGSSolidFillSymbolLayer` and a square geometry. When combined in a `AGSVectorMarkerSymbolElement` and placed in a `AGSVectorMarkerSymbolLayer` a red square displays.
 
 The symbol and geometry properties must create a meaningful combination to have a visual effect. For example, a `AGSMultilayerPolygonSymbol` does not draw anything if the corresponding geometry is a point, but does draw if the geometry is a polygon.
 
 @since 100.5
 */
@interface AGSVectorMarkerSymbolElement : AGSObject

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

- (instancetype)init NS_UNAVAILABLE;

/** Initialize a vector marker symbol element with the provided parameters
  @param geometry Geometry that defines the shape of the symbol.
  @param multilayerSymbol The element's symbol
  @return Initialized vector marker symbol element
  @since 100.5
 */
-(instancetype)initWithGeometry:(AGSGeometry *)geometry
               multilayerSymbol:(AGSMultilayerSymbol *)multilayerSymbol;

/** Initialize a vector marker symbol element with the provided parameters
 @param geometry Geometry that defines the shape of the symbol.
 @param multilayerSymbol The element's symbol
 @return Initialized vector marker symbol element
 @since 100.5
 */
+(instancetype)vectorMarkerSymbolElementWithGeometry:(AGSGeometry *)geometry
                                    multilayerSymbol:(AGSMultilayerSymbol *)multilayerSymbol;

#pragma mark -
#pragma mark properties

/**  The geometry of the vector marker symbol element. When setting a geometry, the corresponding symbol must be appropriate for the desired drawing effect. For instance, a polygon geometry would pair best with a `AGSMultilayerPolygonSymbol` and would draw the symbol with the polygon geometry.
 @note The coordinates used to define the geometry are not in real units. Rather, their values are used for scaling the elements relative to each other and defining their shape.
 @since 100.5
 */
@property (nullable, nonatomic, strong, readwrite) AGSGeometry *geometry;

/**  The symbol of the vector marker symbol element. The symbol, an instance of `AGSMultilayerSymbol` can be any arbitrary multilayer symbol. When setting a geometry, the corresponding symbol must be appropriate for the desired drawing effect. For instance, an instance of `AGSMultilayerPolygonSymbol` would pair best with a polygon geometry and would draw the symbol with the polygon geometry.
 @since 100.5
 */
@property (nullable, nonatomic, strong, readwrite) AGSMultilayerSymbol *symbol;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end
