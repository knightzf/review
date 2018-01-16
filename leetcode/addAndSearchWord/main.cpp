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
#include <iterator>

using namespace std;

struct Trie
{
    Trie()
    {
        memset(data, 0, sizeof(data));
    }

    Trie* data[26];
    bool isWord = false;
};

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        trie = new Trie();
    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        int n = word.size();
        Trie* p = trie;
        for(int i = 0; i < n; ++i)
        {
            int idx = word[i] - 'a';
            if(p->data[idx] == nullptr)
            {
                p->data[idx] = new Trie();
            }

            p = p->data[idx];

            if(i == n - 1) p->isWord = true;
        }
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        int n = word.size();
        return searchImpl(word, n, 0, trie);
    }

    bool searchImpl(const std::string& word, int n, int idx, Trie* p)
    {
        if(idx == n - 1)
        {
            if(word[idx] != '.')
            {
                return p->data[word[idx] - 'a'] && p->data[word[idx] - 'a']->isWord;
            }
            else
            {
                for(int i = 0; i < 26; ++i)
                {
                    if(p->data[i] && p->data[i]->isWord)
                    {
                        return true;
                    }
                }

                return false;
            }
        }
        else
        {
            if(word[idx] != '.')
            {
                int letterIdx = word[idx] - 'a';
                if(p->data[letterIdx])
                {
                    return searchImpl(word, n, idx + 1, p->data[letterIdx]);
                }
                else
                {
                    return false;
                }
            }
            else
            {
                for(int i = 0; i < 26; ++i)
                {
                    if(p->data[i] && searchImpl(word, n, idx + 1, p->data[i]))
                    {
                        return true;
                    }
                }

                return false;
            }
        }

    }

private:
    Trie* trie;
};


int main() {
    //Solution s;
    WordDictionary d;
    d.addWord("bad");
    d.addWord("dad");
    d.addWord("mad");
    std::cout<<d.search("pad")<<std::endl;
    std::cout<<d.search("bad")<<std::endl;
    std::cout<<d.search(".ad")<<std::endl;
    std::cout<<d.search("b..")<<std::endl;
}
