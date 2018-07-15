#include "header.h"

class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        int n = A.size();

        vector<pair<int, int>> b;
        for(int i = 0; i < n ; ++i)
            b.emplace_back(i, B[i]);
        sort(b.begin(), b.end(), [](const auto& a, const auto& b){
                if(a.second < b.second) return true;
                if(a.second == b.second) return a.first < b.first;
                return false;
             });

        map<int, int> m;
        for(int i = 0; i < n; ++i)
            ++m[A[i]];

        vector<int> res(n, -1);
        for(int i = 0; i < n; ++i)
        {
            auto iter = m.upper_bound(b[i].second);
            if(iter != m.end())
            {
                res[b[i].first] = iter->first;
                --iter->second;
                if(iter->second == 0)
                    m.erase(iter->first);
            }
        }

        for(int i = 0; i < n; ++i)
        {
            if(res[i] == -1)
            {
                res[i] = m.begin()->first;
                --m.begin()->second;
                if(m.begin()->second == 0)
                    m.erase(m.begin());
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    {
        vector<int> a{2, 7, 11, 15};
        vector<int> b{1, 10, 4, 11};
        const auto& r = s.advantageCount(a, b);
        for(int i : r)
            cout<<i<<" ";
        cout<<endl;
    }
    {
        vector<int> a{12,24,8,32};
        vector<int> b{13,25,32,11};
        const auto& r = s.advantageCount(a, b);
        for(int i : r)
            cout<<i<<" ";
        cout<<endl;
    }
}
