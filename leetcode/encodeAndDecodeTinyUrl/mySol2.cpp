#include "header.h"

class Solution {
private:
    string base = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    unordered_map<string, long> urlIdMap;
    unordered_map<long, string> idUrlMap;
    int id = 0;
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if(!urlIdMap.count(longUrl)) urlIdMap[longUrl] = id++;
        return base62(urlIdMap[longUrl]);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        long key = 0;
        for(char c : shortUrl) {
            key = key * 62;
            if(c <= '9') key += c - '0';
            else if(c >= 'a') key += c - 'a';
            else key += c - 'A';
        }
        return idUrlMap[key];
    }

    string base62(long key) {
        string res;
        while(key) {
            res += base[key % 62];
            key /= 62;
        }
        return res + (res.size() < 6 ? string(6 - res.size(), '0') : "");
    }
};

int main()
{
    //Solution s;
    string s = "abcd";
    string r;
    int t = 0;
    for(char c : s) {
        t = t * 256 + c - 'a';
        t %= 62;
        if(t < 26) r += 'a' + t;
        else if(t < 52) r += 'A' + (t - 26);
        else r += '0' + (t - 52);
    }
    cout<<r<<endl;
}