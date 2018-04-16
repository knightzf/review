#include "header.h"

class Solution {
public:
    vector<string> ambiguousCoordinates(string S) {
        int n = S.size();
        vector<string> res;
        for(int i = 1; i < n - 2; ++i)
        {
            const auto& first = S.substr(1, i);
            const auto& second = S.substr(i + 1, n - i - 2);
            //std::cout<<first<<" "<<second<<std::endl;

            const auto& r1 = parse(first);
            const auto& r2 = parse(second);
            if(!r1.empty() && !r2.empty())
            {
                for(const auto& i : r1)
                {
                    for(const auto& j : r2)
                    {
                        res.push_back("(" + i + ", " + j + ")");
                        //std::cout<<res.back()<<std::endl;
                    }
                }
            }
        }

        return res;
    }

    vector<string> parse(const string& s)
    {
        if(s.size() == 1) return {s};
        //std::cout<<s<<" "<<(s[0] == '0') <<" "<< (s.back() != '0')<<" "
        //<<(s.substr(0, 1) + "." + s.substr(1))<<std::endl;
        if(s[0] == '0' && s.back() == '0') return {};
        if(s[0] == '0' && s.back() != '0') return {s.substr(0, 1) + "." + s.substr(1)};
        if(s[0] != '0' && s.back() == '0') return {s};
        vector<string> res;
        res.push_back(s);
        for(int i = 1; i <= s.size() - 1; ++i)
        {
            res.push_back(s.substr(0, i) + '.' + s.substr(i));
        }
        return res;
    }
};

int main()
{
    Solution s;
    //const auto& r = s.ambiguousCoordinates("(0123)");
    //const auto& r = s.ambiguousCoordinates("(123)");
    //const auto& r = s.ambiguousCoordinates("(00011)");
    const auto& r = s.ambiguousCoordinates("(100)");
    for(const auto& i : r)
        std::cout<<i<<std::endl;
}
