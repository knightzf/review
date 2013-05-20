#include <iostream>

using namespace std;

void swap(int* a, int* b)
{
    if(a == NULL || b == NULL || a == b)
        return;

    int temp = *a;
    *a = *b;
    *b = temp;
}

void quicksort(int* a, int size)
{
    if(a == NULL || size == 0 || size == 1)
        return;

    int pivot = a[0];
    swap(&a[0], &a[size-1]);

    int* p = &a[0];
    for(int i = 0; i < size - 1; ++i)
    {
        if(a[i] <= pivot)
        {
            swap(p, &a[i]);
            ++p;
        }
    }

    swap(p, &a[size-1]);

    int left_size = p - a;
    int right_size = size - left_size - 1;

    quicksort(a, left_size);
    quicksort(p+1, right_size);
}

int main()
{
    int a[] = {5, 1, 18, 5, 6, 3, 2, 0};
    int size = sizeof(a)/sizeof(int);
    quicksort(a, size);

    for(int i = 0; i < size; ++i)
    {
        std::cout<<a[i]<<"-";
    }
    std::cout<<std::endl;

    return 0;
}
