#include "header.h"

class Master {
  public:
    int guess(string word);
};

class Solution {
public:
    void findSecretWord(vector<string>& wordlist, Master& master) {
        unordered_map<int, unordered_map<int, vector<int>>> m;
        int n = wordlist.size();
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(j != i) {
                    int d = diff(wordlist[i], wordlist[j]);
                    m[i][d].push_back(j);
                }
            }
        }
        vector<int> v; for(int i = 0; i < n; ++i) v.push_back(i);
        for(int i = 0; i < 10; ++i) {
            int idx = v[rand() % v.size()];
            int r = master.guess(wordlist[idx]);
            if(r == 6) return;
            unordered_set<int> mm(v.begin(), v.end());
            vector<int> t;
            for(int x : m[idx][r]) {
                if(mm.count(x)) t.push_back(x);
            }
            v = t;
        }
    }

    int diff(const string& a, const string& b) {
        int res = 0;
        for(int i = 0; i < 6; ++i)
            if(a[i] == b[i]) ++res;
        return res;
    }
};

int main()
{
    Solution s;
}