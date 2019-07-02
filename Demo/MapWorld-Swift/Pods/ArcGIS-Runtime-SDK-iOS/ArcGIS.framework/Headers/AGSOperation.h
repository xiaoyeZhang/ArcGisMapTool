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

#import <Foundation/Foundation.h>

/**
 Represents the state of an AGSOperation.
 */
typedef NS_ENUM(NSInteger, AGSOperationState) {
    AGSOperationStateReady,      /*!<  */
    AGSOperationStateExecuting,  /*!<  */
    AGSOperationStateCompleted   /*!<  */
};

NS_ASSUME_NONNULL_BEGIN

/**
 Protocol for objects that can be added to an AGSOperationQueue.
 @since 100
 */
@protocol AGSOperation <NSObject>

#pragma mark properties

/** The current state of the operation.
 @since 100
 */
@property (nonatomic, assign, readonly) AGSOperationState state;

/**
 The block the operation will call to signify to the operation queue that the operation is complete. This block is reserved for use by the AGSOperationQueue. Do not assign your own block to this.
 @since 100
 */
@property (nullable, nonatomic, copy) void (^internalCompletion)();

/**
 If an operation does all or most of it's work in the `execute` method it should return YES for this.
 If YES then the operation queue will dispatch this async to a global concurrent queue
 with the QOS that matches the qualityOfService specified on the AGSOperationQueue.
 If NO then the you are responsible for returning quickly from `execute` and doing the 
 operation's work on a different queue.
 Either way the completion block must be called when the operation is finished or done being canceled.
 @since 100
 */
@property (nonatomic, assign, readonly) BOOL startAsynchronously;

/**
 Whether or not cancel has been called on the operation.
 "Canceled" is a modifier on the current state since:
 1. The operation can be still "executing" until the cancel takes effect.
 2. An operation can be canceled and in a completed state at the same time.
 @since 100
 */
@property (nonatomic, assign, readonly, getter=isCanceled) BOOL canceled;

#pragma mark methods

/** Cancels the operation.
 @since 100
 */
-(void)cancel;

/** Starts the operation
 @since 100
 */
-(void)execute;

@end


/**
 A base operation class that implements the AGSOperation protocol.
 @since 100
 */
@interface AGSOperationBase : NSObject <AGSOperation>
@end

@interface AGSOperationBase (ForSubclassEyesOnly)

/**
 Subclasses can set this if they want to be started asynchronously or not.
 If an operation does most or all of it's work in `doExecute` it should set this to YES.
 If an operation returns quickly from `doExecute` and does all of it's work on a different
 queue then this value should be NO.
 The default value is YES.
 */
@property (nonatomic, assign, readwrite) BOOL startAsynchronously;

/**
 Subclasses should override to do the actual execution of the operation.
 Once done, call `doneExecuting`.
 @since 100
 */
-(void)doExecute;

/**
 Subclasses can override to do the actual work to cancel the operation.
 Once cancel is complete, call doneExecuting.
 For operations that do not do all of their work in doExecute, it makes sense to override this and cancel any network connections, etc.
 Then when the cancel is complete, you call doneExecuting.
 For operations where the work is all done in doExecute they shouldn't need to override this, you should just check the `isCanceled`
 property throughout the execution of the operation and if it is canceled then call `doneExecuting` and return.
 @since 100
 */
-(void)doCancel;

/** Subclasses should call this when they are done executing or done cancelling.
 @since 100
 */
-(void)doneExecuting;

/**
 Subclasses should override if they want to run some code once the operation is completed.
 This function is guaranteed to only be called once.
 `everStarted` will be NO if the operation was canceled before it could be started.
 @since 100
 */
-(void)didComplete:(BOOL)everStarted;

@end

NS_ASSUME_NONNULL_END






