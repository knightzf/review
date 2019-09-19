#include "header.h"

class Solution {
public:
    int evaluate(string expression) {
        return eval(expression, {});
    }

    int eval(const string& exp, unordered_map<string, int> m) {
        if(exp[0] == '(') {
            const vector<string>& tokens = tokenize(exp);
            if(tokens[0] == "add") {
                return eval(tokens[1], m) + eval(tokens[2], m);
            } else if(tokens[0] == "mult") {
                return eval(tokens[1], m) * eval(tokens[2], m);
            } else {
                for(int i = 1; i < tokens.size() - 1; i += 2) {
                    m[tokens[i]] = eval(tokens[i + 1], m);
                }
                return eval(tokens.back(), m);
            }
        } else {
            if(isalpha(exp[0])) return m[exp];
            return stoi(exp);
        }
    }

    vector<string> tokenize(const string& exp) {
        vector<string> res;
        for(int i = 1, n = exp.size() - 1; i < n;) {
            int j = i + 1;
            if(exp[i] == '(') {
                int cnt = 1;
                while(j < n && cnt) {
                    if(exp[j] == '(') ++cnt;
                    else if(exp[j] == ')') --cnt;
                    ++j;
                }
            } else {
                while(j < n && exp[j] != ' ') ++j;
            }
            res.push_back(exp.substr(i, j - i));
            i = j + 1;
        }
        return res;
    }
};

int main()
{
    //Solution s;
}