#include "header.h"

 class Master {
   public:
     int guess(string word);
 };

class Solution {
public:
    void findSecretWord(vector<string>& wordlist, Master& master) {
        unordered_set<string> s(wordlist.begin(), wordlist.end());
        for(int i = 0; i < 10; ++i)
        {
            int r = master.guess(*s.begin());
            if(r == 6) return;
            strip(*s.begin(), s, r);
        }
    }

private:
    void strip(const string& str, unordered_set<string>& s, int cnt)
    {
        auto iter = s.begin();
        ++iter;
        for(; iter != s.end();)
        {
            if(findCommon(str, *iter) != cnt)
                iter = s.erase(iter);
            else
                ++iter;
        }
        s.erase(str);
    }

    int findCommon(const string& target, const string& a)
    {
        int res = 0;
        for(int i = 0; i < 6; ++i)
        {
            if(target[i] == a[i]) ++res;
        }
        return res;
    }
};

int main()
{
    Solution s;
}
