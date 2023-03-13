#include <iostream>
#include <string>
#include <cstring>
using namespace std;

string reverse(const string& str);

int main()
{
	string str;
	getline(cin, str);
	string str2 = reverse(str);
	cout << str2;
	return 0;
}

string reverse(const string& str) {
	size_t n = str.size();
	string str2;
	for (int i = n - 1; i >= 0; --i) {
		str2 += str[i];
	}
	return str2;
}