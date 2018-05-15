#include "header.h"

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int n = A.size();
        unordered_map<int, int> sumCnt;
        unordered_map<int, int> sumCnt1;

        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
            {
                ++sumCnt[A[i] + B[j]];
                ++sumCnt1[C[i] + D[j]];
            }

        int res = 0;
        for(const auto& p : sumCnt)
        {
            auto iter = sumCnt1.find(-p.first);
            if(iter != sumCnt1.end())
                res += p.second * iter->second;
        }
        return res;
    }
};

int main()
{
    Solution s;
}
