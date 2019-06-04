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

@class AGSGraphic;
@class AGSPopupDefinition;
@class AGSPopupField;
@class AGSPopupManager;
@class AGSGeometry;
@class AGSArcGISFeature;
@class AGSArcGISFeatureTable;
@class AGSSymbol;
@protocol AGSGeoElement;

/** @file AGSPopup.h */ //Required for Globals API doc

/** @brief A popup which displays a geo-element's information.
 
 Instances of this class represent a popup which associates a geo-element with popup definition for the purpose of displaying in an `AGSPopupsViewController`.
 @since 100
 */
@interface AGSPopup : AGSObject
NS_ASSUME_NONNULL_BEGIN


#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

/** Initialize the popup for the provided geo-element based on the popup definition.
 @param geoElement for which to create a popup
 @param popupDefinition specifying how the geo-element should be represented in the popup
 If you pass nil for the `popupDefinition` a default one will be created for you based on the geo-element's attributes or schema.
 @return A new popup
 @since 100
 */
-(instancetype)initWithGeoElement:(id<AGSGeoElement>)geoElement popupDefinition:(nullable AGSPopupDefinition*)popupDefinition;

/** Initialize the popup for the provided geo-element. A default popup definition will be created based on the geo-element's attributes or schema specifying how the geo-element should be represented in the popup.
 @param geoElement for which to create a popup
 @return A new popup
 @since 100
 */
-(instancetype)initWithGeoElement:(id<AGSGeoElement>)geoElement;

/** Initialize the popup for the provided geo-element based on the popup definition.
 @param geoElement for which to create a popup
 @param popupDefinition specifying how the geo-element should be represented in the popup
 If you pass nil for the `popupDefinition` a default one will be created for you based on the geo-element's attributes or schema.
 @return A new popup
 @since 100
 */
+(instancetype)popupWithGeoElement:(id<AGSGeoElement>)geoElement popupDefinition:(nullable AGSPopupDefinition*)popupDefinition;

/** Initialize the popup for the provided geo-element. A default popup definition will be created based on the geo-element's attributes or schema specifying how the geo-element should be represented in the popup.
 @param geoElement for which to create a popup
 @return A new popup
 @since 100
 */
+(instancetype)popupWithGeoElement:(id<AGSGeoElement>)geoElement;

#pragma mark -
#pragma mark properties


/** A popup definition that dictates which information belonging to the geo-element should be displayed in the popup  and how it should be formatted.
 @since 100
 */
@property (nonatomic, strong, readonly) AGSPopupDefinition *popupDefinition;

/** The geoElement which this popup is associated with.
 @since 100
 */
@property (nonatomic, strong, readonly) id<AGSGeoElement> geoElement;

/** The text to display as the popup title.
 @since 100
 */
@property (nullable, nonatomic, copy, readonly) NSString *title;

/** The popup symbol.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSSymbol *symbol;


#pragma mark -
#pragma mark methods

/**
 Returns a string you can use in a display for the popup's field value. String will have the proper formatting
 based on the field type and `AGSPopupField` configuration.
 @param popupField The field for which a properly formatted value is desired
 @return user-friendly string representing the value
 @since 100
 */
-(NSString*)formattedValueForField:(AGSPopupField*)popupField;

/**
 Substitutes attribute templates in a string with actual values.
 @since 100
 */
-(nullable NSString*)stringForTemplatedString:(NSString*)templatedString;

NS_ASSUME_NONNULL_END
@end
