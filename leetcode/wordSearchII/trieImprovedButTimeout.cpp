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
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size();
        if(m == 0) return vector<string>();
        n = board[0].size();

        Trie* t = new Trie();

        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                vector<vector<bool>> visited(m, vector<bool>(n, false));
                createTrie(t, board, i, j, visited);
            }
        }

        std::cout<<"after create"<<std::endl;
        unordered_set<string> res;
        for(const auto& word : words)
        {
            if(!word.empty())
            {
                Trie* p = t;
                bool found = true;
                for(int i = 0; i < word.size(); ++i)
                {
                    if(p->data[word[i] - 'a'])
                    {
                        p = p->data[word[i] - 'a'];
                    }
                    else
                    {
                        found = false;
                        break;
                    }
                }

                if(found)
                {
                    res.insert(word);
                    break;
                }
            }
        }

        return vector<string>(res.begin(), res.end());
    }

private:
    void createTrie(Trie* t, vector<vector<char>>& board, int i, int j,
                    vector<vector<bool>>& visited)
    {
        visited[i][j] = true;

        char c = board[i][j];
        if(t->data[c - 'a'] == nullptr)
        {
            t->data[c - 'a'] = new Trie();
        }


        if(i > 0 && visited[i - 1][j] == false)
        {
            createTrie(t->data[c - 'a'], board, i - 1, j, visited);
        }

        if(j > 0 && visited[i][j - 1] == false)
        {
            createTrie(t->data[c - 'a'], board, i, j - 1, visited);
        }

        if(i < m - 1 && visited[i + 1][j] == false)
        {
            createTrie(t->data[c - 'a'], board, i + 1, j, visited);
        }

        if(j < n - 1 && visited[i][j + 1] == false)
        {
            createTrie(t->data[c - 'a'], board, i, j + 1, visited);
        }

        visited[i][j] = false;
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
    vector<string> b{"oath","pea","eat","rain"};
    */
    vector<vector<char>> a{
        {'b','b','a','a','b','a'},
        {'b','b','a','b','a','a'},
        {'b','b','b','b','b','b'},
        {'a','a','a','b','a','a'},
        {'a','b','a','a','b','b'}};
    vector<string> b{"abbbababaa"};
    std::cout<<s.findWords(a, b).size()<<std::endl;
}
