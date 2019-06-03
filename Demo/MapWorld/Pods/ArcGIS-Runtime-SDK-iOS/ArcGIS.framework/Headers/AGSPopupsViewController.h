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
@protocol AGSPopupsViewControllerDelegate;
@class AGSPopupViewController;
@class AGSGeometry;
@class AGSGeometryBuilder;
@class AGSPopup;
@class AGSViewController;
@class AGSPopupsViewControllerTheme;
@class AGSSketchEditor;

/** @file AGSPopupsViewController.h */ //Required for Globals API doc

/**@brief A view controller for displaying popups
 
 Instances of this class represent a view controller that provides the basic user interface
 (UI) and behavior for displaying and editing information about graphics in a popup. It is a container 
 and manages a number of view controllers behind the scenes, each of which is designed for a specific purpose, 
 such as editing an attribute, displaying media, managing attachments, etc.
 It manages transitions between these view controllers and displays the relevant one
 depending upon what the user intends to do.
 @see @concept{working-with-web-map-popups.htm, Working With Web Map Popups}
 @see @sample{2ddb261648074b9aabb22240b6975918, Feature Layer Editing}
 @ios
 @note The view controller needs access to the device photo library and camera in order to add image attachments to the popup. The app's Info.plist must contain the `NSPhotoLibraryUsageDescription` and `NSCameraUsageDescription` keys to permit this functionality.
 @endios
 @since 100
 */

@interface AGSPopupsViewController : AGSViewController
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

/** Initializes an AGSPopupsViewController.
 @param popups An array of AGSPopup objects representing the popups to be displayed
 @since 100
 */
-(instancetype)initWithPopups:(nullable NSArray<AGSPopup*>*)popups;


/** Initializes an AGSPopupsViewController.
 @param popups An array of AGSPopup objects representing the popups to be displayed
 @since 100
 */
+(instancetype)popupsViewControllerWithPopups:(nullable NSArray<AGSPopup*>*)popups;

#pragma mark -
#pragma mark properties

/** The delegate to be notified when a user interacts with the popups or
 edits graphics related to the popups. The delegate class
 must adopt the @c AGSPopupsViewControllerDelegate protocol.
 @since 100
 */
@property (nonatomic, weak, nullable) id<AGSPopupsViewControllerDelegate> delegate;

/**
 The popups to be displayed.
 @since 100
 */
@property (nonatomic, copy, nullable) NSArray<AGSPopup*> *popups;

/** Indicates whether the view controller is in the process of editing a feature.
 @since 100
 */
@property (nonatomic, assign, readonly) BOOL inEditingMode;

/** When in edit mode and geometry editing is allowed, this property
 returns the sketchEditor for editing the popup's geometry. This is the sketchEditor you passed to the @c AGSPopupsViewController in the @c popupsViewController:sketchEditorForPopup: delegate method.
 When editing is finished, the geometry of the sketch editor will be set on the current popup's graphic.
 @since 100
 */
@property (nonatomic, strong, readonly) AGSSketchEditor *currentSketchEditor;

/** The current popup that is being viewed.
 @since 100
 */
@property (nonatomic, strong, readonly, nullable) AGSPopup *currentPopup;

/** Defines the look and feel of the PopupsViewController.
 @since 100
 */
@property (nonatomic, strong, readwrite) AGSPopupsViewControllerTheme *theme;

/** The default size that new attachments created and committed to a feature will have.
 @since 100
 */
@property (nonatomic, assign, readwrite) AGSPopupAttachmentSize defaultAttachmentSize;

#pragma mark -
#pragma mark methods

/**
 Update the view controller to display additional popups. This is useful
 when the view controller is already displaying some popups,
 but you then want to display additional popups that were retrieved in the
 background, for example, as part of a query/identify operation.
 @param popups An array of @c AGSPopup objects representing the additional popups to be displayed
 @since 100
 */
-(void)showAdditionalPopups:(NSArray<AGSPopup*> *)popups;

/** Start editing mode for the currently shown popup.
 @since 100
 */
-(void)startEditingCurrentPopup;

/** Exit editing mode for the currently shown popup.
 @param completion block that is invoked when the operation completes. The error argument is populated if a problem is encountered (for example, if one of the feature's attribute values does not satisfy its constraints) in which case the editing mode is not ended.
 @since 100
 */
-(void)finishEditingCurrentPopupWithCompletion:(nullable void(^)(NSError *__nullable error))completion;

/** Cancels the editing process for the currently shown popup.
 @since 100
 */
-(void)cancelEditingCurrentPopup;

/** Clears all the popups currently being shown. This is useful if you want to reuse an
 existing popups container to display an entirely new set of popups. That way,
 the popups container doesn't have to reload from a NIB
 everytime it is shown.
 @since 100
 */
-(void)clearAllPopups;

#pragma mark -
#pragma mark iPhone

#if TARGET_OS_IPHONE

/** Initializes an AGSPopupsViewController.
 @param popups An array of AGSPopup objects representing the popups to be displayed
 @param containerStyle specifies how the popups view controller will be displayed in its container.  See @c AGSPopupsViewControllerContainerStyle
 @since 100
 */
-(instancetype)initWithPopups:(nullable NSArray<AGSPopup*> *)popups containerStyle:(AGSPopupsViewControllerContainerStyle)containerStyle;

/** Initializes an AGSPopupsViewController.
 @param popups An array of AGSPopup objects representing the popups to be displayed
 @param containerStyle specifies how the popups view controller will be displayed in its container.  See @c AGSPopupsViewControllerContainerStyle
 @since 100
 */
+(instancetype)popupsViewControllerWithPopups:(nullable NSArray<AGSPopup*> *)popups containerStyle:(AGSPopupsViewControllerContainerStyle)containerStyle;

/** The current done button that appears on the left side of the Navigation Bar when 
 the popup is in viewing mode (not editing).
 @since 100
 */
@property (nonatomic, strong, readonly, nullable) UIBarButtonItem *doneButton;

/** You can replace the button that appears on the left side of the Navigation Bar
 with a custom button through this property.
 This only applies to when the popup is in viewing mode (not editing).
 @since 100
 */
@property (nonatomic, strong, readwrite, nullable) UIBarButtonItem *customDoneButton;

/** The current button that appears on the right side of the Navigation Bar
 when the popup is in viewing mode (not editing).
 @since 100
 */
@property (nonatomic, strong, readonly, nullable) UIBarButtonItem *actionButton;

/** You can replace the button that appears on the right side of the Navigation Bar
 with a custom button through this property.
 This only applies to when the popup is in viewing mode (not editing).
 @since 100
 */
@property (nonatomic, strong, readwrite, nullable) UIBarButtonItem *customActionButton;

/** The style that is used for editing.
 @since 100
 */
@property (nonatomic, assign) AGSPopupsViewControllerGeometryEditingStyle geometryEditingStyle;

/** The UIViewController that should be used for presenting modal view controllers
 from within this AGSPopupsViewController. This is useful when using this view controller
 as a standalone object (for example, in a custom callout or a custom view)  and when it's not part of a view controller hierarchy.
 @since 100
 */
@property (nonatomic, strong, nullable) UIViewController *modalPresenter;

#endif

NS_ASSUME_NONNULL_END
@end

