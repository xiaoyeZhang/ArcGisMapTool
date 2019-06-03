
##一、加载天地图(TianDiTu2.0)

1.先将TianDiTu2.0目录拷贝到项目中

2.在需要加载天地图的类中引入头文件  #import "TianDiMarco.h".同时也要引入ArcGIS 库#import <ArcGIS/ArcGIS.h>

3.加载天地图

初始化AGSMapView 和 AGSMap
AGSMapView *mapView = [[AGSMapView alloc]init];

AGSMap *map = [[AGSMap alloc] init];

获取天地图资源

TianDiTuLayerInfo *tdtInfo = [[TianDiTuLayerInfo alloc] initwithlayerType:TDT_VECTOR SpatialReferenceWKID:TDT_MERCATOR];

TianDiTuLayerInfo *tdtannoInfo = [[TianDiTuLayerInfo alloc] initwithlayerType:TDT_VECTOR LanguageType:TDT_CN SpatialReferenceWKID:TDT_MERCATOR];

TianDiTuLayer *ltl1 = [[TianDiTuLayer alloc] initWithTianDiTuLayerInfo:tdtInfo layerType:TDT_VECTOR];

TianDiTuLayer *ltl2 = [[TianDiTuLayer alloc] initWithTianDiTuLayerInfo:tdtannoInfo layerType:TDT_VECTOR];

NSArray *ltlArr = @[ltl1,ltl2];

[_TDT_typeDic setObject:ltlArr forKey:@(TDT_VECTOR)];//添加到自定义的字典中,用类型区分

将天地图显示在地图上
[map.basemap.baseLayers setArray:[self.TDT_typeDic objectForKey:@(TDT_VECTOR)]];

mapView.map = self.map;

4.其中字段说明

TianDiTuLayerType 有三种类型:  

TDT_VECTOR = 0, ///<天地图矢量服务>
TDT_IMAGE, ///<天地图影像务>
TDT_TERRAIN, ///<天地图地形服务>

TianDiTuLanguageType 有两种类型:  
TDT_CN = 0, ///<天地图中文标注服务>
TDT_EN, ///<天地图英文标注服务>

#二、ArcGis地图功能工具库使用

1.先将GISMapToolUtils目录拷贝到项目中

2.在需要使用地图功能的类中引入头文件  #import "GISMapTool.h"

3.使用工具库
初始化工具类,
GISMapTool *gisMapTool = [[GISMapTool alloc]initWithAGSMapView:self.mapView];//传入当前的地图做为参数

根据需求调用相应的方法,在GISMapTool.h文件中已经做好备注,可自行选择方法调用,设置属性等

4.需要重点注意
在 UIButton+ZXYButton.h"扩展类中对地图操作的类型做了分类.

extern NSString *const ZXYMapViewOperationTypeLine;//画线
extern NSString *const ZXYMapViewOperationTypeArea;//画多边形
extern NSString *const ZXYMapViewOperationTypeAdress;//地点

如果需要删除, 使用- (void)removeObjectForKey:(id)key方法,其中的key就是对应这里的类型

其中画线和画多边形,有且只有一个存在

