#include "header.h"

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr) return "()";
        string res = "(";
        if(root) res += to_string(root->val);
        res += "," + serialize(root->left);
        res += "," + serialize(root->right);
        res += ")";
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        return impl(data, 0, data.size() - 1);
    }

    TreeNode* impl(const string& data, int startIdx, int endIdx) {
        if(startIdx == endIdx - 1)
            return nullptr;

        int i = startIdx + 1;
        while(i < endIdx && data[i] != ',') ++i;
        TreeNode* node = new TreeNode(stoi(data.substr(startIdx + 1, i - startIdx - 1)));

        while(i < endIdx && data[i] != '(') ++i;
        int cnt = 1;
        int j = i;
        for(i = i + 1; i < endIdx; ++i)
        {
            if(data[i] == '(') ++cnt;
            else if(data[i] == ')') --cnt;

            if(cnt == 0)
            {
                node->left = impl(data, j, i);
                node->right = impl(data, i + 2, endIdx - 1);
                break;
            }
        }
        return node;
    }
};

int main()
{
    //Solution s;
    TreeNode* a = new TreeNode(2);
    TreeNode* b = new TreeNode(1);
    TreeNode* c = new TreeNode(3);
    a->left = b;
    a->right = c;
    Codec codec;
    std::cout<<codec.serialize(a)<<std::endl;
    codec.deserialize(codec.serialize(a));
}
