#include "header.h"

class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        for(int i = s.size() - 2; i >= 0; --i) {
            if(s[i] < s[i + 1]) {
                for(int j = s.size() - 1; j > i; --j) {
                    if(s[j] > s[i]) {
                        swap(s[i], s[j]);
                        sort(s.begin() + i + 1, s.end());
                        auto t = stoll(s);
                        if(t <= INT_MAX) return t;
                    }
                }
            }
        }
        return -1;
    }
};

int main()
{
    //Solution s;
}