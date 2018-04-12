#include "header.h"

class Solution {
public:
    int maximumSwap(int num) {
        vector<vector<int>> m(10);
        vector<int> v;
        int idx = 0;
        while(num)
        {
            m[num % 10].push_back(idx++);
            v.push_back(num % 10);
            num /= 10;
        }

        idx = v.size() - 1;
        for(int i = 9; i >=0; --i)
        {
            bool done = false;
            while(!m[i].empty())
            {
                //std::cout<<i<<" "<<v[idx]<<std::endl;
                if(i != v[idx])
                {
                    //std::cout<<idx<<" "<<m[i][0]<<" "<<int(v.size() - 1)<<" "<<abs(m[i][0] - int(v.size() - 1))<<std::endl;
                    swap(v[idx], v[m[i][0]]);
                    done = true;
                    break;
                }
                else
                {
                    m[i].pop_back();
                    --idx;
                }
            }
            if(done) break;
        }

        int res = 0;
        for(int i = v.size() - 1; i >= 0; --i)
            res = res * 10 + v[i];
        return res;
    }
};

int main()
{
    Solution s;
    std::cout<<s.maximumSwap(2736)<<std::endl;
    std::cout<<s.maximumSwap(12)<<std::endl;
    //std::cout<<s.maximumSwap(6773)<<std::endl;
    //std::cout<<s.maximumSwap(0)<<std::endl;
    std::cout<<s.maximumSwap(98368)<<std::endl;
}
