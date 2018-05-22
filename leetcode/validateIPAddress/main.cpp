#include "header.h"

class Solution {
public:
    string validIPAddress(string IP) {
        if(IP.find(".") != string::npos)
        {
            if(isV4(IP)) return "IPv4";
        }
        else
        {
            if(isV6(IP)) return "IPv6";
        }
        return "Neither";
    }

    bool isV4(const string& ip)
    {
        vector<string> v;
        parse(ip, v, '.');
        if(v.size() != 4) return false;
        for(int i = 0; i < 4; ++i)
        {
            if(v[i].empty() || v[i].size() > 4) return false;
            if(v[i].size() > 1 && v[i][0] == '0') return false;
            for(int j = 0; j < v[i].size(); ++j)
            {
                if(!isdigit(v[i][j])) return false;
            }

            int t = stoi(v[i]);
            if(t > 255) return false;
        }
        return true;
    }

    bool isV6(const string& ip)
    {
        vector<string> v;
        parse(ip, v, ':');
        if(v.size() != 8) return false;
        for(int i = 0; i < 8; ++i)
        {
            if(v[i].empty() || v[i].size() > 4) return false;
            for(int j = 0; j < v[i].size(); ++j)
            {
                if(!isoct(v[i][j])) return false;
            }
        }
        return true;
    }

    void parse(const string& ip, vector<string>& v, char c)
    {
        int startIdx = 0;
        for(int i = 0; i < ip.size(); ++i)
        {
            if(ip[i] == c)
            {
                v.push_back(ip.substr(startIdx, i - startIdx));
                startIdx = i + 1;
            }
        }
        v.push_back(ip.substr(startIdx));
    }

    bool isoct(char c)
    {
        if(isdigit(c)) return true;
        c = tolower(c);
        if(c - 'a' >= 0 && c - 'a' <= 5) return true;
        return false;
    }
};

int main()
{
    Solution s;
    cout<<s.validIPAddress("172.16.254.1")<<endl;
    cout<<s.validIPAddress("256.256.256.256")<<endl;
    cout<<s.validIPAddress("2001:0db8:85a3:0:0:8A2E:0370:7334")<<endl;
}
