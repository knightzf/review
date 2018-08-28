#include "header.h"

using Number = pair<int, int>;

class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
        vector<Number> v;
        for(int i : nums) v.emplace_back(make_pair(i, 1));
        return impl(v);
    }

    bool impl(const vector<Number>& v)
    {
        if(v.size() == 1 && v[0].first % v[0].second == 0 && v[0].first / v[0].second == 24) return true;
        
        for(int i = 0, n = v.size(); i < n; ++i)
        {
            for(int j = i + 1; j < n; ++j)
            {
                vector<Number> t;
                for(int k = 0; k < n; ++k)
                {
                    if(k != i && k != j) t.push_back(v[k]);
                }
                
                t.push_back(add(v[i], v[j]));
                if(impl(t)) return true;
                t.pop_back();

                t.push_back(subtract(v[i], v[j]));
                if(impl(t)) return true;
                t.pop_back();

                t.push_back(subtract(v[j], v[i]));
                if(impl(t)) return true;
                t.pop_back();

                t.push_back(multiply(v[i], v[j]));
                if(impl(t)) return true;
                t.pop_back();

                if(v[j].first != 0)
                {
                    t.push_back(divide(v[i], v[j]));
                    if(impl(t)) return true;
                    t.pop_back();
                }
                
                if(v[i].first != 0)
                {
                    t.push_back(divide(v[j], v[i]));
                    if(impl(t)) return true;
                }
            }
        }
        return false;
    }

    Number add(const Number& a, const Number& b)
    {
        return Number(a.first * b.second + b.first * a.second, a.second * b.second);
    }

    Number subtract(const Number& a, const Number& b)
    {
        return Number(a.first * b.second - b.first * a.second, a.second * b.second);
    }

    Number multiply(const Number& a, const Number& b)
    {
        return Number(a.first * b.first, a.second * b.second);
    }

    Number divide(const Number& a, const Number& b)
    {
        return Number(a.first * b.second, a.second * b.first);
    }    
};

int main() {
    Solution s;
    vector<int> a{1, 2, 1, 2};
    cout<<s.judgePoint24(a)<<endl;
}
