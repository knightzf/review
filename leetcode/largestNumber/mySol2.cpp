#include "header.h"

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> v;
        for(int i : nums) v.emplace_back(to_string(i));
        sort(v.begin(), v.end(), [](const string& a, const string& b){
            return a + b > b + a;
        });
        string res;
        for(const auto s : v) {
            if(res.empty() || res[0] != '0')
                res += s;
        }
        return res;
    }
};

int main()
{
    //Solution s;
}