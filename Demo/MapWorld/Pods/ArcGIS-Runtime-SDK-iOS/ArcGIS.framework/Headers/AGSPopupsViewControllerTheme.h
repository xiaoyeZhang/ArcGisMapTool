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

/** @file AGSPopupsViewControllerTheme.h */ //Required for Globals API doc

/** @brief A theme to configure the appearance of `AGSPopupsViewController`
 
 Instances of this class represent a theme that can be used to configure the visual appearance of `AGSPopupsViewController`
 
 @since 100
 */
@interface AGSPopupsViewControllerTheme : NSObject
NS_ASSUME_NONNULL_BEGIN

/** Font used for heading text in the popups container.
 You must set this before you access the view or present the popups view controller.
 @since 100
 */
@property (nonatomic, strong, readwrite) AGSFont *headlineFont;

/** Color used for heading text in the popups container.
 You must set this before you access the view or present the popups view controller.
 @since 100
 */
@property (nonatomic, strong) AGSColor *headlineColor;

/** Font used for attribute title text in the popups container.
 You must set this before you access the view or present the popups view controller.
 @since 100
 */
@property (nonatomic, strong, readwrite) AGSFont *attributeTitleFont;

/** Font used for attribute detail text in the popups container.
 You must set this before you access the view or present the popups view controller.
 @since 100
 */
@property (nonatomic, strong, readwrite) AGSFont *attributeDetailFont;

/** Font used for attachment title text in the popups container.
 You must set this before you access the view or present the popups view controller.
 @since 100
 */
@property (nonatomic, strong, readwrite) AGSFont *attachmentTitleFont;

/** Font used for attachment detail text in the popups container.
 You must set this before you access the view or present the popups view controller.
 @since 100
 */
@property (nonatomic, strong, readwrite) AGSFont *attachmentDetailFont;

/** Color of text used for attribute title text in the popups container.
 You must set this before you access the view or present the popups view controller.
 @since 100
 */
@property (nonatomic, strong) AGSColor *attributeTitleColor;

/** Color of text used for attribute detail text in the popups container.
 You must set this before you access the view or present the popups view controller.
 @since 100
 */
@property (nonatomic, strong) AGSColor *attributeDetailColor;

/** Color used for placeholder text and tooltips in popups.
 @since 100
 */
@property (nonatomic, strong) AGSColor *tooltipColor;

NS_ASSUME_NONNULL_END
@end
