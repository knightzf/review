#include "header.h"

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        unordered_map<long, set<int>> m;
        int n = A.size();
        for(int i = 0; i < n; ++i)
            m[A[i]].insert(i);

        //indx -> {diff : count} map
        unordered_map<int, unordered_map<long, int>> countMap;
        int res = 0;
        for(int i = 0; i < n - 2; ++i)
        {
            for(int j = i + 1; j < n - 1; ++j)
            {
                long diff = (long)A[j] - A[i];
                int t = impl(A, j, diff, countMap, m) - 1;
                if(t > 0)
                {
                    res += t;
                }
            }
        }
        return res;
    }

    int impl(vector<int>& A, int idx, long diff, unordered_map<int, unordered_map<long, int>>& countMap,
             unordered_map<long, set<int>>& m)
    {
        if(countMap.find(idx) != countMap.end() && countMap[idx].find(diff) != countMap[idx].end())
            return countMap[idx][diff];
        long t = A[idx] + diff;
        if(m.find(t) == m.end() || m[t].upper_bound(idx) == m[t].end())
        {
            countMap[idx][t] = 1;
        }
        else
        {
            int cnt = 1;
            for(auto iter = m[t].upper_bound(idx); iter != m[t].end(); ++iter)
            {
                cnt += impl(A, *iter, diff, countMap, m);
            }
            countMap[idx][t] = cnt;
        }
        return countMap[idx][t];
    }
};

int main()
{
    Solution s;
    vector<int> a{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    std::cout<<s.numberOfArithmeticSlices(a)<<std::endl;
}
