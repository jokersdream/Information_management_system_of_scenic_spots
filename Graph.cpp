#include "Graph.h"

Graph::Graph(int)
{
	fstream fvex("Vex.txt", ios::in);

	string str;
	fvex >> this->vexNum;	getline(fvex, str);
	vector<vector<int>> temp(vexNum, vector<int>(vexNum, 0));
	adMatrix = temp;

	int n = 0;
	Vex vex;
	while (n != vexNum) {
		fvex >> vex.num;	getline(fvex, str);
		getline(fvex, vex.name);	getline(fvex, vex.desc);
		this->InsertVex(vex);
		++n;
	}
	fvex.close();

	fstream fedge("Edge.txt", ios::in);
	Edge edge;	int cnt = 1;
	while (fedge >> n) {
		if (cnt % 3 == 1)	edge.vex1 = n;
		else if (cnt % 3 == 2)	edge.vex2 = n;
		else { edge.weight = n; this->InsertEdge(edge); }
		++cnt;
	}
	fedge.close();
}

void Graph::InsertVex(Vex vex)
{
	vecV.push_back(vex);
}

void Graph::InsertEdge(Edge edge)
{
	adMatrix[edge.vex1][edge.vex2] = edge.weight;
	adMatrix[edge.vex2][edge.vex1] = edge.weight;
}

Vex Graph::GetVex(int nVex)
{
		return this->vecV[nVex];
}

vector<Edge> Graph::FindEdge(int nVex)
{
	vector<Edge> edges;
	Edge edge;
	for (int i = 0; i != vexNum; ++i) {//search in row
		if (adMatrix[nVex][i] != 0) {
			edge.vex1 = nVex;	edge.vex2 = i;	edge.weight = adMatrix[nVex][i];
			edges.push_back(edge);
		}
	}
	return edges;
}

vector<Vex> Graph::FindVex(int nVex)
{
	vector<Vex> vexs;
	int i;
	for (i = 0; i != vexNum; ++i) //search in row
		if (adMatrix[nVex][i] != 0)
			vexs.push_back(GetVex(i));
	return vexs;
}

bool Graph::isIncluded(vector<int> used, int n)
{
	for (auto a : used)
		if (a == n)	return true;
	return false;
}

int Graph::GetVexnum(void)
{
	return this->vexNum;
}

vector<Edge> Graph::FindAllEdge()
{
	vector<Edge> edges;
	Edge edge;
	int i, j;
	for (i = 0; i != vexNum; ++i) {//search in row
		for (j = i; j != vexNum; ++j) {//search in col
			if (adMatrix[i][j] != 0) {
				edge.vex1 = i;	edge.vex2 = j;	edge.weight = adMatrix[i][j];
				edges.push_back(edge);
			}
		}
	}
	return edges;
}

vector<vector<int>> Graph::DFSTraverse(int start)
{
	vector<vector<int>> traverse;	//store the results
	vector<int> ivec;	//store the temporary result
	vector<Vex> used;	//store the used vex
	
	DFS(traverse, ivec, used, start);

	return traverse;
}

void Graph::DFS(vector<vector<int>>& traverse, vector<int> ivec, vector<Vex> used, int id)
{
	ivec.push_back(id);	//update
	used.push_back(GetVex(id));

	if (ivec.size() == this->vexNum) {	//end this recursion
		traverse.push_back(ivec);
		return;
	}

	vector<Vex> nextV, temp = this->FindVex(id);	//find all nonredundant adjacent vex, store those to nextV
	for (const auto &a : temp) {
		bool flag = true;
		for (const auto &b : used)
			if (a.num == b.num) flag = false;
		if (flag)	nextV.push_back(a);
	}

	if (nextV.empty())	return;	//if no nextV, then end this recursion

	for (const auto &a : nextV)	//recursion
		DFS(traverse, ivec, used, a.num);
}

vector<int> Graph::DFSShortestPath(int start)
{
	vector<int> traverse;	//store the results
	vector<int> ivec;	//store the temporary result
	vector<Vex> used;	//store the used vex

	DFSS(traverse, ivec, used, start);

	return traverse;
}

vector<Edge> Graph::DesignPath()
{
	vector<Edge> mst;	//store the minimum spanning tree
	vector<Edge> wait = FindAllEdge();	//wait for select
	Edge temp;
	for (int i = 0; i != wait.size(); ++i)	//bubble sort
		for (int j = i; j != wait.size(); ++j) {
			if (wait[j].weight < wait[i].weight) {
				temp = wait[i];
				wait[i] = wait[j];
				wait[j] = temp;
			}
		}
	vector<int> used;
	for (auto edge : wait) {
		if (!isIncluded(used, edge.vex1) || !isIncluded(used, edge.vex2)) {
			mst.push_back(edge);
			if (!isIncluded(used, edge.vex1)) used.push_back(edge.vex1);
			if (!isIncluded(used, edge.vex2)) used.push_back(edge.vex2);
		}
	}
	return mst;
}

void Graph::DFSS(vector<int>& traverse, vector<int> ivec, vector<Vex> used, int id)
{
	ivec.push_back(id);	//update
	used.push_back(GetVex(id));

	if (ivec.size() == this->vexNum) {	//end this recursion
		if (traverse.empty() || LengthTra(ivec) < LengthTra(traverse))	traverse = ivec;
		return;
	}

	vector<Vex> nextV, temp = this->FindVex(id);	//find all nonredundant adjacent vex, store those to nextV
	for (const auto &a : temp) {
		bool flag = true;
		for (const auto &b : used)
			if (a.num == b.num) flag = false;
		if (flag)	nextV.push_back(a);
	}

	if (nextV.empty())	return;	//if no nextV, then end this recursion

	for (const auto &a : nextV)	//recursion
		DFSS(traverse, ivec, used, a.num);
}


int Graph::LengthTra(vector<int> traverse)
{
	int length = 0;
	for (unsigned i = 1; i != traverse.size(); ++i)
		length += adMatrix[i][i - 1];
	return length;
}
