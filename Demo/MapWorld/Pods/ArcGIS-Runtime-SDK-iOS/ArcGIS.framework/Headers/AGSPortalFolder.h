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

@class AGSPortal;

/** @file AGSPortalFolder.h */ //Required for Globals API doc

/** @brief Represents a folder of content within the Portal or Organization.
 
 A user's content in a portal can be organized into folders. 
 
 @since 100
 */
@interface AGSPortalFolder : NSObject
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** The portal that the group belongs to.
 Needs to be optional because it's a weak reference.
 @since 100
 */
@property (nullable, nonatomic, weak, readonly) AGSPortal *portal;

/** The Id of the folder
 @since 100
 */
@property (nullable, nonatomic, copy, readonly) NSString *folderID;

/** The title of the folder
 @since 100
 */
@property (nullable, nonatomic, copy, readonly) NSString *title;

/** The date of creation of the folder.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) NSDate *created;

NS_ASSUME_NONNULL_END
@end
