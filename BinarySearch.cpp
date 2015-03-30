// BinarySearch.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

using namespace std;

void showArray(int *p, int len); // 输出数列
void sort(int *p, int len); // 冒泡排序
bool binSearch(int *p, int len, int value); // 二分查找


int _tmain(int argc, _TCHAR* argv[])
{
	int a[10] = {1, 3, 4, 2, 5, 8, 3, 0, 7, 8};
	int len = 10;
	
	cout<<"a:";
	showArray(a, len);
	
	// 二分查找前要先把数列排好序
	sort(a, len);
	cout<<"a(after sort):";
	showArray(a, len);
	
	int value = 3;
	cout<<"search for "<<value<<" ? "<<(binSearch(a, len, value)?"exist":"not found")<<endl;
	
	value = 1;
	cout<<"search for "<<value<<" ? "<<(binSearch(a, len, value)?"exist":"not found")<<endl;
	
	value = 2;
	cout<<"search for "<<value<<" ? "<<(binSearch(a, len, value)?"exist":"not found")<<endl;
	
	value = 10;
	cout<<"search for "<<value<<" ? "<<(binSearch(a, len, value)?"exist":"not found")<<endl;
	
	value = 7;
	cout<<"search for "<<value<<" ? "<<(binSearch(a, len, value)?"exist":"not found")<<endl;
	
	value = 8;
	cout<<"search for "<<value<<" ? "<<(binSearch(a, len, value)?"exist":"not found")<<endl;
	
	value = 9;
	cout<<"search for "<<value<<" ? "<<(binSearch(a, len, value)?"exist":"not found")<<endl;

	return 0;
}

void showArray(int *p, int len)
{
	for(int i=0; i<len; i++)
		cout<<" "<<p[i];
	cout<<endl;
}

void sort(int *p, int len)
{
	for(int i=1; i<len; i++)
	{
		bool flag = false;
		for(int j=0; j<len-i; j++)
		{
			if(p[j] > p[j+1])
			{
				int temp = p[j];
				p[j] = p[j+1];
				p[j+1] = temp;
				flag = true;
			}
		}
		if(flag == false)
			return ;
	}
}

// binary search
// ~
bool binSearch(int *p, int len, int value)
{
	sort(p, len);
	
	int low = 0;
	int high = len -1;
	int mid;
	while(low <= high)
	{
		mid = (low + high) / 2; // 二分，有序数列，取中间值作比较
		if(p[mid] == value)
			return true;
		else if(p[mid] < value) // 大于中间值，目标在大值部分，更新low
			low = mid + 1;
		else // 小于中间值，目标在小值部分，更新high
			high = mid - 1;
	}
	return false;
}
