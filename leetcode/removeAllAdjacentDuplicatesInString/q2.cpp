#include "header.h"

class Solution {
public:
    string removeDuplicates(string S) {
        deque<char> q;
        for(char c : S) {
            if(!q.empty() && c == q.back()) q.pop_back();
            else q.push_back(c);
        }
        string res;
        while(!q.empty()) {
            res += q.front();
            q.pop_front();
        }
        return res;
    }
};

int main()
{
    Solution s;
}
