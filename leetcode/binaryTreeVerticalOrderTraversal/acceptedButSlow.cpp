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

struct Test
{
    Test(TreeNode* n, int i) : node(n), idx(i)
    {

    }
    TreeNode* node;
    int idx;
};
class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        std::map<int, std::vector<int>> m;
        std::queue<Test> q;
        if(root) q.push(Test(root, 0));
        int qsize = q.size();

        while(!q.empty())
        {
            for(int i = 0; i < q.size(); ++i)
            {
                Test& t = q.front();
                m[t.idx].push_back(t.node->val);

                if(t.node->left)
                {
                    q.push(Test(t.node->left, t.idx - 1));
                }
                if(t.node->right)
                {
                    q.push(Test(t.node->right, t.idx + 1));
                }

                q.pop();
            }

            qsize = q.size();
        }

        vector<vector<int>> res;
        for(const auto& p : m)
        {
            res.push_back(p.second);
        }

        return res;
    }
};

int main() {
    Solution s;
}
