#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <sstream>
#include <cmath>
#include <queue>
#include <map>
#include <string>
#include <cstdlib>
#include <cctype>
#include <stdexcept>
#include <climits>
#include <utility>
#include <bitset>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <memory>

using namespace std;

struct ValueIndex
{
    ValueIndex(int val_, int idx_) : val(val_), idx(idx_) {}
    int val;
    int idx;
};

template<typename T> void print_queue(T& q) {
    while(!q.empty()) {
        std::cout << q.top().idx << " " << q.top().val << "|";
        q.pop();
    }
    std::cout << '\n';
}

class Solution {
public:
    vector<int> pourWater(vector<int>& heights, int V, int K)
    {
        if(heights.empty() || V == 0) return heights;

        int n = heights.size();

        auto cmp = [](const ValueIndex& a, const ValueIndex& b) {
            if(a.val > b.val)
            {
                return true;
            }
            else if(a.val == b.val)
            {
                return a.idx < b.idx;
            }

            return false;
        };

        std::priority_queue<ValueIndex, std::vector<ValueIndex>, decltype(cmp)> q1(cmp);
        for(int i = 0; i < K; ++i)
        {
            q1.push(ValueIndex(heights[i], i));
        }

        auto cmp1 = [](const ValueIndex& a, const ValueIndex& b) {
            if(a.val > b.val)
            {
                return true;
            }
            else if(a.val == b.val)
            {
                return a.idx > b.idx;
            }

            return false;
        };

        std::priority_queue<ValueIndex, std::vector<ValueIndex>, decltype(cmp1)> q2(cmp1);
        for(int i = K + 1; i < n; ++i)
        {
            q2.push(ValueIndex(heights[i], i));
        }

        if(q1.empty())
        {
            q1.push(ValueIndex(INT_MAX, 0));
        }

        if(q2.empty())
        {
            q2.push(ValueIndex(INT_MAX, 0));
        }

        //print_queue(q1);
        //print_queue(q2);

        for(int i = 0; i < V; ++i)
        {
            int val = heights[K];
            if(val <= q1.top().val && val <= q2.top().val)
            {
                ++heights[K];
            }
            else
            {
                std::cout<<val<<" "<< q1.top().val<<" "<<q2.top().val<<std::endl;
                if(val > q1.top().val + 1)
                {
                    ++heights[q1.top().idx];
                    q1.push(ValueIndex(q1.top().val + 1, q1.top().idx));
                    q1.pop();
                }
                else if(val > q2.top().val + 1)
                {
                    ++heights[q2.top().idx];
                    q2.push(ValueIndex(q2.top().val + 1, q2.top().idx));
                    q2.pop();
                }
                else
                {
                    ++heights[K];
                }
            }
        }

        return heights;
    }
};

int main()
{
    Solution s;
    vector<int> heights{1,2,3,4,3,2,1,2,3,4,3,2,1};
    const auto& a = s.pourWater(heights, 2, 5);
    for(auto i : a)
    {
        std::cout << i << " ";
    }
    std::cout<<std::endl;
}
