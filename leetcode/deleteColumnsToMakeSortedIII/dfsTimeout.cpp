#include "header.h"

class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int n = A.size(), m = A[0].size();
        int res = m;

        set<int> removed;
        function<void(int)> dfs = [&](int idx)
        {
            if(idx == m - 1)
            {
                res = min(res, (int)removed.size());
                return;
            }
                
            int nextIdx = idx + 1;
            while(nextIdx < m && removed.count(nextIdx)) ++nextIdx;
            if(nextIdx == m)
            {
                res = min(res, (int)removed.size());
                return;
            }

            vector<int> back;

            for(int i = 0; i < n; ++i)
            {
                if(A[i][idx] > A[i][nextIdx])
                {
                    for(int k = (back.empty() ? idx : back.back()); k >= 0; --k)
                    {
                        if(!removed.count(k))
                        {
                            if(A[i][k] <= A[i][nextIdx]) break;
                            else back.emplace_back(k);
                        }
                    }
                }
            }

            if(!back.empty())
            {
                //delete next char that breaks
                removed.insert(nextIdx);
                dfs(idx);
                removed.erase(nextIdx);

                //delete backwards until it no longer breaks
                for(int k : back)
                    removed.insert(k);
                dfs(nextIdx);
                for(int k : back)
                    removed.erase(k);
            }
            else
            {
                dfs(idx + 1);
            }
        };

        dfs(0);

        return res; 
    }
};

int main()
{
    Solution s;
    vector<string> a{"babca","bbazb"};
    cout<<s.minDeletionSize(a)<<endl;
}
