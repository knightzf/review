#include "header.h"

class Solution {
public:
    string smallestSubsequence(string text) {
        unordered_map<char, int> m;
        map<char, set<int>> indexmap;
        int cnt = 0, n = text.size();
        for(int i = 0; i < n; ++i) {
            char c = text[i];
            if(!m.count(c)) ++cnt;
            ++m[c];
            indexmap[c].insert(i);
        }

        int startIdx = 0, lastIdx = -1;
        for(; startIdx < n; ++startIdx) {
            if(m[text[startIdx]] == 1) {                
                break;
            }
            --m[text[startIdx]];
        }
        string res;
        while(!indexmap.empty()) {
            for(auto& p : indexmap) {
                auto iter = p.second.upper_bound(lastIdx);
                if(iter == p.second.end() || *iter > startIdx) continue;
                lastIdx = *iter;
                res += p.first;
                m.erase(p.first);
                indexmap.erase(p.first);
                --cnt;
                for(; startIdx < n; ++startIdx) {            
                    if(m[text[startIdx]] == 1) {                
                        break;
                    }
                    --m[text[startIdx]];
                }
                break;
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    cout<<s.smallestSubsequence("cdadabcc")<<endl;
}
