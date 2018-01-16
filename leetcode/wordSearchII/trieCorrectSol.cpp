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
    string word;
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size();
        if(m == 0) return vector<string>();
        n = board[0].size();

        Trie* t = new Trie();

        for(const auto& word : words)
        {
            Trie* p = t;
            for(int i = 0; i < word.size(); ++i)
            {
                if(p->data[word[i] - 'a'] == nullptr)
                {
                    p->data[word[i] - 'a'] = new Trie();
                }

                p = p->data[word[i] - 'a'];

                if(i == word.size() - 1)
                {
                    p->isWord = true;
                    p->word = word;
                }
            }
        }

        vector<string> res;

        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                findInTrie(t, board, i, j, res);
            }
        }

        return res;
    }

private:
    void findInTrie(Trie* t, vector<vector<char>>& board, int i, int j, vector<string>& res)
    {
        char temp = board[i][j];
        int idx = temp - 'a';

        if(t->data[idx] == nullptr) return;

        board[i][j] = '#';

        if(t->data[idx]->isWord)
        {
            //std::cout<<t->data[idx]->word<<std::endl;
            res.push_back(t->data[idx]->word);
            t->data[idx]->isWord = false;
        }

        if(i > 0 && board[i - 1][j] != '#')
        {
            findInTrie(t->data[idx], board, i - 1, j, res);
        }

        if(j > 0 && board[i][j - 1] != '#')
        {
            findInTrie(t->data[idx], board, i, j - 1, res);
        }

        if(i < m - 1 && board[i + 1][j] != '#')
        {
            findInTrie(t->data[idx], board, i + 1, j, res);
        }

        if(j < n - 1 && board[i][j + 1] != '#')
        {
            findInTrie(t->data[idx], board, i, j + 1, res);
        }

        board[i][j] = temp;
    }

private:
    int m, n;
};

int main() {
    Solution s;
    /*vector<vector<char>> a{
      {'o','a','a','n'},
      {'e','t','a','e'},
      {'i','h','k','r'},
      {'i','f','l','v'}
    };
    vector<string> b{"oath","pea","eat","rain"};*/

    vector<vector<char>> a{
        {'b','b','a','a','b','a'},
        {'b','b','a','b','a','a'},
        {'b','b','b','b','b','b'},
        {'a','a','a','b','a','a'},
        {'a','b','a','a','b','b'}};
    vector<string> b{"abbbababaa"};
    std::cout<<s.findWords(a, b).size()<<std::endl;
}
