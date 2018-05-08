#include "header.h"

class Solution {
private:
    int n;
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        vector<vector<string>> res;
        if(words.empty()) return res;
        n = words[0].size();

        unordered_map<string, vector<string>> m;
        for(const auto& w : words)
        {
            for(int i = 1; i <= n; ++i)
            {
                m[w.substr(0, i)].push_back(w);
            }
        }

        for(int i = 0; i < words.size(); ++i)
        {
            vector<string> t{words[i]};
            impl(res, m, t, 1);
            t.pop_back();
        }

        return res;
    }

    void impl(vector<vector<string>>& res, unordered_map<string, vector<string>>& m,
              vector<string>& square, int idx)
    {
        if(square.size() == n)
        {
            res.push_back(square);
            return;
        }

        string prefix;
        for(int i = 0; i < idx; ++i)
            prefix += square[i][idx];

        const auto& candidates = m[prefix];
        for(const auto& cand : candidates)
        {
            square.push_back(cand);
            impl(res, m, square, idx + 1);
            square.pop_back();
        }
    }
};

int main()
{
    Solution s;
    vector<string> a{"area","lead","wall","lady","ball"};
    const auto& r = s.wordSquares(a);
    for(const auto& i : r)
    {
        for(const auto& j : i)
            std::cout<<j<<std::endl;
        std::cout<<"----"<<std::endl;
    }
}
