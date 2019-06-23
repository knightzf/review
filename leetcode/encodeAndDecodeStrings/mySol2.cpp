#include "header.h"

class Codec {
public:
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        stringstream ss;
        ss << "[";
        for(const auto& s : strs) ss << s.size() << ",";
        ss << "]";
        for(const auto& s : strs) ss << s;
        return ss.str();
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> res;
        vector<int> v;
        int startIdx = 1;
        for(int i = 1, n = s.size(); i < n; ++i) {
            if(s[i] == ']') break;
            if(s[i] == ',') {
                v.push_back(stoi(s.substr(startIdx, i - startIdx)));
                startIdx = i + 1;
            }
        }        
        ++startIdx;
        for(int i = 0; i < v.size(); ++i) {
            res.emplace_back(s.substr(startIdx, v[i]));
            startIdx += v[i];
        }
        return res;
    }
};


int main()
{
    //Solution s;
}