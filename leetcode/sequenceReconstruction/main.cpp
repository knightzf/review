#include "header.h"

class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        int n = org.size();
        unordered_set<int> s;
        for(int i = 1; i <= n; ++i)
            s.insert(i);

        vector<int> degrees(n + 1, 0);
        unordered_map<int, unordered_set<int>> dependMap;

        for(const auto& seq : seqs)
        {
            for(int i = 0; i < seq.size(); ++i)
            {
                if(seq[i] < 1 || seq[i] > n) return false;
                if(s.find(seq[i]) != s.end()) s.erase(seq[i]);
                if(i != 0)
                {
                    if(dependMap.find(seq[i]) == dependMap.end() ||
                       dependMap[seq[i]].find(seq[i - 1]) == dependMap[seq[i]].end())
                    {
                        dependMap[seq[i]].insert(seq[i - 1]);
                        ++degrees[seq[i - 1]];
                    }
                }
            }
        }

        if(!s.empty()) return false;

        unordered_set<int> zeroDegree;
        for(int i = 1; i <= n; ++i)
        {
            if(degrees[i] == 0)
                zeroDegree.insert(i);
        }

        int idx = n;
        while(!zeroDegree.empty())
        {
            if(zeroDegree.size() > 1) return false;
            int t = *zeroDegree.begin();
            if(t != org[--idx]) return false;
            zeroDegree.erase(t);
            for(int i : dependMap[t])
            {
                --degrees[i];
                if(degrees[i] == 0)
                    zeroDegree.insert(i);
            }
        }
        return idx == 0;
    }
};

int main()
{
    Solution s;
    vector<int> org{1, 2, 3};
    vector<vector<int>> b{
        {1, 2},
        {1, 3},
        {2, 3}
    };
    std::cout<<s.sequenceReconstruction(org, b)<<std::endl;
}
