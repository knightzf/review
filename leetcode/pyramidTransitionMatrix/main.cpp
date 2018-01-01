#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <sstream>
#include <cmath>
#include <queue>
#include <map>
#include <string>
#include <cstdlib>
#include <cctype>
#include <stdexcept>
#include <climits>
#include <utility>
#include <bitset>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <memory>

using namespace std;

class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed)
    {
        std::unordered_map<std::string, std::string> allowMap;
        for(const auto& w : allowed)
        {
            allowMap[w.substr(0, 2)] += w.back();
        }

        return impl(bottom, allowMap);
    }

    bool impl(const std::string& bottom, const std::unordered_map<std::string, std::string>& allowMap)
    {
        //std::cout<<"bottom "<<bottom<<std::endl;
        if(bottom.size() == 1) return true;

        int n = bottom.size();
        std::vector<std::string> nextRowVec;
        for(int i = 0; i < n - 1; ++i)
        {
            const auto& pre = bottom.substr(i, 2);
            if(allowMap.find(pre) != allowMap.end())
            {
                nextRowVec.push_back(allowMap.at(pre));
            }
            else
            {
                return false;
            }
        }

        if(dfs(nextRowVec, 0, "", allowMap))
        {
            return true;
        }

        return false;
    }

    bool dfs(const std::vector<std::string>& rows,
             int idx,
             std::string nextRow,
             const std::unordered_map<std::string, std::string>& allowMap)
    {
        if(idx >= rows.size())
        {
            return impl(nextRow, allowMap);
        }

        for(int i = 0; i < rows[idx].size(); ++i)
        {
            if(dfs(rows, idx + 1, nextRow + rows[idx][i], allowMap))
            {
                return true;
            }
        }

        return false;
    }
};

int main()
{
    Solution s;
    std::vector<std::string> a{"BGF","AGE","AGC","AGA","CCE","CCD","EGA","CCF","CCA","DCD","DCA","FGE","FGA","FGB","BFB","BFG","BFD","ECC","DBA","FAF","DBF","FDA","FDC","FDE","BEA","BEE","AEA","AEC","AED","EEE","DEA","DEC","EEA","CCG","EEC","DEG","CEE","CED","CEC","CEA","GEC","GEA","GEF","GEE","BDE","BDD","GCE","AFC","DDC","DDB","EFB","EFE","DDE","DDD","CBC","CBE","ACB","ACE","BCD","BCE","BCA","BCB","BCC","DGB","ECF","DGF","ECB","ECA","CGD","CGF","FCE","FEF","BBF","BBD","ADG","ADD","ADA","DFD","DFC","CDE","CDF","CDG","EDF","EDG","EDD","FBA","FBG","FBF","GDF","AAE","AAD","AAC","BAG","BAB","BAC","BAA","CAF","CAD","DAD","DAB","DED","EAD","EAG","EAF","FAC","GAD","GAC","GAB","ABA","ABF","EBD","EBF","EBA","EBB","EBC","CFF","CFE","CFC","GFC","GFA","GFG","GFD"};
    std::cout<<s.pyramidTransition("DACCDGDDCFCGCFAGFADF", a)<<std::endl;
}
