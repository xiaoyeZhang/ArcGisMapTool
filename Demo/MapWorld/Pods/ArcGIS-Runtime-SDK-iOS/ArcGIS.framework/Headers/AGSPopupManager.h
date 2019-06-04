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

@class AGSPopupAttachmentManager;
@class AGSPopupField;
@class AGSPopup;
@class AGSFeatureType;
@class AGSDomain;
@class AGSFeatureTemplate;
@class AGSSymbol;
@class AGSSketchEditor;

@protocol AGSPopupManagerDelegate;

#pragma mark -
#pragma mark Notifications / (Events)
#pragma mark -

/** Notification that is fired when the validity of a feature changes.
 @since 100
 */
AGS_EXTERN NSNotificationName _Nonnull const AGSPopupManagerGeoElementValidityDidChangeNotification;

/** Notification that is fired when the feature type for a feature in a popup changes.
 @since 100
 */
AGS_EXTERN NSNotificationName _Nonnull const AGSPopupManagerFeatureTypeDidChangeNotification;


/** @file AGSPopupManager.h */ //Required for Globals API doc

/** @brief A popup manager
 
 Instances of this class represent a popup manager that contains the necessary business logic for displaying and editing popup information for geo-elements. This class is useful, for instance, if you want to create your own View Controller for displaying `AGSPopup` instead of using `AGSPopupsViewController`.
 
 @since 100
 */
@interface AGSPopupManager : NSObject
NS_ASSUME_NONNULL_BEGIN


#pragma mark -
#pragma mark initializers
#pragma mark -


/** Initializes an AGSPopupManager with an AGSPopup.
 This initializer will retain the passed in popup strongly.
 If the AGSGeoElement associated with the popup conforms to AGSLoadable it must be loaded for the AGSPopupManager to work properly.
 @since 100
 */
-(instancetype)initWithPopup:(AGSPopup *)popup;


#pragma mark -
#pragma mark properties
#pragma mark -

/** A delegate of the popup manager that is notified about changes in the popup state or validity.
 @since 100
 */
@property (nullable, nonatomic, weak, readwrite) id<AGSPopupManagerDelegate> delegate;

/** The associated AGSPopup.
 This property is marked unsafe_unretained because it depending on how you instantiate the AGSPopupManager,
 the AGSPopup you pass in may be retained or not.
 If the AGSGeoElement associated with the popup conforms to AGSLoadable it must be loaded for the AGSPopupManager to work properly.
 See the individual initializers for more information.
 @since 100
 */
@property (nonatomic, unsafe_unretained, readonly) AGSPopup *popup;

/** The attachment manager for this popup
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSPopupAttachmentManager *attachmentManager;


#pragma mark display properties


/** The current AGSFeatureType, if any, of the AGSGeoElement
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSFeatureType *featureType;

/** Convenience for getting the popup fields that are editable
 @since 100
 */
@property (nonatomic, copy, readonly) NSArray<AGSPopupField*> *editableDisplayFields;

/** Convenience for getting the AGSPopupFields that are for viewing
 @since 100
 */
@property (nonatomic, copy, readonly) NSArray<AGSPopupField*> *displayFields;


#pragma mark Strings that the popup view controller will use in the UI


/** The text to display as the popup title.
 @since 100
 */
@property (nullable, nonatomic, copy, readonly) NSString *title;

/** The text to display as the custom HTML description.
 @since 100
 */
@property (nullable, nonatomic, copy, readonly) NSString *customDescriptionHTML;

/** The edit summary text.
 @since 100
 */
@property (nullable, nonatomic, copy, readonly) NSString *editSummary;

/** Symbol used by the popup's geo-element
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSSymbol *symbol;

#pragma mark Properties for what UI the popup view controller should show


/**
 Whether or not the popup view controller should allow editing.
 Takes into account if it is a new feature. In which case even if allowEdit
 on the popup is false we still need to show the edit button in the popup if it's a brand new feature.
 Takes into account OBAC and the popup definition as well.
 @since 100
 */
@property (nonatomic, assign, readonly) BOOL shouldAllowEdit;

/**
 Whether or not the popup view controller should allow deleting.
 Takes into account if the table allows deleting the feature and the Popup settings.
 Takes into account OBAC and the popup definition as well.
 @since 100
 */
@property (nonatomic, assign, readonly) BOOL shouldAllowDelete;

/**
 Whether or not the popup view controller should allow editing the geometry.
 Takes into account if we are creating a new geometry, if dealing with only a table, etc.
 Takes into account OBAC and the popup definition as well.
 @since 100
 */
@property (nonatomic, assign, readonly) BOOL shouldAllowEditGeometry;

/**
 Whether or not the popup view controller should allow editing the attachments.
 Takes into account the popupDefinition.showAttachments and if we have an attachment manager and if the
 layer actually has attachments.
 @since 100
 */
@property (nonatomic, assign, readonly) BOOL shouldAllowEditAttachments;

/**
 Whether or not the popup view controller should show the attachments.
 Takes into account the popupDefinition.showAttachments and if we have an attachment manager and if the
 layer actually has attachments.
 @since 100
 */
@property (nonatomic, assign, readonly) BOOL shouldShowAttachments;

/**
 Whether or not the popup view controller should show the media.
 @since 100
 */
@property (nonatomic, assign, readonly) BOOL shouldShowMedia;

/**
 Whether or not the popup view controller should show the edit info summary.
 @since 100
 */
@property (nonatomic, assign, readonly) BOOL shouldShowEditSummary;

/**
 Whether or not the popup view controller should show the custom description HTML.
 @since 100
 */
@property (nonatomic, assign, readonly) BOOL shouldShowCustomDescriptionHTML;

#pragma mark editing properties

/** Whether or not currently in editing mode
 @since 100
 */
@property (nonatomic, assign, readonly, getter=isEditing) BOOL editing;

/** The current sketch editor that is used for editing the geometry of the popup.
 This is used for the AGSPopupManager to determine when the geometry of the popup being edited changes.
 This allows the AGSPopupManager to set the validity of the geoElement accordingly.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSSketchEditor *currentSketchEditor;

/** Whether or not the AGSGeoElement is in a valid state as far as the values it has set in its attributes and it's geometry.
 @since 100
 */
@property (nonatomic, assign, readonly, getter=isGeoElementValid) BOOL geoElementValid;


#pragma mark -
#pragma mark methods
#pragma mark -


#pragma mark Value Helper Methods

/**
 Substitutes attribute templates in a string with actual values.
 @since 100
 */
-(nullable NSString*)stringForTemplatedString:(NSString*)templatedString;

/**
 Creates correct number type from a string. Uses the AGSPopupField to determine type of number to return (int, double, etc)
 @since 100
 @deprecated 100.1. Use `#numberFromString:field:error:` instead.
 */
-(nullable NSNumber*)numberFromString:(NSString*)stringValue field:(AGSPopupField*)popupField __deprecated_msg("Please use numberFromString:field:error:");

/**
 Creates correct number type from a string. Uses the AGSPopupField to determine type of number to return (int, double, etc).
 If the string contains invalid characters it will return nil and fill out the appropriate error.
 If the string is parsed correctly but the number is out of range for the field's range domain (if there is one) then it will return nil.
 If the string is parsed correctly but the number is out of numeric range for the appropriate field type then it will return nil
 and fill out the appropriate error.
 @since 100.1
 */
-(nullable NSNumber*)numberFromString:(NSString *)stringValue field:(AGSPopupField *)popupField error:(NSError**)error;

/**
 Returns a string you can use in a display for the current popup field's value. String will have the proper formatting
 based on the field type and AGSPopupField configuration.
 @since 100
*/
-(NSString*)formattedValueForField:(AGSPopupField*)popupField;

/**
 Returns the actual value that is in the AGSGeoElement for a given AGSPopupField.
 This method is "safe" (returns nil instead of NSNull)
 @since 100
 */
-(nullable id)valueForField:(AGSPopupField*)popupField;


#pragma mark Field Helper Methods


/** Returns the AGSPopupField for a given field name.
 @since 100
 */
-(nullable AGSPopupField*)fieldForName:(NSString*)fieldName;

/** Returns the field type for a given AGSPopupField.
 @since 100
 */
-(AGSFieldType)fieldTypeForField:(AGSPopupField*)popupField;

/** Returns the AGSDomain associated with a given AGSPopupField
 @since 100
 */
-(nullable AGSDomain*)domainForField:(AGSPopupField*)popupField;

/** Returns the field length given an AGSPopupField.
 @since 100
 */
-(NSInteger)lengthForField:(AGSPopupField*)popupField;

/** Returns whether or not a given AGSPopupField allows null values.
 @since 100
 */
-(BOOL)fieldIsNullable:(AGSPopupField*)popupField;

/** Returns whether or not a given AGSPopupField is the TypeID field.
 @since 100
 */
-(BOOL)fieldIsTypeIDField:(AGSPopupField*)popupField;

/** Returns a user-friendly display name for the provided popup field
 @since 100.3
 */
-(NSString *)labelForField:(AGSPopupField *)popupField;

#pragma mark -
#pragma mark Editing Methods
#pragma mark -


#pragma mark methods for starting, cancelling, finishing editing


/** Starts editing of the popup.
 This does some work, like copying the original attributes, etc.
 @since 100
 */
-(BOOL)startEditing;

/** Cancels the editing of the popup. 
 This rolls the AGSGeoElement back to it's original state.
 @since 100
 */
-(void)cancelEditing;

/** Finish editing the popup.
 Async method that calls back when complete. This method commits any attachment and attribute changes to the AGSGeoElement.
 @since 100
 */
-(void)finishEditingWithCompletion:(void(^)(NSError * __nullable error))completion;


#pragma mark methods for updating the value in the geo-element when user changes values

/** Update the value of a field in the AGSGeoElement associated with the popup.
 This function expects you to pass at least the correct type of value for the field.
 The only exception to that is that you can pass a string for numeric fields and this
 function will do the work of converting it to the appropriate number type for the specified field.
 Returns @c YES if the new value passes validation.
 @since 100
 */
-(BOOL)updateValue:(nullable id)newValue field:(AGSPopupField*)popupField validationError:(NSError**)validationError;

/** Method you can call to determine if you need to notify the user when a AGSFeatureType is going to change.
 @param featureTemplate The template that the user wants to change to.
 @since 100
 @deprecated 100.1. Use `#featureTypeChangeRequiresUserNotificationForTemplate` instead
 */
-(BOOL)featureTypeChangeRequiresUserNoficationForTemplate:(nullable AGSFeatureTemplate*)featureTemplate  __deprecated_msg("Please use featureTypeChangeRequiresUserNotificationForTemplate:");

/** Method you can call to determine if you need to notify the user when a AGSFeatureType is going to change.
 @param featureTemplate The template that the user wants to change to.
 @since 100.1
 */
-(BOOL)featureTypeChangeRequiresUserNotificationForTemplate:(nullable AGSFeatureTemplate*)featureTemplate;

/** Update the feature type of the AGSGeoElement associated with the popup.
 Returns @c YES if the new value passes validation.
 @since 100
 */
-(BOOL)updateFeatureTypeWithTemplate:(nullable AGSFeatureTemplate*)featureTemplate changeMode:(AGSPopupFeatureTypeChangeMode)changeMode validationError:(NSError**)validationError;


#pragma mark methods for getting validation errors and messages


/** Gets the validation error, if any, currently associated with an AGSPopupField.
 @since 100
 */
-(nullable NSError*)validationErrorForField:(AGSPopupField*)popupField;

/** Returns a string that you can display in the UI for informing the user of the valid range for numeric input.
 Only returns a non-nil value for when there is a range domain associated with the field.
 @since 100
 */
-(nullable NSString*)rangeValidationTextForField:(AGSPopupField*)popupField;

@end

/** @brief  A delegate of `AGSPopupManager`
 
 A protocol that must be adopted by any class wishing to be notified when `AGSPopupManager` detects changes in the popup's state or validity. An instance of the class must then be set as `AGSPopupManager#delegate` .

 @since 100
 */
@protocol AGSPopupManagerDelegate <NSObject>
@optional

/** Method that will get called when a new sketch editor is needed.
 @since 100
 */
-(nullable AGSSketchEditor*)sketchEditorForPopupManager:(AGSPopupManager*)popupManager;

/** Method that will get called when the valid editing state of the geo element changes.
 @since 100
 */
-(void)popupManager:(AGSPopupManager*)popupManager validityDidChange:(BOOL)geoElementValid;

/** Method that will get called when a new feature type is set.
 @since 100
 */
-(void)popupManager:(AGSPopupManager*)popupManager featureTypeDidChange:(nullable AGSFeatureType*)featureType;

@end

NS_ASSUME_NONNULL_END





