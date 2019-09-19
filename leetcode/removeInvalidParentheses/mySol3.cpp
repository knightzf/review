#include "header.h"

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
       vector<string> res;
       function<void(const string&, int, char, char)> dfs = [&](
         const string& str, int startIdx, char a, char b) {
            for(int i = 0, n = str.size(), cnt = 0; i < n; ++i) {
               if(str[i] == a) ++cnt;
               else if(str[i] == b) --cnt;
               if(cnt < 0) {
                  for(int k = startIdx; k <= i; ++k) {
                     if(str[k] == b && (k == startIdx || str[k - 1] != b)) {
                        dfs(str.substr(0, k) + str.substr(k + 1), k, a, b);
                     }
                  }
                  return;
               }
            }
            string t = str;
            reverse(t.begin(), t.end());
            if(a == '(') {
               dfs(t, 0, b, a);
            } else {
               res.push_back(t);
            }
       };
       dfs(s, 0, '(', ')');
       return res;
    }
};

int main()
{
   return 0;
}