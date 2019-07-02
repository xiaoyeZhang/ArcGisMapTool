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

#import "AGSMarkerSymbol.h"

/** @file AGSTextSymbol.h */ //Required for Globals API doc

/** @brief A text symbol
 
 Instances of this class represent text symbols. Symbols describe how graphics and features look on a map.
 Text symbols are used to display text for graphics and features. The graphic or feature can be based on
 any type of geometry - point, multipoint, polyline, or polygon.
 
 @since 100
 */

@interface AGSTextSymbol : AGSMarkerSymbol
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

/** Initialize a text symbol with the provided parameters
 @param size of the symbol in points (not pixels)
 @param text to be displayed by the symbol
 @param color of the text
 @return Initialized text symbol
 @since 100
 */
-(instancetype)initWithText:(NSString *)text
                      color:(AGSColor *)color
                       size:(CGFloat)size
        horizontalAlignment:(AGSHorizontalAlignment)horizontalAlignment
          verticalAlignment:(AGSVerticalAlignment)verticalAlignment;

/** Initialize a text symbol with the provided parameters
 @param size of the symbol in points (not pixels)
 @param text to be displayed by the symbol
 @param color of the text
 @return Initialized text symbol
 @since 100
 */
+(instancetype)textSymbolWithText:(NSString *)text
                            color:(AGSColor *)color
                             size:(CGFloat)size
              horizontalAlignment:(AGSHorizontalAlignment)horizontalAlignment
                verticalAlignment:(AGSVerticalAlignment)verticalAlignment;

/** Initialize a text symbol
 @return Initialized text symbol
 @since 100
 */
+(instancetype)textSymbol;

#pragma mark -
#pragma mark properties

/** Background color for the text
 @since 100.1
 */
@property (nonatomic, strong, readwrite) AGSColor *backgroundColor;

/** Color of the text
 @since 100
 */
@property (nonatomic, strong, readwrite) AGSColor *color;

/** Font decoration for the text
 @since 100
 */
@property (nonatomic, assign, readwrite) AGSFontDecoration fontDecoration;

/** Font family for the text
 @since 100
 */

@property (nonatomic, copy, readwrite) NSString *fontFamily;

/** Font style for the text
 @since 100
 */
@property (nonatomic, assign, readwrite) AGSFontStyle fontStyle;

/** Font weight for the text
 @since 100
 */
@property (nonatomic, assign, readwrite) AGSFontWeight fontWeight;

/** Color of the halo to put around the text.
 @see `#haloWidth`
 @since 100
 */
@property (nullable, nonatomic, strong, readwrite) AGSColor *haloColor;

/** Width of the text halo
 @see `#haloColor`
 @since 100
 */
@property (nonatomic, assign, readwrite) CGFloat haloWidth;

/** Horizontal alignment of the text
 @since 100
 */
@property (nonatomic, assign, readwrite) AGSHorizontalAlignment horizontalAlignment;

/** Indicates whether or not kerning should be applied to the text. Kerning affects spacing of two particular characters to correct for visually uneven spacing.
 @since 100.1
 */
@property (nonatomic, assign, readwrite, getter=isKerningEnabled) BOOL kerningEnabled;

/** Color for the outline of the text.
 @see `#outlineWidth`
 @since 100
 */
@property (nullable, nonatomic, strong, readwrite) AGSColor *outlineColor;

/** Width of the text outline.
 @see `#outlineColor`
 @since 100
 */
@property (nonatomic, assign, readwrite) CGFloat outlineWidth;

/** Size of the text
 @since 100
 */
@property (nonatomic, assign, readwrite) CGFloat size;

/** Text to display
 @since 100
 */
@property (nonatomic, copy, readwrite) NSString *text;

/** Vertical alignment of the text
 @since 100
 */
@property (nonatomic, assign, readwrite) AGSVerticalAlignment verticalAlignment;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END
@end
