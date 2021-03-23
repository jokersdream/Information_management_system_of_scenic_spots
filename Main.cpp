#include "Tourism.h"

int choice;

inline void menu()
{
	cout << "=====景区信息管理系统=====" << endl;
	cout << "1-创建景区景点图" << endl << "2-查询景点信息" << endl
		<< "3-旅游景点导航" << endl << "4-搜索最短路径" << endl
		<< "5-铺设电路规划" << endl << "0 - 退出";
	cout << endl << "请输入操作编号（0~5）：";
	cin >> choice;
}

int main()
{

	menu();
	Graph graph(1);

	while (choice)
	{
		if (choice < 0 || choice >5) {
			cout << "请输入正确的编号！！！" << endl << endl;
			menu();
			continue;
		}
		cout << endl;

		switch (choice)
		{
		case 1:	CreateGraph(graph);	break;
		case 2: GetSpotInfo(graph);	break;
		case 3: TravelPath(graph); break;
		case 4:	SearchShortestPath(graph); break;
		case 5: MinSpanningTree(graph);	break;

		default:
			break;
		}
		cout << endl << endl;
		menu();
	}

	cout << "感谢您的使用！" << endl;
	return 0;
}


