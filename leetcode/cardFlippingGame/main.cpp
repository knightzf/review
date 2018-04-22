#include "header.h"

class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        unordered_set<int> impossibles;
        set<int> candidates;
        for(int i = 0; i < fronts.size(); ++i)
        {
            if(fronts[i] == backs[i]) impossibles.insert(fronts[i]);
        }

        for(int i = 0; i < fronts.size(); ++i)
        {
            if(fronts[i] != backs[i])
            {
                if(impossibles.find(fronts[i]) == impossibles.end())
                {
                    candidates.insert(fronts[i]);
                }
                if(impossibles.find(backs[i]) == impossibles.end())
                {
                    candidates.insert(backs[i]);
                }
            }
        }

        return *candidates.begin();
    }
};

int main()
{
    Solution s;
}
