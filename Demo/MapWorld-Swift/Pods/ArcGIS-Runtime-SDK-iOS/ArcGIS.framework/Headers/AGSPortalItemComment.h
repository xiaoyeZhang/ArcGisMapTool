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

/** @file AGSPortalItemComment.h */ //Required for Globals API doc

/** @brief A comment for a portal's item
 
 Instances of this class represent comments about an item in the portal.
 
 @since 100
 */
@interface AGSPortalItemComment : NSObject
NS_ASSUME_NONNULL_BEGIN

/** The owner of the comment.
 @since 100
 */
@property (nullable, nonatomic, copy, readonly) NSString *owner;

/** The Id of the comment.
 @since 100
 */
@property (nullable, nonatomic, copy, readonly) NSString *commentID;

/** The text of the comment.
 @since 100
 */
@property (nullable, nonatomic, copy, readonly) NSString *comment;

/** The date of creation of the comment.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) NSDate *created;

NS_ASSUME_NONNULL_END
@end
