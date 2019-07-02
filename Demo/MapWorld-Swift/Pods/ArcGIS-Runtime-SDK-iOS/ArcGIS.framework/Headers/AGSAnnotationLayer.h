/*
 COPYRIGHT 2019 ESRI
 
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

/** @file AGSAnnotationLayer.h */ //Required for Globals API doc

#import "AGSLayer.h"
#import "AGSRemoteResource.h"

NS_ASSUME_NONNULL_BEGIN

@class AGSItem;

/** @brief An instance of this class represents a layer that can visualize annotation text data.
 @see @c AGSLayer
 @since 100.5
 */
@interface AGSAnnotationLayer : AGSLayer <AGSRemoteResource>

#pragma mark -
#pragma mark initializers

-(instancetype)init NS_UNAVAILABLE;

/** Creates a new annotation layer from a feature service portal item.
 @param item A feature service @c AGSPortalItem.
 @param serviceLayerID The ID of the layer in the service for which to create the annotation layer.
 @see @c AGSLayer#item
 @since 100.5
 */
-(instancetype)initWithItem:(AGSItem *)item 
             serviceLayerID:(NSInteger)serviceLayerID;

/** Creates a new annotation layer from a feature service portal item.
 @param item A feature service @c AGSPortalItem.
 @param serviceLayerID The ID of the layer in the service for which to create the annotation layer.
 @see @c AGSLayer#item
 @since 100.5
 */
+(instancetype)annotationLayerWithItem:(AGSItem *)item 
                        serviceLayerID:(NSInteger)serviceLayerID;

/** Creates a new annotation layer from a feature service URL.
 If the specified URL is not a valid Feature Service endpoint, then it will fail to load.
 @param URL The URL to the feature service layer.
 @since 100.5
 */
-(instancetype)initWithURL:(NSURL *)URL;

/** Creates a new annotation layer from a feature service URL.
 If the specified URL is not a valid Feature Service endpoint, then it will fail to load.
 @param URL The URL to the feature service layer.
 @since 100.5
 */
+(instancetype)annotationLayerWithURL:(NSURL *)URL;

#pragma mark -
#pragma mark properties

/** The layer ID that defines the layer within the FeatureService Portal Item
 @see @c AGSLayer#item, @c AGSAnnotationLayer#serviceLayerID
 @since 100.5
 */
@property (nonatomic, assign, readonly) NSInteger serviceLayerID;

/** The reference scale for the layer.
 The reference scale of the layer is the scale at which a client should view the layer for the
 text to appear at its authored size.
 If the client changes the viewing scale, then text will grow or shrink
 to keep a consistent size on the map (not the screen).
 For a valid layer, the reference scale will always be a finite value, greater than zero.
 Until the layer is loaded, the reference scale will be zero.
 @since 100.5
 */
@property (nonatomic, assign, readonly) double referenceScale;

#pragma mark -
#pragma mark methods

@end

NS_ASSUME_NONNULL_END
