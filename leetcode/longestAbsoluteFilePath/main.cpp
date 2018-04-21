#include "header.h"

class Solution {
public:
    int lengthLongestPath(string input) {
        if(input.empty()) return 0;

        int res = 0, currentLen = 0, n = input.size();
        stack<string> s;
        for(int i = 0; i < n;)
        {
            if(s.empty())
            {
                int j = i;
                while(j < n && input[j] != '\n' && input[j] != '\t') ++j;
                s.push(input.substr(i, j - i));
                currentLen += s.top().size();
                if(s.top().find('.') != std::string::npos) res = max(res, currentLen);
                i = j;
            }
            else
            {
                int depth = 0;
                while(i < n && (input[i] == '\n' || input[i] == '\t'))
                {
                    if(input[i] == '\t') ++depth;
                    ++i;
                }
                int j = i;
                while(j < n && input[j] != '\n' && input[j] != '\t') ++j;
                const auto& temp = input.substr(i, j - i);
                if(depth == s.size())
                {
                    s.push(temp);
                    currentLen += 1 + temp.size();
                }
                else
                {
                    while(depth < s.size())
                    {
                        currentLen -= s.top().size() + 1;
                        s.pop();
                    }
                    s.push(temp);
                    currentLen += 1 + temp.size();
                }

                if(temp.find('.') != std::string::npos)
                    res = max(res, currentLen);

                i = j;
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    std::cout<<s.lengthLongestPath("dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext")<<std::endl;
}
