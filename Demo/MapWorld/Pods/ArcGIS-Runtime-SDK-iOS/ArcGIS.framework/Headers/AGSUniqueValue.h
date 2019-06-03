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

@class AGSSymbol;

/** @file AGSUniqueValue.h */ //Required for Globals API doc

/** @brief Each unique value that is symbolized differently by a unique value
 renderer.
 
 Instances of this class represent a unique value of matching attributes that must be symbolized by a unique value renderer.
 
 @since 100
 */


@interface AGSUniqueValue : AGSObject <AGSJSONSerializable, NSCopying>
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

/** Initialize a unique value.
 @return A new unique value.
 @since 100
 */
+(instancetype)uniqueValue;

/** Initialize a unique value.
 @param label for this unique value.
 @param description for this unique value.
 @param values The attribute value or set of values that comprise this unique value.
 @param symbol The symbol to be used to display this unique value.
 @return A new unique value.
 @since 100
 */
-(instancetype)initWithDescription:(NSString *)description
                             label:(NSString *)label
                            symbol:(AGSSymbol *)symbol
                            values:(NSArray<id> *)values;

/** Initialize a unique value.
 @param label for this unique value.
 @param description for this unique value.
 @param values The attribute value or set of values that comprise this unique value.
 @param symbol The symbol to be used to display this unique value.
 @return A new unique value.
 @since 100
 */
+(instancetype)uniqueValueWithDescription:(NSString *)description
                                    label:(NSString *)label
                                   symbol:(AGSSymbol *)symbol
                                   values:(NSArray<id> *)values;

#pragma mark -
#pragma mark properties

/** Label for this unique value.
 @since 100
 */
@property (nonatomic, copy, readwrite) NSString *label;

/** A description for this unique value.
 @since 100
 */
@property (nonatomic, copy, readwrite) NSString *valueDescription;

/** The symbol used to display the value.
 @since 100
 */
@property (nullable, nonatomic, strong, readwrite) AGSSymbol *symbol;

/** The attribute value or set of values that comprise this unique value.
 @since 100
 */
@property (nonatomic, copy, readwrite) NSArray<id> *values;

#pragma mark -
#pragma mark methods

/** Compares this unique value to another for equality.
 @param other unique value to compare this one to
 @return whether equal or not
 @since 100
 */
-(BOOL)isEqualToUniqueValue:(AGSUniqueValue*)other;

NS_ASSUME_NONNULL_END
@end
