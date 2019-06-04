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

/** @file AGSEnumerator.h */ //Required for Globals API doc

/** @brief An enumerator to iterate over a collection
 
 Instances of this class represent an enumerator that can be used to iterate over a collection
 This class adopts `NSEnumerator` which permits the collection to be enumerated conveniently using a for-in loop. For example -
 
 ``` Swift
 let enumr:AGSEnumerator = ... //An enumerator instance
 for object in enumr {
   //do something
 }
 ```
 
 @since 100
 */

@interface AGSEnumerator : NSEnumerator
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/**
 Provides all the objects that can be enumerated as an array
 @since 100
 @note To conserve memory, consider iterating over the objects one-by-one using a for-in loop, or using `#nextObject`
 */
@property(nullable, nonatomic, copy, readonly) NSArray *allObjects;

#pragma mark -
#pragma mark methods

/**
 Returns the next object
 @since 100
 */
-(nullable id)nextObject;

NS_ASSUME_NONNULL_END
@end
