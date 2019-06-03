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

@class AGSEnvelope;
@class AGSPortal;
@class AGSPortalItemComment;
@class AGSLoadableImage;
@class AGSLoadableValue;
@class AGSPortalGroup;

#import "AGSItem.h"
#import "AGSLoadable.h"
#import "AGSJSONSerializable.h"

/** @file AGSPortalItem.h */ //Required for Globals API doc 


/** @brief Object representing a unit of content in an ArcGIS portal.
 
 An AGSPortalItem is a unit of content in the AGSPortal.  Each item has a unique identifier and a well-
 known URL that is independent of the user owning the item. An item may have associated binary or 
 textual data which has to be fetched explicitly using @c `#fetchDataWithCompletion:`.  For example, an item of type @c AGSPortalItemTypeMapPackage will
 fetch the actual bits corresponding to the map package.
 
 @since 100
 */
@interface AGSPortalItem : AGSItem <AGSLoadable, AGSJSONSerializable>
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

/** Initialize a new portal item. The item doesn't exist yet on a portal, and will need to be added using `AGSPortalUser#addPortalItem:withContentParams:toFolder:completion:`
 @param portal where this item will eventually be added
 @return A new portal item
 @since 100
 */
-(instancetype)initWithPortal:(AGSPortal*)portal;

/** Initialize a portal item with a portal and item id to represent an existing item in the portal
 @param portal The portal to which the item belongs to.
 @param itemID The ID of the existing item in the portal
 @since 100
 */
-(instancetype)initWithPortal:(AGSPortal*)portal itemID:(NSString*)itemID;

/** Initialize a new portal item. The item doesn't exist yet on a portal, and will need to be added using `AGSPortalUser#addPortalItem:withContentParams:toFolder:completion:`
 @param portal where this item will eventually be added
 @return A new portal item
 @since 100
 */
+(instancetype)portalItemWithPortal:(AGSPortal*)portal;

/** Initialize a portal item with a portal and item ID to represent an existing item in the portal.
 @param portal The portal to which the item belongs to.
 @param itemID The ID of the existing item in the portal
 @since 100
 */
+(instancetype)portalItemWithPortal:(AGSPortal*)portal itemID:(NSString*)itemID;

/** Initialize a portal item with JSON content to represent an existing item in the portal.
 @param JSONObject representing the JSON content of the item
 @param portal The portal to which the item belongs to.
 @since 100
 */
+(nullable AGSPortalItem *)fromJSON:(id)JSONObject withPortal:(AGSPortal*)portal error:(NSError**)error;

/** Instantiate a portal item based on the given URL.
 The URL you pass can be one of three basic types. Examples of these types are:
 @li Item details page: http://www.arcgis.com/home/item.html?id=&lt;web_map_id&gt;
 @li Map viewer page: http://www.arcgis.com/home/webmap/viewer.html?webmap=&lt;web_map_id&gt;
 @li Item's rest endpoint: http://www.arcgis.com/sharing/rest/content/items/&lt;web_map_id&gt;
 @param URL of the portal item on ArcGIS Online or an on-premises portal
 @return The portal item created from the URL, or nil if an invalid URL is passed.
 @since 100
 */
-(nullable instancetype)initWithURL:(NSURL*)URL;

/** Instantiate a portal item based on the given URL.
 The URL you pass can be one of three basic types. Examples of these types are:
 @li Item details page: http://www.arcgis.com/home/item.html?id=&lt;web_map_id&gt;
 @li Map viewer page: http://www.arcgis.com/home/webmap/viewer.html?webmap=&lt;web_map_id&gt;
 @li Item's rest endpoint: http://www.arcgis.com/sharing/rest/content/items/&lt;web_map_id&gt;
 @param URL of the portal item on ArcGIS Online or an on-premises portal
 @return The portal item created from the URL, or nil if an invalid URL is passed.
 @since 100
 */
+(nullable instancetype)portalItemWithURL:(NSURL*)URL;

#pragma mark -
#pragma mark properties

/** The portal that the item belongs to.
 @since 100
 */
@property (nonatomic, strong, readonly) AGSPortal *portal;

/** The URL of the service inside the portal item.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) NSURL *serviceURL;

/** The ID of the folder this item belongs to.
 @since 100
 */
@property (nonatomic, copy, readonly) NSString *folderID;

/** The user who created the item. 
 @since 100
 */
@property (nonatomic, copy, readwrite) NSString *owner;

/** The type of the item. 
 @since 100
 */
@property (nonatomic, assign, readwrite) AGSPortalItemType type;

/** The type of the item represented as a string.
 @since 100
 */
@property (nonatomic, copy, readonly) NSString *typeName;

/** The file name of the item for file types.
 @since 100
 */
@property (nonatomic, copy, readonly) NSString *name;

/** Information about licenses or restrictions to view or edit the item. 
 @since 100
 @deprecated 100.4 Use `#termsOfUse` instead.
 */
@property (nonatomic, copy, readwrite) NSString *accessAndUseConstraintsHtml __deprecated_msg("Please use termsOfUse");

/** The item's language and country information.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) NSLocale *locale;

/** A set of keywords that further describes the type of item. Each item is tagged with a set of type keywords that are derived based on its primary type.
 @since 100
 */
@property (nonatomic, copy, readwrite) NSArray<NSString*> *typeKeywords;

/** The size of the item in bytes.
 @since 100
 */
@property (nonatomic, assign, readonly) long long size;

/** The number of comments on the item.
 @since 100
 */
@property (nonatomic, assign, readonly) NSInteger commentCount;

/** The number of ratings made by the users on the item.
 @since 100
 */
@property (nonatomic, assign, readonly) NSInteger ratingCount;

/** Average rating of the item.
 @since 100
 */
@property (nonatomic, assign, readonly) CGFloat averageRating;

/** Number of times a file item type is downloaded for the first time or a text item type is opened. For 
 a URL item type, the numViews property increases the first time a service is opened. 
 @since 100
 */
@property (nonatomic, assign, readonly) NSInteger viewCount;

/** Indicates who can access this item. Can be @c AGSPortalAccessPrivate, @c AGSPortalAccessShared, @c AGSPortalAccessOrganization, or @c AGSPortalAccessPublic.
 
 If @c AGSPortalAccessPrivate, only the item owner
 can access. @c AGSPortalAccessShared allows access to members of a group that the item is shared with . @c AGSPortalAccessOrganization restricts item access to members of an organization. If @c AGSPortalAccessPublic, all users can access the item.
 @since 100
 */
@property (nonatomic, assign, readonly) AGSPortalAccess access;

/** Array of comments (@c AGSPortalItemComment) of the item. These need to be fetched explicitly using `#fetchCommentsWithCompletion:`.
 @since 100
 */
@property (nullable, nonatomic, copy, readonly) NSArray<AGSPortalItemComment*> *comments;

/** Indicates whether or not comments are enabled for the item.
 @since 100
 */
@property (nonatomic, assign, readonly) BOOL commentsEnabled;

/** The GUID of this portal item.
 @since 100
 */
@property (nonatomic, copy, readonly) NSString *GUID;

/** The user rating of the item. 
 
 If it is nil, there is no rating. Otherwise, the rating is number that needs to be loaded asynchronously by calling `AGSLoadableValue#loadWithCompletion:`.
 
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSLoadableValue *userRating;

/** Groups (`AGSPortalGroup` objects) that this item belongs to which the current portal user is an administrator.
 Will be nil if they haven't been fetched yet. Use `#fetchGroupsWithCompletion:` to fetch the groups.
 @since 100
 */
@property (nullable, nonatomic, copy, readonly) NSArray<AGSPortalGroup*> *adminGroups;

/** Groups (`AGSPortalGroup` objects) that this item belongs to which the current portal user is a member.
 Will be nil if they haven't been fetched yet. Use `#fetchGroupsWithCompletion:` to fetch the groups.
 @since 100
 */
@property (nullable, nonatomic, copy, readonly) NSArray<AGSPortalGroup*> *memberGroups;

/** Groups (`AGSPortalGroup` objects) that this item belongs to that are public or shared
 to the user's organization, but that the current portal user is not a member of.
 Will be nil if they haven't been fetched yet. Use `#fetchGroupsWithCompletion:` to fetch the groups.
 @since 100
 */
@property (nullable, nonatomic, copy, readonly) NSArray<AGSPortalGroup*> *otherGroups;

#pragma mark -
#pragma mark methods

/** Kicks off an operation to fetch user comments (`AGSPortalItemComment` objects) for the item. The completion block is invoked when the operation completes successfully or if an error is encountered. Once completed the `#comments` property will be populated.
 @param completion block that is invoked when operation finishes
 @return operation which can be canceled
 @since 100
 */
-(id<AGSCancelable>)fetchCommentsWithCompletion:(nullable void(^)(NSArray<AGSPortalItemComment*> * __nullable comments, NSError * __nullable error))completion;

/** Kicks off an operation to fetch the groups (`AGSPortalGroup` objects) that this item belongs to.  The completion block is invoked when the operation completes successfully or if an error is encountered. Only those groups that are visible to the current portal user will be returned. Once completed the `#adminGroups`, `#memberGroups` and, `#otherGroups` properties will be populated.
 @param completion block that is invoked when operation finishes with details about `adminGroups`, `memberGroups`, `otherGroups` that this item belongs to. 
 @return operation which can be canceled
 @since 100
 */
-(id<AGSCancelable>)fetchGroupsWithCompletion:(nullable void(^)(NSArray<AGSPortalGroup*> * __nullable adminGroups, NSArray<AGSPortalGroup*> * __nullable memberGroups, NSArray<AGSPortalGroup*> * __nullable otherGroups, NSError * __nullable error))completion;

/** Kicks off an operation to add a rating to an item that the current portal user has access to. The completion block is invoked when the operation completes successfully or if an error is encountered.  Upon success, the `#avgRating` and `#numRatings` will be updated on the portal item.
 
 If the current user's rating has not been fetched, this method will fetch it before adding the rating.
 Only 1 rating can be given to an item per user. If this call is made on an already rated item, the new rating will overwrite the current one. A user cannot rate their own item. Available only to authenticated users.

 @param rating The rating to add to the portal item. The value must be between 1.0 and 5.0.
 @param completion block that is invoked when operation finishes
 @return operation which can be canceled
 @since 100
 */
-(id<AGSCancelable>)addRating:(CGFloat)rating completion:(nullable void(^)(NSError * __nullable error))completion;

/** Kicks off an operation to add a comment to an item. Available only to authenticated users who have access to the item. The completion block is invoked when the operation completes successfully or if an error is encountered.
 @param comment The comment to add to the portal item.
 @param completion block that is invoked when operation finishes
 @return operation which can be canceled
 @since 100
 */
-(id<AGSCancelable>)addComment:(NSString*)comment completion:(nullable void(^)(AGSPortalItemComment * __nullable resultComment, NSError * __nullable error))completion;

/** Kicks off an operation to update the JSON data for the item on the portal. The completion block is invoked when the operation completes successfully or if an error is encountered. This method is applicable for portal items that use JSON representation, such as web map, feature collection, etc.
 @param json The JSON data with which to update the portal item.
 @param completion block that is invoked when operation finishes
 @return operation which can be canceled
 @license{Basic}
 @ingroup licensing
 @since 100
 */
-(id<AGSCancelable>)updateDataWithJSON:(id)json completion:(nullable void(^)(NSError * __nullable error))completion;

/** Kicks off an operation to update the file for the item on the portal. The completion block is invoked when the operation completes successfully or if an error is encountered. This method is applicable for portal items that represent a static file, such as a shapefile, CSV, etc.
 @param data The binary data with which to update the portal item.
 @param completion block that is invoked when operation finishes
 @return operation which can be canceled
 @license{Basic}
 @ingroup licensing
 @since 100
 */
-(id<AGSCancelable>)updateData:(NSData*)data completion:(nullable void(^)(NSError * __nullable error))completion;

/** Kicks off an operation which will share the item based on the given parameters.  This method is used to share an item
 with everyone or just with the user's organization.  If both 'everyone' and 'org' arguments are YES, the item will be shared with everyone (AGSPortalAccessPublic).
 If both 'everyone' and 'org' arguments are NO, the item will be made private, unless the item has been shared with one or more groups. In that
 case, the items 'access' will be set to AGSPortalAccessShared.
 The groups an item has been shared with are not affected by this method.
 The completion block is invoked when the operation completes successfully or if an error is encountered.
 @param everyone denotes the items should be shared with everyone (made public).
 @param org denotes the items should be shared with the organization.
 @param completion block that is invoked when operation finishes.
 @return operation which can be canceled
 @license{Basic}
 @ingroup licensing
 @since 100
 */
-(id<AGSCancelable>)shareWithEveryone:(BOOL)everyone org:(BOOL)org completion:(nullable void(^)(NSError * __nullable error))completion;

/** Kicks off an operation which will share the item with the given groups.
 The completion block is invoked when the operation completes successfully or if an error is encountered.
 @param groups the array of either groups (AGSPortalGroup objects) or group Id strings the item should be shared with.
 @param completion block that is invoked when operation finishes.  The excludedGroups argument is an array of group Ids representing the groups the item could not be shared with.
 @return operation which can be canceled
 @license{Basic}
 @ingroup licensing
 @since 100
 */
-(id<AGSCancelable>)shareWithGroups:(NSArray<AGSPortalGroup*> *)groups completion:(nullable void(^)(NSArray<AGSPortalGroup*> * __nullable excludedGroups, NSError * __nullable error))completion;

/** Kicks off an operation which will unshare (make private) the item.
 The completion block is invoked when the operation completes successfully or if an error is encountered.
 @param completion block that is invoked when operation finishes
 @return operation which can be canceled
 @license{Basic}
 @ingroup licensing
 @since 100
 */
-(id<AGSCancelable>)unshareWithCompletion:(nullable void(^)(NSError * __nullable error))completion;

/** Kicks off an operation which will unshare the item with the given groups.
 The completion block is invoked when the operation completes successfully or if an error is encountered.
 @param groups the array of either groups (AGSPortalGroup objects) or group Id strings the item should be unshared with.
 @param completion block that is invoked when operation finishes.  The excludedGroups argument is an array of group Ids representing the groups the item could not be unshared with.
 @return operation which can be canceled
 @license{Basic}
 @ingroup licensing
 @since 100
 */
-(id<AGSCancelable>)unshareWithGroups:(NSArray<AGSPortalGroup*> *)groups completion:(nullable void(^)(NSArray<AGSPortalGroup*> * __nullable excludedGroups, NSError * __nullable error))completion;

/**
 Returns JSON representation for this object.
 @return `NSDictionary` or `NSArray` containing the JSON.
 @since 100
 */
-(__nullable id)toJSON:(NSError**)error;

NS_ASSUME_NONNULL_END
@end
