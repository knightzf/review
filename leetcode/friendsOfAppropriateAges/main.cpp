#include "header.h"

class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        vector<int> v(121, 0);
        for(int age : ages)
        {
            ++v[age];
        }

        int cnt = 0;
        for(int age: ages)
        {
            int bot = 0.5 * age + 7;
            for(int i = bot + 1; i <= age; ++i)
            {
                cnt += (i == age ? v[i] - 1 : v[i]);
            }
        }
        return cnt;
    }
};

int main()
{
    Solution s;
    if(0){
        vector<int> a{16, 16};
        std::cout<<s.numFriendRequests(a)<<std::endl;
    }
    if(0){
        vector<int> a{16, 17, 18};
        std::cout<<s.numFriendRequests(a)<<std::endl;
    }
    {
        vector<int> a{20, 30, 100, 110, 120};
        std::cout<<s.numFriendRequests(a)<<std::endl;
    }

}
