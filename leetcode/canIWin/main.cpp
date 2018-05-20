#include "header.h"

class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if(desiredTotal <= maxChoosableInteger) return true;
        if((1 + maxChoosableInteger) * maxChoosableInteger / 2 < desiredTotal) return false;
        unordered_map<int, bool> stateMap;
        return !dfs(maxChoosableInteger, desiredTotal, 0, stateMap);
    }

    bool dfs(int maxChoosableInteger, int desiredTotal, int state, unordered_map<int, bool>& stateMap)
    {
        if(stateMap.find(state) != stateMap.end()) return stateMap[state];

        int sum = 0;
        for(int i = 0; i < maxChoosableInteger; ++i)
        {
            if(state & (1 << i)) sum += i + 1;
        }

        if(sum >= desiredTotal)
        {
            stateMap[state] = true;
            return true;
        }

        bool res = true;
        for(int i = 0; i < maxChoosableInteger; ++i)
        {
            if(!(state & (1 << i)))
            {
                int newState = state | (1 << i);
                if(dfs(maxChoosableInteger, desiredTotal, newState, stateMap))
                {
                    res = false;
                    break;
                }
            }
        }
        stateMap[state] = res;
        return res;
    }
};

int main()
{
    Solution s;
    cout<<s.canIWin(10, 1)<<endl;
}
