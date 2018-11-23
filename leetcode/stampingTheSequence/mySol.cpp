#include "header.h"

class Solution {
    int m, n;
    unordered_map<string, int> mm;
public:
    vector<int> movesToStamp(string stamp, string target) {
        m = stamp.size(), n = target.size();
        const vector<int>& seq = validate(stamp, target);
        
        if(!seq.empty())
        {
            vector<pair<int, int>> v;
            for(int i = 0; i < n; ++i)
            {
                if(i == 0 || (seq[i] != seq[i - 1] + 1))
                {
                    v.push_back({i, seq[i]});
                }
            }

            int sz = v.size();
            vector<bool> visited(sz, false);
            vector<unordered_set<int>> graph(sz);
            vector<int> degree(sz, 0);
            for(int i = 0; i < sz; ++i)
            {
                int j = i - 1;
                if(j >= 0)
                {
                    if(v[i].second != 0)
                    {
                        graph[i].insert(j);
                        ++degree[j];
                    }
                    else if(v[j].first + m - v[j].second - 1 >= v[i].first)
                    {
                        graph[j].insert(i);
                        ++degree[i];
                    }
                }
            }

            queue<int> free;
            for(int i = 0; i < sz; ++i)
            {
                if(degree[i] == 0) {
                    free.push(i);
                }
            }

            vector<int> res;
            while(!free.empty())
            {
                int i = free.front();
                free.pop();

                res.push_back(v[i].first - v[i].second);
                visited[i] = true;
                for(int j : graph[i])
                {
                    --degree[j];
                    if(degree[j] == 0) free.push(j);
                }
            }

            for(int i = 0; i < sz; ++i)
            {
                if(visited[i] == false)
                {
                    res.push_back(v[i].first - v[i].second);
                }
            }
            return res;
        }

        return {};
    }

    vector<int> validate(const string& stamp, const string& target)
    {
        vector<vector<int>> v(26);
        for(int i = 0; i < m; ++i) v[stamp[i] - 'a'].push_back(i);

        vector<vector<pair<int, int>>> candidates(n);
        for(int i = 0; i < n; ++i)
        {
            for(int j : v[target[i] - 'a'])
            {
                if(i >= j && i + m - j <= n)
                {
                    if(i > 0)
                    {
                        if(j == 0) candidates[i].push_back(
                            make_pair(candidates[i - 1][0].second, j));
                        else 
                        {
                            for(auto& p : candidates[i - 1])
                            {
                                if(p.second == j - 1 || p.second == m - 1) 
                                    candidates[i].push_back(make_pair(p.second, j));
                            }
                        }
                    }
                    else candidates[i].push_back(make_pair(-1, j));
                }                
            }
            
            if(candidates[i].empty()) break;            
        }

        vector<int> res;
        if(!candidates.back().empty())
        {
            if(n == 1) res.push_back(0);
            else
            {
                for(int i = n - 1; i > 0; --i)
                {
                    if(i == n - 1) {
                        res.push_back(candidates[i][0].second);
                        res.push_back(candidates[i][0].first);
                    }
                    else {
                        for(const auto& p : candidates[i])
                        {
                            if(p.second == res.back())
                            {
                                res.push_back(p.first);
                                break;
                            }
                        }
                    }
                }
                reverse(res.begin(), res.end());
            }
        }
        
        for(int i = 0; i < n; ++i)
        {
            cout<<i<<" | ";
            for(auto& p : candidates[i])
                cout<<p.first<<" "<<p.second<<" | ";
            cout<<endl;
        }

        for(int i : res)
            cout<<i<<" ";
        cout<<endl;
        return res;
    }
};

int main()
{
    Solution s;
    //const auto& r = s.movesToStamp("abc", "ababc");
    //const auto& r = s.movesToStamp("abca", "aabcaca");
    //const auto& r = s.movesToStamp("voy", "vvyyvoyvvoyoyoy");
    //const auto& r = s.movesToStamp("v", "v");
    const auto& r = s.movesToStamp("df", "dfdff");
    for(int i : r)
    cout<<i<<" ";
    cout<<endl;
}
