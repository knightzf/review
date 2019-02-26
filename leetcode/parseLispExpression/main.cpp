#include "header.h"

class Solution {
public:
    int evaluate(string expression) {
        return impl(expression);
    }

    int impl(const string& exp,
            const unordered_map<string, int>& m = unordered_map<string, int>())
    {
        if(exp[0] != '(')
        {
            if(m.count(exp)) return m.at(exp);
            return stoi(exp);
        }

        vector<string> tokens;
        int startIdx = 1, endIdx = exp.size(), parenthesisCount = 0;
        for(int i = startIdx; i < endIdx; ++i)
        {
            if(i != endIdx - 1)
            {
                if(exp[i] == '(') ++parenthesisCount;
                else if(exp[i] == ')') --parenthesisCount;
            }

            if(i == endIdx - 1 || (exp[i] == ' ' && parenthesisCount == 0))
            {
                tokens.emplace_back(exp.substr(startIdx, i - startIdx));
                startIdx = i + 1;
            }
        }

        unordered_map<string, int> tm = m;
        if(tokens[0] == "let")
        {
            for(int i = 1; i < tokens.size() - 1; i += 2)
            {
                tm[tokens[i]] = impl(tokens[i + 1], tm);
            }
            
            return impl(tokens.back(), tm);
        }
        else if(tokens[0] == "add")
        {
            return impl(tokens[1], tm) + impl(tokens[2], tm);
        }
        return impl(tokens[1], tm) * impl(tokens[2], tm);
    }
};

int main()
{
    Solution s;
    //string a = "(add 1 2)";
    //string a = "(mult 3 (add 2 3))";
    //string a = "(let x 2 (mult x 5))";
    //string a = "(let x 2 (mult x (let x 3 y 4 (add x y))))";
    //string a = "(let x 3 x 2 x)";
    string a = "(let x 1 y 2 x (add x y) (add x y))";
    //string a = "(let x 2 (add (let x 3 (let x 4 x)) x))";
    //string a = "(let a1 3 b2 (add a1 1) b2)";
    cout<<s.evaluate(a)<<endl;
}