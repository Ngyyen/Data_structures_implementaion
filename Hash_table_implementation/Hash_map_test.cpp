#include <iostream>
#include <vector>
#include "Hash_table.h"
using namespace std;
int main()
{
	Hash_map item(3001);
	item.insert("apple", 15);
	item.insert("grape", 20);
	item.insert("onion", 48);
	item.insert("durian", 25);
	item.insert("durian", 35);
	//cout << item;
	cout << item.access("apple") << endl;
	cout << item.access("grape") << endl;
	cout << item.access("banana") << endl;
	item.remove("apple");
	cout << item;
	return 0;
}