#include <exception>
#include <cstdio>

using namespace std;

struct empty_queue : public exception {
	const char* what() const throw () {
		return "Couldn't complete option. Queue is empty";
	}
};

template <class T>
class queue_el {
private:
	queue_el* next;

	T data;

public:
	queue_el() {
		next = nullptr;
	}
	explicit queue_el(const T value) {
		next = nullptr;
		data = value;
	}
	~queue_el() {
		next = nullptr;
	}
	/*
	 * funcs allow you set new value to queue_el object properties
	 */
	void set_next(queue_el* const next_el) {
		next = next_el;
	};
	void set_data(T new_data) {
		data = new_data;
	};

	/*
	 * funcs allow you get value of queue_el object properties
	 */
	queue_el* get_next() {
		return next;
	};
	T get_data() {
		return data;
	};

	/*
	 * funcs set next/prev properties value to 'nullptr'
	 */
	void clr_next() {
		delete this;
		next = nullptr;
	};
};

template <class T>
class queue_like {
private:
	queue_el<T>* front;
	queue_el<T>* back;
	queue_el<T>* temp;

	size_t queue_size;

public:
	queue_like() {
		front = nullptr;
		back = nullptr;
		temp = nullptr;
		queue_size = 0;
	}

	~queue_like() {
		while (queue_size != 0) {
			this->dequeue();
		}
		front = nullptr;
		back = nullptr;
		temp = nullptr;
		queue_size = 0;
	}

	queue_el<T>* get_front() {
		return front;
	}

	queue_el<T>* get_back() {
		return back;
	}

	/*
	 * func adds element to queue
	 */
	void enqueue(T data) {
		temp = new queue_el<T>(data);
		if (queue_size == 0) {
			front = temp;
			back = temp;
			temp = nullptr;
			queue_size++;
			return;
		}
		back->set_next(temp);
		back = back->get_next();

		temp = nullptr;
		queue_size++;
	}

	/*
	 * func removes element from queue and returns its value
	 */
	T dequeue() {
		if (queue_size == 0) {
			throw empty_queue();
		}
		T front_data;
		front_data = front->get_data();
		if (queue_size == 1) {
			front = nullptr;
			back = nullptr;
			temp = nullptr;
			queue_size = 0;
			return front_data;
		}
		temp = front;
		front = front->get_next();
		temp->clr_next();

		temp = nullptr;
		queue_size--;
		return front_data;
	};

	/*
	 * func returns value of first queue element
	 */
	T peek() {
		if (queue_size == 0) {
			throw empty_queue();
		}
		return front->get_data();
	}

	/*
	 * func returns queue size
	 */
	size_t get_size() {
		return queue_size;
	}

};
