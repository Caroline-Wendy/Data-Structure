/*
 * InsertionSort.cpp
 *
 *  Created on: 2014.4.23
 *      Author: Spike
 */

/*eclipse cdt, gcc 4.8.1*/

#include <iostream>
#include <deque>

using namespace std;

void print(const std::deque<int>& L) {
	for (auto i : L) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
}

void ShellInsert (std::deque<int>& L, int dk) {
	for(std::size_t i=dk; i<L.size(); ++i) {
		if(L[i] < L[i-dk]) {
			int temp = L[i];
			int j;
			for(j=i-dk; j>=0&&(temp<L[j]); j-=dk)
				L[j+dk] = L[j];
			L[j+dk] = temp;
		}
 	}
	std::cout << "dlta " << dk << " : "; print(L);
}

void ShellSort(std::deque<int>& L, std::deque<int> dlta) {
	for(std::size_t k=0; k<dlta.size(); ++k)
		ShellInsert(L, dlta[k]);
}

int main(void) {
	std::deque<int> L = {49, 38, 65, 97, 76, 13, 27, 49, 55, 04};
	std::deque<int> dlta = {5, 3, 1};
	ShellSort(L, dlta);
	print(L);

}
