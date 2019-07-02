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

@class AGSPopupMedia;
@class AGSPopupField;
@class AGSPopupRelatedFeaturesDefinition;
@class AGSPopupExpression;

@protocol AGSGeoElement;
@protocol AGSPopupSource;

/** @file AGSPopupDefinition.h */ //Required for Globals API doc

/** @brief A popup definition
 
 Instances of this class respresent popup definitions for geo-elements that need to be displayed in popups. Popup definitions contain information such as -
 
 @li Which attributes of the geo-element should the popup display, whether they are editable, how to format numbers and dates, etc
 @li Whether the popup should show attachments for the geo-element
 @li What media, such as charts and images, should be displayed for the geo-element
 
 @since 100
 */
@interface AGSPopupDefinition : AGSObject
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

/** Initialize a popup definition based on the attribute schema of the geo-element. By default, all the attributes will be included in the popup fields.
 @param geoElement for which popup definition should be created
 @return A new popup definition
 @since 100
 */
-(instancetype)initWithGeoElement:(id<AGSGeoElement>)geoElement;

/** Initialize a popup definition based on popup source. By default, all the fields available in the source will be included in the popup fields.
 @param popupSource for which popup definition should be created
 @return A new popup definition
 @since 100
 */
-(instancetype)initWithPopupSource:(id<AGSPopupSource>)popupSource;

+(instancetype)popupDefinition;

/** Initialize a popup definition based on popup source. By default, all the fields available in the source will be included in the popup fields.
 @param popupSource for which popup definition should be created
 @return A new popup definition
 @since 100
 */
+(instancetype)popupDefinitionWithPopupSource:(id<AGSPopupSource>)popupSource;

/** Initialize a popup definition based on the attribute schema of the geo-element
 @param geoElement for which popup definition should be created
 @return A new popup definition
 @since 100
 */
+(instancetype)popupDefinitionWithGeoElement:(id<AGSGeoElement>)geoElement;

#pragma mark -
#pragma mark properties

/** The title that is displayed for the geo-element in the popup.
 This can contain a literal value, or a placeholder for value from the geo-element's attribute. The placeholder needs to be of the form {field_name}
 where <i>field_name</i> is a key in the geo-element's attributes.
 @since 100
 */
@property (nonatomic, copy, readwrite) NSString *title;

/** The description that is shown for the geo-element in the popup. This can be html. If description is nil then the #popupFields are used
 when viewing attributes.
 This can contain a literal value, or a placeholder for value from the geo-element's attribute. The placeholder needs to be of the form {field_name}
 where <i>field_name</i> is a key in the geo-element's attributes.
 @since 100
 */
@property (nonatomic, copy, readwrite) NSString *customDescription;

/** A list of expressions based on the Arcade language that can be evaluated to display computed information in `#fields`, `#media`, `#title`, or `#customDescription`
 @since 100.3
 */
@property (nonatomic, copy, readwrite) NSArray<AGSPopupExpression*> *expressions;

/** The geo-element's fields (as an array of @c AGSPopupField objects) that are to be displayed in the popup.
 If description is not nil then the popupFields are not used
 when viewing attributes. 
 @since 100
 */
@property (nonatomic, copy, readwrite) NSArray<AGSPopupField*> *fields;

/** The media (as an array of @c AGSPopupMedia objects) that is to be displayed in the popup.
 @since 100
 */
@property (nonatomic, copy, readwrite) NSArray<AGSPopupMedia*> *media;

/** A definition that dictates whether related features should be displayed in the popup and how they should be sorted.
 @since 100.1
 */
@property (nullable, nonatomic, strong, readwrite) AGSPopupRelatedFeaturesDefinition *relatedFeaturesDefinition;

/** Whether or not the popup should show attachments of the geo-element.
 @since 100
 */
@property (nonatomic, assign) BOOL showAttachments;

/** Whether or not the popup should allow the geo-element to be edited.
 @since 100
 */
@property (nonatomic, assign) BOOL allowEdit;

/** Whether or not the popup should allow the geo-element's geometry should be edited. Only applicable when #allowEdit is YES.
 @since 100
 */
@property (nonatomic, assign) BOOL allowEditGeometry;

/** Whether or not the popup should allow the geo-element to be deleted.
 @since 100
 */
@property (nonatomic, assign) BOOL allowDelete;

/** Whether or not the popup should display a summary of when the geo-element was last edited and by whom.
 @since 100
 */
@property (nonatomic, assign) BOOL showEditSummary;

/** Whether or not the popup should show additional geo-elements that are related to this popup's geo-element.
 @since 100
 @deprecated 100.1. Use `#relatedFeaturesDefinition.showRelatedFeatures` instead.
 */
@property (nonatomic, assign) BOOL showRelatedRecords __deprecated_msg("Please use relatedFeaturesDefinition.showRelatedFeatures");

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END
@end

