#include "header.h"

class Solution {
public:
    int tribonacci(int n) {
        static vector<int> v;
        if(v.empty()) {
            v.push_back(0), v.push_back(1), v.push_back(1);
            for(int i = 0; i < 35; ++i) {
                v.push_back(v[v.size() - 3] + v[v.size() - 2] + v[v.size() - 1]);
            }
        }
        return v[n];
    }
};

int main()
{
    Solution s;
    s.tribonacci(1);
}
