#include "header.h"

class Solution {
public:
    vector<int> beautifulArray(int N) {
         vector<int> res = {1};
         while(res.size() < N)
         {
             vector<int> t;
             for(int i : res) if(i * 2 - 1 <= N) t.push_back(i * 2 - 1);
             for(int i : res) if(i * 2 <= N) t.push_back(i * 2);
             res = t;
         } 
         return res;
    }    
};


int main()
{
    Solution s;
    const auto& r = s.beautifulArray(100);
    for(int i : r)
        cout<<i<<" ";
    cout<<endl;
}
