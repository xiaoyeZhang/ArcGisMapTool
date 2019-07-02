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
@protocol AGSOperation;

NS_ASSUME_NONNULL_BEGIN

/**
 A lightweight operation queue that supports AGSOperations.
 Similar to NSOperationQueue, but lighter weight and does not support operation dependencies.
 @since 100
 */
@interface AGSOperationQueue : NSObject

/**
 Returns an instance of an operation queue that can be shared throughout an application.
 @since 100
 */
+(instancetype)sharedOperationQueue;

/**
 The operations that have been added to this queue.
 @since 100
 */
@property (nonatomic, copy, readonly) NSArray<id<AGSOperation>> *operations;

/**
 The number of concurrent operations that can be running at one time.
 0 is the default. A value of 0 means that an unlimited amount of operations can be executing concurrently.
 @since 100
 */
@property (nonatomic, assign, readwrite) NSUInteger maxConcurrentOperationCount;

/**
 The QOS of the dispatch queue that is used for executing synchronous AGSOperations.
 @since 100
 */
@property (nonatomic, assign, readwrite) NSQualityOfService qualityOfService;

/** Adds an operation to the queue. An operation should only be added to a single queue.
 @since 100
 */
-(void)addOperation:(id<AGSOperation>)op;

/** Cancels all operations in the queue.
 @since 100
 */
-(void)cancelAllOperations;

/** Blocks until all the operations in the queue are done executing.
 @since 100
 */
-(void)waitUntilAllOperationsAreFinished;

@end

NS_ASSUME_NONNULL_END
