#include <iostream>
#include "Dynamic_array.h"
using namespace std;

using my_vec = Dynamic_array;

my_vec merge_sort(const my_vec&, const my_vec&);

int main()
{
	my_vec vec1({ 1,4,3,5 }), vec2({ 5,3,4,6 });
	vec1.sort();
	vec2.sort();
	cout<<merge_sort(vec1, vec2);
	return 0;
}

my_vec merge_sort(const my_vec& vec1, const my_vec& vec2) {
	my_vec ret;
	//int val1 = vec1[0], val2 = vec2[0];
	int i = 0, j = 0;
	int n = vec1.get_size(), m = vec2.get_size();
	while(i < n && j < m) {
		if (vec1[i] < vec2[j]) {
			ret.push_back(vec1[i++]);
		}
		else {
			ret.push_back(vec2[j++]);
		}
	}
	if (i == n) {
		for (; j < m; ++j) {
			ret.push_back(vec2[j]);
		}
	}
	else {
		for (; i < n; ++i) {
			ret.push_back(vec1[i]);
		}
	}
	return ret;
}