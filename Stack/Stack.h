#pragma once
#include"ListeChaine.h"
namespace Algo {
	template <class T>
	class Stack
	{

	public:
		void push(T E)
		{
			inner_stack.push_front(E);
		}
		void pop() {
			inner_stack.Delete_front();
		}
		bool empty() const 
		{
			return inner_stack.isEmpty();
		}
		T top() const
		{
			return inner_stack[0];
		}
		int size() const
		{
			return inner_stack.size();
		}
		void Print() const
		{
			cout << "Stack :";
			inner_stack.Print();
		}
	private:
		Liste<T> inner_stack;
	};
};