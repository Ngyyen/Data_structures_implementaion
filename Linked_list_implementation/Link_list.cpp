#include <iostream>
#include "Link_list.h"
using namespace std;
int main() {
	Linked_list list;
	list.print();
	list.append(100);
	list.prepend(55);
	list.append(1);
	list.print();
	list.insert(1, 37);
	list.print();
	list.insert(2, 44);
	list.print();
	list.insert(1, 66);
	list.print();
	list.insert(0, 2);
	list.print();
	list.remove(3);
	list.print();
	list.remove(5);
	list.print();
	list.remove(0);
	list.print();
	return 0;
}