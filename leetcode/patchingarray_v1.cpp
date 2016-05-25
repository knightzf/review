class Solution {
public:
    typedef std::set<int> Set;

    void update(std::set<int>& numSet, std::vector<bool>& allNums, int num)
    {
    	std::vector<int> updates;
    	updates.push_back(num);
        for(Set::iterator iter = numSet.begin(), end = numSet.end();
                iter != end; ++iter)
        {
            updates.push_back(*iter + num);
            allNums[*iter + num] = true;
        }

        for(size_t i = 0, sz = updates.size(); i < sz; ++i)
        {
        	numSet.insert(updates[i]);
        }
        allNums[num] = true;
    }

    int minPatches(vector<int>& nums, int n) {
        std::vector<bool> allNums;
        allNums.reserve(n + 1);

        for(int i = 1; i < n + 1; ++i)
        {
            allNums[i] = false;
        }

        std::set<int> numSet;

        for(size_t i = 0, sz = nums.size(); i < sz; ++i)
        {
            update(numSet, allNums, nums[i]);
        }

        int minPatch = 0;

        for(int i = 1; i < n + 1; ++i)
        {
        	//std::cout<<"i "<<i<<std::endl;
            if(allNums[i] == false)
            {
                int j = i;
                while(allNums[j] == false && j > 1)
                {
                    --j;
                }

                //std::cout<<"j "<<j<<std::endl;

                if(allNums[j])
                {
                    int diff = i - j;
                    //std::cout<<"diff "<<diff<<std::endl;
                    if(allNums[diff] == false)
                    {
                    	update(numSet, allNums, diff);
                    }
                    else
                    {
                        update(numSet, allNums, i);
                    }
                }
                else
                {
                    update(numSet, allNums, i);
                }

                ++minPatch;

                if(numSet.size() == n)
                	break;
            }

            /*for(int i = 1; i < n + 1; ++i)
            {
            	std::cout<<i<<"-"<<allNums[i]<<", ";
            }
            std::cout<<std::endl;*/
        }

        return minPatch;
    }
};