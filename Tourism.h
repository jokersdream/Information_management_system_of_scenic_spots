#pragma once
#include "Graph.h"

void CreateGraph(Graph graph);	//读取文件，创建景区景点图。
void GetSpotInfo(Graph graph);	//查询指定景点信息，显示到相邻景点的距离。
void TravelPath(Graph graph);	//实现景点导航功能，将导航路线显示在界面上
void SearchShortestPath(Graph graph);	//搜索最短路径
void MinSpanningTree(Graph graph);	//铺设电路规划，即获得最小生成树