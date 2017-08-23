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

using namespace std;

class Solution {
public:
    int count = 0;

    void printTime(const std::string& s, char c = ' ')
    {
        if(s.empty())
        {
            return;
        }

        if(s.size() == 1)
        {
            if(c == ' ' || s[0] != c)
            {
                //std::cout<<"s "<<s<<" c "<<c<<std::endl;
                ++count;
            }
            return;
        }

        std::vector<std::pair<size_t, size_t>> ranges(26, std::make_pair(999, 999));
        std::map<int, char> countMap;

        for(size_t i = 0, sz = s.size(); i < sz; ++i)
        {
            char c = s[i];
            size_t idx = c - 'a';
            if(ranges[idx].first == 999)
            {
                ranges[idx].first = i;
            }
            ranges[idx].second = i;

            countMap[ranges[idx].second - ranges[idx].first + 1] = c;
        }

        auto iter = countMap.rbegin();
        size_t idx = iter->second - 'a';


        if(iter->second != c)
        {
            //std::cout<<"s1 "<<s<<" c1 "<<c<<std::endl;
            ++count;
        }

        //std::cout<<"max c "<<iter->second<<" "<<ranges[idx].first<<" "<< ranges[idx].second<<std::endl;
        if(ranges[idx].first != ranges[idx].second && ranges[idx].second - ranges[idx].first != 1)
        {
            //std::cout<<"middle "<<s.substr(ranges[idx].first + 1, ranges[idx].second - ranges[idx].first - 1)<<std::endl;
            size_t start = ranges[idx].first + 1;
            size_t end = ranges[idx].second - 1;
            while(true)
            {
                if(start > end || (s[start] != iter->second && s[end] != iter->second))
                    break;

                if(s[start] == iter->second) ++start;
                if(s[end] == iter->second) --end;
            }

            if(start <= end)
            {
                printTime(s.substr(start, end - start + 1), iter->second);
            }
        }

        if(ranges[idx].first != 0)
        {
            printTime(s.substr(0, ranges[idx].first));
            //std::cout<<"left "<<s.substr(0, ranges[idx].first)<<std::endl;
        }

        if(ranges[idx].second != s.size() - 1)
        {
            printTime(s.substr(ranges[idx].second + 1));
            //std::cout<<"right "<<s.substr(ranges[idx].second + 1)<<std::endl;
        }
    }

    int strangePrinter(string s)
    {
        printTime(s);
        return count;
    }

    int strangePrinter1(string s) {
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        return helper(s, dp, 0, n);
    }

    int helper(string& str, vector<vector<int>>& dp, int s, int e) {
        if (s >= e) return 0;
        if (dp[s][e]) return dp[s][e];
        // handle leading and trailing characters of str[s]
        // Note the range is left inclusive [s,e) [l,r)
        int l = s, r = e;
        while (l < e && str[l] == str[s]) l++;
        while (r > l && str[r-1] == str[s]) r--;
        dp[s][e] = 1+helper(str, dp, l, r);
        for (int i = l; i < r; i++) {
            if (str[i] == str[s]) {
                dp[s][e] = min(dp[s][e], helper(str,dp,l,i)+helper(str,dp,i,r));
                while (i < e && str[i] == str[s]) i++;
            }
        }
        return dp[s][e];
    }
};

int main()
{
    Solution sol;
    string s = "bdbcdc";
    std::cout<<sol.strangePrinter(s)<<std::endl;
    std::cout<<sol.strangePrinter1(s)<<std::endl;
    return 0;
}
