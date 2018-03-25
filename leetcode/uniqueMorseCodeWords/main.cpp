#include "header.h"

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        static vector<string> code{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

        std::unordered_set<string> s;
        for(int i = 0; i < words.size(); ++i)
        {
            string t;
            for(int j = 0; j < words[i].size(); ++j)
                t += code[words[i][j] - 'a'];
            s.insert(t);
        }
        return s.size();
    }
};

int main()
{
    Solution s;
}
