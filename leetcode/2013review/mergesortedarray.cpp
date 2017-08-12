class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(A == NULL || B == NULL)
            return;
            
        if(n == 0 || n < 0 || m < 0)
            return;
            
            
        const int result_size = m + n;
        int C[result_size];
        
        int* p = A;
        int* q = B;
        
        int index = 0;
        
        while(p != A + m && q != B + n)
        {
            if(*p <= *q)
            {
                C[index++] = *p;
                ++p;
            }
            else
            {
                C[index++] = *q;
                ++q;
            }
        }
        
        if(p < A + m)
        {
            while( p != A + m)
            {
                C[index++] = *p;
                ++p;
            }
        }
        else if( q < B + n)
        {
            while ( q != B + n)
            {
                C[index++] = *q;
                q++;
            }
        }
        
        memcpy(A, C, sizeof(int) * (m + n));
        
        
    }
};
