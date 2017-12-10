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
    int findClosestLeaf(TreeNode* root, int k)
    {
        TreeNode* targetNode = nullptr;

        std::queue<TreeNode*> v;
        v.push(root);

        std::stack<TreeNode*> tempV;

        while(true)
        {
            TreeNode* node = v.front();
            v.pop();

            tempV.push(node);

            if(node->val == k)
            {
                targetNode = node;
                break;
            }
            else
            {
                if(node->left)
                {
                    v.push(node->left);
                }

                if(node->right)
                {
                    v.push(node->right);
                }
            }
        }

        if(!targetNode->left && !targetNode->right)
        {
            return targetNode->val;
        }
        else
        {
            TreeNode* firstChildLeaf = nullptr;
            int childDistance = findFirstChildLeaf(targetNode, firstChildLeaf);

            //std::cout<<firstChildLeaf->val<<" "<<childDistance<<std::endl;

            TreeNode* parentLeaf = nullptr;
            int parentDistance = INT_MAX;
            int parentLevel = 1;

            tempV.pop();
            while(!tempV.empty())
            {
                //std::cout<<"here"<<std::endl;
                TreeNode* p = tempV.top();
                tempV.pop();

                if(p->left == targetNode || p->right == targetNode)
                {
                    targetNode = p;
                    TreeNode* tNode = nullptr;
                    int distance = findFirstChildLeaf(targetNode, tNode) + parentLevel;

                    if(distance < parentDistance)
                    {
                        parentLeaf = tNode;
                        parentDistance = distance;
                    }
                    ++parentLevel;
                }
            }

            //std::cout<<parentDistance<<std::endl;

            return childDistance < parentDistance ? firstChildLeaf->val : parentLeaf->val;
        }
    }

    int findFirstChildLeaf(TreeNode* targetNode, TreeNode*& firstChildLeaf)
    {
        int childDistance = 0;

        std::queue<TreeNode*> q;
        q.push(targetNode);

        while(!q.empty())
        {
            int n = q.size();
            bool found = false;
            for(int i = n; i > 0; --i)
            {
                TreeNode* p = q.front();
                q.pop();

                if(!p->left && !p->right)
                {
                    firstChildLeaf = p;
                    found = true;
                    break;
                }
                else
                {
                    if(p->left) q.push(p->left);
                    if(p->right) q.push(p->right);
                }
            }

            if(found)
            {
                break;
            }

            ++childDistance;
        }

        return childDistance;
    }
};

int main()
{
    Solution s;
    TreeNode* a = new TreeNode(1);
    TreeNode* b = new TreeNode(2);
    TreeNode* c = new TreeNode(3);
    a->left = b;
    a->right = c;
    TreeNode* d = new TreeNode(4);
    TreeNode* e = new TreeNode(5);
    TreeNode* f = new TreeNode(6);
    b->left = d;
    d->left = e;
    e->left = f;
    std::cout<<s.findClosestLeaf(a, 2)<<std::endl;
}
