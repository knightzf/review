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

using namespace std;

class Solution {
public:
    int compress(vector<char>& chars)
    {
        int n = chars.size();

        if(n == 1)
        {
            return 1;
        }

        int lastIdx = -1;
        char c = chars[0];
        int count = 1;
        for(int i = 1; i < n; ++i)
        {
            if(chars[i] == c)
            {
                ++count;

                if(i == n - 1)
                {
                    ++lastIdx;
                    std::swap(chars[lastIdx], chars[i]);
                    if(count > 1)
                    {
                        std::string len = std::to_string(count);
                        for(char t : len)
                        {
                            chars[++lastIdx] = t;
                        }
                    }
                }
            }
            else
            {
                ++lastIdx;
                std::swap(chars[lastIdx], chars[i - 1]);
                if(count > 1)
                {
                    std::string len = std::to_string(count);
                    for(char t : len)
                    {
                        chars[++lastIdx] = t;
                    }
                }

                if(i == n - 1)
                {
                    ++lastIdx;
                    std::swap(chars[lastIdx], chars[i]);
                }
                else
                {
                    c = chars[i];
                    count = 1;
                }

            }
        }

        std::cout<<"last "<<lastIdx<<std::endl;

        if(lastIdx < n)
        {
            chars.erase(chars.begin() + ++lastIdx, chars.end());
        }

        for(char c : chars)
        {
            std::cout<<c<<" ";
        }
        std::cout<<std::endl;

        return chars.size();
    }
};

int main()
{
    Solution sol;
    std::vector<char> a{'a','a','b','b','c','c','c'};
    std::cout<<sol.compress(a)<<std::endl;
    std::vector<char> b{'a'};
    std::cout<<sol.compress(b)<<std::endl;
    std::vector<char> c{'a','b','b','b','b','b','b','b','b','b','b','b','b'};
    std::cout<<sol.compress(c)<<std::endl;
    std::vector<char> d{'a','b','c'};
    std::cout<<sol.compress(d)<<std::endl;
    std::vector<char> e{'a','a'};
    std::cout<<sol.compress(e)<<std::endl;
    std::vector<char> f{'a','a','a','a','a','b'};
    std::cout<<sol.compress(f)<<std::endl;
    std::vector<char> g{'i','i','i','i','k','k','k','k','k','k','r','r','b','b','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','n','n','a','a','k','k'};
    std::cout<<sol.compress(g)<<std::endl;
}
