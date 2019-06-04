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

@protocol AGSLayerContent;
@class AGSPopup;

/*@file AGSIdentifyLayerResult.h */


/** @brief Results of an identify layer operation on `AGSGeoView`
 
 Instances of this class represent the result for an individual layer returned by the identify operation on `AGSGeoView`
 
 @since 100
 @see `AGSGeoView#identifyLayersAtScreenPoint:tolerance:completion:` to identify features from all the map's operational layers
 @see `AGSGeoView#identifyLayer:screenPoint:tolerance:completion:` to identify features from a specific layer
 */
@interface AGSIdentifyLayerResult : AGSObject
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** The identifed geo-elements for the layer represented by `#layerContent`. Might be empty if the layer is composed of sub layers in which case `#sublayerResults` will be populated with results from sub layers. 
 Only valid when the identify was called with the `returnPopupsOnly` parameter set to false.
 @since 100
 */
@property (nonatomic, copy, readonly) NSArray<id<AGSGeoElement>> *geoElements;

/** The identifed popups for the layer represented by `#layerContent`. Might be empty if the layer is composed of sub layers in which case `#sublayerResults` will be populated with results from sub layers.
 @since 100
 */
@property (nonatomic, copy, readonly) NSArray<AGSPopup*> *popups;

/** Specifies if the transfer limit was exceeded for the identify results.
 @since 100
 */
@property (nonatomic, assign, readonly, getter=isTransferLimitExceeded) BOOL transferLimitExceeded;

/** The layer to which the identified `#geoElements` belong.
 @since 100
 */
@property (nonatomic, strong, readonly) id<AGSLayerContent> layerContent;

/** Results for any sublayers of the layer represented by `#layerContent`.
 Only applicable if the current layer contains any sub-layers.
 @since 100
 */
@property (nonatomic, copy, readonly) NSArray<AGSIdentifyLayerResult*> *sublayerResults;

/** Error encountered during identify, if any.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) NSError *error;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END
@end
