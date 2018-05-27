#include "header.h"

class Solution {
public:
    vector<int> splitIntoFibonacci(string S) {
        int n = S.size();
        vector<int> res;
        if(n == 0) return res;

        int xMaxLen = S[0] == '0' ? 1 : min(10, n / 2);
        for(int i = 1; i <= xMaxLen; ++i)
        {
            if(stol(S.substr(0, i)) > INT_MAX) break;
            int x = stoi(S.substr(0, i));
            int yMaxLen = S[i] == '0' ? 1 : min(10, n - i);
            for(int j = 1; j <= yMaxLen; ++j)
            {
                if(stol(S.substr(i, j)) > INT_MAX) break;
                int y = stoi(S.substr(i, j));
                if(valid(S, x, y, i + j, res))
                {
                    return res;
                }
            }
        }
        return {};
    }

    bool valid(const string& s, int x, int y, int idx, vector<int>& res)
    {
        //cout<<"here"<<endl;
        if(idx >= s.size()) return false;
        if(s[idx] == '0' && (x != 0 || y != 0)) return false;
        res.clear();
        res.push_back(x); res.push_back(y);
        while(idx < s.size())
        {
            const string& t = to_string(x + y);
            //cout<<x<<" "<<y<<" "<<t<<endl;
            if(idx + t.size() > s.size()) return false;
            if(s.substr(idx, t.size()) != t) return false;
            res.push_back(x + y);
            x = y;
            y = res.back();
            idx += t.size();
            if(idx > s.size()) return false;
        }
        return res.size() >= 3;
    }
};

int main()
{
    Solution s;
    const auto& r = s.splitIntoFibonacci("11235813");
    for(int i : r)
        cout<<i<<" ";
    cout<<endl;
}
