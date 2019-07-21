#include "header.h"

struct Trie
{
    Trie* children[26] = {0};
};

class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        int n = s.size();
        Trie* root = new Trie();
        for(int i = 0; i < n; ++i) {
            insert(root, s, i);
        }
        sort(d.begin(), d.end(), [](const string&a, const string& b){
            if(a.size() > b.size()) return true;
            if(a.size() < b.size()) return false;
            return a < b;
        });

        for(const string& w : d) {
            if(search(root, w, 0)) return w;
        }
        return "";
    }

    void insert(Trie* node, const string& s, int idx) {
        char c = s[idx];
        if(node->children[c - 'a']) return;
        node->children[c - 'a'] = new Trie();
        for(int i = idx + 1; i < s.size(); ++i)
            insert(node->children[c - 'a'], s, i);
    }

    bool search(Trie* root, const string& w, int idx) {
        if(idx == w.size()) return true;
        if(!root->children[w[idx] - 'a']) return false;
        return search(root->children[w[idx] - 'a'], w, idx + 1);
    }
};

int main()
{
    Solution s;
    vector<string> a{"apple","ewaf","awefawfwaf","awef","awefe","ewafeffewafewf"};
    cout<<s.findLongestWord("aewfafwafjlwajflwajflwafj", a)<<endl;
}