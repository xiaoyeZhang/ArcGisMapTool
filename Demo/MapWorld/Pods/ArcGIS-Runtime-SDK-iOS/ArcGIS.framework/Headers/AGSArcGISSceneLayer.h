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

#import "AGSObject.h"
#import "AGSLayer.h"
#import "AGSRemoteResource.h"

@class AGSFeature;
@class AGSFeatureQueryResult;
@class AGSFeatureTable;

/** @file AGSArcGISSceneLayer.h */ //Required for Globals API doc

/** @brief A layer that can display 3D features from an ArcGIS Scene service
 
 An instance of this class represents a layer that can display 3D features in a scene using `AGSSceneView`. The features are provided by an ArcGIS Scene service such as http://scene.arcgis.com/arcgis/rest/services/Hosted/Building_Basel/SceneServer or a local scene layer package (.slpk file).
 
 Features are rendered according to their distance from the viewpoint's camera; thus, features closer to the camera are more detailed.
 
 @since 100
 */
@interface AGSArcGISSceneLayer : AGSLayer <AGSRemoteResource>

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

/** Initialize this layer with a URL to an individual layer in an ArcGIS Scene Service, e.g. http://scene.arcgis.com/arcgis/rest/services/Hosted/Building_Basel/SceneServer/layers/0 or a URL to scene layer package (.slpk file) on disk.
 @param url URL to an individual layer in an ArcGIS Scene Service or a scene layer package (.slpk file) on disk
 @return A new scene layer
 @since 100
 */
-(instancetype)initWithURL:(NSURL *)url;

/** Initialize this layer with an item representing an individual layer in an ArcGIS Scene Service. The item's type should be `AGSPortalItemTypeSceneService`
 @param item representing a layer in an ArcGIS Scene service
 @return A new scene layer.
 @since 100
 */
-(instancetype)initWithItem:(AGSItem*)item;

/** Initialize this layer with the name of a scene layer package within the application bundle or shared documents directory.
 @param name of the scene layer package (without the .slpk file extension) within the application bundle or shared documents directory.
 @return A new scene layer.
 @since 100.1
 */
-(instancetype)initWithName:(NSString*)name;

/** Initialize this layer with an item representing an individual layer in an ArcGIS Scene Service. The item's type should be `AGSPortalItemTypeSceneService`
 @param item representing a layer in an ArcGIS Scene service
 @return A new scene layer.
 @since 100
 */
+(instancetype)ArcGISSceneLayerWithItem:(AGSItem*)item;

/** Initialize this layer with a URL to an individual layer in an ArcGIS Scene Service, e.g. http://scene.arcgis.com/arcgis/rest/services/Hosted/Building_Basel/SceneServer/layers/0 or a URL to scene layer package (.slpk file) on disk.
 @param url URL to an individual layer in an ArcGIS Scene Service or a scene layer package (.slpk file) on disk
 @return A new scene layer
 @since 100
 */
+(instancetype)ArcGISSceneLayerWithURL:(NSURL *)url;

/** Initialize this layer with the name of a scene layer package within the application bundle or shared documents directory.
 @param name of the scene layer package (without the .slpk file extension) within the application bundle or shared documents directory.
 @return A new scene layer.
 @since 100.1
 */
+(instancetype)ArcGISSceneLayerWithName:(NSString*)name;

#pragma mark -
#pragma mark properties

@property (nullable, nonatomic, strong, readonly) AGSFeatureTable *featureTable;

#pragma mark -
#pragma mark methods

/** Clears selection on all features.
 @since 100.3
 */
-(void)clearSelection;

/** Retrieve the list of features that have selection enabled.
 @param completion block that is invoked with the results, or an error if one is encountered.
 @return operation which can be canceled
 @since 100.3
 */
-(id<AGSCancelable>)getSelectedFeaturesWithCompletion:(void(^)(AGSFeatureQueryResult *__nullable featureQueryResult, NSError *__nullable error))completion;

/** Select the specified feature. The scene will be updated to highlight the features with a selection color (cyan by default).
 @param feature to select
 @since 100.3
 @note Use `#selectFeatures:` to enable selection on a group of features together. It provides better performance as the scene will only need to be updated once.
 */
-(void)selectFeature:(AGSFeature *)feature;

/** Select the specified features. The scene will be updated to highlight the features with a selection color (cyan by default).
 @param features to select
 @since 100.3
 */
-(void)selectFeatures:(NSArray<AGSFeature*> *)features;

/** Clear selection on the specified feature. The scene will be redrawn to reflect the change.
 @param feature to unselect
 @since 100.3
 @note Use `#unselectFeatures:` to disable selection on a group of features together. It provides better performance as the scene will only need to be updated once.
 */
-(void)unselectFeature:(AGSFeature *)feature;

/** Clear selection on the specified features. The scene will be redrawn to reflect the change.
 @param features to unselect
 @since 100.3
 */
-(void)unselectFeatures:(NSArray<AGSFeature*> *)features;

NS_ASSUME_NONNULL_END

@end

