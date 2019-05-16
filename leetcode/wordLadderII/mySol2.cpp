#include "header.h"

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<int, vector<int>> m;
        int n = wordList.size();
        for(int i = 0; i < n; ++i) {
            if(diff(beginWord, wordList[i])) m[-1].push_back(i);
        }
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(i != j && diff(wordList[i], wordList[j])) m[i].push_back(j);
            }
        }
        vector<vector<string>> res;
        queue<vector<int>> q;
        for(int i : m[-1]) {
            q.push(vector<int>{i});
        }
        vector<bool> visited(n, false);
        int qsize = q.size();
        bool found = false;        
        while(!q.empty() && !found) {
            for(int i = 0; i < qsize; ++i) {
                const auto& v = q.front();
                if(v.back() != -1) visited[v.back()] = true;
                if(wordList[v.back()] == endWord) {
                    found = true;
                    vector<string> t{beginWord};
                    for(int j : v) {
                        t.push_back(wordList[j]);
                    }
                    res.emplace_back(t);
                }
                else {
                    for(int j : m[v.back()]) {
                        if(!visited[j]) {                            
                            q.push(v);
                            q.back().push_back(j);
                        }
                    }
                }
                q.pop();
            }
            qsize = q.size();
        }
        return res;
    }

    bool diff(const string& a, const string& b) 
    {
        for(int i = 0, n = a.size(), cnt = 0; i < n; ++i) {
            if(a[i] != b[i]) ++cnt;
            if(cnt > 1) return false;
        }
        return true;
    }
};

int main()
{
    Solution s;
    
}