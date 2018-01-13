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

struct Data
{
    Data()
    {
        memset(children, 0, sizeof(children));
    }

    Data* children[26];
    bool isWord = false;
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        data = new Data();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Data* p = data;
        for(int i = 0; i < word.size(); ++i)
        {
            int idx = word[i] - 'a';
            if(p->children[idx] == nullptr)
            {
                p->children[idx] = new Data();
            }

            p = p->children[idx];
        }

        p->isWord = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Data* p = data;
        for(int i = 0; i < word.size(); ++i)
        {
            int idx = word[i] - 'a';
            if(p->children[idx] == nullptr)
            {
                return false;
            }

            p = p->children[idx];
        }

        return p->isWord;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Data* p = data;
        for(int i = 0; i < prefix.size(); ++i)
        {
            int idx = prefix[i] - 'a';
            if(p->children[idx] == nullptr)
            {
                return false;
            }

            p = p->children[idx];
        }

        return true;
    }

private:
    Data* data;
};

int main() {
    //Solution s;

    Trie a;
    a.insert("hello");
    std::cout<<a.search("hell")<<std::endl;
    std::cout<<a.search("helloa")<<std::endl;
    std::cout<<a.search("hello")<<std::endl;
    std::cout<<a.startsWith("hell")<<std::endl;
    std::cout<<a.startsWith("helloa")<<std::endl;
    std::cout<<a.startsWith("hello")<<std::endl;
}
