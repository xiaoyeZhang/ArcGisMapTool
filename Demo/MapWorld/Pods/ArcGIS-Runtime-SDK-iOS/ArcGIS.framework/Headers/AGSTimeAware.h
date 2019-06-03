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

@class AGSTimeExtent;
@class AGSTimeValue;

NS_ASSUME_NONNULL_BEGIN

/** @file AGSTimeAware.h */ //Required for Globals API doc

/** @brief A protocol that can be implemented by layers that support time
 
 A protocol that can be implemented by layers that support time. When time is enabled on a layer, data can be filtered/fetched based on a time-range.
 
 @see `AGSGeoView#timeExtent` to set the time-range for which data needs to be displayed
 @since 100.2
 */
@protocol AGSTimeAware

#pragma mark -
#pragma mark properties

/** The full time extent of the layer
 100.2
 */
@property (nullable, nonatomic, strong, readonly) AGSTimeExtent *fullTimeExtent;

/** Indicates whether the layer supports filtering its contents by a time range
 100.2
 */
@property (nonatomic, assign, readonly) BOOL supportsTimeFiltering;

/** Indicates whether the layer must use the time extent defined on the owning `AGSGeoView#timeExtent` and filter its content.
 Only applicable if the layer supports time filtering (see `#supportsTimeFiltering`)
 100.2
 */
@property (nonatomic, assign, readwrite, getter=isTimeFilteringEnabled) BOOL timeFilteringEnabled;

/** A time offset for this layer. This is useful when data from different layers belong to different time periods and must be displayed together. The offset it applied on-the-fly, it does not change the actual data of the layer. The time offset is subtracted from the time extent set on the owning `AGSGeoView#timeExtent` before the extent is used to filter content from the layer.
 100.2
 */
@property (nullable, nonatomic, strong, readwrite) AGSTimeValue *timeOffset;

/** Returns the suggested time slider step size for this time aware layer.
 100.2
 */
@property (nullable, nonatomic, strong, readonly) AGSTimeValue *timeInterval;

#pragma mark -
#pragma mark methods


@end

NS_ASSUME_NONNULL_END
