#include "header.h"

class Solution {
public:
    TreeNode* recoverFromPreorder(string S) {
        stack<pair<TreeNode*, int>> s;
        TreeNode* res;
        int level = 0;
        for(int i = 0, n = S.size(); i < n; )
        {
            if(S[i] == '-')
            {
                ++level;
                ++i;
            }
            else
            {
                int j = i;
                while(isdigit(S[j])) ++j;
                int num = stoi(S.substr(i, j - i));
                TreeNode* node = new TreeNode(num);
                if(level == 0) {
                    res = node;
                    s.push(make_pair(node, level));        
                }
                else
                {
                    if(level > s.top().second)
                    {
                        s.top().first->left = node;
                    }
                    else
                    {
                        while(s.top().second >= level) s.pop();
                        s.top().first->right = node;
                    }                    
                    s.push(make_pair(node, level));
                }        
                i = j;
                level = 0;                
            }            
        }
        return res;
    }
};

int main()
{
    Solution s;
}
