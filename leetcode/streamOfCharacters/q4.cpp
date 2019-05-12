#include "header.h"

struct Trie
{
    bool isword = false;
    vector<Trie*> v = vector<Trie*>(26, nullptr);
};

class StreamChecker {
    Trie * trie;
    string s;
public:
    StreamChecker(vector<string>& words) {
        trie = new Trie();      
        for(const auto& w : words)
        {
            Trie* node = trie;
            for(int i = w.size() - 1; i >= 0; --i)
            {
                if(node->v[w[i] - 'a'] == nullptr) node->v[w[i] - 'a'] = new Trie();
                node = node->v[w[i] - 'a'];
                if(i == 0) node->isword = true;
            }
        }
    }
    
    bool query(char letter) {
        s += letter;
        Trie* node = trie;
        for(int i = s.size() - 1; i >= 0; --i)
        {
            if(node->v[s[i] - 'a'] == nullptr) return false;
            node = node->v[s[i] - 'a'];
            if(node->isword) return true;
        }
        return false;
    }
};

int main()
{
    //Solution s;
    vector<string> a{"cd","f","kl"};
    StreamChecker* streamChecker = new StreamChecker(a);
}
