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

/** @file AGSFeatureServiceCapabilities.h */ //Required for Globals API doc

/** @brief Capabilities supported by a feature service
 
 Instances of this class represent capabilities supported by a feature service.
 
 @since 100
 */
@interface AGSFeatureServiceCapabilities : AGSObject

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** Indicates whether the service allows new features to be created.
 @since 100
 */
@property (nonatomic, assign, readonly) BOOL supportsCreate;

/** Indicates whether the service allows features to be deleted.
 @since 100
 */
@property (nonatomic, assign, readonly) BOOL supportsDelete;

/** Indicates whether the service allows features to be edited.
 @since 100
 */
@property (nonatomic, assign, readonly) BOOL supportsEditing;

/** Indicates whether the service allows a features to be queried.
 @since 100
 */
@property (nonatomic, assign, readonly) BOOL supportsQuery;

/** Indicates whether the service allows a features to be synced.
 @since 100
 */
@property (nonatomic, assign, readonly) BOOL supportsSync;

/** Indicates whether the service allows a features to be updated.
 @since 100
 */
@property (nonatomic, assign, readonly) BOOL supportsUpdate;

NS_ASSUME_NONNULL_END

@end
