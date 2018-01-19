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
    int countNodes(TreeNode* root) {
        std::stack<TreeNode*> s;
        TreeNode* t = root;
        while(t)
        {
            s.push(t);
            t = t->left;
        }

        int h = s.size();

        int lastRowCount = 0;

        int len = -1;

        while(!s.empty())
        {
            TreeNode* p = s.top();
            s.pop();

            if(len == -1)
            {
                ++lastRowCount;
            }
            else
            {
                int temp = getLastRowCount(p->right, len);
                lastRowCount += temp;
                if(temp != std::pow(2, len))
                {
                    break;
                }
            }

            ++len;
        }

        int c = 0;
        for(int i = 0; i < h - 1; ++i)
        {
            c += std::pow(2, i);
        }

        //std::cout<<c<<" "<<lastRowCount<<std::endl;

        return c + lastRowCount;
    }

    int getLastRowCount(TreeNode* node, int h)
    {
        if(node == nullptr) return 0;

        std::queue<TreeNode*> q;
        q.push(node);

        int qsize = q.size();
        int level = 0;
        while(level != h)
        {
            for(int i = 0; i < qsize; ++i)
            {
                TreeNode* n = q.front();
                q.pop();
                if(n->left) q.push(n->left);
                if(n->right) q.push(n->right);
            }

            qsize = q.size();
            ++level;
        }

        return q.size();
    }
};

int main() {
    Solution s;
    TreeNode* a = new TreeNode(1);
    TreeNode* b = new TreeNode(2);
    TreeNode* c = new TreeNode(3);
    a->left = b; a->right = c;
    s.countNodes(a);
}
