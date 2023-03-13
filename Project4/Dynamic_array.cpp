#include <iostream>
#include "Dynamic_array.h"
using namespace std;
int main()
{
	Dynamic_array dy_arr({1,2,3,4,5,6,7});
	Dynamic_array vec;
	vec.push_back(8);
	cout << vec << " " << vec.get_size() << " " << vec.get_capacity() << endl;
	vec.push_back(9);
	cout << vec << " " << vec.get_size() << " " << vec.get_capacity() << endl;
	vec.push_back(10);
	cout << vec << " " << vec.get_size() << " " << vec.get_capacity() << endl;
	vec.push_back(11);
	cout << vec << " " << vec.get_size() << " " << vec.get_capacity() << endl;
	vec.insert(-1, 0);
	cout << vec << " " << vec.get_size() << " " << vec.get_capacity() << endl;
	vec.erase(2);
	cout << vec << " " << vec.get_size() << " " << vec.get_capacity() << endl;
	vec.erase(5);
	return 0;
}