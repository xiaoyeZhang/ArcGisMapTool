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

#import "AGSObject.h"

/** @file AGSBackgroundGrid.h */ //Required for Globals API doc

/** @brief Background for contents of `AGSMapView`
 
 Instances of this class represent the background for contents of `AGSMapView`
 
 @since 100
 */
@interface AGSBackgroundGrid : AGSObject
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

/** Initialize the background grid with specified properties
 @param color Fill color of the background
 @param gridLineColor Color of background grid lines
 @param gridLineWidth Width (in points) of background grid lines
 @param gridSize Size (in points) of the background grid
 @return initialized background
 @since 100
 */
-(instancetype)initWithColor:(AGSColor*)color
               gridLineColor:(AGSColor*)gridLineColor
               gridLineWidth:(double)gridLineWidth
                    gridSize:(double)gridSize;

/** Initialize the background grid with specified properties
 @param color Fill color of the background
 @param gridLineColor Color of background grid lines
 @param gridLineWidth Width (in points) of background grid lines
 @param gridSize Size (in points) of the background grid
 @return initialized background
 @since 100
 */
+(instancetype)backgroundGridWithColor:(AGSColor*)color
                         gridLineColor:(AGSColor*)gridLineColor
                         gridLineWidth:(double)gridLineWidth
                              gridSize:(double)gridSize;
#pragma mark -
#pragma mark properties

/** The fill color of the background
 @since 100
 */
@property (nonatomic, strong, readwrite) AGSColor *color;

/** The color of background grid lines
 @since 100
 */
@property (nonatomic, strong, readwrite) AGSColor *gridLineColor;

/** The width (in points) of background grid lines
 @since 100
 */
@property (nonatomic, assign, readwrite) double gridLineWidth;

/** The size (in points) of the background grid
 @since 100
 */
@property (nonatomic, assign, readwrite) double gridSize;

/** Visibility of the background grid
 @since 100.1
 */
@property (nonatomic, assign, readwrite, getter=isVisible) BOOL visible;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END
@end
