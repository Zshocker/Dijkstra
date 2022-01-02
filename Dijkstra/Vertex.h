#pragma once
#include<iostream>
#define infinity 30000
template<class T=int>
class Vertex
{
	T nodeDep;
	T nodeArr;
	int Lenght;
public:
	Vertex() {

	}
	Vertex(T nodD, T nodA, int len) {
		nodeDep = nodD;
		nodeArr = nodA;
		Lenght = len;
	}
	bool operator<(const Vertex<T>& A);
	bool is_Dep(T node);
	T Neighbor(T node);
	int Distance(T id1, T id2) 
	{
		if (id1 == nodeDep && id2 == nodeArr) {
			return Lenght;
		}
		else {
			return infinity;
		}
	}
	Vertex<T>& operator=(const Vertex<T>& A);
};
template<class T>
inline bool Vertex<T>::operator<(const Vertex& A)
{
	Lenght < A.Lenght;
}
template<class T>
Vertex<T>& Vertex<T>::operator=(const Vertex<T>& A)
{
	nodeDep = A.nodeDep;
	nodeArr = A.nodeArr;
	Lenght = A.Lenght;
	return *this;
}
template<class T>
T Vertex<T>::Neighbor(T node)
{
	if (is_Dep(node)) 
	{
		return nodeArr;
	}
	return NULL;
}
template<class T>
inline bool Vertex<T>::is_Dep(T node)
{
	return node==nodeDep;
}