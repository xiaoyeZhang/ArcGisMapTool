/*
 COPYRIGHT 2011 ESRI
 
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

@class AGSPopupMediaValue;

NS_ASSUME_NONNULL_BEGIN

/** @file AGSPopupMedia.h */ //Required for Globals API doc

/** @brief Information about a single media in a popup
 
 Instances of this class represents media that is displayed in a popup for a geo-element.
 @since 100
 */
@interface AGSPopupMedia : AGSObject

#pragma mark -
#pragma mark initializers

+(instancetype)popupMedia;

#pragma mark -
#pragma mark properties

/** The caption that is displayed for the media.
 This can contain a literal value, or a placeholder for value from the geo-element's attribute for which the popup is displayed. The placeholder needs to be of the form {field_name}
 where <i>field_name</i> is a key in the geo-element's attributes.
 @since 100
 */
@property (nonatomic, copy, readwrite) NSString *caption;

/** The title that is displayed for the media. 
 This can contain a literal value, or a placeholder for value from the geo-element's attribute 
 for which the popup is displayed. The placeholder needs to be of the form {field_name}
 where <i>field_name</i> is a key in the geo-element's attributes.
 @since 100
 */
@property (nonatomic, copy, readwrite) NSString *title;

/** The type of media. 
 @since 100
 */
@property (nonatomic, assign) AGSPopupMediaType type;

/** The value for the media.
 @since 100
 */
@property (nullable, nonatomic, strong) AGSPopupMediaValue *value;

#pragma mark -
#pragma mark methods


@end

NS_ASSUME_NONNULL_END
