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

#pragma mark -

#import "AGSObject.h"

/** @file AGSTimeReference.h */ //Required for Globals API doc

/** @brief Contains information about how the time was measured.
 
 Instances of this class represent time reference which contains information about
 how the time was measured. Conceptually similar to a spatial reference, includes
 information about daylight savings time in addition to the time zone. You can
 use it to project a time object from one time zone to another. You can also
 associate one of several predefined time zones with a given time object.
 
 @since 100
 */
@interface AGSTimeReference : AGSObject
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** Time zone information associated with the time reference.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) NSTimeZone *timeZone;

/** The name of the time zone associated with the time reference.
 @since 100.3
 */
@property (nonatomic, copy, readonly) NSString *timeZoneName;

/** Determines whether or not the referenced time respects Daylight Savings Time.
 @since 100
 */
@property (nonatomic, assign, readonly) BOOL respectsDaylightSavings;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END
@end
