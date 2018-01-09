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
    int compareVersion(string version1, string version2) {
        std::vector<int> v1;
        std::vector<int> v2;

        convertVersion(version1, v1);
        convertVersion(version2, v2);

        int n = v1.size();
        int m = v2.size();

        for(int i = 0; i < n && i < m; ++i)
        {
            if(v1[i] > v2[i])
            {
                return 1;
            }
            else if(v1[i] < v2[i])
            {
                return -1;
            }
        }

        if(n == m)
        {
            return 0;
        }
        else if(n > m)
        {
            for(int j = m; j < n; ++j)
            {
                if(v1[j] != 0)
                {
                    return 1;
                }
            }
            return 0;
        }
        else
        {
            for(int j = n; j < m; ++j)
            {
                if(v2[j] != 0)
                {
                    return -1;
                }
            }
            return 0;
        }
    }

    void convertVersion(const std::string& version, vector<int>& v)
    {
        int n = version.size();
        std::string s;
        for(int i = 0; i < n; ++i)
        {
            if(version[i] != '.')
            {
                s += version[i];
                if(i == n - 1)
                {
                    v.push_back(std::stoi(s));
                }
            }
            else
            {
                v.push_back(std::stoi(s));
                s.clear();
            }
        }
    }
};

int main()
{
    Solution s;
    std::cout<<s.compareVersion("1", "0")<<std::endl;
}
