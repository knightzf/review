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
    vector<int> grayCode(int n)
    {
        std::vector<int> v;
        for(int i = 0, max = std::pow(2, n); i < max; ++i)
        {
            v.push_back(i);
        }

        vector<int> res;
        bool r = impl(v, res);
        std::cout<<"r "<<r<<std::endl;

        if(r)
        {
            return res;
        }
    }

    bool impl(vector<int>& allNums, vector<int>& res)
    {
        /*for(auto i : res)
        {
            std::cout<<i<<" ";
        }
        std::cout<<std::endl;*/

        bool found = false;
        for(int i = 0; i < allNums.size(); ++i)
        {
            int v = allNums[i];
            if(v != -1)
            {
                if(res.empty())
                {
                    res.push_back(v);
                    found = true;
                }
                else
                {
                    //std::cout<<"check "<<res.back()<<" "<<v<<" "<<areDiffByOneBit(res.back(), v)<<std::endl;
                    if(areDiffByOneBit(res.back(), v))
                    {
                        res.push_back(v);
                        found = true;
                    }
                }

                if(found)
                {
                    if(res.size() == allNums.size())
                    {
                        return true;
                    }

                    allNums[i] = -1;
                    bool r = impl(allNums, res);

                    if(!r)
                    {
                        if(!res.empty()) res.pop_back();
                        allNums[i] = v;
                    }
                    else
                    {
                        return true;
                    }
                }
            }
        }

        return false;
    }

private:
    bool areDiffByOneBit(int a, int b)
    {
        int r = a ^ b;
        return r > 0 && (r & (r - 1)) == 0;
    }
};

int main()
{
    Solution s;
    const auto& r = s.grayCode(3);
    for(auto i : r)
    {
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
}
