#include <iostream>
#include <string>
#include "Hash_table.h"
using namespace std;

char find_1st_dup(const string&);

int main()
{
	cout << find_1st_dup("abcdcda");
	return 0;
}

char find_1st_dup(const string& s) {
	Hash_map map(100);
	for (char c : s) {
		string key;
		key += c;
		map.insert(key,1);
		if (map.access(key) == 2) {
			return c;
		}
	}
	/*for (char c : s) {
		string key;
		key += c;
		if (map.access(key) == 2) {
			return c;
		}
	}*/
	return '\0';
}