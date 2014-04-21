/*
 * test.cpp
 *
 *  Created on: 2014.04.18
 *      Author: Spike
 */

/*eclipse cdt, gcc 4.8.1*/

#include <iostream>
#include <deque>

using namespace std;

void BInsertSort(std::deque<int>& L) {
	for (std::size_t i=2; i<L.size(); ++i) {
		L[0] = L[i];
		int low = 1, high = i-1;

		//查找L[0]的位置
		while (low <= high) {
			int m = (low + high)/2;
			if (L[0] < L[m]) high = m-1;
			else low = m+1;
		}

		//把较大的向前移动
		for (int j=i-1; j>=high+1; --j) L[j+1] = L[j];

		L[high+1] = L[0];
	}
}

void print(const std::deque<int>& L) {
	for(std::size_t i=0; i < L.size(); ++i) {
		std::cout << L[i] << " ";
	}
	std::cout << std::endl;
}

int main() {
	std::deque<int> L = {0, 5, 2, 4, 3, 1};
	print(L);
	BInsertSort(L);
	print(L);

	return 0;
}

