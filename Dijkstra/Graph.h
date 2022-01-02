#pragma once
#include<iostream>
#include<vector>
#include <fstream>
#include<map>
#include"NodeE.h"
#include"Vertex.h"
#include"MyPriority_Queue.h"
using namespace std;
using namespace Algo;
class Graph
{
	vector<Vertex<NodeE*>*> G;
	vector<NodeE*> nods;
	NodeE* Get_node(int id);
	NodeE* insert_node(int id);
	vector<NodeE*>& Get_neighbours(NodeE*);
	int lenght_between(NodeE* idSource,NodeE* idDest);
public:
	Graph(string chemin);
	void Dijskistra(int id_source);
};

