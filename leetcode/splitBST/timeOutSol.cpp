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

class Solution {
public:
    vector<TreeNode*> splitBST(TreeNode* root, int V) {
        if(root == nullptr) return vector<TreeNode*>{nullptr, nullptr};

        TreeNode* target = nullptr;
        inorder(root, V, target);

        if(target == nullptr) return vector<TreeNode*>{root, nullptr};

        vector<TreeNode*> v;
        traverseByLayer(root, v);

        vector<TreeNode*> res;
        for(int i = 0; i < v.size(); ++i)
        {
            if(v[i] == target)
            {
                int idx = i;
                if(idx == 0)
                {
                    res.push_back(root);
                    res.push_back(root->right);
                    root->right = nullptr;
                }
                else
                {
                    int t = idx;
                    while(t > 2)
                    {
                        t = t % 2 == 0 ? (t - 2)/2 : (t - 1)/2;
                    }

                    bool left = t == 1 ? true : false;

                    if(idx % 2 == 0)
                    {
                        int pIdx = (idx - 2)/2;
                        if(left)
                        {
                            int ppIdx = pIdx % 2 == 0 ? (pIdx - 2)/2 : (pIdx - 1)/2;
                            while(v[ppIdx]->val < v[idx]->val)
                            {
                                ppIdx = ppIdx % 2 == 0 ? (ppIdx - 2)/2 : (ppIdx - 1)/2;
                            }
                            res.push_back(v[ppIdx]->left);

                            v[ppIdx]->left = v[idx]->right;
                            v[idx]->right = nullptr;
                            res.push_back(root);
                        }
                        else
                        {
                            v[pIdx]->right = v[idx]->left;
                            v[idx]->left = nullptr;
                            res.push_back(root);
                            res.push_back(v[idx]);
                        }
                    }
                    else
                    {
                        int pIdx = (idx - 1)/2;
                        if(left)
                        {
                            v[pIdx]->left = v[idx]->right;
                            v[idx]->right = nullptr;
                            res.push_back(root);
                            res.push_back(v[idx]);
                        }
                        else
                        {
                            int ppIdx = pIdx % 2 == 0 ? (pIdx - 2)/2 : (pIdx - 1)/2;
                            while(v[ppIdx]->val > v[idx]->val)
                            {
                                ppIdx = ppIdx % 2 == 0 ? (ppIdx - 2)/2 : (ppIdx - 1)/2;
                            }
                            res.push_back(v[ppIdx]->right);

                            v[ppIdx]->right = v[idx];
                            v[pIdx]->left = v[idx]->right;
                            v[idx]->right = nullptr;
                            res.push_back(root);
                        }
                    }
                }
            }
        }

        return res;
    }

    void traverseByLayer(TreeNode* root, vector<TreeNode*>& v)
    {
        std::queue<TreeNode*> q;
        q.push(root);
        int qsize = q.size();
        while(!q.empty())
        {
            if(q.front() == nullptr) break;
            for(int i = 0; i < qsize; ++i)
            {
                TreeNode* t = q.front();
                q.pop();
                v.push_back(t);
                if(t)
                {
                    q.push(t->left);
                    q.push(t->right);
                }
                else
                {
                    q.push(nullptr);
                    q.push(nullptr);
                }
            }

            qsize = q.size();
        }
    }

    void inorder(TreeNode* root, int V, TreeNode*& target)
    {
        if(root == nullptr) return;

        inorder(root->left, V, target);

        if(root->val <= V)
        {
            target = root;
        }
        else
        {
            return;
        }

        inorder(root->right, V, target);
    }
};

int main() {
    Solution s;
    TreeNode* a = new TreeNode(4);
    TreeNode* b = new TreeNode(2);
    TreeNode* c = new TreeNode(6);
    TreeNode* d = new TreeNode(1);
    TreeNode* e = new TreeNode(3);
    TreeNode* f = new TreeNode(5);
    TreeNode* g = new TreeNode(7);
    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;

    s.splitBST(a, 2);
}
