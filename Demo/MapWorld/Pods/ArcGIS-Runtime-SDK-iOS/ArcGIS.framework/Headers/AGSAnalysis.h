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

/** @file AGSAnalysis.h */ //Required for Globals API doc

/** @brief Base class for rendering analysis results in a scene view
 
 Base class for rendering analysis results in a scene view.
 
 @see `AGSAnalysisOverlay`
 @since 100.2
 */
@interface AGSAnalysis : AGSObject
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

#pragma mark -
#pragma mark properties

/** Indicates whether the results of this analysis should be visible or not.
 Visibility can be controlled for individual analyses as well as for the analysis overlay that contains them.
 @since 100.2
 */
@property (nonatomic, assign, readwrite, getter=isVisible) BOOL visible;

NS_ASSUME_NONNULL_END
@end
