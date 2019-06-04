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

@class AGSLegendInfo;

/** @file AGSLayerContent.h */ //Required for Globals API doc

/** @brief A protocol defining common properties and operations for layers
 
 A protocol defining common properties and operations for layers
 
 @since 100
 */
@protocol AGSLayerContent <NSObject>
NS_ASSUME_NONNULL_BEGIN

@required

#pragma mark -
#pragma mark properties

/** Denotes whether the layer can change visibility or not.
 @since 100
 */
@property (nonatomic, assign, readonly) BOOL canChangeVisibility;

/** Denotes whether the layer is visible or not.
 @since 100
 */
@property (nonatomic, assign, readwrite, getter=isVisible) BOOL visible;

/** The name of the layer.
 @since 100
 */
@property (nonatomic, copy, readonly) NSString *name;

/** Indicates whether to show legend information.
 @since 100
 */
@property (nonatomic, assign, readwrite) BOOL showInLegend;

/** This layer's sub-layers.
 @since 100
 */
@property (nonatomic, copy, readonly) NSArray<id<AGSLayerContent>> *subLayerContents;

/** Block that is invoked when the sub layer contents changes.
 @note The block will be invoked on the same thread on which the event occured, which could be any arbitrary thread. You need to dispatch any UI related work to the main thread.
 @since 100
 */
@property (nullable, nonatomic, copy, readwrite) void (^subLayerContentsChangedHandler)();

#pragma mark -
#pragma mark methods

/** Fetches the array of legend infos (`AGSLegendInfo`) for this layer.
 @since 100
 */
-(id<AGSCancelable>)fetchLegendInfosWithCompletion:(void(^)(NSArray<AGSLegendInfo*> * __nullable legendInfos, NSError * __nullable error))completion;

/** Check whether this layer is visible at a given scale.
 @since 100
 */
-(BOOL)isVisibleAtScale:(double)scale;

NS_ASSUME_NONNULL_END
@end
