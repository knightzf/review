#include "header.h"

class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& A) {
        map<int, int> m;
        for(int n = A.size(), i = n - 1; i >= 0; --i) {
            if(!m.count(A[i])) m[A[i]] = i;
            auto iter = m.find(A[i]);
            if(iter != m.begin()) {
                --iter;
                swap(A[i], A[iter->second]);
                return A;
            }
        }
        return A;
    }
};

int main()
{
    Solution s;
}

