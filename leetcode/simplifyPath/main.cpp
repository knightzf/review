#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <sstream>
#include <cmath>
#include <queue>
#include <map>
#include <string>
#include <cstdlib>
#include <cctype>
#include <stdexcept>
#include <climits>
#include <utility>
#include <bitset>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string simplifyPath(string path)
    {
        std::deque<std::string> s;
        int start = 0;
        while(path[start] == ' ')
        {
            ++start;
        }

        int n = path.size();
        for(int i = start; i < n; )
        {
            if(i == start && path[i] != '/')
            {
                return "";
            }

            if(path[i] == '/')
            {
                int sIdx = i;
                while(true)
                {
                    ++i;

                    bool shouldBreak = false;
                    std::string p;

                    if(i == n)
                    {
                        shouldBreak = true;
                        if(sIdx != n - 1)
                        {
                            p = path.substr(sIdx + 1);
                        }
                    }

                    if(path[i] == '/')
                    {
                        shouldBreak = true;
                        p = path.substr(sIdx + 1, i - sIdx - 1);
                    }

                    if(shouldBreak)
                    {
                        if(p.empty() || p == ".")
                        {

                        }
                        else if(p == "..")
                        {
                            if(!s.empty())
                            {
                                s.pop_back();
                            }
                        }
                        else
                        {
                            s.push_back(p);
                        }
                        break;
                    }
                }
            }
        }

        std::string result = "";
        while(!s.empty())
        {
            result += "/" + s.front();
            s.pop_front();
        }

        if(result.empty())
        {
            result = "/";
        }

        return result;
    }
};

int main()
{
    Solution sol;
    std::cout<<sol.simplifyPath("/home/")<<std::endl;
    std::cout<<sol.simplifyPath("/a/./b/../../c/")<<std::endl;
    std::cout<<sol.simplifyPath("/...")<<std::endl;
    std::cout<<sol.simplifyPath("/abc/...")<<std::endl;
    return 0;
}
