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
@class AGSAreaUnit;

/** @file AGSLinearUnit.h */ //Required for Globals API doc

/** @brief Represents linear units.
 
 Instances of this class represent a linear unit of measurement.
 
 @since 100
 */
@interface AGSLinearUnit : AGSUnit

#pragma mark -
#pragma mark initializers
NS_ASSUME_NONNULL_BEGIN

-(instancetype)init __attribute__((unavailable("init is not available.")));

/**
 Initializes a linear unit.
 
 @param unitID linear unit ID
 @since 100
 */
-(nullable instancetype)initWithUnitID:(AGSLinearUnitID)unitID;

/**
 Initializes a linear unit.
 
 @param unitID linear unit ID
 @since 100
 */
+(nullable instancetype)unitWithUnitID:(AGSLinearUnitID)unitID;

/**
 Initializes a linear unit from an AGSAreaUnit.
 @param areaUnit to use to initialize a linear unit
 @since 100
 */
-(nullable instancetype)initWithAreaUnit:(AGSAreaUnit*)areaUnit;

/**
 Initializes a linear unit from an AGSAreaUnit.
 @param areaUnit to use to initialize a linear unit
 @since 100
 */
+(nullable instancetype)linearUnitWithAreaUnit:(AGSAreaUnit*)areaUnit;

/**
 A linear unit representing meters.
 
 @since 100
 */
+(instancetype)meters;

/**
 A linear unit representing feet.
 
 @since 100
 */
+(instancetype)feet;

/**
 A linear unit representing miles.
 
 @since 100
 */
+(instancetype)miles;

/**
 A linear unit representing kilometers.
 
 @since 100
 */
+(instancetype)kilometers;

#pragma mark -
#pragma mark properties



@property (nonatomic, assign, readonly) AGSLinearUnitID unitID;

#pragma mark -
#pragma mark methods

/**
 Returns the corresponding area unit for this linear unit.
 
 @since 100
 */
-(nullable AGSAreaUnit*)toAreaUnit;

/**
 Converts the value from this unit to meters.
 
 @param value to convert.
 @since 100
 */
-(double)convertToMeters:(double)value;

/**
 Converts the value from meters into this unit.
 
 @param meters to convert
 @since 100
 */
-(double)convertFromMeters:(double)meters;

/**
 Converts the value from this unit to the specified linear unit.
 
 @param value to convert.
 @param toUnit The units the converted value needs to be in
 @since 100
 */
-(double)convert:(double)value toUnit:(AGSLinearUnit*)toUnit;

/**
 Converts the value from the specified linear unit into this unit.
 
 @param value to convert
 @param fromUnit The units the given value is already in.
 @since 100
 */
-(double)convert:(double)value fromUnit:(AGSLinearUnit*)fromUnit;

NS_ASSUME_NONNULL_END
@end
