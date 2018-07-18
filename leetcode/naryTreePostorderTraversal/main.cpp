#include "header.h"

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<int> postorder(Node* root) {
        if(!root) return {};
        stack<Node*> s;
        s.push(root);
        vector<int> res;

        while(!s.empty())
        {
            Node* node = s.top();
            s.pop();
            res.emplace_back(node->val);
            for(int i = 0, n = node->children.size(); i < n; ++i)
            {
                s.push(node->children[i]);
            }
        }

        reverse(res.begin(), res.end());
        return res;
    }
};


int main()
{
    //Solution s;
}
