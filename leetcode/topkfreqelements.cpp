class Solution {
    public:
        vector<int> topKFrequent(vector<int>& nums, int k) {
            typedef std::map<int, int> IntMap;
            typedef IntMap::iterator IMIter;

            IntMap countMap;
            for(size_t i = 0, sz = nums.size(); i < sz; ++i)
            {
                if(countMap.find(nums[i]) != countMap.end())
                {
                    countMap[nums[i]] = countMap[nums[i]] + 1;
                }
                else
                {
                    countMap[nums[i]] = 1;
                }
            }

            typedef std::map<int, std::vector<int>* > OrderMap;
            typedef OrderMap::iterator OMIter;
            typedef OrderMap::reverse_iterator OMRter;
            OrderMap orderMap;
            for(IMIter itr = countMap.begin(), end = countMap.end(); itr != end; ++itr)
            {
                if(orderMap.find(itr->second) != orderMap.end())
                {
                    orderMap[itr->second]->push_back(itr->first);
                }
                else
                {
                    std::vector<int>* vec = new std::vector<int>();
                    vec->push_back(itr->first);
                    orderMap[itr->second] = vec;
                }
            }

            std::vector<int> result;
            int count = 0;
            for(OMRter itr = orderMap.rbegin(), end = orderMap.rend(); itr != end && count != k; ++itr)
            {
                std::vector<int>* vec = itr->second;
                for(size_t i = 0, sz = vec->size(); i < sz && count != k; ++i, ++count)
                {
                    result.push_back((*vec)[i]);
                }
            }

            return result;
        }
};
