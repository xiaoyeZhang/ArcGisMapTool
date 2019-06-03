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

/** @file AGSLabelDefinition.h */ //Required for Globals API doc

/** @brief Defines how labels should be displayed
 
 An instance of this class specifies how labels should be displayed for features in a layer or for graphics in a graphics overlay within a specific scale range. It can specify -
 
  @li which features/graphics are covered by the definition (by applying the label definition's where-clause)
  @li what text should be displayed, based on the individual attributes of the feature/graphic and the label definition label-expression formula
  @li how the text should appear, using the definition's text symbol
  @li where the text should appear, with respect to its feature/graphic, using the definition's label placement
  @li how to move or avoid other labels and features/graphics that would overlap each label
 
 An instance of  `AGSLabelDefinition` can be constructed from JSON as follows :
 
 ```
 let labelDefinitionString = "{"
 + "  \"allowOverrun\": false,"
 + "  \"deconflictionStrategy\":\"static\","
 + "  \"labelExpressionInfo\": { \"expression\": \"round($feature.length,2) + 'm^2'\"},"
 + "  \"labelPlacement\": \"esriServerPolygonPlacementAlwaysHorizontal\","
 + "  \"lineConnection\": \"none\","
 + "  \"minScale\": 1999,"
 + "  \"maxScale\": 0,"
 + "  \"multiPart\": \"labelLargest\","
 + "  \"name\":\"Building interior code\","
 + "  \"priority\": 15,"
 + "  \"removeDuplicates\": \"featureType\","
 + "  \"removeDuplicatesDistance\": 300,"
 + "  \"repeatLabel\":false,"
 + "  \"repeatLabelDistance\":0,"
 + "  \"stackLabel\": true,"
 + "  \"stackAlignment\": \"dynamic\","
 + "  \"stackRowLength\": 20,"
 + "  \"stackBreakPosition\": \"before\","
 + "  \"symbol\": {\"type\": \"esriTS\", \"color\": [0,78,78,255], \"backgroundColor\": null, \"borderLineColor\": null, \"verticalAlignment\": \"bottom\", \"horizontalAlignment\": \"left\", \"rightToLeft\": false, \"angle\": 0, \"xoffset\": 0, \"yoffset\": 0, \"font\": {\"family\": \"Arial\", \"size\": 12, \"style\": \"normal\", \"weight\": \"bold\", \"decoration\": \"none\"}},"
 + "}"
 
 if let jsonData = labelDefinitionString.data(using: .utf8) {
   do {
     //convert string data into JSON
    let JSON = try JSONSerialization.jsonObject(with: jsonData, options: JSONSerialization.ReadingOptions.mutableContainers)
 
     //convert JSON into AGSLabelDefinition
     let labelDefinition = try AGSLabelDefinition.fromJSON(JSON)
   }
   catch {
    print("Error: \(error.localizedDescription)")
   }
 }
 ```
 
 @since 100.1
 @see `AGSFeatureLayer#labelsEnabled`, `AGSGraphicsOverlay#labelsEnabled`, `AGSArcGISMapImageSublayer#labelsEnabled` to enable labels
 @see `AGSFeatureLayer#labelDefinitions`, `AGSGraphicsOverlay#labelDefinitions`, `AGSArcGISMapImageSublayer#labelDefinitions` to specify label definitions
 */
@interface AGSLabelDefinition : AGSObject <AGSJSONSerializable>
NS_ASSUME_NONNULL_BEGIN

#pragma mark -
#pragma mark initializers

-(instancetype)init __attribute__((unavailable("init is not available.")));

NS_ASSUME_NONNULL_END
@end
