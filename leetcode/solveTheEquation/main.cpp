#include "header.h"

class Solution {
public:
    string solveEquation(string equation) {
        int equalIdx = equation.find("=");
        auto left = parse(equation.substr(0, equalIdx));
        auto right = parse(equation.substr(equalIdx + 1));
        int xParam = left.first - right.first;
        int num = right.second - left.second;
        if(xParam == 0)
        {
            if(num == 0) return "Infinite solutions";
            else return "No solution";
        }
        return "x=" + to_string(num/xParam);
    }

    pair<int, int> parse(const string& s)
    {
        auto f = [](const string& sub)
        {
            if(sub.back() == 'x')
            {
                int t = 0;
                if(sub.size() == 1) t = 1;
                else if(sub.size() == 2 && !isdigit(sub[0])) t = sub[0] == '+' ? 1 : -1;
                else t = stoi(sub.substr(0, sub.size() - 1));
                return make_pair(t, 0);
            }
            else
            {
                return make_pair(0, stoi(sub));
            }
        };
        pair<int, int> res{0, 0};
        int startIdx = 0;
        for(int i = 0, n = s.size(); i < n; ++i)
        {
            if(i != 0 && (s[i] == '+' || s[i] == '-'))
            {
                const auto& t = f(s.substr(startIdx, i - startIdx));
                res.first += t.first;
                res.second += t.second;
                startIdx = i;
            }
        }

        const auto& t = f(s.substr(startIdx));
        res.first += t.first;
        res.second += t.second;
        return res;
    }
};


int main() {
    Solution s;
    //s.solveEquation("x+5-3+x=6+x-2");
    s.solveEquation("-x=-1");
}
