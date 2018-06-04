#include "header.h"

class Solution {
private:
    int res;
    int n;
    unordered_set<string> m;
public:
    int findMinStep(string board, string hand) {
        unordered_map<char, int> t;
        for(char c : board)
            ++t[c];

        string newHand;
        for(char c : hand)
        {
            if(t.find(c) != t.end())
            {
                newHand += c;
                ++t[c];
            }
        }

        for(const auto& p : t)
            if(p.second < 3) return -1;

        sort(newHand.begin(), newHand.end());
        n = newHand.size();
        res = INT_MAX;
        m.clear();
        m.insert(board);
        for(int i = 0; i < n; ++i)
        {
            if(i == 0 || (newHand[i] != newHand[i - 1]))
            {
                swap(newHand[0], newHand[i]);
                impl(board, newHand, 0, 0);
                swap(newHand[0], newHand[i]);
            }
        }
        return res == INT_MAX ? -1 : res;
    }

    void impl(const string& board, string& hand, int idx, int cnt)
    {
        if(cnt >= res) return;

        if(board.empty())
        {
            res = min(res, cnt);
            return;
        }

        if(idx == n) return;

        for(int i = 0; i <= board.size(); ++i)
        {
            //this assumption below is incorrect
            //example that it will fail "RRWWRRBBRR", "WB"
            //if((i > 0 && board[i - 1] == hand[idx]) || (i < board.size() - 1 && board[i + 1] == hand[idx]))
            {
                const string& newBoard = board.substr(0, i) + hand[idx] + board.substr(i);
                if(m.count(newBoard))
                    continue;

                const string& after = shrink(newBoard, i);
                m.insert(newBoard);

                for(int j = idx + 1; j <= n; ++j)
                {
                    swap(hand[idx + 1], hand[j]);
                    impl(after, hand, idx + 1, cnt + 1);
                    swap(hand[idx + 1], hand[j]);
                }
            }
        }
    }

    string shrink(const auto& board, int idx)
    {
        string t = board;
        while(idx >= 0 && idx < t.size())
        {
            int leftIdx = idx - 1;
            int rightIdx = idx + 1;
            while(leftIdx >= 0 && t[leftIdx] == t[idx]) --leftIdx;
            while(rightIdx < t.size() && t[rightIdx] == t[idx]) ++rightIdx;

            if(rightIdx - leftIdx - 1 >= 3)
            {
                t = t.substr(0, leftIdx + 1) + t.substr(rightIdx);
                idx = leftIdx;
            }
            else
            {
                break;
            }
        }
        return t;
    }
};

int main()
{
    Solution s;
    //cout<<s.findMinStep("GGRRGRRYY", "RYRBR")<<endl;
    //cout<<s.findMinStep("WRYYRWWRRWW", "WYBR")<<endl;
    //cout<<s.findMinStep("R", "RR")<<endl;
    //cout<<s.findMinStep("GGYYBRGGRYBYG", "RYYBG")<<endl;
    cout<<s.findMinStep("RRWWRRBBRR", "WB")<<endl;
}
