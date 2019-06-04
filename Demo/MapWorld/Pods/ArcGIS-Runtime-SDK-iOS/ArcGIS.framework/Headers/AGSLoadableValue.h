/*
 COPYRIGHT 2014 ESRI
 
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

/** @brief A value that is loaded asynchronously
 
 Represents a value that is loaded asynchronously. To initiate loading it, you need to call `AGSLoadable#loadWithCompletion:`

 @since 100
 */
@interface AGSLoadableValue : AGSLoadableBase

NS_ASSUME_NONNULL_BEGIN

/** The value that this object represents. It is available only if `AGSLoadable#loadStatus` is `AGSLoadStatusLoaded`. To initiate loading the value, you need to call `AGSLoadable#loadWithCompletion:`
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) id value;

NS_ASSUME_NONNULL_END

@end
