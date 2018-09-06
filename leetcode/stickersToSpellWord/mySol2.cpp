#include "header.h"

class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
        vector<unordered_map<char, int>> s;
        unordered_set<char> all;
        for(auto& str : stickers)
        {
            unordered_map<char, int> m;
            for(char c : str)
            {
                all.insert(c);
                ++m[c];
            }
            s.emplace_back(m);
        }

        for(char c : target)
        {
            if(!all.count(c)) return -1;
        }

        unordered_map<string, int> dp;
        sort(target.begin(), target.end());
        impl(s, dp, target);
        return dp[target];
    }

    int impl(vector<unordered_map<char, int>>& s, unordered_map<string, int>& dp, const string& target)
    {
        if(target.empty()) return 0;

        if(!dp.count(target)) {
            int res = INT_MAX;
            for(const auto& m : s)
            {
                string newTarget;
                for(int i = 0, n = target.size(); i < n; )
                {
                    if(m.count(target[i]))
                    {
                        int j = i;
                        while(j < n && target[j] == target[i]) ++j;
                        auto iter = m.find(target[i]);
                        int remain = max(j - i - iter->second, 0);
                        newTarget += string(remain, target[i]);
                        i = j;
                    }
                    else
                    {
                        newTarget += target[i];
                        ++i;
                    }    
                }
                if(newTarget != target) res = min(res, impl(s, dp, newTarget));
            }
            res += 1;

            dp[target] = res;
        }

        return dp[target];
    }
};

int main() {
    Solution s;
    vector<string> a{"with", "example", "science"};
    cout<<s.minStickers(a, "thehat")<<endl;
}
