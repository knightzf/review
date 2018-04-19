#include "header.h"

class Solution {
private:
    int n;
    int res;
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        n = A.size();
        vector<int> swapped(n, INT_MAX);
        vector<int> unchange(n, INT_MAX);

        swapped[0] = 1;
        unchange[0] = 0;

        for(int i = 1; i < n; ++i)
        {
            if(A[i] > A[i - 1] && B[i] > B[i - 1])
                unchange[i] = unchange[i - 1];
            if(A[i] > B[i - 1] && B[i] > A[i - 1])
                unchange[i] = min(unchange[i], swapped[i - 1]);

            if(A[i] > B[i - 1] && B[i] > A[i - 1])
                swapped[i] = unchange[i - 1] + 1;
            if(A[i] > A[i - 1] && B[i] > B[i - 1])
                swapped[i] = min(swapped[i], swapped[i - 1] + 1);
        }

        return min(swapped[n - 1], unchange[n - 1]);
    }
};

int main()
{
    Solution s;
    //vector<int> a{1, 3, 5, 4};
    //vector<int> b{1, 2, 3, 7};
    //vector<int> a{3,3,8,9,10};
    //vector<int> b{1,7,4,6,8};
    //vector<int> a{0,4,4,5,9};
    //vector<int> b{0,1,6,8,10};
    //vector<int> a{0,7,8,10,10,11,12,13,19,18};
    //vector<int> b{4,4,5,7,11,14,15,16,17,20};
    vector<int> a{1,8,4,6,7,8,16,18,19,29,25,26,35,31,38,35,37,41,39,43,48,49,46,47,50,52,54,55,63,58,67,63,69,71,74,73,76,77,80,78,79,80,86,87,90,93,95,96,97,100,101,105,106,108,108,109,116,111,119,121,122,124,130,125,126,127,128,140,144,135,148,151,143,154,155,157,160,156,158,159,168,170,163,173,175,176,177,180,177,182,183,184,185,190,191,194,194,195,196,200};
    vector<int> b{7,3,12,14,19,22,24,26,27,21,30,31,28,36,33,39,40,38,42,43,44,45,50,55,56,57,58,61,56,64,60,68,70,71,72,75,74,75,77,81,82,83,81,84,91,93,95,96,99,100,102,103,104,107,113,114,110,118,112,113,114,115,124,132,133,134,135,131,134,145,137,140,152,144,150,151,154,163,165,166,160,161,172,164,168,171,172,173,181,183,184,187,189,191,192,193,195,198,199,197};
    std::cout<<s.minSwap(a, b)<<std::endl;
}