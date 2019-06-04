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

@class AGSPopup;
@class AGSSketchEditor;
@class AGSPopupsViewController;

/** @file AGSPopupsViewControllerDelegate.h */ //Required for Globals API doc

/** @brief A delegate of @c AGSPopupsViewController
 
  A protocol that must be adopted by any class wishing to be notified when @c AGSPopupsViewController detects user interaction with popups or if a user tries to edit a popup. An instance of the class must then be set as @c AGSPopupsViewController#delegate .
 
 All methods of this protocol are optional.
 @since 100
 */
@protocol AGSPopupsViewControllerDelegate <NSObject>
NS_ASSUME_NONNULL_BEGIN
@optional

/** Tells the delegate that a sketch editor is required for an @c AGSPopup. The popupsViewController will listen for changes to the @c AGSSketchEditor to determine when the geometry is in a valid state. Depending upon the type of geometry (point, polygon, polyline, etc) required for the @c id<AGSGeoElement>, the delegate must return a sketch editor for editing the appropriate type of geometry. At this point the sketchEditor should be started and assigned to the appropriate @c AGSMapView.
 @param popupsViewController The popup view controller
 @param popup Popup of the @c id<AGSGeoElement> for which a sketchEditor is required.
 @since 100
 */
-(nullable AGSSketchEditor*)popupsViewController:(AGSPopupsViewController *)popupsViewController sketchEditorForPopup:(AGSPopup*)popup;

/** Tells the delegate that a user is ready to edit the geometry for
 the current popup. This will happen when the user clicks the toolbar item for
 editing the geometry. Or if the editing mode is "Geometry Inline", it will happen when
 editing begins. 
 The sketchEditor is the sketchEditor that was earlier passed to the popupsViewController through the @c popupsViewController:sketchEditorForPopup: delegate method.
 If you want to make programmatic changes to the popup's geometry, you should go through this sketchEditor. 
 This allows the popupsViewController to know when the geometry changes so that it can update it's UI appropriately (ie. enabling the "Done" button).
 @param popupsViewController The popup view controller
 @param sketchEditor The sketchEditor that should be used for editing a popup's geometry.
 @param popup whose @c id<AGSGeoElement>'s geometry needs to be edited
 @since 100
 */
-(void)popupsViewController:(AGSPopupsViewController *)popupsViewController readyToEditGeometryWithSketchEditor:(nullable AGSSketchEditor*)sketchEditor forPopup:(AGSPopup*)popup;

/** The method called by the AGSPopupsViewController when the user begins editing the current popup.
 @param popupsViewController The popup view controller
 @param popup whose @c id<AGSGeoElement> needs to be edited
 @since 100
 */
-(void)popupsViewController:(AGSPopupsViewController *)popupsViewController didStartEditingForPopup:(AGSPopup*)popup;

/** The method called by the AGSPopupsViewController when the user is done editing the current popup.
 This method is called before @c popupsViewController:didFinishEditingForPopup and it
 is also called before feature updates are submitted to its table (when dealing with AGSFeature objects).
 @param popupsViewController The popup view controller
 @param popup whose @c id<AGSGeoElement> was edited
 @since 100.3
 */
-(void)popupsViewController:(AGSPopupsViewController *)popupsViewController willFinishEditingForPopup:(AGSPopup*)popup;

/** The method called by the AGSPopupsViewController when the user is done editing the current popup.
 @note This is where you might make the appropriate calls to keep the server in sync with the client. For example, you might call @c applyEditsWithCompletion if dealing with @c AGSArcGISFeature objects.
 @param popupsViewController The popup view controller
 @param popup whose @c id<AGSGeoElement> was edited
 @since 100
 */
-(void)popupsViewController:(AGSPopupsViewController *)popupsViewController didFinishEditingForPopup:(AGSPopup*)popup;

/** The method called by the AGSPopupsViewController when the user tries to finish editing but errors were encountered.
 If you implement this method then you are responsible for showing any UI that should be shown when an editing error
 occurs. If you do not implement this method the AGSPopupsViewController will show an alert depicting the localized description of the error.
 @param popupsViewController The popup view controller
 @param popup whose @c id<AGSGeoElement> was edited
 @param error that occurred when trying to finish editing
 @since 100
 */
-(void)popupsViewController:(AGSPopupsViewController *)popupsViewController didFailToFinishEditingForPopup:(AGSPopup*)popup withError:(NSError*)error;

/** The method called by the AGSPopupsViewController when the user cancels editing the current popup.
 @param popupsViewController The popup view controller
 @param popup whose @c id<AGSGeoElement> was started to be edited but later canceled
 @since 100
 */
-(void)popupsViewController:(AGSPopupsViewController *)popupsViewController didCancelEditingForPopup:(AGSPopup*)popup;

/** The method called by the AGSPopupsViewController when the user confirms they want to delete the @c id<AGSGeoElement>.
 The implementer of this method must actually delete the @c id<AGSGeoElement>.
 @note This method will only be called for popups with a @c id<AGSGeoElement> that we don't know how to delete.
 Currently, the popup only knows how to delete @c AGSArcGISFeature objects. This method will be called for all other types of @c id<AGSGeoElement> objects.
 @param popupsViewController The popup view controller
 @param popup whose @c id<AGSGeoElement> needs to be deleted
 @return Whether or not the popup was successfully deleted
 @since 100
 */
-(BOOL)popupsViewController:(AGSPopupsViewController *)popupsViewController wantsToDeleteForPopup:(AGSPopup*)popup;

/** The method called by the AGSPopupsViewController when a @c id<AGSGeoElement> was successfully deleted.
 @param popupsViewController The popup view controller
 @param popup whose @c id<AGSGeoElement> was deleted
 @since 100
 */
-(void)popupsViewController:(AGSPopupsViewController *)popupsViewController didDeleteForPopup:(AGSPopup*)popup;

/** The method called by the AGSPopupsViewController when it fails to delete a @c id<AGSGeoElement>.
 If you do not implement this method then AGSPopupsViewController will show an alert to the user with the error.
 If you do implement this method then you are responsible for bubbling up the error to the user.
 @param popupsViewController The popup view controller
 @param popup whose @c id<AGSGeoElement> was meant to be deleted
 @param error that occurred
 @since 100
 */
-(void)popupsViewController:(AGSPopupsViewController *)popupsViewController didFailToDeleteForPopup:(AGSPopup*)popup withError:(NSError*)error;

/** The method that is called when the user is done viewing the popups.
 @param popupsViewController The popup view controller
 @since 100
 */
-(void)popupsViewControllerDidFinishViewingPopups:(AGSPopupsViewController *)popupsViewController;

/** The method called by the AGSPopupsViewController when a popup's validity is changed. This happens
 when the geometry or attributes of the popup's @c id<AGSGeoElement> are changed. isValid will be YES if it is
 determined that a @c id<AGSGeoElement> meets it's requirements to be saved to it's datasource.
 This method is useful if you have your own "finish editing" button and you want to enable/disable it
 when the @c id<AGSGeoElement> is valid.
 @param popupsViewController The popup view controller
 @param isValid Whether or not the @c id<AGSGeoElement> meets it's known requirements to be saved to it's datasource.
 @since 100
 */
-(void)popupsViewController:(AGSPopupsViewController *)popupsViewController validityChanged:(BOOL)isValid forPopup:(AGSPopup*)popup;

#if TARGET_OS_IPHONE

/** The AGSPopupsViewController will call this method on the delegate when a view controller needs to be presented.
 This method is optional, but if you want to show view controllers in different ways than the standard modal way,
 then you need to implement this method.
 @param popupsViewController The popup view controller
 @param svc The view controller that needs to be displayed
 @param viewType The predefined type of the view controller
 @param fvc The view controller that is currently being displayed
 @param rect The rect is in the coordinate space of the fromViewController. Only applicable if viewType is @c AGSPopupViewControllerTypeUIImagePicker
 @since 100
 */
-(void)popupsViewController:(AGSPopupsViewController *)popupsViewController wantsToShowViewController:(AGSViewController *)svc ofType:(AGSPopupViewControllerType)viewType fromViewController:(AGSViewController*)fvc atRect:(CGRect)rect;

/** The AGSPopupsViewController will call this method on the delegate when a view controller needs to be hidden.
 You need to implement this if you implement popupsViewController:wantsToShowViewController:fromViewController:atRect,
 so that you can hide a view controller in the proper way if you've shown it in a custom manner.
 @param popupsViewController The popup view controller
 @param vc The view controller that needs to be hidden
 @param viewType the predefined type of the view controller
 
 @since 100
 */
-(void)popupsViewController:(AGSPopupsViewController *)popupsViewController wantsToHideViewController:(AGSViewController*)vc ofType:(AGSPopupViewControllerType)viewType;

/** The AGSPopupsViewController will call this delegate method when it one of it's view controllers
 needs to know if it can auto-rotate to a certain interface orientation. If you don't implement this
 method then we just always return YES.
 @param popupsViewController The popup view controller
 @param vc The view controller that needs to respond to orientation change
 @param viewType the predefined type of the view controller  
 @since 100
 */
-(BOOL)popupsViewController:(AGSPopupsViewController *)popupsViewController shouldAutorotateForViewController:(UIViewController*)vc ofType:(AGSPopupViewControllerType)viewType;

/** Implement this method if you want to provide a custom header view for the popup.
 @param popupsViewController The popup view controller
 @param popup The popup the header view will display for
 @since 100
 */
-(nullable UIView*)popupsViewController:(AGSPopupsViewController *)popupsViewController headerViewForPopup:(AGSPopup*)popup;

/** Implement this method if you want to provide a custom footer view for the popup.
 @param popupsViewController The popup view controller
 @param popup The popup the footer view will display for
 @since 100
 */
-(nullable UIView*)popupsViewController:(AGSPopupsViewController *)popupsViewController footerViewForPopup:(AGSPopup*)popup;

#endif

/** The AGSPopupsViewController will call this method when the currently showing popup changes.
 @param popupsViewController The popup view controller
 @param popup which is currently being displayed
 @since 100
 */
-(void)popupsViewController:(AGSPopupsViewController *)popupsViewController didChangeToCurrentPopup:(AGSPopup*)popup;

/** The AGSPopupsViewController will call this method when there is a document that it wants to preview. 
 By default, if this method is not implemented, it will preview the document with a UIDocumentInteractionController. 
 If you have need to hide or show popovers before previewing you should implement this method and 
 create the UIDocumentInteractionController manually.
 @since 100
 */
-(void)popupsViewController:(AGSPopupsViewController *)popupsViewController wantsToPreviewDocumentAtURL:(NSURL*)documentURL fromViewController:(AGSViewController*)fvc atRect:(CGRect)rect;

/** The AGSPopupsViewController will call this when the user switches a feature type for the current popup.
 Potentially at this point symbology will change for the feature. Currently this is only called for @c AGSArcGISFeature popups.
 @since 100
 */
-(void)popupsViewController:(AGSPopupsViewController *)popupsViewController didChangeFeatureTypeForPopup:(AGSPopup *)popup;

#if TARGET_OS_MAC && (!TARGET_OS_IPHONE)

/** The AGSPopupsViewController will call this when the user opens a window containing an attachment or media object.
 If this method is not implemented, the window will close when the popup is removed from the popups view controller.
 @since 100
 */
-(void)popupsViewController:(AGSPopupsViewController *)popupsViewController didShowWindow:(NSWindow *)window forPopup:(AGSPopup *)popup;

#endif

NS_ASSUME_NONNULL_END
@end

