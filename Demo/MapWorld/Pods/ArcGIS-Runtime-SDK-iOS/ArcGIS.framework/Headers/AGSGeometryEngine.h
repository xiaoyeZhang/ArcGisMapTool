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

@class AGSSpatialReference;
@class AGSGeometry;
@class AGSPolygon;
@class AGSEnvelope;
@class AGSPolyline;
@class AGSPoint;
@class AGSProximityResult;
@class AGSUnit;
@class AGSAreaUnit;
@class AGSLinearUnit;
@class AGSAngularUnit;
@class AGSGeodesicEllipseParameters;
@class AGSGeodeticDistanceResult;
@class AGSMutablePointCollection;
@class AGSGeodesicSectorParameters;
@class AGSMultipart;
@class AGSDatumTransformation;

/** @file AGSGeometryEngine.h */ //Required for Globals API doc

/** @brief An engine to perform geometric operations
 
 This class can perform geometric operations such as spatial relationship tests, reprojections, shape manipulations, and topological query and analysis operations.
 
 The class contains static methods that operate on geometries. The types of operations that can be performed include the following -
 
 @li Create new geometries from others with methods that buffer, clip and join (union) geometries.
 @li Test spatial relationships between geometries such as intersect and contains.
 @li Find the points of nearest distance between geometries.
 @li Reproject geometries.
 @li Calculate area and length.
 @li Convert geometries to and from their JSON representation.
 @li Perform planar and geodesic/geodetic operations.
 
 
 Some operations use geodesic line interpolation rather than planar (Cartesian). Those that use geodesic line interpolation are specified in their descriptions. A geodesic line follows the shortest distance between two points on the Earth's surface when Earth's surface is approximated by a spheroid. When geodesic line interpolation is used, measurements of distance, area and azimuth are accurate with respect to the curved surface of the spheroid.
 
 @see @concept{geometry-operations.htm, Peforming geometric operations}
 @see @sample{759c80ef60bb4ef993737a3d41a8d9f7, Geometry sample}
 @since 100
 */

@interface AGSGeometryEngine : AGSObject
NS_ASSUME_NONNULL_BEGIN

#pragma mark - Geodetic/Geodesic Operators

/** Gets the geodetic area for the AGSGeometry passed in. Will return NAN if the calculation
 results in a linear to angular conversion (for instance, Decimal Degrees to Meters)
 @param geometry The geometry to calculate the area for.
 @param areaUnit The unit at which the area is calculated.
 @param curveType The type of geodetic curve
 @return The calculated geodetic area in the specified unit.
 @since 100
 */
+ (double)geodeticAreaOfGeometry:(AGSGeometry*)geometry areaUnit:(AGSAreaUnit*)areaUnit curveType:(AGSGeodeticCurveType)curveType;

/** Creates a buffer polygon at the specified distance around the given geometry.
 @param geometry The input geometry
 @param distance The distance by which to buffer the geometry
 @param distanceUnit in which the distance is specified
 @param maxDeviation the maximum distance that the generalized buffer geometry can deviate from the original one, specified in the units of `distanceUnit`. Can be NaN for default behavior, or must be a value between 0.001 and 0.5*abs(`distance`)
 @param curveType The type of geodetic curve. `AGSGeodeticCurveTypeShapePreserving` is a good option for most cases.
 @return The geodetically buffered geometry.
 @since 100
 */
+ (nullable AGSPolygon*)geodeticBufferGeometry:(AGSGeometry*)geometry distance:(double)distance distanceUnit:(AGSLinearUnit*)distanceUnit maxDeviation:(double)maxDeviation curveType:(AGSGeodeticCurveType)curveType;

/** Calculates the geodesic buffer of the geometries in a given array.
 @param geometries An NSArray of geometries.
 @param distances The distance to buffer each geometry, expressed as NSArray of NSNumbers (doubles). If the size of the distances array is less than the number of geometries, the last distance value is used for the rest of geometries.
 @param distanceUnit The unit of measure for the distance.
 @param maxDeviation The maximum deviation between points.
 @param curveType The curve type to calculate.
 @param unionResults Return a single geometry that buffers all the geometries (YES), or one buffer for each in the given collection (NO).
 @return A collection of polygon geometries that represent a geodesic buffer at the desired distance(s) around the given geometries. If `unionResult` is YES, there will be only a single polygon in the resulting collection. If geometries is empty, returns an empty array. Returns nil on error.
 The geometries must have consistent, non-nil spatial references.
 @since 100.1
 */
+ (nullable NSArray<AGSGeometry*>*)geodeticBufferGeometries:(NSArray<AGSGeometry*>*)geometries distances:(NSArray<NSNumber*>*)distances distanceUnit:(AGSLinearUnit*)distanceUnit maxDeviation:(double)maxDeviation curveType:(AGSGeodeticCurveType)curveType unionResults:(BOOL)unionResults;

/** Densifies the input geometry by plotting points between existing vertices.
 @param geometry The input geometry
 @param maxSegmentLength The maximum distance between points after densification.
 @param lengthUnit The unit that the max segment length parameter is in.
 @param curveType The type of geodetic curve
 @return The geodetically densified geometry.
 @since 100
 */
+ (nullable AGSGeometry*)geodeticDensifyGeometry:(AGSGeometry*)geometry maxSegmentLength:(double)maxSegmentLength lengthUnit:(AGSLinearUnit*)lengthUnit curveType:(AGSGeodeticCurveType)curveType;

/** Returns the geodetic distance between 2 given points and calculates the azimuth at both points for the geodetic curves that connects the points.
 @param point1 The first point
 @param point2 The second point
 @param distanceUnit The linear units of the distance returned in the AGSGeodeticDistanceResult object
 @param azimuthUnit The angular unit of the azimuth returned in the AGSGeodeticDistanceResult object
 @param curveType The type of geodetic curve
 @return The AGSGeodeticDistanceResult object containing the shortest distance between the 2 points along the geodetic curve, and the azimuth at both those points.
 @since 100
 */
+ (nullable AGSGeodeticDistanceResult*)geodeticDistanceBetweenPoint1:(AGSPoint*)point1 point2:(AGSPoint*)point2 distanceUnit:(AGSLinearUnit*)distanceUnit azimuthUnit:(AGSAngularUnit*)azimuthUnit curveType:(AGSGeodeticCurveType)curveType;

/** Constructs a geodesic ellipse that is centered on a specified point and defined by it's 2 axes and the direction of it's longest axis. The ellipse is provided as a AGSPolygon, AGSPolyline or AGSMultipoint geometry.
 @param params Specifies the parameters for constructing the ellipse.
 @return The ellipse is returned in the format specified by the geometryType parameter. The ellipse is generalized according to the vertexCount.
 @since 100
 */
+ (nullable AGSGeometry*)geodesicEllipseWithParameters:(AGSGeodesicEllipseParameters*)params;

/** Gets the geodetic length for the AGSGeometry passed in. The length is calculated  using only the vertices of the polygon and define the lines between the points as geodesic segments independent of the actual shape of the polygon. A geodesic segment is the shortest path between two points on an ellipsoid. Thus, if you have a line that spans the width of the world, with only two vertices, each on the edges of the map, the geodesic length would be zero (shortest distance between the two vertices).
 
 Will return NAN if the calculation
 results in a linear to angular conversion (for instance, Decimal Degrees to Meters)
 @param geometry The geometry to calculate the geodetic length for.
 @param lengthUnit The unit at which the length is calculated.
 @param curveType The type of geodetic curve
 @return The calculated geodetic length in the specified unit.
 @since 100
 @see `#lengthOfGeometry:`
 
 */
+ (double)geodeticLengthOfGeometry:(AGSGeometry*)geometry lengthUnit:(AGSLinearUnit*)lengthUnit curveType:(AGSGeodeticCurveType)curveType;

/** Gets an array of AGSPoint objects that have been moved by geodetic calculation. Each point in the array is moved by the given distance and azimuth.
 @param points An array of points to be moved.
 @param distance The distance by which the points are moved.
 @param distanceUnit The linear units of the distance. The default is AGSSRUnitMeter.
 @param azimuth The azimuth for the points to be moved along.
 @param azimuthUnit The angular unit of the azimuth.
 @param curveType The type of geodetic curve
 @return An array of points moved along a geodetic curve by distance and azimuth.
 @since 100
 */
+ (nullable NSArray<AGSPoint*>*)geodeticMovePoints:(NSArray<AGSPoint*>*)points distance:(double)distance distanceUnit:(AGSLinearUnit*)distanceUnit azimuth:(double)azimuth azimuthUnit:(AGSAngularUnit*)azimuthUnit curveType:(AGSGeodeticCurveType)curveType;

/** Constructs a geodesic sector defined by a geodesic arc and 2 radii. The arc is a portion of an ellipse that is centered on a specified point and is defined by it's 2 axes and the length of it's longest axis. The first radius angle is defined by the startDirection angle and the second radius angle is the sum of the startDirection and the sectorAngle. The sector is constructed as a AGSPolygon, AGSPolyline or AGSMultipoint geometry.
 @param params Specifies the parameters for constructing the sector.
 @return The sector is returned in the format specified by the geometryType and is generalized according to the arcVertexCount and the radiusVertexCount parameters.
 @since 100
 */
+ (nullable AGSGeometry*)geodesicSectorWithParameters:(AGSGeodesicSectorParameters*)params;


#pragma mark - Topological Query Operators

/** Returns YES if geometry1 contains geometry2.
 @since 100
 */
+ (BOOL)geometry:(AGSGeometry*)geometry1 containsGeometry:(AGSGeometry*)geometry2;

/** Returns YES if geometry1 crosses geometry2.
 @since 100
 */
+ (BOOL)geometry:(AGSGeometry*)geometry1 crossesGeometry:(AGSGeometry*)geometry2;

/** Cut the 'geometry' with the 'cutter'. The cutter and geometry's spatial references must match.
 When cutting an @c AGSPolyline, all left cuts will be grouped together in the first @c AGSGeometry, right cuts and coincident cuts are grouped in the second @c AGSGeometry, and each undefined cut, along with any uncut parts, are output as separate @c AGSPolylines.
 When cutting an @c AGSPolygon, all left cuts are grouped in the first @c AGSGeometry, all right cuts are in the second @c AGSGeometry, and each undefined cut, along with any left-over parts after cutting, are output as a separate @c AGSGeometry.
 If there were no cuts the an empty @c NSArray will be returned.
 If the left or right cut does not exist, the returned @c AGSGeometry will be empty for this type of cut. An undefined cut will only be produced if a left cut or right cut was produced, and there was a part left over after cutting or a cut is bounded to the left and right of the cutter.
 If an error occurs, nil is returned.
 
 @param geometry to cut
 @param cutter polyline to cut with
 @since 100
 */
+ (nullable NSArray<AGSGeometry *> *)cutGeometry:(AGSGeometry*)geometry withCutter:(AGSPolyline*)cutter;

/** Returns YES if geometry1 is disjoint to geometry2.
 @since 100
 */
+ (BOOL)geometry:(AGSGeometry*)geometry1 disjointToGeometry:(AGSGeometry*)geometry2;

/** Returns YES if geometry1 is equal to geometry2.
 @since 100
 */
+ (BOOL)geometry:(AGSGeometry*)geometry1 equalsGeometry:(AGSGeometry*)geometry2;

/** Returns YES if geometry1 intersects geometry2.
 @since 100
 */
+ (BOOL)geometry:(AGSGeometry*)geometry1 intersectsGeometry:(AGSGeometry*)geometry2;

/** Returns YES if geometry is topologically simple.
 @since 100
 */
+ (BOOL)geometryIsSimple:(AGSGeometry*)geometry;

/** Returns YES if geometry1 overlaps geometry2.
 It compares two geometries of the same dimension
 and returns TRUE if their intersection results in a geometry different from both but of the same dimension.

 @since 100
 */
+ (BOOL)geometry:(AGSGeometry*)geometry1 overlapsGeometry:(AGSGeometry*)geometry2;

/** Determines if @p geometry1 is related to @p geometry2 by the @p relation specified.
 Example: To test if a polygon 'P' contains a point 'pt' you would pass the following:
 <code>-[AGSGeometryEngine geometry:P relatesToGeometry:pt byRelation:@"T*****FF*"]</code>.
 This checks:
 1. The interiors of both geometries intersect.
 2. The exterior of P does not intersect the interior of pt
 3. The exterior of P does not intersect the boundary of pt.
 
 @param geometry1 The input geometry to be compared.
 @param geometry2 The input geometry in which we are comparing @p geometry1 against.
 @param relation The DE-9IM string to be evaluated. Strings such as <code>"T*****FF*"</code> are accepted.
 @return A boolean indicating if the relation is <code>True</code> or <code>False</code>.
 @since 100
 */
+ (BOOL)geometry:(AGSGeometry*)geometry1 relatesToGeometry:(AGSGeometry*)geometry2 byRelation:(NSString*)relation;

/** Returns YES if geometry1 touches geometry2.
 @since 100
 */
+ (BOOL)geometry:(AGSGeometry*)geometry1 touchesGeometry:(AGSGeometry*)geometry2;

/** Returns YES if geometry1 is completely within geometry2.
 @since 100
 */
+ (BOOL)geometry:(AGSGeometry*)geometry1 withinGeometry:(AGSGeometry*)geometry2;


#pragma mark - Topological Analysis Operators

/** Gets the simple area for the AGSGeometry passed in. This is a planar measurement using 2D Cartesian mathematics to compute the area.
 
 The geometry must be topologically correct
 to get its accurate legth. Geometries returned by ArcGIS Server services are always correct.
 If you construct geometries programmatically or using the sketch layer, or if you modify geometries returned by ArcGIS Server,
 you should simplify them using <code>#simplifyGeometry:</code>
 @param geometry The geometry to calculate the area for.
 @return The computed area in the same units as the geometry's spatial reference unit.
 @since 100
 @see `#geodeticAreaOfGeometry:areaUnit:curveType:`
 */
+ (double)areaOfGeometry:(AGSGeometry*)geometry;

+ (nullable AGSGeometry*)boundaryOfGeometry:(AGSGeometry*)geometry;

/** Creates a buffer polygon at the specified distance around the given geometry.
 @param geometry Specifies the input geometry.
 @param distance The distance (in the unit of the geometry's spatial reference) by which
 to buffer the geometry.
 @return The polygon that represents the buffered area.
 @since 100
 @see @c AGSUnit#convert:fromUnit: and @c AGSUnit#convert:toUnit: to convert values between different units
 */
+ (nullable AGSPolygon*)bufferGeometry:(AGSGeometry*)geometry byDistance:(double)distance;

/** Creates and returns a buffer around the given geometries.

 The geometries must have consistent spatial references.
 @param geometries A collection of geometries.
 @param distances The distance (in the unit of the geometry's spatial reference) to buffer each geometry, expressed as an NSArray of NSNumbers (doubles). If the size of the distances array is less than the number of geometries, the last distance value is used for the rest of geometries.
 @param unionResults Return a single geometry that buffers all the geometries (YES), or one buffer for each in the given collection (NO).
 @return A collection of polygon geometries that represent a buffer at the desired distance(s) around the given geometries. If `unionResult` is true, there will be only a single polygon in the resulting collection. If geometries is empty, returns an empty array. Returns nil on error.
 @since 100.1
 */
+ (nullable NSArray<AGSGeometry*>*)bufferGeometries:(NSArray<AGSGeometry*>*)geometries distances:(NSArray<NSNumber*>*)distances unionResults:(BOOL)unionResults;

/** Constructs the polygon created by clipping geometry by envelope.
 @param geometry The geometry to be clipped by the given envelope.
 @param envelope The envelope in which to use in order to clip geometry.
 @return A geometry that represents the area clipped by envelope.
 @since 100
 */
+ (nullable AGSGeometry*)clipGeometry:(AGSGeometry*)geometry withEnvelope:(AGSEnvelope*)envelope;

/** Returns the combined envelope of the two given geometries.
 
 The given geometries must have consistent spatial references.
 @param geometry1 A geometry object.
 @param geometry2 Another geometry object.
 @return The maximum extents of the two given geometries, or nil on error.
 @since 100.1
 */
+ (nullable AGSEnvelope*)combineExtentsOfGeometry:(AGSGeometry*)geometry1 andGeometry:(AGSGeometry*)geometry2;

/** Returns the combined envelope of geometries in the given array.
 
 The geometries must have consistent spatial references.
 @param geometries An NSArray of geometries.
 @return The maximum extents of the geometries in the collection, or nil on error.
 @since 100.1
 */
+ (nullable AGSEnvelope*)combineExtentsOfGeometries:(NSArray<AGSGeometry*>*)geometries;

/** Returns the minimum bounding geometry that completely encloses the given geometry.
 @param geometry for which convex hull needs to be calculated. Typically either an @c AGSMultipoint, @c AGSPolygon, or @c AGSPolyline.
 @return minimum bounding geometry
 @since 100
 */
+ (nullable AGSGeometry*)convexHullForGeometry:(AGSGeometry*)geometry;

/** Returns the convex hull for the geometries in the given array.
 
 The geometries must have consistent spatial references.
 @param geometries An NSArray of geometries.
 @param mergeInputs Return a single geometry that encloses all the geometries (YES), or one enclosing geometry for each in the collection (NO).
 @return If mergeInputs is YES, returns a single convex hull that encloses all the geometries in the collection as a single geometry in an array. If mergeInputs is NO, returns the minimum bounding geometry that completely encloses each of the geometries in the given collection as an array of geometries. If geometries is empty, returns an empty array. Returns nil on error.
 @since 100.1
 */
+ (nullable NSArray<AGSGeometry*>*)convexHullForGeometries:(NSArray<AGSGeometry*>*)geometries mergeInputs:(BOOL)mergeInputs;

/** Densifies the input geometry by plotting points between existing vertices.
 @param geometry The input geometry
 @param maxSegmentLength The maximum distance between points after densification. This
 distance should be in the same unit as the geometry's spatial reference.
 @return The densified geometry.
 @since 100
 */
+ (nullable AGSGeometry*)densifyGeometry:(AGSGeometry*)geometry maxSegmentLength:(double)maxSegmentLength;

/** Constructs the set-theoretic difference between two geometries.
 @param geometry1 The first geometry.
 @param geometry2 The second geometry. Must be of same type as first geometry.
 @return A geometry that represents the difference of the two input geometries.
 @since 100
 */
+ (nullable AGSGeometry*)differenceOfGeometry1:(AGSGeometry*)geometry1 geometry2:(AGSGeometry*)geometry2;

/** Measures the simple planar distance between two geometries.
 @param geometry1 The first geometry.
 @param geometry2 The second geometry.
 @return The distance between the two input geometries in the same unit as the spatial reference of the
 input geometries.
 @since 100
 */
+ (double)distanceBetweenGeometry1:(AGSGeometry*)geometry1 geometry2:(AGSGeometry*)geometry2;


/** Extends a polyline using a polyline as the extender.

 The output polyline will have the first and last segment of each path extended to the extender if the segments can be interpolated to intersect the extender. 
 In the case that the segments can be extended to multiple segments of the extender, the shortest extension is chosen. 
 Only end points for paths that are not shared by the end points of other paths will be extended. 
 If the polyline cannot be extended by the input extender, then nil will be returned.
 @param polyline The polyline to be extended.
 @param extender The polyline to extend to.
 @param options The flags for the type of extend operation to perform.
 @return The extended polyline. Returns nil on error.
 @since 100.1
 */
+ (nullable AGSPolyline*)extendPolyline:(AGSPolyline*)polyline withPolyline:(AGSPolyline*)extender options:(AGSGeometryExtendOption)options;

/** Generalizes the input geometry by removing vertices based on the Douglas-Poiker algorithm.
 @param geometry The input geometry
 @param maxDeviation the maximum distance that the generalized geometry can deviate from the original one, specified in the units of the input geometry's spatial reference
 @param removeDegenerateParts If YES, degenerate parts of the generalized geometry that are undesired for drawing will be removed.
 @since 100
 */
+ (nullable AGSGeometry*)generalizeGeometry:(AGSGeometry*)geometry maxDeviation:(double)maxDeviation removeDegenerateParts:(BOOL)removeDegenerateParts;

/** Constructs the set-theoretic intersection between two geometries.
 @param geometry1 The first geometry.
 @param geometry2 The second geometry. Must be of same type as first geometry.
 @return A geometry that represents the intersection of the two input geometries.
 @since 100
 */
+ (nullable AGSGeometry*)intersectionOfGeometry1:(AGSGeometry*)geometry1 geometry2:(AGSGeometry*)geometry2;

+ (nullable NSArray*)intersectionsOfGeometry1:(AGSGeometry*)geometry1 geometry2:(AGSGeometry*)geometry2;

/** Gets the length for a specified @c AGSGeometry. This is a planar measurement using 2D Cartesian mathematics to compute the length.
 
 The geometry must be topologically correct
 to get its accurate legth. Geometries returned by ArcGIS Server services are always correct.
 If you construct geometries programmatically or using the sketch layer, or if you modify geometries returned by ArcGIS Server,
 you should simplify them using <code>simplifyGeometry:</code>
 
 @param geometry The geometry to calculate the length for.
 @return The calculated length in the same units as the geometry's spatial reference unit.
 @since 100
 @see `#geodeticLengthOfGeometry:lengthUnit:curveType:`
 */
+ (double)lengthOfGeometry:(AGSGeometry*)geometry;

/** Return a copy of the given geometry with its M values removed.
 @param geometry A geometry.
 @return A copy of the given geometry with its M values removed, or nil on error.
 @since 100.1
 */
+ (AGSGeometry*)geometryByRemovingMFromGeometry:(AGSGeometry*)geometry;


/** Return a copy of the given geometry with its Z ordinate removed.
 @param geometry A geometry.
 @return A copy of the given geometry with its Z ordinate removed, or nil on error.
 @since 100.1
 */
+ (AGSGeometry*)geometryByRemovingZFromGeometry:(AGSGeometry*)geometry;


/** Return a copy of the given geometry with its Z ordinate and M values removed.
 @param geometry A geometry.
 @return A copy of the given geometry with both its Z and M attributes removed, or nil on error.
 @since 100.1
 */
+ (AGSGeometry*)geometryByRemovingZAndMFromGeometry:(AGSGeometry*)geometry;

/** Reshape polygons or polylines with a single path polyline.

 Performs the reshape operation on a polygon or polyline using a single path polyline as the reshaper. The output geometry takes the shape of the Multi_path where it first intersects the reshaper to
 the last intersection. The first and last intersection points of the reshaper are chosen closest to the end points of the reshaper in the case that multiple intersections are found. For polygons, only
 individual paths can be reshaped. However, polylines can be reshaped across paths. If the geometry cannot be reshaped by the input reshaper, then nil will be returned.
 @param geometry The polygon or polyline to be reshaped.
 @param reshaper The single path polyline reshaper
 @return The reshaped polygon or polyline. Returns nil on error.
 @since 100.1
 */
+ (nullable AGSMultipart*)reshapeGeometry:(AGSMultipart*)geometry withPolyline:(AGSPolyline*)reshaper;

/** Return a copy of a geometry with the supplied M value.

 If the given geometry already has M values, they will be replaced within the resulting geometry by the supplied M value. The resulting geometry will have hasM true.
 @param m The M value.
 @param geometry A geometry.
 @return A copy of the given geometry with its M values set to the supplied value, or nil on error.
 @since 100.1
 */
+ (AGSGeometry*)geometryBySettingM:(double)m inGeometry:(AGSGeometry*)geometry;

/** Return a copy of a geometry with the supplied Z ordinate.

 If the given geometry already has Z ordinates, they will be replaced within the resulting geometry by the supplied Z value. The resulting geometry will have hasZ true.
 @param z The Z ordinate.
 @param geometry A geometry.
 @return A copy of the given geometry with its Z ordinates set to the supplied value, or nil on error.
 @since 100.1
 */
+ (AGSGeometry*)geometryBySettingZ:(double)z inGeometry:(AGSGeometry*)geometry;

/** Return a copy of a geometry with the supplied Z and M values.

 If the given geometry already has Z ordinates or M values, they will be replaced in the resulting geometry by the supplied Z and M values. The resulting geometry will have both hasZ and hasM true.
 @param z The Z ordinate.
 @param m The M value.
 @param geometry A geometry.
 @return A copy of the given geometry with its Z and M values set to the supplied values, or nil on error.
 @since 100.1
 */
+ (AGSGeometry*)geometryBySettingZ:(double)z M:(double)m inGeometry:(AGSGeometry*)geometry;

/** Simplifies the given geometry to make it topologically consistent according
 to their geometry type. For instance, it rectifies polygons that may be
 self-intersecting, or contain incorrect ring orientations.
 @param geometry The geometry to be simplified.
 @return The simplified geometry.
 @since 100
 */
+ (nullable AGSGeometry*)simplifyGeometry:(AGSGeometry*)geometry;

/** Constructs the set-theoretic symmetric difference between two geometries.
 @param geometry1 The first geometry.
 @param geometry2 The second geometry of dimension equal
 to or greater than the elements of the first geometry.
 @return A geometry that represents the difference of the two input geometries.
 @since 100
 */
+ (nullable AGSGeometry*)symmetricDifferenceOfGeometry1:(AGSGeometry*)geometry1 geometry2:(AGSGeometry*)geometry2;

/** The union operation constructs the set-theoretic union of the two provided geometries.
 @param geometry1 The first geometry.
 @param geometry2 The second geometry. Must be of same type as first geometry.
 @return The union of both the input geometries.
 @since 100
 */
+ (nullable AGSGeometry*)unionOfGeometry1:(AGSGeometry*)geometry1 geometry2:(AGSGeometry*)geometry2;

/** Calculates the union of an array of geometries

 There must be at least one geometry in the given array.
 The geometries must have consistent spatial references.
 If the array contains geometries of differing dimensionality, returns the union of the subset of geometries with the highest dimensionality. E.g. given a collection of polygons, polylines and points, returns the union of the polygons.

 @param geometries An NSArray of geometries.
 @return The union of all the geometries in the given collection. Returns nil on error.
 @since 100.1
 */
+ (nullable AGSGeometry*)unionGeometries:(NSArray<AGSGeometry*>*)geometries;

#pragma mark - Other

/** Fills the closed gaps between polygons using polygon boundaries and polylines as the boundary for the new polygons.

 The new polygons are created in the closed empty areas bounded by the edges of the existing polygon boundaries and the new boundary polylines.
 The newly created polygons do not overlap any existing polygons or polylines, and the boundary of a new polygon must contain at least one edge from the polylines. 
 Only polygons that intersect the input polylines will participate in the operation, so it makes sense to prefilter the input accordingly.
 The geometries in existingBoundaries must all have an area, i.e. be polygons or envelopes.
 The geometries in newBoundaries must all be polylines.
 The geometries in existingBoundaries and newBoundaries must have consistent spatial references.

 @param existingBoundaries The polygons
 @param newBoundaries The polylines
 @return The new polygons that were created. If either `existingBoundaries` or `newBoundaries` is empty, returns an empty array. Returns nil on error.
 @since 100.1
 */
+ (nullable NSArray<AGSPolygon*>*)autoCompleteForExistingBoundaries:(NSArray<AGSGeometry*>*)existingBoundaries newBoundaries:(NSArray<AGSPolyline*>*)newBoundaries;

/** Calculates an interior point for a specified polygon. This interior
 point can be used by clients to place a label for the polygon.
 @param polygon The polygon to get label points for.
 @return The label point.
 @since 100
 */
+ (nullable AGSPoint*)labelPointForPolygon:(AGSPolygon*)polygon;

/** Folds the geometry into a range of 360 degrees. This may be necessary when wrap around
 is enabled on the map.
 @param geometry The geometry that you want folded.
 @return The folded geometry
 @since 100
 */
+ (nullable AGSGeometry*)normalizeCentralMeridianOfGeometry:(AGSGeometry*)geometry;

/** Creates offset version of the input geometries.
 
 The offset operation creates a geometry that is a constant distance from an input polyline or polygon.
 It is similar to buffering, but produces a one sided result. If offsetDistance > 0, then the offset
 geometry is constructed to the right of the oriented input geometry, otherwise it is constructed to
 the left. For a simple polygon, the orientation of outer rings is clockwise and for inner rings it is counter
 clockwise. So the “right side” of a simple polygon is always its inside.
 The bevelRatio is multiplied by the offset distance and the result determines how far a mitered
 offset intersection can be from the input curve before it is beveled.
 
 @param geometry The geometry to calculate offset for. Point and MultiPoint are not supported.
 @param distance The offset distance for the Geometries.
 @param offsetType The join type of the offset geometry.
 @param bevelRatio The ratio used to produce a bevel join instead of a miter join (used only when joins is Miter)
 @param flattenError The maximum distance of the resulting segments compared to the true circular arc (used only when joins is Round).
 If flattenError is 0, tolerance value is used. Also, the algorithm never produces more than around 180 vetices for each round join.
 @return Returns the result of the offset operation.
 @since 100
 */
+ (nullable AGSGeometry*)offsetGeometry:(AGSGeometry*)geometry distance:(double)distance offsetType:(AGSGeometryOffsetType)offsetType bevelRatio:(double)bevelRatio flattenError:(double)flattenError;

/**  Projects the given geometry into a new spatial reference.
 @param geometry The geometry to be projected.
 @param spatialReference The spatial reference to which geometry need to be
 projected.
 @return The projected geometry
 @since 100
 */
+ (nullable AGSGeometry*)projectGeometry:(AGSGeometry*)geometry toSpatialReference:(AGSSpatialReference*)spatialReference;

+ (nullable AGSGeometry*)projectGeometry:(AGSGeometry *)geometry
                      toSpatialReference:(AGSSpatialReference *)toSpatialReference
                     datumTransformation:(nullable AGSDatumTransformation *)datumTransformation;

/** Finds the nearest coordinate in a specified geometry to a specified point.
 @param geometry The geometry in which the nearest coordinate to a specified point is to be found.
 @param point The point which to find the nearest coordinate to.
 @return The proximity result.
 @since 100
 */
+ (nullable AGSProximityResult*)nearestCoordinateInGeometry:(AGSGeometry*)geometry toPoint:(AGSPoint*)point;

/** Finds the nearest vertex in a specified geometry to a specified point.
 @param geometry The geometry in which the nearest vertex to a specified point is to be found.
 @param point The point which to find the nearest vertex to.
 @return The proximity result.
 @since 100
 */
+ (nullable AGSProximityResult*)nearestVertexInGeometry:(AGSGeometry*)geometry toPoint:(AGSPoint*)point;

/** Returns the point at the given distance along the line. If distance is less than or equal to zero, the point returned is coincident with the start of the line. If distance is greater than or equal to the line's length, the point returned is coincident with the end of the line. If the line has multiple parts, and the distance falls exactly on a boundary between two parts, the returned point will be coincident with either the end of one part or the start of the next–which is undetermined.
 @param polyline A line.
 @param distance The distance along the line of the point to return, in the line's units.
 @return The point result, or nil if an error ocurred.
 @since 100.2
 */
+ (nullable AGSPoint *)pointAlongPolyline:(AGSPolyline *)polyline distance:(double)distance;

NS_ASSUME_NONNULL_END
@end
