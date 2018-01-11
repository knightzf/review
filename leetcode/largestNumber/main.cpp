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
#include <iterator>

using namespace std;


class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return "";
        std::vector<std::string> strv(n);
        int maxLen = 0;
        for(int i = 0; i < n; ++i)
        {
            strv[i] = std::to_string(nums[i]);
            maxLen = std::max(maxLen, (int)strv[i].size());
        }

        std::vector<std::pair<std::string, std::string>> pv;
        for(int i = 0; i < n; ++i)
        {
            if(strv[i].size() < maxLen)
            {
                pv.push_back(std::make_pair(strv[i],
                                            strv[i] + std::string(maxLen - strv[i].size(),
                                                                  strv[i].back() >= strv[i][0] ? strv[i].back() : strv[i][0]) ));

            }
            else
            {
                pv.push_back(std::make_pair(strv[i], strv[i]));
            }
        }

        /*for(auto& i : pv)
        {
            std::cout<<i.first<<" "<<i.second<<std::endl;;
        }*/

        std::sort(pv.begin(), pv.end(), [](const std::pair<std::string, std::string>& a,
                                           const std::pair<std::string, std::string>& b){
                    return a.second > b.second;
                  });

        std::string res;
        for(const auto& p : pv)
        {
            res += p.first;
        }

        int idx = 0;
        while(res[idx] == '0' && idx < res.size() - 1)
        {
            ++idx;
        }

        return res.substr(idx);
    }
};

int main() {
    Solution s;
    vector<int> a{3, 30, 34, 5, 9};
    std::cout<<s.largestNumber(a)<<std::endl;
}
