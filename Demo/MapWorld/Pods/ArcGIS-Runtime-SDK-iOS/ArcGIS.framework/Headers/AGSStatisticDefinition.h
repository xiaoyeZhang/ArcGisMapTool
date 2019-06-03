/*
 COPYRIGHT 2017 ESRI
 
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

/** @file AGSStatisticDefinition.h */ //Required for Globals API doc

/** @brief Defines a statistic to be queried
 
 Instances of this class represent a type used for defining a statistic to be queried in the feature table.
 
 @since 100.2
 */
@interface AGSStatisticDefinition : AGSObject

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));


/** Initialize a statistic definition with the provided info
 @param onFieldName The name of the field in the table containing values on which the statistic should be computed.
 @param statisticType The statistic to calculate.
 @param outputAlias The name for this statistic in the results. This is optional.
 @return An initialized statistic definition
 @since 100.2
 */
-(instancetype)initWithOnFieldName:(NSString *)onFieldName
                     statisticType:(AGSStatisticType)statisticType
                       outputAlias:(nullable NSString *)outputAlias;

/** Initialize a statistic definition with the provided info
 @param onFieldName The name of the field in the table containing values on which the statistic should be computed.
 @param statisticType The statistic to calculate.
 @param outputAlias The name for this statistic in the results. This is optional.
 @return An initialized statistic definition
 @since 100.2
 */
+(instancetype)statisticDefinitionWithOnFieldName:(NSString *)onFieldName
                                    statisticType:(AGSStatisticType)statisticType
                                      outputAlias:(nullable NSString *)outputAlias;

#pragma mark -
#pragma mark properties

/** The name of the field in the table containing values on which the statistic should be computed.
 @since 100.2
 */
@property (nonatomic, copy, readwrite) NSString *onFieldName;

/** The name for this statistic in the results.
 @since 100.2
 */
@property (nonatomic, copy, readwrite) NSString *outputAlias;

/** The statistic to calculate.
 @since 100.2
 */
@property (nonatomic, assign, readwrite) AGSStatisticType statisticType;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end
