#include "header.h"

class Solution {
public:
    int countTriplets(vector<int>& A) {
        int n = A.size();
        int res = 0;
        unordered_map<int, int> m;

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                int t = (A[i] & A[j]);
                ++m[t];
            }
        }

        for(auto& p : m)
        {
            if(p.first == 0) {
                res += n * p.second;;
                continue;
            }
            for(int i = 0; i < n; ++i) {
                if((p.first & A[i]) == 0) res += p.second;
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> a{2,1,3};
    //vector<int> a{1,1,1};
    //vector<int> a{2,4,7,3};
    cout<<s.countTriplets(a)<<endl;
}
