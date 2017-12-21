#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <sstream>
#include <cmath>
#include <queue>
#include <map>
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

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root)
    {
        if(!root)
        {
            return true;
        }

        bool isValid = true;
        if(root->left)
        {
            std::cout<<root->val<<" "<<root->left->val<<" "<<maxElement(root->left)<<std::endl;
            isValid = isValid && root->val > maxElement(root->left) && isValidBST(root->left);
            if(!isValid)
            {
                return false;
            }
        }

        if(root->right)
        {
            std::cout<<root->val<<" "<<root->right->val<<" "<<minElement(root->right)<<std::endl;
            isValid = isValid && root->val < minElement(root->right) && isValidBST(root->right);
            if(!isValid)
            {
                return false;
            }
        }

        return isValid;
    }

    int maxElement(TreeNode* node)
    {
        static std::unordered_map<TreeNode*, int> maxMap;

        auto iter = maxMap.find(node);
        if(iter != maxMap.end())
        {
            return iter->second;
        }

        int leftMax = node->left ? maxElement(node->left) : INT_MIN;
        int rightMax = node->right ? maxElement(node->right) : INT_MIN;
        int max = std::max(node->val, std::max(leftMax, rightMax));
        maxMap[node] = max;
        return max;
    }

    int minElement(TreeNode* node)
    {
        static std::unordered_map<TreeNode*, int> minMap;

        auto iter = minMap.find(node);
        if(iter != minMap.end())
        {
            return iter->second;
        }

        int leftMin = node->left ? minElement(node->left) : INT_MAX;
        int rightMin = node->right ? minElement(node->right) : INT_MAX;
        int min = std::min(node->val, std::min(leftMin, rightMin));
        minMap[node] = min;
        return min;
    }
};

int main()
{
    Solution s;
    /*TreeNode* a = new TreeNode(10);
    TreeNode* b = new TreeNode(5);
    TreeNode* c = new TreeNode(15);
    TreeNode* d = new TreeNode(6);
    TreeNode* e = new TreeNode(20);
    a->left = b;
    a->right = c;
    c->left = d;
    c->right = e;*/

    TreeNode* a = new TreeNode(0);
    TreeNode* b = new TreeNode(-1);
    a->left = b;
    std::cout<<s.isValidBST(a)<<std::endl;;

}
