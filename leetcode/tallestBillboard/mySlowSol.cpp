#include "header.h"

class Solution {
public:

    int tallestBillboard(vector<int>& rods) {
        int n = rods.size();        
        int minLen = INT_MAX, sum = 0;
        for(int i = 0; i < n; ++i)
        {
            sum += rods[i];
            minLen = min(minLen, rods[i]);
        }

        for(int i = sum / 2; i >= minLen; --i)
        {
            cout<<"i "<<i<<endl;

            vector<bool> visited(n, false);

            int diff = sum - i * 2;

            function<bool(int, int, int)> dfs = [&](int idx, int target, int sum)
            {
                if(sum > target) return false;
                if(sum == target) return true;

                for(int j = idx; j < n; ++j)
                {
                    if(visited[j]) continue;

                    visited[j] = true;
                    if(dfs(j + 1, target, sum + rods[j])) return true;
                    visited[j] = false;
                }

                return false;
            };

            if(dfs(0, diff, 0) && dfs(0, i, 0)) return i;
        }

        return 0;
    }
};

int main()
{
    Solution s;
    //vector<int> a{1,2,4,8,16,32,64,128,256,512,50,50,50,150,150,150,100,100,100,123};
    //vector<int> a{1,2,3,6};
    //vector<int> a{1,2,3,4,5,6};
    //vector<int> a{111,96,96,92,97,90,111,101,112,96,93,91,114};
    vector<int> a{33,30,41,34,37,29,26,31,42,33,38,27,33,31,35,900,900,900,900,900};
    cout<<s.tallestBillboard(a)<<endl;
}
