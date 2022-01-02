#pragma once
#include"ListeChaine.h"
namespace Algo {
	template<class T>
	class MyPriority_Queue
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
			inner_queue.remove_ind(inner_queue.get_ind_min());
		}
		T& peek()const
		{
			return inner_queue[inner_queue.get_ind_min()];
		}
		int size()const
		{
			return inner_queue.size();
		}
		bool isEmpty() 
		{
			return inner_queue.isEmpty();
		}
	};
}
