#include "header.h"

class Solution {
public:
    string countOfAtoms(string formula) {
        const map<string, int>& res = impl(formula);
        stringstream ss;
        for(auto& p : res)
        {
            ss << p.first;
            if(p.second > 1)
                ss << p.second;
        }
        return ss.str();
    }

    map<string, int> impl(const auto& formula)
    {
        map<string, int> res;
        for(int i = 0, n = formula.size(); i < n;)
        {
            if(formula[i] == '(')
            {
                int j = i;
                int cnt = 0;
                while(j < n)
                {
                    if(formula[j] == '(') ++cnt;
                    else if(formula[j] == ')') --cnt;
                    ++j;
                    if(cnt == 0) break;
                }
                const auto& t = impl(formula.substr(i + 1, j - i - 2));
                int multiplier = 1;
                if(j < n && isdigit(formula[j]))
                {
                    int k = j;
                    while(++k < n && isdigit(formula[k])){}
                    multiplier = stoi(formula.substr(j, k - j));
                    j = k;
                }
                for(auto& p : t)
                {
                    res[p.first] += p.second * multiplier;
                }
                i = j;
            }
            else
            {
                int j = i + 1;
                while(j < n && islower(formula[j]))
                {
                    ++j;
                }
                const auto& atom = formula.substr(i, j - i);
                int multiplier = 1;
                if(j < n && isdigit(formula[j]))
                {
                    int k = j;
                    while(++k < n && isdigit(formula[k])){}
                    multiplier = stoi(formula.substr(j, k - j));
                    j = k;
                }
                res[atom] += multiplier;
                i = j;
            }
        }
        return res;
    }
};

int main() {
    Solution s;
}
