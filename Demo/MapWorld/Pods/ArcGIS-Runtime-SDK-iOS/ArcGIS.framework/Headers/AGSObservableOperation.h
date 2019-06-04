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

#import "AGSCancelable.h"
#import "AGSOperation.h"

/** @file AGSObservableOperation.h */ //Required for Globals API doc

/** @brief Base class for operations. This adds the ability to register a listener to the AGSOperationBase. It also adds the concept of an error and a result.
 @since 100
 */
@interface AGSObservableOperation : AGSOperationBase 
NS_ASSUME_NONNULL_BEGIN

/** The results of an operation.
 It will be of type @c NSDictionary when the result is json, @c AGSImage when the result is an image, and @c NSData when anything else.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly ) id result;

/** The error, if any, that occurred.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) NSError *error;

/** Adds a completion handler to the operation for the specified listener.
 If you are using this option, you can unregister a completionHandler for a listener if you need to.
 When there are no more listeners the operation will be canceled automatically.
 @param listener The listener to add the completion block for.
 @param completion The completion handler to be called.
 @since 100
 */
-(void)registerListener:(id)listener forCompletion:(void(^)(id __nullable result, NSError * __nullable error))completion;

/** Removes the registered completion handler to the operation for the specified listener.
 When there are no more listeners the operation will be canceled automatically.
 To avoid any potential retain cycles the listener is not retained by the operation.
 Unregistering is just the way to tell the operation that you no longer care about getting the completion event.
 @param listener The listener to unregister
 @since 100
 */
-(void)unregisterListener:(id)listener;

/** Returns whether or not the specified object is a registered as a listener to this operation.
 @since 100
 */
-(BOOL)isRegisteredListener:(id)listener;

NS_ASSUME_NONNULL_END
@end

