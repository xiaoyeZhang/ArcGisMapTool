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

#import "AGSSymbol.h"

/** @file AGSCompositeSymbol.h */ //Required for Globals API doc

/** @brief A symbol composed of multiple symbols
 
 Instances of this class represent composite symbols. Composite symbols are simply a combination of two or more symbols. Each symbol can represent the same or a different visual aspect, for example the fill, outline, vertex,etc.
 
 For example, consider a composite symbol of an `AGSSimpleMarkerSymbol` and an `AGSSimpleFillSymbol`. A polygon displayed with this composite symbol would display the marker at each vertex along the polygon, and fill the interior space of each ring in the polygon.
 
 @since 100
 */
@interface AGSCompositeSymbol : AGSSymbol

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

/** Initialize the composite symbol with the provided symbols
 @param symbols The individual symbols which make up this composite symbol. The symbols are drawn in the order they are stored in the array. The 0th symbol is drawn first, then the next symbol is drawn on top of it, and so on.
 @since 100
 @return initialized composite symbol
 */
-(instancetype)initWithSymbols:(NSArray<AGSSymbol*> *)symbols;

/** Initialize an empty composite symbol. 
 @since 100
 @return initialized composite symbol
 */
+(instancetype)compositeSymbol;

/** Initialize the composite symbol with the provided symbols
 @param symbols The individual symbols which make up this composite symbol. The symbols are drawn in the order they are stored in the array. The 0th symbol is drawn first, then the next symbol is drawn on top of it, and so on.
 @since 100
 @return initialized composite symbol
 */
+(instancetype)compositeSymbolWithSymbols:(NSArray<AGSSymbol*> *)symbols;

#pragma mark -
#pragma mark RTCCompositeSymbol methods

#pragma mark -
#pragma mark properties

/** The individual symbols which make up this composite symbol. The symbols are drawn in the order they are stored in the array. The 0th symbol is drawn first, then the next symbol is drawn on top of it, and so on.
 @since 100
 */
@property (nonatomic, copy, readwrite) NSArray<AGSSymbol*> *symbols;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end

