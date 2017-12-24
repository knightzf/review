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
#include <unordered_set>
#include <cstring>
#include <memory>

using namespace std;

class Solution {
public:
    string crackSafe(int n, int k)
    {
        std::string res(n, '0');

        int totalCombi = (int)std::pow(k, n);

        std::unordered_set<std::string> visited;
        visited.insert(res);

        dfs(res, visited, totalCombi, n, k);

        return res;
    }

    bool dfs(std::string& s, std::unordered_set<std::string>& visited, int totalCombi, int n, int k)
    {
        if(visited.size() == totalCombi)
        {
            return true;
        }

        for(int i = 0; i < k; ++i)
        {
            //std::cout<<s<<" "<<s.size() - n + 1<<" "<<n - 1<<std::endl;
            std::string temp = s.substr(s.size() - n + 1, n - 1);

            char c =  i + '0';
            temp = temp.append(1, c);

            if(visited.find(temp) == visited.end())
            {
                s = s.append(1, c);
                visited.insert(temp);

                if(dfs(s, visited, totalCombi, n, k))
                {
                    return true;
                }
                else
                {
                    s.pop_back();
                    visited.erase(temp);
                }
            }
        }

        return false;
    }
};

int main()
{
    Solution s;
    std::cout<<s.crackSafe(1, 3)<<std::endl;
}
