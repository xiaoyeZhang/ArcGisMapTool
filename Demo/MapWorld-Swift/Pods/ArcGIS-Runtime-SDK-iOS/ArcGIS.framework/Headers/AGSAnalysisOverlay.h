/*
 COPYRIGHT 2017 ESRI
 
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

@class AGSAnalysis;

/** @file AGSAnalysisOverlay.h */ //Required for Globals API doc

/** @brief Manages the display of one or more Analyses on a scene view.
 
 Instances of this class represent an analysis overlay which display the visual results of one or more `AGSAnalysis`. It allows you to group related analyses and control visibility for all members of the collection. A scene view can contain many analysis overlays.
 
 @see `AGSSceneView#analysisOverlays`
 @since 100.2
 */
@interface AGSAnalysisOverlay : AGSObject
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

+(instancetype)analysisOverlay;

#pragma mark -
#pragma mark properties

/** A collection of analyses managed by this overlay.
 @since 100.2
 */
@property (nonatomic, strong, readonly) NSMutableArray<AGSAnalysis*> *analyses;

/** Indicates if the overlay is visible. If not, the results of analyses managed by this overlay aren't visible either.
 @since 100.2
 */
@property (nonatomic, assign, readwrite, getter=isVisible) BOOL visible;

NS_ASSUME_NONNULL_END
@end
