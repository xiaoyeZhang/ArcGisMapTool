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

@class AGSFeature;
@class AGSField;
@class AGSSpatialReference;
@class AGSFeatureEnumerator;

/** @file AGSFeatureSet.h */ //Required for Globals API doc

/** @brief An abstract representation of a set of features
 
 This protocol represents an abstract set of features with information about the attribute schema of the contained features, their geometry type, and spatial reference of their geometry. Conforming classes provide concrete implementations such as `AGSFeatureQueryResult` that represents the set of features returned as the results of a query operations, `AGSGeoprocessingFeatureSet` that reprsents features that are input or result of geoprocessing jobs, etc.
 
 
 @since 100
 */
@protocol AGSFeatureSet <NSObject>

NS_ASSUME_NONNULL_BEGIN

@required

#pragma mark -
#pragma mark properties

/** The attribute fields (columns) available in data. The property is an
 array of @c AGSField objects.
 @since 100
 */
@property (nonatomic, copy, readonly) NSArray<AGSField*> *fields;

/** The type of geometry contained by features.
 @since 100
 */
@property (nonatomic, assign, readonly) AGSGeometryType geometryType;

/** The spatial reference of the features.
 @since 100
 */
@property (nullable, nonatomic, strong, readonly) AGSSpatialReference *spatialReference;

#pragma mark -
#pragma mark methods

/**
 Returns an enumerator object that lets you access each feature.
 @since 100
 */
-(AGSFeatureEnumerator*)featureEnumerator;

NS_ASSUME_NONNULL_END

@end
