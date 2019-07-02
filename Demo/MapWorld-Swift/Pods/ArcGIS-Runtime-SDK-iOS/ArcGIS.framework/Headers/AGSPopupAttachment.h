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

#import "AGSLoadableBase.h"

@class AGSImage;
@class AGSAttachment;

/** @brief An attachment belonging to a popup.
 
 Instances of this class represent an attachment belonging to a popup (`AGSPopup`).
 
 This class  provides a wrapper around the underlying `AGSAttachment` from `AGSArcGISFeature`,
 which makes it easier to deal with than dealing with `AGSAttachment`s directly.
 
 This object is considered "Loaded" when it has a `#filepath`. The `#name`,
 `#contentType` are always available. The `#actualSize` property is available before the attachment 
 is loaded except for in the case when the attachment is created with a URL, in which the `#actualSize` will
 return -1 until it's loaded.
 
 The `#filepath` is the main aspect of this object that is "Loadable".
 
 Because "Loaded" means that we have the attachment data saved to a temporary location
 on disk, attachments can be "Local" but not yet loaded. However if it is Loaded, then it is always "Local".
 
 @since 100
 @see `AGSPopupAttachmentManager` for creating, editing, and managing attachments
 */
@interface AGSPopupAttachment : AGSLoadableBase
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers


#pragma mark -
#pragma mark properties

/** The name of the attachments
 @since 100
 */
@property (nullable, nonatomic, copy, readonly) NSString *name;

/** The MIME content type of the attachment.
 @since 100
 */
@property (nullable, nonatomic, copy, readonly) NSString *contentType;

/** The size in bytes of the original attachment. Not taking into account the preferred size.
 @since 100
 */
@property (nonatomic, assign, readonly) NSInteger actualSizeInBytes;

/** The current edit state of the attachment.
 When adding or removing attachments the edit state of each attachment will be set accordingly. Once you apply the changes through the `AGSPopupAttachmentManager` then the edit state will be set to `AGSPopupAttachmentEditStateOriginal`
 @since 100
 */
@property (nonatomic, assign, readonly) AGSPopupAttachmentEditState editState;

/** The underlying attachment that this object wraps and helps with.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSAttachment *featureAttachment;


/** Returns the type of the attachment.
 @since 100
 */
@property (nonatomic, assign, readonly) AGSPopupAttachmentType type;

/** The size the attachment should be saved as. This property is only has an affect on attachments that have not been added to the table yet. Only applies to images, not videos.
 @since 100
 */
@property (nonatomic, assign, readwrite) AGSPopupAttachmentSize preferredSize;

/** If the attachment is an image, and it has an edit state of added then preferredSize can be set.
 @since 100
 */
@property (nonatomic, assign, readonly) BOOL supportsPreferredSize;

/** Indicates whether or not "loading" (fetching the data) will cause it to go over the network. False if the loading will cause a network request. True if it just needs to pull the data from a database.
 @since 100
 */
@property (nonatomic, assign, readonly) BOOL isLocal;

/** The local temporary filepath where we store the attachment once it's loaded. Returns nil if the attachment is not loaded.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) NSURL *fileURL;

#pragma mark -
#pragma mark methods

/** Generates a thumbnail for the attachment. Causes the attachment to load if necessary.
 The image will be scaled with aspect fill.
 @param size of the desired thumbnail image (in points)
 @param completion block that is invoked when the operation completes.
 @since 100
 */
-(void)generateThumbnailWithSize:(float)size completion:(void(^)(AGSImage * _Nullable image))completion;

/** Generates a thumbnail for the attachment. Causes the attachment to load if necessary.
 @param size of the desired thumbnail image (in points)
 @param scaleMode of the desired thumbnail image
 @param completion block that is invoked when the operation completes.
 @since 100.3
 */
-(void)generateThumbnailWithSize:(float)size scaleMode:(AGSImageScaleMode)scaleMode completion:(void(^)(AGSImage * _Nullable image))completion;

/**
 Gets the size of the attachment in bytes, taking into account the preferred size. 
 If preferred size is not supported then returns the actual size.
 @since 100
 */
-(void)sizeInBytesForPreferredSizeWithCompletion:(void(^)(NSInteger sizeInBytes))completion;

#if TARGET_OS_IPHONE && !TARGET_OS_TV

/** Gets the full image for displaying the attachment in a full screen or some UI larger than a thumbnail.
 @param completion block that is invoked when the operation completes.
 @since 100
 */
-(void)fullDisplayImageWithCompletion:(void(^)(AGSImage * _Nullable image))completion;

#endif

NS_ASSUME_NONNULL_END
@end

