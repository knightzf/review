#include "header.h"

class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        int n = rectangles.size();
        long res = 0;

        vector<pair<int, pair<int, pair<int, int>>>> v;
        v.reserve(n);
        for(const auto& p : rectangles)
        {
            v.push_back(make_pair(p[0],
                                  make_pair(1, make_pair(p[1], p[3]))
                                  ));
            v.push_back(make_pair(p[2],
                                  make_pair(-1, make_pair(p[1], p[3]))
                                  ));
        }
        sort(v.begin(), v.end(), [](const auto& a, const auto& b){
                if(a.first < b.first) return true;
                else if(a.first == b.first)
                {
                    if(a.second.first > b.second.first) return true;
                    else if(a.second.first == b.second.first)
                    {
                        return a.second.second < b.second.second;
                    }
                    return false;
                }
                return false;
             });

        int prevHeight = -1;
        int prevIdx = -1;
        map<pair<int, int>, int> m;
        for(int i = 0; i < v.size();)
        {
            //cout<<"i "<<i<<" "<<v[i].first<<endl;
            int j = i;
            while(v[j].first == v[i].first) ++j;

            for(int k = i; k < j; ++k)
            {
                if(v[k].second.first == 1)
                    ++m[v[k].second.second];
                else
                {
                    int t = m[v[k].second.second];
                    if(t == 1)
                        m.erase(v[k].second.second);
                    else
                        --m[v[k].second.second];
                }
            }

            int height = calc(m);
            //cout<<"height "<<height<<endl;
            if(prevHeight != -1)
            {
                res += (v[i].first - prevIdx) * (long)prevHeight;
                //cout<<(v[i].first - prevIdx) * (long)prevHeight<<endl;
            }


            prevHeight = height;
            prevIdx = v[i].first;
            i = j;
        }

        return res % 1000000007;
    }

    int calc(map<pair<int, int>, int>& m)
    {
        int res = 0;
        for(auto iter = m.begin(); iter != m.end();)
        {
            auto p = iter->first;
            auto jter = iter;
            while(true)
            {
                ++jter;
                if(jter != m.end() &&
                   jter->first.first >= p.first &&
                   jter->first.first <= p.second)
                {
                    p.second = max(p.second, jter->first.second);
                }
                else
                    break;
            }

            res += p.second - p.first;
            iter = jter;
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> a{{0,0,2,2},{1,0,2,3},{1,0,3,1}};
    cout<<s.rectangleArea(a)<<endl;
}
