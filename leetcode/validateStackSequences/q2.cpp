#include "header.h"

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int i = 0, n = pushed.size();
        for(int num : popped)
        {
            if(!s.empty() && s.top() == num)
            {
                s.pop();
            }
            else
            {
                while(i < n)
                {
                    s.push(pushed[i]);
                    ++i;
                    if(s.top() == num) break;
                }
                if(s.top() == num) s.pop();
                else return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution s;
    vector<int> a{1,2,3,4,5};
    vector<int> b{4,5,3,2,1};
    cout<<s.validateStackSequences(a, b)<<endl;
}
