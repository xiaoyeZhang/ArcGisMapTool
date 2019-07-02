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

NS_ASSUME_NONNULL_BEGIN

/** @file AGSPopupMediaValue.h */ //Required for Globals API doc

/** @brief Contents of a media element in a popup
 
 Instances of this class represents contents of an individual media element in a popup.
 @since 100
 */
@interface AGSPopupMediaValue : AGSObject

#pragma mark -
#pragma mark initializers

+(instancetype)popupMediaValue;

#pragma mark -
#pragma mark properties

/** The geo-element's fields (attributes) whose values should be displayed in the chart. Only applicable if media is a chart.
 @since 100
 */
@property (nonatomic, copy, readwrite) NSArray<NSString*> *fieldNames;

/** The URL or URL template that defines which web address the image links to.
 Only applicable is media is an image.
 @since 100
 */
@property (nonatomic, copy, readwrite) NSString *link;

/** The geo-element's field (attribute) whose value should be used to normalize values of `#fields`. Only applicable if media is a chart.
 @since 100
 */
@property (nonatomic, copy, readwrite) NSString *normalizeFieldName;

/** The URL or URL template that defines which web address the image is available on.
 Only applicable is media is an image.
 @since 100
 */
@property (nonatomic, copy, readwrite) NSString *source;

/** The geo-lement's field (attribute) whose value should be used to display a tooltip for sections of the chart. Only applicable if media is a chart.
 @since 100
 */
@property (nonatomic, copy, readwrite) NSString *tooltipFieldName;

#pragma mark -
#pragma mark methods

@end

NS_ASSUME_NONNULL_END

