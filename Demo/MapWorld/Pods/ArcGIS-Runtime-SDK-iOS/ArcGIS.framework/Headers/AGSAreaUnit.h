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
@class AGSLinearUnit;

/** @file AGSAreaUnit.h */ //Required for Globals API doc

/** @brief Represents area units
 
 Instances of this class represetnt an area unit of measurement.
 
 @since 100
 */
@interface AGSAreaUnit : AGSUnit
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

/**
 Initializes an area unit.
 
 @param unitID area unit ID
 @since 100
 */
-(nullable instancetype)initWithUnitID:(AGSAreaUnitID)unitID;

/**
 Initializes an area unit from the corresponding linear unit.
 
 @param linearUnit The linear unit that you want to create an area unit from.
 @since 100
 */
-(nullable instancetype)initWithLinearUnit:(AGSLinearUnit*)linearUnit;

/**
 Initializes an area unit.
 
 @param unitID area unit ID
 @since 100
 */
+(nullable instancetype)unitWithUnitID:(AGSAreaUnitID)unitID;

/**
 Initializes an area unit from the corresponding linear unit.
 
 @param linearUnit The linear unit that you want to create an area unit from.
 @since 100
 */
+(nullable instancetype)areaUnitWithLinearUnit:(AGSLinearUnit*)linearUnit;

/**
 An area unit representing sq. feet
 
 @since 100
 */
+(instancetype)squareFeet;

/**
 An area unit representing sq. meters
 
 @since 100
 */
+(instancetype)squareMeters;

/**
 An area unit representing sq. miles
 
 @since 100
 */
+(instancetype)squareMiles;

/**
 An area unit representing sq. kilometers
 
 @since 100
 */
+(instancetype)squareKilometers;

#pragma mark -
#pragma mark properties

@property (nonatomic, assign, readonly) AGSAreaUnitID unitID;

#pragma mark -
#pragma mark methods

/**
 Returns the corresponding linear unit for this area unit.
 
 @since 100
 */
-(nullable AGSLinearUnit*)toLinearUnit;

/**
 Converts the value from this unit to sq. meters.
 
 @param area to convert.
 @since 100
 */
-(double)convertToSquareMeters:(double)area;

/**
 Converts the value from sq. meters into this unit.
 
 @param area to convert
 @since 100
 */
-(double)convertFromSquareMeters:(double)area;

/**
 Converts the value from this unit to the specified area unit.
 
 @param area to convert.
 @param toUnit The units the converted value needs to be in
 @since 100
 */
-(double)convert:(double)area toUnit:(AGSAreaUnit*)toUnit;

/**
 Converts the value from the specified area unit into this unit.
 
 @param area to convert
 @param fromUnit The units the given value is already in.
 @since 100
 */
-(double)convert:(double)area fromUnit:(AGSAreaUnit*)fromUnit;

NS_ASSUME_NONNULL_END
@end
