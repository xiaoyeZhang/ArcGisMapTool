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
@class AGSDistanceSymbolRange;

/** @file AGSDistanceCompositeSceneSymbol.h */ //Required for Globals API doc

/** @brief A symbol that changes based on distance from the camera
 
 Instances of this class represent a symbol that changes based on the distance, in meters, between the scene viewpoint's camera and the GeoElement that the symbol is assigned to.
 
 A Range links a symbol to a minimum and maximum distance, the symbol is then only visible between that distance. The Ranges then links to the `AGSDistanceCompositeSceneSymbol` which will be used by a GeoElement and display each symbol within it's set distance.
 
 
 @since 100
 */
@interface AGSDistanceCompositeSceneSymbol : AGSSymbol

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

+(instancetype)distanceCompositeSceneSymbol;

#pragma mark -
#pragma mark properties

/** The ranges used by the symbol.
 
 Each range links a symbol to a minimum and maximum distance, the symbol is then only visible between that distance. Ranges in the collection can have the same minimum and maximum distance. They can also have overlapping distances, which will cause their symbols to be displayed simultaneously if the camera is within that distance.
 
 @since 100
 */
@property (nonatomic, copy, readwrite) NSArray<AGSDistanceSymbolRange*> *ranges;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end
