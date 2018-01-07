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
    bool isOneEditDistance(string s, string t) {
        int sSize = s.size();
        int tSize = t.size();

        if(sSize != tSize)
        {
            if(std::abs(sSize - tSize) > 1) return false;

            if(sSize < tSize)
            {
                std::swap(s, t);
                std::swap(sSize, tSize);
            }

            int i = 0;
            int j = 0;
            int diff = 0;
            while(i < sSize && j < tSize)
            {
                if(s[i] != t[j])
                {
                    ++i;
                    ++diff;
                    if(diff > 1)
                    {
                        return false;
                    }
                }
                else
                {
                    ++i;
                    ++j;
                }
            }
        }
        else
        {
            int diff = 0;
            for(int i = 0; i < sSize; ++i)
            {
                if(s[i] != t[i])
                {
                    ++diff;
                    if(diff > 1)
                    {
                        return false;
                    }
                }
            }

            if(diff == 0)
            {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    Solution s;
}
