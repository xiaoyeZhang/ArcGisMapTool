/*
 COPYRIGHT 2014 ESRI
 
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
#import "AGSEnumerations.h"

@class AGSPoint;
@class AGSLinearUnit;
@class AGSAngularUnit;
@class AGSGeometry;

/** @file AGSGeodesicEllipseParameters.h */ //Required for Globals API doc

/** @brief Parameters for @c AGSGeometryEngine#geodesicEllipseWithParameters:
 
 This class holds options for the @c AGSGeometryEngine#geodesicEllipseWithParameters: operation.
 
 @define{AGSGeodesicEllipseParameters.h, ArcGIS}
 @since 100
 */
@interface AGSGeodesicEllipseParameters : AGSObject
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

/**Initializes an AGSGeodesicEllipseParameters object.
 @param center The center point of the ellipse.
 @param maxSegmentLength The maximum distance between vertices used to construct the ellipse.
 @param semiAxisLength The length of the semi-major or the semi-minor axis of the ellipse.
 @return A new geodesic ellipse parameter object.
 @since 100
 */
-(instancetype)initWithCenter:(AGSPoint*)center
             maxSegmentLength:(double)maxSegmentLength
               semiAxisLength:(double)semiAxisLength;


/**Initializes an AGSGeodesicEllipseParameters object.
 @param center The center point of the ellipse.
 @param semiAxis1Length The length of the semi-major or semi-minor axis of the ellipse, in units of linearUnit.
 @param semiAxis2Length The length of the semi-major or semi-minor axis of the ellipse, in units of linearUnit.
 @return A new geodesic ellipse parameter object.
 @since 100.1.1
 */
-(instancetype)initWithCenter:(nullable AGSPoint*)center
              semiAxis1Length:(double)semiAxis1Length
              semiAxis2Length:(double)semiAxis2Length;

/**Initializes an AGSGeodesicEllipseParameters object.
 @param axisDirection The direction of the major axis of the ellipse as an angle, in units of angularUnit.
 @param angularUnit The optional angular unit of measure. If null, degrees will be assumed.
 @param center The center point of the ellipse.
 @param linearUnit The optional linear unit of measure. If null, meters will be assumed.
 @param maxPointCount The maximum number of points permitted in the constructed ellipse.
 @param maxSegmentLength The maximum distance between vertices used to construct the ellipse.
 @param geometryType The type of output geometry. Acceptable values are Multipoint, Polyline, and Polygon.
 @param semiAxis1Length The length of the semi-major or semi-minor axis of the ellipse, in units of linearUnit.
 @param semiAxis2Length The length of the semi-major or semi-minor axis of the ellipse, in units of linearUnit.
 @return A new geodesic ellipse parameter object.
 @since 100.4
 */
-(instancetype)initWithAxisDirection:(double)axisDirection
                         angularUnit:(nullable AGSAngularUnit*)angularUnit
                              center:(AGSPoint *)center
                          linearUnit:(nullable AGSLinearUnit*)linearUnit
                       maxPointCount:(NSInteger)maxPointCount
                    maxSegmentLength:(double)maxSegmentLength
                        geometryType:(AGSGeometryType)geometryType
                     semiAxis1Length:(double)semiAxis1Length
                     semiAxis2Length:(double)semiAxis2Length;
    
/**Initializes an AGSGeodesicEllipseParameters object.
 @param center The center AGSPoint of the ellipse.
 @param maxSegmentLength The maximum distance between vertices used to construct the ellipse.
 @param semiAxisLength The length of the semi-major or the semi-minor axis of the ellipse.
 @return A new, autoreleased, geodesic ellipse parameter object.
 @since 100
 */
+(instancetype)parametersWithCenter:(AGSPoint*)center
                   maxSegmentLength:(double)maxSegmentLength
                     semiAxisLength:(double)semiAxisLength;

/**Initializes an AGSGeodesicEllipseParameters object.
 @return A new geodesic ellipse parameter object.
 @since 100
 */
+(instancetype)geodesicEllipseParameters;

/**Initializes an AGSGeodesicEllipseParameters object.
 @param center The center point of the ellipse.
 @param semiAxis1Length The length of the semi-major or semi-minor axis of the ellipse, in units of linearUnit.
 @param semiAxis2Length The length of the semi-major or semi-minor axis of the ellipse, in units of linearUnit.
 @return A new geodesic ellipse parameter object.
 @since 100.1.1
 */
+(instancetype)parametersWithCenter:(nullable AGSPoint*)center
                    semiAxis1Length:(double)semiAxis1Length
                    semiAxis2Length:(double)semiAxis2Length;
    
    
/**Initializes an AGSGeodesicEllipseParameters object.
 @param axisDirection The direction of the major axis of the ellipse as an angle, in units of angularUnit.
 @param angularUnit The optional angular unit of measure. If null, degrees will be assumed.
 @param center The center point of the ellipse.
 @param linearUnit The optional linear unit of measure. If null, meters will be assumed.
 @param maxPointCount The maximum number of points permitted in the constructed ellipse.
 @param maxSegmentLength The maximum distance between vertices used to construct the ellipse.
 @param geometryType The type of output geometry. Acceptable values are Multipoint, Polyline, and Polygon.
 @param semiAxis1Length The length of the semi-major or semi-minor axis of the ellipse, in units of linearUnit.
 @param semiAxis2Length The length of the semi-major or semi-minor axis of the ellipse, in units of linearUnit.
 @return A new geodesic ellipse parameter object.
 @since 100.4
 */
+(instancetype)parametersWithAxisDirection:(double)axisDirection
                               angularUnit:(nullable AGSAngularUnit*)angularUnit
                                    center:(AGSPoint *)center
                                linearUnit:(nullable AGSLinearUnit*)linearUnit
                             maxPointCount:(NSInteger)maxPointCount
                          maxSegmentLength:(double)maxSegmentLength
                              geometryType:(AGSGeometryType)geometryType
                           semiAxis1Length:(double)semiAxis1Length
                           semiAxis2Length:(double)semiAxis2Length;

#pragma mark -
#pragma mark properties

/** The center AGSPoint of the ellipse.
 @since 100
 */
@property (nullable, nonatomic, strong) AGSPoint *center;

/** The length of the semi-major or the semi-minor axis of the ellipse.
 @since 100
 */
@property (nonatomic, assign) double semiAxis1Length;

/** The length of the semi-major or the semi-minor axis of the ellipse. If semiAxis1 = semiAxis2 then a geodesic circle is created.
 @since 100
 */
@property (nonatomic, assign) double semiAxis2Length;

/** The linear units of the lengths maxSegment, semiAxis1 and semiAxis2. The default is AGSLinearUnitIDMeters.
 @since 100
 */
@property (nullable, nonatomic, strong) AGSLinearUnit *linearUnit;

/** The angular unit of the sectorAngle.
 @since 100
 */
@property (nullable, nonatomic, strong) AGSAngularUnit *angularUnit;

/** The direction of the longest axis of the ellipse as an angle (in degrees).
 @since 100
 */
@property (nonatomic, assign) double axisDirection;

/** The maximum distance between vertices used to construct the ellipse.
 @since 100
 */
@property (nonatomic, assign) double maxSegmentLength;

/** The type of output geometry created. Acceptable values are AGSMultipoint, AGSPolyline and AGSPolygon. Defaults to AGSGeometryTypePolgon.
 @since 100
 */
@property (nonatomic, assign) AGSGeometryType geometryType;

/** The maximum number of points permitted in the constructed ellipse.
 @since 100
 */
@property (nonatomic, assign) NSInteger maxPointCount;

NS_ASSUME_NONNULL_END
@end
