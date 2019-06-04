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

/** @file AGSMultilayerPolygonSymbol.h */ //Required for Globals API doc

/** @brief A multilayer polygon symbol
 
 Instances of this class represent multilayer polygon symbols. These symbols are composed of multiple layers of symbols which are rendered as one symbol with a polygon geometry. Each symbol layer has its own properties like width, height, offset which can be combined to create polygon symbols with special effects. e.g. a polygon with a marker in the middle. 
 
 @since 100.2
 */
@interface AGSMultilayerPolygonSymbol : AGSMultilayerSymbol

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end

