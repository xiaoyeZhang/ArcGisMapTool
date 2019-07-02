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

#import "AGSMarkerSymbolLayer.h"

@class AGSVectorMarkerSymbolElement;

/** @file AGSVectorMarkerSymbolLayer.h */ //Required for Globals API doc

/** @brief A class representing a marker comprising vector graphics.
 
 A class representing a marker comprising vector graphics. It is constructed from a collection of `AGSVectorMarkerSymbolElement` objects which define the building blocks of the vector marker. If it is the sole symbol layer in a `AGSMultilayerPointSymbol`, this symbol layer places a vector marker at the location of the point feature. This symbol layer is similar to the Web Scene specification's IconSymbol3DLayer, when the IconSymbol3DLayer references a primitive shape.
 
 @since 100.5
 */
@interface AGSVectorMarkerSymbolLayer : AGSMarkerSymbolLayer

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init NS_UNAVAILABLE;

/** Initialize a vector marker symbol layer with the provided parameter
 @param vectorMarkerSymbolElements Collection of vector marker symbol elements.
 @return Initialized vector marker symbol layer
 @since 100.5
 */
-(instancetype)initWithVectorMarkerSymbolElements:(NSArray<AGSVectorMarkerSymbolElement*>*)vectorMarkerSymbolElements;

/** Initialize a vector marker symbol layer with the provided parameter
 @param vectorMarkerSymbolElements Collection of vector marker symbol elements.
 @return Initialized vector marker symbol layer
 @since 100.5
 */
+(instancetype)vectorMarkerSymbolLayerWithVectorMarkerSymbolElements:(NSArray<AGSVectorMarkerSymbolElement*>*)vectorMarkerSymbolElements;

#pragma mark -
#pragma mark properties

/**  Collection of vector marker symbol elements held by the vector marker symbol layer
 @since 100.5
 */
@property (nonatomic, copy, readwrite) NSArray<AGSVectorMarkerSymbolElement*> *vectorMarkerSymbolElements;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end
