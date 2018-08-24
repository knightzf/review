#include "header.h"

class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        string sorted = s;
        sort(sorted.begin(), sorted.end(), std::greater<int>());
        cout<<sorted<<endl;
        for(int i = 0, n = s.size(); i < n; ++i)
        {
            if(s[i] != sorted[i]) {
                char c = s[i];
                s[i] = sorted[i];
                for(int j = n - 1; j > i; --j)
                {
                    if(s[j] == sorted[i]) {
                        s[j] = c;
                        break;
                    }
                }
                break;
            }
        }
        return stoi(s);
    }
};

int main() {
    Solution s;
}
