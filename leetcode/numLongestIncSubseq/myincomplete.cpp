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

using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums)
    {
        std::map<int, int> countMap;

        std::multimap<int, std::pair<size_t, int>> map;
        for(size_t i = 0; i < nums.size(); ++i)
        {
            std::cout<<nums[i]<<std::endl;
            if(map.empty())
            {
                map.insert(std::make_pair(nums[i], std::make_pair(i, 1)));
                countMap[1] = 1;
            }
            else
            {
                auto iter = map.lower_bound(nums[i]);

                if(iter == map.begin())
                {
                    map.insert(std::make_pair(nums[i], std::make_pair(i, 1)));
                    countMap[1] += 1;
                }
                else
                {
                    //std::cout<<"test "<<iter->first<<std::endl;

                    while((--iter)->first > nums[i])
                    {
                        //std::cout<<11<<std::endl;
                    }

                    if(iter->first == nums[i] && iter == map.begin())
                    {
                        map.insert(std::make_pair(nums[i], std::make_pair(i, 1)));
                        countMap[1] += 1;
                    }
                    else
                    {
                        int maxLen = 0;
                        int maxCount = 0;
                        std::cout<<111<<" "<<iter->first<<std::endl;
                        for(auto j = map.begin(); j != iter; ++j)
                        {
                            if(j->second.first < i)
                            {
                                std::cout<<"item "<<j->first<<" "<<j->second.first<<" "<<j->second.second<<std::endl;
                                int len = j->second.second + 1;
                                maxLen = maxLen > len ? maxLen : len;

                                if(countMap.find(len) == countMap.end())
                                {
                                    std::cout<<"len "<<len<<std::endl;
                                    countMap[len] = countMap[len - 1];
                                }
                                else
                                {
                                    std::cout<<"len1 "<<len<<std::endl;
                                    countMap[len] += 1;
                                }

                                maxCount = countMap[len] > maxCount ? countMap[len] : maxCount;
                            }
                        }
                        //std::cout<<222<<std::endl;

                        if(iter->second.first < i)
                        {
                            std::cout<<"item "<<iter->first<<" "<<iter->second.first<<" "<<iter->second.second<<std::endl;
                            int len = iter->second.second + 1;
                            maxLen = maxLen > len ? maxLen : len;

                            if(countMap.find(len) == countMap.end())
                            {
                                std::cout<<"len2 "<<len<<std::endl;
                                countMap[len] = countMap[len - 1];
                            }
                            else
                            {
                                std::cout<<"len3 "<<len<<std::endl;
                                countMap[len] += 1;
                            }

                            maxCount = countMap[len] > maxCount ? countMap[len] : maxCount;
                        }


                        std::cout<<"max "<<maxLen<<" "<<maxCount<<std::endl;

                        map.insert(std::make_pair(nums[i], std::make_pair(i, maxLen)));
                    }
                }
            }
        }


        for(const auto& m : map)
        {
            std::cout<<m.first<<" "<<m.second.first<<" "<<m.second.second<<std::endl;
        }
        std::cout<<"-------------"<<std::endl;
        for(const auto& m : countMap)
        {
            std::cout<<m.first<<" "<<m.second<<std::endl;
        }

        return countMap.rbegin()->second;
    }
};

int main()
{
    Solution sol;
    //std::vector<int> a{3,1,3,2,4};
    std::vector<int> a{1,3,5};
    std::cout<<sol.findNumberOfLIS(a)<<std::endl;
    return 0;
}
