//
//  TianDiTuLayerInfo.swift
//  MapWorld-Swift
//
//  Created by zhangxiaoye on 2019/6/10.
//  Copyright © 2019 zhangxiaoye. All rights reserved.
//

import UIKit
import ArcGIS

enum TianDiTuLayerType {
    case TDT_VECTOR///<天地图矢量服务>
    case TDT_IMAGE ///<天地图影像务>
    case TDT_TERRAIN ///<天地图地形服务>
}

enum TianDiTuLanguageType {
    case TDT_CN ///<天地图中文标注服务>
    case TDT_EN ///<天地图英文标注服务>
    
}

enum TianDiTuSpatialReferenceType {
    case TDT_MERCATOR ///<天地图墨卡托服务>
    case TDT_2000 ///<天地图2000服务>
    
}

let kURLGetTile = "http://t%ld.tianditu.gov.cn/%@/wmts?service=wmts&request=gettile&version=1.0.0&layer=%@&STYLE=default&tilematrixset=%@"

let tiandituURL = "http://t%ld.tianditu.gov.cn/%@/wmts"

let X_MIN_MERCATOR = -20037508.3427892
let Y_MIN_MERCATOR = -20037508.3427892
let X_MAX_MERCATOR = 20037508.3427892
let Y_MAX_MERCATOR = 20037508.3427892

let X_MIN_2000 = -180.0
let Y_MIN_2000 = -90.0
let X_MAX_2000 = 180.0
let Y_MAX_2000 = 90.0

let _minZoomLevel = 0
let _maxZoomLevel = 18
let tileWidth = 256
let tileHeight = 256
let dpi = 96

let _WebMercator = 102100
let _GCS2000 = 4490

let kTILE_MATRIX_SET_MERCATOR = "w"
let kTILE_MATRIX_SET_2000 = "c"

class TianDiTuLayerInfo: NSObject {

    
    var layername : String! = nil
    var servicename : String! = nil
    var tilematrixset : String! = nil

    
    var sp : AGSSpatialReference!
    var fullExtent : AGSEnvelope!
    var origin : AGSPoint!
    var lods : NSMutableArray!
    var tileInfo : AGSTileInfo!


   public func initwithlayerType(layerType:TianDiTuLayerType, sptype:TianDiTuSpatialReferenceType) -> Self {

        layername = ""

        switch layerType {
        case TianDiTuLayerType.TDT_VECTOR :
            layername = "vec"
            break
        case TianDiTuLayerType.TDT_IMAGE :
            layername = "img"
            break
        case TianDiTuLayerType.TDT_TERRAIN :
            layername = "ter"
            break
        }

        self.setSpatialReference(sptype: sptype)
        tileInfo = self.getTianDiTuLayerInfo()

        return self
    }

    func initwithlayerType(layerType:TianDiTuLayerType, lan:TianDiTuLanguageType ,sptype:TianDiTuSpatialReferenceType) -> TianDiTuLayerInfo {

        self.layername = "";

        switch (layerType) {
        case .TDT_VECTOR:
            switch (lan) {
            case .TDT_CN:
                self.layername = "cva";
                break;
            case .TDT_EN:
                self.layername = "eva";
                break;
            }
            break;
        case .TDT_IMAGE:

            switch (lan) {
            case .TDT_CN:
                self.layername = "cia";
                break;
            case .TDT_EN:
                self.layername = "eia";
                break;
            }
            break;
        case .TDT_TERRAIN:
            self.layername = "cta";
            break;

        }

        self.setSpatialReference(sptype: sptype)
        self.tileInfo = self.getTianDiTuLayerInfo();

        return self

    }
    
    func setSpatialReference(sptype :TianDiTuSpatialReferenceType) {
        
        sp = AGSSpatialReference(wkid: _WebMercator)
        
        lods = NSMutableArray.init()
        
        var _baseScale : Double = 2.958293554545656E8
        var _baseRelu : Double = 78271.51696402048

        
        switch sptype {
        case .TDT_MERCATOR:
            
            sp = AGSSpatialReference(wkid: _WebMercator)
            servicename = layername + "_" + kTILE_MATRIX_SET_MERCATOR
            
            tilematrixset = kTILE_MATRIX_SET_MERCATOR
            
            origin = AGSPoint(x: X_MIN_MERCATOR, y: Y_MAX_MERCATOR, spatialReference: sp)
            
            fullExtent = AGSEnvelope(xMin: X_MIN_MERCATOR, yMin: Y_MIN_MERCATOR, xMax: X_MAX_MERCATOR, yMax: Y_MAX_MERCATOR, spatialReference: sp)
            
            _baseRelu = 78271.51696402048
            
            break
            

        case .TDT_2000:
            
            
            sp = AGSSpatialReference(wkid: _GCS2000)
            servicename = layername + "_" + kTILE_MATRIX_SET_2000
            
            tilematrixset = kTILE_MATRIX_SET_2000
            
            origin = AGSPoint(x: X_MIN_2000, y: Y_MAX_2000, spatialReference: sp)
            
            fullExtent = AGSEnvelope(xMin: X_MIN_2000, yMin: Y_MIN_2000, xMax: X_MAX_2000, yMax: Y_MAX_2000, spatialReference: sp)
            
            _baseRelu = 0.7031249999891485
            
            break
        }
        
        for index in _minZoomLevel..._maxZoomLevel {

            let level = AGSLevelOfDetail(level: index, resolution: _baseRelu, scale: _baseScale)
            
            self.lods.add(level)
            
            _baseRelu = _baseRelu / 2
            _baseScale = _baseScale / 2
        }
        
    }
    
    func getTianDiTuLayerInfo() -> AGSTileInfo {
                
        let tileInfo = AGSTileInfo.init(dpi: dpi, format: .PNG32, levelsOfDetail: lods as! [AGSLevelOfDetail], origin: origin, spatialReference: sp, tileHeight: tileHeight, tileWidth: tileWidth)
        
        return tileInfo;
    }
 
    func getTianDiTuServiceURL() -> String {
        
//        let wmtsURL = String(format: kURLGetTile, self.servicename, self.layername, self.tilematrixset)
        
        return kURLGetTile;
    }
    

    
}
