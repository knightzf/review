#include "header.h"

class Solution {
public:
    string simplifyPath(string path) {
        int n = path.size();
        int startIdx = 0;
        deque<string> s;
        for(int i = 0; i <= n; ++i)
        {
            if(i == n || path[i] == '/') {
                if(i - startIdx) {
                    const auto& t = path.substr(startIdx, i - startIdx);
                    if(t == "..") {
                        if(!s.empty()) s.pop_back();
                    }
                    else if(t != ".") s.push_back(t);
                }
                startIdx = i + 1;
            }
        }
        if(s.empty()) return "/";
        string res;
        while(!s.empty()) {res += "/" + s.front(); s.pop_front();}        
        return res;
    }
};

int main()
{
    Solution s;
}