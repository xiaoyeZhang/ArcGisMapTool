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

NS_ASSUME_NONNULL_BEGIN

/** @file AGSJSONSerializable.h */ //Required for Globals API doc

/** @brief A protocol to convert objects to and from JSON.
 
 This protocol must be adopted by all classes which wish to allow decoding/encoding
 from/to JSON.
 @define{AGSJSONSerializable.h, ArcGIS}
 @since 100
 */
@protocol AGSJSONSerializable <NSObject>

@required

/** Initializes and returns an object from its JSON representation.
 @param JSONObject `NSDictionary` or `NSArray` containing the JSON.
 @param error encountered during the operation, if any.
 @since 100
 */
+(__nullable id<AGSJSONSerializable>)fromJSON:(id)JSONObject error:(NSError**)error;

/**
 Returns JSON representation for this object.
 @param error encountered during the operation, if any.
 @return `NSDictionary` or `NSArray` containing the JSON.
 @since 100
 */
-(__nullable id)toJSON:(NSError**)error;

/** A dictionary of values that was in the source JSON but was unparsed by API.
 @return `NSDictionary` containing the unknown JSON.
 @since 100
 */
@property (nullable, nonatomic, copy, readonly) NSDictionary<NSString*,id> *unknownJSON;

/** A dictionary of values that are supported by the REST API, but not exposed through the SDK API.
 @return `NSDictionary` containing the unsupported JSON.
 @since 100
 */
@property (nullable, nonatomic, copy, readonly) NSDictionary<NSString*,id> *unsupportedJSON;

@end

NS_ASSUME_NONNULL_END
