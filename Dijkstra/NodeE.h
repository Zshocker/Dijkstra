#pragma once
#include<iostream>
using namespace std;
class NodeE
{
	int id;
	int dist_Source=0;
	bool visited = false;
public:
	NodeE(int id);
	void Set_DistSource(int dis);
	int Get_DistSource();
	bool operator<(const NodeE&);
	bool operator==(const NodeE&);
	bool is_id(int i);
	void visit();
	void Unvisit();
	bool isVisited();
	void print();
	void Print_id();
};

