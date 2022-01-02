#include "NodeE.h"

NodeE::NodeE(int id)
{
	this->id = id;
}

void NodeE::Set_DistSource(int dis)
{
	this->dist_Source=dis;
}

int NodeE::Get_DistSource()
{
	return dist_Source;
}

bool NodeE::operator<(const NodeE&CS)
{
	return dist_Source<CS.dist_Source;
}

bool NodeE::operator==(const NodeE&E)
{
	return id==E.id;
}

bool NodeE::is_id(int i)
{
	return i==id;
}

void NodeE::visit()
{
	visited = true;
}

void NodeE::Unvisit()
{
	visited = false;
}

bool NodeE::isVisited()
{
	return visited;
}

void NodeE::print()
{
	cout << id << "      " << dist_Source;
}

void NodeE::Print_id()
{
	cout << id;
}
