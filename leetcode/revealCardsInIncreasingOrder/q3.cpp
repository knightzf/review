#include "header.h"

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        deque<int> q;

        for(auto iter = deck.rbegin(); iter != deck.rend(); ++iter)
        {
            int t = *iter;
            if(!q.empty())            
            {
                int b = q.back();
                q.pop_back();
                q.push_front(b);                
            }

            q.push_front(t);
        }

        vector<int> res(q.begin(), q.end());
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> a{17,13,11,2,3,5,7};
    const auto r = s.deckRevealedIncreasing(a);
    for(int i : r)
        cout<<i<<" ";
    cout<<endl;
}

