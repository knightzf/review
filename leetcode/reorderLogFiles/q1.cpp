#include "header.h"

class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<pair<string, string>> letterLog;
        vector<string> digitLog;
        for(const auto& log : logs)
        {
            int i = log.find(' ');
            int j = i + 1;
            while(log[j] == ' ') ++j;
            if(isdigit(log[j]))
            {
                digitLog.emplace_back(log);
            }
            else
            {
                letterLog.emplace_back(log.substr(0, i), log.substr(i));
            }
        }
        sort(letterLog.begin(), letterLog.end(), [](const auto& a, const auto& b){
            if(a.second < b.second) return true;
            else if(a.second == b.second) return string(a.first + a.second) < string(b.first + b.second);
            return false;
        });

        vector<string> res;
        for(auto& p : letterLog)
            res.emplace_back(p.first + p.second);
        for(auto& s : digitLog)
            res.emplace_back(s);
        return res;
    }
};

int main()
{
    //Solution s;
}
