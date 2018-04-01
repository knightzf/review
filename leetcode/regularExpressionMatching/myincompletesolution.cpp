#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <sstream>
#include <cmath>
#include <queue>
#include <map>
#include <string>
#include <cstdlib>
#include <cctype>
#include <stdexcept>

using namespace std;

class Solution {
public:
    enum Type {NONE, STR, DOT, STAR, ANY};

    bool isMatch(string s, string p)
    {
        std::vector<std::pair<Type, std::string>> regexVec;

        size_t start = 0;
        size_t i = 0;
        while(i != p.size())
        {
            switch(p[i])
            {
            case '.':
                if(i + 1 < p.size() && p[i+1] == '*')
                {
                    regexVec.push_back(std::make_pair(ANY, std::string(".*")));
                    i += 2;
                    start = i;
                }
                else
                {
                    regexVec.push_back(std::make_pair(DOT, std::string(".")));
                    ++i;
                    start = i;
                }
                break;
            case '*':
                throw std::logic_error("should never come here");
                break;
            default:
                if(i + 1 < p.size())
                {
                    switch(p[i+1])
                    {
                    case '*':
                        regexVec.push_back(std::make_pair(STAR, p.substr(i, 1)));
                        i += 2;
                        start = i;
                        break;
                    case '.':
                        regexVec.push_back(std::make_pair(STR, p.substr(start, i - start + 1)));
                        ++i;
                        start = i;
                        break;
                    default:
                        ++i;
                        break;
                    }
                }
                else
                {
                    regexVec.push_back(std::make_pair(STR, p.substr(start)));
                    ++i;
                }
                break;
            }
        }

        for(size_t i = 0, sz = regexVec.size(); i < sz; ++i)
        {
            if(regexVec[i].first == DOT)
            {
                int temp = i + 1;
                while(temp < sz)
                {
                    if(regexVec[temp].first == STR)
                    {
                        regexVec[i].second = regexVec[i].second + regexVec[temp].second;
                        regexVec[temp].first = NONE;
                        break;
                    }
                    else if(regexVec[temp].first == DOT)
                    {
                        regexVec[i].second = regexVec[i].second + ".";
                        regexVec[temp].first = NONE;
                    }

                    ++temp;
                }
            }
        }

        for (auto it = regexVec.begin(); it != regexVec.end();)
        {
           if(it->first == NONE)
              it = regexVec.erase(it);
          else
              ++it;
         }

        for(auto& item : regexVec)
        {
            std::cout<<item.first<<" "<<item.second<<" ";
        }
        std::cout<<std::endl;

        size_t regIdx = 0;
        size_t regSz = regexVec.size();

        size_t strIdx = 0;
        size_t strSz = s.size();
        while(regIdx < regSz)
        {
            switch(regexVec[regIdx].first)
            {
            case STR:
            {
                size_t len = regexVec[regIdx].second.size();
                if(strIdx + len - 1 < strSz && s.substr(strIdx, len) == regexVec[regIdx].second)
                {
                    ++regIdx;
                    strIdx = strIdx + len;
                }
                else
                {
                    return false;
                }
                break;
            }
            case DOT:
            {
                size_t len = regexVec[regIdx].second.size();
                if(strIdx + len > strSz)
                {
                    return false;
                }
                else
                {
                    for(size_t i = 0; i < len; ++i)
                    {
                        if(regexVec[regIdx].second[i] == '.')
                            continue;

                        if(s[strIdx + i] != regexVec[regIdx].second[i])
                            return false;
                    }

                    ++regIdx;
                    strIdx += len;
                }
                break;
            }
            case STAR:
            {
                if(regIdx == regSz - 1)
                {
                    char c = regexVec[regIdx].second[0];
                    while(strIdx < strSz)
                    {
                        if(s[strIdx] != c)
                            return false;

                        ++strIdx;
                    }
                    return true;
                }
                else
                {
                    switch(regexVec[regIdx + 1].first)
                    {
                    case STR:
                    {
                        char c = regexVec[regIdx].second[0];
                        if(s[strIdx] == c)
                        {
                            size_t len = regexVec[regIdx + 1].second.size();
                            if(std::string(len, c) == regexVec[regIdx + 1].second)
                            {
                                std::swap(regexVec[regIdx], regexVec[regIdx + 1]);
                            }
                            else
                            {
                                bool found = false;
                                while(strIdx + len - 1 < strSz )
                                {
                                    if(s.substr(strIdx, len) == regexVec[regIdx + 1].second)
                                    {
                                        found = true;
                                        regIdx += 2;
                                        strIdx = strIdx + len;
                                        break;
                                    }

                                    if(s[strIdx] != c)
                                        return false;

                                    ++strIdx;
                                }

                                if(!found)
                                    return false;
                            }
                        }
                        else
                        {
                            ++regIdx;
                        }
                        break;
                    }
                    case DOT:
                    {
                        size_t len = regexVec[regIdx + 1].second.size();
                        if(strIdx + len > strSz)
                        {
                            return false;
                        }
                        else
                        {
                            //I stopped here because two reasons
                            //1. This is already very complicated, and I haven't started the ANY case
                            //2. I am not sure what to do here, how aggressvie should the match be
                        }
                        break;
                    }
                    case STAR:
                    {
                        if(regexVec[regIdx].second != regexVec[regIdx + 1].second)
                        {
                            char c = regexVec[regIdx].second[0];
                            if(s[strIdx] == c)
                            {
                                while(strIdx < strSz && s[strIdx] == c)
                                {
                                    ++strIdx;
                                }
                            }
                        }
                        ++regIdx;
                        break;
                    }
                    case ANY:
                        ++regIdx;
                        break;
                    }
                }
                break;
            }
            case ANY:
            {
                break;
            }
            }
        }

        return regIdx == regSz && strIdx == strSz;
    }
};

int main()
{
    Solution sol;
    //std::cout<<sol.isMatch("aab", "c*a*b")<<std::endl;
    std::cout<<sol.isMatch("aaaaaaa", "a*.aa.a")<<std::endl;
	return 0;
}
