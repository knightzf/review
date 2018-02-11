#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <sstream>
#include <cmath>
#include <queue>
#include <map>
#include <list>
#include <string>
#include <cstdlib>
#include <cctype>
#include <stdexcept>
#include <climits>
#include <utility>
#include <bitset>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <memory>
#include <iterator>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr) return "()";

        string res = "(" + std::to_string(root->val);

        //if(root->left || root->right)
        {
            res += serialize(root->left);
            res += serialize(root->right);
        }

        res += ")";

        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        return parse(data, 0, data.size());
    }

private:
    TreeNode* parse(const std::string& s, int startIdx, int endIdx)
    {
        if(endIdx - startIdx <= 2) return nullptr;

        int i = startIdx + 1;
        while(s[i] != '(') ++i;
        TreeNode* root = new TreeNode(std::stoi(s.substr(startIdx + 1, i - startIdx - 1)));

        int j = i;
        int count = 1;
        while(count > 0)
        {
            ++j;
            if(s[j] == '(') ++count;
            if(s[j] == ')') --count;
        }

        root->left = parse(s, i, j + 1);

        i = j + 1;
        if(s[i] == '(')
        {
            j = i;
            count = 1;
            while(count > 0)
            {
                ++j;
                if(s[j] == '(') ++count;
                if(s[j] == ')') --count;
            }

            root->right = parse(s, i, j + 1);
        }

        return root;
    }
};

int main() {
    //Solution s;

    TreeNode* a = new TreeNode(1);
    TreeNode* b = new TreeNode(2);
    TreeNode* c = new TreeNode(3);
    a->left = b; a->right = c;
    TreeNode* d = new TreeNode(4);
    TreeNode* e = new TreeNode(5);
    c->left = d; c->right = e;

    Codec code;
    const auto& s = code.serialize(a);
    std::cout<<code.serialize(a)<<std::endl;
    code.deserialize(s);
}
