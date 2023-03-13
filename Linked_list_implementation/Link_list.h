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


#endif