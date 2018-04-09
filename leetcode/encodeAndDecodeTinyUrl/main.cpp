#include "header.h"

class Solution {
private:
    int idx = 0;
    unordered_map<int, string> m;
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        m[idx] = longUrl;
        return "http://tinyurl/com/" + to_string(idx++);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        int i = shortUrl.size() - 1;
        for(; i >= 0; --i)
        {
            if(shortUrl[i] == '/')
            {
                ++i;
                break;
            }
        }
        return m[stoi(shortUrl.substr(i))];
    }
};

int main()
{
    Solution s;
}
