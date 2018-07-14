#include "header.h"

class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        unordered_map<int, vector<int>> m;
        for(int i = 0, n = pid.size(); i < n; ++i)
        {
            m[ppid[i]].emplace_back(pid[i]);
        }

        vector<int> res;

        deque<int> q;
        q.push_back(kill);
        int qsize = q.size();
        while(qsize)
        {
            for(int i = 0; i < qsize; ++i)
            {
                int id = q.front();
                res.emplace_back(id);
                if(m.count(id))
                {
                    for(int child : m[id])
                        q.push_back(child);
                }
                q.pop_front();
            }
            qsize = q.size();
        }
        return res;
    }
};

int main()
{
    Solution s;
}
