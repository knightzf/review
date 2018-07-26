#include "header.h"

class Solution {
public:
    int smallestFactorization(int a) {
        vector<pair<int, int>> v{{2, 0}, {3, 0}, {5, 0}, {7, 0}};
        for(auto& p : v)
        {
            int i = 0;
            while(a % (int)pow(p.first, i) == 0) ++i;
            p.second = i - 1;
            a /= pow(p.first, p.second);
        }

        if(a != 1) return 0;

        string res = dfs(v[0].second, v[1].second);
        for(int i = 0; i < v[2].second; ++i)
            res += '5';
        for(int i = 0; i < v[3].second; ++i)
            res += '7';
        sort(res.begin(), res.end());

        if(res.empty()) return 1;
        if(res.size() > 10 || stol(res) > INT_MAX) return 0;
        return stoi(res);
    }

    string dfs(int n2, int n3)
    {
        static map<pair<int, int>, string> m;

        auto key = make_pair(n2, n3);
        if(m.count(key) == 0) {
            if(n2 == 0 && n3 == 0) {
                m[key] = "";
            }
            else if(n3 == 0)
            {
                string res;
                while(n2)
                {
                    if(n2 >= 3)
                    {
                        res += '8';
                        n2 -= 3;
                    }
                    else if(n2 >= 2)
                    {
                        res += '4';
                        n2 -= 2;
                    }
                    else
                    {
                        res += '2';
                        n2--;
                    }
                }
                reverse(res.begin(), res.end());
                m[key] = res;
            }
            else if(n2 == 0)
            {
                string res;
                while(n3)
                {
                    if(n3 >= 2)
                    {
                        res += '9';
                        n3 -= 2;
                    }
                    else
                    {
                        res += '3';
                        n3--;
                    }
                }
                reverse(res.begin(), res.end());
                m[key] = res;

            }
            else
            {
                string res = '2' + dfs(n2 - 1, n3);
                sort(res.begin(), res.end());
                if(n2 >= 3)
                {
                    string t = '8' + dfs(n2 - 3, n3);
                    sort(t.begin(), t.end());
                    if(t.size() < res.size())
                        res = t;
                    else if(t.size() == res.size())
                        res = min(res, t);
                }

                if(n2 >= 2)
                {
                    string t = '4' + dfs(n2 - 2, n3);
                    sort(t.begin(), t.end());
                    if(t.size() < res.size())
                        res = t;
                    else if(t.size() == res.size())
                        res = min(res, t);
                }


                string t = '6' + dfs(n2 - 1, n3 - 1);
                sort(t.begin(), t.end());
                if(t.size() < res.size())
                    res = t;
                else if(t.size() == res.size())
                    res = min(res, t);
                m[key] = res;
            }
        }

        return m[key];

    }
};

int main() {
    Solution s;
    cout<<s.smallestFactorization(192)<<endl;
}
