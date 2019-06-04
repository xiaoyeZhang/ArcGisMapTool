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

#import "AGSAnalysis.h"

/** @file AGSLineOfSight.h */ //Required for Globals API doc

/** @brief Base class for all line-of-sight analysis
 
 Base class for line of sight analysis. Line of sight analysis determines the visibility of sight lines over obstructions consisting of a surface and multipatch datasets (such as 3D models, etc).
 
 @license{Standard}
 @ingroup licensing
@since 100.2
 */
@interface AGSLineOfSight : AGSAnalysis
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

#pragma mark -
#pragma mark properties

/** Indicates state of the target's visbility.
 @since 100.2
 */
@property (nonatomic, assign, readonly) AGSLineOfSightTargetVisibility targetVisibility;

#pragma mark -
#pragma mark methods


/** The line width used to render analysis results. This setting is applied to all line of sight analyses in the view.
 @since 100.2
 */
+(CGFloat)lineWidth;

/** The color used to render segments that are not visible along the analysis results. Sections of the line between the observer and the target that are obstructed (not visible) are drawn with the specified color. This setting is applied to all line of sight analyses in the view.
 @since 100.2
 */
+(AGSColor *)obstructedColor;

/** The color used to render segments that are visible along the analysis results. Sections of the line between the observer and the target that are visible are drawn with the specified color. This setting is applied to all line of sight analyses in the view.
 @since 100.2
 */
+(AGSColor *)visibleColor;

/** Sets the line width used to render analysis results. This setting is applied to all line of sight analyses in the view.
 @param lineWidth in points
 @since 100.2
 */
+(void)setLineWidth:(CGFloat)lineWidth;

/** Sets the color used to render segments that are not visible along the analysis results. Sections of the line between the observer and the target that are obstructed (not visible) are drawn with the specified color. This setting is applied to all line of sight analyses in the view.
 @param obstructedColor used to render segments that are not visible
 @since 100.2
 */
+(void)setObstructedColor:(AGSColor *)obstructedColor;

/** Sets the color used to render segments that are visible along the analysis results. Sections of the line between the observer and the target that are visible are drawn with the specified color. This setting is applied to all line of sight analyses in the view.
 @param visibleColor used to render segments that are visible
 @since 100.2
 */
+(void)setVisibleColor:(AGSColor *)visibleColor;

NS_ASSUME_NONNULL_END
@end
