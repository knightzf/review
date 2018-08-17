#include "header.h"

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        vector<pair<int, int>> v;
        for(int i = 0, n = nums.size(); i < n; ++i)
        {
            if(v.empty())
            {
                v.push_back(make_pair(nums[i], 1));
            }
            else
            {
                if(nums[i] == v.back().first)
                {
                    ++v.back().second;
                }
                else if(nums[i] == v.back().first + 1)
                {
                    v.push_back(make_pair(nums[i], 1));
                }
                else
                {
                    if(!check(v)) return false;
                    v.clear();
                }
            }
        }

        return check(v);
    }

    bool check(vector<pair<int, int>>& v)
    {
        vector<pair<int, int>> m;
        for(int i = 0, n = v.size(); i < n; ++i)
        {
            while(v[i].second)
            {
                pair<int, int> t{v[i].first, v[i].first};
                --v[i].second;
                for(int j = i + 1; j < n; ++j)
                {
                    if(v[j].second)
                    {
                        t.second = v[j].first;
                        --v[j].second;
                    }
                    else
                    {
                        break;
                    }
                }
                m.emplace_back(t);
            }
        }
        /*for(auto& i : m)
        {
            cout<<i.first<<" "<<i.second<<endl;
        }
        //*/
        for(int i = 0, n = m.size(); i < n; ++i)
        {
            if(m[i].second - m[i].first + 1 < 3)
            {
                bool found = false;
                for(int j = 0; j < i; ++j)
                {
                    if(m[i].first >= m[j].first && m[i].first <= m[j].second)
                    {
                        if(m[i].second - m[j].first + 1 >= 3 && m[j].second - m[i].first + 1 >= 3)
                        {
                            found = true;
                            m[j].first = m[i].first;
                            break;
                        }
                    }
                    else if(m[i].second >= m[j].first && m[i].second <= m[j].second)
                    {
                        if(m[j].second - m[i].first + 1 >= 3 && m[i].second - m[j].first + 1 >= 3)
                        {
                            found = true;
                            m[j].second = m[i].second;
                            break;
                        }
                    }
                }

                if(!found) return false;
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    vector<int> a{1, 2, 3, 4, 4, 5};
    //vector<int> a{1};
    cout<<s.isPossible(a)<<endl;;
}
