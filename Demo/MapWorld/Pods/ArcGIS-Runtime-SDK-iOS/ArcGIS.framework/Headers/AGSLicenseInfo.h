/*
 COPYRIGHT 2016 ESRI
 
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

/** @file AGSLicenseInfo.h */ //Required for Globals API doc

/** @brief A class that contains information pertaining to a licensed named user
 
 Instances of this class contain encrypted information pertaining to a licensed named user. It is available on `AGSPortalInfo#licenseInfo` after a user successfully signs in to a portal (`AGSPortal`).
 
 You can persist this object to disk by serializing it to JSON. This is useful when you want to license the app in situations where there isn't any network connectivity. For example, say the user signed in to the portal when the app initially had a network connection, but then later restarted the app when there was no network connectivity. To support licensing the app in an offline environment, you can serialize the license info to JSON on disk when the user first logs into the portal. You can then deserialize the license info from disk when the app is restarted in an offline environment and use it to license the app. This manner of licensing the app in an offline environment is supported for up to 30 days since the license info was made available by logging into the portal.
 
 @since 100
 */
@interface AGSLicenseInfo : AGSObject <AGSJSONSerializable>

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

- (instancetype)init __attribute__((unavailable("init is not available.")));


#pragma mark -
#pragma mark properties

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end
