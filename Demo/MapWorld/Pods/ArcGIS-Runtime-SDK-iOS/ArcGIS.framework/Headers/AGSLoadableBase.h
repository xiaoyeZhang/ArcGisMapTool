/*
 COPYRIGHT 2013 ESRI
 
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
/** @file AGSLoadableBase.h */ //Required for Globals API doc

#import "AGSObject.h"
#import "AGSLoadable.h"

NS_ASSUME_NONNULL_BEGIN


/**
 @brief A base class for loadables
 
 A base class for objects that can load data asynchronously, for example, from a remote network location or the local file system.
 
 It provides some basic plumbing that make it easier to adopt the `<AGSLoadable>` protocol. For example, you don't have to worry about keeping references to completion blocks, loading data on background threads, invoking completion blocks, managing the load status, and so on; this base class will handle all that.
 
 Subclasses need only pay attention to the methods defined in `AGSLoadableBase(ForSubclassEyesOnly)`
 
 @see AGSLoadableBase(ForSubclassEyesOnly) for implementing loadables
 @since 100
 */
@interface AGSLoadableBase : AGSObject <AGSLoadable>

@end


/** @brief Information relevant to sublcasses of @c AGSLoadableBase
 
 This category organizes the  methods that are relevant to subclassing `AGSLoadableBase`. Although you can adopt the `<AGSLoadable>` protocol directly in your classes, it will often be easier to subclass `AGSLoadableBase`. Developers can easily make their objects implement the loadable behavior by paying special attention to the methods in this category.
 
 
 Here are some guidelines:
 - Override `AGSLoadableBase#doStartLoading:` to load your data. Call `AGSLoadableBase#loadDidFinishWithError:` upon completion, passing in the error if any.
 - Override `AGSLoadableBase#doCancelLoading` to cancel loading your data. Call `AGSLoadableBase#loadDidFinishWithError:` at the end passing in an error representing `NSUserCancelledError`
 
 @since 100
 */
@interface AGSLoadableBase (ForSubclassEyesOnly)

/**
 Never call this method directly. The framework calls this method on a background thread when `AGSLoadable#loadWithCompletion:` or `AGSLoadable#retryLoadWithCompletion:` is called.  It is meant to be overriden by subclasses. Subclasses should override this method to load their data and call `AGSLoadableBase#loadDidFinishWithError:` upon completion, passing in the error if any.
 
 @param retrying flag that is true if this method was called from `AGSLoadable#retryLoadWithCompletion:`.
 @since 100
 */
-(void)doStartLoading:(BOOL)retrying;

/**
 Never call this method directly. The framework calls this method on a background thread when `AGSLoadable#cancelLoad`  is called. It is meant to be overriden by subclasses.
 Subclasses should override this method to cancel loading their data and call `AGSLoadableBase#loadDidFinishWithError:` at the end passing in an error representing `NSUserCancelledError`.

 @since 100
 */
-(void)doCancelLoading;

/**
 Only subclasses should call this method in `AGSLoadableBase#doStartLoading:` and `AGSLoadableBase#doCancelLoading` when done loading or failed to load.
 @since 100
 */
-(void)loadDidFinishWithError:(nullable NSError*)error;

/**
 Never call this method directly. The framework calls this method on a background thread when `AGSLoadable#loadStatus` changes  is called. Subclasses can optionally implement this to know when their loading status has changed.
 @since 100
 */
-(void)onLoadStatusChanged;

@end

NS_ASSUME_NONNULL_END
