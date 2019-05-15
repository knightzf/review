#include "header.h"

struct Suffix {
    int index; 
    pair<int, int> rank;

    bool operator<(const Suffix& rhs) const {
        return rank < rhs.rank;
    }
};

vector<int> buildSuffixArray(const std::string& s)
{
    int n = s.size();
    vector<int> suffixRank(n);
    for(int i = 0; i < n; ++i) suffixRank[i] = s[i] - 'a';
    
    vector<Suffix> suffixVec(n);
    for(int cnt = 1, step = 1; cnt < n; cnt *= 2, ++step) {
        for(int i = 0; i < n; ++i) {
            suffixVec[i].rank.first = suffixRank[i];
            suffixVec[i].rank.second = i + cnt < n ? suffixRank[i + cnt] : -1;
            suffixVec[i].index = i;
        }

        sort(suffixVec.begin(), suffixVec.end());

        suffixRank[suffixVec[0].index] = 0;
        for(int i = 1, currRank = 0; i < n; ++i)
        {
            if(suffixVec[i].rank.first != suffixVec[i - 1].rank.first ||
               suffixVec[i].rank.second != suffixVec[i - 1].rank.second)
            {
                ++currRank;
            }
            suffixRank[suffixVec[i].index] = currRank;
        }
    }

    vector<int> suffixArray(n);
    for(int i = 0; i < n; ++i) suffixArray[i] = suffixVec[i].index;
    return suffixArray;
}

vector<int> longestCommonPrefix(const vector<int>& suffixArray, const std::string& s)
{
    int n = s.size();
    vector<int> invSuffix(n);
    for(int i = 0; i < n; ++i) invSuffix[suffixArray[i]] = i;
    vector<int> lcp(n);
    for(int i = 0, k = 0; i < n; ++i) {
        if(invSuffix[i] == n - 1) {
            k = 0;
            continue;
        }
        int j = suffixArray[invSuffix[i] + 1]; 
        while(i + k < n && j + k < n && s[i + k] == s[j + k]) ++k;
        lcp[i] = k;
        if(k > 0) --k;
    }
    return lcp;
}

class Solution {
public:
    string longestDupSubstring(string S) {
        const auto& suffixArray = buildSuffixArray(S);
        const auto& lcp = longestCommonPrefix(suffixArray, S);
        int startIdx = 0, maxLen = 0;
        for(int i = 0, n = S.size(); i < n; ++i)
        {
            if(lcp[i] > maxLen) {
                startIdx = i;
                maxLen = lcp[i];
            }
        }
        return S.substr(startIdx, maxLen);
    }
};

int main()
{
    Solution s;
    string a = "banana";
    cout<<s.longestDupSubstring(a)<<endl;
}
