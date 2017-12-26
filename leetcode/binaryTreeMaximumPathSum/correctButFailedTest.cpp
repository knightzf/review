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

struct Node {
    int val;
    Node* left;
    Node* right;
    Node* parent;
    Node(int x) : val(x), left(NULL), right(NULL), parent(NULL) {}
};

class Solution {
public:
    int maxPathSum(TreeNode* root)
    {
        if(root == nullptr)
        {
            return 0;
        }

        std::set<Node*> nodeSet;
        loopTree(root, nullptr, true, nodeSet);

        //std::cout<<nodeSet.size()<<std::endl;

        std::vector<Node*> nodeV(nodeSet.begin(), nodeSet.end());

        //std::cout<<nodeV.size()<<std::endl;

        std::unordered_map<Node*, int> idxMap;
        for(int i = 0; i < nodeV.size(); ++i)
        {
            idxMap[nodeV[i]] = i;
        }

        std::vector<std::vector<int>> sum(nodeV.size(), std::vector<int>(nodeV.size(), -1));

        for(int i = 0; i < sum.size(); ++i)
        {
            sum[i][i] = nodeV[i]->val;
        }

        for(int i = 0; i < nodeV.size(); ++i)
        {
            for(int j = i + 1; j < nodeV.size(); ++j)
            {
                //std::cout<<i<<" "<<j<<" "<<nodeV[i]->val<<" "<<nodeV[j]->val<<std::endl;
                std::set<Node*> visited;
                findSum(nodeV[i], nodeV[j], sum, idxMap, visited);
            }
        }

        /*for(const auto& i : sum)
        {
            for(auto j : i)
            {
                std::cout<<j<<" ";
            }
            std::cout<<std::endl;
        }*/

        int max = INT_MIN;

        for(int i = 0; i < sum.size(); ++i)
        {
            for(int j = i; j < sum.size(); ++j)
            {
                max = std::max(max, sum[i][j]);
            }
        }

        return max;
    }

    void findSum(Node* a, Node* b,
                 std::vector<std::vector<int>>& sum,
                 const std::unordered_map<Node*, int>& idxMap,
                 std::set<Node*>& visited)
    {
        if(visited.find(a) != visited.end())
        {
            return;
        }

        int idxA = idxMap.at(a);
        int idxB = idxMap.at(b);

        if(idxA > idxB)
        {
            std::swap(idxA, idxB);
        }

        if(sum[idxA][idxB] > 0)
        {
            return;
        }

        if(a->left == b || a->right == b || a->parent == b)
        {
            sum[idxA][idxB] = a->val + b->val;
            return;
        }

        visited.insert(a);

        if(a->left)
        {
            findSum(a->left, b, sum, idxMap, visited);
            int idxa = idxMap.at(a->left);
            int idxb = idxMap.at(b);
            if(idxa > idxb) std::swap(idxa, idxb);
            if(sum[idxa][idxb] > 0)
            {
                sum[idxA][idxB] = a->val + sum[idxa][idxb];
            }
        }

        if(a->right)
        {
            findSum(a->right, b, sum, idxMap, visited);
            int idxa = idxMap.at(a->right);
            int idxb = idxMap.at(b);
            if(idxa > idxb) std::swap(idxa, idxb);
            if(sum[idxa][idxb] > 0)
            {
                sum[idxA][idxB] = a->val + sum[idxa][idxb];
            }
        }

        if(a->parent)
        {
            findSum(a->parent, b, sum, idxMap, visited);
            int idxa = idxMap.at(a->parent);
            int idxb = idxMap.at(b);
            if(idxa > idxb) std::swap(idxa, idxb);
            if(sum[idxa][idxb] > 0)
            {
                sum[idxA][idxB] = a->val + sum[idxa][idxb];
            }
        }

        visited.erase(a);
    }

    void loopTree(TreeNode* node, Node* parent, bool left, std::set<Node*>& nodeSet)
    {
        Node* n = new Node(node->val);
        n->parent = parent;

        nodeSet.insert(n);

        if(parent)
        {
            if(left)
            {
                parent->left = n;
            }
            else
            {
                parent->right = n;
            }
        }

        if(node->left)
        {
            loopTree(node->left, n, true, nodeSet);
        }

        if(node->right)
        {
            loopTree(node->right, n, false, nodeSet);
        }
    }
};

int main()
{
    Solution s;
    /*TreeNode* a = new TreeNode(1);
    TreeNode* b = new TreeNode(-2);
    TreeNode* c = new TreeNode(-3);
    a->left = b;
    a->right = c;
    TreeNode* d = new TreeNode(1);
    TreeNode* e = new TreeNode(3);
    b->left = d;
    b->right = e;
    TreeNode* f = new TreeNode(-2);
    c->left = f;
    TreeNode* g = new TreeNode(-1);
    d->left = g;*/
    TreeNode* a = new TreeNode(1);
    TreeNode* b = new TreeNode(2);
    TreeNode* c = new TreeNode(3);
    TreeNode* d = new TreeNode(4);
    TreeNode* e = new TreeNode(5);
    a->right = b;
    b->right = c;
    c->right = d;
    d->right = e;
    std::cout<<s.maxPathSum(a)<<std::endl;
}
