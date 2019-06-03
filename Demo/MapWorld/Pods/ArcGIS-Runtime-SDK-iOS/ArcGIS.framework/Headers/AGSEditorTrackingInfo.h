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

/** @file AGSEditorTrackingInfo.h */ //Required for Globals API doc

/** @brief information about a feature service's editor tracking configuration and ownership based access control
 
 @since 100
 */
@interface AGSEditorTrackingInfo : AGSObject

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** Indicates whether anonymous users can delete features
 @since 100.3
 */
@property (nonatomic, assign, readonly) BOOL allowAnonymousToDelete;

/** Indicates whether anonymous users can delete features
 @since 100.3
 */
@property (nonatomic, assign, readonly) BOOL allowAnonymousToUpdate;

/** Indicates whether non-owners can delete features
 @since 100
 */
@property (nonatomic, assign, readonly) BOOL allowOthersToDelete;

/** Indicates whether non-owners can update features
 @since 100
 */
@property (nonatomic, assign, readonly) BOOL allowOthersToUpdate;

/** Indicates whether the feature service has editor tracking enabled
 @since 100
 */
@property (nonatomic, assign, readonly) BOOL editorTrackingEnabled;

/** Indicates whether the feature service has owner access control enabled. If enabled, only users who "own" a feature (i.e created the feature originally) are allowed to update or delete them unless explicitly allowed by `#allowOthersToUpdate`, `#allowOthersToDelete`, `#allowAnonymousToUpdate`, `#allowAnonymousToDelete` settings.
 When disabled, any user can edit any feature (even if it belongs to another user) as long as the service allows edits in general.
 @see `AGSFeatureTable#canDeleteFeature:` and `AGSFeatureTable#canUpdateFeature:` for information about whether a user can edit a feature based on the specified ownership based access control
 @since 100
 */
@property (nonatomic, assign, readonly) BOOL ownershipBasedAccessControlEnabled;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end
