/*
 COPYRIGHT 2016 ESRI
 
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

/** @file AGSGrid.h */ //Required for Globals API doc

/** @brief A base class for displaying coordinate system grids on a map
 
 A base class for displaying coordinate system grids such as MGRS, USNG, UTM and LatitudeLongitude. It contains all of the common operations and properties that apply to displaying and working with the different grids currently supported. This includes toggling visibility and configuring layout and appearance preferences.
 
 @since 100
 */
@interface AGSGrid : AGSObject

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

#pragma mark -
#pragma mark properties

/** Specifies whether the grid is visible or not
 @since 100
 */
@property (nonatomic, assign, readwrite, getter=isVisible) BOOL visible;

/** Specifies the grid's text label offset (in screen points) from the edge of the map view.
 @since 100
 */
@property (nonatomic, assign, readwrite) double labelOffset;

/** Specifies the positioning of the grid's text labels.
 @since 100
 */
@property (nonatomic, assign, readwrite) AGSGridLabelPosition labelPosition;

/** Specifies whether the grid's text labels are visible or not.
 @since 100
 */
@property (nonatomic, assign, readwrite) BOOL labelVisibility;

/** Returns the number of levels of resolution supported by the grid. The line and label style can be set for each of these resolution levels.
 The resolution of the displayed grid may adapt as the scale of the displayed map changes.
 @since 100
 */
@property (nonatomic, assign, readonly) NSInteger levelCount;

#pragma mark -
#pragma mark methods


/** Returns the line symbol used for the grid lines at the given resolution level.
 @param level specifiying the resolution level for which the symbol is desired
 @return symbol at the specified resolution level
 @since 100
 */
-(AGSSymbol*)lineSymbolForLevel:(NSInteger)level;

/** Set the line symbol used for the grid lines at the given resolution level.
 @param symbol to be used for grid lines
 @param level specifiying the resolution level for which the symbol is desired
 @since 100
 */
-(void)setLineSymbol:(AGSSymbol*)symbol forLevel:(NSInteger)level;


/** Returns the text symbol used for the grid text labels at the given resolution level.
 @param level specifiying the resolution level for which the symbol is desired
 @return symbol at the specified resolution level
 @since 100
 */
-(AGSSymbol*)textSymbolForLevel:(NSInteger)level;

/** Set the text symbol used for the grid text labels at the given resolution level.
 @param symbol to be used for grid text label
 @param level specifiying the resolution level for which the symbol is desired
 @since 100
 */
-(void)setTextSymbol:(AGSSymbol*)symbol forLevel:(NSInteger)level;

NS_ASSUME_NONNULL_END

@end
