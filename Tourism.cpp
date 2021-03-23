#include "Tourism.h"

void CreateGraph(Graph graph)
{
	cout << "===== 创建景区景点图 =====" << endl;
	cout << "顶点数目：" << graph.GetVexnum() << endl;

	cout << "----- 顶点 -----" << endl;
	int n;
	for (n = 0; n != graph.GetVexnum(); ++n)
		cout << n << " - " << graph.GetVex(n).name << endl;

	cout << "----- 边 -----" << endl;
	vector<Edge> edges = graph.FindAllEdge();
	for (n = 0; n != edges.size(); ++n)
		cout << "<v" << edges[n].vex1 << ", v" << edges[n].vex2 << ">  " << edges[n].weight << endl;
}

void GetSpotInfo(Graph graph)
{
	cout << "===== 查询景点信息 =====" << endl;
	int n;
	for (n = 0; n != graph.GetVexnum(); ++n)
		cout << n << " - " << graph.GetVex(n).name << endl;

	cout << "请输入想要查询的景点编号：";
	int choice;
	cin >> choice;
	while (choice < 0 || choice >= graph.GetVexnum()) {
		cout << "请输入正确的景点编号：";
		cin >> choice;
	}
	cout << graph.GetVex(choice).name << endl << graph.GetVex(choice).desc << endl;

	cout << "----- 周边景区 -----" << endl;
	vector<Edge> edges = graph.FindEdge(choice);
	Vex vex1, vex2;
	for (n = 0; n != edges.size(); ++n) {
		vex1 = graph.GetVex(edges[n].vex1);
		vex2 = graph.GetVex(edges[n].vex2);
		if (vex1.num == choice)
			cout << vex1.name << " -> " << vex2.name << "   " << edges[n].weight << "米" << endl;
		else
			cout << vex2.name << " -> " << vex1.name << "   " << edges[n].weight << "米" << endl;
	}
}

void TravelPath(Graph graph)
{
	cout << "===== 旅游景点导航 =====" << endl;
	for (int n = 0; n != graph.GetVexnum(); ++n) {
		cout << n << " - " << graph.GetVex(n).name << endl;
	}

	cout << "请输入起始点编号：";
	int choice;
	cin >> choice;
	while (choice < 0 || choice >= graph.GetVexnum()) {
		cout << "请输入正确的起始点编号：";
		cin >> choice;
	}

	cout << "导游路线为：" << endl;
	vector<vector<int>> vec = graph.DFSTraverse(choice);
	for (unsigned i = 0; i != vec.size(); ++i) {
		cout << "路线" << i + 1 << "：";
		for (unsigned j = 0; j != graph.GetVexnum(); ++j) {
			cout << graph.GetVex(vec[i][j]).name;
			if (j != graph.GetVexnum() - 1)
				cout << " -> ";
		}
		cout << endl;
	}
}

void SearchShortestPath(Graph graph)
{
	cout << "===== 搜索最短旅游路径 =====" << endl;
	for (int n = 0; n != graph.GetVexnum(); ++n) {
		cout << n << " - " << graph.GetVex(n).name << endl;
	}

	cout << "请输入起始点编号：";
	int choice;
	cin >> choice;
	while (choice < 0 || choice >= graph.GetVexnum()) {
		cout << "请输入正确的起始点编号：";
		cin >> choice;
	}

	cout << "导游路线为：\n\t";
	vector<int> ivec = graph.DFSShortestPath(choice);
	for (unsigned i = 0; i != ivec.size(); ++i) {
		cout << graph.GetVex(ivec[i]).name;
		if (i != graph.GetVexnum() - 1)
			cout << " -> ";
	}
	cout << endl;
}

void MinSpanningTree(Graph graph)
{
	cout << "===== 铺设电路规划 =====" << endl
		 << "在以下两个景点之间铺设电路：" << endl;
	vector<Edge> mst = graph.DesignPath();
	int sum = 0;
	for (auto it = mst.begin(); it != mst.end(); ++it) {
		cout << graph.GetVex(it->vex1).name << " - " << graph.GetVex(it->vex2).name
			<< "\t" << it->weight << "m" << endl;
		sum += it->weight;
	}
	cout << "铺设电路的总长度为： " << sum << "m" << endl;
}
