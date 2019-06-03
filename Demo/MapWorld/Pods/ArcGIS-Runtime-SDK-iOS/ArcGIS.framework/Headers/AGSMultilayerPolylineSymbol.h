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

/** @file AGSMultilayerPolylineSymbol.h */ //Required for Globals API doc

/** @brief A multilayer polyline symbol
 
 Instances of this class represent multilayer polyline symbols. These symbols are composed of multiple layers of symbols which are rendered as one symbol with a polyline geometry. Each symbol layer has its own properties like width, dash patterns which can be combined to create line symbols with special effects. e.g. Solid Road with dashed pattern on top to show divider line.
 
 @since 100.2
 */
@interface AGSMultilayerPolylineSymbol : AGSMultilayerSymbol

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

@property(nonatomic, assign, readwrite) CGFloat width;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end

