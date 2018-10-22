#include "header.h"

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int m = A.size(), n = B.size();
        
        unordered_map<int, vector<int>> map;
        for(int i = 0; i < n; ++i)
        {
            map[B[i]].push_back(i);
        }

        auto findLen = [&](int i, int j)
        {
            int len = 0;
            while(i < m && j < n && A[i] == B[j])
            {
                ++len;
                ++i;
                ++j;
            }
            return len;
        };

        int res = 0;
        for(int i = 0; i < m; ++i)
        {
            for(int j : map[A[i]])
            {
                if(i * j == 0 || A[i - 1] != B[j - 1])
                {
                    res = max(res, findLen(i, j));
                }
            }
        }

        return res;
    }
};

int main() {
    Solution s;
}
