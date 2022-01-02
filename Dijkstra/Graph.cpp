#include "Graph.h"
NodeE* Graph::Get_node(int id)
{
	for (auto it : nods)
	{
		if (it->is_id(id))return &(*it);
	}
	return NULL;
}
NodeE* Graph::insert_node(int id) {
	NodeE* E = Get_node(id);
	if (E) return E;
	else E= new NodeE(id);
	nods.push_back(E);
	return E;
}

vector<NodeE*>& Graph::Get_neighbours(NodeE*SAS)
{
	vector<NodeE*>* neighbors = new vector<NodeE*>();
	for (auto& it : G)
	{
		NodeE* ED;
		if ((ED = it->Neighbor(SAS))) {
			neighbors->push_back(ED);
		}
	}
	return *neighbors;
}

int Graph::lenght_between(NodeE* idSource, NodeE* idDest)
{
	for (auto& i : G)
	{
		int a;
		if ((a = i->Distance(idSource, idDest)) != infinity) {
			return a;
		}
	}
	return infinity;
}

Graph::Graph(string chemin)
{
	int Sommet, Succ, LEn;
	fstream F;
	char temp;
	if (!F.is_open())F.open(chemin, ios::in);
	do
	{
		if (F.eof())break;
		F >> Sommet >> temp;
		NodeE* E = insert_node(Sommet);
		do
		{
			F >> Succ;
			if (Succ == 0) {
				break;
			}
			NodeE* B = insert_node(Succ);
			F >> temp >> LEn >> temp;
			G.push_back(new Vertex<NodeE*>(E, B, LEn));
		} while (1);
	} while (1);
	F.close();
}

void Graph::Dijskistra(int id_source)
{
	MyPriority_Queue<NodeE&> Q;
	map<NodeE*, NodeE*> prev;
	NodeE* Source = Get_node(id_source);
	assert(Source);
	for (auto iterator : nods)
	{
		iterator->Set_DistSource(infinity);
		prev.insert(make_pair<NodeE*, NodeE*>(&(*iterator), NULL));
		Q.add(*iterator);
	}
	Source->Set_DistSource(0);
	while (!Q.isEmpty())
	{
		NodeE& U = Q.peek();
		Q.pop();
		U.visit();
		vector<NodeE*>& neis = Get_neighbours(&U);
		for (auto it : neis)
		{
			if (!it->isVisited()) 
			{
				int temp =U.Get_DistSource()+ lenght_between(&U, &(*it));
				if (temp < it->Get_DistSource()) {
					it->Set_DistSource(temp);
					prev.at(&(*it)) = &U;
				}
			}
		}
	}
	cout << "Node"<< "   distance"<<"   Chemin"<<endl;
	for (auto& i : nods)
	{
		i->print();
		for (int i = 0; i < 10; i++)
		{
			cout << " ";
		}
		NodeE* Courant = &(*i);
		Courant->Print_id();
		while (true)
		{
			NodeE* Prev=prev.at(Courant);
			if(!Prev) break;
			cout << "<-";
			Prev->Print_id();
			Courant = Prev;
		}
		cout << endl;
	}
}
