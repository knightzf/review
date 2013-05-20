// heap_sort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>

void swap(int* a, int* b);
int get_parent(int current);

int _tmain(int argc, _TCHAR* argv[])
{
  int a[] = {4,6,2,4,9,8,1,3, 23,11,55,21,5,7,4};
	//create heap
	int size = sizeof(a)/sizeof(int);
	int* b = new int[size];
	for(int i = 0; i < size; ++i)
	{
		b[i] = a[i];
		if(i != 0) //Not root
		{
			int current = i;
			int parent = get_parent(current);
			while(current != 0)
			{
				if(b[current] > b[parent])
				{
					swap(b + current, b + parent);
					current = parent;
					parent = get_parent(current);
				}
				else
					break;
				
			}
		}
	}

	std::cout<<"Creating heap"<<std::endl;
	for(int i = 0; i < size; ++i)
	{
		std::cout<<b[i]<<"-";
	}
	std::cout<<std::endl;

	//Start to sort
	
	for(int i = 0; i < size - 1; ++i)
	{		
		//Firt sort, swap the first item with the last item
		//it doesn't apply for other cases in the loop
		//since the swap should be at the last step in the loop 
		if (i == 0)
			swap(b, b + size - i - 1);		

		int current = 0;
		int last = size - i - 1;
		while(current * 2 + 2 < last )
		{
			int left = 2*current + 1;
			int right = 2*current + 2;

			int max = std::max(b[left],b[right]);
			if(b[current] < max)
			{
				if(max == b[left])
				{
					swap(b + current, b + left);
					current = left;
				}
				else
				{
					swap(b + current, b + right);
					current = right;
				}
			}
			else
			{
				break;
			}
		}

		//swap after this loop
		if (i != 0)
		swap(b, b + size - i - 1);

	}

	std::cout<<"After sort"<<std::endl;
	for(int i = 0; i < size; ++i)
	{
		std::cout<<b[i]<<"-";
	}
	std::cout<<std::endl;

	getchar();
	return 0;
}

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int get_parent(int current)
{
	int parent = 0;
	if(current%2 == 1)
	{
		parent = current/2;
	}
	else
	{
		parent = (current-1)/2;
	}
	return parent;
}
