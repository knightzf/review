#include "header.h"

struct TrieNode
{
    bool isword = false;
    vector<TrieNode*> v = vector<TrieNode*>(26, nullptr);
};

class Trie {
private:
    TrieNode* m_ptr = new TrieNode();
public:
    /** Initialize your data structure here. */
    Trie() {
        
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* p = m_ptr;
        for(int i = 0, n = word.size(); i < n; ++i) {
            int idx = word[i] - 'a';
            if(!p->v[idx]) p->v[idx] = new TrieNode();
            p = p->v[idx];
        }
        p->isword = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* p = m_ptr;
        for(int i = 0, n = word.size(); i < n; ++i) {
            int idx = word[i] - 'a';
            if(!p->v[idx]) return false;
            p = p->v[idx];
        }
        return p->isword;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* p = m_ptr;
        for(int i = 0, n = prefix.size(); i < n; ++i) {
            int idx = prefix[i] - 'a';
            if(!p->v[idx]) return false;
            p = p->v[idx];
        }
        return true;
    }
};

int main()
{
    //Solution s;
}