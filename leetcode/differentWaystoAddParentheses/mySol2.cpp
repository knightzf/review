#include "header.h"

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        unordered_map<string, vector<int>> m;

        function<vector<int>(const string&)> dfs = [&](const string& s) {
            if(m.count(s)) return m[s];

            vector<int> res;
            for(int i = 0; i < s.size(); ++i) {
                if(s[i] == '+' || s[i] == '-' || s[i] == '*') {
                    const auto& r1 = dfs(s.substr(0, i));
                    const auto& r2 = dfs(s.substr(i + 1));
                    for(int x : r1) {
                        for(int y : r2) {
                            if(s[i] == '+') res.push_back(x + y);
                            else if(s[i] == '-') res.push_back(x - y);
                            else res.push_back(x * y);
                        }
                    }
                }
            }
            if(res.empty()) res.push_back(stoi(s));
            return res;
        };

        return dfs(input);
    }
};

int main()
{
    //Solution s;
}