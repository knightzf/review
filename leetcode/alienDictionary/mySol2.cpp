#include "header.h"

class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_set<char> s;
        for(const auto& w : words)
            for(char c : w) s.insert(c);
        
        unordered_map<char, unordered_set<int>> indegree;
        unordered_map<char, unordered_set<int>> outdegree;
        for(int i = 1, n = words.size(); i < n; ++i) {
            for(int j = 0, m = min(words[i - 1].size(), words[i].size()); j < m; ++j) {
                if(words[i - 1][j] != words[i][j]) {
                    indegree[words[i - 1][j]].insert(words[i][j]);
                    outdegree[words[i][j]].insert(words[i - 1][j]);
                    break;
                }
            }
        }

        unordered_set<char> free;
        for(char c : s) if(!outdegree.count(c)) free.insert(c);

        string res;
        while(!free.empty()) {
            char c = *free.begin();
            free.erase(c);
            res += c;
            for(char t : indegree[c]) {
                outdegree[t].erase(c);
                if(outdegree[t].empty()) {
                    outdegree.erase(t);
                    free.insert(t);
                }
            }
        }
        return res.size() == s.size() ? res : "";
    }
};

int main()
{
    //Solution s;
}