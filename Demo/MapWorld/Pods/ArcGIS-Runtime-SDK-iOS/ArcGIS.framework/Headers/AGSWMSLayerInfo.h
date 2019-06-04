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

@class AGSEnvelope;
@class AGSSpatialReference;
@class AGSWMSLayerInfo;

/** @file AGSWMSLayerInfo.h */ //Required for Globals API doc

/** @brief Information about a layer in an OGC-WMS service
 
 An instance of this class represents information about an individual layer in an OGC-WMS service.
 
 @since 100.2
 */
@interface AGSWMSLayerInfo : AGSObject

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** A brief narrative description of the layer.
 @since 100.2
 */
@property (nonatomic, copy, readonly) NSString *layerDescription;

/** The geographic extent this layer covers
 @since 100.2
 */
@property (nullable, nonatomic, strong, readonly) AGSEnvelope *extent;

/** A value indicating the height (in points) of map images the service is capable of producing. When present and nonzero, it indicates that the server is not able to produce a map image at a height different from the fixed height indicated.
 @since 100.2
 */
@property (nonatomic, assign, readonly) NSInteger fixedImageHeight;

/** A value indicating the width (in points) of map images the service is capable of producing. When present and nonzero, it indicates that the server is not able to produce a map image at a width different from the fixed width indicated.
 @since 100.2
 */
@property (nonatomic, assign, readonly) NSInteger fixedImageWidth;

/** List of keywords describing the layer
 @since 100.2
 */
@property (nonatomic, copy, readonly) NSArray<NSString*> *keywords;

/** Name of the layer. Layers may have a name and a `#title`. Only layers with a name are displayable. Layers with only a title are categories for other layers. Layers with a name may also have children; displaying these layers will display all sublayers.
 @since 100.2
 */
@property (nonatomic, copy, readonly) NSString *name;

/** Indicates if the layer is opaque and obscures content of other layers below it. It describes the layer's data content, not the picture format of the map image. A true value indicates that the map data are mostly or completely opaque. A false value indicates that the map data represent vector features that probably do not completely fill space. In practice, a layer with opaque set to true is a good candidate for use as a basemap.
 @since 100.2
 */
@property (nonatomic, assign, readonly, getter=isOpaque) BOOL opaque;

/** Indicates whether the layer is queryable or not.
 @since 100.2
 */
@property (nonatomic, assign, readonly, getter=isQueryable) BOOL queryable;

/** The spatial reference of the layer
 @since 100.2
 */
@property (nonatomic, copy, readonly) NSArray<AGSSpatialReference*> *spatialReferences;

/** Available styles for the layer. Styles are server-defined options for how the layer and its information are displayed. Note that the order of styles returned does not indicate which style is the default.
 @since 100.2
 */
@property (nonatomic, copy, readonly) NSArray<NSString*> *styles;

/** Sublayers of this layer.
 @since 100.2
 */
@property (nonatomic, strong, readonly) NSMutableArray<AGSWMSLayerInfo*> *sublayerInfos;

/** Title of the layer. The title property is intended for use as a human-readable layer identification. The title is not unique. Note also that a layer with a title but no name describes a category for use as a container for sublayers.
 @since 100.2
 */
@property (nonatomic, copy, readonly) NSString *title;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end

