#include "header.h"

class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        string s;
        for(int i = 0; i < sentence.size(); ++i)
        {
            s += (i != 0 ? " " : "") + sentence[i];
        }
        s += " ";

        int start = 0, len = s.size();
        for(int i = 0; i < rows; ++i)
        {
            start += cols;
            if(s[start % len] == ' ')
            {
                ++start;
            }
            else
            {
                while(start > 0 && s[(start - 1) % len] != ' ') --start;
            }
        }

        return start / len;
    }
};

int main()
{
    Solution s;
    vector<string> a{"hello", "world"};
    std::cout<<s.wordsTyping(a, 2, 8)<<std::endl;
}
