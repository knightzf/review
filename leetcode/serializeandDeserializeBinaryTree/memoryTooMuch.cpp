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
        string res;
        if(root == nullptr) return res;

        std::queue<TreeNode*> q;
        q.push(root);
        int qsize = q.size();
        while(true)
        {
            bool allnull = true;
            for(int i = 0; i < qsize; ++i)
            {
                TreeNode* n = q.front();
                q.pop();
                if(n != nullptr)
                {
                    allnull = false;
                    res += std::to_string(n->val) + ",";
                    q.push(n->left);
                    q.push(n->right);
                }
                else
                {
                    res += ",";
                    q.push(nullptr);
                    q.push(nullptr);
                }
            }

            if(allnull)
            {
                break;
            }
            else
            {
                qsize = q.size();
            }
        }

        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int n = data.size();
        if(n == 0) return nullptr;

        std::vector<TreeNode*> v;
        int startIdx = 0;
        for(int i = 0; i < n; ++i)
        {
            if(data[i] == ',')
            {
                if(i == startIdx)
                {
                    v.push_back(nullptr);
                }
                else
                {
                    v.push_back(new TreeNode(std::stoi(data.substr(startIdx, i - startIdx))));
                }
                startIdx = i + 1;
            }
        }

        int vs = v.size();
        for(int i = 0; i < vs; ++i)
        {
            if(v[i])
            {
                if(2 * i + 1 < vs)
                {
                    v[i]->left = v[2 * i + 1];
                }
                if(2 * i + 2 < vs)
                {
                    v[i]->right = v[2 * i + 2];
                }
            }
        }

        return v[0];
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
