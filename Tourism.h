#pragma once
#include "Graph.h"

void CreateGraph(Graph graph);	//��ȡ�ļ���������������ͼ��
void GetSpotInfo(Graph graph);	//��ѯָ��������Ϣ����ʾ�����ھ���ľ��롣
void TravelPath(Graph graph);	//ʵ�־��㵼�����ܣ�������·����ʾ�ڽ�����
void SearchShortestPath(Graph graph);	//�������·��
void MinSpanningTree(Graph graph);	//�����·�滮���������С������