#include<iostream>
#include"Graph.h"
using namespace std;

int main()
{
	Graph E("Graphe.txt");
	E.Dijskistra(2);
	return 0;
}