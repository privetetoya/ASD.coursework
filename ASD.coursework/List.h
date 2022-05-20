#pragma once
#include <stdexcept>
#include <iostream>
using namespace std;

template<class T>
class List
{
private:
	class Node
	{
	private:
		T data;
		Node* next, * prev;
	public:

		Node() : next(nullptr), prev(nullptr) {};

		void set_data(T data) {
			this->data = data;
		}

		T get_data() {
			return data;
		}

		Node* get_next() {
			return next;
		}

		void set_next(Node* pointer) {
			next = pointer;
		}

		void set_prev(Node* pointer) {
			prev = pointer;
		}

	};

	Node* head, * tail;

	Node* get_pointer(size_t index)
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
	List() : head(nullptr), tail(nullptr) {}

	List(int size, int value) {
		while (size--) {
			push_back(value);
		}
	}

	List(const List<T>& list) {
		head = nullptr;
		tail = nullptr;
		Node* temp = list.head;
		while (temp) {
			push_back(temp->get_data());
			temp = temp->get_next();
		}
	}

	~List()
	{		
		clear();
	}

	void push_back(T data)
	{
		Node* temp = new Node;
		temp->set_data(data);
		if (head){
			temp->set_prev(tail);
			tail->set_next(temp);
			tail = temp;
		}
		else{
			head = temp;
			tail = head;
		}
	}

	T at(size_t index)
	{
		Node* temp;
		temp = get_pointer(index);
		return temp->get_data();
	}

	bool contains(T symb) {
		Node* temp = head;
		while (temp) {
			if (temp->get_data() == symb)
				return true;
			temp = temp->get_next();
		}
		return false;
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

	size_t get_index(T symb) {
		Node* temp = head;
		size_t index = 0;
		while (temp) {
			if (temp->get_data() == symb)
				break;
			temp = temp->get_next();
			index++;
		}
		return index;
	}

	void set(size_t index, T data)
	{
		Node* temp;
		temp = get_pointer(index);
		temp->set_data(data);
	}


	bool isEmpty() {
		return get_size() == false;
	}

	void reset() {
		head = nullptr;
		tail = nullptr;
	}
};