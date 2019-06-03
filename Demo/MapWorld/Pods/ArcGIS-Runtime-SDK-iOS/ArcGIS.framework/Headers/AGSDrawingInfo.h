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

@class AGSRenderer;
@class AGSLabelingInfo;

/** @file AGSDrawingInfo.h */ //Required for Globals API doc

/** @brief Drawing information about a sub-layer of map or feature service.
 
 Instances of this class represent drawing information about a sub-layer of a dynamic or feature service.
 
 @since 100
 */
@interface AGSDrawingInfo : AGSObject

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** An array of @c AGSLabelingInfo objects representing the labeling information associated with this sub-layer.
 @since 100
 */
@property (nonatomic, copy, readonly) NSArray<AGSLabelingInfo*> *labelingInfo;

/** The transparency of this layer as a value between 0(fully opaque) and 100(fully transparent)
 @since 100
 */
@property (nonatomic, assign, readonly) double transparency;

/** @c The renderer assigned to the layer.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSRenderer *renderer;

/** Determine whether the symbols are scaled or not.
 @since 100
 */
@property (nonatomic, assign, readonly) BOOL scaleSymbols;

/** Determine whether the labels are shown or not.
 @since 100
 */
@property (nonatomic, assign, readonly) BOOL showLabels;

NS_ASSUME_NONNULL_END

@end
