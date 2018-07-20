#include "header.h"

class Solution {
public:
    string fractionAddition(string expression) {
        int n = expression.size();
        vector<int> operIdx;
        while(true)
        {
            int startPos = operIdx.empty() ? 1 : (operIdx.back() + 1);
            int plusIdx = expression.find('+', startPos);
            int minusIdx = expression.find('-', startPos);
            if(plusIdx == -1 && minusIdx == -1) break;
            else if(plusIdx == -1)
            {
                operIdx.emplace_back(minusIdx);
            }
            else if(minusIdx == -1)
            {
                operIdx.emplace_back(plusIdx);
            }
            else
            {
                operIdx.emplace_back(min(plusIdx, minusIdx));
            }
        }

        if(operIdx.empty()) return expression;

        auto num = convert(expression.substr(0, operIdx[0]));
        for(int i = 0; i < operIdx.size(); ++i)
        {
            if(i != operIdx.size() - 1)
            {
                num = add(num, convert(expression.substr(operIdx[i], operIdx[i + 1] - operIdx[i])));
            }
            else
            {
                num = add(num, convert(expression.substr(operIdx[i])));
            }
        }
        return to_string(num.first) + "/" + to_string(num.second);
    }

    pair<int, int> convert(const string& str)
    {
        int pos = str.find('/');
        return {stoi(str.substr(0, pos)), stoi(str.substr(pos + 1))};
    }

    pair<int, int> add(const pair<int, int>& a, const pair<int, int>& b)
    {
        //cout<<a.first<<" "<<a.second<<" | "<<b.first<<" "<<b.second<<endl;
        pair<int, int> res;
        if(a.second % b.second == 0)
        {
            res.first = a.first + a.second / b.second * b.first;
            res.second = a.second;
        }
        else if(b.second % a.second == 0)
        {
            res.first = b.first + b.second / a.second * a.first;
            res.second = b.second;
        }
        else
        {
            res.first = a.first * b.second + b.first * a.second;
            res.second = a.second * b.second;
        }

        shrink(res);
        return res;
    }

    void shrink(pair<int, int>& p)
    {
        if(p.first == 0) p.second = 1;
        else {
            //cout<<p.first<<" "<<p.second<<" "<<endl;
            int lcd = getLcd(abs(p.first), abs(p.second));
            p.first /= lcd;
            p.second /= lcd;
        }
    }

    int getLcd(int a, int b)
    {
        if(a == b) return a;
        if(a < b) swap(a, b);
        if(a % b == 0) return b;
        return getLcd(b, a - b);
    }
};


int main()
{
    Solution s;
    cout<<s.fractionAddition("-4/7-3/4+2/3")<<endl;
}
