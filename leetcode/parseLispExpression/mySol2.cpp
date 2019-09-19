#include "header.h"

class Solution {
public:
    int evaluate(string expression) {
        return eval(expression, 0, expression.size(), {});
    }

    int eval(const string& exp, int startIdx, int endIdx, unordered_map<string, int> m) {
        if(exp[startIdx] == '(') {
            const vector<pair<int, int>>& tokens = tokenize(exp, startIdx, endIdx);
            char oper = exp[tokens[0].first];
            if(oper == 'a') {
                return eval(exp, tokens[1].first, tokens[1].second, m) +
                    eval(exp, tokens[2].first, tokens[2].second, m);
            } else if(oper == 'm') {
                return eval(exp, tokens[1].first, tokens[1].second, m) *
                    eval(exp, tokens[2].first, tokens[2].second, m);
            } else {
                for(int i = 1; i < tokens.size() - 1; i += 2) {
                    m[exp.substr(tokens[i].first, tokens[i].second - tokens[i].first)] =
                        eval(exp, tokens[i + 1].first, tokens[i + 1].second, m);
                }
                return eval(exp, tokens.back().first, tokens.back().second, m);
            }
        } else {
            if(isalpha(exp[startIdx])) return m[exp.substr(startIdx, endIdx - startIdx)];
            return stoi(exp.substr(startIdx, endIdx - startIdx));
        }
    }

    vector<pair<int, int>> tokenize(const string& exp, int startIdx, int endIdx) {
        vector<pair<int, int>> res;
        for(int i = startIdx + 1; i < endIdx - 1;) {
            int j = i + 1;
            if(exp[i] == '(') {
                int cnt = 1;
                while(j < endIdx - 1 && cnt) {
                    if(exp[j] == '(') ++cnt;
                    else if(exp[j] == ')') --cnt;
                    ++j;
                }
            } else {
                while(j < endIdx - 1 && exp[j] != ' ') ++j;
            }
            res.push_back({i, j});
            i = j + 1;
        }
        return res;
    }
};

int main()
{
    //Solution s;
}