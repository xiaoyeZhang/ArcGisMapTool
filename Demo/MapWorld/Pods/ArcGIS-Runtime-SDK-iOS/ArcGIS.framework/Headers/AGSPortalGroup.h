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

#import "AGSJSONSerializable.h"

@class AGSPortal;
@class AGSLoadableImage;

/** @file AGSPortalGroup.h */ //Required for Globals API doc

/** @brief Represents a group within the Portal or Organization.
 
 An Instance of this class resource represents a group within the Portal or Organization. The owner is 
 automatically an administrator and is returned in the list of admins. Adminstrators can invite, add to
 or remove members from a group as well as update or delete the group. The administrator for an 
 organization may also reassign the group to another member of the organization. Group members may leave
 the group. Authenticated users may apply to join a group.
 
 @since 100
 */
@interface AGSPortalGroup : NSObject <AGSJSONSerializable>
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

/** Initialize a portal group with JSON content to represent an existing group in the portal.
 @param JSONObject representing the JSON content of the group
 @param portal The portal to which the group belongs to.
 @since 100
 */
+(nullable AGSPortalGroup *)fromJSON:(id)JSONObject withPortal:(AGSPortal*)portal error:(NSError**)error;

#pragma mark -
#pragma mark properties

/** The portal that the group belongs to.
 Needs to be optional because it's a weak reference.
 @since 100
 */
@property (nullable, nonatomic, weak, readonly) AGSPortal *portal;

/** Id of the group.
 @since 100
 */
@property (nullable, nonatomic, copy, readonly) NSString *groupID;

/** The group title.
 @since 100
 */
@property (nullable, nonatomic, copy, readonly) NSString *title;

/** The user who created the group. 
 @since 100
 */
@property (nullable, nonatomic, copy, readonly) NSString *owner;

/** The description of the group, if exists. 
 @since 100
 */
@property (nullable, nonatomic, copy, readonly) NSString *groupDescription;

/** Snippet or summary of the group with a character limit of 250 characters.
 @since 100
 */
@property (nullable, nonatomic, copy, readonly) NSString *snippet;

/** Words or short phrases that describe the group.
 @since 100
 */
@property (nullable, nonatomic, copy, readonly) NSArray<NSString*> *tags;

/** The date on which the group was created.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) NSDate *created;

/** The date on which the group was modified.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) NSDate *modified;

/** Determines who can access the group's conent. Can be either @c AGSPortalAccessPrivate, @c AGSPortalAccessOrganization, or @c AGSPortalAccessPublic.
 
 @c AGSPortalAccessPrivate implies only members of the group have access. @c AGSPortalAccessOrganization implies all members of the organization have access regardless of whether they are members of the group. @c AGSPortalAccessPublic implies everyone has access.
 
  @since 100
 */
@property (nonatomic, assign, readonly) AGSPortalAccess access;

/** If YES, this group will not accept join requests. Else, this group does not require an invitation to join. Only group owners and admins can invite users to the group. 
 @since 100
 */
@property (nonatomic, assign, readonly, getter=isInvitationOnly) BOOL invitationOnly;

/** The thumbnail image of the group.  
 
 If it is nil, there is no group thumbnail. Otherwise, the image needs to be loaded asynchronously by calling `AGSLoadableImage#loadWithCompletion:`
 
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSLoadableImage *thumbnail;

/** Array of strings representing users of the group. These need to be fetched explicitly using `#fetchUsersWithCompletion:`
 @since 100
 */
@property (nullable, nonatomic, copy, readonly) NSArray<NSString*> *users;

/** Array of strings representing admin users of the group. These need to be fetched explicitly using `#fetchUsersWithCompletion:`
 @since 100
 */
@property (nullable, nonatomic, copy, readonly) NSArray<NSString*> *admins;

/** Determines the sort field for the group's content. Can be either @c AGSPortalGroupSortFieldTitle, @c AGSPortalGroupSortFieldOwner, @c AGSPortalGroupSortFieldAvgRating, @c AGSPortalGroupSortFieldNumViews, @c AGSPortalGroupSortFieldCreated, or @c AGSPortalGroupSortFieldModified.
 @since 100
 */
@property (nonatomic, assign, readonly) AGSPortalGroupSortField sortField;

/** Determines the sort order for the group's content. Can be either @c AGSPortalQuerySortOrderAscending or @c AGSPortalQuerySortOrderDescending.
 @since 100
 */
@property (nonatomic, assign, readonly) AGSPortalQuerySortOrder sortOrder;

/** Determines whether the group is 'view only' or not.  Users cannot share items with 'view only' groups.
 @since 100
 */
@property (nonatomic, assign, readonly, getter=isViewOnly) BOOL viewOnly;

/** The contact information for the group.
 @since 100
 */
@property (nullable, nonatomic, copy, readonly) NSString *phone;

#pragma mark -
#pragma mark methods

/** Kicks off an operation to fetch users and admins of the group. The completion block is invoked when the operation completes successfully or if an error is encountered. When completed, the `#admins` and `#users` properties will be populated.
 @param completion block that is invoked when operation finishes
 @return operation which can be canceled
 @since 100
 */
-(id<AGSCancelable>)fetchUsersWithCompletion:(nullable void(^)(NSArray<NSString*> * __nullable users, NSArray<NSString*> * __nullable admins, NSError * __nullable error))completion;

NS_ASSUME_NONNULL_END
@end
