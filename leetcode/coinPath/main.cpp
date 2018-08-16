#include "header.h"

class Solution {
public:
    vector<int> cheapestJump(vector<int>& A, int B) {
        int n = A.size();
        vector<pair<int, int>> cost(n, make_pair(INT_MAX, -1));
        cost[n - 1] = make_pair(A[n - 1], n + 1);

        for(int i = n - 2; i >= 0; --i)
        {
            if(A[i] != -1)
            {
                for(int j = min(i + B, n - 1); j > i; --j)
                {
                    if(A[j] != -1)
                    {
                        if(cost[j].first + A[i] <= cost[i].first)
                            cost[i] = make_pair(cost[j].first + A[i], j + 1);
                    }
                }
            }
        }

        //for(auto& i : cost)
        //    cout<<i.first<<" "<<i.second<<endl;

        vector<int> res;
        if(cost[0].first != INT_MAX)
        {
            int i = 1;
            while(i != n + 1)
            {
                if(i == -1) return {};
                res.push_back(i);
                i = cost[i - 1].second;
            }
            //reverse(res.begin(), res.end());
        }
        return res;
    }
};

int main() {
    Solution s;
    /*vector<int> a{1,2,4,-1,2};
    s.cheapestJump(a, 2);*/
    vector<int> a{1,2,4,-1,2};
    s.cheapestJump(a, 1);
}
