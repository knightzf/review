#include "header.h"

class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values,
                                vector<pair<string, string>> queries) {
        unordered_map<string, pair<string, double>> m;
        for(int i = 0; i < equations.size(); ++i)
        {
            if(m.find(equations[i].first) != m.end() && m.find(equations[i].second) != m.end())
            {
                const auto& p1 = getParent(equations[i].first, m);
                const auto& p2 = getParent(equations[i].second, m);

                if(p1.first != p2.first)
                {
                    m[p2.first].first = p1.first;
                    m[p2.first].second = p1.second / p2.second * values[i];
                }
            }
            else if(m.find(equations[i].first) == m.end() && m.find(equations[i].second) == m.end())
            {
                m[equations[i].first] = {equations[i].first, 1};
                m[equations[i].second] = {equations[i].first, values[i]};
            }
            else if(m.find(equations[i].first) == m.end())
            {
                m[equations[i].first].first = m[equations[i].second].first;
                m[equations[i].first].second = m[equations[i].second].second / values[i];
            }
            else if(m.find(equations[i].second) == m.end())
            {
                m[equations[i].second].first = m[equations[i].first].first;
                m[equations[i].second].second = m[equations[i].first].second * values[i];
            }

            /*for(const auto& p : m)
            {
                std::cout<<p.first<<" "<<p.second.first<<" "<<p.second.second<<" | ";
            }
            std::cout<<std::endl;*/
        }

        vector<double> res;
        for(const auto& p : queries)
        {
            if(m.find(p.first) == m.end() || m.find(p.second) == m.end())
            {
                res.push_back(-1);
                continue;
            }
            const auto& p1 = getParent(p.first, m);
            const auto& p2 = getParent(p.second, m);
            if(p1.first != p2.first) res.push_back(-1);
            else res.push_back(p2.second / p1.second);
        }

        return res;
    }

    pair<string, double> getParent(const string& variable, unordered_map<string, pair<string, double>>& m)
    {
        pair<string, double> res = m[variable];
        while(m[res.first].first != res.first)
        {
            res.second = m[res.first].second * res.second;
            res.first = m[res.first].first;
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<pair<string, string>> equations{{"a", "e"}, {"b", "e"}};
    vector<double> values{4, 3};
    vector<pair<string, string>> queries{{"a", "b"}};
    s.calcEquation(equations, values, queries);
}
