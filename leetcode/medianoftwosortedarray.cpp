//THIS SOLUTION IS NOT OPTIMAL
//RUN TIME COMPLEXITY IS LOG(M+N)
//IDEA IS FROM HERE http://leetcode.com/2011/03/median-of-two-sorted-arrays.html
//BUT NOT EXACTLY THE SAME
//A LOT OF SPECIAL CASES, SOME WERE FOUND DURING TESTING USING ONLINE JUDGE
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

double median(int* a, int size)
{
   //assume a is not empty
   if(size%2 == 1)
   {
      return a[(size-1)/2];
   }
   else
   {
      int temp = size / 2;
      return (a[temp - 1] + a[temp])/2.0;
   }
}

void insert_element(int * a, int size, int b, int *c, int size_c)
{
    int begin = 0;
    int end = size -1;
    int middle = size/2;
    
    while(true)
    {
        if(b> a[middle])
        {
            if(end == middle + 1)
            {
                memcpy(c, a, (middle+1) * sizeof(int));
                c[middle+1] = b;
                memcpy(c+middle+2, a+ middle+1, (size - middle - 1) * sizeof(int));
                break;
            }
            begin = middle;
            middle = (begin + end )/2;
        }
        else if(b< a[middle])
        {
            if(begin == middle - 1)
            {
                memcpy(c, a, middle * sizeof(int));
                c[middle] = b;
                memcpy(c + middle + 1, a + middle, (size - middle) * sizeof(int));
                break;
            }
            end = middle;
            middle = (begin + end )/2;
        }
        else
        {
            memcpy(c, a, middle * sizeof(int));
            c[middle] = b;
            memcpy(c + middle + 1, a + middle, (size - middle) * sizeof(int));
            break;
        }
    }
}

double median_binary(int* a, int size, int b)
{
    const int size_c = size + 1;
    int c[size_c ];
    insert_element(a, size, b, c, size_c );
    return median(c, size_c);
}

double median_binary_2(int* a, int size, int b1, int b2)
{
    const int size_c  = size + 1;
    int c[size_c ];
    insert_element(a, size, b1, c, size_c );
    
    const int size_d = size_c + 1;
    int d[size_d ];
    insert_element(c, size_c, b2, d, size_d );
    return  median(d, size_d);
}


double findMedianSortedArrays(int A[], int m, int B[], int n)
{

   if(m == 0 && n != 0)
      return median(B, n);

   if(m != 0 && n == 0)
      return median(A, m);

   if(m == 1 && n == 1)
      return (A[0] + B[0])/2.0;

   if(m == 2 && n == 2)
   {
      return (std::max(A[0], B[0]) + std::min(A[1], B[1]))/2.0;
   }

   if(A[m - 1] <= B[0])
   {
      const int size = m + n;
      int c[size];
      memcpy(c, A, m * sizeof(int));
      memcpy(c + m, B, n * sizeof(int));
      return median(c, size);
   }

   if(B[n - 1] <= A[0])
   {
      const int size = m + n;
      int c[size];
      memcpy(c, B, n * sizeof(int));
      memcpy(c + n, A, m * sizeof(int));
      return median(c, size);
   }
   
   double median_a = median(A, m);
   double median_b = median(B, n);
   if(fabs(median_a - median_b) < .00001)
   {
      return median_a;
   }
   
   int* left_array = median_a < median_b ? A: B;
   int left_size = median_a < median_b ? m: n;
   bool left_even = left_size % 2 == 1? false: true;

   int* right_array = median_a < median_b ? B: A;
   int right_size = median_a < median_b ? n: m;
   bool right_even = right_size % 2 == 1? false: true;

   if(left_size == 1)
   {
      return median_binary(right_array, right_size, left_array[0]);
   }

   if(right_size == 1)
   {
      return median_binary(left_array, left_size, right_array[0]);
   }

   if(left_size == 2)
   {
      return median_binary_2(right_array, right_size, left_array[0], left_array[1]);
   }

   if(right_size == 2)
   {
      return median_binary_2(left_array, left_size, right_array[0], right_array[1]);
   }

   if(left_even == true && right_even == true)
   {
      int remove_size = std::min(left_size/2, right_size/2);
      if(remove_size > 1)
        remove_size -= 1;
      return findMedianSortedArrays(left_array+remove_size, left_size-remove_size, right_array, right_size-remove_size );
   }

   int remove_size = std::min(left_size/2, right_size/2);
   return findMedianSortedArrays(left_array+remove_size, left_size-remove_size, right_array, right_size-remove_size );

}

int main()
{
   int a[] = {1,5,6,7};
   int b[] = {2,3,4,8,9,10};

   std::cout<<findMedianSortedArrays(a,4,b,6)<<std::endl;

   return 0;
}
