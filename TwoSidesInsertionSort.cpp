/*
 * test.cpp
 *
 *  Created on: 2014.04.21
 *      Author: Spike
 */

/*eclipse cdt, gcc 4.8.1*/

#include <iostream>
#include <deque>

void print(const std::deque<int>& L) {
	for(auto i: L) {
		std::cout << i << " ";
	}

	std::cout << std::endl;
}


void insertSort(std::deque<int>& L)
{
	int first(0), final(0);
	std::size_t n(L.size());

	std::deque<int> D(n);

	D[0] = L[0];

	for(std::size_t i=1; i<n; ++i) {
		if (L[i] < D[first]) {
			first = (first-1+n)%n;
			D[first] = L[i];
			print(D);
		} else if (L[i] > D[final]) {
			final = (final+1+n)%n;
			D[final] = L[i];
			print(D);
		} else {
			//折半查找
			int low(0), high((final-first)%n);
			int temp(first), end(high);
			while (low <= high) {
				int m = (low + high)/2;
				if (L[i] < D[(m+temp)%n])
					high = m-1;
				else
					low = m+1;
			}
			for (int j=end; j>=high+1; --j) {
				D[(j+temp+1)%n] = D[(j+temp)%n];
			}
			D[(high+temp+1)%n] = L[i];
			final = (final+1+n)%n;
			print(D);
		}
	}

	//复制数组
	for (std::size_t k=0; k<n; k++) {
		L[k] = D[(first+k)%n];
	}
}

int main(void)
{
	std::deque<int> L = {9, 3, 2, 4, 5, 8, 7, 6};
	print(L);
	insertSort(L);
	print(L);
	return 0;
}
