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

@class AGSPoint;
@class AGSSpatialReference;

/** @file AGSCoordinateFormatter.h */ //Required for Globals API doc

/** @brief Formatter to convert between coordinates and their string representation
 
 Instances of this class represent a formatter than can convert between coordinates and their string representation in various formats such as decimal degrees; degrees, minutes, and seconds; U.S. National Grid (USNG); and Military Grid Reference System (MGRS).
 
 
 @since 100.1
 */
@interface AGSCoordinateFormatter : AGSObject

NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

#pragma mark -
#pragma mark properties

#pragma mark -
#pragma mark methods

// Strings to Points

/** Returns a point by parsing a coordinate notation string in the Global Area Reference System (GARS) format.

 | GARS notation examples  |
 | ------------------------|
 | 354ND                   |
 | 354ND22                 |
 
 @note The spatial reference provided must have an ellipsoid and datum matching those used by the source of the GARS string. If no spatial reference is provided, it is assumed the GARS string is referenced to WGS 84. The GARS string must not contain any whitespace.
 @param GARSString the coordinate notation string in GARS format
 @param spatialReference in which the point should be returned
 @param conversionMode determining whether the returned point will represent the lower-left (south-west) or center of the GARS cell, quadrant or area.
 @return A point with the location from the GARS string in the spatial reference provided.
 @since 100.1
 */
+(nullable AGSPoint*)pointFromGARSString:(NSString*)GARSString
                        spatialReference:(nullable AGSSpatialReference*)spatialReference
                          conversionMode:(AGSGARSConversionMode)conversionMode;

/** Returns a point by parsing a coordinate notation string in the World Geographic Reference system (GEOREF) format.
 
 | GEOREF notation examples  |
 | --------------------------|
 | MKML5056                  |
 | MKML50285665              |
 
 @note The spatial reference provided must have an ellipsoid and datum matching those used by the source of the GEOREF string. If no spatial reference is provided, it is assumed the GEOREF string is referenced to WGS 84. The GEOREF string may contain leading and trailing whitespace.
 @param GEOREFString the coordinate notation string in GEOREF format
 @param spatialReference in which the point should be returned
 @return A point with the location from the GEOREF string in the spatial reference provided.
 @since 100.1
 */
+(nullable AGSPoint*)pointFromGEOREFString:(NSString*)GEOREFString
                          spatialReference:(nullable AGSSpatialReference*)spatialReference;


/** Returns a point by parsing a coordinate notation string in latitude-longitude format such as decimal degrees, degrees and decimal minutes, or degrees, minutes, and seconds. The latitude-longitude string may contain leading and trailing whitespace, and may also contain a space, comma, or vertical bar symbol to separate the latitude from the longitude. It may also contain the characters 'N', 'S', 'E' and 'W', or use a minus (-) symbol to indicate the hemisphere of each value.
 
 | Latitude-longitude notation examples  |
 | --------------------------------------|
 | 55 56 39.123N 003 09 43.034W          |
 | 55°56′39″N 3°09′43″W                  |
 | 55~56.65205', -003~09.71723'          |
 | 55.9442008* \| -3.1619539*            |
 
 <table>
 <caption>Supported characters</caption>
 <tr><th>Symbol             <th>Character <th>Name                        <th>Unicode number <th>HTML code
 <tr><td rowspan="7">Degree <td>        <td>Asterisk                    <td>U+002A         <td>&#42;
 <tr>                       <td>^         <td>Circumflex Accent           <td>U+005E         <td>&#94;
 <tr>                       <td>~         <td>Tilde                       <td>U+007E         <td>&#126;
 <tr>                       <td>°         <td>Degree Sign                 <td>U+00B0         <td>&#176;
 <tr>                       <td>º         <td>Masculine Ordinal Indicator <td>U+00BA         <td>&#186;
 <tr>                       <td>˚         <td>Ring Above                  <td>U+02DA         <td>&#730;
 <tr>                       <td>⁰         <td>Superscript Zero            <td>U+2070         <td>&#8304;
 <tr><td rowspan="3">Minute <td>'         <td>Apostrophe                  <td>U+0027         <td>&#39;
 <tr>                       <td>’         <td>Right Single Quotation Mark <td>U+2019         <td>&#8127;
 <tr>                       <td>′         <td>Prime                       <td>U+2032         <td>&#8242;
 <tr><td rowspan="4">Second <td>"         <td>Quotation Mark              <td>U+0022         <td>&#34;
 <tr>                       <td>˝         <td>Double Acute Accent         <td>U+02DD         <td>&#733;
 <tr>                       <td>”         <td>Right Double Quotation Mark <td>U+201D         <td>&#8221;
 <tr>                       <td>″         <td>Double Prime                <td>U+2033         <td>&#8243;
 </table>

 @note The spatial reference provided must have an ellipsoid and datum matching those used by the source of the latitude-longitude string. If no spatial reference is provided, it is assumed the latitude-longitude coordinates are referenced to WGS 84.
 @param latLongString the coordinate notation string in latitude-longitude format
 @param spatialReference in which the point should be returned
 @return A point with the location from the latitude-longitude string in the spatial reference provided.
 @since 100.1
 */
+(nullable AGSPoint*)pointFromLatitudeLongitudeString:(NSString*)latLongString
                                     spatialReference:(nullable AGSSpatialReference*)spatialReference;

/** Returns a point by parsing a coordinate notation string in the Military Grid Reference System (MGRS) format.
 
 | MGRS notation examples  |
 | ------------------------|
 | 30UVG898998             |
 | 30UVG 89885 99877       |
 
 @note The spatial reference provided must have an ellipsoid and datum matching those used by the source of the MGRS string. If no spatial reference is provided, it is assumed the MGRS string is referenced to WGS 84. For an explanation of the different modes for interpreting an MGRS notation string, please see `AGSMGRSConversionMode`. Note that the choice between zone 01 and 60 has no impact when reading from an MGRS notation string. The MGRS string can contain leading and trailing whitespace and can have whitespace between the grid zone designator, the 100km square identifier, and the numerical eastings and northings.
 @param MGRSString the coordinate notation string in MGRS format
 @param spatialReference in which the point should be returned
 @param conversionMode determining the lettering scheme and treatment of coordinates at 180 degrees longitude.
 @return A point with the location from the MGRS string in the spatial reference provided.
 @since 100.1
 */
+(nullable AGSPoint*)pointFromMGRSString:(NSString*)MGRSString
                        spatialReference:(nullable AGSSpatialReference*)spatialReference
                          conversionMode:(AGSMGRSConversionMode)conversionMode;

/** Returns a point by parsing a coordinate notation string in the United States National Grid (USNG) format.
 
 | USNG notation examples  |
 | ------------------------|
 | 13TFJ 23 59             |
 | 13TFJ2374159574         |
 
 @note The spatial reference provided must have an ellipsoid and datum matching those used by the source of the USNG string. If no spatial reference is provided and the USNG string is suffixed with "(NAD 27)", it is assumed the USNG string is referenced to NAD 27. If no spatial reference is provided and no such suffix exists, it is assumed the USNG string is referenced to WGS 84. The USNG string can contain leading and trailing whitespace and can have whitespace between the grid zone designator, the 100km square identifier and the numerical eastings and northings.
 @param USNGString the coordinate notation string in USNG format
 @param spatialReference in which the point should be returned
 @return A point with the location from the USNG string in the spatial reference provided.
 @since 100.1
 */
+(nullable AGSPoint*)pointFromUSNGString:(NSString*)USNGString
                        spatialReference:(nullable AGSSpatialReference*)spatialReference;


/** Returns a point by parsing a coordinate notation string in the Universal Transverse Mercator (UTM) format.
 
 | UTM notation examples                     |
 | ------------------------------------------|
 | 30U 489885 6199877                        |
 | 30U4898856199877                          |
 | 30N 489885 6199877 (using N/S indicator)  |
 
 @note The spatial reference provided must have an ellipsoid and datum matching those used by the source of the UTM string. If no spatial reference is provided, it is assumed the UTM string is referenced to WGS 84. The UTM string can contain leading and trailing whitespace and can have whitespace between the zone and latitude designator and the numerical eastings and northings..
 @param UTMString the coordinate notation string in UTM format
 @param spatialReference in which the point should be returned
 @param conversionMode indicating whether the coordinate string contains North or South Hemisphere indicators, or a latitude band identified with letters C through X (omitting I and O).
 @return A point with the location from the UTM string in the spatial reference provided.
 @since 100.1
 */
 +(nullable AGSPoint*)pointFromUTMString:(NSString*)UTMString
                       spatialReference:(nullable AGSSpatialReference*)spatialReference
                         conversionMode:(AGSUTMConversionMode)conversionMode;

// Points to Strings

/** Returns a coordinate notation string in Global Area Reference System (GARS) format representing the given point's location.
 @param point to be represented in GARS notation. The point must have a spatial reference.
 @return A GARS notation string representing the GARS cell containing the given point.
 @since 100.1
 */
+(nullable NSString*)GARSStringFromPoint:(AGSPoint*)point;


/** Returns a coordinate notation string in World Geographic Reference system (GEOREF) format representing the given point's location.
 The precision value controls the number of digits used to represent the fractional part of coordinate's latitude and longitude, expressed in minutes. For example:
 Precision | Example output         | Angular precision | Approx precision*
 --------- | ---------------------- | ----------------- | -----------------
 0         | MKML5056               | 1min              | 2km
 1         | MKML5056               | 1min              | 2km
 2         | MKML5056               | 1min              | 2km
 3         | MKML502566             | 0.1min            | 200m
 4         | MKML50285665           | 0.01min           | 20m
 5         | MKML5028256652         | 0.001min          | 2m
 
 \*At the equator to 1 significant figure.
 
 @param point to be represented in GEOREF notation. The point must have a spatial reference.
 @param precision with which to represent the coordinate. Should be a value 0-9.
 @return A GEOREF notation string representing the position of the given point.
 @since 100.1
 */
+(nullable NSString*)GEOREFStringFromPoint:(AGSPoint*)point
                                 precision:(NSInteger)precision;

/** Returns a coordinate notation string in latitude-longitude format representing the given point's location.
 The latitude-longitude string will contain a space separating the latitude from the longitude value, and the characters 'N' or 'S', and 'E' and 'W', to indicate the hemisphere of each value. The string will also contain spaces separating the components (degrees, minutes, seconds) of each value. The precision of the output is controlled by both the `format` and `decimalPlaces` parameters. For example:
 
 DecimalPlaces  | Format                                            | Example output               | Angular precision | Approx precision*
 -------------- | ------------------------------------------------- | ---------------------------- | ----------------- | -----------------
 0              | `AGSLatitudeLongitudeFormatDecimalDegrees`        | 056N 0003W                   | 1deg              | 100km
 1              | `AGSLatitudeLongitudeFormatDecimalDegrees`        | 55.9N 003.2W                 | 0.1deg            | 10km
 2              | `AGSLatitudeLongitudeFormatDecimalDegrees`        | 55.94N 003.16W               | 0.01deg           | 1km
 3              | `AGSLatitudeLongitudeFormatDecimalDegrees`        | 55.944N 003.162W             | 0.001deg          | 100m
 0              | `AGSLatitudeLongitudeFormatDegreesDecimalMinutes` | 55 057N 003 010W             | 1min              | 2km
 1              | `AGSLatitudeLongitudeFormatDegreesDecimalMinutes` | 55 56.7N 003 09.7W           | 0.1min            | 200m
 2              | `AGSLatitudeLongitudeFormatDegreesDecimalMinutes` | 55 56.65N 003 09.72W         | 0.01min           | 20m
 3              | `AGSLatitudeLongitudeFormatDegreesDecimalMinutes` | 55 56.650N 003 09.717W       | 0.001min          | 2m
 0              | `AGSLatitudeLongitudeFormatDegreesMinutesSeconds` | 55 56 039N 003 09 043W       | 1sec              | 30m
 1              | `AGSLatitudeLongitudeFormatDegreesMinutesSeconds` | 55 56 39.1N 003 09 43.0W     | 0.1sec            | 3m
 2              | `AGSLatitudeLongitudeFormatDegreesMinutesSeconds` | 55 56 39.12N 003 09 43.03W   | 0.01sec           | 300mm
 3              | `AGSLatitudeLongitudeFormatDegreesMinutesSeconds` | 55 56 39.123N 003 09 43.034W | 0.001sec          | 30mm
 
 \*At the equator to 1 significant figure.
 
 @param point to be represented in latitude-longitude notation. The point must have a spatial reference.
 @param format The mode to use when formatting the latitude-longitude string.
 @param decimalPlaces The number of decimal places to use. Should be a value 0-16.
 @return A latitude-longitude notation string representing the position of the given point.
 @since 100.1
 */
+(nullable NSString*)LatitudeLongitudeStringFromPoint:(AGSPoint*)point
                                               format:(AGSLatitudeLongitudeFormat)format
                                        decimalPlaces:(NSInteger)decimalPlaces;

/** Returns a coordinate notation string in Military Grid Reference System (MGRS) format representing the given point's location. The precision value controls the number of digits used to represent each numerical easting and northing value within the MGRS string. For example:

 Precision | Add spaces | Example output     | Approx precision
 --------- | ---------- | ------------------ | ----------------
 0         | false      | 30UVG              | 100km
 1         | false      | 30UVG89            | 10km
 2         | false      | 30UVG8999          | 1km
 3         | false      | 30UVG898998        | 100m
 4         | false      | 30UVG89889988      | 10m
 5         | false      | 30UVG8988499881    | 1m
 0         | true       | 30U VG             | 100km
 1         | true       | 30U VG 8 9         | 10km
 2         | true       | 30U VG 89 99       | 1km
 3         | true       | 30U VG 898 998     | 100m
 4         | true       | 30U VG 8988 9988   | 10m
 5         | true       | 30U VG 89884 99881 | 1m

 @param point to be represented in MGRS notation. The point must have a spatial reference.
 @param conversionMode The mode to use for the returned MGRS notation string.
 @param precision The precision with which to represent the coordinate. Should be a value 0-8.
 @param addSpaces If false, the generated string will contain no spaces. If true, a space separates the grid zone designator, the 100km square identifier, and the numerical easting and northing values.
 @return A MGRS notation string representing the position of the given point.
 @since 100.1
 */
+(nullable NSString*)MGRSStringFromPoint:(AGSPoint*)point
                          conversionMode:(AGSMGRSConversionMode)conversionMode
                               precision:(NSInteger)precision
                               addSpaces:(BOOL)addSpaces;

/** Returns a coordinate notation string in United States National Grid (USNG) format representing the given point's location. The precision value controls the number of digits used to represent each numerical easting and northing value within the USNG string. For example:
 Precision | Add spaces | Example output         | Approx precision
 --------- | ---------- | ---------------------- | ----------------
 0         | false      | 13TFJ                  | 100km
 1         | false      | 13TFJ25                | 10km
 2         | false      | 13TFJ2359              | 1km
 3         | false      | 13TFJ237595            | 100m
 4         | false      | 13TFJ23745951          | 10m
 5         | false      | 13TFJ2374359512        | 1m
 0         | true       | 13T FJ                 | 100km
 1         | true       | 13T FJ 2 5             | 10km
 2         | true       | 13T FJ 23 59           | 1km
 3         | true       | 13T FJ 237 595         | 100m
 4         | true       | 13T FJ 2374 5951       | 10m
 5         | true       | 13T FJ 23743 59512     | 1m
 \*4       | false      | 13TFJ23795929 (NAD 27) | 10m
 \*2       | true       | 13T FJ 23 59 (NAD 27)  | 1km
 
 \*When the point's spatial reference is based on NAD 27
 
 @param point to be represented in USNG notation. The point must have a spatial reference.
 @param precision The precision with which to represent the coordinate. Should be a value 0-8.
 @param addSpaces If false, the generated string will contain no spaces. If true, a space separates the grid zone designator, the 100km square identifier, and the numerical easting and northing values.
 @return A USNG notation string representing the position of the given point.
 @since 100.1
 */
+(nullable NSString*)USNGStringFromPoint:(AGSPoint*)point
                               precision:(NSInteger)precision
                               addSpaces:(BOOL)addSpaces;


/** Returns a coordinate notation string in Universal Transverse Mercator (UTM) format representing the given point's location.

 UTM Conversion Mode                          | add_spaces          | Example output
 -------------------------------------------- | ------------------- | -------------------
 `AGSUTMConversionModeLatitudeBandIndicators` | false               | 30U4898846199881
 `AGSUTMConversionModeLatitudeBandIndicators` | true                | 30U 489884 6199881
 `AGSUTMConversionModeNorthSouthIndicators`   | false               | 30N4898846199881
 `AGSUTMConversionModeNorthSouthIndicators`   | true                | 30N 489884 6199881
 
 @param point to be represented in UTM notation. The point must have a spatial reference.
 @param conversionMode The latitude notation scheme to use in the returned UTM notation string, either a latitudinal band, or a hemisphere designator.
 @param addSpaces If false, the generated string will contain no spaces. If true, a space separates the UTM zone and latitude designator, and each numerical easting and northing value
 @return A UTM notation string representing the position of the given point.
 @since 100.1
 */
+(nullable NSString*)UTMStringFromPoint:(AGSPoint*)point
                         conversionMode:(AGSUTMConversionMode)conversionMode
                              addSpaces:(BOOL)addSpaces;

@end

NS_ASSUME_NONNULL_END

