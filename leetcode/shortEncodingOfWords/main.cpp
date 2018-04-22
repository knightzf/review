#include "header.h"

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        unordered_set<string> ss(words.begin(), words.end());
        unordered_set<string> s;
        for(const auto& w : ss)
        {
            int n = w.size();
            for(int i = 1; i < n; ++i)
            {
                //s.insert(w.substr(0, i));
                s.insert(w.substr(n - i, i));
            }
        }

        int len = 0;
        for(const auto& w : ss)
        {
            if(s.find(w) == s.end())
            {
                len += w.size() + 1;
            }
        }

        return len;
    }
};

int main()
{
    Solution s;
    //vector<string> a{"time","time","time","time"};
    vector<string> a{"a","a","b","b"};
    std::cout<<s.minimumLengthEncoding(a)<<std::endl;
}
