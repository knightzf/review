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
    int sumNumbers(TreeNode* root)
    {
        int sum = 0;
        std::string s;
        impl(root, s, sum);
        return sum;
    }

    void impl(TreeNode* node, std::string s, int& sum)
    {
        if(node == nullptr)
        {
            return;
        }

        s += node->val + '0';

        if(!node->left && !node->right)
        {
            sum += std::stoi(s);
            return;
        }

        impl(node->left, s, sum);
        impl(node->right, s, sum);
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
    std::cout<<s.sumNumbers(a)<<std::endl;
}
