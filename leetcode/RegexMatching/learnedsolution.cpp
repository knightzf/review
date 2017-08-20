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
    bool isMatch(string s, string p)
    {
        size_t stringSz = s.size();
        size_t patternSz = p.size();

        std::vector<std::vector<bool>> match(stringSz + 1, std::vector<bool>(patternSz + 1, false));

        /*
            The match array is of size (stringSz + 1) * (patternSz + 1)
            match[i][j] denotes if s.substr(0, i) matches p.substr(0, j)
            Note s.substr(0, i) takes s[0], s[1]...s[i-1]
            Then we need to define values when i = 0 or j = 0
            When i = 0 and j = 0, meaning empty string and empty pattern
                We define this to be match
            When i = 0, meaning we have s.substr(0, 0) which is an empty string
                Only patterns like a*, .*, or a*b*c* would match
            When j = 0, meaning we have an empty pattern string
                No non-empty string matches an empty pattern
         */

        //Case 1
        match[0][0] = true;

        //Case 2
        for(size_t j = 1; j < patternSz + 1; ++j)
        {
            match[0][j] = j > 1 && p[j - 1] == '*' && match[0][j - 2];
        }

        //Case 3
        //already set to false in the initialization of match


        /*
            Now we need to fill out rest of the array
            1. match[i][j] equals match[i - 1][j - 1] if p[j - 1] != '*' &&
                ( s[i - 1] == p[j - 1] || p[j - 1] == '.' )
            2. match[i][j] equals match[i][j - 2] if p[j - 1] == '*' && p[j-2] repeats 0 times in s
                e.g. s = "ab" p = "abc*"
            3. match[i][j] equals match[i - 1][j] if p[j - 1] == '*' &&
                (p[j-2] repeats >= 1 times in s || p[[j-2] == '.')
                e.g. s = "abc" p = "abc*" or p = "ab.*"
         */
        for(size_t i = 1; i < stringSz + 1; ++i)
        {
            for(size_t j = 1; j < patternSz + 1; ++j)
            {
                if(p[j - 1] != '*')
                {
                    match[i][j] = match[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
                }
                else
                {
                    //The single line looks beautiful but a little hard to understand
                    //It can be seen as match[i][j] = match[i][j - 2] || ( Condition && match[i - 1][j] )
                    //Condition here includes pattern repeats >=1 times or it's ".*"
                    //Why is this? Because Case 2 and 3 are not mutually exclusive
                    //If match[i][j - 2] == true and p[j -1] == '*', match[i][j] is surely true
                    //Only if match[i][j - 2] == false do we start to check if Case 3 is satisfied
                    match[i][j] = match[i][j - 2] ||
                        ((s[i - 1] == p[j - 2] || p[j-2] == '.') && match[i - 1][j]);
                }
            }
        }

        return match[stringSz][patternSz];
    }
};
int main()
{
    Solution sol;

    std::cout<<sol.isMatch("aab", "c*a*b")<<std::endl;

	return 0;
}
