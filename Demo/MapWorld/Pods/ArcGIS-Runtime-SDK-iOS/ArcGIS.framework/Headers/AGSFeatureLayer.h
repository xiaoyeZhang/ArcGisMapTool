/*
 COPYRIGHT 2015 ESRI
 
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
#import "AGSLayer.h"
#import "AGSPopupSource.h"
#import "AGSTimeAware.h"

@class AGSFeatureTable;
@class AGSRenderer;
@class AGSColor;
@class AGSFeature;
@class AGSQueryParameters;
@class AGSFeatureQueryResult;
@class AGSItem;
@class AGSLabelDefinition;
@class AGSLayerSceneProperties;

/** @file AGSFeatureLayer.h */ //Required for Globals API doc

/** @brief A layer that can display features on a map or a scene
 
 Instances of this class represent a feature layer. Feature layers can display features from an `AGSFeatureTable` on a map using `AGSMapView` or a scene using `AGSSceneView`. The feature table represents feature data either in a remote ArcGIS Feature Service or in a local geodatabase on disk.
 
 Feature layer adopts the loadable pattern; many of its properties are initialized asynchronously. See `AGSLoadable` for more information.
 
 The feature layer has a load dependency on its `#featureTable` from where it gets information about itself such as min/max scale, renderer, etc. Calling `AGSLoadable#loadWithCompletion:` on the feature layer initiates loading of its `#featureTable` too.
 
 @see @c AGSFeatureTable
 @since 100
 */
@interface AGSFeatureLayer : AGSLayer <AGSPopupSource, AGSTimeAware>

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

/** Initialize the layer with the given @c AGSFeatureTable
 @param featureTable The backing dataset whose features need to be drawn on the map by this layer.
 @since 100
*/
-(instancetype)initWithFeatureTable:(AGSFeatureTable *)featureTable;

/** Initialize a new feature layer
 @return A new initialized feature layer
 @since 100
 @deprecated 100.1. Use `#initWithFeatureTable:`  or `#initWithItem:layerID:` instead.
*/
-(instancetype)init __deprecated_msg("Please use initWithFeatureTable: or initWithItem:layerID:");

/** Initialize the layer with the provided information
 @param item representing an ArcGIS Feature Serivce. The item's type must be `AGSPortalItemTypeFeatureService`
 @param layerID ID of an individual layer in the ArcGIS Feature service represented by the `item`
 @return Initialized layer
 @since 100
 */
-(instancetype)initWithItem:(AGSItem*)item layerID:(NSInteger)layerID;

/** Initialize the layer with the provided information
 @param item representing an ArcGIS Feature Serivce. The item's type must be `AGSPortalItemTypeFeatureService`
 @param layerID ID of an individual layer in the ArcGIS Feature service represented by the `item`
 @return Initialized layer
 @since 100
 */
+(instancetype)featureLayerWithItem:(AGSItem*)item layerID:(NSInteger)layerID;

/** Initialize a new feature layer
 @return A new initialized feature layer
 @since 100
 @deprecated 100.1. Use `#featureLayerWithFeatureTable:`  or `#featureLayerWithItem:layerID:` instead.
 */
+(instancetype)featureLayer __deprecated_msg("Please use featureLayerWithFeatureTable: or featureLayerWithItem:layerID:");

/** Initialize the layer with the given @c AGSFeatureTable
 @param featureTable The backing dataset whose features need to be drawn on the map by this layer.
 @since 100
 */
+(instancetype)featureLayerWithFeatureTable:(AGSFeatureTable*)featureTable;

#pragma mark -
#pragma mark properties 

/** The definition expression in the syntax of a SQL where clause by which to limit which features are displayed on the map.
 @since 100
 */
@property (nonatomic, copy, readwrite) NSString *definitionExpression;

/** Indicates whether or not features will be labelled on this layer.
 @since 100
 */
@property (nonatomic, assign, readwrite) BOOL labelsEnabled;

/** The renderer specifying how the features should be symbolized
 @since 100
 */
@property (nullable, nonatomic, strong, readwrite) AGSRenderer *renderer;

/** Mode used for rendering this layer. `Static` mode is better suited for displaying large datasets (in terms of number of vertices) and for complex symbology because it does not update the layer's display while pan/zoom operations are in progress. `Dynamic` mode is better suited for smaller datasets that are updating frequently or for more interactive experience as the layer's display is updated continuously while pan/zoom operations are in progress.
 @since 100.2
 @see `AGSLoadSettings` to specify rendering mode for all feature layers in a map or scene
 */
@property (nonatomic, assign, readwrite) AGSFeatureRenderingMode renderingMode;

/** Properties to apply only when rendering data in 3D scenes using `AGSSceneView`
 @since 100.2
 */
@property (nullable, nonatomic, strong, readwrite) AGSLayerSceneProperties *sceneProperties;

/** The color to use for drawing a halo around selected features. Defaults to cyan color.
 @since 100
 @deprecated 100.4 Use `color` property exposed through `AGSGeoView#selectionProperties`
 */
@property (nullable, nonatomic, strong, readwrite) AGSColor *selectionColor __deprecated_msg("Please use 'color' property exposed through 'selectionProperties' property in AGSGeoView");

/** The width (in points) of the selection halo
 @since 100
 @deprecated 100.4 This property will be removed in a future version
 */
@property (nonatomic, assign, readwrite) double selectionWidth __deprecated_msg("This property will be removed in a future version");

/** The backing dataset whose features are drawn on the map by this layer.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSFeatureTable *featureTable;

/** Defines how labels should be displayed.
 @since 100.1
 */
@property (nonatomic, strong, readonly) NSMutableArray<AGSLabelDefinition*> *labelDefinitions;

/** Time interval (in seconds) specifying how often the layer should auto-refresh its contents. If 0 or less is specified, the layer will not auto-refresh.
 @since 100.1
 */
@property (nonatomic, assign, readwrite) NSTimeInterval refreshInterval;

#pragma mark -
#pragma mark methods

/** Reset the visibility of all features back to their original state
 @since 100
 */
-(void)resetFeaturesVisible;

/** Reset the `#renderer` back to the original renderer provided by the `#featureTable`.
 This is useful if you, for instance, change the renderer and then want to revert back to the original.
 @since 100
 */
-(void)resetRenderer;

/** Change the visibility of the specified feature. The map or scene is redrawn to reflect the change.
 @param feature to change
 @param visible If true, feature is made visible. If false, feature is hidden
 @since 100
 @note Use `#setFeatures:visible:` to change the visibility of a group of features together. It provides better performance as the map will only need to be updated once.
 */
-(void)setFeature:(AGSFeature *)feature visible:(BOOL)visible;

/** Change the visibility of the specified features. The map or scene is updated to reflect the change.
 @param features to change
 @param visible If true, features are made visible. If false, features are hidden
 @since 100
 */
-(void)setFeatures:(NSArray<AGSFeature*> *)features visible:(BOOL)visible;

/** Clears selection on all features.
 @since 100
 */
-(void)clearSelection;

/** Retrieve the list of features that have selection enabled.
 @param completion block that is invoked with the results, or an error if one is encountered.
 @return operation which can be canceled
 @since 100
 */
-(id<AGSCancelable>)getSelectedFeaturesWithCompletion:(void(^)(AGSFeatureQueryResult *__nullable featureQueryResult, NSError *__nullable error))completion;

/** Select the specified feature. The map or scene will be updated to render the feature with `#selectionColor`
 @param feature to select
 @since 100
 @see `#selectionColor`
 @note Use `#selectFeatures:` to enable selection on a group of features together. It provides better performance as the map will only need to be updated once.
 */
-(void)selectFeature:(AGSFeature *)feature;

/** Select the specified features. The map or scene will be updated to highlight the features with `#selectionColor` (cyan by default).
 @param features to select
 @since 100
 @see `#selectionColor`
 */
-(void)selectFeatures:(NSArray<AGSFeature*> *)features;

/** Select features that match the query criteria. The map or scene will be updated to highlight the features with `#selectionColor` (cyan by default).
 @param parameters defining which features should be considered
 @param mode defining how selection needs to be applied to the features
 @param completion block that is invoked with the results, or an error if one is encountered.
 @return operation which can be canceled
 @since 100
 */
-(id<AGSCancelable>)selectFeaturesWithQuery:(AGSQueryParameters *)parameters mode:(AGSSelectionMode)mode completion:(nullable void (^)(AGSFeatureQueryResult *__nullable featureQueryResult, NSError *__nullable error))completion;


/** Clear selection on the specified feature. The map or scene will be redrawn to reflect the change.
 @param feature to unselect
 @since 100
 @note Use `#unselectFeatures:` to disable selection on a group of features together. It provides better performance as the map will only need to be updated once.
 */
-(void)unselectFeature:(AGSFeature *)feature;

/** Clear selection on the specified features. The map or scene will be redrawn to reflect the change.
 @param features to unselect
 @since 100
 */
-(void)unselectFeatures:(NSArray<AGSFeature*> *)features;

NS_ASSUME_NONNULL_END

@end
