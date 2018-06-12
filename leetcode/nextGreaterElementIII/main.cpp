#include "header.h"

class Solution {
public:
    int nextGreaterElement(int m) {
        vector<int> v;
        while(m)
        {
            v.push_back(m % 10);
            m /= 10;
        }

        int n = v.size();
        if(n < 2) return -1;

        int i = 0;
        while(i < n - 1 && v[i] <= v[i + 1]) ++i;
        if(i == n - 1) return -1;

        int j = i;
        while(j >= 0 && v[j] > v[i + 1]) --j;
        //if(j == -1) return -1;

        swap(v[i + 1], v[j + 1]);

        sort(v.begin(), v.begin() + i + 1, std::greater<int>());

        long res = 0;
        for(int i = n - 1; i >= 0; --i)
        {
            res *= 10;
            res += v[i];
        }
        return res > INT_MAX ? -1 : res;
    }
};

int main()
{
    Solution s;
    cout<<s.nextGreaterElement(5732)<<endl;
}
