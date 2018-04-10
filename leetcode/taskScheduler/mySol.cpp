#include "header.h"

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if(tasks.empty()) return 0;
        vector<int> v(26, 0);
        for(char c : tasks)
        {
            ++v[c - 'A'];
        }
        multimap<int, int, std::greater<int>> m;
        for(int i = 0; i < 26; ++i)
        {
            if(v[i]) m.insert(make_pair(v[i], i));
        }
        vector<int> lastIdxV(26, -1);
        int i = 0;
        while(!m.empty())
        {
            for(auto iter = m.begin(); iter != m.end(); ++iter)
            {
                if(lastIdxV[iter->second] == -1 || lastIdxV[iter->second] + n < i)
                {
                    if(iter->first - 1 > 0) m.insert(make_pair(iter->first - 1, iter->second));
                    lastIdxV[iter->second] = i;
                    m.erase(iter);
                    break;
                }
            }
            ++i;
        }

        return i;
    }
};

int main()
{
    Solution s;
    vector<char> a{'A','A','A','B','B','B'};
    std::cout<<s.leastInterval(a, 2)<<std::endl;
}
