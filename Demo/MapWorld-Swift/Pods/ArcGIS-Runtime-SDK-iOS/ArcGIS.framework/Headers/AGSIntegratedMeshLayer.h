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
#import "AGSRemoteResource.h"

/** @file AGSIntegratedMeshLayer.h */ //Required for Globals API doc

/** @brief A layer that can display an integrated mesh
 
 An instance of this class represents a layer that can visualize an integrated mesh layer. An integrated mesh can represent built and natural 3D features, such as building walls, trees, valleys, and cliffs, with realistic textures and includes elevation information.
 
 @since 100.5
 */
@interface AGSIntegratedMeshLayer : AGSLayer <AGSRemoteResource>

NS_ASSUME_NONNULL_BEGIN

/** Initialize the layer with the given URL
 @param url The URL of an individual layer
 @since 100.5
 */
-(instancetype)initWithURL:(NSURL *)url;

/** Initialize the layer with the provided information
 @param item representing an Integrated Mesh Layer. The item's type must be @c AGSPortalItemTypeSceneService.
 @return Initialized layer
 @since 100.5
 */
-(instancetype)initWithItem:(AGSItem*)item;

/** Initialize this layer with the name of a scene layer package within the application bundle or shared documents directory.
 @param name of the scene layer package (without the .slpk file extension) within the application bundle or shared documents directory.
 @return A new integrated mesh layer.
 @since 100.5
 */
-(instancetype)initWithName:(NSString*)name;

/** Initialize the layer
 @since 100.5
 */
+(instancetype)integratedMeshLayer;

/** Initialize the layer with the given URL
 @param URL The URL of an Integrated Mesh Layer
 @since 100.5
 */
+(instancetype)integratedMeshLayerWithURL:(NSURL*)URL;

/** Initialize the layer with the provided information
 @param item representing an Integrated Mesh Layer. The item's type must be @c AGSPortalItemTypeLayer.
 @return Initialized layer
 @since 100.5
 */
+(instancetype)integratedMeshLayerWithItem:(AGSItem*)item;

/** Initialize this layer with the name of a scene layer package within the application bundle or shared documents directory.
 @param name of the scene layer package (without the .slpk file extension) within the application bundle or shared documents directory.
 @return A new integrated mesh layer.
 @since 100.5
 */
+(instancetype)integratedMeshLayerWithName:(NSString*)name;

NS_ASSUME_NONNULL_END

@end
