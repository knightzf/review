#include "header.h"

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> res(n, 0);
        int currentTime = 0;
        stack<int> stk;
        for(const auto& s : logs)
        {
            auto p1 = s.find_first_of(':');
            auto p2 = s.find_last_of(':');
            int id = std::stoi(s.substr(0, p1));
            bool start = s.substr(p1 + 1, p2 - p1 - 1) == "start";
            int time = std::stoi(s.substr(p2 + 1));

            if(!stk.empty() && id == stk.top() && !start)
            {
                res[id] += time - currentTime + 1;
                stk.pop();
            }
            else
            {
                if(!stk.empty()) res[stk.top()] += time - currentTime;
                stk.push(id);
            }

            currentTime = start ? time : time + 1;
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<string> a{
        "0:start:0",
        "1:start:2",
        "1:end:5",
        "0:end:6"};
    const auto& r = s.exclusiveTime(2, a);
    for(int i : r)
        std::cout<<i<<" ";
    std::cout<<std::endl;
}
