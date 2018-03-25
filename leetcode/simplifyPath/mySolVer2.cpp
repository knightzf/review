#include "header.h"

class Solution {
public:
    string simplifyPath(string path) {
        std::deque<string> q;
        int lastSlashIdx = -1;
        int n = path.size();
        for(int i = 0; i <= n; ++i)
        {
            if(i == n || path[i] == '/')
            {
                if(lastSlashIdx != -1 && i - lastSlashIdx - 1 > 0)
                {
                    const auto& t = path.substr(lastSlashIdx + 1, i - lastSlashIdx - 1);
                    if(t == "..")
                    {
                        if(!q.empty()) q.pop_back();
                    }
                    else if(t != ".")
                        q.push_back(t);
                }
                lastSlashIdx = i;
            }
        }

        string res;
        if(q.empty()) res = "/";
        while(!q.empty())
        {
            res += "/" + q.front();
            q.pop_front();
        }
        return res;
    }
};

int main()
{
    Solution s;
    //std::cout<<s.simplifyPath("/")<<std::endl;
    std::cout<<s.simplifyPath("/..")<<std::endl;
}
