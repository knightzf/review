#include "header.h"

class Solution {
public:
    int numSquarefulPerms(vector<int>& A) {
        int n = A.size();
        unordered_map<int, vector<int>> m;
        for(int i = 0; i < n; ++i)
        {
            for(int j = i + 1; j < n; ++j)
            {
                int x = sqrt(A[i] + A[j]);
                if(x * x == A[i] + A[j])
                {
                    m[i].push_back(j);
                    m[j].push_back(i);
                }
            }
        }

        set<stack<int>> all;
        unordered_set<int> used;
        stack<int> num;
        int res = 0;

        function<void(int)> dfs = [&](int i)
        {
            if(all.count(num)) return;
            all.insert(num);
            if(used.size() == n)
            {
                ++res;
                return;
            }

            for(int j : m[i])
            {
                if(used.count(j) == 0)
                {
                    used.insert(j);
                    num.push(A[j]);
                    dfs(j);
                    used.erase(j);
                    num.pop();
                }
            }
        };

        for(int i = 0; i < n; ++i)
        {
            used.insert(i);
            num.push(A[i]);
            dfs(i);
            used.erase(i);
            num.pop();
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> a{2,2,2,2,2,2,2,2,2,2};
    cout<<s.numSquarefulPerms(a)<<endl;
}
