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

/** @file AGSPortalPrivilege.h */ //Required for Globals API doc

/** @brief Privileges of a portal user
 
 Instances of this class represent a previlege possessed by a portal user. This privlege permits the user to peform specific operations on the portal.
 
 @since 100
 */
@interface AGSPortalPrivilege : NSObject
NS_ASSUME_NONNULL_BEGIN

/** The realm the privilege belongs to. Helps to organize privileges into categories for aspects relating to a portal.
 @since 100
 */
@property (nonatomic, assign, readonly) AGSPortalPrivilegeRealm realm;

/** The role the privilege applies to. 
 @since 100
 */
@property (nonatomic, assign, readonly) AGSPortalPrivilegeRole role;

/** The operation permitted by the privilege.
 @since 100
 */
@property (nonatomic, assign, readonly) AGSPortalPrivilegeType type;

/** The type represented as a string.
 @since 100
 */
@property (nonatomic, copy, readonly) NSString *typeName;

NS_ASSUME_NONNULL_END
@end
