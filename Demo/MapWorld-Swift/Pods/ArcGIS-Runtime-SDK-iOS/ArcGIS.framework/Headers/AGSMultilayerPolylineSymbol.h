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
#import "AGSMultilayerSymbol.h"

@class AGSSymbolLayer;

/** @file AGSMultilayerPolylineSymbol.h */ //Required for Globals API doc

/** @brief A multilayer polyline symbol
 
 Instances of this class represent multilayer polyline symbols. These symbols are composed of multiple layers of symbols which are rendered as one symbol with a polyline geometry. Each symbol layer has its own properties like width, dash patterns which can be combined to create line symbols with special effects. e.g. Solid Road with dashed pattern on top to show divider line.
 
 @since 100.2
 */
@interface AGSMultilayerPolylineSymbol : AGSMultilayerSymbol

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init NS_UNAVAILABLE;

/** Initialize a multilayer polyline symbol based on the provided parameter
 @param symbolLayers A collection of symbol layers that make up the symbol.
 @return Initialized multilayer polyline symbol
 @since 100.5
 */
-(instancetype)initWithSymbolLayers:(NSArray<AGSSymbolLayer*>*)symbolLayers;

/** Initialize a multilayer polyline symbol based on the provided parameter
 @param symbolLayers A collection of symbol layers that make up the symbol.
 @return Initialized multilayer polyline symbol
 @since 100.5
 */
+(instancetype)multilayerPolylineSymbolWithSymbolLayers:(NSArray<AGSSymbolLayer*>*)symbolLayers;

#pragma mark -
#pragma mark properties

/** Width, in DIPs. The value reported is the largest width of all the symbol layers the polyline symbol contains. The width of the symbol is updated when its constituent symbol layers width changes (if there is a new largest layer width). When setting a new width, the width of the largest symbol layer is given the provided value, and all the smaller layers widths are updated proportionately. An individual symbol layer can be given a specific width without affecting the other layers.
 @since 100.2
 */
@property(nonatomic, assign, readwrite) CGFloat width;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end

