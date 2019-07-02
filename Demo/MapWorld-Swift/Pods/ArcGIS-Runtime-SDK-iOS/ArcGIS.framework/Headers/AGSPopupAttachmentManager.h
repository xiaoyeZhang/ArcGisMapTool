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

@class AGSArcGISFeature;
@class AGSPopupAttachment;

/** @brief Manages attachments belonging to a popup
 
 Instances of this class represent a light-weight and coarse-grained object for managing attachments of a popup.
 
 It is useful for dealing with attachments (`AGSPopupAttachment`) if you want to create your own View Controller for displaying popups and attachments. It is used by `AGSPopupManager` and available for you to use through `AGSPopupManager#attachmentManager`.

 @since 100
 */
@interface AGSPopupAttachmentManager : NSObject
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)initWithFeature:(AGSArcGISFeature*)feature;

#pragma mark -
#pragma mark properties

#pragma mark -
#pragma mark methods

/** Fetch the attachments that belong to the popup. Once complete then you can access the `#attachments`.
 @param completion block that is invoked when the operation completes.
 @return operation that can be canceled
 @since 100
 */
-(id<AGSCancelable>)fetchAttachmentsWithCompletion:(nullable void(^)(NSArray<AGSPopupAttachment*>* __nullable attachments, NSError* __nullable error))completion;

/** Returns all the current attachments. Will be empty if attachments haven't yet been fetched.
 @return popup's attachments
 @since 100
 @see`#fetchAttachmentsWithCompletion:` to fetch attachments
 */
-(NSArray<AGSPopupAttachment*>*)attachments;

/** Returns the attachments filtered for types that `AGSPopupsViewController` can display (see `AGSPopupAttachmentType
`) and sorted alphabetically by name.  Will be empty if attachments haven't yet been fetched.
 @return popup's attachments that are supported for display
 @since 100
 @see`#fetchAttachmentsWithCompletion:` to fetch attachments
 */
-(NSArray<AGSPopupAttachment*>*)filteredAndSortedAttachments;

/** Delete the specified attachment.
@note This edit doesn't go into the table until changes are applied to the table through `AGSPopupManager#finishEditingWithCompletion:`. However, the attachment will no longer be available in `#attachments`
 @param attachment to delete
 @since 100
 */
-(void)deleteAttachment:(AGSPopupAttachment*)attachment;

/** Add the specified image as an attachment.
 @note This edit doesn't go into the table until changes are applied to the table through `AGSPopupManager#finishEditingWithCompletion:`. However, the attachment will be available in `#attachments`
 @param image to be added as attachment
 @param name of the attachment
 @return popup attachment
 @since 100
 */
-(nullable AGSPopupAttachment*)addAttachmentAsJPGWithImage:(AGSImage*)image name:(NSString*)name preferredSize:(AGSPopupAttachmentSize)preferredSize;

/** Add the specified data as an attachment.
 @note This edit doesn't go into the table until changes are applied to the table through `AGSPopupManager#finishEditingWithCompletion:`. However, the attachment will be available in `#attachments`
 @param data to be added as attachment
 @param name of the attachment
 @param contentType MIME type of the data
 @return popup attachment
 @since 100
 */
-(AGSPopupAttachment*)addAttachmentWithData:(NSData*)data name:(NSString*)name contentType:(NSString*)contentType preferredSize:(AGSPopupAttachmentSize)preferredSize;


#if TARGET_OS_IPHONE && !TARGET_OS_TV

/** Add the specified image as an attachment.
 @note This edit doesn't go into the table until changes are applied to the table through `AGSPopupManager#finishEditingWithCompletion:`. However, the attachment will be available in `#attachments`
 @param info dictionary provided by `UIImagePickerController`
 @param baseName name of the attachment without the file extension.
 @param completion block that is invoked when the operation completes.
 @since 100
 */
-(void)addAttachmentWithUIImagePickerControllerInfoDictionary:(NSDictionary*)info
                                                         name:(NSString*)baseName
                                                preferredSize:(AGSPopupAttachmentSize)preferredSize
                                                   completion:(void (^)(AGSPopupAttachment *attachment))completion;
#endif

/** Returns the base-name for a new attachment if you need to display a recommended name for an attachment before it's added.
 @since 100
 */
-(NSString*)basenameForNewAttachmentWithType:(AGSPopupAttachmentType)type;

NS_ASSUME_NONNULL_END
@end
