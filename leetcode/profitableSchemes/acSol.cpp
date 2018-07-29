#include "header.h"

class Solution {
private:
    int n;
    int mod = 1000000007;
public:
    int profitableSchemes(int G, int P, vector<int>& group, vector<int>& profit) {
        n = group.size();
        vector<unordered_map<int, int>> v(101);
        int res = 0;
        for(int i = 0; i < n; ++i)
        {
            for(int j = 100; j > 0; --j)
            {
                int prevPeople = j - group[i];
                if(prevPeople < 0) break;
                if(prevPeople == 0) {
                    long t = v[j][profit[i]] + 1;
                    v[j][profit[i]] = t % mod;
                    if(profit[i] >= P && j <= G) {
                        res = (long(res) + 1) % mod;
                    }
                }
                else {
                    for(auto& p : v[prevPeople]) {
                        int prof = p.first + profit[i];
                        long t = (long)p.second + v[j][prof];
                        v[j][prof] = t % mod;
                        if(prof >= P && j <= G) {
                            res = (long(res) + p.second) % mod;
                        }
                    }
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    if(1)
    {
        vector<int> a{3, 5};
        vector<int> b{7, 8};
        cout<<s.profitableSchemes(10, 5, a, b)<<endl;
    }

    if(1){
        vector<int> a{2, 3, 5};
        vector<int> b{6, 7, 8};
        cout<<s.profitableSchemes(10, 5, a, b)<<endl;
    }

    if(1){
        vector<int> a{24,23,7,4,26,3,7,11,1,7,1,3,5,26,26,1,13,12,2,1,7,4,1,27,13,16,26,18,6,1,1,7,16,1,6,2,5,9,19,28,1,23,2,1,3,4,4,3,22,1,1,3,5,34,2,1,22,16,8,5,3,21,1,8,14,2,1,3,8,12,40,6,4,2,2,14,1,11,9,1,7,1,1,1,6,6,4,1,1,7,8,10,20,2,14,31,1,13,1,9};
        vector<int> b{5,2,38,25,4,17,5,1,4,0,0,8,13,0,20,0,28,1,22,7,10,32,6,37,0,11,6,11,23,20,13,13,6,2,36,1,0,9,4,5,6,14,20,1,13,6,33,0,22,1,17,12,10,1,19,13,8,1,0,17,20,9,8,6,2,2,1,4,22,11,3,2,6,0,40,0,0,7,1,0,25,5,12,7,19,4,12,7,4,4,1,15,33,14,2,1,1,61,4,5};
        cout<<s.profitableSchemes(100, 100, a, b)<<endl;
    }

}
