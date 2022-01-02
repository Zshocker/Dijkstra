#pragma once
#include"ListeChaine.h"
namespace Algo {
	template<class T>
	class Queue
	{
	private:
		Liste<T> inner_queue;
	public:
		void add(T Elem) 
		{
			inner_queue.push_back(Elem);
		}
		void pop() 
		{
			inner_queue.Delete_front();
		}
		T peek() const
		{
			return inner_queue[0];
		}
		int size()const 
		{
			return inner_queue.size();
		}
		void Print()const
		{
			cout << "Queue : ";
			inner_queue.Print();
		}
	};
}
