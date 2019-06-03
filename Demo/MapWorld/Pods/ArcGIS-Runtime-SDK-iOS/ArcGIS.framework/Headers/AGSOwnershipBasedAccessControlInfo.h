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

/** @file AGSOwnershipBasedAccessControlInfo.h */ //Required for Globals API doc

/** @brief Ownership-based access control information for the features of a feature service layer.
 
Information about the ownership-based access control for the features of a feature service layer.
 
 @since 100
 */
@interface AGSOwnershipBasedAccessControlInfo : AGSObject

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** Indicates whether a feature can be deleted by anonymous users.
 @since 100
 */
@property (nonatomic, assign, readonly) BOOL allowAnonymousToDelete;

/** Indicates whether a feature can be updated by anonymous users.
 @since 100
 */
@property (nonatomic, assign, readonly) BOOL allowAnonymousToUpdate;

/** Indicates whether a feature can be deleted by others (i.e. non creator).
 @since 100
 */
@property (nonatomic, assign, readonly) BOOL allowOthersToDelete;

/** Indicates whether a feature can be queried by others (i.e. non creator).
 @since 100
 */
@property (nonatomic, assign, readonly) BOOL allowOthersToQuery;

/** Indicates whether a feature can be updated by others (i.e. non creator).
 @since 100
 */
@property (nonatomic, assign, readonly) BOOL allowOthersToUpdate;

NS_ASSUME_NONNULL_END

@end
