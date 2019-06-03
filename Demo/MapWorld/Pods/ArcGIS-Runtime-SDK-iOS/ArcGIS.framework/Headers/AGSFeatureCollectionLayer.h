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

#import "AGSLayer.h"

@class AGSFeatureCollection;
@class AGSFeatureLayer;


/** @file AGSFeatureCollectionLayer.h */ //Required for Globals API doc

/** @brief A layer that can display features from a feature collection
 
 Instances of this class represent a layer that can display features from a feature collection on a map using `AGSMapView` or a scene using `AGSSceneView`. This layer aggregates a number of sub-layers, each of which is responsible for displaying features from an individual feature collection table in the feature collection.
 
 @since 100
 @see `AGSFeatureCollection` 
 */
@interface AGSFeatureCollectionLayer : AGSLayer

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

/** Initialize the layer with a feature collection
 @param featureCollection The collection of features that will be displayed by this layer.
 @return Initialized feature collection layer
 @since 100
 */
-(instancetype)initWithFeatureCollection:(AGSFeatureCollection *)featureCollection;

/** Initialize the layer with a feature collection
 @param featureCollection The collection of features that will be displayed by this layer.
 @return Initialized feature collection layer
 @since 100
 */
+(instancetype)featureCollectionLayerWithFeatureCollection:(AGSFeatureCollection *)featureCollection;

#pragma mark -
#pragma mark properties

/** The collection of features that will be displayed by this layer
 @since 100
 */
@property (nonatomic, strong, readonly) AGSFeatureCollection *featureCollection;

/** The sub-layers that are responsible for displaying features from individual feature collection tables in the feature collection.
@since 100
 */
@property (nonatomic, copy, readonly) NSArray<AGSFeatureLayer*> *layers;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end
