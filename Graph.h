#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

struct Vex
{
	int num;		         // 景点编号
	string name;	// 景点名字
	string desc;	// 景点介绍
};

struct Edge
{
	int vex1, vex2;   //边的两个个顶点
	int weight;  	    //权值
};

//Graph对象，用于存储景区景点图
class Graph {
private:
	vector<vector<int>> adMatrix;	//邻接矩阵
	vector<Vex> vecV;	//顶点数组
	int vexNum = 0;	//顶点个数
public:
	Graph() = default;
	Graph(int);	//初始化图结构(int值随意，用以与合成的默认构造函数区别
	Vex GetVex(int nVex);	//查询指定顶点信息
	vector<Edge> FindEdge(int nVex);	//查询与指定顶点相连的边
	int GetVexnum(void);	//获取当前顶点数
	vector<Edge> FindAllEdge();	//返回所有边
	vector<vector<int>> DFSTraverse(int start);	//返回深度优先搜索到的序列，形如"0123456"
	vector<int> DFSShortestPath(int start);	//返回深度优先搜索得到的最短序列
	vector<Edge> DesignPath();	//返回最小生成树的边集
private:
	void InsertVex(Vex sVex);	//将顶点添加到顶点数组中
	void InsertEdge(Edge sEdge);	//将边保存到邻接矩阵中
	void DFS(vector<vector<int>> &traverse, vector<int> ivec, vector<Vex> used, int id);	//递归的得到深度优先搜索序列
	void DFSS(vector<int> &traverse, vector<int> ivec, vector<Vex> used, int id);	//递归的得到深度优先搜索序列中最短序列
	int LengthTra(vector<int> traverse);	//返回序列的加权长度
	vector<Vex> FindVex(int nVex);	//查询与指定顶点相连的顶点
	bool isIncluded(vector<int> used, int n);	//判断int数组中是否包含n，是-返回true，否-返回false
};
