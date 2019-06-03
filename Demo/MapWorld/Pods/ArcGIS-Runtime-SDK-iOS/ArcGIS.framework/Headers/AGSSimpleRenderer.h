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

/** @file AGSSimpleRenderer.h */ //Required for Globals API doc

/** @brief A simple renderer based on a single symbol.
 
 Instances of this class represent simple renderers. Renderers symbolize all
 graphics in a graphics layer or features in a feature layer according to a given scheme. This is easier than
 symbolizing each graphic individually.
 
 Simple renderers use a simple scheme - the same symbol is used for all graphics and features.
 
 @since 100
 */


@interface AGSSimpleRenderer : AGSRenderer
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

/** Initialize renderer with desired symbol.
 @param symbol The symbol to be used to render all graphics.
 @return A new simple renderer object.
 @since 100
 */
-(instancetype)initWithSymbol:(nullable AGSSymbol*)symbol;

/** Initialize renderer without any symbol.
 @return A new simple renderer object.
 @since 100
 */
+(instancetype)simpleRenderer;

/** Initialize renderer with desired symbol.
 @param symbol The symbol to be used to render all graphics.
 @return A new simple renderer object.
 @since 100
 */
+(instancetype)simpleRendererWithSymbol:(nullable AGSSymbol*)symbol;

#pragma mark -
#pragma mark properties

/** The symbol for the renderer.
 @since 100
 */
@property (nullable, nonatomic, strong, readwrite) AGSSymbol *symbol;

/** The description for the renderer
 @since 100
 */
@property (nonatomic, copy, readwrite) NSString *rendererDescription;

/* The label for the renderer
 @since 100
 */
@property (nonatomic, copy, readwrite) NSString *label;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END
@end
