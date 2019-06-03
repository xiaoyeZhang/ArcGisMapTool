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

@class AGSGeoprocessingParameter;

/** @file AGSGeoprocessingParameterInfo.h */ //Required for Globals API doc

/** @brief Information about an input/output Geoprocessing Task parameter
 
 Instances of this class represent information about a parameter of a Geoprocessing Task such as its name, type, whether or not it is optional (for input parameters), and whether it is an input or output parameter.
 
 @since 100.1
 */
@interface AGSGeoprocessingParameterInfo : AGSObject

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

/** Category of the parameter
@since 100.1
*/
@property (nonatomic, copy, readonly) NSString *category;

/** Permissible values for the parameter
 @since 100.1
 */
@property (nonatomic, copy, readonly) NSArray<NSString*> *choiceList;

/** Data type of the parameter
 @since 100.1
 */
@property (nonatomic, assign, readonly) AGSGeoprocessingParameterType dataType;

/** Default value of the parameter
 @since 100.1
 */
@property (nullable, nonatomic, strong, readonly) AGSGeoprocessingParameter *defaultParameter;

/** Description of the parameter
 @since 100.1
 */
@property (nonatomic, copy, readonly) NSString *parameterDescription;

/** Indicates whether the parameter is input (needed to execute the task) or output (generated when the task finishes)
 @since 100.1
 */
@property (nonatomic, assign, readonly) AGSGeoprocessingParameterDirection direction;

/** User-friendly name of the parameter
 @since 100.1
 */
@property (nonatomic, copy, readonly) NSString *displayName;

/** When the parameter represents features, this property indicates whether the features require a geometry or not.
 @since 100.1
 */
@property (nonatomic, assign, readonly) BOOL featuresRequireGeometry;

/** Indicates whether the parameter is mandatory or not
 @since 100.1
 */
@property (nonatomic, assign, readonly, getter=isRequired) BOOL required;

/** When the parameter is a multivalue parameter, this property indicates the data type of the values. If the parameter is not a multivalue parameter, this property will be `AGSGeoprocessingParameterTypeUnknown`
 @since 100.1
 */
@property (nonatomic, assign, readonly) AGSGeoprocessingParameterType multiValueDataType;

/** Name of the parameter
 @since 100.1
 */
@property (nonatomic, copy, readonly) NSString *name;

#pragma mark -
#pragma mark methods

@end

NS_ASSUME_NONNULL_END
