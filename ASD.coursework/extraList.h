#pragma once
#include "List.h"
template<class T>
class extraList
{
	class Node
	{
	private:
		T data;
		Node* next, * prev;
	public:
		Node() : next(nullptr), prev(nullptr) {};

		void set_data(T& data) {
			this->data = data;
		}

		T& get_data() {
			return data;
		}

		Node* get_next() {
			return next;
		}

		void set_next(Node* temp) {
			next = temp;
		}

		void set_prev(Node* temp) {
			prev = temp;
		}
	};

	Node* head, * tail;

	Node* get_node(size_t index)
	{
		if (isEmpty() || (index > get_size() - 1))
		{
			throw out_of_range("Invalid argument");
		}
		else if (index == get_size() - 1)
			return tail;
		else if (index == 0)
			return head;
		else
		{
			Node* temp = head;
			while ((temp) && (index--))
			{
				temp = temp->get_next();
			}
			return temp;
		}
	}
public:
	extraList() : head(nullptr), tail(nullptr) {}

	void push_back(T& data)
	{
		Node* temp = new Node;
		temp->set_data(data);

		if (head)
		{
			temp->set_prev(tail);
			tail->set_next(temp);
			tail = temp;
		}
		else
		{
			head = temp;
			tail = head;
		}
	}

	T& at(size_t index)
	{
		Node* temp;
		temp = get_node(index);
		return temp->get_data();
	}

	size_t get_size()
	{
		Node* temp = head;
		size_t size = 0;
		while (temp)
		{
			size++;
			temp = temp->get_next();
		}
		return size;
	}

	void clear()
	{
		while (head)
		{
			tail = head->get_next();
			delete head;
			head = tail;
		}
	}

	bool isEmpty()
	{
		if (!head)
			return true;
		else
			return false;
	}
};