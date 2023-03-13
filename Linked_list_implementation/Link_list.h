#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
using namespace std;

class Node {
public:
	Node() = default;
	Node(int data) {
		this->data = data;
		next = NULL;
	}
	int data = 0;
	Node* next = NULL;
};

class Linked_list {
public:
	Linked_list() = default;
	Linked_list(int data) {
		Node* new_node = new Node(data);
		head = new_node;
		tail = new_node;
		size++;
	}
	void append(int data);
	void prepend(int data);
	void insert(int index, int data);
	void remove(int index);
	void print();

	Node* head = NULL;
	Node* tail = NULL;
	size_t size = 0;
};

void Linked_list::append(int data) {
	Node* new_node = new Node(data);
	if (head == NULL) {
		head = new_node;
		tail = new_node;
		size++;
		return;
	}
	tail->next = new_node;
	tail = new_node;
	size++;
}

void Linked_list::prepend(int data) {
	Node* new_node = new Node(data);
	if (head == NULL) {
		head = new_node;
		tail = new_node;
		size++;
		return;
	}
	new_node->next = head;
	head = new_node;
	size++;
}

void Linked_list::insert(int index, int data) {
	if (index == 0) {
		this->prepend(data);
		++size;
		return;
	}
	Node* ite = head;
	int i = 0;
	while (i < index-1) {
		ite = ite->next;
		++i;
	}
	// ite is currently pointed to node before insert location
	Node* new_node = new Node(data);
	new_node->next = ite->next;
	ite->next = new_node;
	++size;
}

void Linked_list::remove(int index) {
	if (index == 0) {
		head = head->next;
		--size;
		return;
	}
	Node* ite = head;
	int i = 0;
	while (i < index - 1) {
		ite = ite->next;
		++i;
	}
	// ite is currently pointed to node before delete location
	ite->next = ite->next->next;
	--size;
}

void Linked_list::print() {
	Node* ite = head;
	while (ite!=NULL) {
		cout << ite->data << "-->";
		ite = ite->next;
	}
	cout << endl;
}

#endif