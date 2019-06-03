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
@class AGSEnvelope;
@class AGSLoadableImage;
@class AGSBasemap;
@class AGSPortalHelperServices;
@class AGSLicenseInfo;

@protocol AGSPortalInfoDelegate;

/** @file AGSPortalInfo.h */ //Required for Globals API doc

/** @brief Information about a Portal or Organization
 
 If the accessing user is a member of
 an organization, the details pertain to that organization. If the accessing user is not a member of an organization then then the details 
 pertain to the Portal instead. Information includes the name and logo for the portal/ 
 organization, query information for the featured groups and content, and other 
 customizable aspects of the Portal for an organization.
 
 @since 100
 */
@interface AGSPortalInfo : NSObject <AGSJSONSerializable>
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

/** Initialize a portal info with JSON content to represent the info for the portal.
 @param JSONObject representing the JSON content of the info
 @param portal The portal to which the info belongs to.
 @since 100
 */
+(nullable AGSPortalInfo *)fromJSON:(id)JSONObject withPortal:(AGSPortal*)portal error:(NSError**)error;

#pragma mark -
#pragma mark properties

/** The portal that is being referred to.
 Needs to be optional because it's a weak reference.
 @since 100
 */
@property (nullable, nonatomic, weak, readonly) AGSPortal *portal;

/** The id of the organization. 
 @since 100
 */
@property (nullable, nonatomic, copy, readonly) NSString *organizationID;

/** The name of the organization.
 @since 100
 */
@property (nullable, nonatomic, copy, readonly) NSString *organizationName;

/** The description of the organization.
 @since 100
 */
@property (nullable, nonatomic, copy, readonly) NSString *organizationDescription;

/** The name of the portal.
 @since 100
 */
@property (nullable, nonatomic, copy, readonly) NSString *portalName;

/** The pre-defined query string for finding featured items group. 
 @since 100
 */
@property (nullable, nonatomic, copy, readonly) NSString *featuredItemsGroupQuery;

/** Indicates whether the members of the organization can share content outside of the organization.
 @since 100
 */
@property (nonatomic, assign, readonly) BOOL canSharePublic;

/** Indicates whether the members of the organization can share Bing content outside of the organization.
 @since 100
 */
@property (nonatomic, assign, readonly) BOOL canShareBingPublic;

/** Indicates whether the members of the organization can search content outside of the organization.
 @since 100
 */
@property (nonatomic, assign, readonly) BOOL canSearchPublic;

/** The pre-defined query string for finding the collection of basemaps.
 @since 100
 */
@property (nullable, nonatomic, copy, readonly) NSString *basemapGalleryGroupQuery;

/** The default extent for the basemaps.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSEnvelope *defaultExtent;

/** The default basemap of the portal/organization.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSBasemap *defaultBasemap;

/** The pre-defined query string for finding homepage featured items group.
 @since 100
 */
@property (nullable, nonatomic, copy, readonly) NSString *homePageFeaturedContentGroupQuery;

/** Array of pre-defined query strings for finding featured groups.
 @since 100
 */
@property (nullable, nonatomic, copy, readonly) NSArray<NSString*> *featuredGroupsQueries;

/** The organization's thumbnail image.
 
 If it is nil, there is no thumbnail. Otherwise, the image needs to be loaded asynchronously by calling `AGSLoadableImage#loadWithCompletion:`
 
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSLoadableImage *thumbnail;

/** The banner image of the organization. 
 
 If it is nil, there is no banner. Otherwise, the image needs to be loaded asynchronously by calling `AGSLoadableImage#loadWithCompletion:`
 
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSLoadableImage *organizationBanner;

/** Determines who can view the organization's content. Can be either  @c AGSPortalAccessPublic or @c AGSPortalAccessPrivate. 
 
 @c AGSPortalAccessPublic implies even anonymous users can access the content. @c AGSPortalAccessPrivate restricts access to only members of the organization. 
 
 @since 100
 */
@property (nonatomic, assign, readonly) AGSPortalAccess access;

/** Indicates whether the portal is single or multi tenant.
 A multi tenant portal supports organization subscriptions, but a
 single tenant does not.
 @since 100
 */
@property (nonatomic, assign, readonly) AGSPortalMode portalMode;

/** The portion of the URL's host component that identifies the portal
 For example, http://&lt;organizationSubdomain&gt;.&lt;customBaseDomain&gt;/
 @since 100
 @see #organizationSubdomain
 */
@property (nullable, nonatomic, copy, readonly) NSString *customBaseDomain;

/** The portion of the URL's host component that identifies a specific organization subscription within a portal.
 For example, http://&lt;organizationSubdomain&gt;.&lt;customBaseDomain&gt;/
 @since 100
 @see #customBaseDomain
 */
@property (nullable, nonatomic, copy, readonly) NSString *organizationSubdomain;

/** Various services provided by the organization. 
 @since 100
 */
@property (nonatomic, strong, readonly) AGSPortalHelperServices *helperServices;

/** Indicates whether or not this portal supports OAuth authentication.
 @since 100
 */
@property (nonatomic, assign, readonly) BOOL supportsOAuth;

/** The Bing App ID associated with the portal.
 @since 100
 */
@property (nullable, nonatomic, copy, readonly) NSString *bingKey;

/** Indicates whether or not comments are enabled for the portal.
 @since 100
 */
@property (nonatomic, assign, readonly) BOOL commentsEnabled;

/** License information for the named-user currently logged into the portal.
 Only applicable if the portal connection wasn't established anonymously. 
 @see `AGSPortal#user` for details about the user logged into the portal.
 @see `AGSArcGISRuntimeEnvironment#setLicenseInfo:error:` to license the application for deployment using a named-user
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSLicenseInfo *licenseInfo;

/** Indicates if the organization is using HTTPS. If true, all calls made against resources that belong to the organization will require HTTPS. The default is false.
 @since 100
 */
@property (nonatomic, assign, readonly) BOOL allSSL;

/** The date the organization was created.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) NSDate *created;

/** The item's language and country information.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) NSLocale *locale;

/** The number of featured items that can be displayed on the home page. The max is 100.
 @since 100
 */
@property (nonatomic, assign, readonly) NSInteger homePageFeaturedContentCount;

/** The country code of the calling IP.
 @since 100
 */
@property (nullable, nonatomic, copy, readonly) NSString *IPCountryCode;

/** Indicates if the portal is on-premises.
 @since 100
 */
@property (nonatomic, assign, readonly) BOOL isPortal;

/** The date the organization was last modified.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) NSDate *modified;

/** Indicates if the description of your organization displays on the home page.
 @since 100
 */
@property (nonatomic, assign, readonly) BOOL showHomePageDescription;

/** The thumbnail image of the portal.
 
 If it is nil, there is no thumbnail. Otherwise, the image needs to be loaded asynchronously by calling `AGSLoadableImage#loadWithCompletion:`
 
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSLoadableImage *portalThumbnail;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END
@end
