class Solution {
private:
    string base = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    unordered_map<string, long> urlIdMap;
    unordered_map<long, string> idUrlMap;
    int id = 0;
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if(!urlIdMap.count(longUrl)) {
            urlIdMap[longUrl] = id++;
            idUrlMap[id - 1] = longUrl;
        }
        return base62(urlIdMap[longUrl]);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        long key = 0;
        for(char c : shortUrl) {
            key = key * 62;
            key += (int)base.find(c);
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
