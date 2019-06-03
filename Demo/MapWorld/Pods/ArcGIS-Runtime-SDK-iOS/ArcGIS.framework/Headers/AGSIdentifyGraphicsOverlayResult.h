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

@class AGSGraphicsOverlay;
@class AGSGraphic;
@class AGSPopup;

/*@file AGSIdentifyGraphicsOverlayResult.h */

/** @brief Results of an identify graphic overlay operation on `AGSGeoView`
 
 Instances of this class represent the result for an individual graphic overlay returned by the identify operation on `AGSGeoView`
 
 @since 100
 @see `AGSGeoView#identifyGraphicOverlaysAtScreenPoint:tolerance:completion:` to identify graphics from all the graphic overlays
 @see `AGSGeoView#identifyGraphicOverlay:screenPoint:tolerance:completion:` to identify graphics from a specific graphic overlay
 */
@interface AGSIdentifyGraphicsOverlayResult : AGSObject
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** The resulting identified graphics
 Only valid when the identify was called with the `returnPopupsOnly` parameter set to false.
 @since 100
 */
@property (nonatomic, copy, readonly) NSArray<AGSGraphic*> *graphics;

/** The identifed popups for the graphicsOverlay represented by `#graphicsOverlay`.
 @since 100
 */
@property (nonatomic, copy, readonly) NSArray<AGSPopup*> *popups;

/** The graphics overlay to which the identified `#graphics` belong.
 @since 100
 */
@property (nonatomic, strong, readonly) AGSGraphicsOverlay *graphicsOverlay;

/** Error encountered during identify, if any.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) NSError *error;

NS_ASSUME_NONNULL_END
@end
