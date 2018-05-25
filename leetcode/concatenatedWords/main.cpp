#include "header.h"

struct Node{
    unordered_map<char, Node*> data;
    bool isWord = false;
};

class Solution {
private:
    unordered_set<string> m;
    Node* root;
    int minLen;
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        m.clear();
        root = new Node();
        minLen = INT_MAX;
        for(const auto& w : words)
        {
            add(root, w);
            m.insert(w);
            minLen = min(minLen, (int)w.size());
        }

        vector<string> res;
        for(const auto& w: words)
        {
            if(w.size() > minLen && dfs(root, w, 0)) res.push_back(w);
        }

        return res;
    }

    bool dfs(Node* node, const string& w, int startIdx)
    {
        if(startIdx != 0 && m.count(w.substr(startIdx))) return true;

        for(int i = startIdx; i < w.size(); ++i)
        {
            if(node->data.count(w[i]) == 0) return false;
            node = node->data[w[i]];
            if(node->isWord)
            {
                if(startIdx != 0 && i == w.size() - 1) return true;
                if(i != w.size() - 1 && dfs(root, w, i + 1)) return true;
            }
        }

        return false;
    }

    void add(Node* node, const string& w)
    {
        for(char c : w)
        {
            if(node->data[c] == nullptr) node->data[c] = new Node();
            node = node->data[c];
        }

        node->isWord = true;
    }
};

int main()
{
    Solution s;
}
