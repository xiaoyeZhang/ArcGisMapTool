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

/** @file AGSDistanceSymbolRange.h */ //Required for Globals API doc

/** @brief A distance range for symbols
 
 Instances of this class represent a distance range for symbols. It links a symbol to a minimum and maximum distance, in meters, from the viewpoint's camera. The symbol will be visible only within the range.
 
 When a range's maximum distance is set to 0, the symbol that is assigned will be visible from the minimum distance set and onward. Setting a minimum distance to be greater than a maximum distance will cause the symbol to never display.
 
 @since 100
 */
@interface AGSDistanceSymbolRange : AGSObject

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

/** Initialize a new distance range for the provided symbol. Both min and max distance will be set to 0, which implies the symbol should be visible at all distances from the scene viewpoint's camera.
 @param symbol to use for the range
 @return An initialized distance symbol range.
 @since 100
 */
-(instancetype)initWithSymbol:(AGSSymbol*)symbol;


/** Initialize a new distance range for the provided symbol with the given distances.
 @param minDistance of the symbol, in meters, from the scene viewpoint's camera at which the symbol becomes visible
 @param maxDistance of the symbol, in meters, from the scene viewpoint's camera until which the symbol remains visible
 @param symbol to use for the range
 @return An initialized distance symbol range.
 @since 100
 */
-(instancetype)initWithSymbol:(AGSSymbol*)symbol
                  minDistance:(double)minDistance
                  maxDistance:(double)maxDistance;

/** Initialize a new distance range for the provided symbol. Both min and max distance will be set to 0, which implies the symbol should be visible at all distances from the scene viewpoint's camera.
 @param symbol to use for the range
 @return An initialized distance symbol range.
 @since 100
 */
+(instancetype)distanceSymbolRangeWithSymbol:(AGSSymbol*)symbol;


/** Initialize a new distance range for the provided symbol with the given distances.
 @param minDistance of the symbol, in meters, from the scene viewpoint's camera at which the symbol becomes visible
 @param maxDistance of the symbol, in meters, from the scene viewpoint's camera until which the symbol remains visible
 @param symbol to use for the range
 @return An initialized distance symbol range.
 @since 100
 */
+(instancetype)distanceSymbolRangeWithSymbol:(AGSSymbol*)symbol
                                 minDistance:(double)minDistance
                                 maxDistance:(double)maxDistance;

#pragma mark -
#pragma mark properties

/** The maximum distance, in meters, from the scene viewpoint's camera at which the `#symbol` should be visible.
 A value of 0 implies there is no maximum for this range and the symbol will always be displayed at distances greater than the minimum cutoff.
 @since 100
 */
@property (nonatomic, assign, readwrite) double maxDistance;

/** The minimum distance, in meters, from the scene viewpoint's camera at which the `#symbol` should be visible.
 A value of 0 implies there is no minimum for this range and the symbol will always be displayed at distances lesser than the maximum cutoff.
 @since 100
 */
@property (nonatomic, assign, readwrite) double minDistance;

/** The symbol for this distance range
 @since 100
 */
@property (nonatomic, strong, readwrite) AGSSymbol *symbol;

#pragma mark -
#pragma mark methods

NS_ASSUME_NONNULL_END

@end
