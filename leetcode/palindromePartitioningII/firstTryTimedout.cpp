class Solution {
    public:
        bool isPalindrome(const std::string& s)
        {
            if(s.size() < 1) return true;

            if(palinMap.find(s) != palinMap.end())
            {
                return palinMap[s];
            }

            int i = 0;
            int j = s.size() - 1;

            bool isPalin = true;

            while(i < j)
            {
                if(s[i] != s[j])
                {
                    isPalin = false;
                    break;
                }
                ++i;
                --j;
            }

            palinMap[s] = isPalin;

            return isPalin;
        }

        int minCut(string s)
        {
            if(s.size() < 2) return 0;

            impl(s);
            return palinCache[s];
        }

        int impl(const string& s)
        {
            if(s.size() == 1 || isPalindrome(s))
            {
                palinCache[s] = 0;
                return 0;
            }

            if(palinCache.find(s) != palinCache.end())
            {
                return palinCache[s];
            }

            int mincuts = INT_MAX;

            for(int i = 0; i < s.size(); ++i)
            {
                int cuts = INT_MAX;
                const std::string& pre = s.substr(0, i + 1);
                if(isPalindrome(pre))
                {
                    if(i == s.size() - 1)
                    {
                        cuts = 0;
                    }
                    else
                    {
                        const std::string& rest = s.substr(i + 1);
                        int resCuts = impl(rest);
                        cuts = 1 + resCuts;
                    }
                }

                mincuts = std::min(mincuts, cuts);
            }

            if(palinCache.find(s) != palinCache.end())
            {
                if(mincuts < palinCache[s])
                {
                    palinCache[s] = mincuts;
                }
            }
            else
            {
                palinCache[s] = mincuts;
            }

            return palinCache[s];
        }

    private:
        std::unordered_map<std::string, bool> palinMap;
        std::unordered_map<std::string, int> palinCache;
};
