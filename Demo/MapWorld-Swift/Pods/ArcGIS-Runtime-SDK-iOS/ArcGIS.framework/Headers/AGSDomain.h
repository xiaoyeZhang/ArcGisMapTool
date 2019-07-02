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

/** @file AGSDomain.h */ //Required for Globals API doc

/** @brief information about a field's domain
 
 
 @since 100
 */
@interface AGSDomain : AGSObject

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

#pragma mark -
#pragma mark properties

/** Name of the domain
 @since 100
 */
@property (nonatomic, copy, readonly) NSString *name;

#pragma mark -
#pragma mark methods

/** Compares this domain to another for equality
 @param other domain to compare this one to
 @return whether the two domains are equal or not
 @since 100.4
 */
-(BOOL)isEqualToDomain:(AGSDomain*)other;

NS_ASSUME_NONNULL_END

@end
