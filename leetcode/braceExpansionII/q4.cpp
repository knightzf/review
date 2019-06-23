#include "header.h"

class Solution {
public:
    vector<string> braceExpansionII(string expression) {        
        int n = expression.size();
        unordered_map<int, int> m;
        stack<int> s;
        for(int i = 0; i < n; ++i) {
            if(expression[i] == '{') s.push(i);
            if(expression[i] == '}') {
                m[s.top()] = i;
                s.pop();
            }
        }
        function<set<string>(int, int)> f = [&](int startIdx, int endIdx)
        {
            vector<set<string>> res;
            bool newSection = true;
            for(int i = startIdx; i < endIdx; ++i) {
                if(expression[i] == '{') {
                    const auto& r = f(i + 1, m[i]);
                    if(newSection) res.emplace_back(r);
                    else res.back() = mul(res.back(), r);
                    i = m[i];
                    newSection = false;
                }
                else if(isalpha(expression[i])) {
                    set<string> r{string(1, expression[i])};
                    if(newSection) res.emplace_back(r);
                    else res.back() = mul(res.back(), r);
                    newSection = false;
                } else {
                    newSection = true;
                }
            }
            for(int i = 1, n = res.size(); i < n; ++i)
                add(res[0], res[i]);
            return res[0];
        };
        const auto& r = f(0, n);
        return vector<string>(r.begin(), r.end());
    }

    void add(set<string>& a, const set<string>& b) {
        for(const auto& t : b) a.insert(t);
    }

    set<string> mul(const set<string>& a, const set<string>& b) {
        set<string> res;
        for(const auto& t : a) {
            for(const auto& p : b) {
                res.insert(t + p);
            }
        }
        return res;
    };
};

int main()
{
    Solution s;
    //const auto& r = s.braceExpansionII("{a,b}{c{d,e}}");
    const auto& r = s.braceExpansionII("{{a,z},a{b,c},{ab,z}}");
    for(const auto& t : r) cout<<t<<endl;
}
