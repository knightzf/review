#include "header.h"

class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        vector<string> res;

        std::unordered_map<string, int> m;

        for(const auto& s : cpdomains)
        {
            int num = 0;
            int lastIdx = 0;
            for(int i = 0; i < s.size(); ++i)
            {
                char c = s[i];
                switch(c)
                {
                case ' ':
                    num = std::stoi(s.substr(0, i));
                    m[s.substr(i + 1)] += num;
                    lastIdx = i;
                    break;
                case '.':
                    m[s.substr(i + 1)] += num;
                    lastIdx = i;
                    break;
                default:
                    break;
                }
            }
        }

        for_each(m.begin(), m.end(), [&](const std::unordered_map<string, int>::value_type& p){
                 res.push_back(std::to_string(p.second) + ' ' + p.first);
                 });
        return res;
    }
};

int main()
{
    Solution s;
    vector<string> a{"900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"};
    const auto& r = s.subdomainVisits(a);
    for(const auto& i : r)
    {
        std::cout<<i<<std::endl;
    }
}
