#include "header.h"

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> s;
        for(const auto& email : emails)
        {
            int atIdx = email.find('@');
            string localName;
            for(int i = 0; i < atIdx; ++i)
            {
                if(email[i] == '+') break;
                if(email[i] == '.') continue;
                localName += email[i];
            }
            s.insert(localName + email.substr(atIdx));
        }
        return s.size();
    }
};

int main()
{
    //Solution s;
}
