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
#import "AGSRemoteResource.h"

@class AGSPortalFolder;
@class AGSPortalItem;
@class AGSPortalItemContentParameters;
@class AGSPortalQueryParameters;
@class AGSPortalUser;
@class AGSPortalGroup;
@class AGSPortalInfo;
@class AGSPortalQueryResultSet;
@class AGSAuthenticationChallenge;
@class AGSMap;
@class AGSBasemap;

/** @file AGSPortal.h */ //Required for Globals API doc

/** @brief An Object representing a Portal for ArcGIS
 
 AGSPortal is an object that represents a view for a user (anonymous or not) into a 
 portal. www.ArcGIS.com is an example of a portal. A portal may support subscriptions which provides organizations a  sandboxed area on the portal. 
 
 AGSPortal is the main class and the entry point into the API to work with portals and organization subscriptions. It implements all the operations to 
 interface with the backend ArcGIS Portal REST API. 
 
 
 
 @b Concepts:
 
 - Portals  allow users and  organizations to publish and share content over the web. 
 
 - A Portal has  Users (@c AGSPortalUser), Groups (@c AGSPortalGroup) and Content (@c AGSPortalItem).
 
 - A Portal may have users who are unaffiliated with an organization or users who are part of an 
 organization.
 
 - Users sign in to the portal and  create and share content which is organized into Items. The system 
 supports different types of items including web maps, map services (that can be used as layers in web 
 maps), applications (that are built around web maps) and data files (that can be uploaded and 
 downloaded).
 
 - Users can choose to keep content Private or to share it with other users via Groups or make content 
 Public and accessible to everyone.
 
 - Users can create and join Groups. Users can share items with Groups. This makes the items visible to 
 and accessible by the other members of the Group.
 
 - A Portal may contain multiple Organizations.
 
 - A user of the Portal (and of the REST API) sees the view off the Portal that applies to their 
 organization subscription.  This view includes users, groups and items that belong to the organization and have been 
 shared with them. This view may also include users, groups and items that are external to the 
 organization and have been shared with the user.
 
 - An organization has users in different roles including administrators, publishers and  information 
 workers.
 
 - Administrators can add  users to  their organization subscriptions and have access to all content within the 
 organization.
 
 - All users can create web maps based  on mashing up services that they have access to and can register 
 services running on external servers.
 
 - Publishers within an organization can in addition create hosted services based on data files that they 
 upload.
 
 @see @concept{connecting-to-a-portal.htm, Working with Portals}
 @see @sample{588b9892d4284999b2a345456d555f65, Portal Sample}
 
 @since 100
 */
@interface AGSPortal : AGSLoadableBase <AGSRemoteResource>

#pragma mark -
#pragma mark initializers
NS_ASSUME_NONNULL_BEGIN

-(instancetype)init __attribute__((unavailable("init is not available.")));

/** Instantiates the AGSPortal with a URL.
 You should load the portal by calling #loadWithCompletion: before using it.
 
 Some portals, for instance ArcGIS Online, permit anonymous access. If you want to connect to the portal anonymously, you should set `loginRequired` to false. But if you want to connect to the portal using an identity, you should set `loginRequired` to true. This will ensure that API propogates the `#credential` to the portal. If a credential is not available, an  authentication challenge will be issued to first request a credential.
 
 If the portal does not permit anonymous access, the value of `loginRequired` parameter is ignored. The API will attempt to propogate the `#credential` to the portal. If a credential is not available, an  authentication challenge will be issued to first request a credential.
 
 @param url The url for the portal. Eg, www.arcgis.com
 @param loginRequired Whether or not you intend to access the portal anonymously or if you want to use a credential.
 If set to YES, authentication challenge will be issued. If set to NO, the portal will be accessed anonymously. If the portal does not permit anonymous access, an authentication challenge will be issued.
 After you instantiate the portal, if you set a credential then the credential you set will be used regardless of the loginRequired parameter.
 @since 100
 */
-(instancetype)initWithURL:(NSURL *)url loginRequired:(BOOL)loginRequired;

/** Instantiates the AGSPortal with a URL.
 You should load the portal by calling #loadWithCompletion: before using it.
 
 Some portals, for instance ArcGIS Online, permit anonymous access. If you want to connect to the portal anonymously, you should set `loginRequired` to false. But if you want to connect to the portal using an identity, you should set `loginRequired` to true. This will ensure that API propogates the `#credential` to the portal. If a credential is not available, an  authentication challenge will be issued to first request a credential.
 
 If the portal does not permit anonymous access, the value of `loginRequired` parameter is ignored. The API will attempt to propogate the `#credential` to the portal. If a credential is not available, an  authentication challenge will be issued to first request a credential.
 
 @param URL The url for the portal. Eg, www.arcgis.com
 @param loginRequired Whether or not you intend to access the portal anonymously or if you want to use a credential.
 If set to YES, authentication challenge will be issued. If set to NO, the portal will be accessed anonymously. If the portal does not permit anonymous access, an authentication challenge will be issued.
 After you instantiate the portal, if you set a credential then the credential you set will be used regardless of the loginRequired parameter.
 @since 100
 */
+(instancetype)portalWithURL:(NSURL*)URL loginRequired:(BOOL)loginRequired;

/** Instantiates a new AGSPortal pointing to www.arcgis.com.
 You should load the portal by calling #loadWithCompletion: before using it.
 This is not a singleton and retuns a new portal whenever it's called.
 
 ArcGIS Online, permits anonymous access. If you want to connect to the portal anonymously, you should set `loginRequired` to false. But if you want to connect to the portal using an identity, you should set `loginRequired` to true. This will ensure that API propogates the `#credential` to the portal. If a credential is not available, an  authentication challenge will be issued to first request a credential.
 
 @param loginRequired Whether or not you intend to access the portal anonymously or if you want to use a credential.
 If set to YES, authentication challenge will be issued. If set to NO, the portal will be accessed anonymously. If the portal does not permit anonymous access, an authentication challenge will be issued.
 After you instantiate the portal, if you set a credential then the credential you set will be used regardless of the loginRequired parameter.
 @since 100
 */
+(instancetype)ArcGISOnlineWithLoginRequired:(BOOL)loginRequired;

#pragma mark -
#pragma mark properties

/** Returned upon successful initialization of the portal. Contains details of the portal/organization as seen by the current user, anonymous or logged in.
 This property will be nil until the portal is loaded.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSPortalInfo *portalInfo;

/** Represents the registered user of the portal/organization and is returned upon successful initialization of the portal with a credential. 
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSPortalUser *user;

/** The featured groups for this portal.
 This property will be nil until the groups are successfully fetched with #fetchFeaturedGroupsWithCompletion:
 @since 100
 */
@property (nullable, nonatomic, copy, readonly) NSArray<AGSPortalGroup*> *featuredGroups;

/** Determines whether to access the portal anonymously or use a credential.
 @see #initWithURL:loginRequired:
 @see #portalWithURL:loginRequired:
 @see #ArcGISOnlineWithLoginRequired:
 @since 100
 */
@property (nonatomic, assign, readonly, getter=isLoginRequired) BOOL loginRequired;

#pragma mark -
#pragma mark methods

/**
 Kicks off an operation to find items based on the specified query. The completion block is invoked when the operation completes successfully or if an error is encountered. The items provided by this method are not suitable to update, delete or move because some properties, required for these operations, are not populated. Use the `fetchContent` or `fetchContentInFolder` methods on the `AGSPortalUser` to get items that are fully populated.
 @param queryParameters The query parameters to find portal items.
 @param completion block that is invoked when operation finishes
 @return operation which can be canceled
 @since 100
 */
-(id<AGSCancelable>)findItemsWithQueryParameters:(AGSPortalQueryParameters*)queryParameters
                                      completion:(void(^)(AGSPortalQueryResultSet * __nullable resultSet, NSError * __nullable error))completion;

/**
 Kicks off an operation to find groups based on the specified query. The completion block is invoked when the operation completes successfully or if an error is encountered.
 @param queryParameters The query parameters to find portal groups.
 @param completion block that is invoked when operation finishes
 @return operation which can be canceled
 @since 100
 */
-(id<AGSCancelable>)findGroupsWithQueryParameters:(AGSPortalQueryParameters*)queryParameters
                                       completion:(void(^)(AGSPortalQueryResultSet * __nullable resultSet, NSError * __nullable error))completion;


/**
 Kicks off an operation to fetch basemaps (`AGSBasemap` objects) that are available for the portal. The completion block is invoked when the operation completes successfully or if an error is encountered.
 If the @c AGSPortalInfo #basemapGalleryGroupQuery property is empty, the completion block will return a nil array and no error.
 @param completion block that is invoked when operation finishes.
 @return operation which can be canceled
 @since 100
 */
-(id<AGSCancelable>)fetchBasemapsWithCompletion:(nullable void(^)(NSArray<AGSBasemap*> * __nullable basemaps, NSError * __nullable error))completion;

/**
 Kicks off an operation to fetch the featured groups (`AGSPortalGroup` objects) that are available for the portal. The completion block is invoked when the operation completes successfully or if an error is encountered.
 If the @c AGSPortalInfo #featuredGroupsQueries property is empty, the completion block will return a nil array and no error.
 @param completion block that is invoked when operation finishes.
 @return operation which can be canceled
 @since 100
 */
-(id<AGSCancelable>)fetchFeaturedGroupsWithCompletion:(nullable void(^)(NSArray<AGSPortalGroup*> * __nullable featuredGroups, NSError * __nullable error))completion;

/**
 Kicks off an operation to fetch the featured items (`AGSPortalItem` objects) that are available for the portal. The completion block is invoked when the operation completes successfully or if an error is encountered.
 If the @c AGSPortalInfo #featuredItemsGroupQuery property is empty, the completion block will return a nil array and no error.
 @param completion block that is invoked when operation finishes.
 @return operation which can be canceled
 @since 100
 */
-(id<AGSCancelable>)fetchFeaturedItemsWithCompletion:(nullable void(^)(NSArray<AGSPortalItem*> * __nullable featuredItems, NSError * __nullable error))completion;

/**
 Kicks off an operation to fetch the homepage featured content (`AGSPortalItem` objects) that are available for the portal. The completion block is invoked when the operation completes successfully or if an error is encountered.
 If the @c AGSPortalInfo #homePageFeaturedContentGroupQuery property is empty, the completion block will return a nil array and no error.
 @param completion block that is invoked when operation finishes.
 @return operation which can be canceled
 @since 100
 */
-(id<AGSCancelable>)fetchHomePageFeaturedContentWithCompletion:(nullable void(^)(NSArray<AGSPortalItem*> * __nullable featuredItems, NSError * __nullable error))completion;

/**
 If there is a credential for this portal then it will be set to nil and remove it from credential cache. If credential is of type OAuth then token will be invalidated.
 @since 100.2
 */
-(void)logout;

/** Checks login type for the given portal url. It'll return error if url require authentication or is invalid. If url require authentication then the loginType will be either AGSPortalLoginTypeUsernamePassword or AGSPortalLoginTypeClientCertificate. If the url is invalid then loginType will be AGSPortalLoginTypeUnknown.
 @param url The url for the portal. Eg, www.arcgis.com
 @param completion block that is invoked when operation finishes
 @return The object you can use to cancel the operation.
 @since 100
 */
+(id<AGSCancelable>)loginTypeForURL:(NSURL*)url completion:(void(^)(AGSPortalLoginType loginType, NSError * __nullable error))completion;

NS_ASSUME_NONNULL_END
@end
