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

#import "AGSObject.h"

/** @file AGSAttachment.h */ //Required for Globals API doc

/** @brief Information about a feature attachment
 
 Instances of this class represent information about an attachment that is associated with a feature.
 
 @since 100
 */
@interface AGSAttachment : AGSObject

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

- (instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** The MIME type of the attachment
 @since 100
 */
@property (nonatomic, copy, readonly) NSString *contentType;

/** The name of the attachment
 @since 100
 */
@property (nonatomic, copy, readonly) NSString *name;

/** The size of the attachment in bytes
 @since 100
 */
@property (nonatomic, assign, readonly) NSInteger size;

/** Indicates whether the attachment data has already been retrieved.
 Even if the data has been retrieved previously, you will still need to call `#fetchDataWithCompletion:` to get the data, however that operation should complete quickly since the data is already available locally and so you can request it proactively. Otherwise, it could take some time to retrieve the data from its source, and you should fetch the data only when the user explicitly asks for it.
 @since 100
 */
@property (nonatomic, assign, readonly) BOOL hasFetchedData;

/** The ID of the attachment
 @since 100
 */
@property (nonatomic, assign, readonly) NSInteger attachmentID;

#pragma mark -
#pragma mark methods

/** Fetches the raw data for the attachment 
 @param completion block that is invoked when the operation completes
 @return operation which can be canceled
 @since 100
 */
-(id<AGSCancelable>)fetchDataWithCompletion:(nullable void(^)(NSData *__nullable result, NSError *__nullable error))completion;

NS_ASSUME_NONNULL_END

@end
