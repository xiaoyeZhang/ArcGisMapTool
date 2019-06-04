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
@class AGSUniqueValue;

/** @file AGSUniqueValueRenderer.h */ //Required for Globals API doc

/** @brief A renderer based on unique values.
 
 A unique value renderer symbolizes groups of graphics or features that have matching
 attributes with the same symbol. This is most common with nominal, or string data. Different groups use different symbols.
 
 For example, you could use a unique value renderer to symbolize zoning
 designations: yellow for "Residential", purple for "Industrial", red for
 "Commercial", and so on. You can also use unique value renderers on numeric
 fields that are coded values, or on ordinal attributes such as "First", "Second",
 "Third", and so on.
 
 Typically, graphics and features are rendered based on the unique values of one attribute
 field. However, up to three fields can be combined to generate a unique value.
 
 @since 100
 */

@interface AGSUniqueValueRenderer : AGSRenderer
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

/** Initialize a unique value renderer.
 @return A unique value renderer object.
 @since 100
 */
+(instancetype)uniqueValueRenderer;

/** Initialize a unique value renderer with the given properties.
 @param fieldNames An array of strings with field names representing attributes of a graphic or feature that the renderer uses to match values against.
 @param uniqueValues An array of @c AGSUniqueValue objects defining the symbol for each matched value
 @param defaultLabel for the renderer
 @param defaultSymbol used for any unmatched values
 @return A unique value renderer object.
 @since 100
 */
-(instancetype)initWithFieldNames:(nullable NSArray<NSString*> *)fieldNames
                     uniqueValues:(nullable NSArray<AGSUniqueValue*> *)uniqueValues
                     defaultLabel:(NSString*)defaultLabel
                    defaultSymbol:(nullable AGSSymbol*)defaultSymbol;

/** Initialize a unique value renderer with the given properties
 @param fieldNames An array of strings with field names representing attributes of a graphic or feature that the renderer uses to match values against.
 @param uniqueValues An array of @c AGSUniqueValue objects defining the symbol for each matched value
 @param defaultLabel for the renderer
 @param defaultSymbol used for any unmatched values
 @return A unique value renderer object.
 @since 100
 */
+(instancetype)uniqueValueRendererWithFieldNames:(nullable NSArray<NSString*> *)fieldNames
                                    uniqueValues:(nullable NSArray<AGSUniqueValue*> *)uniqueValues
                                    defaultLabel:(NSString*)defaultLabel
                                   defaultSymbol:(nullable AGSSymbol*)defaultSymbol;

#pragma mark -
#pragma mark properties

/** Default label for the renderer
 @since 100
 */
@property (nonatomic, copy, readwrite) NSString *defaultLabel;

/** Default symbol for the renderer. This symbol is used for any unmatched values.
 @since 100
 */
@property (nullable, nonatomic, strong, readwrite) AGSSymbol *defaultSymbol;

/** A list of strings with field names.
 The names represent attributes of a graphic or feature that the renderer uses to match values against.
 @since 100
 */
@property (nonatomic, copy, readwrite) NSArray<NSString*> *fieldNames;

/** An array of @c AGSUniqueValue objects defining the symbol for each matched value
 @since 100
 */
@property (nonatomic, copy, readwrite) NSArray<AGSUniqueValue*> *uniqueValues;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END
@end
