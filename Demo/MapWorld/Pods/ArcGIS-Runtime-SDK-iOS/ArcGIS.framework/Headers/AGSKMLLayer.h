/*
 COPYRIGHT 2018 ESRI
 
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

#import "AGSLayer.h"
#import "AGSTimeAware.h"

@class AGSKMLDataset;
@class AGSTimeExtent;

/** @file AGSKMLLayer.h */ //Required for Globals API doc

/** @brief A layer that can display KML data
 
 An instance of this class represents a layer based on a KML (Keyhole Markup Language) file (.kml,.kmz file extension). 
 KML is an XML-based container for geographic information. For more information about KML and how to create a KML file,
 please refer to the [Google documentation](http://developers.google.com/kml/documentation). KML data is typically
 composed of one or more KML node elements such as documents, folders, placemarks, network links or overlays -
 arranged hierarchically in a tree structure that's represented by the `AGSKMLDataset`.

 
 A KML Layer can be used to display KML data in both 2D and 3D using an `AGSMapView` or an `AGSSceneView` respectively.
 
 @license{Standard, when using local .kml or .kmz file}
 @ingroup licensing
 @since 100.4
 */
@interface AGSKMLLayer : AGSLayer <AGSTimeAware>

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

/** Initialize this layer with a KML dataset.
 @param The KML dataset.
 @return A new kml layer
 @since 100.4
 */
-(instancetype)initWithKMLDataset:(AGSKMLDataset *)dataset;

/** Initialize this layer with an item representing a KML file or link to a KML resource. The item's type should be `AGSPortalItemTypeKML`.
 @param item representing a KML file or link to a KML resource.
 @return A new kml layer
 @since 100.4
 */
-(instancetype)initWithItem:(AGSItem*)item;

/** Initialize this layer with a KML dataset.
 @param The KML dataset.
 @return A new kml layer
 @since 100.4
 */
+(instancetype)KMLLayerWithKMLDataset:(AGSKMLDataset *)dataset;

/** Initialize this layer with an item representing a KML file or link to a KML resource. The item's type should be `AGSPortalItemTypeKML`.
 @param item representing a KML file or link to a KML resource.
 @return A new kml layer
 @since 100.4
 */
+(instancetype)KMLLayerWithItem:(AGSItem*)item;

#pragma mark -
#pragma mark properties

/** The KML dataset used to create the layer.
 @since 100.4
 */
@property (nonatomic, strong, readonly) AGSKMLDataset *dataset;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end
