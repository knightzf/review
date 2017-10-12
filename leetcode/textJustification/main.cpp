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
    vector<string> fullJustify(vector<string>& words, int maxWidth)
    {
        if(maxWidth == 0)
        {
            return words;
        }

        std::vector<string> result;

        std::vector<string> strVec;
        int currLen = 0;

        auto helper = [&](bool lastline = false) {
            if(strVec.size() == 1)
            {
                std::string s(strVec[0]);
                s.append(maxWidth - s.size(), ' ');
                result.push_back(s);
                return;
            }

            std::string s(strVec[0]);

            int actualWordsLen = currLen - strVec.size();
            int spacePerGap = strVec.size() == 1 ? 0 : (maxWidth - actualWordsLen) / (strVec.size() - 1);
            int extraSpace = strVec.size() == 1 ? 0 : (maxWidth - actualWordsLen) % (strVec.size() - 1);

            std::string space(spacePerGap, ' ');
            for(int j = 1; j < strVec.size(); ++j)
            {
                if(lastline)
                {
                    s += " " + strVec[j];
                }
                else
                {
                    s += space + (j <= extraSpace ? " " : "") + strVec[j];
                }
            }

            if(lastline)
            {
                s.append(maxWidth - s.size(), ' ');
            }

            result.push_back(s);
        };

        for(int i = 0; i < words.size(); ++i)
        {
            bool valid = currLen + words[i].size() <= maxWidth;
            bool last = i == words.size() - 1;

            if(valid)
            {
                currLen += words[i].size() + 1;
                strVec.push_back(words[i]);

                if(last)
                {
                    helper(true);
                }
            }
            else
            {
                helper();

                if(last)
                {
                    if(words[i].size() == maxWidth)
                    {
                        result.push_back(words[i]);
                    }
                    else
                    {
                        std::string s(words[i]);
                        s.append(maxWidth - words[i].size(), ' ');
                        result.push_back(s);
                    }

                }
                else
                {
                    strVec.clear();
                    currLen = 0;
                    --i;
                }
            }
        }

        return result;
    }
};

void print(const vector<string>& r)
{
    for(const auto& i : r)
    {
        std::cout<<i<<"<"<<std::endl;
    }
    std::cout<<"-------"<<std::endl;
}
int main()
{
    Solution sol;
    //
    //
    vector<string> a{"a", "b", "c"};
    vector<string> b{""};
    vector<string> c{"This", "is", "an", "example", "of", "text", "justification."};
    vector<string> d{"What","must","be","shall","be."};

    print(sol.fullJustify(a, 1));
    print(sol.fullJustify(b, 2));
    print(sol.fullJustify(c, 16));
    print(sol.fullJustify(d, 12));

    return 0;
}
