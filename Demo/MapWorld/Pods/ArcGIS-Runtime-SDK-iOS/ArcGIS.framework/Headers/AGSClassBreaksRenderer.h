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

#import "AGSRenderer.h"

@class AGSSymbol;
@class AGSClassBreak;

/** @file AGSClassBreaksRenderer.h */ //Required for Globals API doc

/** @brief A renderer based on class breaks.
 
 A class breaks renderer symbolizes each graphic or feature based on the value of some
 numeric attribute. Graphics and features with similar values for the attribute get the same
 symbol. The "breaks" define the values at which the symbology changes.
 
 For example, suppose you have a "buildings" layer with an attribute that
 defines the building age. You want to symbolize buildings constructed since
 the year 2000 in green, buildings constructed between 1980 and 2000 in yellow,
 and buildings built before 1980 with red. This would be a good scenario for
 class breaks renderer.
 
 Any value that is greater than or equal to the minimum will be included in the
 break. Any value that is less than the maximum will be included in the break.
 
 @since 100
 */

@interface AGSClassBreaksRenderer : AGSRenderer
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

/** Initialize a class breaks renderer with a field name and an array of class breaks.
 @param fieldName name of the field to apply the class breaks to
 @param classBreaks array of class breaks
 @return A new class breaks renderer.
 @since 100
 */
-(instancetype)initWithFieldName:(NSString *)fieldName classBreaks:(NSArray<AGSClassBreak*> *)classBreaks;

/** Initialize a class breaks renderer.
 @return A new class breaks renderer.
 @since 100
 */
+(instancetype)classBreaksRenderer;

/** Initialize a class breaks renderer with a field name and an array of class breaks.
 @param fieldName name of the field to apply the class breaks to
 @param classBreaks array of class breaks
 @return A new class breaks renderer.
 @since 100
 */
+(instancetype)classBreaksRendererWithFieldName:(NSString *)fieldName classBreaks:(NSArray<AGSClassBreak*> *)classBreaks;

#pragma mark -
#pragma mark properties

/** The renderer's background fill symbol 
 @since 100.1
 */
@property (nullable, nonatomic, strong, readwrite) AGSSymbol *backgroundFillSymbol;

/** A collection of class breaks defined for the renderer. The breaks are an
 array of @c AGSClassBreak objects.
 @since 100
 */
@property (nonatomic, copy, readwrite) NSArray<AGSClassBreak*> *classBreaks;

/** The classification method used to generate class breaks.
 @since 100.2
 */
@property (nonatomic, assign, readonly) AGSRendererClassificationMethod classificationMethod;

/** The default label if the values does not fall into any of the class breaks.
 @since 100
 */
@property (nonatomic, copy, readwrite) NSString *defaultLabel;

/** The symbol to use if the value does not fall into any of the class breaks.
 @since 100
 */
@property (nullable, nonatomic, strong, readwrite) AGSSymbol *defaultSymbol;

/** Attribute field used by renderer to match values. This must be a key from
 the attributes collection of the graphic.
 @since 100
 */
@property (nonatomic, copy, readwrite) NSString *fieldName;

/** The minimum value for this class breaks renderer.
 @since 100
 */
@property (nonatomic, assign, readwrite) double minValue;

/** The normalization field.
 @since 100
 */
@property (nonatomic, copy, readwrite) NSString *normalizationField;

/** The normalization total for this class breaks renderer.
 Used when `#normalizationType` is `AGSNormalizationTypeByPercentOfTotal`.
 @since 100
 */
@property (nonatomic, assign, readwrite) double normalizationTotal;

/** The normalization type.
 @since 100
 */
@property (nonatomic, assign, readwrite) AGSRendererNormalizationType normalizationType;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END
@end
