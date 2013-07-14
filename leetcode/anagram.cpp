
class Solution {
public:

     static vector<string> anagrams(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        std::vector<std::string> result;
        
        if(strs.empty())
        {
            return result;
        }
        
        typedef std::map<std::string, std::multiset<std::string> > StrMap;
        StrMap strmap;
            
        for(int i = 0; i < strs.size(); ++i)
        {
            std::string str = strs[i];
            std::sort(str.begin(), str.end());
            
            StrMap::iterator iter = strmap.find(str);
            if(iter != strmap.end())
            {
                iter->second.insert(strs[i]);
            }
            else
            {
                std::multiset<std::string> a;
                a.insert(strs[i]);
                strmap.insert(StrMap::value_type(str, a ));
            }
        }
        
        for(StrMap::iterator iter = strmap.begin(); iter != strmap.end(); ++iter)
        {
            if(iter->second.size() > 1)
            {
                std::copy (iter->second.begin(),iter->second.end(),back_inserter(result));
            }
        }
        
    }
};

