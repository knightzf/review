#include "header.h"

class Solution {
public:
    string decodeString(string s) {
        return impl(s, 0, s.size());
    }

    string impl(const string& s, int startIdx, int endIdx)
    {
        string res;
        for(int i = startIdx; i < endIdx;)
        {
            if(isalpha(s[i]))
            {
                res += s[i];
                ++i;
            }
            else if(isdigit(s[i]))
            {
                int j = i;
                while(j < endIdx && isdigit(s[j])) ++j;
                int cnt = std::stoi(s.substr(i, j - i));
                int k = j + 1, sum = 1;
                while(k < endIdx && sum != 0)
                {
                    if(s[k] == '[') ++sum;
                    else if(s[k] == ']') --sum;
                    ++k;
                }
                //std::cout<<"here "<<j + 1<<" "<<k<<std::endl;
                const auto& r = impl(s, j + 1, k - 1);
                for(int j = 0; j < cnt; ++j)
                {
                    res += r;
                }
                i = k;
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    std::cout<<s.decodeString("3[a]2[bc]")<<std::endl;
    std::cout<<s.decodeString("3[a2[c]]")<<std::endl;
    std::cout<<s.decodeString("2[abc]3[cd]ef")<<std::endl;
}
