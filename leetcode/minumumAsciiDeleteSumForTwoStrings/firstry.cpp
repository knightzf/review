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
    int minimumDeleteSum(string s1, string s2)
    {
        int m = s1.size();
        int n = s2.size();

        std::vector<std::vector<std::pair<std::vector<int>, std::vector<int>>>>
            dp(m + 1, std::vector<std::pair<std::vector<int>, std::vector<int>>>(n + 1,
                std::make_pair(std::vector<int>(128, 0), std::vector<int>(128, 0))));

        for(int i = 1; i < m + 1; ++i)
        {
            for(char c : s1.substr(0, i))
            {
                dp[i][0].first[c]++;
            }
        }

        for(int i = 1; i < n + 1; ++i)
        {
            for(char c : s2.substr(0, i))
            {
                dp[0][i].second[c]++;
            }
        }

        for(int i = 1; i < m + 1; ++i)
        {
            for(int j = 1; j < n + 1; ++j)
            {
                std::vector<std::pair<std::vector<int>, std::vector<int>>> tempV;

                if(s1[i - 1] == s2[j - 1])
                {
                    tempV.push_back(dp[i - 1][j - 1]);
                }
                else
                {
                    if(dp[i - 1][j].second[s1[i - 1]] > 0 &&
                       dp[i][j - 1].first[s2[j - 1]] > 0)
                    {
                        auto t1 = dp[i][j - 1].first;
                        t1[s2[j - 1]]--;

                        auto t2 = dp[i - 1][j].second;
                        t2[s1[i - 1]]--;

                        tempV.push_back(std::make_pair(t1, t2));
                    }
                    else
                    {
                        //std::cout<<s1[i - 1]<<" "<<s2[j - 1]<<std::endl;
                        if(dp[i - 1][j].second[s1[i - 1]] > 0)
                        {
                            //std::cout<<"a"<<std::endl;
                            auto t = dp[i - 1][j].second;
                            t[s1[i - 1]]--;
                            tempV.push_back(std::make_pair(dp[i - 1][j].first, t));
                        }
                        else if(dp[i][j - 1].first[s2[j - 1]] > 0)
                        {
                            //std::cout<<"b"<<std::endl;
                            auto t = dp[i][j - 1].first;
                            t[s2[j - 1]]--;
                            tempV.push_back(std::make_pair(t, dp[i][j - 1].second));
                        }
                        else
                        {
                            //std::cout<<"c"<<std::endl;
                            auto t1 = dp[i - 1][j - 1].first;
                            t1[s1[i - 1]]++;
                            auto t2 = dp[i - 1][j - 1].second;
                            t2[s2[j - 1]]++;
                            tempV.push_back(std::make_pair(t1, t2));
                        }
                    }
                }

                //std::cout<<tempV.size()<<std::endl;
                int idx = -1;
                int sum = -1;
                for(int s = 0; s < tempV.size(); ++s)
                {
                    const auto& item = tempV[s];

                    int sumT = 0;

                    const auto& a = item.first;
                    for(int k = 0; k < a.size(); ++k)
                    {
                        if(a[k] > 0)
                        {
                            //std::cout<<k<<"--"<<a[k]<<std::endl;
                            sumT += k * a[k];
                        }
                    }

                    const auto& b = item.second;
                    for(int k = 0; k < b.size(); ++k)
                    {
                        if(b[k] > 0)
                        {
                            //std::cout<<k<<"--"<<b[k]<<std::endl;
                            sumT += k * b[k];
                        }
                    }

                    if(sumT > sum)
                    {
                        sum = sumT;
                        idx = s;
                    }
                }
                //std::cout<<222<<" "<<idx<<" "<<sum<<std::endl;

                dp[i][j] = tempV[idx];
            }
        }

        for(int i = 1; i < m + 1; ++i)
        {
            for(int j = 1; j < n + 1; ++j)
            {
                const auto& t = dp[i][j];
                std::cout<<s1.substr(0, i)<<" "<<s2.substr(0, j)<<std::endl;
                const auto& a = t.first;
                for(int k = 0; k < a.size(); ++k)
                {
                    if(a[k] > 0)
                    {
                        std::cout<<char(k)<<" " << a[k] << " | ";
                    }
                }
                std::cout<<std::endl;
                const auto& b = t.second;
                for(int k = 0; k < b.size(); ++k)
                {
                    if(b[k] > 0)
                    {
                        std::cout<<char(k)<< " " << b[k]<< " | ";
                    }
                }
                std::cout<<"\n--------"<<std::endl;
            }
        }

        int sum;

        const auto& r = dp[m][n];

        const auto& a = r.first;
        for(int k = 0; k < a.size(); ++k)
        {
            if(a[k] > 0)
            {
                sum += k * a[k];
            }
        }

        const auto& b = r.second;
        for(int k = 0; k < b.size(); ++k)
        {
            if(b[k] > 0)
            {
                sum += k * b[k];
            }
        }

        return sum;
    }
};

int main()
{
    Solution sol;
    //std::cout<<sol.minimumDeleteSum("sea", "eat")<<std::endl;
    std::cout<<sol.minimumDeleteSum("delete", "leet")<<std::endl;
    return 0;
}
