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

#import "AGSObject.h"

/** @file AGSUnit.h */ //Required for Globals API doc

/** @brief Base class for all units.
 
 A base class for all units of measurement.
 
 @since 100
 */
@interface AGSUnit : AGSObject
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available. You must initialize with a unitID.")));

#pragma mark -
#pragma mark properties

/**
 The name of the measurement unit.
 
 @since 100
 */
@property (nonatomic, copy, readonly) NSString *name;

/**
 A user-friendly name of the measurement unit.
 
 @since 100
 */
@property (nonatomic, copy, readonly) NSString *displayName;

/**
 A plural form of the user-friendly name.
 
 @since 100
 */
@property (nonatomic, copy, readonly) NSString *pluralDisplayName;

/**
 Abbreviated name of the unit.
 
 @since 100
 */
@property (nonatomic, copy, readonly) NSString *abbreviation;

#pragma mark -
#pragma mark methods

/**
 Compares whether two units are equal.
 
 @param unit to compare this one to
 @return YES if the units are equal
 @since 100
 */
-(BOOL)isEqualToUnit:(AGSUnit*)unit;

NS_ASSUME_NONNULL_END
@end
