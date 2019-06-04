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

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import <QuartzCore/QuartzCore.h>
#import <Security/Security.h>
#import <AVFoundation/AVFoundation.h>
#if !TARGET_OS_TV
#import <WebKit/WebKit.h>
#endif

#if TARGET_OS_IPHONE
#import <UIKit/UIKit.h>
#import <MobileCoreServices/MobileCoreServices.h>
#import <AVKit/AVKit.h>
#elif TARGET_OS_MAC && (!TARGET_OS_IPHONE)
#import <AppKit/AppKit.h>
#import <Cocoa/Cocoa.h>
#import <CoreServices/CoreServices.h>
#import <OpenGL/OpenGL.h>
#else
#error Unsupported platform
#endif

#if TARGET_OS_IPHONE && !TARGET_OS_TV
#import <Photos/Photos.h>
#import <SafariServices/SafariServices.h>
#endif

//! Project version number for ArcGIS.
FOUNDATION_EXPORT double ArcGISVersionNumber;

//! Project version string for ArcGIS.
FOUNDATION_EXPORT const unsigned char ArcGISVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <ArcGIS/PublicHeader.h>

#if TARGET_OS_IPHONE && !TARGET_OS_TV
#import <ArcGIS/AGSApplicationDelegate.h>
#endif

//
// Framework

#import <ArcGIS/AGSObject.h>
#import <ArcGIS/AGSJSONSerializable.h>
#import <ArcGIS/AGSJSONSerializableBase.h>
#import <ArcGIS/AGSDefines.h>
#import <ArcGIS/AGSEnumerations.h>
#import <ArcGIS/AGSImage.h>
#import <ArcGIS/AGSColor.h>
#import <ArcGIS/AGSView.h>
#import <ArcGIS/AGSViewController.h>
#import <ArcGIS/AGSFont.h>
#import <ArcGIS/AGSViewControllerBase.h>
#import <ArcGIS/AGSEnumerator.h>

//
// Licensing

#import <ArcGIS/AGSArcGISRuntimeEnvironment.h>
#import <ArcGIS/AGSLicense.h>
#import <ArcGIS/AGSLicenseInfo.h>
#import <ArcGIS/AGSLicenseResult.h>
#import <ArcGIS/AGSExtensionLicense.h>

//
// AGSAdditions

#import <ArcGIS/NSBlockOperation+AGSCancelable.h>
#import <ArcGIS/NSBundle+AGSBundle.h>
#import <ArcGIS/AGSApplication+AGSNetworkActivity.h>
#import <ArcGIS/NSArray+AGSJSONSerializable.h>
#import <ArcGIS/NSValue+AGSEnumSupport.h>

//
// High Level Protocols

#import <ArcGIS/AGSCancelable.h>
#import <ArcGIS/AGSGeoElement.h>

//
// Loadable

#import <ArcGIS/AGSLoadableImage.h>
#import <ArcGIS/AGSLoadableValue.h>
#import <ArcGIS/AGSLoadable.h>
#import <ArcGIS/AGSLoadableBase.h>

//
// Authentication / Request

#import <ArcGIS/AGSCredential.h>
#import <ArcGIS/AGSCredentialCache.h>
#import <ArcGIS/AGSAuthenticationChallenge.h>
#import <ArcGIS/AGSAuthenticationManager.h>
#import <ArcGIS/AGSAuthenticationManagerDelegate.h>
#import <ArcGIS/AGSRequestConfiguration.h>
#import <ArcGIS/AGSKeychainItem.h>
#if !TARGET_OS_TV
#import <ArcGIS/AGSOAuthConfiguration.h>
#endif

//
// Operations
#import <ArcGIS/AGSOperationQueue.h>
#import <ArcGIS/AGSOperation.h>
#import <ArcGIS/AGSObservableOperation.h>
#import <ArcGIS/AGSRequestOperation.h>
#import <ArcGIS/AGSJSONRequestOperation.h>

//
// Geometry

#import <ArcGIS/AGSSpatialReference.h>
#import <ArcGIS/AGSGeometry.h>
#import <ArcGIS/AGSEnvelope.h>
#import <ArcGIS/AGSMultipoint.h>
#import <ArcGIS/AGSPoint.h>
#import <ArcGIS/AGSMultipart.h>
#import <ArcGIS/AGSPointCollection.h>
#import <ArcGIS/AGSMutablePointCollection.h>
#import <ArcGIS/AGSPartCollection.h>
#import <ArcGIS/AGSMutablePartCollection.h>
#import <ArcGIS/AGSPolygon.h>
#import <ArcGIS/AGSPolyline.h>
#import <ArcGIS/AGSGeometryBuilder.h>
#import <ArcGIS/AGSPointBuilder.h>
#import <ArcGIS/AGSEnvelopeBuilder.h>
#import <ArcGIS/AGSMultipointBuilder.h>
#import <ArcGIS/AGSMultipartBuilder.h>
#import <ArcGIS/AGSPolylineBuilder.h>
#import <ArcGIS/AGSPolygonBuilder.h>
#import <ArcGIS/AGSGeometryEngine.h>
#import <ArcGIS/AGSProximityResult.h>
#import <ArcGIS/AGSGeodesicSectorParameters.h>
#import <ArcGIS/AGSGeodesicEllipseParameters.h>
#import <ArcGIS/AGSGeodeticDistanceResult.h>
#import <ArcGIS/AGSSegment.h>
#import <ArcGIS/AGSLineSegment.h>
#import <ArcGIS/AGSPart.h>
#import <ArcGIS/AGSMutablePart.h>
#import <ArcGIS/AGSCoordinateFormatter.h>
#import <ArcGIS/AGSDatumTransformation.h>
#import <ArcGIS/AGSGeographicTransformation.h>
#import <ArcGIS/AGSGeographicTransformationStep.h>
#import <ArcGIS/AGSTransformationCatalog.h>

// Unit
#import <ArcGIS/AGSUnit.h>
#import <ArcGIS/AGSLinearUnit.h>
#import <ArcGIS/AGSAngularUnit.h>
#import <ArcGIS/AGSAreaUnit.h>

// Query
#import <ArcGIS/AGSQueryParameters.h>
#import <ArcGIS/AGSOrderBy.h>

//
// Portal

#import <ArcGIS/AGSItem.h>
#import <ArcGIS/AGSLocalItem.h>
#import <ArcGIS/AGSPortal.h>
#import <ArcGIS/AGSPortalFolder.h>
#import <ArcGIS/AGSPortalGroup.h>
#import <ArcGIS/AGSPortalInfo.h>
#import <ArcGIS/AGSPortalItem.h>
#import <ArcGIS/AGSPortalItemComment.h>
#import <ArcGIS/AGSPortalItemContentParameters.h>
#import <ArcGIS/AGSPortalPrivilege.h>
#import <ArcGIS/AGSPortalQueryParameters.h>
#import <ArcGIS/AGSPortalQueryResultSet.h>
#import <ArcGIS/AGSPortalUser.h>
#import <ArcGIS/AGSPortalHelperServices.h>
#import <ArcGIS/AGSItemResourceCache.h>

//
// Popup
#import <ArcGIS/AGSPopup.h>
#import <ArcGIS/AGSPopupField.h>
#import <ArcGIS/AGSPopupDefinition.h>
#import <ArcGIS/AGSPopupMedia.h>
#import <ArcGIS/AGSPopupMediaValue.h>
#import <ArcGIS/AGSPopupRelatedFeaturesDefinition.h>
#import <ArcGIS/AGSPopupRelatedFeaturesSortOrder.h>
#import <ArcGIS/AGSPopupFieldFormat.h>
#import <ArcGIS/AGSPopupManager.h>
#import <ArcGIS/AGSPopupAttachment.h>
#import <ArcGIS/AGSPopupAttachmentManager.h>
#import <ArcGIS/AGSPopupSource.h>
#import <ArcGIS/AGSPopupExpression.h>

//
// Popup View Controller

#if !TARGET_OS_TV

#import <ArcGIS/AGSPopupsViewControllerDelegate.h>
#import <ArcGIS/AGSPopupsViewController.h>
#import <ArcGIS/AGSPopupsViewControllerTheme.h>

#endif

//
// MapView / SceneView

#import <ArcGIS/AGSViewpoint.h>
#import <ArcGIS/AGSOpenGLView.h>
#import <ArcGIS/AGSGeoView.h>
#import <ArcGIS/AGSLayerViewState.h>
#import <ArcGIS/AGSViewLabelProperties.h>
#import <ArcGIS/AGSMapViewInteractionOptions.h>
#import <ArcGIS/AGSMapViewCommon.h>
#import <ArcGIS/AGSMapView.h>
#import <ArcGIS/AGSCallout.h>
#import <ArcGIS/AGSIdentifyGraphicsOverlayResult.h>
#import <ArcGIS/AGSIdentifyLayerResult.h>
#import <ArcGIS/AGSBackgroundGrid.h>
#import <ArcGIS/AGSSceneView.h>
#import <ArcGIS/AGSCamera.h>
#import <ArcGIS/AGSCameraController.h>
#import <ArcGIS/AGSGlobeCameraController.h>
#import <ArcGIS/AGSOrbitGeoElementCameraController.h>
#import <ArcGIS/AGSOrbitLocationCameraController.h>
#import <ArcGIS/AGSLocationToScreenResult.h>
#import <ArcGIS/AGSGrid.h>
#import <ArcGIS/AGSLatitudeLongitudeGrid.h>
#import <ArcGIS/AGSMGRSGrid.h>
#import <ArcGIS/AGSUSNGGrid.h>
#import <ArcGIS/AGSUTMGrid.h>
#import <ArcGIS/AGSSelectionProperties.h>

//
// Location

#import <ArcGIS/AGSLocation.h>
#import <ArcGIS/AGSLocationDataSource.h>
#import <ArcGIS/AGSSimulatedLocationDataSource.h>
#import <ArcGIS/AGSGPXLocationDataSource.h>
#import <ArcGIS/AGSLocationDisplay.h>
#import <ArcGIS/AGSCLLocationDataSource.h>

//
// Map / Scene

#import <ArcGIS/AGSMap.h>
#import <ArcGIS/AGSBasemap.h>
#import <ArcGIS/AGSBookmark.h>
#import <ArcGIS/AGSScene.h>
#import <ArcGIS/AGSLoadSettings.h>

//
// Layers

#import <ArcGIS/AGSLayer.h>
#import <ArcGIS/AGSImageAdjustmentLayer.h>
#import <ArcGIS/AGSImageTiledLayer.h>
#import <ArcGIS/AGSServiceImageTiledLayer.h>
#import <ArcGIS/AGSArcGISMapImageLayer.h>
#import <ArcGIS/AGSArcGISTiledLayer.h>
#import <ArcGIS/AGSTileCache.h>
#import <ArcGIS/AGSArcGISSublayer.h>
#import <ArcGIS/AGSArcGISMapImageSublayer.h>
#import <ArcGIS/AGSArcGISTiledSublayer.h>
#import <ArcGIS/AGSLegendInfo.h>
#import <ArcGIS/AGSArcGISMapServiceInfo.h>
#import <ArcGIS/AGSArcGISMapServiceSublayerInfo.h>
#import <ArcGIS/AGSArcGISMapServiceCapabilities.h>
#import <ArcGIS/AGSUnknownLayer.h>
#import <ArcGIS/AGSUnsupportedLayer.h>
#import <ArcGIS/AGSArcGISVectorTiledLayer.h>
#import <ArcGIS/AGSVectorTileCache.h>
#import <ArcGIS/AGSVectorTileSourceInfo.h>
#import <ArcGIS/AGSVectorTileStyle.h>
#import <ArcGIS/AGSArcGISSceneLayer.h>
#import <ArcGIS/AGSRasterLayer.h>
#import <ArcGIS/AGSElevationSource.h>
#import <ArcGIS/AGSRasterElevationSource.h>
#import <ArcGIS/AGSArcGISTiledElevationSource.h>
#import <ArcGIS/AGSSurface.h>
#import <ArcGIS/AGSOpenStreetMapLayer.h>
#import <ArcGIS/AGSBingMapsLayer.h>
#import <ArcGIS/AGSSublayerSource.h>
#import <ArcGIS/AGSMapSublayerSource.h>
#import <ArcGIS/AGSTableSublayerSource.h>
#import <ArcGIS/AGSTableJoinSublayerSource.h>
#import <ArcGIS/AGSTableQuerySublayerSource.h>
#import <ArcGIS/AGSRasterSublayerSource.h>
#import <ArcGIS/AGSWebTiledLayer.h>
#import <ArcGIS/AGSRelationshipInfo.h>
#import <ArcGIS/AGSLabelDefinition.h>

// Shapefile
#import <ArcGIS/AGSShapefileFeatureTable.h>
#import <ArcGIS/AGSShapefileInfo.h>

// WMS
#import <ArcGIS/AGSWMSFeature.h>
#import <ArcGIS/AGSWMSLayer.h>
#import <ArcGIS/AGSWMSLayerInfo.h>
#import <ArcGIS/AGSWMSService.h>
#import <ArcGIS/AGSWMSServiceInfo.h>
#import <ArcGIS/AGSWMSSublayer.h>

// WMTS
#import <ArcGIS/AGSWMTSLayer.h>
#import <ArcGIS/AGSWMTSLayerInfo.h>
#import <ArcGIS/AGSWMTSService.h>
#import <ArcGIS/AGSWMTSServiceInfo.h>
#import <ArcGIS/AGSWMTSTileMatrix.h>
#import <ArcGIS/AGSWMTSTileMatrixSet.h>

// Graphics
#import <ArcGIS/AGSGraphic.h>
#import <ArcGIS/AGSGraphicsOverlay.h>
#import <ArcGIS/AGSSketchEditor.h>
#import <ArcGIS/AGSSketchEditConfiguration.h>
#import <ArcGIS/AGSSketchStyle.h>
#import <ArcGIS/AGSSketchVertex.h>

// Symbols
#import <ArcGIS/AGSSymbol.h>
#import <ArcGIS/AGSMarkerSymbol.h>
#import <ArcGIS/AGSSimpleMarkerSymbol.h>
#import <ArcGIS/AGSPictureFillSymbol.h>
#import <ArcGIS/AGSPictureMarkerSymbol.h>
#import <ArcGIS/AGSLineSymbol.h>
#import <ArcGIS/AGSSimpleLineSymbol.h>
#import <ArcGIS/AGSTextSymbol.h>
#import <ArcGIS/AGSFillSymbol.h>
#import <ArcGIS/AGSSimpleFillSymbol.h>
#import <ArcGIS/AGSModelSceneSymbol.h>
#import <ArcGIS/AGSMarkerSceneSymbol.h>
#import <ArcGIS/AGSSimpleMarkerSceneSymbol.h>
#import <ArcGIS/AGSDistanceCompositeSceneSymbol.h>
#import <ArcGIS/AGSDistanceSymbolRange.h>
#import <ArcGIS/AGSUnsupportedSymbol.h>
#import <ArcGIS/AGSCompositeSymbol.h>
#import <ArcGIS/AGSMultilayerSymbol.h>
#import <ArcGIS/AGSMultilayerPointSymbol.h>
#import <ArcGIS/AGSMultilayerPolygonSymbol.h>
#import <ArcGIS/AGSMultilayerPolylineSymbol.h>

// Renderers
#import <ArcGIS/AGSRenderer.h>
#import <ArcGIS/AGSSimpleRenderer.h>
#import <ArcGIS/AGSClassBreak.h>
#import <ArcGIS/AGSClassBreaksRenderer.h>
#import <ArcGIS/AGSUniqueValue.h>
#import <ArcGIS/AGSUniqueValueRenderer.h>
#import <ArcGIS/AGSRendererSceneProperties.h>

// Military Symbology
#import <ArcGIS/AGSSymbolStyle.h>
#import <ArcGIS/AGSDictionarySymbolStyle.h>
#import <ArcGIS/AGSDictionaryRenderer.h>
#import <ArcGIS/AGSSymbolStyleSearchParameters.h>
#import <ArcGIS/AGSSymbolStyleSearchResult.h>

// Layer Supporting Objects
#import <ArcGIS/AGSLayerContent.h>
#import <ArcGIS/AGSTileKey.h>
#import <ArcGIS/AGSTileInfo.h>
#import <ArcGIS/AGSLevelOfDetail.h>
#import <ArcGIS/AGSTimeReference.h>
#import <ArcGIS/AGSLayerTimeInfo.h>
#import <ArcGIS/AGSLayerSceneProperties.h>
#import <ArcGIS/AGSIDInfo.h>
#import <ArcGIS/AGSMapServiceLayerIDInfo.h>
#import <ArcGIS/AGSTimeAware.h>
#import <ArcGIS/AGSTimeExtent.h>
#import <ArcGIS/AGSTimeValue.h>
#import <ArcGIS/AGSServiceTimeInfo.h>

// Feature Layer and supporting objects
#import <ArcGIS/AGSFeatureTable.h>
#import <ArcGIS/AGSFeature.h>
#import <ArcGIS/AGSFeatureLayer.h>
#import <ArcGIS/AGSFeatureQueryResult.h>
#import <ArcGIS/AGSEditResult.h>
#import <ArcGIS/AGSFeatureEditResult.h>
#import <ArcGIS/AGSDomain.h>
#import <ArcGIS/AGSCodedValue.h>
#import <ArcGIS/AGSCodedValueDomain.h>
#import <ArcGIS/AGSInheritedDomain.h>
#import <ArcGIS/AGSRangeDomain.h>
#import <ArcGIS/AGSField.h>
#import <ArcGIS/AGSSyncCapabilities.h>
#import <ArcGIS/AGSFeatureServiceCapabilities.h>
#import <ArcGIS/AGSEditorTrackingInfo.h>
#import <ArcGIS/AGSFeatureTemplate.h>
#import <ArcGIS/AGSFeatureType.h>
#import <ArcGIS/AGSOwnershipBasedAccessControlInfo.h>
#import <ArcGIS/AGSDrawingInfo.h>
#import <ArcGIS/AGSLabelingInfo.h>
#import <ArcGIS/AGSEditFieldsInfo.h>
#import <ArcGIS/AGSArcGISFeatureServiceInfo.h>
#import <ArcGIS/AGSServiceDocumentInfo.h>
#import <ArcGIS/AGSServiceFeatureTable.h>
#import <ArcGIS/AGSArcGISFeatureTable.h>
#import <ArcGIS/AGSArcGISFeatureLayerInfo.h>
#import <ArcGIS/AGSAttachment.h>
#import <ArcGIS/AGSArcGISFeature.h>
#import <ArcGIS/AGSFeatureSet.h>
#import <ArcGIS/AGSFeatureCollectionTable.h>
#import <ArcGIS/AGSFeatureCollection.h>
#import <ArcGIS/AGSFeatureCollectionLayer.h>
#import <ArcGIS/AGSFeatureEnumerator.h>
#import <ArcGIS/AGSFeatureSubtype.h>

// Geodatabase and supporting objects
#import <ArcGIS/AGSGeodatabase.h>
#import <ArcGIS/AGSGeodatabaseFeatureTable.h>
#import <ArcGIS/AGSRelatedFeatureQueryResult.h>
#import <ArcGIS/AGSRelatedQueryParameters.h>
#import <ArcGIS/AGSStatisticsQueryParameters.h>
#import <ArcGIS/AGSStatisticDefinition.h>
#import <ArcGIS/AGSStatisticsQueryResult.h>
#import <ArcGIS/AGSStatisticRecord.h>
#import <ArcGIS/AGSStatisticRecordEnumerator.h>

// Mobile Map Package
#import <ArcGIS/AGSMobileMapPackage.h>
#import <ArcGIS/AGSTransportationNetworkDataset.h>
#import <ArcGIS/AGSMobileBasemapLayer.h>
#import <ArcGIS/AGSGeodatabaseDataset.h>

// GeoPackage
#import <ArcGIS/AGSGeoPackage.h>
#import <ArcGIS/AGSGeoPackageRaster.h>
#import <ArcGIS/AGSGeoPackageFeatureTable.h>

// Raster
#import <ArcGIS/AGSRaster.h>
#import <ArcGIS/AGSBaseStretchRenderer.h>
#import <ArcGIS/AGSBlendRenderer.h>
#import <ArcGIS/AGSColormapRenderer.h>
#import <ArcGIS/AGSHeatmapRenderer.h>
#import <ArcGIS/AGSHillshadeRenderer.h>
#import <ArcGIS/AGSRasterRenderer.h>
#import <ArcGIS/AGSRGBRenderer.h>
#import <ArcGIS/AGSStretchRenderer.h>
#import <ArcGIS/AGSRasterFunction.h>
#import <ArcGIS/AGSRasterFunctionArguments.h>
#import <ArcGIS/AGSAddRastersParameters.h>
#import <ArcGIS/AGSFrameCameraAddRastersParameters.h>
#import <ArcGIS/AGSStretchParameters.h>
#import <ArcGIS/AGSHistogramEqualizationStretchParameters.h>
#import <ArcGIS/AGSMinMaxStretchParameters.h>
#import <ArcGIS/AGSPercentClipStretchParameters.h>
#import <ArcGIS/AGSStandardDeviationStretchParameters.h>
#import <ArcGIS/AGSMosaicDatasetRaster.h>
#import <ArcGIS/AGSColorRamp.h>
#import <ArcGIS/AGSColormap.h>
#import <ArcGIS/AGSImageServiceRaster.h>
#import <ArcGIS/AGSArcGISImageServiceInfo.h>
#import <ArcGIS/AGSRenderingRule.h>
#import <ArcGIS/AGSRenderingRuleInfo.h>

// KML
#import <ArcGIS/AGSKMLContainer.h>
#import <ArcGIS/AGSKMLDataset.h>
#import <ArcGIS/AGSKMLDocument.h>
#import <ArcGIS/AGSKMLFolder.h>
#import <ArcGIS/AGSKMLGeometry.h>
#import <ArcGIS/AGSKMLGroundOverlay.h>
#import <ArcGIS/AGSKMLLayer.h>
#import <ArcGIS/AGSKMLNetworkLink.h>
#import <ArcGIS/AGSKMLNode.h>
#import <ArcGIS/AGSKMLPhotoOverlay.h>
#import <ArcGIS/AGSKMLPlacemark.h>
#import <ArcGIS/AGSKMLScreenOverlay.h>
#import <ArcGIS/AGSKMLTour.h>
#import <ArcGIS/AGSKMLViewpoint.h>

//
// Tasks

// Route task and supporting objects
#import <ArcGIS/AGSPolygonBarrier.h>
#import <ArcGIS/AGSPointBarrier.h>
#import <ArcGIS/AGSPolylineBarrier.h>
#import <ArcGIS/AGSStop.h>
#import <ArcGIS/AGSSourceObjectPosition.h>
#import <ArcGIS/AGSNetworkLocation.h>
#import <ArcGIS/AGSTravelMode.h>
#import <ArcGIS/AGSDirectionEvent.h>
#import <ArcGIS/AGSDirectionManeuver.h>
#import <ArcGIS/AGSRoute.h>
#import <ArcGIS/AGSRouteResult.h>
#import <ArcGIS/AGSRouteParameters.h>
#import <ArcGIS/AGSRouteTaskInfo.h>
#import <ArcGIS/AGSRouteTask.h>
#import <ArcGIS/AGSCostAttribute.h>
#import <ArcGIS/AGSDirectionMessage.h>
#import <ArcGIS/AGSRestrictionAttribute.h>
#import <ArcGIS/AGSAttributeParameterValue.h>

// Service Area
#import <ArcGIS/AGSServiceAreaFacility.h>
#import <ArcGIS/AGSServiceAreaParameters.h>
#import <ArcGIS/AGSServiceAreaPolygon.h>
#import <ArcGIS/AGSServiceAreaPolyline.h>
#import <ArcGIS/AGSServiceAreaResult.h>
#import <ArcGIS/AGSServiceAreaTask.h>
#import <ArcGIS/AGSServiceAreaTaskInfo.h>

// Closest Facility
#import <ArcGIS/AGSFacility.h>
#import <ArcGIS/AGSIncident.h>
#import <ArcGIS/AGSClosestFacilityParameters.h>
#import <ArcGIS/AGSClosestFacilityTaskInfo.h>
#import <ArcGIS/AGSClosestFacilityRoute.h>
#import <ArcGIS/AGSClosestFacilityResult.h>
#import <ArcGIS/AGSClosestFacilityTask.h>

// Locator task and supporting objects
#import <ArcGIS/AGSGeocodeParameters.h>
#import <ArcGIS/AGSReverseGeocodeParameters.h>
#import <ArcGIS/AGSSuggestParameters.h>
#import <ArcGIS/AGSSuggestResult.h>
#import <ArcGIS/AGSGeocodeResult.h>
#import <ArcGIS/AGSLocatorInfo.h>
#import <ArcGIS/AGSLocatorTask.h>
#import <ArcGIS/AGSLocatorAttribute.h>

// Geodatabase Sync Task
#import <ArcGIS/AGSGeodatabaseSyncTask.h>
#import <ArcGIS/AGSGenerateGeodatabaseParameters.h>
#import <ArcGIS/AGSSyncLayerOption.h>
#import <ArcGIS/AGSSyncLayerResult.h>
#import <ArcGIS/AGSGenerateLayerOption.h>
#import <ArcGIS/AGSSyncGeodatabaseParameters.h>

// Export Tile Cache Task
#import <ArcGIS/AGSExportTileCacheTask.h>
#import <ArcGIS/AGSExportTileCacheParameters.h>
#import <ArcGIS/AGSEstimateTileCacheSizeResult.h>

// Geoprocessing task and supporting objects
#import <ArcGIS/AGSGeoprocessingParameter.h>
#import <ArcGIS/AGSGeoprocessingParameterInfo.h>
#import <ArcGIS/AGSGeoprocessingBoolean.h>
#import <ArcGIS/AGSGeoprocessingDataFile.h>
#import <ArcGIS/AGSGeoprocessingDate.h>
#import <ArcGIS/AGSGeoprocessingDouble.h>
#import <ArcGIS/AGSGeoprocessingFeatures.h>
#import <ArcGIS/AGSGeoprocessingLinearUnit.h>
#import <ArcGIS/AGSGeoprocessingLong.h>
#import <ArcGIS/AGSGeoprocessingMultiValue.h>
#import <ArcGIS/AGSGeoprocessingRaster.h>
#import <ArcGIS/AGSGeoprocessingString.h>
#import <ArcGIS/AGSGeoprocessingUnknownParameter.h>
#import <ArcGIS/AGSGeoprocessingFeatureSet.h>
#import <ArcGIS/AGSGeoprocessingParameters.h>
#import <ArcGIS/AGSGeoprocessingResult.h>
#import <ArcGIS/AGSGeoprocessingJob.h>
#import <ArcGIS/AGSGeoprocessingTask.h>
#import <ArcGIS/AGSGeoprocessingTaskInfo.h>

// OfflineMap

#import <ArcGIS/AGSOfflineMapTask.h>
#import <ArcGIS/AGSGenerateOfflineMapParameters.h>
#import <ArcGIS/AGSGenerateOfflineMapResult.h>
#import <ArcGIS/AGSOfflineMapItemInfo.h>
#import <ArcGIS/AGSOfflineMapSyncParameters.h>
#import <ArcGIS/AGSOfflineMapSyncResult.h>
#import <ArcGIS/AGSOfflineMapSyncTask.h>
#import <ArcGIS/AGSOfflineCapability.h>
#import <ArcGIS/AGSOfflineMapCapabilities.h>
#import <ArcGIS/AGSOfflineMapSyncLayerResult.h>
#import <ArcGIS/AGSDownloadPreplannedOfflineMapJob.h>
#import <ArcGIS/AGSDownloadPreplannedOfflineMapResult.h>
#import <ArcGIS/AGSPreplannedMapArea.h>
#import <ArcGIS/AGSDownloadPreplannedOfflineMapParameters.h>
#import <ArcGIS/AGSOfflineMapParametersKey.h>
#import <ArcGIS/AGSGenerateOfflineMapParameterOverrides.h>

// ExportVectorTiles
#import <ArcGIS/AGSExportVectorTilesParameters.h>
#import <ArcGIS/AGSExportVectorTilesResult.h>
#import <ArcGIS/AGSExportVectorTilesJob.h>
#import <ArcGIS/AGSExportVectorTilesTask.h>

//
// Jobs

#import <ArcGIS/AGSJob.h>
#import <ArcGIS/AGSEstimateTileCacheSizeJob.h>
#import <ArcGIS/AGSExportTileCacheJob.h>
#import <ArcGIS/AGSGenerateGeodatabaseJob.h>
#import <ArcGIS/AGSSyncGeodatabaseJob.h>
#import <ArcGIS/AGSGenerateOfflineMapJob.h>
#import <ArcGIS/AGSOfflineMapSyncJob.h>
#import <ArcGIS/AGSJobMessage.h>

//
// ENC
#import <ArcGIS/AGSENCCell.h>
#import <ArcGIS/AGSENCDataset.h>
#import <ArcGIS/AGSENCEnvironmentSettings.h>
#import <ArcGIS/AGSENCExchangeSet.h>
#import <ArcGIS/AGSENCFeature.h>
#import <ArcGIS/AGSENCLayer.h>
#import <ArcGIS/AGSENCMarinerSettings.h>
#import <ArcGIS/AGSENCTextGroupVisibilitySettings.h>
#import <ArcGIS/AGSENCViewingGroupSettings.h>
#import <ArcGIS/AGSENCDisplayCategories.h>
#import <ArcGIS/AGSENCDisplaySettings.h>

//
// Analysis

#import <ArcGIS/AGSAnalysisOverlay.h>
#import <ArcGIS/AGSAnalysis.h>

// Viewshed
#import <ArcGIS/AGSViewshed.h>
#import <ArcGIS/AGSLocationViewshed.h>
#import <ArcGIS/AGSGeoElementViewshed.h>

// Line Of Sight
#import <ArcGIS/AGSLineOfSight.h>
#import <ArcGIS/AGSLocationLineOfSight.h>
#import <ArcGIS/AGSGeoElementLineOfSight.h>

// Distance Measurement
#import <ArcGIS/AGSLocationDistanceMeasurement.h>
#import <ArcGIS/AGSDistance.h>

/*******************************************************************/

/** @mainpage Introduction
 @ios
 ArcGIS Runtime SDK for iOS provides an API for developers that allows you to add mapping and GIS functionality to your
 iPhone and iPad applications. You can use the API in both Objective-C & Swift programming languages.
 
 The API provides a MapView to display 2D geographic content, and a SceneView to display 3D content. You can find geopgraphic content from Esri's ArcGIS Online or use content from your own on-premises ArcGIS Enterprise portals. This content is delivered through REST web services. You can also use geopgraphic content that exists locally on the device when the device is offline.
 
 The API is provided as a framework called ArcGIS. Classes and
 functions defined in this framework begin with the prefix AGS. This prefix acts
 as a namespace and prevents naming conflicts with classes defined in your
 application or other frameworks you use.
 
 You need to use a minimum of iOS 11 SDK to build your applications. Also, the applications you build will require a minimum of iOS 10 running on the device.
 
 @section sec1 Setting up your Xcode project using CocoaPods
 
 If you're already using <a target="_blank" href="http://cocoapods.org/">CocoaPods</a>, setting up your project to use ArcGIS is really easy.
 
 - Add <b>pod 'ArcGIS-Runtime-SDK-iOS', '100.4'</b> to your Podfile.
 - Run the command <b>pod install</b> on the Podfile using the Terminal application.
 - Open the project workspace (*.xcworkspace file) and add the <b>#import &lt;ArcGIS/ArcGIS.h&gt;</b>  statement to any class files where you wish to use the API.
 
 
 @section sec2 Setting up your Xcode project manually
 
 Download the SDK from https://developers.arcgis.com/ios . Run the installer, this will install the ArcGIS framework
 under <i> ${HOME}/Library/SDKs/ArcGIS/iOS</i>.
 
 Set the project's <b>Frameworks Search Paths</b> setting to
 include <i>${HOME}/Library/SDKs/ArcGIS/iOS/Frameworks/Static</i> , and the <b>Other Linker Flags</b> setting to include the following entries: <i> -ObjC -framework ArcGIS -l c++ </i>
 
 Add the <i>ArcGIS.bundle</i> file found under <i>${HOME}/Library/SDKs/ArcGIS/iOS/Frameworks/Static/ArcGIS.framework/Versions/Current/Resources</i> to your project. This bundle file contains the resources (images, localized strings, etc) used by the API.
 
 Finally, add the <i>#import &lt;ArcGIS/ArcGIS.h&gt;</i>  statement to your class files where you wish
 to use the API.
 
 @section Third-party Third party libraries
 
 The ArcGIS library depends upon and already includes the following third party libraries -
 @li <a target="_blank" href="http://code.google.com/p/core-plot/">core-plot</a>
 
 The functions/classes in these libaries have been renamed/namespaced to avoid conflicts with other versions of the same libraries you may have in your project.
 @endios
 
 @mac
 ArcGIS Runtime SDK for macOS provides an API for developers that allows you to add mapping and GIS functionality to your
 Mac applications. You can use the API in both Objective-C & Swift programming languages.
 
 The API provides a MapView to display 2D geographic content, and a SceneView to display 3D content. You can find geopgraphic content from Esri's ArcGIS Online or use content from your own on-premises ArcGIS Enterprise portals. This content is delivered through REST web services. You can also use geopgraphic content that exists locally on the machine when the machine is offline.
 
 
 The API is provided as a framework called ArcGIS. Classes and functions defined in this framework begin with the prefix AGS. This prefix acts as a namespace and prevents naming conflicts with classes defined in your application or other frameworks you use.
 
 You need to use a minimum of macOS 10.13 SDK to build your applications. Also, the applications you build will require a Mac running a minimum of macOS Sierra (10.12).
 
 @section sec1 Setting up your Xcode project using CocoaPods
 
 If you're already using <a target="_blank" href="http://cocoapods.org/">CocoaPods</a>, setting up your project to use ArcGIS is really easy.
 
 - Add <b>pod 'ArcGIS-Runtime-SDK-macOS', '100.4'</b> to your Podfile.
 - Run the command <b>pod install</b> on the Podfile using the Terminal application.
 - Open the project workspace (*.xcworkspace file) and add the <b>#import &lt;ArcGIS/ArcGIS.h&gt;</b>  statement to any class files where you wish to use the API.
 
 
 @section sec2 Setting up your Xcode project manually
 
 Download the SDK from https://developers.arcgis.com/macos/ . Run the installer, this will install the ArcGIS framework
 under <i> ${HOME}/Library/SDKs/ArcGIS/macOS</i>.
 
 Set the project's <b>Frameworks Search Paths</b> setting to include <i>${HOME}/Library/SDKs/ArcGIS/macOS/Frameworks/Static</i> , and the <b>Other Linker Flags</b> setting to include the following entries: <i> -ObjC -framework ArcGIS -l c++</i>
 
 Finally, you must also add the <i>ArcGIS.bundle</i> file found under <i>${HOME}/Library/SDKs/ArcGIS/macOS/Frameworks/Static/ArcGIS.framework/Resources</i> to your project. This bundle file contains the resources (images, localized strings, etc) used by the API.
 
 @section Third-party Third party libraries
 
 The ArcGIS library depends upon and already includes the following third party libraries -
 @li <a target="_blank" href="http://code.google.com/p/core-plot/">core-plot</a>
 
 The functions/classes in these libraries have been renamed/namespaced to avoid conflicts with other versions of the same libraries you may have in your project.
 
 @endmac
 */

/**  @defgroup licensing
 @brief Functionality that requires Basic or Standard license for production deployment.
 
 This page lists all the APIs that require a __Basic__ or __Standard__ license for production deployment. All remaining APIs not listed here require a __Lite__ license for production deployment.
 No license is required for any APIs in __Developer__ mode for testing.
 */

