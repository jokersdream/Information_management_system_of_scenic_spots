#include "Tourism.h"

void CreateGraph(Graph graph)
{
	cout << "===== ������������ͼ =====" << endl;
	cout << "������Ŀ��" << graph.GetVexnum() << endl;

	cout << "----- ���� -----" << endl;
	int n;
	for (n = 0; n != graph.GetVexnum(); ++n)
		cout << n << " - " << graph.GetVex(n).name << endl;

	cout << "----- �� -----" << endl;
	vector<Edge> edges = graph.FindAllEdge();
	for (n = 0; n != edges.size(); ++n)
		cout << "<v" << edges[n].vex1 << ", v" << edges[n].vex2 << ">  " << edges[n].weight << endl;
}

void GetSpotInfo(Graph graph)
{
	cout << "===== ��ѯ������Ϣ =====" << endl;
	int n;
	for (n = 0; n != graph.GetVexnum(); ++n)
		cout << n << " - " << graph.GetVex(n).name << endl;

	cout << "��������Ҫ��ѯ�ľ����ţ�";
	int choice;
	cin >> choice;
	while (choice < 0 || choice >= graph.GetVexnum()) {
		cout << "��������ȷ�ľ����ţ�";
		cin >> choice;
	}
	cout << graph.GetVex(choice).name << endl << graph.GetVex(choice).desc << endl;

	cout << "----- �ܱ߾��� -----" << endl;
	vector<Edge> edges = graph.FindEdge(choice);
	Vex vex1, vex2;
	for (n = 0; n != edges.size(); ++n) {
		vex1 = graph.GetVex(edges[n].vex1);
		vex2 = graph.GetVex(edges[n].vex2);
		if (vex1.num == choice)
			cout << vex1.name << " -> " << vex2.name << "   " << edges[n].weight << "��" << endl;
		else
			cout << vex2.name << " -> " << vex1.name << "   " << edges[n].weight << "��" << endl;
	}
}

void TravelPath(Graph graph)
{
	cout << "===== ���ξ��㵼�� =====" << endl;
	for (int n = 0; n != graph.GetVexnum(); ++n) {
		cout << n << " - " << graph.GetVex(n).name << endl;
	}

	cout << "��������ʼ���ţ�";
	int choice;
	cin >> choice;
	while (choice < 0 || choice >= graph.GetVexnum()) {
		cout << "��������ȷ����ʼ���ţ�";
		cin >> choice;
	}

	cout << "����·��Ϊ��" << endl;
	vector<vector<int>> vec = graph.DFSTraverse(choice);
	for (unsigned i = 0; i != vec.size(); ++i) {
		cout << "·��" << i + 1 << "��";
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
	cout << "===== �����������·�� =====" << endl;
	for (int n = 0; n != graph.GetVexnum(); ++n) {
		cout << n << " - " << graph.GetVex(n).name << endl;
	}

	cout << "��������ʼ���ţ�";
	int choice;
	cin >> choice;
	while (choice < 0 || choice >= graph.GetVexnum()) {
		cout << "��������ȷ����ʼ���ţ�";
		cin >> choice;
	}

	cout << "����·��Ϊ��\n\t";
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
	cout << "===== �����·�滮 =====" << endl
		 << "��������������֮�������·��" << endl;
	vector<Edge> mst = graph.DesignPath();
	int sum = 0;
	for (auto it = mst.begin(); it != mst.end(); ++it) {
		cout << graph.GetVex(it->vex1).name << " - " << graph.GetVex(it->vex2).name
			<< "\t" << it->weight << "m" << endl;
		sum += it->weight;
	}
	cout << "�����·���ܳ���Ϊ�� " << sum << "m" << endl;
}
