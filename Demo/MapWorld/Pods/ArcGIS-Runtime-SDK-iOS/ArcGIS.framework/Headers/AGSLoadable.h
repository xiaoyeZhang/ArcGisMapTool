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
/** @file AGSLoadable.h */ //Required for Globals API doc

#import "AGSObject.h"

NS_ASSUME_NONNULL_BEGIN

/**
 @brief A protocol adopted by classes that can load data asynchronously.
 
 A protocol adopted by classes whose objects can load data asynchronously, for example, from a remote network location or the local file system.
 You need to call `#loadWithCompletion:` to initiate loading.
 The `#loadStatus` property reflects the status of the load operation.
 
 @since 100
 @see `AGSLoadObjects()` which provides convenience for batch loading a group of loadable objects
 */
@protocol AGSLoadable <NSObject>

@required

/**
 Loads data for the object asynchronously. The completion block is invoked upon completion.
 
 You can call this method any number of times, however only one attempt is made to load the data. If it is already loading, it will just continue to load (i.e. not force a reload).
 If it has already loaded successfully, the completion block will be invoked right away.
 If it has already failed to load, the completion block will be invoked right away with error previously encountered.
 This method supports multiple callers and will call them all back on completion. However, each caller's completion block will be invoked once and only once.
 
 @param completion block that is invoked when object loads successfully or fails to load. An error is passed to the block if the object fails to load.
 @since 100
 @see `#cancelLoad` to cancel loading
 @see `#retryLoadWithCompletion:` to force reload
 */
-(void)loadWithCompletion:(nullable void(^)(NSError * __nullable error))completion;

/**
 Tries to reload when an object has failed to load.
 This method should be called judiciously. It should be called when:
 1. you didn't have network connectivity earlier when it failed and you want to retry now that you have connectivity
 2. the server was down earlier when it failed and you want to retry
 3. the request is taking too long and you want to cancel it and retry, in which case you will first call `#cancelLoad` and then this method
 
 If the data hasn't started loading, it will start loading.
 If it is already loading, it will just continue to load.
 If it has already loaded successfully, calls back right away.
 If it has already failed to load, tries again.
 This method supports multiple callers and will call them all back on completion. However, each caller's completion block will be invoked once and only once.
 
 @param completion block that is invoked when object loads successfully or fails to load. An error is passed to the block if the object fails to load.
 @since 100
 */
-(void)retryLoadWithCompletion:(nullable void(^)(NSError * __nullable error))completion;

/**
 Cancels loading if it is in progress, otherwise it does nothing.
 This should be called carefully because other objects could be
 waiting for `#loadWithCompletion:` or `#retryLoadWithCompletion:` to complete and this will call them all back with
 the error of `NSUserCancelledError`
 @since 100
 */
-(void)cancelLoad;

// kvo enabled properties
/**
 Status of the load operation.
 @since 100
 */
@property (nonatomic, assign, readonly) AGSLoadStatus loadStatus;

/** The error that was encountered during the most recent load operation.
 Will be nil if the operation succeeded.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) NSError *loadError;

@end

#pragma mark loadObjects declaration

/** Block that is invoked by `AGSLoadObjects()` when all the loadable objects are finished loading.
 `finishedWithNoErrors` indicates if all the objects loaded sucessfully or if some of them encountered errors.
 @since 100
 */
typedef void (^ags_load_objects_block_t)(BOOL finishedWithNoErrors);

/** Loads an array of `AGSLoadable` objects. Calls you back once all the objects in the array are loaded.
 The callback will be invoked with `YES` (`true`) if no load errors occurred in any of the objects passed in.
 @param array of loadable objects which need to be loaded
 @param completion block that is invoked when all the loadable objects have finished loading
 @since 100
 */
AGS_EXTERN void AGSLoadObjects(NSArray<id<AGSLoadable>> *array, _Nullable ags_load_objects_block_t completion);

NS_ASSUME_NONNULL_END


