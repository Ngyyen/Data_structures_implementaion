#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <iostream>
#include <vector>
#include <string>
#include <list>
using namespace std;

class Node {
public:
	Node() = default;
	Node(string key, int value) {
		this->key = key;
		this->value = value;
	}

	string key = "";
	int value = 0;
};

class Hash_map {
	friend ostream& operator<< (ostream&, const Hash_map&);
public:
	Hash_map() = default;
	Hash_map(size_t size) {
		map.resize(ARRAY_SIZE);
	}
	void insert(const string& key, int value);
	int access(const string& key);
	void remove(const string& key);

private:
	static size_t hash_func(const string& key);
	static const int PRIME_CONST = 31;
	static const int ARRAY_SIZE = 20;
	vector<list<Node>> map;

};

size_t Hash_map::hash_func(const string& key) {
	size_t sum = 0;
	for (int i = 0; i < key.length(); i++) {
		sum += (key[i] * (int)pow(PRIME_CONST, i)) % ARRAY_SIZE;
	}
	return sum % ARRAY_SIZE;
}

void Hash_map::insert(const string& key, int value) {
	Node node(key, value);
	size_t index = hash_func(key);
	for (auto node : map[index]) {
		if (node.key == key) {
			return;
		}
	}
	map[index].push_back(node);
}

int Hash_map::access(const string& key) {
	size_t index = hash_func(key);
	for (auto node : map[index]) {
		if (node.key == key) {
			return node.value;
		}
	}
	return -1;
}

void Hash_map::remove(const string& key) {
	size_t index = hash_func(key);
	list<Node>& bucket = map[index];
	auto ite = bucket.begin();
	if (bucket.size() != 0) {
		while(ite!= bucket.end()) {
			if (ite->key == key) {
				ite = bucket.erase(ite);
			}
			else {
				++ite;
			}
		}
	}
}

ostream& operator<< (ostream& os, const Hash_map& item) {
	for (const auto& bucket : item.map) {
		for (const Node& node : bucket) {
			os << node.key << " " << node.value << " ";
		}
		os << endl;
	}
	return os;
}

#endif
