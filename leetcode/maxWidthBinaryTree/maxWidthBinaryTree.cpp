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

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;

        int maxWidth = 1;
        std::deque<TreeNode*> parentVec;
        parentVec.push_back(root);

        size_t parentSz = 1;

        while(true)
        {
            bool hasItem = false;
            for(size_t i = 0; i < parentSz; ++i)
            {
                const auto& item = parentVec.front();
                if(item)
                {
                    if(!hasItem)
                    {
                        if(item->left)
                        {
                            parentVec.push_back(item->left);
                            hasItem = true;
                        }
                    }
                    else
                    {
                        parentVec.push_back(item->left);
                    }
                    if(!hasItem)
                    {
                        if(item->right)
                        {
                            parentVec.push_back(item->right);
                            hasItem = true;
                        }
                    }
                    else
                    {
                        parentVec.push_back(item->right);
                    }
                }
                else
                {
                    if(hasItem)
                    {
                        parentVec.push_back(0);
                        parentVec.push_back(0);
                    }
                }

                parentVec.pop_front();
            }

            parentSz = parentVec.size();

            bool empty = true;
            for(const auto& item : parentVec)
            {
                empty = empty && (item == nullptr);
                if(!empty)
                {
                    break;
                }
            }

            if(empty)
            {
                break;
            }

            size_t firstValidIdx = 0;
            while(firstValidIdx != parentVec.size())
            {
                if(parentVec[firstValidIdx])
                    break;

                ++firstValidIdx;
            }

            size_t lastValidIdx = parentVec.size() - 1;
            while(lastValidIdx != 0)
            {
                if(parentVec[lastValidIdx])
                    break;

                --lastValidIdx;
            }

            maxWidth = lastValidIdx - firstValidIdx + 1 > maxWidth ? lastValidIdx - firstValidIdx + 1 : maxWidth;
        }

        return maxWidth;
    }
};
int main()
{
    Solution sol;
    TreeNode* a = new TreeNode(1);
    TreeNode* b = new TreeNode(3);
    TreeNode* c = new TreeNode(2);
    a->left = b;
    a->right = c;

    TreeNode* d = new TreeNode(5);
    TreeNode* e = new TreeNode(3);
    TreeNode* f = new TreeNode(9);

    b->left = d;
    b->right = e;
    c->right = f;

    std::cout<<sol.widthOfBinaryTree(a)<<std::endl;

	return 0;
}
