#include "header.h"

class Solution {
public:
    TreeNode* str2tree(string s) {
        if(s.empty()) return nullptr;
        stack<TreeNode*> stk;
        TreeNode* node = nullptr;
        int sign = 1;
        for(char c : s) {
            if(c == '-') sign = -1;
            else if(isdigit(c)) {
                if(!node) node = new TreeNode((c - '0') * sign);
                else node->val = node->val * 10 + (c - '0') * (node->val > 0 ? 1 : -1);
                sign = 1;
            } else if(c == '(') {
                if(node) stk.push(node);
                node = nullptr;
            } else {
                if(node) {
                    if(!stk.empty()) {
                        if(!stk.top()->left) stk.top()->left = node;
                        else stk.top()->right = node;
                    }
                    node = nullptr;
                } else if(stk.size() > 1) {
                    auto* t = stk.top();
                    stk.pop();
                    if(!stk.top()->left) stk.top()->left = t;
                    else stk.top()->right = t;
                }
            }
        }
        return node ? node : stk.top();;
    }
};

int main()
{
    //Solution s;
}