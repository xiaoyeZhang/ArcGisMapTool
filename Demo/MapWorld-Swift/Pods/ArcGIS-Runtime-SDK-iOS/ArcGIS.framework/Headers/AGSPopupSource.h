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

@class AGSPopupDefinition;

NS_ASSUME_NONNULL_BEGIN

/** @file AGSPopupSource.h */ //Required for Globals API doc

/** @brief A source for popups
 
 Instances of this class represent a source of popups that can be displayed by `AGSPopupsViewController`.
 
 @see `AGSGeoView#identifyPopupsAtScreenPoint:tolerance:completion:` to retrieve popups for layers in a map
 @since 100
 */
@protocol AGSPopupSource <NSObject>

@required

/** Indicates whether popups are enabled on this source.
 @since 100
 */
@property (nonatomic, assign, readwrite, getter=isPopupEnabled) BOOL popupEnabled;

/** Information on how popups are defined for this source.
 @since 100
 */
@property (nullable, nonatomic, strong, readwrite) AGSPopupDefinition *popupDefinition;

@end

NS_ASSUME_NONNULL_END
