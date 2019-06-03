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


/** @file AGSFeatureEnumerator.h */ //Required for Globals API doc

/** @brief An enumerator to iterate over features
 
 Instances of this class represent an enumerator to iterate over features
 
 @since 100
 */
@interface AGSFeatureEnumerator : NSEnumerator

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/**
 Provides all the features that can be enumerated as an array of `AGSFeature` objects.
 @since 100
 @note Accessing this property causes all the features to be loaded into memory. To conserve memory, consider iterating over the features one-by-one using a for-in loop, or using `#nextObject`.
 */
@property(nonatomic, copy, readonly) NSArray<AGSFeature*> *allObjects;

#pragma mark -
#pragma mark methods

/**
 Returns the next feature
 @since 100
 */
-(nullable AGSFeature*)nextObject;

/**
 returns YES if there is another feature available
 @since 100
 */
-(BOOL)hasNextObject;

/**
 puts the cursor back to the beginning
 @since 100
 */
-(void)reset;

NS_ASSUME_NONNULL_END

@end
