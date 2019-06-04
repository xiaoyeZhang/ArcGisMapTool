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

/** @file AGSMobileBasemapLayer.h */ //Required for Globals API doc

/** @brief A layer to display basemap contents of a mobile map package
 
 Instances of this class represent a layer that can visualize vector/feature data in the basemap of a mobile map package (.mmpk file). It represents multiple feature layers from a geodatabase which are rendered together in a group to form a vector basemap. This layer abstracts the complexity of 100's of layers into a simple to use basemap layer.
 
 @since 100
 */
@interface AGSMobileBasemapLayer : AGSLayer

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/**
 The file URL of mobile map package (.mmpk file)
 @since 100
 */
@property (nonatomic, strong, readonly) NSURL *fileURL;

/*
 List of IDs of this layer's sub-layers
 @since 100
 */
@property (nonatomic, copy, readonly) NSArray<NSNumber*> *sublayerIDs;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end

