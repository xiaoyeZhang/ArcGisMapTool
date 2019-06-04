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

#import "AGSUnit.h"

/** @file AGSAngularUnit.h */ //Required for Globals API doc

/** @brief Represents angular units
 
 Instances of this class represetnt an angular unit of measurement.
 
 @since 100
 */
@interface AGSAngularUnit : AGSUnit
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

/**
 Initializes an angular unit.
 
 @param unitID angular unit ID
 @since 100
 */
-(nullable instancetype)initWithUnitID:(AGSAngularUnitID)unitID;

/**
 Initializes an angular unit.
 
 @param unitID angular unit ID
 @since 100
 */
+(nullable instancetype)unitWithUnitID:(AGSAngularUnitID)unitID;

/**
 An angular unit representing degrees
 
 @since 100
 */
+(instancetype)degrees;

/**
 An angular unit representing radians
 
 @since 100
 */
+(instancetype)radians;

#pragma mark -
#pragma mark properties

@property (nonatomic, assign, readonly) AGSAngularUnitID unitID;

#pragma mark -
#pragma mark methods

/**
 Converts the value from this unit to radians
 
 @param angle to convert.
 @since 100
 */
-(double)convertToRadians:(double)angle;

/**
 Converts the value from radians into this unit.
 
 @param radians Value to convert
 @since 100
 */
-(double)convertFromRadians:(double)radians;

/**
 Converts the value from this unit to the specified angular unit.
 
 @param angle to convert.
 @param toUnit The units the converted value needs to be in
 @since 100
 */
-(double)convert:(double)angle toUnit:(AGSAngularUnit*)toUnit;

/**
 Converts the value from the specified angular unit into this unit.
 
 @param value to convert
 @param fromUnit The units the given value is already in.
 @since 100
 */
-(double)convert:(double)value fromUnit:(AGSAngularUnit*)fromUnit;

NS_ASSUME_NONNULL_END
@end
