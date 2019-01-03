#include "header.h"

class Solution {
public:
    int leastOpsExpressTarget(int x, int target) {
        unordered_map<int, int> m;
        m[1] = 1;
        m[x] = 0;
        for(int i = 1; ; ++i)
        {
            int a = 1 + i;
            int b = x - i;
            
            if(b < a) break;

            m[a] = m[a - 1] + 2;
            m[b] = m[b + 1] + 2;           
        }

        function<int(int, int, bool)> f = [&](int x, int target, bool checkupper)
        {
            //cout<<x<<" "<<target<<" "<<checkupper<<endl;
            if(!m.count(target)) 
            {
                int p = 1;
                while(pow(x, p) < target) ++p;

                if(pow(x, p) == target) 
                {
                    m[target] = p - 1;
                }
                else
                {
                    int lower = pow(x, p - 1);
                    int upper = pow(x, p);

                    int t = p - 1 + f(x, target - lower, (target - lower > lower ? false : true));
                    if(checkupper)
                    {
                        int tt = f(x, upper - target, (upper - target > lower ? false : true));
                        t = min(t, p + tt);
                        m[upper - target] = min(tt, p + t);
                    }

                    m[target] = t;
                }
            }

            return m[target];
        };
        
        int res = f(x, target, true);
        /*cout<<"----"<<endl;
        for(auto& p : m)
            cout<<p.first<<" "<<p.second<<endl;*/
        return res;
    }
};

int main()
{
    Solution s;
    //cout<<s.leastOpsExpressTarget(3, 19)<<endl;
    //cout<<s.leastOpsExpressTarget(5, 501)<<endl;
    //cout<<s.leastOpsExpressTarget(100, 100000000)<<endl;
    cout<<s.leastOpsExpressTarget(2, 125046)<<endl;
}
