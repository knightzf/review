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
    bool isInterleave(string s1, string s2, string s3)
    {
        if(s1.size() + s2.size() != s3.size())
        {
            return false;
        }

        if(s3.empty())
        {
            return s1.empty() && s2.empty();
        }
        else
        {
            if(s1.empty())
            {
                return s2 == s3;
            }

            if(s2.empty())
            {
                return s1 == s3;
            }
        }

        return impl(s1, s2, s3, 0, 0, 0);
    }

    bool impl(const std::string& s1, const std::string& s2, const std::string& s3, int i, int j, int k)
    {
        char a = s1[i];
        char b = s2[j];
        char c = s3[k];

        if(a == c || b == c)
        {
            if(k == s3.size() - 1)
            {
                return true;
            }
        }

        if(a == c && b != c)
        {
            if(i < s1.size())
            {
                return impl(s1, s2, s3, i + 1, j, k + 1);
            }
            return false;
        }

        if(a != c && b == c)
        {
            if(j < s2.size())
            {
                return impl(s1, s2, s3, i, j + 1, k + 1);
            }
            return false;
        }

        if(a == c && b == c)
        {
            bool r1 = false;
            if(i < s1.size())
            {
                r1 = impl(s1, s2, s3, i + 1, j, k + 1);
            }

            bool r2 = false;
            if(j < s2.size())
            {
                r2 = impl(s1, s2, s3, i, j + 1, k + 1);
            }

            return r1 || r2;
        }

        return false;
    }
};

int main()
{
    Solution s;
    std::cout<<s.isInterleave("aabcc", "dbbca", "aadbbcbcac")<<std::endl;
    std::cout<<s.isInterleave("aabcc", "dbbca", "aadbbbaccc")<<std::endl;
    std::cout<<s.isInterleave("cbcccbabbccbbcccbbbcabbbabcababbbbbbaccaccbabbaacbaabbbc",
                              "abcbbcaababccacbaaaccbabaabbaaabcbababbcccbbabbbcbbb",
                              "abcbcccbacbbbbccbcbcacacbbbbacabbbabbcacbcaabcbaaacbcbbbabbbaacacbbaaaabccbcbaabbbaaabbcccbcbabababbbcbbbcbb")<<std::endl;
}
