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

/** @file AGSClassBreak.h */ //Required for Globals API doc

/** @brief A class break for the @c AGSClassBreaksRenderer
 
 Instances of this class represent class breaks. A class break specifies a
 range of values and a corresponding symbol. @c AGSClassBreaksRenderer applies
 the symbol to graphics which have values that fall within the specified range.
 
 @since 100
 */


@interface AGSClassBreak : AGSObject <AGSJSONSerializable, NSCopying>
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

/** Initialize an <code>AGSClassBreak</code>.
 @param label The label for the symbol used to draw the value.
 @param description The description for the symbol used to draw the value.
 @param minValue The minimum value of the range that matches this class break
 @param maxValue The maximum value of the range that matches this class break
 @param symbol The symbol used to display the value.
 @return A new class break
 @since 100
 */
- (instancetype)initWithDescription:(NSString *)description
                              label:(NSString *)label
                           minValue:(double)minValue
                           maxValue:(double)maxValue
                             symbol:(AGSSymbol *)symbol;


/** Initialize an <code>AGSClassBreak</code>.
 @return A new class break
 @since 100
 */
+(instancetype)classBreak;


/** Initialize an <code>AGSClassBreak</code>.
 @param label The label for the symbol used to draw the value.
 @param description The description for the symbol used to draw the value.
 @param minValue The minimum value of the range that matches this class break
 @param maxValue The maximum value of the range that matches this class break
 @param symbol The symbol used to display the value.
 @return A new class break
 @since 100
 */
+(instancetype)classBreakWithDescription:(NSString *)description
                                   label:(NSString *)label
                                minValue:(double)minValue
                                maxValue:(double)maxValue
                                  symbol:(AGSSymbol *)symbol;

#pragma mark -
#pragma mark properties

/** Label for the symbol used to draw the value.
 @since 100
 */
@property (nonatomic, copy, readwrite) NSString * label;

/** Description for the symbol used to draw the value.
 @since 100
 */
@property (nonatomic, copy, readwrite) NSString * breakDescription;

/** The minimum value for this class break.
 @since 100
 */
@property (nonatomic, assign, readwrite) double minValue;

/** The maximum value for this class break.
 @since 100
 */
@property (nonatomic, assign, readwrite) double maxValue;

/** Symbol to use for this class break.
 @since 100
 */
@property (nullable, nonatomic, strong, readwrite) AGSSymbol * symbol;

#pragma mark -
#pragma mark methods

/** Compares this class break to another for equality.
 @param other class break to compare this one to
 @return whether equal or not
 @since 100
 */
-(BOOL)isEqualToClassBreak:(AGSClassBreak*)other;

NS_ASSUME_NONNULL_END
@end
