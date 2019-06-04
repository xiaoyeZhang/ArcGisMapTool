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

#import "AGSLoadableBase.h"
#import "AGSJSONSerializable.h"

@class AGSPortal;
@class AGSLoadableImage;
@class AGSPortalPrivilege;

/** @file AGSPortalUser.h */ //Required for Globals API doc

/** @brief An object representing a registered user of the portal or organization. 
 
 AGSPortalUser represents a registered user of a portal or organization. A Portal may have users who are
 unaffiliated with an organization or users who are part of an organization. Users sign in to the portal 
 and create and share content which is organized into Items (@c AGSPortalItem). Users can create and 
 join Groups (@c AGSPortalGroup) and share items with Groups. This makes the items visible and 
 accessible to other members of the Group. Users could be in different roles including administrators, 
 publishers and  information workers. Administrators can add  users to  their organizations and have 
 access to all content within the organization. All users can create web maps based  on mashing up 
 services that they have access to and can register services running on external servers. Publishers 
 within an organization can in addition create hosted services based on data files that they upload.
 
 @since 100
 */
@interface AGSPortalUser : AGSLoadableBase <AGSJSONSerializable>
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

/** Initializes a portal user with a portal and a username.
 @param portal The portal that the user belongs to.
 @param username The username of the user.
 @since 100
 */
-(instancetype)initWithPortal:(AGSPortal*)portal username:(NSString*)username;

/** Initialize a portal user with JSON content to represent an existing user in the portal.
 @param JSONObject representing the JSON content of the user
 @param portal The portal to which the user belongs to.
 @since 100
 */
+(nullable AGSPortalUser *)fromJSON:(id)JSONObject withPortal:(AGSPortal*)portal error:(NSError**)error;

#pragma mark -
#pragma mark properties

/** The portal that the user belongs to.
 Needs to be optional because it's a weak reference.
 @since 100
 */
@property (nullable, nonatomic, weak, readonly) AGSPortal *portal;

/** Username of the user.
 @since 100
 */
@property (nullable, nonatomic, copy, readonly) NSString *username;

/** Full name of the user.
 @since 100
 */
@property (nullable, nonatomic, copy, readonly) NSString *fullName;

/** Description of the user, if exists. 
 @since 100
 */
@property (nullable, nonatomic, copy, readonly) NSString *userDescription;

/** Email of the user
 @since 100
 */
@property (nullable, nonatomic, copy, readonly) NSString *email;

/** The id of the organization if the user belongs to an organization. 
 @since 100
 */
@property (nullable, nonatomic, copy, readonly) NSString *organizationID;

/** Words or short phrases that describe the user.
 @since 100
 */
@property (nullable, nonatomic, copy, readonly) NSArray<NSString*> *tags;

/** Groups that the user is a member of.
 @since 100
 */
@property (nullable, nonatomic, copy, readonly) NSArray<AGSPortalGroup*> *groups;

/**  Determines if other users can search for this user's name to find content and groups owned by this
 user and to invite this user to join their groups.  Can be @ AGSPortalAccessPrivate, @c AGSPortalAccessOrganization, or @c AGSPortalAccessPublic. 
 
 @c AGSPortalAccessPrivate implies the user is hidden and others cannot search for the user or view his/her information. @c AGSPortalAccessOrganization implies only members of the organization can search for or view the user's information. @c AGSPortalAccessPublic implies anyone can search for or access the user's information.
 @since 100
 */
@property (nonatomic, assign, readonly) AGSPortalAccess access;

/** The date on which the user account was created. 
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) NSDate *created;

/** The date on which the user account was modified. 
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) NSDate *modified;

/** The role of the user within the organization.
 @since 100
 */
@property (nonatomic, assign, readonly) AGSPortalUserRole role;

/** The ID of the group that contains the user’s favorites.
 @since 100
 */
@property (nullable, nonatomic, copy, readonly) NSString *favoritesGroupID;

/** The units preference of the user.
 @since 100
 */
@property (nonatomic, assign, readonly) AGSUnitSystem units;

/** The thumbnail image of the user. 
 
 If it is nil, there is no thumbnail. Otherwise, the image needs to be loaded asynchronously by calling `AGSLoadableImage#loadWithCompletion:`
 
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSLoadableImage *thumbnail;

/** An array of `AGSPortalPrivilege` objects defining the fine-grained privileges possessed by this user.
 @since 100
 */
@property (nullable, nonatomic, copy, readonly) NSArray<AGSPortalPrivilege*> *privileges;

#pragma mark -
#pragma mark methods

/** Kicks off an operation that fetches the user's content at the root level (meaning, not under any sub-folder).  The completion block is invoked when the operation completes successfully or if an error is encountered. Items are returned as an array of `AGSPortalItem` objects, and folders are returned as an array of `AGSPortalFolder`.
 @param completion block that is invoked when operation finishes
 @return operation which can be canceled
 @since 100
 */
-(id<AGSCancelable>)fetchContentWithCompletion:(void(^)(NSArray<AGSPortalItem*> * __nullable items, NSArray<AGSPortalFolder*> * __nullable folders, NSError * __nullable error))completion;

/** Kicks off an operation that fetches the user's content within the specified folder. The completion block is invoked when the operation completes successfully or if an error is encountered. Items are returned as an array of `AGSPortalItem` objects.
 @param folderID The the id of the folder to fetch the content from.
 @param completion block that is invoked when operation finishes
 @return operation which can be canceled
 @since 100
 */
-(id<AGSCancelable>)fetchContentInFolder:(nullable NSString*)folderID completion:(void(^)(NSArray<AGSPortalItem*> * __nullable items, NSError * __nullable error))completion;

/** Adds the given item to the user's favorites group.
 @param item The portal item to add.
 @param completion block that is invoked when operation finishes
 @return operation which can be canceled
 @since 100
 */
-(id<AGSCancelable>)addToFavorites:(AGSPortalItem *)item completion:(nullable void(^)(NSError * __nullable error))completion;

/** Removes the given item from the user's favorites group.
 @param item The portal item to remove.
 @param completion block that is invoked when operation finishes
 @return operation which can be canceled
 @since 100
 */
-(id<AGSCancelable>)removeFromFavorites:(AGSPortalItem *)item completion:(nullable void(^)(NSError * __nullable error))completion;

/** Determines whether the given item is in the user's favorites group.
 @param item The portal item to check.
 @param completion block that is invoked when operation finishes
 @return operation which can be canceled
 @since 100
 */
-(id<AGSCancelable>)fetchFavoriteStatus:(AGSPortalItem *)item completion:(void(^)(BOOL isFavorite, NSError * __nullable error))completion;

/** Creates a new folder with the given title in the user's root folder (nested folders are not supported).
 The 'folder' parameter in the completion block is the newly created AGSPortalFolder.
 @param title The title for the new folder.
 @param completion block that is invoked when operation finishes.
 @return operation which can be canceled
 @license{Basic}
 @ingroup licensing
 @since 100
 */
-(id<AGSCancelable>)createFolder:(NSString *)title
                       completion:(nullable void(^)(AGSPortalFolder * __nullable folder, NSError * __nullable error))completion;

/** Deletes the given folder from the portal.  Deleting a folder also deletes all items that it contains.
 Note that you cannot delete a user's root folder, so the 'folder' parameter must be non-nil.
 @param folder The folder to delete.
 @param completion block that is invoked when operation finishes.
 @return operation which can be canceled
 @license{Basic}
 @ingroup licensing
 @since 100
 */
-(id<AGSCancelable>)deleteFolder:(AGSPortalFolder *)folder completion:(nullable void(^)(NSError * __nullable error))completion;

/** Deletes an item from the portal.
 @param portalItem The item to be deleted from the portal.
 @param completion block that is invoked when operation finishes
 @return operation which can be canceled
 @license{Basic}
 @ingroup licensing
 @since 100
 */
-(id<AGSCancelable>)deletePortalItem:(AGSPortalItem*)portalItem completion:(nullable void(^)(NSError * __nullable error))completion;

/** Adds the specified item to the portal at the given folder.
 @param portalItem The new item to be added to the portal.
 @param contentParameters The portal item content parameters for the item to be added.
 @param folder The folder in which to create the item. If nil is passed it will
 be added to the user's root folder.
 @param completion block that is invoked when operation finishes
 @return operation which can be canceled
 @license{Basic}
 @ingroup licensing
 @since 100
 */
-(id<AGSCancelable>)addPortalItem:(AGSPortalItem*)portalItem
            withContentParameters:(nullable AGSPortalItemContentParameters*)contentParameters
                          toFolder:(nullable AGSPortalFolder*)folder
                        completion:(nullable void(^)(NSError * __nullable error))completion;

/** Moves a portal item to a new folder.  Passing nil for the 'folder' parameter will move the item to the user's root folder.
 @param portalItem The item to move.
 @param folder The folder to move the item to
 @param completion block that is invoked when operation finishes.
 @return operation which can be canceled
 @license{Basic}
 @ingroup licensing
 @since 100
 */
-(id<AGSCancelable>)movePortalItem:(AGSPortalItem *)portalItem
                           toFolder:(nullable AGSPortalFolder *)folder
                         completion:(nullable void(^)(NSError * __nullable error))completion;

/** Moves an array of portal items to a new folder.  Passing nil for the 'folder' parameter will move the item to the user's root folder.
 The `moveErrors` parameter in the completion block is a dictionary of itemIDs to errors that occurred when trying to move a particular portal item.
 The `error` parameter of the completion block is an overall error (like an HTTP error).
 @param portalItems The items to move. Items must be loaded and have an itemID.
 @param folder The folder to move the item to
 @param completion block that is invoked when operation finishes.
 @return operation which can be canceled
 @license{Basic}
 @ingroup licensing
 @since 100
 */
-(id<AGSCancelable>)movePortalItems:(NSArray<AGSPortalItem*> *)portalItems
                            toFolder:(nullable AGSPortalFolder *)folder
                          completion:(nullable void(^)(NSDictionary<NSString*,NSError*> * __nullable moveErrors, NSError * __nullable error))completion;

NS_ASSUME_NONNULL_END
@end
