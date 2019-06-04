/*
 COPYRIGHT 2011 ESRI

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

/** @file AGSEnumerations.h */

#import "AGSDefines.h"

@class AGSSpatialReference;
@class AGSGeometry;

NS_ASSUME_NONNULL_BEGIN

#pragma mark - Geometry

/** Supported geometry types.
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSGeometryType)  {
    AGSGeometryTypeUnknown = -1,    /*!< Undefined */
    AGSGeometryTypePoint = 1,           /*!< Point */
    AGSGeometryTypeEnvelope = 2,          /*!< Envelope */
    AGSGeometryTypePolyline = 3,        /*!< Polyline */
    AGSGeometryTypePolygon = 4,         /*!< Polygon */
    AGSGeometryTypeMultipoint = 5,      /*!< Multipoint */
};

/** Supported @p offsetHow types.
 Square only applicable with the AGSGeometryEngine
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSGeometryOffsetType) {
    AGSGeometryOffsetTypeMitered = 0,       /*!< Mietered */
    AGSGeometryOffsetTypeBevelled = 1,      /*!< Bevelled  */
    AGSGeometryOffsetTypeRounded = 2,       /*!< Rounded */
    AGSGeometryOffsetTypeSquared = 3       /**  Squared  */
};

/** Dimension classification of the geometry
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSGeometryDimension) {
    AGSGeometryDimensionPoint = 0,          /*!<  */
    AGSGeometryDimensionCurve = 1,          /*!<  */
    AGSGeometryDimensionArea = 2,           /*!<  */
    AGSGeometryDimensionVolume = 3,         /*!<  */
    AGSGeometryDimensionUnknown = -1,       /*!<  */
};

/** Extend geometry options
 @since 100.1
 */
typedef NS_OPTIONS(NSInteger, AGSGeometryExtendOption)
{
    AGSGeometryExtendOptionDefault = 0,                             /*!<  */
    AGSGeometryExtendOptionRelocateEnds = 1 << 0,                   /*!<  */
    AGSGeometryExtendOptionKeepEndAttributes = 1 << 1,              /*!<  */
    AGSGeometryExtendOptionNoEndAttributes = 1 << 2,                /*!<  */
    AGSGeometryExtendOptionDoNotExtendFromStartPoint = 1 << 3,      /*!<  */
    AGSGeometryExtendOptionDoNotExtendFromEndPoint = 1 << 4,        /*!<  */
};

/**
 Types of Geodetic curves.
 @since 100
 @see [About geodetic features](http://resources.arcgis.com/en/help/main/10.1/index.html#/About_geodetic_features/01m70000003q000000/)
 */
typedef NS_ENUM(NSInteger, AGSGeodeticCurveType) {
    AGSGeodeticCurveTypeGeodesic = 0,       /*!< The shortest line between any two points on the Earth's surface on a spheroid (ellipsoid) */
    AGSGeodeticCurveTypeLoxodrome,          /*!< A line of constant bearing, or azimuth.*/
    AGSGeodeticCurveTypeGreatElliptic,      /*!< The line on a spheroid (ellipsoid) defined by the intersection at the surface by a plane that passes through the center of the spheroid and the start and end points of a segment. This is also known as a great circle when a sphere is used */
    AGSGeodeticCurveTypeNormalSection,      /*!<  */
    AGSGeodeticCurveTypeShapePreserving    /*!< Keeps the original shape of the geometry or curve  */
};

/** Indicates the location of a point relative to a GARS cell.
 @since 100.1
 */
typedef NS_ENUM(NSInteger, AGSGARSConversionMode) {
    AGSGARSConversionModeLowerLeft = 0,     /*!< Represents a GARS cell by the coordinate of its south-west corner. */
    AGSGARSConversionModeCenter = 1,        /*!< Represents a GARS cell by the coordinate of its center. */
};

/** Determines the lettering scheme and treatment of coordinates at 180 degrees longitude when converting MGRS coordinates.
 @since 100.1
 */
typedef NS_ENUM(NSInteger, AGSMGRSConversionMode) {
    AGSMGRSConversionModeAutomatic = 0,         /*!< The choice of MGRS lettering scheme is based on the datum and ellipsoid of the spatial reference provided. Spatial references with new datums (e.g. WGS 84) assume new lettering scheme (AA scheme). This is equivalent to `AGSMGRSConversionModeNew180InZone60`. Spatial references with older datums (e.g. Clarke 1866, Bessel 1841, Clarke 1880) assume old lettering scheme (AL scheme). This is equivalent to `AGSMGRSConversionModeOld180InZone60`. When converted, points with longitude of exactly 180deg are placed in zone 60. */
    AGSMGRSConversionModeNew180InZone01 = 1,    /*!< The MGRS notation uses the new lettering scheme (AA scheme) and, when converted, places points with longitude of 180deg in zone 01. */
    AGSMGRSConversionModeNew180InZone60 = 2,    /*!< The MGRS notation uses the new lettering scheme (AA scheme) and, when converted, places points with longitude of 180deg in zone 60.*/
    AGSMGRSConversionModeOld180InZone01 = 3,    /*!< The MGRS notation uses the old lettering scheme (AL scheme) and, when converted, places points with longitude of 180deg in zone 01.*/
    AGSMGRSConversionModeOld180InZone60 = 4,    /*!< The MGRS notation uses the old lettering scheme (AL scheme) and, when converted, places points with longitude of 180deg in zone 60. */
};

/** Determines how latitude is designated in UTM notation.

 Within a single longitudinal zone within the UTM system, two points share the same grid position: one in the northern hemisphere and one in the south. Two schemes are used to resolve this ambiguity. In the first, the point is designated a latitude band, identified with letters C through X (omitting I and O). In the second, in place of the latitude band, a hemisphere indicator (N or S) is used.

 @since 100.1
 */
typedef NS_ENUM(NSInteger, AGSUTMConversionMode) {
    AGSUTMConversionModeLatitudeBandIndicators = 0, /*!<  The letter after the UTM zone number represents a latitudinal band (C through X, omitting I and O).*/
    AGSUTMConversionModeNorthSouthIndicators = 1,   /*!<  The letter after the UTM zone number represents a hemisphere (N or S).*/
};

/** Supported formats for representing latitude-longitude geographical coordinates as a string.
 @since 100.1
 */
typedef NS_ENUM(NSInteger, AGSLatitudeLongitudeFormat) {
    AGSLatitudeLongitudeFormatDecimalDegrees = 0,           /*!< The geographical coordinates are represented in decimal degrees. */
    AGSLatitudeLongitudeFormatDegreesDecimalMinutes = 1,    /*!< The geographical coordinates are represented in degrees and decimal minutes.*/
    AGSLatitudeLongitudeFormatDegreesMinutesSeconds = 2,    /*!< The geographical coordinates are represented in degrees and minutes and decimal seconds. */
};

#pragma mark - Network Request

/** The HTTP method being used by the network request.
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSRequestHTTPMethod) {
    AGSRequestHTTPMethodGet = 0,						/*!< GET */
    AGSRequestHTTPMethodPostFormEncodeParameters = 1,	/*!< POST Form Encoded Params */
    AGSRequestHTTPMethodPostJSON = 2					/*!< POST Json */
};



#pragma mark - Errors

/** Constant representing domain for errors originating from web services.
 @since 100
 */
AGS_EXTERN NSString *const AGSServicesErrorDomain;

/** Constants representing error codes coming from web services. These errors belongs to @c #AGSServicesErrorDomain.
 The values in this enumeration are not comprehensive. You may get error codes belonging to the #AGSServicesErrorDomain 
 that are not in this enumeration.
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSServicesErrorCode) {
    AGSServicesErrorCodeBadRequest = 400,                   /*!< Bad Request */
    AGSServicesErrorCodeUnauthorized = 401,                 /*!< Authorization Required */
    AGSServicesErrorCodeInvalidToken = 498,                 /*!< Invalid Token */
    AGSServicesErrorCodeTokenRequired = 499,                /*!< Token Required */
    AGSServicesErrorCodeUnknownError = 500                  /*!< Unknown Error */
};

/** Constant representing domain for errors originating from ArcGIS Runtime.
 @since 100
 @see `AGSServicesErrorDomain`
 */
AGS_EXTERN NSString *const AGSErrorDomain;

/** Constants representing core error codes. These errors belongs to @c #AGSErrorDomain.
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSErrorCode) {
    AGSErrorCodeUnknown = -1,                                               /*!<  */
    AGSErrorCodeCommonNullPtr = 1,                                          /*!<  */
    AGSErrorCodeCommonInvalidArgument = 2,                                  /*!<  */
    AGSErrorCodeCommonNotImplemented = 3,                                   /*!<  */
    AGSErrorCodeCommonOutOfRange = 4,                                       /*!<  */
    AGSErrorCodeCommonInvalidAccess = 5,                                    /*!<  */
    AGSErrorCodeCommonIllegalState = 6,                                     /*!<  */
    AGSErrorCodeCommonNotFound = 7,                                         /*!<  */
    AGSErrorCodeCommonExists = 8,                                           /*!<  */
    AGSErrorCodeCommonTimeout = 9,                                          /*!<  */
    AGSErrorCodeCommonRegularExpression = 10,                               /*!<  */
    AGSErrorCodeCommonPropertyNotSupported = 11,                            /*!<  */
    AGSErrorCodeCommonNoPermission = 12,                                    /*!<  */
    AGSErrorCodeCommonFile = 13,                                            /*!<  */
    AGSErrorCodeCommonFileNotFound = 14,                                    /*!<  */
    AGSErrorCodeCommonInvalidCall = 15,                                     /*!<  */
    AGSErrorCodeCommonIO = 16,                                              /*!<  */
    AGSErrorCodeCommonUserCanceled = 17,                                    /*!<  */
    AGSErrorCodeCommonInternalError = 18,                                   /*!<  */
    AGSErrorCodeCommonConversionFailed = 19,                                /*!<  */
    AGSErrorCodeCommonNoData = 20,                                          /*!<  */
    AGSErrorCodeCommonInvalidJSON = 21,                                     /*!<  */
    AGSErrorCodeCommonUserDefinedFailure = 22,                              /*!<  */
    AGSErrorCodeCommonObjectAlreadyOwned = 24,                              /*!<  */
    AGSErrorCodeCommonBadXml = 23,                                          /*!<  */
    AGSErrorCodeSqliteError = 1001,                                         /*!<  */
    AGSErrorCodeSqliteInternal = 1002,                                      /*!<  */
    AGSErrorCodeSqlitePerm = 1003,                                          /*!<  */
    AGSErrorCodeSqliteAbort = 1004,                                         /*!<  */
    AGSErrorCodeSqliteBusy = 1005,                                          /*!<  */
    AGSErrorCodeSqliteLocked = 1006,                                        /*!<  */
    AGSErrorCodeSqliteNoMem = 1007,                                         /*!<  */
    AGSErrorCodeSqliteReadonly = 1008,                                      /*!<  */
    AGSErrorCodeSqliteInterrupt = 1009,                                     /*!<  */
    AGSErrorCodeSqliteIOErr = 1010,                                         /*!<  */
    AGSErrorCodeSqliteCorrupt = 1011,                                       /*!<  */
    AGSErrorCodeSqliteNotFound = 1012,                                      /*!<  */
    AGSErrorCodeSqliteFull = 1013,                                          /*!<  */
    AGSErrorCodeSqliteCantOpen = 1014,                                      /*!<  */
    AGSErrorCodeSqliteProtocol = 1015,                                      /*!<  */
    AGSErrorCodeSqliteEmpty = 1016,                                         /*!<  */
    AGSErrorCodeSqliteSchema = 1017,                                        /*!<  */
    AGSErrorCodeSqliteTooBig = 1018,                                        /*!<  */
    AGSErrorCodeSqliteConstraint = 1019,                                    /*!<  */
    AGSErrorCodeSqliteMismatch = 1020,                                      /*!<  */
    AGSErrorCodeSqliteMisuse = 1021,                                        /*!<  */
    AGSErrorCodeSqliteNolfs = 1022,                                         /*!<  */
    AGSErrorCodeSqliteAuth = 1023,                                          /*!<  */
    AGSErrorCodeSqliteFormat = 1024,                                        /*!<  */
    AGSErrorCodeSqliteRange = 1025,                                         /*!<  */
    AGSErrorCodeSqliteNotadb = 1026,                                        /*!<  */
    AGSErrorCodeSqliteNotice = 1027,                                        /*!<  */
    AGSErrorCodeSqliteWarning = 1028,                                       /*!<  */
    AGSErrorCodeSqliteRow = 1029,                                           /*!<  */
    AGSErrorCodeSqliteDone = 1030,                                          /*!<  */
    AGSErrorCodeGeometryUnknownError = 2000,                                /*!<  */
    AGSErrorCodeGeometryCorruptedGeometry = 2001,                           /*!<  */
    AGSErrorCodeGeometryEmptyGeometry = 2002,                               /*!<  */
    AGSErrorCodeGeometryMathSingularity = 2003,                             /*!<  */
    AGSErrorCodeGeometryBufferIsTooSmall = 2004,                            /*!<  */
    AGSErrorCodeGeometryInvalidShapeType = 2005,                            /*!<  */
    AGSErrorCodeGeometryProjectionOutOfSupportedRange = 2006,				/*!<  */
    AGSErrorCodeGeometryNonSimpleGeometry = 2007,                           /*!<  */
    AGSErrorCodeGeometryCannotCalculateGeodesic = 2008,						/*!<  */
    AGSErrorCodeGeometryNotationConversion = 2009,                          /*!<  */
    AGSErrorCodeGeometryMissingGridFile = 2010,                             /*!<  */
    AGSErrorCodeGDBValueOutOfRange = 3001,                                  /*!<  */
    AGSErrorCodeGDBDataTypeMismatch = 3002,                                 /*!<  */
    AGSErrorCodeGDBBadXml = 3003,                                           /*!<  */
    AGSErrorCodeGDBDatabaseAlreadyExists = 3004,                            /*!<  */
    AGSErrorCodeGDBDatabaseDoesNotExist = 3005,                             /*!<  */
    AGSErrorCodeGDBNameLongerThan128Characters = 3006,						/*!<  */
    AGSErrorCodeGDBInvalidShapeType = 3007,                                 /*!<  */
    AGSErrorCodeGDBRasterNotSupported = 3008,                               /*!<  */
    AGSErrorCodeGDBRelationshipClassOneToOne = 3009,						/*!<  */
    AGSErrorCodeGDBItemNotFound = 3010,                                     /*!<  */
    AGSErrorCodeGDBDuplicateCode = 3011,                                    /*!<  */
    AGSErrorCodeGDBMissingCode = 3012,                                      /*!<  */
    AGSErrorCodeGDBWrongItemType = 3013,                                    /*!<  */
    AGSErrorCodeGDBIDFieldNotNullable = 3014,                               /*!<  */
    AGSErrorCodeGDBDefaultValueNotSupported = 3015,                         /*!<  */
    AGSErrorCodeGDBTableNotEditable = 3016,                                 /*!<  */
    AGSErrorCodeGDBFieldNotFound = 3017,                                    /*!<  */
    AGSErrorCodeGDBFieldExists = 3018,                                      /*!<  */
    AGSErrorCodeGDBCannotAlterFieldType = 3019,                             /*!<  */
    AGSErrorCodeGDBCannotAlterFieldWidth = 3020,                            /*!<  */
    AGSErrorCodeGDBCannotAlterFieldToNullable = 3021,						/*!<  */
    AGSErrorCodeGDBCannotAlterFieldToEditable = 3022,						/*!<  */
    AGSErrorCodeGDBCannotAlterFieldToDeletable = 3023,						/*!<  */
    AGSErrorCodeGDBCannotAlterGeometryProperties = 3024,					/*!<  */
    AGSErrorCodeGDBUnnamedTable = 3025,                                     /*!<  */
    AGSErrorCodeGDBInvalidTypeForDomain = 3026,                             /*!<  */
    AGSErrorCodeGDBMinMaxReversed = 3027,                                   /*!<  */
    AGSErrorCodeGDBFieldNotSupportedOnRelationshipClass = 3028,             /*!<  */
    AGSErrorCodeGDBRelationshipClassKey = 3029,                             /*!<  */
    AGSErrorCodeGDBValueIsNull = 3030,                                      /*!<  */
    AGSErrorCodeGDBMultipleSqlStatements = 3031,                            /*!<  */
    AGSErrorCodeGDBNoSqlStatements = 3032,                                  /*!<  */
    AGSErrorCodeGDBGeometryFieldMissing = 3033,                             /*!<  */
    AGSErrorCodeGDBTransactionStarted = 3034,                               /*!<  */
    AGSErrorCodeGDBTransactionNotStarted = 3035,                            /*!<  */
    AGSErrorCodeGDBShapeRequiresZ = 3036,                                   /*!<  */
    AGSErrorCodeGDBShapeRequiresM = 3037,                                   /*!<  */
    AGSErrorCodeGDBShapeNoZ = 3038,                                         /*!<  */
    AGSErrorCodeGDBShapeNoM = 3039,                                         /*!<  */
    AGSErrorCodeGDBShapeWrongType = 3040,                                   /*!<  */
    AGSErrorCodeGDBCannotUpdateFieldType = 3041,                            /*!<  */
    AGSErrorCodeGDBNoRowsAffected = 3042,                                   /*!<  */
    AGSErrorCodeGDBSubtypeInvalid = 3043,                                   /*!<  */
    AGSErrorCodeGDBSubtypeMustBeInteger = 3044,                             /*!<  */
    AGSErrorCodeGDBSubtypesNotEnabled = 3045,                               /*!<  */
    AGSErrorCodeGDBSubtypeExists = 3046,                                    /*!<  */
    AGSErrorCodeGDBDuplicateFieldNotAllowed = 3047,                         /*!<  */
    AGSErrorCodeGDBCannotDeleteField = 3048,                                /*!<  */
    AGSErrorCodeGDBIndexExists = 3049,                                      /*!<  */
    AGSErrorCodeGDBIndexNotFound = 3050,                                    /*!<  */
    AGSErrorCodeGDBCursorNotOnRow = 3051,                                   /*!<  */
    AGSErrorCodeGDBInternalError = 3052,                                    /*!<  */
    AGSErrorCodeGDBCannotWriteGeodatabaseManagedFields = 3053,              /*!<  */
    AGSErrorCodeGDBItemAlreadyExists = 3054,                                /*!<  */
    AGSErrorCodeGDBInvalidSpatialIndexName = 3055,                          /*!<  */
    AGSErrorCodeGDBRequiresSpatialIndex = 3056,                             /*!<  */
    AGSErrorCodeGDBReservedName = 3057,                                     /*!<  */
    AGSErrorCodeGDBCannotUpdateSchemaIfChangeTracking = 3058,				/*!<  */
    AGSErrorCodeGDBInvalidDate = 3059,                                      /*!<  */
    AGSErrorCodeGDBDatabaseDoesNotHaveChanges = 3060,						/*!<  */
    AGSErrorCodeGDBReplicaDoesNotExist = 3061,                              /*!<  */
    AGSErrorCodeGDBStorageTypeNotSupported = 3062,                          /*!<  */
    AGSErrorCodeGDBReplicaModelError = 3063,                                /*!<  */
    AGSErrorCodeGDBReplicaClientGenError = 3064,                            /*!<  */
    AGSErrorCodeGDBReplicaNoUploadToAcknowledge = 3065,						/*!<  */
    AGSErrorCodeGDBLastWriteTimeInTheFuture = 3066,                         /*!<  */
    AGSErrorCodeGDBInvalidArgument = 3067,                                  /*!<  */
    AGSErrorCodeGDBTransportationNetworkCorrupt = 3068,						/*!<  */
    AGSErrorCodeGDBTransportationNetworkFileIO = 3069,						/*!<  */
    AGSErrorCodeGDBFeatureHasPendingEdits = 3070,                           /*!<  */
    AGSErrorCodeGDBChangeTrackingNotEnabled = 3071,                         /*!<  */
    AGSErrorCodeGDBTransportationNetworkFileOpen = 3072,					/*!<  */
    AGSErrorCodeGDBTransportationNetworkUnsupported = 3073,					/*!<  */
    AGSErrorCodeGDBCannotSyncCopy = 3074,                                   /*!<  */
    AGSErrorCodeGDBAccessControlDenied = 3075,                              /*!<  */
    AGSErrorCodeGDBGeometryOutsideReplicaExtent = 3076,                     /*!<  */
    AGSErrorCodeGDBUploadAlreadyInProgress = 3077,                          /*!<  */
    AGSErrorCodeGDBDatabaseClosed = 3078,                                   /*!<  */
    AGSErrorCodeGeocodeUnsupportedFileFormat = 4001,						/*!<  */
    AGSErrorCodeGeocodeUnsupportedSpatialReference = 4002,					/*!<  */
    AGSErrorCodeGeocodeUnsupportedProjectionTransformation = 4003,			/*!<  */
    AGSErrorCodeGeocodeGeocoderCreation = 4004,                             /*!<  */
    AGSErrorCodeGeocodeIntersectionsNotSupported = 4005,					/*!<  */
    AGSErrorCodeGeocodeUninitializedGeocodeTask = 4006,						/*!<  */
    AGSErrorCodeGeocodeInvalidLocatorProperties = 4007,						/*!<  */
    AGSErrorCodeGeocodeRequiredFieldMissing = 4008,                         /*!<  */
    AGSErrorCodeGeocodeCannotReadAddress = 4009,                            /*!<  */
    AGSErrorCodeGeocodeReverseGeocodingNotSupported = 4010,					/*!<  */
    AGSErrorCodeNAInvalidRouteSettings = 5001,                              /*!<  */
    AGSErrorCodeNANoSolution = 5002,                                        /*!<  */
    AGSErrorCodeNATaskCanceled = 5003,                                     /*!<  */
    AGSErrorCodeNAInvalidNetwork = 5004,                                    /*!<  */
    AGSErrorCodeNADirectionsError = 5005,                                   /*!<  */
    AGSErrorCodeNAInsufficientNumberOfStops = 5006,                         /*!<  */
    AGSErrorCodeNAStopUnlocated = 5007,                                     /*!<  */
    AGSErrorCodeNAStopLocatedOnNonTraversableElement = 5008,                /*!<  */
    AGSErrorCodeNAPointBarrierInvalidAddedCostAttributeName = 5009,			/*!<  */
    AGSErrorCodeNALineBarrierInvalidScaledCostAttributeName = 5010,			/*!<  */
    AGSErrorCodeNAPolygonBarrierInvalidScaledCostAttributeName = 5011,		/*!<  */
    AGSErrorCodeNAPolygonBarrierInvalidScaledCostAttributeValue = 5012,     /*!<  */
    AGSErrorCodeNAPolylineBarrierInvalidScaledCostAttributeValue = 5013,    /*!<  */
    AGSErrorCodeNAInvalidImpedanceAttribute = 5014,                         /*!<  */
    AGSErrorCodeNAInvalidRestrictionAttribute = 5015,						/*!<  */
    AGSErrorCodeNAInvalidAccumulateAttribute = 5016,						/*!<  */
    AGSErrorCodeNAInvalidDirectionsTimeAttribute = 5017,					/*!<  */
    AGSErrorCodeNAInvalidDirectionsDistanceAttribute = 5018,				/*!<  */
    AGSErrorCodeNAInvalidAttributeParametersAttributeName = 5019,			/*!<  */
    AGSErrorCodeNAInvalidAttributeParametersParameterName = 5020,			/*!<  */
    AGSErrorCodeNAInvalidAttributeParametersValueType = 5021,				/*!<  */
    AGSErrorCodeNAInvalidAttributeParametersRestrictionUsageValue = 5022,	/*!<  */
    AGSErrorCodeNANetworkHasNoHierarchyAttribute = 5023,					/*!<  */
    AGSErrorCodeNANoPathFoundBetweenStops = 5024,                           /*!<  */
    AGSErrorCodeNAUndefinedInputSpatialReference = 5025,					/*!<  */
    AGSErrorCodeNAUndefinedOutputSpatialReference = 5026,					/*!<  */
    AGSErrorCodeNAInvalidDirectionsStyle = 5027,                            /*!<  */
    AGSErrorCodeNAInvalidDirectionsLanguage = 5028,                         /*!<  */
    AGSErrorCodeNADirectionsTimeAndImpedanceAttributeMismatch = 5029,		/*!<  */
    AGSErrorCodeNAInvalidDirectionsRoadClassAttribute = 5030,				/*!<  */
    AGSErrorCodeNAStopIsUnreachable = 5031,                                 /*!<  */
    AGSErrorCodeNAStopTimeWindowStartsBeforeUnixEpoch = 5032,               /*!<  */
    AGSErrorCodeNAStopTimeWindowIsInverted = 5033,                          /*!<  */
    AGSErrorCodeNAWalkingModeRouteTooLarge = 5034,                          /*!<  */
    AGSErrorCodeNAStopHasNullGeometry = 5035,                               /*!<  */
    AGSErrorCodeNAPointBarrierHasNullGeometry = 5036,                       /*!<  */
    AGSErrorCodeNAPolylineBarrierHasNullGeometry = 5037,                    /*!<  */
    AGSErrorCodeNAPolygonBarrierHasNullGeometry = 5038,                     /*!<  */
    AGSErrorCodeNAUnsupportedSearchWhereClause = 5039,                      /*!<  */
    AGSErrorCodeNAInsufficientNumberOfFacilities = 5040,                    /*!<  */
    AGSErrorCodeNAFacilityHasNullGeometry = 5041,                           /*!<  */
    AGSErrorCodeNAFacilityHasInvalidAddedCostAttributeName = 5042,          /*!<  */
    AGSErrorCodeNAFacilityHasNegativeAddedCostAttribute = 5043,             /*!<  */
    AGSErrorCodeNAFacilityHasInvalidImpedanceCutoff = 5044,                 /*!<  */
    AGSErrorCodeNAInsufficientNumberOfIncidents = 5045,                     /*!<  */
    AGSErrorCodeNAIncidentHasNullGeometry = 5046,                           /*!<  */
    AGSErrorCodeNAIncidentHasInvalidAddedCostAttributeName = 5047,          /*!<  */
    AGSErrorCodeNAIncidentHasNegativeAddedCostAttribute = 5048,             /*!<  */
    AGSErrorCodeNAInvalidTargetFacilityCount = 5049,                        /*!<  */
    AGSErrorCodeNAIncidentHasInvalidImpedanceCutoff = 5050,                 /*!<  */
    AGSErrorCodeNAStartTimeIsBeforeUnixEpoch = 5051,                        /*!<  */
    AGSErrorCodeNAInvalidDefaultImpedanceCutoff = 5052,                     /*!<  */
    AGSErrorCodeNAInvalidDefaultTargetFacilityCount = 5053,                 /*!<  */
    AGSErrorCodeNAInvalidPolygonBufferDistance = 5054,                      /*!<  */
    AGSErrorCodeNAPolylinesCannotBeReturned = 5055,                         /*!<  */
    AGSErrorCodeNATimeWindowsWithNonTimeImpedance = 5056,                   /*!<  */
    AGSErrorCodeNAUnsupportedStopType = 5057,                               /*!<  */
    AGSErrorCodeNARouteStartsOrEndsOnWaypoint = 5058,                       /*!<  */
    AGSErrorCodeNAWaypointsAndRestBreaksForbiddenReordering = 5059,         /*!<  */
    AGSErrorCodeNAWaypointHasTimeWindows = 5060,                            /*!<  */
    AGSErrorCodeNAWaypointHasAddedCostAttribute = 5061,                     /*!<  */
    AGSErrorCodeNAStopHasInvalidCurbApproach = 5062,                        /*!<  */
    AGSErrorCodeNAPointBarrierHasInvalidCurbApproach = 5063,                /*!<  */
    AGSErrorCodeNAFacilityHasInvalidCurbApproach = 5064,                    /*!<  */
    AGSErrorCodeNAIncidentHasInvalidCurbApproach = 5065,                    /*!<  */
    AGSErrorCodeNANetworkDoesNotSupportDirections = 5066,                   /*!<  */
    AGSErrorCodeNADirectionsLanguageNotFound = 5067,                        /*!<  */
    AGSErrorCodeJSONParserInvalidToken = 6001,                              /*!<  */
    AGSErrorCodeJSONParserInvalidCharacter = 6002,                          /*!<  */
    AGSErrorCodeJSONParserInvalidUnicode = 6003,                            /*!<  */
    AGSErrorCodeJSONParserInvalidJSONStart = 6004,                          /*!<  */
    AGSErrorCodeJSONParserInvalidEndOfPair = 6005,                          /*!<  */
    AGSErrorCodeJSONParserInvalidEndOfElement = 6006,                       /*!<  */
    AGSErrorCodeJSONParserInvalidEscapeSequence = 6007,                     /*!<  */
    AGSErrorCodeJSONParserInvalidEndOfFieldName = 6008,                     /*!<  */
    AGSErrorCodeJSONParserInvalidStartOfFieldName = 6009,                   /*!<  */
    AGSErrorCodeJSONParserInvalidStartOfComment = 6010,                     /*!<  */
    AGSErrorCodeJSONParserInvalidDecDigit = 6011,                           /*!<  */
    AGSErrorCodeJSONParserInvalidHexDigit = 6012,                           /*!<  */
    AGSErrorCodeJSONParserExpectingNull = 6013,                             /*!<  */
    AGSErrorCodeJSONParserExpectingTrue = 6014,                             /*!<  */
    AGSErrorCodeJSONParserExpectingFalse = 6015,                            /*!<  */
    AGSErrorCodeJSONParserExpectingClosingQuote = 6016,                     /*!<  */
    AGSErrorCodeJSONParserExpectingNan = 6017,                              /*!<  */
    AGSErrorCodeJSONParserExpectingEndOfComment = 6018,                     /*!<  */
    AGSErrorCodeJSONParserUnexpectedEndOfData = 6019,                       /*!<  */
    AGSErrorCodeJSONObjectExpectingStartObject = 6020,                      /*!<  */
    AGSErrorCodeJSONObjectExpectingStartArray = 6021,                       /*!<  */
    AGSErrorCodeJSONObjectExpectingValueObject = 6022,                      /*!<  */
    AGSErrorCodeJSONObjectExpectingValueArray = 6023,                       /*!<  */
    AGSErrorCodeJSONObjectExpectingValueInt32 = 6024,                       /*!<  */
    AGSErrorCodeJSONObjectExpectingIntegerType = 6025,                      /*!<  */
    AGSErrorCodeJSONObjectExpectingNumberType = 6026,                       /*!<  */
    AGSErrorCodeJSONObjectExpectingValueString = 6027,                      /*!<  */
    AGSErrorCodeJSONObjectExpectingValueBool = 6028,                        /*!<  */
    AGSErrorCodeJSONObjectIteratorNotStarted = 6029,                        /*!<  */
    AGSErrorCodeJSONObjectIteratorIsFinished = 6030,                        /*!<  */
    AGSErrorCodeJSONObjectKeyNotFound = 6031,                               /*!<  */
    AGSErrorCodeJSONObjectIndexOutOfRange = 6032,                           /*!<  */
    AGSErrorCodeJSONStringWriterJSONIsComplete = 6033,                      /*!<  */
    AGSErrorCodeJSONStringWriterInvalidJSONInput = 6034,                    /*!<  */
    AGSErrorCodeJSONStringWriterExpectingContainer = 6035,                  /*!<  */
    AGSErrorCodeJSONStringWriterExpectingKeyOrEndObject = 6036,             /*!<  */
    AGSErrorCodeJSONStringWriterExpectingValueOrEndArray = 6037,            /*!<  */
    AGSErrorCodeJSONStringWriterExpectingValue = 6038,                      /*!<  */
    AGSErrorCodeMappingMissingSpatialReference = 7001,                      /*!<  */
    AGSErrorCodeMappingMissingInitialViewpoint = 7002,                      /*!<  */
    AGSErrorCodeMappingInvalidResponse = 7003,                              /*!<  */
    AGSErrorCodeMappingMissingBingMapsKey = 7004,                           /*!<  */
    AGSErrorCodeMappingUnsupportedLayerType = 7005,                         /*!<  */
    AGSErrorCodeMappingSyncNotEnabled = 7006,                               /*!<  */
    AGSErrorCodeMappingTileExportNotEnabled = 7007,                         /*!<  */
    AGSErrorCodeMappingMissingItemProperty = 7008,                          /*!<  */
    AGSErrorCodeMappingWebmapNotSupported = 7009,                           /*!<  */
    AGSErrorCodeMappingSpatialReferenceInvalid = 7011,                      /*!<  */
    AGSErrorCodeMappingPackageUnpackRequired = 7012,                        /*!<  */
    AGSErrorCodeMappingUnsupportedElevationFormat = 7013,                   /*!<  */
    AGSErrorCodeMappingWebsceneNotSupported = 7014,                         /*!<  */
    AGSErrorCodeLicensingUnlicensedFeature = 8001,                          /*!<  */
    AGSErrorCodeLicensingLicenseLevelFixed = 8002,                          /*!<  */
    AGSErrorCodeLicensingLicenseLevelAlreadySet = 8003,                     /*!<  */
    AGSErrorCodeLicensingMainLicenseNotSet = 8004,                          /*!<  */
    AGSErrorCodeLicensingUnlicensedExtension = 8005,                        /*!<  */
    AGSErrorCodeLocalServerServerFailedToStart = 9001,                      /*!<  */
    AGSErrorCodeLocalServerServiceFailedToStart = 9002,                     /*!<  */
    AGSErrorCodeLocalServerServiceTerminatedUnexpectedly = 9003,            /*!<  */
    AGSErrorCodeLocalServerServerFailed = 9004,                             /*!<  */
    AGSErrorCodeLocalServerServiceFailed = 9005,                            /*!<  */
    AGSErrorCodeStdIosBaseFailure = 10001,                                  /*!<  */
    AGSErrorCodeStdBadArrayNewLength = 10002,                               /*!<  */
    AGSErrorCodeStdUnderflowError = 10003,                                  /*!<  */
    AGSErrorCodeStdSystemError = 10004,                                     /*!<  */
    AGSErrorCodeStdRangeError = 10005,                                      /*!<  */
    AGSErrorCodeStdOverflowError = 10006,                                   /*!<  */
    AGSErrorCodeStdOutOfRange = 10007,                                      /*!<  */
    AGSErrorCodeStdLengthError = 10008,                                     /*!<  */
    AGSErrorCodeStdInvalidArgument = 10009,                                 /*!<  */
    AGSErrorCodeStdFutureError = 10010,                                     /*!<  */
    AGSErrorCodeStdDomainError = 10011,                                     /*!<  */
    AGSErrorCodeStdRuntimeError = 10012,                                    /*!<  */
    AGSErrorCodeStdLogicError = 10013,                                      /*!<  */
    AGSErrorCodeStdBadWeakPtr = 10014,                                      /*!<  */
    AGSErrorCodeStdBadTypeId = 10015,                                       /*!<  */
    AGSErrorCodeStdBadFunctionCall = 10016,                                 /*!<  */
    AGSErrorCodeStdBadException = 10017,                                    /*!<  */
    AGSErrorCodeStdBadCast = 10018,                                         /*!<  */
    AGSErrorCodeStdBadAlloc = 10019,                                        /*!<  */
    AGSErrorCodeStdException = 10020,                                       /*!<  */
};

/** Constant representing domain for popup validation errors.
 @since 100
 */
AGS_EXTERN NSString *const AGSPopupValidationErrorDomain;

/** Constants representing popup validation error codes. These errors belongs to @c #AGSPopupValidationErrorDomain.
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSPopupValidationErrorCode) {
    AGSPopupValidationErrorCodeInvalidGeoElement = 11000,          /*!< Invalid attributes or geometry on the associated AGSGeoElement */
    AGSPopupValidationErrorCodeNullNotAllowed = 11001,          /*!< Null value not allowed */
    AGSPopupValidationErrorCodeValueOutOfRange = 11002,         /*!< Value out of range domain. */
    AGSPopupValidationErrorExceedsMaxLength = 11003,             /*!< Value exceeds maximum field length */
    AGSPopupValidationErrorInvalidNumericString = 11004,             /*!< String input could not be parsed into the numeric value required by the field */
    AGSPopupValidationErrorExceedsNumericMaximum = 11005,             /*!< Numeric field value greater than the field type allows */
    AGSPopupValidationErrorLessThanNumericMinimum = 11006             /*!< Numeric field value less than the field type allows */
};

/** The edit state of attachments in an AGSPopupAttachmentManager.
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSPopupAttachmentEditState) {
    AGSPopupAttachmentEditStateOriginal = 0,    /*!<  */
    AGSPopupAttachmentEditStateAdded,           /*!<  */
    AGSPopupAttachmentEditStateDeleted,         /*!<  */
};

/** The type of attachments in an AGSPopupAttachmentManager.
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSPopupAttachmentType) {
    AGSPopupAttachmentTypeImage = 0,/*!< Any attachment whose MIME type contains 'image' prefix */
    AGSPopupAttachmentTypeVideo,    /*!< Any attachment whose MIME type contains 'video' prefix */
    AGSPopupAttachmentTypeDocument, /*!< PDF, MS-Word, MS-Excel, MS-Powerpoint, HTML */
    AGSPopupAttachmentTypeOther     /*!< */
};

/** Size options for an image attachment
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSPopupAttachmentSize) {
    AGSPopupAttachmentSizeActual = 0,        /*!<  full resolution */
    AGSPopupAttachmentSizeSmall,             /*!<  240x320 */
    AGSPopupAttachmentSizeMedium,            /*!<  480x640 */
    AGSPopupAttachmentSizeLarge,             /*!<  960x1280 */
    AGSPopupAttachmentSizeExtraLarge,        /*!<  1126x1500 */
};

typedef NS_ENUM(NSInteger, AGSPopupExpressionReturnType) {
    AGSPopupExpressionReturnTypeString = 0,
    AGSPopupExpressionReturnTypeNumber = 1
};

#pragma mark - Portal

/** The type of content represented by the local item
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSLocalItemType) {
    AGSLocalItemTypeUnknown = -1,           /*!<  */
    AGSLocalItemTypeMobileMap = 0,          /*!<  */
    AGSLocalItemTypeMobileScene = 1,        /*!<  */
    AGSLocalItemTypeMobileMapPackage = 2    /*!<  */
};


/** The type of content represented by the portal item
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSPortalItemType) {
    AGSPortalItemTypeUnknown = -1,                                      /*!<  */
    AGSPortalItemTypeArcGISProAddIn = 0,                                /*!<  */
    AGSPortalItemTypeArcPadPackage = 1,					                /*!<  */
    AGSPortalItemTypeCADDrawing = 2,                                    /*!<  */
    AGSPortalItemTypeCSV = 3,							                /*!<  */
    AGSPortalItemTypeCityEngineWebScene = 4,			                /*!<  */
    AGSPortalItemTypeCodeAttachment = 5,				                /*!<  */
    AGSPortalItemTypeCodeSample = 6,					                /*!<  */
    AGSPortalItemTypeColorSet = 7,						                /*!<  */
    AGSPortalItemTypeDesktopAddIn = 8,					                /*!<  */
    AGSPortalItemTypeDesktopApplication = 9,                            /*!<  */
    AGSPortalItemTypeDesktopApplicationTemplate = 10,	                /*!<  */
    AGSPortalItemTypeDesktopStyle = 11,                                 /*!<  */
    AGSPortalItemTypeDocumentLink = 12,					                /*!<  */
    AGSPortalItemTypeExplorerAddIn = 13,				                /*!<  */
    AGSPortalItemTypeExplorerLayer = 14,				                /*!<  */
    AGSPortalItemTypeExplorerMap = 15,					                /*!<  */
    AGSPortalItemTypeFeatureCollection = 16,			                /*!<  */
    AGSPortalItemTypeFeatureCollectionTemplate = 17,	                /*!<  */
    AGSPortalItemTypeFeatureService = 18,				                /*!<  */
    AGSPortalItemTypeFileGeodatabase = 19,                              /*!<  */
    AGSPortalItemTypeForm = 20,                                         /*!<  */
    AGSPortalItemTypeGeocodingService = 21,				                /*!<  */
    AGSPortalItemTypeGeodataService = 22,				                /*!<  */
    AGSPortalItemTypeGeometryService = 23,				                /*!<  */
    AGSPortalItemTypeGeoprocessingPackage = 24,			                /*!<  */
    AGSPortalItemTypeGeoprocessingPackageProVersion = 25,               /*!<  */
    AGSPortalItemTypeGeoprocessingSample = 26,			                /*!<  */
    AGSPortalItemTypeGeoprocessingService = 27,			                /*!<  */
    AGSPortalItemTypeGlobeDocument = 28,				                /*!<  */
    AGSPortalItemTypeGlobeService = 29,					                /*!<  */
    AGSPortalItemTypeImage = 30,						                /*!<  */
    AGSPortalItemTypeImageCollection = 31,                              /*!<  */
    AGSPortalItemTypeImageService = 32,					                /*!<  */
    AGSPortalItemTypeInsightsModel = 33,                                /*!<  */
    AGSPortalItemTypeInsightsPage = 34,                                 /*!<  */
    AGSPortalItemTypeInsightsWorkbook = 35,                             /*!<  */
    AGSPortalItemTypeiWorkKeynote NS_SWIFT_NAME(iWorkKeynote) = 36,     /*!<  */
    AGSPortalItemTypeiWorkNumbers NS_SWIFT_NAME(iWorkNumbers) = 37,     /*!<  */
    AGSPortalItemTypeiWorkPages NS_SWIFT_NAME(iWorkPages) = 38,         /*!<  */
    AGSPortalItemTypeIWorkKeynote __deprecated_enum_msg("Please use AGSPortalItemTypeiWorkKeynote. Available at 100.3") = AGSPortalItemTypeiWorkKeynote,   /*!<  */
    AGSPortalItemTypeIWorkNumbers __deprecated_enum_msg("Please use AGSPortalItemTypeiWorkNumbers. Available at 100.3") = AGSPortalItemTypeiWorkNumbers,   /*!<  */
    AGSPortalItemTypeIWorkPages __deprecated_enum_msg("Please use AGSPortalItemTypeiWorkPages. Available at 100.3") = AGSPortalItemTypeiWorkPages,         /*!<  */
    AGSPortalItemTypeKML = 39,							                /*!<  */
    AGSPortalItemTypeKMLCollection = 40,                                /*!<  */
    AGSPortalItemTypeLayer = 41,						                /*!<  */
    AGSPortalItemTypeLayerPackage = 42,					                /*!<  */
    AGSPortalItemTypeLayout = 43,                                       /*!<  */
    AGSPortalItemTypeLocatorPackage = 44,				                /*!<  */
    AGSPortalItemTypeMapDocument = 45,					                /*!<  */
    AGSPortalItemTypeMapPackage = 46,					                /*!<  */
    AGSPortalItemTypeMapService = 47,					                /*!<  */
    AGSPortalItemTypeMapTemplate = 48,					                /*!<  */
    AGSPortalItemTypeMicrosoftExcel = 49,				                /*!<  */
    AGSPortalItemTypeMicrosoftPowerpoint = 50,                          /*!<  */
    AGSPortalItemTypeMicrosoftWord = 51,				                /*!<  */
    AGSPortalItemTypeMobileApplication = 52,			                /*!<  */
    AGSPortalItemTypeMobileBasemapPackage = 53,                         /*!<  */
    AGSPortalItemTypeMobileMapPackage = 54,				                /*!<  */
    AGSPortalItemTypeNativeApplication = 55,                            /*!<  */
    AGSPortalItemTypeNativeApplicationInstaller = 56,                   /*!<  */
    AGSPortalItemTypeNativeApplicationTemplate = 57,                    /*!<  */
    AGSPortalItemTypeNetCDF = 58,                                       /*!<  */
    AGSPortalItemTypeNetworkAnalysisService = 59,		                /*!<  */
    AGSPortalItemTypeOperationView = 60,				                /*!<  */
    AGSPortalItemTypeOperationsDashboardAddIn = 61,		                /*!<  */
    AGSPortalItemTypeOperationsDashboardExtension = 62,                 /*!<  */
    AGSPortalItemTypePDF = 63,							                /*!<  */
    AGSPortalItemTypeProjectPackage = 64,                               /*!<  */
    AGSPortalItemTypeProjectTemplate = 65,                              /*!<  */
    AGSPortalItemTypeProMap = 66,                                       /*!<  */
    AGSPortalItemTypePublishedMap = 67,					                /*!<  */
    AGSPortalItemTypeRasterFunctionTemplate = 68,                       /*!<  */
    AGSPortalItemTypeRelationalDatabaseConnection = 69,                 /*!<  */
    AGSPortalItemTypeReportTemplate = 70,                               /*!<  */
    AGSPortalItemTypeRulePackage = 71,                                  /*!<  */
    AGSPortalItemTypeSceneDocument = 72,				                /*!<  */
    AGSPortalItemTypeScenePackage = 73,                                 /*!<  */
    AGSPortalItemTypeSceneService = 74,                                 /*!<  */
    AGSPortalItemTypeServiceDefinition = 75,			                /*!<  */
    AGSPortalItemTypeShapeFile = 76,					                /*!<  */
    AGSPortalItemTypeStatisticalDataCollection = 77,                    /*!<  */
    AGSPortalItemTypeSymbolSet = 78,					                /*!<  */
    AGSPortalItemTypeTaskFile = 79,                                     /*!<  */
    AGSPortalItemTypeTilePackage = 80,					                /*!<  */
    AGSPortalItemTypeVectorTilePackage = 81,			                /*!<  */
    AGSPortalItemTypeVectorTileService = 82,			                /*!<  */
    AGSPortalItemTypeVisioDocument = 83,				                /*!<  */
    AGSPortalItemTypeVr360Experience = 84,                              /*!<  */
    AGSPortalItemTypeWFS = 85,                                          /*!<  */
    AGSPortalItemTypeWMS = 86,							                /*!<  */
    AGSPortalItemTypeWMTS = 87,							                /*!<  */
    AGSPortalItemTypeWebMap = 88,						                /*!<  */
    AGSPortalItemTypeWebMappingApplication = 89,		                /*!<  */
    AGSPortalItemTypeWebScene = 90,                                     /*!<  */
    AGSPortalItemTypeWindowsMobilePackage = 91,			                /*!<  */
    AGSPortalItemTypeWorkflowManagerPackage = 92,		                /*!<  */
    AGSPortalItemTypeWorkflowManagerService = 93,                       /*!<  */
    AGSPortalItemTypeWorkforceProject = 94,				                /*!<  */
    AGSPortalItemTypeSQLiteGeodatabase = 95,                            /*!<  */
    AGSPortalItemTypeMapArea = 96,                                      /*!<  */
    AGSPortalItemTypeHubInitiative = 97,                                /*!<  */
    AGSPortalItemTypeHubSiteApplication = 98,                           /*!<  */
    AGSPortalItemTypeHubPage = 99,                                      /*!<  */
    AGSPortalItemTypeAppBuilderExtension = 100,                         /*!<  */
    AGSPortalItemTypeAppBuilderWidgetPackage = 101,                     /*!<  */
    AGSPortalItemTypeDashboard = 102,                                   /*!<  */
    AGSPortalItemTypeArcGISProConfiguration = 103                       /*!<  */
};



/** Access types on Portal, Item, Group or User.

 <b> For Portal or Organization </b>

 Determines who can view your organization as an anonymous user. <code>AGSPortalAccessPublic</code>
 means it allows anonymous users to access your organization's custom URL. <code>AGSPortalAccessPrivate </code> restricts access to only members of your organization.

 <b> For Portal Item </b>

 Indicates the access level of the item. If <code>AGSPortalAccessPrivate</code>, only the item owner can
 access. <code>AGSPortalAccessShared</code> allows the item to be shared with a specific group. <code>
 AGSPortalAccessOrganization</code> restricts item access to members of your organization. If <code>
 AGSPortalAccessPublic</code>, all users can access the item.

 <b> For Portal Group </b>

 Determines who can access the group. <code>AGSPortalAccessPrivate</code> gives access to only the group
 members. If <code>AGSPortalAccessOrganization</code>, all members of this organization can access the
 group. <code>AGSPortalAccessPublic</code> makes the group accessible to all.

 <b> For Portal User </b>

 Determines if other users can search for this user's name to find content and groups owned by this user
 and to invite this user to join their groups. <code>AGSPortalAccessPrivate</code> hides the user from
 user searches and invites. If <code>AGSPortalAccessOrganization</code>, only members of this user's
 organization can search for this user, the content and groups. <code>AGSPortalAccessPublic</code> makes
 the user findable.

 @since 100
 */
typedef NS_ENUM(NSInteger, AGSPortalAccess) {
    AGSPortalAccessUnknown = -1,
    AGSPortalAccessOrganization = 0,                    /*!< Applicable for Items, Groups and Users  */
    AGSPortalAccessPrivate = 1,                     /*!< Applicable for All  */
    AGSPortalAccessPublic = 2,                           /*!< Applicable for All  */
    AGSPortalAccessShared = 3                          /*!< Applicable for only Items  */
};

/** Indicates the order of results of the portal query.
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSPortalQuerySortOrder){
    AGSPortalQuerySortOrderAscending = 0,   	/*!< Ascending */
    AGSPortalQuerySortOrderDescending,			/*!< Descending */
} ;


/** Indicating whether the portal contains multiple organizations or not.
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSPortalMode) {
    AGSPortalModeSingleTenant = 0,   	/*!< Only one organization*/
    AGSPortalModeMultiTenant,			/*!< Multiple organizations*/
} ;

/** Indicates the role of the portal user within an organization.
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSPortalUserRole) {
    AGSPortalUserRoleUnknown = 0,           /*!< The user does not belong to an organization */
    AGSPortalUserRoleUser,                  /*!< Information worker */
    AGSPortalUserRolePublisher,             /*!< Publisher */
    AGSPortalUserRoleAdmin,                 /*!< Administrator */
} ;

/** Indicates the desired sorting criterion for group items.
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSPortalGroupSortField) {
    AGSPortalGroupSortFieldUnknown = 0,
    AGSPortalGroupSortFieldTitle,           /*!< Title */
    AGSPortalGroupSortFieldOwner,           /*!< Ownder */
    AGSPortalGroupSortFieldAvgRating,       /*!< Average Rating */
    AGSPortalGroupSortFieldNumViews,        /*!< Number of Views */
    AGSPortalGroupSortFieldCreated,         /*!< Created Date */
    AGSPortalGroupSortFieldModified,        /*!< Modified Date */
} ;

/** Supported login types for portal.
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSPortalLoginType) {
    AGSPortalLoginTypeOAuth = 0,                   /*!<  */
    AGSPortalLoginTypeClientCertificate,           /*!<  */
    AGSPortalLoginTypeUsernamePassword,            /*!<  */
    AGSPortalLoginTypeUnknown,                     /*!<  */
} ;

/** Loading status of an object implementing `<AGSLoadable>` protocol.
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSLoadStatus) {
    AGSLoadStatusLoaded = 0,            /*!< Loading completed successfully */
    AGSLoadStatusLoading = 1,           /*!< Loading in progress */
    AGSLoadStatusFailedToLoad = 2,      /*!< Loading completed with error */
    AGSLoadStatusNotLoaded = 3,         /*!< Loading not started */
    AGSLoadStatusUnknown = -1           /*!< Unknwon */
} ;

#pragma mark - Portal Privileges

/** Supported portal privilege realms.
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSPortalPrivilegeRealm) {
    AGSPortalPrivilegeRealmUnknown = 0,         /*!<  */
    AGSPortalPrivilegeRealmFeatures,            /*!<  */
    AGSPortalPrivilegeRealmMarketplace,         /*!<  */
    AGSPortalPrivilegeRealmOpenData,            /*!<  */
    AGSPortalPrivilegeRealmPortal,              /*!<  */
    AGSPortalPrivilegeRealmPremium,             /*!<  */
};

/** Supported portal privilege roles.
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSPortalPrivilegeRole) {
    AGSPortalPrivilegeRoleUnknown = 0,          /*!<  */
    AGSPortalPrivilegeRoleUser,                 /*!<  */
    AGSPortalPrivilegeRoleAdmin,                /*!<  */
    AGSPortalPrivilegeRolePublisher,            /*!<  */
};

/** Supported portal privilege types.
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSPortalPrivilegeType) {
    AGSPortalPrivilegeTypeUnknown = 0,          /*!<  */
    AGSPortalPrivilegeTypeEdit,                 /*!<  */
    AGSPortalPrivilegeTypeFullEdit,             /*!<  */
    AGSPortalPrivilegeTypeManage,               /*!<  */
    AGSPortalPrivilegeTypePurchase,             /*!<  */
    AGSPortalPrivilegeTypeStartTrial,           /*!<  */
    AGSPortalPrivilegeTypeDesignateGroup,       /*!<  */
    AGSPortalPrivilegeTypeOpenDataAdmin,        /*!<  */
    AGSPortalPrivilegeTypeAssignToGroups,       /*!<  */
    AGSPortalPrivilegeTypeManageEnterpriseGroups,/*!<  */
    AGSPortalPrivilegeTypeChangeUserRoles,      /*!<  */
    AGSPortalPrivilegeTypeDeleteGroups,         /*!<  */
    AGSPortalPrivilegeTypeDeleteItems,          /*!<  */
    AGSPortalPrivilegeTypeDeleteUsers,          /*!<  */
    AGSPortalPrivilegeTypeDisableUsers,         /*!<  */
    AGSPortalPrivilegeTypeInviteUsers,          /*!<  */
    AGSPortalPrivilegeTypeManageLicenses,       /*!<  */
    AGSPortalPrivilegeTypeReassignGroups,       /*!<  */
    AGSPortalPrivilegeTypeReassignItems,        /*!<  */
    AGSPortalPrivilegeTypeReassignUsers,        /*!<  */
    AGSPortalPrivilegeTypeUpdateGroups,         /*!<  */
    AGSPortalPrivilegeTypeUpdateItems,          /*!<  */
    AGSPortalPrivilegeTypeUpdateUsers,          /*!<  */
    AGSPortalPrivilegeTypeViewGroups,           /*!<  */
    AGSPortalPrivilegeTypeViewItems,            /*!<  */
    AGSPortalPrivilegeTypeViewUsers,            /*!<  */
    AGSPortalPrivilegeTypePublishFeatures,      /*!<  */
    AGSPortalPrivilegeTypePublishTiles,         /*!<  */
    AGSPortalPrivilegeTypePublishScenes,        /*!<  */
    AGSPortalPrivilegeTypeCreateGroup,          /*!<  */
    AGSPortalPrivilegeTypeCreateItem,           /*!<  */
    AGSPortalPrivilegeTypeJoinGroup,            /*!<  */
    AGSPortalPrivilegeTypeJoinNonOrgGroup,      /*!<  */
    AGSPortalPrivilegeTypeShareGroupToOrg,      /*!<  */
    AGSPortalPrivilegeTypeShareGroupToPublic,   /*!<  */
    AGSPortalPrivilegeTypeShareToGroup,         /*!<  */
    AGSPortalPrivilegeTypeShareToOrg,           /*!<  */
    AGSPortalPrivilegeTypeShareToPublic,        /*!<  */
    AGSPortalPrivilegeTypeDemographics,         /*!<  */
    AGSPortalPrivilegeTypeElevation,            /*!<  */
    AGSPortalPrivilegeTypeGeocode,              /*!<  */
    AGSPortalPrivilegeTypeGeoEnrichment,        /*!<  */
    AGSPortalPrivilegeTypeNetworkAnalysis,      /*!<  */
    AGSPortalPrivilegeTypeSpatialAnalysis,      /*!<  */
    AGSPortalPrivilegeTypeViewOrgUsers,         /*!<  */
    AGSPortalPrivilegeTypeViewOrgItems,         /*!<  */
    AGSPortalPrivilegeTypeViewOrgGroups,        /*!<  */
    AGSPortalPrivilegeTypeGeoAnalytics,         /*!<  */
    AGSPortalPrivilegeTypeRasterAnalysis,       /*!<  */
    AGSPortalPrivilegeTypeCreateUpdateCapableGroup  /*!<  */
};

#pragma mark - popups

/** Style options for the Popups VC
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSPopupsViewControllerContainerStyle) {
    AGSPopupsViewControllerContainerStyleNavigationController,  /*!< The popups view controller will be pushed onto a navigation controller stack by the client */
    AGSPopupsViewControllerContainerStyleNavigationBar,         /*!< The popups view controller will add a navigation bar for the client (useful for when presenting modally) */
    AGSPopupsViewControllerContainerStyleCustom                 /*!< The popups view controller will be embedded in a custom container by the client, who is then responsible for having an edit button */
};

/** Options specifying how to handle existing field values when a feature's type is changed.
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSPopupFeatureTypeChangeMode) {
    AGSPopupFeatureTypeChangeModeResetDefaultValues = 0,        /*!< Reset all fields to default values when feature type is changed */
    AGSPopupFeatureTypeChangeModeKeepValues = 1                 /*!< Keep existing field values even when the feature type is changed */
};

/** An enumeration that is used for defining the editing style of an AGSPopupsViewController.
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSPopupsViewControllerGeometryEditingStyle) {
    AGSPopupsViewControllerGeometryEditingStyleToolbar,     /*!< Shows a toolbar with a button for attachments and a button for collecting the geometry */
    AGSPopupsViewControllerGeometryEditingStyleInline    /*!< Has a view to switch between attributes and attachments.
                                                          There is no button for the collecting the geometry, as this is assumed
                                                          the user has access to the map while the popup is up (think ipad), or
                                                          the user will not be collecting a geometry at all. */
};

/** Enumeration that specifies how date fields are formatted in an AGSPopup.
 The LE (Little Endian) formats are the same as their counterparts. We will not force the LE format,
 but instead honor the format of the current locale. This is so we give the user a string value for the date
 that they expect based on their current locale.
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSPopupDateFormat) {
    AGSPopupDateFormatDayShortMonthYear = 0,           /*!< Date with d MMM y */
    AGSPopupDateFormatLongDate = 1,                    /*!< Date with EEEE, MMMM d, y */
    AGSPopupDateFormatLongMonthDayYear = 2,            /*!< Date with  MMMM d y */
    AGSPopupDateFormatLongMonthYear = 3,               /*!< Date with MMMM y */
    AGSPopupDateFormatShortDate = 4,                   /*!< Date with M/d/y */
    AGSPopupDateFormatShortDateLE = 5,                 /*!< Date with M/d/y */
    AGSPopupDateFormatShortDateLELongTime = 6,         /*!< Date with M/d/y h:mm:ss a */
    AGSPopupDateFormatShortDateLELongTime24 = 7,       /*!< Date with M/d/y H:mm:ss */
    AGSPopupDateFormatShortDateLEShortTime = 8,        /*!< Date with M/d/y h:mm a */
    AGSPopupDateFormatShortDateLEShortTime24 = 9,      /*!< Date with M/d/y H:mm */
    AGSPopupDateFormatShortDateLongTime = 10,          /*!< Date with M/d/y h:mm:ss a */
    AGSPopupDateFormatShortDateLongTime24 = 11,        /*!< Date with M/d/y H:mm:ss */
    AGSPopupDateFormatShortDateShortTime = 12,         /*!< Date with M/d/y h:mm a*/
    AGSPopupDateFormatShortDateShortTime24 = 13,       /*!< Date with M/d/y H:mm */
    AGSPopupDateFormatShortMonthYear = 14,             /*!< Date with MMM y */
    AGSPopupDateFormatYear = 15,                       /*!< Date with y */
    AGSPopupDateFormatUnknown = -1,
};

/** Enumeration that specifies different types of media in an AGSPopup.
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSPopupMediaType){
    AGSPopupMediaTypeImage = 0,                       /*!< Image */
    AGSPopupMediaTypeBarChart = 1,                    /*!< Bar Chart */
    AGSPopupMediaTypeColumnChart = 2,                 /*!< Column Chart */
    AGSPopupMediaTypeLineChart = 3,                   /*!< Line Chart */
    AGSPopupMediaTypePieChart = 4,                    /*!< Pie Chart */
    AGSPopupMediaTypeUnknown = -1                     /*!< Unknown */
};

/** The type of view within @c AGSPopupsViewController
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSPopupViewControllerType){
    AGSPopupViewControllerTypeContainer = 0,  /*!< The default starting view controller */
    AGSPopupViewControllerTypeUIImagePicker,  /*!< View controller that displays the AGSImagePicker */
    AGSPopupViewControllerTypeFullMedia,      /*!< View controller that displays a single media item (image/chart)  */
    AGSPopupViewControllerTypeWeb,            /*!< View controller that displays an embedded `WKWebView` */
    AGSPopupViewControllerTypeMovie,          /*!< View controller that displays movies */
    AGSPopupViewControllerTypeAttributeInput,  /*!< View controller that displays interface for inputting an attribute value */
    AGSPopupViewControllerTypeAlert           /*!< View controller of type UIAlertController */
};

/** Options for string fields in AGSPopupsViewController
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSPopupStringFieldOption) {
    AGSPopupStringFieldOptionSingleLine = 0,        /*!<  */
    AGSPopupStringFieldOptionMultiLine = 1,         /*!<  */
    AGSPopupStringFieldOptionRichText = 2,          /*!<  */
    AGSPopupStringFieldOptionUnknown = -1,          /*!<  */
};

/** The scale mode for images.
 @since 100.3
 */
typedef NS_ENUM(NSInteger, AGSImageScaleMode) {
    AGSImageScaleModeFill = 0,        /*!< Scale to fill, not maintaining aspect ratio. */
    AGSImageScaleModeAspectFit,       /*!< Scales the image to fit in the desired size, maintains aspect ratio. No image cropping will occur. */
    AGSImageScaleModeAspectFill       /*!< Scales the image to fill in the desired size both width and height-wise, maintains aspect ratio. Some cropping may occur. */
};

#pragma mark - License

/** Status for license operations
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSLicenseStatus) {
    AGSLicenseStatusInvalid = 0,                /*!< License is invalid */
    AGSLicenseStatusExpired	= 1,	    		/*!< License has expired */
    AGSLicenseStatusLoginRequired = 2,          /*!< License has passed the 30-day timeout period for a named user. User will need to login in again */
    AGSLicenseStatusValid = 3					/*!< License is valid */
};

/** Available license levels
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSLicenseLevel) {
    AGSLicenseLevelDeveloper = 0,           /*!< No license set. Application will run in developer mode. Full functionality but with a watermarked view. Not suitable for production deployment. */
    AGSLicenseLevelLite = 1,                /*!< Lite license set. No watermark. Functionality available at the lowest level.*/
    AGSLicenseLevelBasic = 2,				/*!< Basic license set. No watermark. Functionality available at the basic level. */
    AGSLicenseLevelStandard = 3,			/*!< Standard license set. No watermark. Functionality available at the standard level. */
    AGSLicenseLevelAdvanced = 4             /*!< Advanced license set. No watermark. Functionality available at the advanced level.*/
};

/** The type of license being used by the application.
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSLicenseType) {
    AGSLicenseTypeDeveloper = 0,             /*!< A license has not been set and application is running in developer mode. Not suitable for production deployment.*/
    AGSLicenseTypeNamedUser = 1,             /*!< Using a subscription license from a named user account.*/
    AGSLicenseTypeLicenseKey = 2             /*!< Licensed from a license key.*/
};

#pragma mark - Load status

/** Return load status for status string.
 @param loadStatus The string representation of a load status.
 @return @c AGSLoadStatus for @p loadStatus string.
 @since 100
 @see AGSLoadStatus
 */
AGS_EXTERN AGSLoadStatus AGSLoadStatusFromString(NSString *loadStatus);

/** Return load status string for @c AGSLoadStatus.
 @param loadStatus The load status.
 @return String representation of @p loadStatus.
 @since 100
 @see AGSLoadStatus
 */
AGS_EXTERN NSString *AGSLoadStatusAsString(AGSLoadStatus loadStatus);




#pragma mark - Mapping

/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSBasemapType) {
    AGSBasemapTypeImagery = 0,                  /*!< */
    AGSBasemapTypeImageryWithLabels = 1,        /*!< */
    AGSBasemapTypeStreets = 2,                  /*!< */
    AGSBasemapTypeTopographic = 3,              /*!< */
    AGSBasemapTypeTerrainWithLabels = 4,        /*!< */
    AGSBasemapTypeLightGrayCanvas = 5,          /*!< */
    AGSBasemapTypeNationalGeographic = 6,       /*!< */
    AGSBasemapTypeOceans = 7,                   /*!< */
    AGSBasemapTypeOpenStreetMap = 8,            /*!< */
    AGSBasemapTypeImageryWithLabelsVector = 9,  /*!< */
    AGSBasemapTypeStreetsVector = 10,           /*!< */
    AGSBasemapTypeTopographicVector = 11,       /*!< */
    AGSBasemapTypeTerrainWithLabelsVector = 12, /*!< */
    AGSBasemapTypeLightGrayCanvasVector = 13,   /*!< */
    AGSBasemapTypeNavigationVector = 14,        /*!< */
    AGSBasemapTypeStreetsNightVector = 15,      /*!< */
    AGSBasemapTypeStreetsWithReliefVector = 16, /*!< */
    AGSBasemapTypeDarkGrayCanvasVector = 17     /*!< */
};

/**
 @since 100
 @deprecated 100.1.  AGSGridType is not used.
 */
typedef __deprecated_msg("AGSGridType is not used") NS_ENUM(NSInteger, AGSGridType){
    AGSGridTypeLatitudeLongitudeGrid __deprecated_msg("AGSGridType is not used") = 0, /*!< */
    AGSGridTypeUTM __deprecated_msg("AGSGridType is not used") = 1,                   /*!< */
    AGSGridTypeMGRS __deprecated_msg("AGSGridType is not used") = 2,                  /*!< */
    AGSGridTypeUSNG __deprecated_msg("AGSGridType is not used") = 3,                  /*!< */
    AGSGridTypeUnknown __deprecated_msg("AGSGridType is not used") = -1,              /*!< */
};

/** Bing Maps style
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSBingMapsLayerStyle){
    AGSBingMapsLayerStyleAerial = 0,     /*!< Aerial */
    AGSBingMapsLayerStyleHybrid = 1,     /*!< Hybrid */
    AGSBingMapsLayerStyleRoad = 2,       /*!< Road */
    AGSBingMapsLayerStyleUnknown = -1    /*!< Unknown */
};

/** The draw status
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSDrawStatus) {
    AGSDrawStatusInProgress = 0,    /*!< In progress*/
    AGSDrawStatusCompleted = 1,     /*!< Completed */
};

/** The status could be a combination of any of these individual states
 @since 100
 */
typedef NS_OPTIONS(NSInteger, AGSLayerViewStatus) {
    AGSLayerViewStatusActive = 1 << 0,       /*!< */
    AGSLayerViewStatusNotVisible = 1 << 1,   /*!< */
    AGSLayerViewStatusOutOfScale = 1 << 2,   /*!< */
    AGSLayerViewStatusLoading = 1 << 3,      /*!< */
    AGSLayerViewStatusError = 1 << 4        /*!< */
};

/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSWrapAroundMode) {
    AGSWrapAroundModeEnabledWhenSupported = 0,  /*!< */
    AGSWrapAroundModeDisabled = 1,              /*!< */
};

/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSViewpointType) {
    AGSViewpointTypeCenterAndScale = 0,         /*!< */
    AGSViewpointTypeBoundingGeometry = 1,       /*!< */
    AGSViewpointTypeUnknown = -1,               /*!< */
};

/** Rendering modes available for feature layers.
 @since 100.2
 */
typedef NS_ENUM(NSInteger, AGSFeatureRenderingMode) {
    AGSFeatureRenderingModeAutomatic = 0,       /*!< The rendering mode for the layer will be automatically chosen based on the geometry type and renderer. For point geometries it is typically Dynamic, for polyline and polgyon it is Static. */
    AGSFeatureRenderingModeStatic = 1,          /*!< Static rendering mode - Features are updated after zoom and pan operations complete. This mode is good for complex geometries or features to be rendered with cartographic quality symbology for example. It may also be suited for rendering features when low end graphics hardware is used. */
    AGSFeatureRenderingModeDynamic = 2          /*!< Dynamic rendering mode - Features will be updated continuously while pan and zoom operations are performed for a smoothly rendered display. This mode is not supported by all renderers. A heat map renderer is an example of a renderer not supported by the dynamic rendering mode. */
};

/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSCacheStorageFormat)
{
    AGSCacheStorageFormatCompact = 0,       /*!<  */
    AGSCacheStorageFormatCompactV2 = 1,     /*!<  */
    AGSCacheStorageFormatExploded = 2,      /*!<  */
    AGSCacheStorageFormatUnknown = -1       /*!<  */
};

/** Represents options for positioning grid labels on screen. `AGSGridLabelPositionGeographic`  means labels are anchored to a
 geographical position on the map, whereas the remaining enum values are screen-positioned, with the labels anchored
 relative to the edge of the map.
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSGridLabelPosition) {
    AGSGridLabelPositionGeographic = 0,     /*!< Labels anchored to a geographical position on the map view. */
    AGSGridLabelPositionBottomLeft = 1,     /*!< x-labels anchored to bottom, y-labels anchored to left of map view.*/
    AGSGridLabelPositionBottomRight = 2,    /*!< x-labels anchored to bottom, y-labels anchored to right of map view.*/
    AGSGridLabelPositionTopLeft = 3,        /*!< x-labels anchored to top, y-labels anchored to left of map view. */
    AGSGridLabelPositionTopRight = 4,       /*!< x-labels anchored to top, y-labels anchored to right of map view.*/
    AGSGridLabelPositionCenter = 5,         /*!< x- and y-labels are anchored in center of map view*/
    AGSGridLabelPositionAllSides = 6,       /*!< Labels are anchored to top, right, bottom and left of map view.*/
};

/** Supported formats for Latitude-Longitude values used in grid labels.
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSLatitudeLongitudeGridLabelFormat) {
    AGSLatitudeLongitudeGridLabelFormatDecimalDegrees = 0,          /*!< Label the grid lines (graticules) in decimal degrees. */
    AGSLatitudeLongitudeGridLabelFormatDegreesMinutesSeconds = 1,   /*!< Label the grid lines (graticules) in degrees, minutes and seconds. */
};

/** Supported units for values displayed in MGRS grid labels
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSMGRSGridLabelUnit) {
    AGSMGRSGridLabelUnitKilometersMeters = 0,   /*!< Labels are displayed in kilometers or meters based on view's scale */
    AGSMGRSGridLabelUnitMeters = 1,             /*!< Labels are always displayed in meters. */
};

/** Supported units for values displayed in USNG grid labels
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSUSNGGridLabelUnit) {
    AGSUSNGGridLabelUnitKilometersMeters = 0,   /*!< Labels are displayed in kilometers or meters based on view's scale */
    AGSUSNGGridLabelUnitMeters = 1,             /*!< Labels are always displayed in meters. */
};

/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSNoDataTileBehavior) {
    AGSNoDataTileBehaviorUpSample = 0,      /*!<  */
    AGSNoDataTileBehaviorBlank = 1,         /*!<  */
    AGSNoDataTileBehaviorShow = 2,          /*!<  */
    AGSNoDataTileBehaviorUnknown = -1       /*!<  */
};

#pragma mark - Symbology

/** Determines whether the symbol should rotate with the map/scene or not.
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSMarkerSymbolAngleAlignment)
{
    AGSMarkerSymbolAngleAlignmentMap = 0,       /*!< Top edge of the symbol stays aligned with the North direction of the map/scene. When the map/scene is rotated, symbols will also rotate along with them. */
    AGSMarkerSymbolAngleAlignmentScreen = 1    /*!< Top edge of the symbol stays aligned with the top-edge of the screen. Even when the map/scene is rotated, symbols will appear to remain face up. */
};

/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSSymbolRotationType)
{
    AGSSymbolRotationTypeArithmetic = 0,    /*!< Rotation is performed starting from East in a counter-clockwise direction where East is the 0° axis */
    AGSSymbolRotationTypeGeographic = 1     /*!< Rotation is performed starting from North in a clockwise direction where North is the 0° axis */
};

/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSSimpleMarkerSymbolStyle)
{
    AGSSimpleMarkerSymbolStyleCircle = 0,       /*!< */
    AGSSimpleMarkerSymbolStyleCross = 1,        /*!< */
    AGSSimpleMarkerSymbolStyleDiamond = 2,      /*!< */
    AGSSimpleMarkerSymbolStyleSquare = 3,       /*!< */
    AGSSimpleMarkerSymbolStyleTriangle = 4,     /*!< */
    AGSSimpleMarkerSymbolStyleX = 5             /*!< */
};

/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSSimpleLineSymbolStyle) {
    AGSSimpleLineSymbolStyleDash = 0,           /*!< */
    AGSSimpleLineSymbolStyleDashDot = 1,        /*!< */
    AGSSimpleLineSymbolStyleDashDotDot = 2,     /*!< */
    AGSSimpleLineSymbolStyleDot = 3,            /*!< */
    AGSSimpleLineSymbolStyleNull = 4,           /*!< */
    AGSSimpleLineSymbolStyleSolid = 5           /*!< */
};


/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSFontDecoration) {
    AGSFontDecorationLineThrough = 0,           /*!< */
    AGSFontDecorationNone = 1,                  /*!< */
    AGSFontDecorationUnderline = 2              /*!< */
};


/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSFontStyle) {
    AGSFontStyleItalic = 0,     /*!< */
    AGSFontStyleNormal = 1,     /*!< */
    AGSFontStyleOblique = 2    /*!< */
};

/**
 @since 100
 */

typedef NS_ENUM(NSInteger, AGSFontWeight) {
    AGSFontWeightBold = 0,      /*!< */
    AGSFontWeightNormal = 1    /*!< */
};

/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSHorizontalAlignment) {
    AGSHorizontalAlignmentCenter = 0,       /*!< */
    AGSHorizontalAlignmentJustify = 1,      /*!< */
    AGSHorizontalAlignmentLeft = 2,         /*!< */
    AGSHorizontalAlignmentRight = 3         /*!< */
};

/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSVerticalAlignment) {
    AGSVerticalAlignmentBaseline = 0,       /*!< */
    AGSVerticalAlignmentBottom = 1,         /*!< */
    AGSVerticalAlignmentMiddle = 2,         /*!< */
    AGSVerticalAlignmentTop = 3             /*!< */
};

/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSSimpleFillSymbolStyle) {
    AGSSimpleFillSymbolStyleBackwardDiagonal = 0,       /*!< */
    AGSSimpleFillSymbolStyleCross = 1,                  /*!< */
    AGSSimpleFillSymbolStyleDiagonalCross = 2,          /*!< */
    AGSSimpleFillSymbolStyleForwardDiagonal = 3,        /*!< */
    AGSSimpleFillSymbolStyleHorizontal = 4,             /*!< */
    AGSSimpleFillSymbolStyleNull = 5,                   /*!< */
    AGSSimpleFillSymbolStyleSolid = 6,                  /*!< */
    AGSSimpleFillSymbolStyleVertical = 7               /*!< */
};

typedef NS_ENUM(NSInteger, AGSSimpleLineSymbolMarkerPlacement) {
    AGSSimpleLineSymbolMarkerPlacementBegin = 0,
    AGSSimpleLineSymbolMarkerPlacementEnd = 1,
    AGSSimpleLineSymbolMarkerPlacementBeginAndEnd = 2
};

typedef NS_ENUM(NSInteger, AGSSimpleLineSymbolMarkerStyle) {
    AGSSimpleLineSymbolMarkerStyleNone = 0,
    AGSSimpleLineSymbolMarkerStyleArrow = 1
};

/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSSceneSymbolAnchorPosition) {
    AGSSceneSymbolAnchorPositionTop = 0,        /*!<  */
    AGSSceneSymbolAnchorPositionBottom = 1,     /*!<  */
    AGSSceneSymbolAnchorPositionCenter = 2,     /*!<  */
    AGSSceneSymbolAnchorPositionOrigin = 3,     /*!<  */
};

/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSSimpleMarkerSceneSymbolStyle) {
    AGSSimpleMarkerSceneSymbolStyleCone = 0,        /*!<  */
    AGSSimpleMarkerSceneSymbolStyleCube = 1,        /*!<  */
    AGSSimpleMarkerSceneSymbolStyleCylinder = 2,    /*!<  */
    AGSSimpleMarkerSceneSymbolStyleDiamond = 3,     /*!<  */
    AGSSimpleMarkerSceneSymbolStyleSphere = 4,      /*!<  */
    AGSSimpleMarkerSceneSymbolStyleTetrahedron = 5  /*!<  */
};

#pragma mark - Renderer

/**
 @since 100
 @deprecated 100.1. AGSRendererNormalizationTypeUnknown is not supported
 */
typedef NS_ENUM(NSInteger, AGSRendererNormalizationType) {
    AGSRendererNormalizationTypeByField = 0,            /*!< */
    AGSRendererNormalizationTypeByLog = 1,              /*!< */
    AGSRendererNormalizationTypeByPercentOfTotal = 2,   /*!< */
    AGSRendererNormalizationTypeNone = 3,               /*!< */
    AGSRendererNormalizationTypeUnknown __deprecated_enum_msg("AGSRendererNormalizationTypeUnknown is no longer supported") = -1            /*!< */
};

/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSPresetColorRampType) {
    AGSPresetColorRampTypeNone = -1,                          /*!<  */
    AGSPresetColorRampTypeElevation = 0,                      /*!<  */
    AGSPresetColorRampTypeDEMScreen = 1,                      /*!<  */
    AGSPresetColorRampTypeDEMLight = 2,                       /*!<  */
};

/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSPansharpenType) {
    AGSPansharpenTypeNone = -1,                         /*!<  */
    AGSPansharpenTypeIHS = 0,                           /*!<  */
    AGSPansharpenTypeBrovey = 1,                        /*!<  */
    AGSPansharpenTypeMean = 2,                          /*!<  */
    AGSPansharpenTypeEsri = 3,                          /*!<  */
    AGSPansharpenTypeGramSchmidt = 4,                   /*!<  */
};

/** Type of data, such as signed integer, unsigned integer, or floating point, contained in each pixel of a raster
 @since 100.1
 */
typedef NS_ENUM(NSInteger, AGSPixelType) {
    AGSPixelTypeUnknown = -1,       /*!<  */
    AGSPixelTypeUInt1 = 0,          /*!<  */
    AGSPixelTypeUInt2 = 1,          /*!<  */
    AGSPixelTypeUInt4 = 2,          /*!<  */
    AGSPixelTypeUInt8 = 3,          /*!<  */
    AGSPixelTypeInt8 = 4,           /*!<  */
    AGSPixelTypeUInt16 = 5,         /*!<  */
    AGSPixelTypeInt16 = 6,          /*!<  */
    AGSPixelTypeUInt32 = 7,         /*!<  */
    AGSPixelTypeInt32 = 8,          /*!<  */
    AGSPixelTypeFloat32 = 9,        /*!<  */
    AGSPixelTypeFloat64 = 10        /*!<  */
};

typedef NS_ENUM(NSInteger, AGSSlopeType) {
    AGSSlopeTypeNone = -1,                              /*!<  */
    AGSSlopeTypeDegree = 0,                             /*!<  Inclination of slope is calculated in degrees. The values range from 0 to 90 */
    AGSSlopeTypePercentRise = 1,                        /*!<  Inclination of slope is calculated as percentage values. The values range from 0 to essentially infinity. A flat surface is 0 percent and a 45-degree surface is 100 percent, and as the surface becomes more vertical, the percent rise becomes increasingly larger */
    AGSSlopeTypeScaled = 2,                             /*!<  Same as Degree, but the z-factor is adjusted for scale using Pixel Size Power and Pixel Size Factor */
};

/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSExtrusionMode) {
    AGSExtrusionModeNone = 0,                           /*!<  No extrusion */
    AGSExtrusionModeMinimum = 1,                        /*!<  A z-value is calculated by adding the extrusion height to the minimum z-value of the geo-element, and the geo-element is extruded to a flat top at that value.*/
    AGSExtrusionModeMaximum = 2,                        /*!<  A z-value is calculated by adding the extrusion height to the maximum z-value of the geo-element, and the geo-element is extruded to a flat top at that value.*/
    AGSExtrusionModeAbsoluteHeight = 3,                 /*!<  The geo-element is extruded to the specified z-value as a flat top, regardless of the z-values of the geo-element.*/
    AGSExtrusionModeBaseHeight = 4,                     /*!<  A z-value is calculated for each vertex of the geo-element's base, and the geo-element is extruded to the various z-values. This is the only extrusion mode that doesn't have a flat top.*/
};

/**
 @since 100.2
 */
typedef NS_ENUM(NSInteger, AGSRendererClassificationMethod)
{
    AGSRendererClassificationMethodDefinedInterval = 0,        /*!<  */
    AGSRendererClassificationMethodEqualInterval = 1,          /*!<  */
    AGSRendererClassificationMethodGeometricalInterval = 2,    /*!<  */
    AGSRendererClassificationMethodNaturalBreaks = 3,          /*!<  */
    AGSRendererClassificationMethodQuantile = 4,               /*!<  */
    AGSRendererClassificationMethodStandardDeviation = 5,      /*!<  */
    AGSRendererClassificationMethodManual = 6                  /*!<  */
};

#pragma mark - Animation

/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSAnimationCurve) {
    AGSAnimationCurveLinear = 0,                /*!< */
    AGSAnimationCurveEaseInQuad = 1,            /*!< */
    AGSAnimationCurveEaseOutQuad = 2,           /*!< */
    AGSAnimationCurveEaseInOutQuad = 3,         /*!< */
    AGSAnimationCurveEaseInCubic = 4,           /*!< */
    AGSAnimationCurveEaseOutCubic = 5,          /*!< */
    AGSAnimationCurveEaseInOutCubic = 6,        /*!< */
    AGSAnimationCurveEaseInQuart = 7,           /*!< */
    AGSAnimationCurveEaseOutQuart = 8,          /*!< */
    AGSAnimationCurveEaseInOutQuart = 9,        /*!< */
    AGSAnimationCurveEaseInQuint = 10,          /*!< */
    AGSAnimationCurveEaseOutQuint = 11,         /*!< */
    AGSAnimationCurveEaseInOutQuint = 12,       /*!< */
    AGSAnimationCurveEaseInSine = 13,           /*!< */
    AGSAnimationCurveEaseOutSine = 14,          /*!< */
    AGSAnimationCurveEaseInOutSine = 15,        /*!< */
    AGSAnimationCurveEaseInExpo = 16,           /*!< */
    AGSAnimationCurveEaseOutExpo = 17,          /*!< */
    AGSAnimationCurveEaseInOutExpo = 18,        /*!< */
    AGSAnimationCurveEaseInCirc = 19,           /*!< */
    AGSAnimationCurveEaseOutCirc = 20,          /*!< */
    AGSAnimationCurveEaseInOutCirc = 21        /*!< */
};



#pragma mark - Units

/** Supported time units.
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSTimeUnit) {
    AGSTimeUnitUnknown = -1,               /*!< Unknown */
    AGSTimeUnitCenturies = 0,              /*!< Centuries */
    AGSTimeUnitDays = 1,                   /*!< Days */
    AGSTimeUnitDecades = 2,                /*!< Decades*/
    AGSTimeUnitHours = 3,                  /*!< Hours */
    AGSTimeUnitMilliseconds = 4,           /*!< Milliseconds */
    AGSTimeUnitMinutes = 5,                /*!< Minutes */
    AGSTimeUnitMonths = 6,                 /*!< Months */
    AGSTimeUnitSeconds = 7,                /*!< Seconds */
    AGSTimeUnitWeeks = 8,                  /*!< Weeks */
    AGSTimeUnitYears = 9                   /*!< Years */
};

/** Supported time relation.
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSTimeRelation) {
    AGSTimeRelationUnknown = -1,                /*!<  */
    AGSTimeRelationOverlaps = 0,                /*!<  */
    AGSTimeRelationAfterStartOverlapsEnd = 1,   /*!<  */
    AGSTimeRelationOverlapsStartWithinEnd = 2,  /*!<  */
};

/**
 Angular units.
 
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSAngularUnitID)
{
    AGSAngularUnitIDDegrees = 9102,     /*!< Degrees */
    AGSAngularUnitIDGrads = 9105,       /*!< Gradians */
    AGSAngularUnitIDMinutes = 9103,     /*!< Minutes */
    AGSAngularUnitIDRadians = 9101,     /*!< Radians */
    AGSAngularUnitIDSeconds = 9104,     /*!< Seconds */
    AGSAngularUnitIDOther = 0           /*!< Other */
};

/**
 Area units.
 
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSAreaUnitID)
{
    AGSAreaUnitIDAcres = 109402,                /*!< Acres */
    AGSAreaUnitIDHectares = 109401,             /*!< Hectares */
    AGSAreaUnitIDSquareCentimeters = 109451,    /*!< Sq. Centimeters */
    AGSAreaUnitIDSquareDecimeters = 109450,     /*!< Sq. Decimeters */
    AGSAreaUnitIDSquareFeet = 109405,           /*!< Sq. Feet */
    AGSAreaUnitIDSquareKilometers = 109414,     /*!< Sq. Kilometers */
    AGSAreaUnitIDSquareMeters = 109404,         /*!< Sq. Meters */
    AGSAreaUnitIDSquareMillimeters = 109452,    /*!< Sq. Millimeters */
    AGSAreaUnitIDSquareMiles = 109439,          /*!< Sq. Miles */
    AGSAreaUnitIDSquareYards = 109442,          /*!< Sq. Yards */
    AGSAreaUnitIDOther = 0                      /*!< Other */
};

/**
 Linear units.
 
 @since 100
 */

typedef NS_ENUM(NSInteger, AGSLinearUnitID)
{
    AGSLinearUnitIDCentimeters = 1033,          /*!< Centimeters. */
    AGSLinearUnitIDFeet = 9002,                 /*!< International foot. */
    AGSLinearUnitIDInches = 109008,             /*!< International inch. */
    AGSLinearUnitIDKilometers = 9036,           /*!< Kilometer. */
    AGSLinearUnitIDMeters = 9001,               /*!< International meter. */
    AGSLinearUnitIDMiles = 9093,                /*!< Statute Miles. */
    AGSLinearUnitIDMillimeters = 1025,          /*!< Millimeters */
    AGSLinearUnitIDNauticalMiles = 9030,		/*!< International nautical mile. */
    AGSLinearUnitIDYards = 9096,                /*!< Yards. */
    AGSLinearUnitIDOther = 0,                   /*!< Other */
};

#pragma mark - Image Format

/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSMapServiceImageFormat) {
    AGSMapServiceImageFormatDefault = 0,      /*!< */
    AGSMapServiceImageFormatPNG = 1,          /*!< */
    AGSMapServiceImageFormatPNG8 = 2,         /*!< */
    AGSMapServiceImageFormatPNG24 = 3,        /*!< */
    AGSMapServiceImageFormatPNG32 = 4,        /*!< */
    AGSMapServiceImageFormatJPG = 5,          /*!< */
    AGSMapServiceImageFormatJPGPNG = 6,       /*!< */
    AGSMapServiceImageFormatBMP = 7,          /*!< */
    AGSMapServiceImageFormatGIF = 8,          /*!< */
    AGSMapServiceImageFormatTIFF = 9,         /*!< */
    AGSMapServiceImageFormatUnknown = -1,     /*!< */
};

/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSTileImageFormat)
{
    AGSTileImageFormatPNG = 0,      /*!<  */
    AGSTileImageFormatPNG8 = 1,     /*!<  */
    AGSTileImageFormatPNG24 = 2,    /*!<  */
    AGSTileImageFormatPNG32 = 3,    /*!<  */
    AGSTileImageFormatJPG = 4,      /*!<  */
    AGSTileImageFormatMIXED = 5,    /*!<  */
    AGSTileImageFormatLERC = 6,     /*!<  */
    AGSTileImageFormatUnknown = -1  /*!<  */
};

#pragma mark - Labeling

/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSLabelingPlacement) {
    AGSLabelingPlacementUnknown = -1,           /*!< */
    AGSLabelingPlacementLineAboveAfter = 0,     /*!< */
    AGSLabelingPlacementLineAboveAlong = 1,     /*!< */
    AGSLabelingPlacementLineAboveBefore = 2,    /*!< */
    AGSLabelingPlacementLineAboveEnd = 3,       /*!< */
    AGSLabelingPlacementLineAboveStart = 4,     /*!< */
    AGSLabelingPlacementLineBelowAfter = 5,     /*!< */
    AGSLabelingPlacementLineBelowAlong = 6,     /*!< */
    AGSLabelingPlacementLineBelowBefore = 7,    /*!< */
    AGSLabelingPlacementLineBelowEnd = 8,       /*!< */
    AGSLabelingPlacementLineBelowStart = 9,     /*!< */
    AGSLabelingPlacementLineCenterAfter = 10,   /*!< */
    AGSLabelingPlacementLineCenterAlong = 11,   /*!< */
    AGSLabelingPlacementLineCenterBefore = 12,  /*!< */
    AGSLabelingPlacementLineCenterEnd = 13,     /*!< */
    AGSLabelingPlacementLineCenterStart = 14,   /*!< */
    AGSLabelingPlacementPointAboveCenter = 15,  /*!< */
    AGSLabelingPlacementPointAboveLeft = 16,    /*!< */
    AGSLabelingPlacementPointAboveRight = 17,   /*!< */
    AGSLabelingPlacementPointBelowCenter = 18,  /*!< */
    AGSLabelingPlacementPointBelowLeft = 19,    /*!< */
    AGSLabelingPlacementPointBelowRight = 20,   /*!< */
    AGSLabelingPlacementPointCenterCenter = 21, /*!< */
    AGSLabelingPlacementPointCenterLeft = 22,   /*!< */
    AGSLabelingPlacementPointCenterRight = 23,  /*!< */
    AGSLabelingPlacementPolygonAlwaysHorizontal = 24,/*!< */
};



#pragma mark - Feature

/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSFieldType) {
    AGSFieldTypeUnknown = -1,       /*!< */
    AGSFieldTypeInt16 = 0,          /*!< */
    AGSFieldTypeInt32 = 1,          /*!< */
    AGSFieldTypeGUID = 3,           /*!< */
    AGSFieldTypeFloat = 4,          /*!< */
    AGSFieldTypeDouble = 5,         /*!< */
    AGSFieldTypeDate = 6,           /*!< */
    AGSFieldTypeText = 7,           /*!< */
    AGSFieldTypeOID = 8,            /*!< */
    AGSFieldTypeGlobalID = 9,       /*!< */
    AGSFieldTypeBlob = 10,          /*!< */
    AGSFieldTypeGeometry = 11,      /*!< */
    AGSFieldTypeRaster = 12,        /*!< */
    AGSFieldTypeXML = 13            /*!< */
};

/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSSpatialRelationship) {
    AGSSpatialRelationshipUnknown = -1,             /*!< */
    AGSSpatialRelationshipRelate = 0,               /*!< */
    AGSSpatialRelationshipEquals = 1,               /*!< */
    AGSSpatialRelationshipDisjoint = 2,             /*!< */
    AGSSpatialRelationshipIntersects = 3,           /*!< */
    AGSSpatialRelationshipTouches = 4,              /*!< */
    AGSSpatialRelationshipCrosses = 5,              /*!< */
    AGSSpatialRelationshipWithin = 6,               /*!< */
    AGSSpatialRelationshipContains = 7,             /*!< */
    AGSSpatialRelationshipOverlaps = 8,             /*!< */
    AGSSpatialRelationshipEnvelopeIntersects = 9,   /*!< */
    AGSSpatialRelationshipIndexIntersects = 10,     /*!< */
};

/** Specifies how `AGSServiceFeatureTable` should retrieve data from its service.
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSFeatureRequestMode) {
    AGSFeatureRequestModeUndefined = 0,                 /*!< */
    AGSFeatureRequestModeOnInteractionCache = 1,        /*!< Data is automatically requested as the user navigates and interacts with the map. All data that is requested is cached locally. Cached data is never requested again even when the map is navigated to areas that have been already visited. Suitable for fairly static data that does not change on the server.*/
    AGSFeatureRequestModeOnInteractionNoCache = 2,      /*!< Data is automatically requested as the user navigates and interacts with the map, but it is never cached. The same data may be requested mutliple times when the map is navigated to areas that have been already visited. Suitable for continually updateing data on the server.*/
    AGSFeatureRequestModeManualCache = 3,               /*!< Data is not automatically requested upon map interaction or navigation. The developer needs to explicitly request data using `AGSServiceFeatureTable#populateFromServiceWithParameters:clearCache:completion:` */
};

/** The type of join between the sources
 @since 100.1
 */
typedef NS_ENUM(NSInteger, AGSJoinType) {
    AGSJoinTypeInnerJoin = 0,           /*!< Inner join:  keeps only those rows that are common between the two sources */
    AGSJoinTypeLeftOuterJoin = 1,       /*!< Left join: keeps all rows from the left source, some values from the right source may be null when there isn't a match */
    AGSJoinTypeUnknown = -1             /*!< Unknown */
};

/** Order in which to sort query results
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSSortOrder) {
    AGSSortOrderAscending = 0,      /*!< */
    AGSSortOrderDescending = 1,     /*!< */
};

/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSEditOperation) {
    AGSEditOperationAdd = 0,        /*!< */
    AGSEditOperationUpdate = 1,     /*!< */
    AGSEditOperationDelete = 2,     /*!< */
    AGSEditOperationUnknown = -1,   /*!< */
};

/** Selection mode for handling results
 @see `AGSFeatureLayer#selectFeaturesWithQuery:mode:completion:`
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSSelectionMode) {
    AGSSelectionModeAdd = 0,            /*!< Add results to the existing set of selected features */
    AGSSelectionModeNew = 1,            /*!< Replace existing set of selected features with the results  */
    AGSSelectionModeSubtract = 2,       /*!< Remove results from the existing set of selected features */
};

/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSQueryFeatureFields) {
    AGSQueryFeatureFieldsIDsOnly = 0,       /*!<  */
    AGSQueryFeatureFieldsMinimum = 1,       /*!<  */
    AGSQueryFeatureFieldsLoadAll = 2,       /*!<  */
};

/** Supported drawing tools.
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSDrawingTool) {
    AGSDrawingToolUnknown = -1,             /*!< */
    AGSDrawingToolAutoCompletePolygon = 0,  /*!< */
    AGSDrawingToolCircle = 1,               /*!< */
    AGSDrawingToolDownArrow = 2,            /*!< */
    AGSDrawingToolEllipse = 3,              /*!< */
    AGSDrawingToolFreeHand = 4,             /*!< */
    AGSDrawingToolLeftArrow = 5,            /*!< */
    AGSDrawingToolLine = 6,                 /*!< */
    AGSDrawingToolNone = 7,                 /*!< */
    AGSDrawingToolPoint = 8,                /*!< */
    AGSDrawingToolPolygon = 9,              /*!< */
    AGSDrawingToolRectangle = 10,           /*!< */
    AGSDrawingToolRightArrow = 11,          /*!< */
    AGSDrawingToolText = 12,                /*!< */
    AGSDrawingToolTriangle = 13,            /*!< */
    AGSDrawingToolUpArrow = 14,             /*!< */
};

/** Supported service type of feature layer info.
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSArcGISFeatureLayerInfoServiceType) {
    AGSArcGISFeatureLayerInfoServiceTypeLayer = 0,          /*!<  */
    AGSArcGISFeatureLayerInfoServiceTypeTable = 1,          /*!<  */
    AGSArcGISFeatureLayerInfoServiceTypeGroupLayer = 2,     /*!<  */
    AGSArcGISFeatureLayerInfoServiceTypeUnknown = -1,       /*!<  */
};

/** Represents the various statistics that can be calculated for values in a field in a table.
 @since 100.2
 */
typedef NS_ENUM(NSInteger, AGSStatisticType) {
    AGSStatisticTypeAverage = 0,                /*!< the average for all non-null values in a column. */
    AGSStatisticTypeCount = 1,                  /*!< the number of non-null values in a column. */
    AGSStatisticTypeMaximum = 2,                /*!< the maximum value found within a column. */
    AGSStatisticTypeMinimum = 3,                /*!< the minimum value found within a column. */
    AGSStatisticTypeStandardDeviation = 4,      /*!< the standard deviation of the values within a column. */
    AGSStatisticTypeSum = 5,                    /*!< the sum of all non-null values within a column. */
    AGSStatisticTypeVariance = 6,               /*!< the variance of the values within a column. */
};

#pragma mark - Location Display

/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSLocationDisplayAutoPanMode) {
    AGSLocationDisplayAutoPanModeOff = 0,                       /*!< */
    AGSLocationDisplayAutoPanModeRecenter = 1,                  /*!< */
    AGSLocationDisplayAutoPanModeNavigation = 2,                /*!< */
    AGSLocationDisplayAutoPanModeCompassNavigation = 3          /*!< */
};

#pragma mark - Layer

/** Cardinality of the relationship
 @since 100.1
 */
typedef NS_ENUM(NSInteger, AGSRelationshipCardinality) {
    AGSRelationshipCardinalityManyToMany = 0,       /*!< Each feature in the origin table may be related to many features in the destination table and vice versa */
    AGSRelationshipCardinalityOneToMany = 1,        /*!< Each feature in the origin table may be related to many features in the destination table */
    AGSRelationshipCardinalityOneToOne = 2,          /*!< Each feature in the origin table may be related to only one feature in the destination table */
    AGSRelationshipCardinalityUnknown = -1          /*!< */
};

/** Role of the feature table in the relationship
 @since 100.1
 */
typedef NS_ENUM(NSInteger, AGSRelationshipRole) {
    AGSRelationshipRoleDestination = 0,     /*!< Table serves as the destination in the relationship */
    AGSRelationshipRoleOrigin = 1,           /*!< Table serves as the origin in the relationship */
    AGSRelationshipRoleUnknown = -1          /*!< */
};

#pragma mark - Service Info

/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSTextAntialiasingMode) {
    AGSTextAntialiasingModeNone = 0,                /*!<  */
    AGSTextAntialiasingModeNormal = 1,              /*!<  */
    AGSTextAntialiasingModeForce = 2,               /*!<  */
};

/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSAntialiasingMode) {
    AGSAntialiasingModeNone = 0,                    /*!<  */
    AGSAntialiasingModeFastest = 1,                 /*!<  */
    AGSAntialiasingModeFast = 2,                    /*!<  */
    AGSAntialiasingModeNormal = 3,                  /*!<  */
    AGSAntialiasingModeBest = 4,                    /*!<  */
};

/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSServiceType) {
    AGSServiceTypeUnknown = -1,             /*!<  */
    AGSServiceTypeFeatureService = 0,       /*!<  */
    AGSServiceTypeImageService = 1,         /*!<  */
    AGSServiceTypeMapService = 2,           /*!<  */
};

/** The type of sublayer in the ArcGIS Map Service
 @since 100.1
 */
typedef NS_ENUM(NSInteger, AGSArcGISMapServiceSublayerType) {
    AGSArcGISMapServiceSublayerTypeFeatureLayer = 0,         /*!< Feature layer */
    AGSArcGISMapServiceSublayerTypeTable = 1,                /*!< Non-spatial table */
    AGSArcGISMapServiceSublayerTypeGroupLayer = 2,           /*!< Group layer */
    AGSArcGISMapServiceSublayerTypeRasterLayer = 3,          /*!< Raster layer */
    AGSArcGISMapServiceSublayerTypeNetworkAnalysisLayer = 4, /*!< Network Analysis layer */
    AGSArcGISMapServiceSublayerTypeUnknown = -1,             /*!< Other */
};

/** Represents the version of WMS services.
 @since 100.2.1
 */
typedef NS_ENUM(NSInteger, AGSWMSVersion) {
    AGSWMSVersionV110 = 110,    /*!< Version 1.1.0 */
    AGSWMSVersionV111 = 111,    /*!< Version 1.1.1 */
    AGSWMSVersionV130 = 130,    /*!< Version 1.3.0 */
};

#pragma mark - Graphics Overlay

/**  Specifies how the `AGSGraphicsOverlay` renders its content.
 Dynamic mode is better suited for a small number of graphics that are constantly changing or moving and need to
 be redrawn frequently.
 If your content is more static then use static mode. Static mode does not provide the same level
 of interactiveness or user experience as dynamic mode,
 but it allows the overlay to render a larger number of graphics.
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSGraphicsRenderingMode) {
    AGSGraphicsRenderingModeDynamic = 0,    /*!< */
    AGSGraphicsRenderingModeStatic = 1,     /*!< */
};

#pragma mark - Network Tasks

/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSBarrierType) {
    AGSBarrierTypeRestriction = 0,          /*!<  */
    AGSBarrierTypeCostAdjustment = 1,       /*!<  */
};

/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSCurbApproach) {
    AGSCurbApproachEitherSide = 0,      /*!<  */
    AGSCurbApproachLeftSide = 1,        /*!<  */
    AGSCurbApproachRightSide = 2,       /*!<  */
    AGSCurbApproachNoUTurn = 3,         /*!<  */
    AGSCurbApproachUnknown = 4          /*!<  */
};

/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSLocationStatus) {
    AGSLocationStatusNotLocated = 0,                /*!< The element's location on the network dataset can't be determined. */
    AGSLocationStatusOnClosest = 1,                 /*!< The element has been located on the closest network location */
    AGSLocationStatusOnClosestNotRestricted = 2,    /*!< The closest network location to the element is not traversable because of a restriction or barrier, so the element has been located on the closest traversable network feature instead  */
    AGSLocationStatusNotReached = 3,                /*!< The element can't be reached during analysis */
};

/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSUTurnPolicy) {
    AGSUTurnPolicyNotAllowed = 0,                           /*!<  */
    AGSUTurnPolicyAllowedAtDeadEnds = 1,                    /*!<  */
    AGSUTurnPolicyAllowedAtIntersections = 2,               /*!<  */
    AGSUTurnPolicyAllowedAtDeadEndsAndIntersections = 3,    /*!<  */
};

/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSDirectionManeuverType) {
    AGSDirectionManeuverTypeUnknown = 0,			/*!<  */
    AGSDirectionManeuverTypeStop = 1,               /*!<  */
    AGSDirectionManeuverTypeStraight = 2,			/*!<  */
    AGSDirectionManeuverTypeBearLeft = 3,			/*!<  */
    AGSDirectionManeuverTypeBearRight = 4,			/*!<  */
    AGSDirectionManeuverTypeTurnLeft = 5,			/*!<  */
    AGSDirectionManeuverTypeTurnRight = 6,			/*!<  */
    AGSDirectionManeuverTypeSharpLeft = 7,			/*!<  */
    AGSDirectionManeuverTypeSharpRight = 8,			/*!<  */
    AGSDirectionManeuverTypeUTurn = 9,              /*!<  */
    AGSDirectionManeuverTypeFerry = 10,             /*!<  */
    AGSDirectionManeuverTypeRoundabout = 11,		/*!<  */
    AGSDirectionManeuverTypeHighwayMerge = 12,		/*!<  */
    AGSDirectionManeuverTypeHighwayExit = 13,		/*!<  */
    AGSDirectionManeuverTypeHighwayChange = 14,		/*!<  */
    AGSDirectionManeuverTypeForkCenter = 15,		/*!<  */
    AGSDirectionManeuverTypeForkLeft = 16,			/*!<  */
    AGSDirectionManeuverTypeForkRight = 17,			/*!<  */
    AGSDirectionManeuverTypeDepart = 18,			/*!<  */
    AGSDirectionManeuverTypeTripItem = 19,			/*!<  */
    AGSDirectionManeuverTypeEndOfFerry = 20,		/*!<  */
    AGSDirectionManeuverTypeRampRight = 21,			/*!<  */
    AGSDirectionManeuverTypeRampLeft = 22,			/*!<  */
    AGSDirectionManeuverTypeTurnLeftRight = 23,		/*!<  */
    AGSDirectionManeuverTypeTurnRightLeft = 24,		/*!<  */
    AGSDirectionManeuverTypeTurnRightRight = 25,	/*!<  */
    AGSDirectionManeuverTypeTurnLeftLeft = 26,		/*!<  */
    AGSDirectionManeuverTypePedestrianRamp = 27,	/*!<  */
    AGSDirectionManeuverTypeElevator = 28,			/*!<  */
    AGSDirectionManeuverTypeEscalator = 29,			/*!<  */
    AGSDirectionManeuverTypeStairs = 30,			/*!<  */
    AGSDirectionManeuverTypeDoorPassage = 31,		/*!<  */
};

/** Type of stop along the route
 @since 100.1
 */
typedef NS_ENUM(NSUInteger, AGSStopType) {
    AGSStopTypeStop = 0,            /*!<  */
    AGSStopTypeWaypoint = 1,        /*!<  */
    AGSStopTypeRestBreak = 2,       /*!<  */
};

/** The system of units/measurement
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSUnitSystem) {
    AGSUnitSystemUnknown = -1,
    AGSUnitSystemImperial = 0,                      /*!<  */
    AGSUnitSystemMetric = 1,                        /*!<  */
};

/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSDirectionsStyle) {
    AGSDirectionsStyleDesktop = 0,      /*!<  */
    AGSDirectionsStyleNavigation = 1,   /*!<  */
    AGSDirectionsStyleCampus = 2,       /*!<  */
};

/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSRouteShapeType) {
    AGSRouteShapeTypeNone = 0,                      /*!<  */
    AGSRouteShapeTypeStraightLine = 1,              /*!<  */
    AGSRouteShapeTypeTrueShapeWithMeasures = 2,     /*!<  */
};

/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSAttributeUnit) {
    AGSAttributeUnitUnknown = 0,              /*!<  */
    AGSAttributeUnitInches = 1,               /*!<  */
    AGSAttributeUnitFeet = 2,                 /*!<  */
    AGSAttributeUnitYards = 3,                /*!<  */
    AGSAttributeUnitMiles = 4,                /*!<  */
    AGSAttributeUnitMillimeters = 5,          /*!<  */
    AGSAttributeUnitCentimeters = 6,          /*!<  */
    AGSAttributeUnitDecimeters = 7,           /*!<  */
    AGSAttributeUnitMeters = 8,               /*!<  */
    AGSAttributeUnitKilometers = 9,           /*!<  */
    AGSAttributeUnitNauticalMiles = 10,       /*!<  */
    AGSAttributeUnitDecimalDegrees = 11,      /*!<  */
    AGSAttributeUnitSeconds = 12,             /*!<  */
    AGSAttributeUnitMinutes = 13,             /*!<  */
    AGSAttributeUnitHours = 14,               /*!<  */
    AGSAttributeUnitDays = 15,                /*!<  */
};

/**
 @since 100
 @deprecated 100.2 AGSDirectionMessageTypeLength is not supported, use AGSDirectionManeuver#length instead
 @deprecated 100.2 AGSDirectionMessageTypeTime is not supported, use AGSDirectionManeuver#duration instead
 @deprecated 100.2 AGSDirectionMessageTypeSummary is not supported, use AGSDirectionManeuver#duration and AGSDirectionManeuver#length instead
 @deprecated 100.2 AGSDirectionMessageTypeTimeWindow is not supported, use AGSStop#timeWindowEnd instead
 @deprecated 100.2 AGSDirectionMessageTypeViolationTime is not supported, use AGSStop#violationTime instead
 @deprecated 100.2 AGSDirectionMessageTypeWaitTime is not supported, use AGSStop#waitTime instead
 @deprecated 100.2 AGSDirectionMessageTypeServiceTime is not supported, use the difference between AGSDirectionManeuver#duration and AGSStop#waitTime instead
 @deprecated 100.2 AGSDirectionMessageTypeEstimatedArrivalTime is not supported, use AGSDirectionManeuver#estimatedArriveTime instead
 @deprecated 100.2 AGSDirectionMessageTypeCumulativeLength is not supported, use the sum of previous AGSDirectionManeuver#length instead
 */
typedef NS_ENUM(NSInteger, AGSDirectionMessageType) {
    AGSDirectionMessageTypeLength __deprecated_enum_msg("AGSDirectionMessageTypeLength is no longer supported, use AGSDirectionManeuver.length instead") = 0,                  /*!<  */
    AGSDirectionMessageTypeTime __deprecated_enum_msg("AGSDirectionMessageTypeTime is no longer supported, use AGSDirectionManeuver.duration instead") = 1,                    /*!<  */
    AGSDirectionMessageTypeSummary __deprecated_enum_msg("AGSDirectionMessageTypeSummary is no longer supported, use AGSDirectionManeuver.duration and AGSDirectionManeuver.length instead") = 2,                 /*!<  */
    AGSDirectionMessageTypeTimeWindow __deprecated_enum_msg("AGSDirectionMessageTypeTimeWindow is no longer supported, use AGSStop.timeWindowEnd instead") = 3,              /*!<  */
    AGSDirectionMessageTypeViolationTime __deprecated_enum_msg("AGSDirectionMessageTypeViolationTime is no longer supported, use AGSStop.violationTime instead") = 4,			/*!<  */
    AGSDirectionMessageTypeWaitTime __deprecated_enum_msg("AGSDirectionMessageTypeWaitTime is no longer supported, use AGSStop.waitTime instead") = 5,                /*!<  */
    AGSDirectionMessageTypeServiceTime __deprecated_enum_msg("AGSDirectionMessageTypeServiceTime is no longer supported, use the difference between AGSDirectionManeuver.duration and AGSStop.waitTime instead") = 6,             /*!<  */
    AGSDirectionMessageTypeEstimatedArrivalTime __deprecated_enum_msg("AGSDirectionMessageTypeEstimatedArrivalTime is no longer supported, use AGSDirectionManeuver.estimatedArriveTime instead") = 7,	/*!<  */
    AGSDirectionMessageTypeCumulativeLength __deprecated_enum_msg("AGSDirectionMessageTypeCumulativeLength is no longer supported, use the sum of previous AGSDirectionManeuver.length instead") = 8,		/*!<  */
    AGSDirectionMessageTypeStreetName = 9,              /*!<  */
    AGSDirectionMessageTypeAlternativeName = 10,		/*!<  */
    AGSDirectionMessageTypeBranch = 11,                 /*!<  */
    AGSDirectionMessageTypeToward = 12,                 /*!<  */
    AGSDirectionMessageTypeCrossStreet = 13,			/*!<  */
    AGSDirectionMessageTypeExit = 14,                   /*!<  */
};

#pragma mark - Service Area Task

/** Type of overlap between service area geometries
 @since 100.1
 */
typedef NS_ENUM(NSInteger, AGSServiceAreaOverlapGeometry)
{
    AGSServiceAreaOverlapGeometryOverlap = 0,   /*!< Creates individual polygons for each facility. The polygons can overlap each other. For overlapping lines, portions of the network that are within reach of more than one facility will have a line for each facility*/
    AGSServiceAreaOverlapGeometryDissolve = 1,  /*!< Merges the polygons of multiple facilities that have the same cutoff values into one polygon. If the polygons of a given break value don't touch, they are nonetheless merged into one multipart polygon. This option does not apply to lines */
    AGSServiceAreaOverlapGeometrySplit = 2      /*!< Creates individual polygons that are closest for each facility. The polygons do not overlap each other. For split lines, none of the lines overlap each other, and a line is always assigned to the nearest facility even if more than one facility can reach it */
};

/** Type of geometry for concentric service areas
 @since 100.1
 */
typedef NS_ENUM(NSInteger, AGSServiceAreaPolygonCutoffGeometry)
{
    AGSServiceAreaPolygonCutoffGeometryRings = 0,   /*!< Output polygons extend between the nearest cutoff values only. They do not include the area of smaller breaks. This creates polygons between consecutive breaks */
    AGSServiceAreaPolygonCutoffGeometryDisks = 1    /*!< Output polygons extend from the facility to the cutoff. If you create 5- and 10-minute service areas, the 10-minute service area polygon will include the area under the 5-minute service area polygon as well as the area from the 5-minute to the 10-minute area */
};

/** Level of detail for service area geometries
 @since 100.1
 */
typedef NS_ENUM(NSInteger, AGSServiceAreaPolygonDetail)
{
    AGSServiceAreaPolygonDetailGeneralized = 0, /*!< Prefers higher-order edges to the lowest-order edges in the transportation network, for example primary roads, then secondary roads, and finally local roads in that order.  */
    AGSServiceAreaPolygonDetailStandard = 1,    /*!< Polygons are generated quickly and are fairly accurate, but quality deteriorates somewhat as you move toward the borders of the service area polygons. Outputting standard-detail polygons may result in islands of unreached network elements, such as roads, being covered. */
    AGSServiceAreaPolygonDetailHigh = 2         /*!< Most detailed polygons. Holes within the polygon may exist; they represent islands of network elements that couldn't be reached due to travel restrictions for example. Expect high-precision polygons to take the longest amount of time to generate. */
};

/** Specifies the direction of travel between facilities and incidents
 @since 100.1
 */
typedef NS_ENUM(NSInteger, AGSTravelDirection)
{
    AGSTravelDirectionFromFacility = 0, /*!< Direction of travel is from facilities to incidents. Fire departments commonly use this setting, since they are concerned with the time it takes to travel from the fire station (facility) to the location of the emergency (incident) */
    AGSTravelDirectionToFacility = 1 /*!< Direction of travel is from incidents to facilities. Retail stores commonly use this setting, since they are concerned with the time it takes the shoppers (incidents) to reach the store (facility) */
};

#pragma mark - Closest Facility Task

/** Determines whether the specified time is departure time or arrival time
 @since 100.1
 */
typedef NS_ENUM(NSInteger, AGSStartTimeUsage)
{
    AGSStartTimeUsageDepartureTime = 0, /*!< Departure time from incident or facility */
    AGSStartTimeUsageArrivalTime = 1 /*!< Arrival time at incident or facility */
};

#pragma mark - Offline Map

/** Indicates the type of parameters object used to take layers offline.
 @since 100.4
 */
typedef NS_ENUM(NSInteger, AGSOfflineMapParametersType) {
    AGSOfflineMapParametersTypeGenerateGeodatabase = 0, /*!< Parameters used to generate a geodatabase */
    AGSOfflineMapParametersTypeExportVectorTiles = 1, /*!< Parameters used for exporting vector tiles */
    AGSOfflineMapParametersTypeExportTileCache = 2, /*!< Parameters used for exporting a tile cache */
    AGSOfflineMapParametersTypeUnknown = -1, /*!< Unknown paramters type */
};

/** Indicates whether tables in relationships will contain all rows or can be filtered to a smaller set of related rows.
 @since 100.4
 */
typedef NS_ENUM(NSInteger, AGSDestinationTableRowFilter) {
    AGSDestinationTableRowFilterAll = 0,            /*!< All rows of a table will be take offline */
    AGSDestinationTableRowFilterRelatedOnly = 1     /*!< Where appropriate, a table will be filtered to only related rows when taking the table offline. */
};

#pragma mark - Geodatabase

/** The sync model defines how feature layers in a sync-enabled geodatabase can be synced.
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSSyncModel) {
    AGSSyncModelNone = 0,           /*!< Not a valid value */
    AGSSyncModelGeodatabase = 1,    /*!< Layers within a geodatabase cannot be synchronized independently, the whole geodatabase must be synced. The sync operation and sync direction applies to all the layers in the geodatabase. */
    AGSSyncModelLayer = 2,          /*!< Layers within a geodatabase can be synchronized independently of one another. Any subset of the layers can be synchronized when running the sync operation. Also, each layer can independently choose its sync direction */
};

/** Direction in which changes should be synced
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSSyncDirection) {
    AGSSyncDirectionNone = 0,           /*!< No changes are synced */
    AGSSyncDirectionDownload = 1,       /*!< Only download changes from the service during sync */
    AGSSyncDirectionUpload = 2,         /*!< Only upload changes from the client to the service during sync */
    AGSSyncDirectionBidirectional = 3,  /*!< Both download and upload changes */
};

/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSAttachmentSyncDirection) {
    AGSAttachmentSyncDirectionNone = 0,             /*!< Data may not be uploaded or downloaded */
    AGSAttachmentSyncDirectionUpload = 1,           /*!< Data may only be uploaded to the service, but not downloaded */
    AGSAttachmentSyncDirectionBidirectional = 2,    /*!< Data may either be uploaded or downloaded */
};

/** Options specifying whether or not to include attachments for feature layers when taking a map offline
 @since 100.1
 */
typedef NS_ENUM(NSInteger, AGSReturnLayerAttachmentOption) {
    AGSReturnLayerAttachmentOptionNone = 0,              /*!< Do not include attachments for any feature layers */
    AGSReturnLayerAttachmentOptionAllLayers = 1,         /*!< Include attachments for all feature layers */
    AGSReturnLayerAttachmentOptionReadOnlyLayers = 2,    /*!< Include attachments only for read-only feature layers */
    AGSReturnLayerAttachmentOptionEditableLayers = 3     /*!< Include attachments only for editable feature layers. Editable layers are those that support all the editing capabilities - Create, Update, and Delete. */
};

/** Type of relationship constraint violated by the edit
 @since 100.1
 */
typedef NS_ENUM(NSInteger, AGSRelationshipConstraintViolationType) {
    AGSRelationshipConstraintViolationTypeNone = 0,             /*!<  No constraints violated */
    AGSRelationshipConstraintViolationTypeCardinality = 1,      /*!<  Edit leads to relationship cardinality being violated. */
    AGSRelationshipConstraintViolationTypeOrphaned = 2          /*!<  Edit leads to orphaned feature in the destination table. */
};

#pragma mark - Authentication

/** Supported authentication challenge types.
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSAuthenticationChallengeType) {
    AGSAuthenticationChallengeTypeUsernamePassword = 0,          /*!<  */
    AGSAuthenticationChallengeTypeOAuth,                         /*!<  */
    AGSAuthenticationChallengeTypeClientCertificate,             /*!<  */
    AGSAuthenticationChallengeTypeUntrustedHost,                 /*!<  */
    AGSAuthenticationChallengeTypeUnknown,                       /*!<  */
} ;

/** Error types returned
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSCredentialErrorType) {
    AGSCredentialErrorTypeNone = 0,                 /*!<  */
    AGSCredentialErrorTypeInvalidCredentials,       /*!<  */
    AGSCredentialErrorTypeSSLRequired,              /*!<  */
    AGSCredentialErrorTypeUnknown                   /*!<  */
} ;

#pragma mark - Keychain Item

/** Indicates when a keychain item is accessible.
 @since 100.2
 */
typedef NS_ENUM(NSInteger, AGSKeychainItemAccessible) {
    AGSKeychainItemAccessibleAfterFirstUnlock = 0,                  /*!<  */
    AGSKeychainItemAccessibleAfterFirstUnlockThisDeviceOnly,        /*!<  */
    AGSKeychainItemAccessibleAlways,                                /*!<  */
    AGSKeychainItemAccessibleWhenPasscodeSetThisDeviceOnly,         /*!<  */
    AGSKeychainItemAccessibleAlwaysThisDeviceOnly,                  /*!<  */
    AGSKeychainItemAccessibleWhenUnlocked,                          /*!<  */
    AGSKeychainItemAccessibleWhenUnlockedThisDeviceOnly,            /*!<  */
};

#pragma mark - AGSJob

/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSJobType) {
    AGSJobTypeGenerateGeodatabase = 0,      /*!<  */
    AGSJobTypeSyncGeodatabase = 1,          /*!<  */
    AGSJobTypeExportTileCache = 2,          /*!<  */
    AGSJobTypeEstimateTileCacheSize = 3,    /*!<  */
    AGSJobTypeGeoprocessingJob = 4,         /*!<  */
    AGSJobTypeGenerateOfflineMap = 5,       /*!<  */
    AGSJobTypeOfflineMapSync = 7            /*!<  */
};

/** Status of a job
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSJobStatus) {
    AGSJobStatusNotStarted = 0,             /*!<  */
    AGSJobStatusStarted = 1,                /*!<  */
    AGSJobStatusPaused = 2,                 /*!<  */
    AGSJobStatusSucceeded = 3,              /*!<  */
    AGSJobStatusFailed = 4                  /*!<  */
};

/** Job message severity
 @since 100.4
 */
typedef NS_ENUM(NSInteger, AGSJobMessageSeverity) {
    AGSJobMessageSeverityUnknown = -1,         /*!<  */
    AGSJobMessageSeverityInfo = 0,             /*!<  */
    AGSJobMessageSeverityWarning = 1,          /*!<  */
    AGSJobMessageSeverityError = 2             /*!<  */
};

/** Job message source
 @since 100.4
 */
typedef NS_ENUM(NSInteger, AGSJobMessageSource) {
    AGSJobMessageSourceClient = 0,             /*!<  */
    AGSJobMessageSourceService = 1             /*!<  */
};

/** Defines whether and how filters will be applied to a layer/table when including its data in a geodatabase.
 @since 100.1
 */
typedef NS_ENUM(NSInteger, AGSGenerateLayerQueryOption) {
    AGSGenerateLayerQueryOptionUnknown = -1,    /*!<  */
    AGSGenerateLayerQueryOptionAll = 0,         /*!< All the features from the layer are included regardless of what is specified in `AGSGenerateLayerOption#includeRelated`, `AGSGenerateLayerOption#whereClause`, or `AGSGenerateLayerOption#useGeometry`  */
    AGSGenerateLayerQueryOptionNone = 1,        /*!< No features are included, unless they are related to a feature in another layer in the geodatabase and `AGSGenerateLayerOption#includeRelated` is `YES`. When combined with a sync direction of `AGSAttachmentSyncDirectionUpload` this option can be used for an efficient upload-only work-flow.*/
    AGSGenerateLayerQueryOptionUseFilter = 2    /*!< Only those features are included that satisfy filtering based on `AGSGenerateLayerOption#whereClause` and optionally, the specified extent for the geodatabase (`AGSGenerateGeodatabaseParameters#extent`)  if `AGSGenerateLayerOption#useGeometry` is `YES`  */
};

#pragma mark - AGSScene

/** Visual effect for a scene view's atmosphere
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSAtmosphereEffect) {
    AGSAtmosphereEffectNone = 0,            /*!<  */
    AGSAtmosphereEffectHorizonOnly = 1,     /*!<  */
    AGSAtmosphereEffectRealistic = 2        /*!<  */
};

/** Ambient lighting options for a scene view
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSLightingMode) {
    AGSLightingModeNoLight = 0,             /*!<  */
    AGSLightingModeLight = 1,               /*!<  */
    AGSLightingModeLightAndShadows = 2      /*!<  */
};

/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSSurfacePlacement) {
    AGSSurfacePlacementDraped = 0,          /*!< Altitude is based on the underlying surface elevation. Object's Z value is ignored. */
    AGSSurfacePlacementAbsolute = 1,        /*!< Altitude is based on object's Z value and doesn't take surface elevation into consideration. */
    AGSSurfacePlacementRelative = 2,        /*!< Altitude is based on a combination of object's Z value and the underlying surface elevation */
};

/** The configuration for setting a scene tiling scheme.
 @since 100.2.1
 */
typedef NS_ENUM(NSInteger, AGSSceneViewTilingScheme) {
    AGSSceneViewTilingSchemeGeographic = 0,     /*!< Use a geographic tiling scheme for the tiled layers. */
    AGSSceneViewTilingSchemeWebMercator = 1,    /*!< Use a Web Mercator tiling scheme for tiled layers. */
};

#pragma mark - Raster


/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSScreenLocationVisibility) {
    AGSScreenLocationVisibilityVisible = 0,                /*!<  */
    AGSScreenLocationVisibilityHiddenByBaseSurface = 1,    /*!<  */
    AGSScreenLocationVisibilityHiddenByEarth = 2,          /*!<  */
    AGSScreenLocationVisibilityHiddenByElevation = 3,      /*!<  */
    AGSScreenLocationVisibilityNotOnScreen = 4,            /*!<  */
};

#pragma mark - Sketch

/** Specifies what type of geometry is to be created and the manner in which it is created
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSSketchCreationMode) {
    AGSSketchCreationModeUnset = -1,            /*!<  */
    AGSSketchCreationModePoint,                 /*!< Create Point geometry */
    AGSSketchCreationModeMultipoint,            /*!< Create Multipoint geometry incrementally one vertex at a time  */
    AGSSketchCreationModePolyline,              /*!< Create Polyline geometry incrementally one vertex at a time */
    AGSSketchCreationModePolygon,               /*!< Create Polygon geometry incrementally one vertex at a time */
    AGSSketchCreationModeFreehandPolyline,      /*!< Create Polyline geometry using a continuous freehand gesture */
    AGSSketchCreationModeFreehandPolygon,       /*!< Create Polygon geometry using a continuous freehand gesture */
    AGSSketchCreationModeRectangle,             /*!< Create Polygon geometry shaped as a rectangle. Use together with `AGSSketchResizeModeUniform` to create a square */
    AGSSketchCreationModeEllipse,               /*!< Create Polygon geometry shaped as an ellipse. Use together with `AGSSketchResizeModeUniform` to create a circle */
    AGSSketchCreationModeTriangle,              /*!< Create Polygon geometry shaped as a triangle */
    AGSSketchCreationModeArrow,                 /*!< Create Polygon geometry shaped as an arrow */
};

/** Specifies permitted operations on the vertices of the geometry
 @since 100.2
 */
typedef NS_ENUM(NSInteger, AGSSketchVertexEditMode) {
    AGSSketchVertexEditModeInteractionEdit,     /*!< Users can interactively select, add, remove, and move vertices */
    AGSSketchVertexEditModeSelectOnly           /*!< Users can interactively only select vertices. Vertices cannot be added, moved, or removed interactively. */
};

/** Specifies how geometries can be resized
 @since 100.3
 */
typedef NS_ENUM(NSInteger, AGSSketchResizeMode) {
    AGSSketchResizeModeNone,            /*!< Resizing not allowed */
    AGSSketchResizeModeStretch,         /*!< Resizing is free-form and may change the aspect-ratio of the geometry */
    AGSSketchResizeModeUniform          /*!< Resizing is proportional, preserving the aspect-ratio of the geometry */
};

#pragma mark - Geoprocessing

/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSGeoprocessingParameterType) {
    AGSGeoprocessingParameterTypeBoolean = 0,       /*!<  */
    AGSGeoprocessingParameterTypeDataFile = 1,      /*!<  */
    AGSGeoprocessingParameterTypeDate = 2,          /*!<  */
    AGSGeoprocessingParameterTypeDouble = 3,        /*!<  */
    AGSGeoprocessingParameterTypeFeatures = 4,      /*!<  */
    AGSGeoprocessingParameterTypeLinearUnit = 5,    /*!<  */
    AGSGeoprocessingParameterTypeLong = 6,          /*!<  */
    AGSGeoprocessingParameterTypeMultiValue = 7,    /*!<  */
    AGSGeoprocessingParameterTypeRaster = 8,        /*!<  */
    AGSGeoprocessingParameterTypeString = 9,        /*!<  */
    AGSGeoprocessingParameterTypeUnknown = 10,      /*!<  */
};

/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSGeoprocessingLinearUnits) {
    AGSGeoprocessingLinearUnitsCentimeter = 0,      /*!<  */
    AGSGeoprocessingLinearUnitsDecimeter = 1,       /*!<  */
    AGSGeoprocessingLinearUnitsKilometer = 2,       /*!<  */
    AGSGeoprocessingLinearUnitsMeter = 3,           /*!<  */
    AGSGeoprocessingLinearUnitsMillimeter = 4,      /*!<  */
    AGSGeoprocessingLinearUnitsPoint = 5,           /*!<  */
    AGSGeoprocessingLinearUnitsUSNauticalMile = 6,  /*!<  */
    AGSGeoprocessingLinearUnitsUSSurveyFoot = 7,    /*!<  */
    AGSGeoprocessingLinearUnitsUSSurveyInch = 8,    /*!<  */
    AGSGeoprocessingLinearUnitsUSSurveyMile = 9,    /*!<  */
    AGSGeoprocessingLinearUnitsUSSurveyYard = 10,   /*!<  */
    AGSGeoprocessingLinearUnitsUnknown = -1,        /*!<  */
};

/**
 @since 100
 */
typedef NS_ENUM(NSInteger, AGSGeoprocessingExecutionType) {
    AGSGeoprocessingExecutionTypeAsynchronousSubmit = 0,    /*!<  */
    AGSGeoprocessingExecutionTypeSynchronousExecute = 1,    /*!<  */
    AGSGeoprocessingExecutionTypeUnknown = -1               /*!<  */
};

typedef NS_ENUM(NSInteger, AGSGeoprocessingParameterDirection) {
    AGSGeoprocessingParameterDirectionInput = 0,
    AGSGeoprocessingParameterDirectionOutput = 1,
};

#pragma mark - ENC

/**
 @since 100.2
 */
typedef NS_ENUM(NSInteger, AGSENCAreaSymbolizationType)
{
    AGSENCAreaSymbolizationTypePlain = 4,       /*!<  */
    AGSENCAreaSymbolizationTypeSymbolized = 5   /*!<  */
};

/**
 @since 100.2
 */
typedef NS_ENUM(NSInteger, AGSENCColorScheme)
{
    AGSENCColorSchemeDay = 1,   /*!<  */
    AGSENCColorSchemeDusk = 2,  /*!<  */
    AGSENCColorSchemeNight = 3  /*!<  */
};

/**
 @since 100.2
 */
typedef NS_ENUM(NSInteger, AGSENCDisplayDepthUnits)
{
    AGSENCDisplayDepthUnitsMeters = 1,  /*!<  */
    AGSENCDisplayDepthUnitsFeet = 2,    /*!<  */
    AGSENCDisplayDepthUnitsFathoms = 3  /*!<  */
};

/**
 @since 100.2
 */
typedef NS_ENUM(NSInteger, AGSENCPointSymbolizationType)
{
    AGSENCPointSymbolizationTypeSimplified = 2, /*!<  */
    AGSENCPointSymbolizationTypePaperChart = 1  /*!<  */
};

#pragma mark - Scene Analysis

typedef NS_ENUM(NSInteger, AGSLineOfSightTargetVisibility)
{
    AGSLineOfSightTargetVisibilityVisible = 0,
    AGSLineOfSightTargetVisibilityObstructed = 1,
    AGSLineOfSightTargetVisibilityUnknown = 2
};

#pragma mark - KML

/** KML Geometry types
 @since 100.4
 */
typedef NS_ENUM(NSInteger, AGSKMLGeometryType)
{
    AGSKMLGeometryTypePoint = 0,
    AGSKMLGeometryTypePolyline = 1,
    AGSKMLGeometryTypePolygon = 2,
    AGSKMLGeometryTypeModel = 3,
    AGSKMLGeometryTypeUnknown = -1
};

/** KML Altitude modes
 @since 100.4
 */
typedef NS_ENUM(NSInteger, AGSKMLAltitudeMode)
{
    AGSKMLAltitudeModeClampToGround = 0,        /*!< The `<altitude>` value is ignored, and the object will be draped over the ground. */
    AGSKMLAltitudeModeRelativeToGround = 1,     /*!< (default) Interprets the `<altitude>` as a value in meters above the ground. If the point is over water, the `<altitude>` will be interpreted as a value in meters above sea level. */
    AGSKMLAltitudeModeAbsolute = 2,             /*!< Interprets the `<altitude>` as a value in meters above sea level, regardless of the actual terrain elevation beneath the feature. */
    AGSKMLAltitudeModeUnknown = -1              /*!< Unknown altitude mode. */
};

/** KML Viewpoint types
 @since 100.4
 */
typedef NS_ENUM(NSInteger, AGSKMLViewpointType)
{
    AGSKMLViewpointTypeCamera = 0,      /*!< A camera viewpoint defines the position of the camera directly. */
    AGSKMLViewpointTypeLookAt = 1,      /*!< A 'LookAt' viewpoint, positions the camera relative to an object, like an `AGSKMLPlacemark`. For more information about LookAt, including a diagram, see https://developers.google.com/kml/documentation/kmlreference#lookat. */
    AGSKMLViewpointTypeUnknown = -1     /*!< Unknown viewpoint type. */
};

/** KML graphic types.
 @since 100.4
 */
typedef NS_ENUM(NSInteger, AGSKMLGraphicType)
{
    AGSKMLGraphicTypeNone = 0,              /*!<  */
    AGSKMLGraphicTypePoint = 1,             /*!<  */
    AGSKMLGraphicTypePolyline = 2,          /*!<  */
    AGSKMLGraphicTypePolygon = 3,           /*!<  */
    AGSKMLGraphicTypeExtrudedPoint = 4,     /*!<  */
    AGSKMLGraphicTypeExtrudedPolyline = 5,  /*!<  */
    AGSKMLGraphicTypeExtrudedPolygon = 6,   /*!<  */
    AGSKMLGraphicTypeModel = 7,             /*!<  */
    AGSKMLGraphicTypeMultiGeometry = 8,     /*!<  */
    AGSKMLGraphicTypeUnknown = -1           /*!<  */
};

/** Defines how visibility selection should work, enabling either single or multiple
 selection of child nodes of a document, folder, or network link.
 @note Values of 'checkOffOnly' are represented as `#AGSKMLListItemTypeCheck`.
 @since 100.4
 @see [Google's KML reference documentation](https://developers.google.com/kml/documentation/kmlreference#liststyle)
 for more information about list item types.
 */
typedef NS_ENUM(NSInteger, AGSKMLListItemType)
{
    AGSKMLListItemTypeCheck = 0,                /*!< All child nodes can be enabled for display. In a table of contents, nodes should be shown with checkboxes to enable multiple selection. */
    AGSKMLListItemTypeRadioFolder = 1,          /*!< Only one child node can be enabled for display at any one time. In a table of contents, nodes should be shown with radio buttons. When a child node is selected for display, sibling nodes will be hidden automatically. */
    AGSKMLListItemTypeCheckHideChildren = 2,    /*!< All child nodes should be enabled for display, but they should not be shown in the table of contents. */
    AGSKMLListItemTypeUnknown = -1              /*!<  */
};

/** Refresh status of a KML node.
 @since 100.4
 */
typedef NS_ENUM(NSInteger, AGSKMLRefreshStatus)
{
    AGSKMLRefreshStatusNone = 0,            /*!< No status */
    AGSKMLRefreshStatusInProgress = 1,      /*!< Refresh in progress */
    AGSKMLRefreshStatusCompleted = 2,       /*!< Refresh completed */
    AGSKMLRefreshStatusFailed = 3           /*!< Refresh failed */
};

NS_ASSUME_NONNULL_END

