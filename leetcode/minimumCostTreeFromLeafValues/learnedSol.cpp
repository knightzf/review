#include "header.h"

class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size(), res = 0;
        vector<int> s{INT_MAX};
        for(int i : arr) {
            while(i >= s.back()) {
                int mid = s.back();
                s.pop_back();
                res += mid * min(s.back(), i);
            }
            s.push_back(i);
        }
        for(int i = 2; i < s.size(); ++i) {
            res += s[i - 1] * s[i];
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> a{6, 2, 4};
    cout<<s.mctFromLeafValues(a)<<endl;
}

