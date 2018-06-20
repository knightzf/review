#include "header.h"

class Solution {
private:
    int n;
public:
    int change(int amount, vector<int>& coins) {
        if(amount == 0) return 1;
        n = coins.size();

        unordered_map<int, int> m{{0, 1}};
        for(int i = 0; i < n; ++i)
        {
            unordered_map<int, int> t;
            for(const auto& p : m)
            {
                int j = 1;
                while(p.first + j * coins[i] <= amount)
                {
                    int num = p.first + j * coins[i];
                    t[num] += p.second;
                    ++j;
                }
            }

            for(const auto& p : t)
            {
                if(m.count(p.first) == 0)
                    m[p.first] = p.second;
                else
                    m[p.first] += p.second;
            }

            /*for(const auto& p : m)
                std::cout<<p.first<<","<<p.second<<" | ";
            cout<<endl;*/
        }

        return m.count(amount) ? m[amount] : 0;
    }
};

int main()
{
    Solution s;
    if(true){
        vector<int> a{102, 89, 76, 63, 50, 37, 24, 11};
        cout<<s.change(5000, a)<<endl;
    }
    {
        vector<int> a{1, 2, 5};
        cout<<s.change(5, a)<<endl;
    }
}
