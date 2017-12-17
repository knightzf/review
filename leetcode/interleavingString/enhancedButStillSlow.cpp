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
        if(k == s3.size())
        {
            //std::cout<<i<<" "<<j<<std::endl;
            if(i == s1.size() && j == s2.size())
            {
                return true;
            }
            return false;
        }

        if(i == s1.size() && j != s2.size())
        {
            //std::cout<<"h1"<<s2.substr(j)<<" "<<s3.substr(k)<<std::endl;
            return s2.substr(j) == s3.substr(k);
        }

        if(i != s1.size() && j == s2.size())
        {
            //std::cout<<"h2"<<std::endl;
            return s1.substr(i) == s3.substr(k);
        }

        char a = s1[i];
        char b = s2[j];
        char c = s3[k];

        if(a == c && b != c)
        {
            while(i < s1.size() && k < s3.size() && s1[i] == s3[k] && s2[j] != s3[k])
            {
                ++i;
                ++k;
            }

            return impl(s1, s2, s3, i, j, k);
        }

        if(a != c && b == c)
        {
            while(j < s2.size() && k < s3.size() && s2[j] == s3[k] && s1[i] != s3[k])
            {
                ++j;
                ++k;
            }

            return impl(s1, s2, s3, i, j, k);
        }

        if(a == c && b == c)
        {
            int newI = i, newJ = j, newK = k;
            while(newI < s1.size() && newJ < s2.size() && newK < s3.size() &&
                  s1[newI] == s3[newK] && s2[newJ] == s3[newK])
            {
                ++newI; ++newJ; ++newK;
            }

            //--newI; --newJ; --newK;

            /*if(newI == i + 1)
            {
                return impl(s1, s2, s3, newI, newJ - 1, newK) ||
                    impl(s1, s2, s3, newI - 1, newJ, newK);
            }
            else
            {
                return impl(s1, s2, s3, newI, j, newK) ||
                    impl(s1, s2, s3, i, newJ, newK) ;
            }*/

            while(newI > i)
            {
                bool r1 = impl(s1, s2, s3, newI, j, newK);
                if(r1)
                {
                    return true;
                }

                bool r2 = impl(s1, s2, s3, i, newJ, newK);
                if(r2)
                {
                    return true;
                }

                --newI; --newJ; --newK;
            }
        }

        //std::cout<<"h3"<<std::endl;
        return false;
    }
};

int main()
{
    Solution s;

    std::cout<<s.isInterleave("aacaac", "aacaaeaac", "aacaacaaeaacaac")<<std::endl;
    //return 0;
    std::cout<<s.isInterleave("aabc", "abad", "aabcabad")<<std::endl;
    std::cout<<s.isInterleave("aabcc", "dbbca", "aadbbcbcac")<<std::endl;
    std::cout<<s.isInterleave("aabcc", "dbbca", "aadbbbaccc")<<std::endl;
    std::cout<<s.isInterleave("cbcccbabbccbbcccbbbcabbbabcababbbbbbaccaccbabbaacbaabbbc",
                              "abcbbcaababccacbaaaccbabaabbaaabcbababbcccbbabbbcbbb",
                              "abcbcccbacbbbbccbcbcacacbbbbacabbbabbcacbcaabcbaaacbcbbbabbbaacacbbaaaabccbcbaabbbaaabbcccbcbabababbbcbbbcbb")<<std::endl;

    std::cout<<s.isInterleave("bbbbbabbbbabaababaaaabbababbaaabbabbaaabaaaaababbbababbbbbabbbbababbabaabababbbaabababababbbaaababaa",
                              "babaaaabbababbbabbbbaabaabbaabbbbaabaaabaababaaaabaaabbaaabaaaabaabaabbbbbbbbbbbabaaabbababbabbabaab",
                              "babbbabbbaaabbababbbbababaabbabaabaaabbbbabbbaaabbbaaaaabbbbaabbaaabababbaaaaaabababbababaababbababbbababbbbaaaabaabbabbaaaaabbabbaaaabbbaabaaabaababaababbaaabbbbbabbbbaabbabaabbbbabaaabbababbabbabbab")<<std::endl;

}
