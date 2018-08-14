#include "header.h"

class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size();
        int i = 0;
        while(true)
        {
            if(senate[i] != ' ')
            {
                int j = (i + 1) % n;
                bool found = false;
                while(j != i)
                {
                    if(senate[j] != ' ' && senate[j] != senate[i])
                    {
                        senate[j] = ' ';
                        found = true;
                        break;
                    }
                    j = (j + 1) % n;
                }

                if(!found) return senate[i] == 'R' ? "Radiant" : "Dire";
            }
            i = (i + 1) % n;
        }
    }
};

int main() {
    Solution s;
}
