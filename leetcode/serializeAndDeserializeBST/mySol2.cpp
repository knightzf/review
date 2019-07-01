#include "header.h"

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "()";
        return "(" + to_string(root->val) + serialize(root->left) + serialize(root->right) + ")";
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        function<TreeNode*(int, int)> f = [&](int start, int end) {
            if(start + 2 == end) return static_cast<TreeNode*>(nullptr);
            int i = start + 1;
            for(; i < end; ++i) if(data[i] == '(') break;            
            TreeNode* node = new TreeNode(stoi(data.substr(start + 1, i - start - 1)));
            int cnt = 1;
            for(int j = i + 1; j < end; ++j) {
                if(data[j] == '(') ++cnt;
                if(data[j] == ')') --cnt;
                if(cnt == 0) {
                    node->left = f(i, j + 1);
                    node->right = f(j + 1, end - 1);
                    break;
                }
            }
            return node;
        };
        return f(0, data.size());
    }
};

int main()
{
    //Solution s;
}