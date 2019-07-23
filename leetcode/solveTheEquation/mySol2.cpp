#include "header.h"

class Solution {
public:
    string solveEquation(string equation) {
        int idx = equation.find('=');
        const auto& left = parse(equation.substr(0, idx));
        const auto& right = parse(equation.substr(idx + 1));
        int coef = left.first - right.first;
        int num = right.second - left.second;
        if(coef == 0) {
            if(num == 0) return "Infinite solutions";
            return "No solution";
        }
        return "x=" + to_string(num / coef);
    }

    pair<int, int> parse(const string& s) {
        int coef = 0, num = 0;
        int sign = 1, t = 0;
        bool hasnum = false;
        for(char c : s) {
            switch(c) {
                case 'x':
                coef += sign * (hasnum ? t : 1);
                t = 0;
                sign = 1;
                hasnum = false;
                break;
                case '+':
                case '-':
                num += sign * t;
                t = 0;
                sign = c == '+' ? 1 : -1;
                hasnum = false;
                break;
                default:
                t = t * 10 + c - '0';
                hasnum = true;
                break;
            }
        }
        num += sign * t;
        return make_pair(coef, num);
    }
};

int main()
{
    Solution s;
}