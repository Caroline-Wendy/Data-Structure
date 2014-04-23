/*
 * test.cpp
 *
 *  Created on: 2014.04.22
 *      Author: Spike
 */

/*eclipse cdt, gcc 4.8.1*/

#include <iostream>
#include <climits>
#include <deque>

using namespace std;

//打印排序的序列
void printSeq(const std::deque<int>& vals, std::deque<int>& ptrs) {
	int t = 0;
	for (std::size_t i=0; i<vals.size(); ++i) {
		t = ptrs[t];
		std::cout << vals[t] << " ";
		if (ptrs[t] == 0) {
			break;
		}
	}
	std::cout << std::endl;
}

//打印数组
void print(const std::deque<int>& L) {
	for (auto i : L) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
}

//表插入排序
void ListInsertSort(const std::deque<int>& vals, std::deque<int>& ptrs) {
	const int length(vals.size());
	ptrs.resize(length);

	ptrs[0] = 1;
	ptrs[1] = 0;

	for (int i=2; i<length; ++i) {
		int t = 0; //从0开始查找
		int pre = 0; //记录前一个指针
		for (int j=0; j<i-1; ++j) {
			t = ptrs[t]; //找到指针的位置
			if (vals[t] > vals[i]) { //小于插到后面
				ptrs[i] = t;
				ptrs[pre] = i;
				break; //终止
			} else if (ptrs[t] == 0) { //末尾, 直接插入前面
				ptrs[i] = 0;
				ptrs[t] = i;
			}
			pre = t; //记录指针
		}

		//测试
		std::cout << "Pointer: "; print(ptrs);
	}
}

//重排记录
void Arrange(std::deque<int>& vals, std::deque<int>& ptrs) {
	const int length(vals.size());
	int t = 0;
	int pre = 0;
	t = ptrs[t];

	for (int i=1; i<length; ++i) {
		while( t<=i && t!=0) { //顺次找到结点
			t = ptrs[t];
		}
		if(t == 0)
			break;

		pre = ptrs[t];

		if (t != i) { //交换值, 交换指针
			int temp = vals[t];
			vals[t] = vals[i];
			vals[i] = temp;

			int temp2 = ptrs[i];
			ptrs[i] = t;
			ptrs[t] = temp2;
		}

		t = pre;
		std::cout << "Pointer: "; print(ptrs);
	}


}

int main(void) {
	std::deque<int> vals = {INT_MAX, 49, 38, 65, 97, 76, 13, 27, 49};
	std::deque<int> ptrs;
	print(vals);
	ListInsertSort(vals, ptrs);
	printSeq(vals, ptrs);

	Arrange(vals, ptrs);
	print(vals);

	return 0;
}
