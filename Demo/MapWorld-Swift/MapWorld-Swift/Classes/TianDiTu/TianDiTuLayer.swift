//
//  TianDiTuLayer.swift
//  MapWorld-Swift
//
//  Created by zhangxiaoye on 2019/6/10.
//  Copyright © 2019 zhangxiaoye. All rights reserved.
//

import UIKit
import ArcGIS

class TianDiTuLayer: AGSImageTiledLayer {

    var mainType:String!

    init(tiandituLayerInfo:TianDiTuLayerInfo , layerType:TianDiTuLayerType) {
        
        super.init(tileInfo: tiandituLayerInfo.tileInfo, fullExtent:tiandituLayerInfo.fullExtent)
        
        self.tileRequestHandler = {[weak self](tileKey:AGSTileKey) -> () in
            
            let mainURL = tiandituLayerInfo.getTianDiTuServiceURL()
            
            switch (layerType) {
            case .TDT_VECTOR:
                self?.mainType = "TDT_VECTOR";
                break;
            case .TDT_IMAGE:
                self?.mainType = "TDT_IMAGE";
                break;
            default:
                break;
            }
            
            let requestUrl1 = mainURL + "&TILEMATRIX=%ld&TILEROW=%ld&TILECOL=%ld&FORMAT=tiles&tk=7fc4ee9c3af380e16276a965efa3f75c"

            let requestUrl = NSString(format: requestUrl1 as NSString, tileKey.column % 8 , tiandituLayerInfo.servicename , tiandituLayerInfo.layername , tiandituLayerInfo.tilematrixset , (tileKey.level + 1) , tileKey.row , tileKey.column) as String
            
            let aURL = NSURL(string: requestUrl)
            
//            let imageData = NSData(contentsOf: aURL! as URL)
//
//            let img = UIImage(data: imageData! as Data)
//
//            self?.respond(with: tileKey, data: img!.pngData(), error: nil)

            let concurrent = DispatchQueue(label: "mapimage", attributes:.concurrent)

            concurrent.sync {

                let imageData = NSData(contentsOf: aURL! as URL)

                dispatch_queue_main_t.main.async {
                    let img = UIImage(data: imageData! as Data)
                    self?.respond(with: tileKey, data: img!.pngData(), error: nil)

                }
            }
        }
        
    }

}
