/*
 COPYRIGHT 2018 ESRI
 
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

@class AGSLinearUnit;

/** @file AGSDistance.h */ //Required for Globals API doc

/** @brief Represents distance measurement
 
 Instances of this class hold the distance measurement data associated with a specific distance component.
 
 @since 100.3
 */
@interface AGSDistance : AGSObject
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** The linear unit by which the `#value` of the distance is measured.
 @since 100.3
 */
@property (nonatomic, strong, readonly) AGSLinearUnit *unit;

/** The scalar value of the distance, measured by the associated `#unit`.
 @since 100.3
 */
@property (nonatomic, assign, readonly) double value;

NS_ASSUME_NONNULL_END
@end
