#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

struct Vex
{
	int num;		         // ������
	string name;	// ��������
	string desc;	// �������
};

struct Edge
{
	int vex1, vex2;   //�ߵ�����������
	int weight;  	    //Ȩֵ
};

//Graph�������ڴ洢��������ͼ
class Graph {
private:
	vector<vector<int>> adMatrix;	//�ڽӾ���
	vector<Vex> vecV;	//��������
	int vexNum = 0;	//�������
public:
	Graph() = default;
	Graph(int);	//��ʼ��ͼ�ṹ(intֵ���⣬������ϳɵ�Ĭ�Ϲ��캯������
	Vex GetVex(int nVex);	//��ѯָ��������Ϣ
	vector<Edge> FindEdge(int nVex);	//��ѯ��ָ�����������ı�
	int GetVexnum(void);	//��ȡ��ǰ������
	vector<Edge> FindAllEdge();	//�������б�
	vector<vector<int>> DFSTraverse(int start);	//����������������������У�����"0123456"
	vector<int> DFSShortestPath(int start);	//����������������õ����������
	vector<Edge> DesignPath();	//������С�������ı߼�
private:
	void InsertVex(Vex sVex);	//��������ӵ�����������
	void InsertEdge(Edge sEdge);	//���߱��浽�ڽӾ�����
	void DFS(vector<vector<int>> &traverse, vector<int> ivec, vector<Vex> used, int id);	//�ݹ�ĵõ����������������
	void DFSS(vector<int> &traverse, vector<int> ivec, vector<Vex> used, int id);	//�ݹ�ĵõ�������������������������
	int LengthTra(vector<int> traverse);	//�������еļ�Ȩ����
	vector<Vex> FindVex(int nVex);	//��ѯ��ָ�����������Ķ���
	bool isIncluded(vector<int> used, int n);	//�ж�int�������Ƿ����n����-����true����-����false
};
