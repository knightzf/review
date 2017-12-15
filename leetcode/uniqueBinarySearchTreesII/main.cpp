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
    vector<TreeNode*> generateTrees(int n)
    {
        std::vector<int> v(n);
        for(int i = 0; i < n; ++i)
        {
            v[i] = i + 1;
        }

        return impl(v);
    }

    vector<TreeNode*> impl(std::vector<int>& v)
    {
        vector<TreeNode*> res;

        if(v.size() == 1)
        {
            res.push_back(new TreeNode(v[0]));
            return res;
        }

        for(int i = 0; i < v.size(); ++i)
        {
            std::vector<int> leftV;
            std::vector<int> rightV;

            //std::cout<<"call imp "<<v.size()<<" i "<<i<<std::endl;
            if(i > 0)
            {
                leftV.insert(leftV.end(), v.begin(), v.begin() + i);
                //std::cout<<"left "<<leftV.size()<<std::endl;
            }

            if(i < v.size() - 1)
            {
                rightV.insert(rightV.end(), v.begin() + i + 1, v.end());
                //std::cout<<"right "<<rightV.size()<<std::endl;
            }

            if(!leftV.empty() && rightV.empty())
            {
                const auto& r = impl(leftV);
                for(auto t : r)
                {
                    TreeNode* h = new TreeNode(v[i]);
                    h->left = t;
                    res.push_back(h);
                }
            }

            if(leftV.empty() && !rightV.empty())
            {
                const auto& r = impl(rightV);
                for(auto t : r)
                {
                    TreeNode* h = new TreeNode(v[i]);
                    h->right = t;
                    res.push_back(h);
                }
            }

            if(!leftV.empty() && !rightV.empty())
            {
                const auto& l = impl(leftV);
                const auto& r = impl(rightV);
                for(auto m : l)
                {
                    for(auto n : r)
                    {
                        TreeNode* h = new TreeNode(v[i]);
                        h->left = m;
                        h->right = n;
                        res.push_back(h);
                    }
                }
            }
        }

        return res;
    }
};
int main()
{
    Solution s;
    std::cout<<s.generateTrees(3).size()<<std::endl;;
}
