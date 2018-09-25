#include "header.h"

class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> res;
        bool hasBlock = false;
        string temp;
        for(int i = 0, n = source.size(); i < n; ++i)
        {
            if(hasBlock)
            {
                int idx = source[i].find("*/");
                if(idx != -1)
                {
                    source[i] = temp + source[i].substr(idx + 2);
                    --i;
                    //temp += source[i].substr(idx + 2);
                    //if(!temp.empty()) res.emplace_back(temp);
                    hasBlock = false;
                }
            }
            else
            {
                int simpleIdx = source[i].find("//");
                int blockIdx = source[i].find("/*");
                if(simpleIdx != -1 && blockIdx != -1)
                {
                    if(simpleIdx < blockIdx)
                    {
                        const auto& t = source[i].substr(0, simpleIdx);
                        if(!t.empty()) res.emplace_back(t);
                    }
                    else
                    {
                        temp = source[i].substr(0, blockIdx);
                        source[i] = source[i].substr(blockIdx + 2);
                        --i;
                        hasBlock = true;
                    }
                }
                else if(simpleIdx != -1)
                {
                    const auto& t = source[i].substr(0, simpleIdx);
                    if(!t.empty()) res.emplace_back(t);
                }
                else if(blockIdx != -1)
                {
                    temp = source[i].substr(0, blockIdx);
                    source[i] = source[i].substr(blockIdx + 2);
                    --i;
                    hasBlock = true;
                }
                else if(!source[i].empty())
                {
                    res.emplace_back(source[i]);
                }
            }
        }
        return res;
    }
};

int main() {
    Solution s;
}
