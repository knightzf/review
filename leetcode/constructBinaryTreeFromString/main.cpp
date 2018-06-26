#include "header.h"

class Solution {
public:
    TreeNode* str2tree(string s) {
        return impl(s, 0, s.size());
    }

    TreeNode* impl(const string& s, int startIdx, int endIdx)
    {
        if(startIdx == endIdx) return nullptr;
        int i = startIdx;
        while(i < endIdx && (isdigit(s[i]) || s[i] == '-')) ++i;
        TreeNode* node = new TreeNode(stoi(s.substr(startIdx, i - startIdx)));
        if(i == endIdx) return node;
        int j = i + 1;
        int cnt = 1;
        while(j < endIdx && cnt != 0)
        {
            if(s[j] == '(') ++cnt;
            else if(s[j] == ')') --cnt;
            ++j;
        }
        node->left = impl(s, i + 1, j - 1);
        if(j == endIdx) return node;
        node->right = impl(s, j + 1, endIdx - 1);
        return node;
    }
};

int main()
{
    Solution s;
}
