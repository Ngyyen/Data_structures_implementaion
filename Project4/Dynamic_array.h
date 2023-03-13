#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <iostream>
using namespace std;

class Dynamic_array {
	friend ostream& operator<< (ostream&, const Dynamic_array&);

public:
	Dynamic_array() = default;
	Dynamic_array(size_t ini_size);
	Dynamic_array(initializer_list<int> ini_list);

	size_t get_size() const { return size; }
	size_t get_capacity() const { return capacity; }
	const int& operator[] (size_t index) const { return arr[index]; }
	int& operator[] (size_t index) { return arr[index]; }

	int& access(size_t index);
	const int& access(size_t index) const;
	void push_back(int val);
	void pop_back();
	void insert(int val, size_t index);
	void erase(size_t index);
	
private:
	void extend();
	int* arr = new int[1];
	size_t size = 0;
	size_t capacity = 1;
};

Dynamic_array::Dynamic_array(size_t ini_size) {
	capacity = 2 * ini_size;
	arr = new int[capacity];
	size = ini_size;
}

Dynamic_array::Dynamic_array(initializer_list<int> ini_list) {
	size = ini_list.size();
	capacity = size * 2;
	arr = new int[capacity];
	
	int i = 0;
	for (int val : ini_list) {
		arr[i++] = val;
	}
}

int& Dynamic_array::access(size_t index) {
	if (index >= size) {
		cerr << "Subcription out of range";
	}
	else return arr[index];
}

const int& Dynamic_array::access(size_t index) const {
	if (index >= size) {
		cerr << "Subcription out of range";
	}
	else return arr[index];
}

void Dynamic_array::extend() {
	int* temp = new int[capacity * 2];
	for (int i = 0; i < size; ++i) {
		temp[i] = arr[i];
	}
	delete[] arr; //delete current memory address that arr hold
	capacity = capacity * 2;
	arr = temp; //copy base address of temp to arr;
}

void Dynamic_array::push_back(int val) {
	if (size == capacity) {
		extend();
	}
	arr[size] = val;
	size++;
}

void Dynamic_array::pop_back() {
	arr[size-1] = 0;
	size--;
}

void Dynamic_array::insert(int val, size_t index) {
	if (index<0 || index>size) {
		cerr << "Index out of range";
		return;
	}
	if (size == capacity) {
		extend();
	}
	for (int i = size ; i > index; --i) {
		arr[i] = arr[i-1];
	}
	arr[index] = val;
	size++;
}

void Dynamic_array::erase(size_t index) {
	if (index<0 || index>size) {
		throw runtime_error("Index out of range");
		return;
	}
	for (int i = index; i < size - 1; ++i) {
		arr[i] = arr[i + 1];
	}
	arr[size - 1] = 0;
	size--;
}

ostream& operator<< (ostream& os, const Dynamic_array& dy_arr) {
	for (int i = 0; i < dy_arr.get_size(); ++i) {
		os << dy_arr[i] << " ";
	}
	return os;
}

#endif