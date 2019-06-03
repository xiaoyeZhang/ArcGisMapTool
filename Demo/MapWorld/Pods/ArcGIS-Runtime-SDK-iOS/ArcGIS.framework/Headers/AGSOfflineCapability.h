/*
 COPYRIGHT 2017 ESRI
 
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

/** @file AGSOfflineCapability.h */ //Required for Globals API doc

/** @brief Offline capabilities of a map's layer or table
 
 Instances of this class represent offline capabilities of a map's layer or table.
 
 @since 100.1
 */
@interface AGSOfflineCapability : AGSObject

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** Error, if any, that was encountered while determining the layer or table's offline capabilities.
 @since 100.1
 */
@property (nullable, nonatomic, strong, readonly) NSError *error;

/** Indicates whether the layer or table can be taken offline.
 @since 100.1
 */
@property (nonatomic, assign, readonly) BOOL supportsOffline;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end

