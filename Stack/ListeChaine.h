#pragma once
#include<assert.h>
#include<iostream>
using namespace std;
namespace Algo {
	template<class T>
	class Node
	{
	private:
		T data;
		Node* next;
	public:
		Node(T data):data(data)
		{
			//this->data = data;
			this->next = NULL;
		}
		Node* push_front(T E) 
		{
			Node* newNode = new Node(E);
			assert(newNode != 0);
			newNode->next = this;
			return newNode;
		};
		void push_back(T E)
		{
			Node* newNode = new Node(E);
			assert(newNode != 0);
			Node* cou = this;
			while (cou->next)cou = cou->next;
			cou->next = newNode;
		}
		T acces_Head() 
		{
			return data;
		}
		int size(){
			Node* Cour = this;
			int i = 0;
			if (!Cour)return 0;
			while (Cour) {
				i++;
				Cour = Cour->next;
			}
			return i;
		}
		Node* Delete_front() {
			Node* E = this->next;
			this->next = NULL;
			delete this;
			return E;
		}
		Node* Delete_Back() 
		{
			Node* Cour=this;
			if (size()<2) 
			{
				return Delete_front();
			}
			while (Cour->next->next)
			{
				Cour = Cour->next;
			}
			delete Cour->next;
			Cour->next = NULL;
			return this;
		}
		T& operator[](int a) {
			assert(a >= -1 && a < size());
			Node* Cour=this;
			if (a == -1)a = size() - 1;
			for (int i = 0; i < a; i++)
			{
				Cour = Cour->next;
			}
			return Cour->data;
		}
		Node* remove_indice(int id)
		{
			assert(id >= -1 && id < size());
			if (id==0) {
				return Delete_front();
				
			}
			if (id == size() - 1 || id==-1 ) {
				return Delete_Back();
				
			}
			Node* Cour = this;
			for (int i = 0; i < id-1; i++)
			{
				Cour = Cour->next;
			}
			Node* D = Cour->next;
			Cour->next = D->next;
			delete D;
			return this;
		}
		void print_all() 
		{
			Node* Courant=this;
			while (Courant) 
			{
				cout << Courant->data << " -- ";
				Courant = Courant->next;
			}
			cout << endl;
		}
		int get_ind_min() {
			int id = 0;
			int i = 0;
			Node* min= this;
			Node* Courant = this;
			while (Courant)
			{
				if (Courant->data < min->data) {
					min = Courant;
					id = i;
				}
				Courant = Courant->next;
				i++;
			}
			return id;
		}
		~Node()
		{
			/*while (size()>1)
			{
				Delete_Back();
			}*/
		}
	};
	template<class T>
	class Liste 
	{
	private:
		Node<T>* Head;
	public:
		Liste() 
		{
			this->Head = NULL;
		}
		bool isEmpty()const {
			return Head == NULL;
		}
		void Delete_front() 
		{
			if (!isEmpty()) {
				Head=Head->Delete_front();
			}
		}
		void Delete_Back() {
			if (!isEmpty()) {
				Head = Head->Delete_Back();
			}
		}
		void push_back(T var) 
		{
			if (isEmpty()) {
				Head = new Node<T>(var);
				return;
			}
			Head->push_back(var);
		}
		void push_front(T var) 
		{
			if (isEmpty()) {
				Head = new Node<T>(var);
				return;
			}
			Head=Head->push_front(var);
		}
		T& operator[](int a)const
		{
			assert(!isEmpty());
			return Head->operator[](a);
		}
		~Liste()
		{
			if (!isEmpty()) {
				Head = Head->Delete_Back();
			}
		}
		int size()const{
			if (isEmpty())return 0;
			return Head->size();
		}
		void Print() const
		{
			if (!isEmpty())
			{
				Head->print_all();
			}
		}
		int get_ind_min()const 
		{
			if (isEmpty())return -1;
			return Head->get_ind_min();
		}
		void remove_ind(int id) {
			if (isEmpty())return;
			Head=Head->remove_indice(id);
			return;
		}
	};
};

