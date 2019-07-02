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

/** @file AGSPointCloudLayer.h */ //Required for Globals API doc

/** @brief A layer that can display point cloud data

 An instance of this class represents a layer that can visualize a point cloud layer. Point cloud layers provide fast display of large volumes of symbolized and filtered point cloud data. They are optimized for the display and sharing of many kinds of sensor data, including lidar.
 
 @since 100.5
 */
@interface AGSPointCloudLayer : AGSLayer <AGSRemoteResource>

NS_ASSUME_NONNULL_BEGIN

-(instancetype)init NS_UNAVAILABLE;

/** Initialize the layer with the given URL
 @param url The URL of an individual layer
 @since 100.5
 */
-(instancetype)initWithURL:(NSURL *)url;

/** Initialize the layer with the provided information
 @param item representing a Point Cloud Layer. The item's type must be @c AGSPortalItemTypeSceneService.
 @return Initialized layer
 @since 100.5
 */
-(instancetype)initWithItem:(AGSItem*)item;

/** Initialize this layer with the name of a scene layer package within the application bundle or shared documents directory.
 @param name of the scene layer package (without the .slpk file extension) within the application bundle or shared documents directory.
 @return A new point cloud layer.
 @since 100.5
 */
-(instancetype)initWithName:(NSString*)name;

/** Initialize the layer with the given URL
 @param URL The URL of a Point Cloud Layer
 @since 100.5
 */
+(instancetype)pointCloudLayerWithURL:(NSURL*)URL;

/** Initialize the layer with the provided information
 @param item representing a Point Cloud Layer. The item's type must be @c AGSPortalItemTypeLayer.
 @return Initialized layer
 @since 100.5
 */
+(instancetype)pointCloudLayerWithItem:(AGSItem*)item;

/** Initialize this layer with the name of a scene layer package within the application bundle or shared documents directory.
 @param name of the scene layer package (without the .slpk file extension) within the application bundle or shared documents directory.
 @return A new point cloud layer.
 @since 100.5
 */
+(instancetype)pointCloudLayerWithName:(NSString*)name;

NS_ASSUME_NONNULL_END

@end
