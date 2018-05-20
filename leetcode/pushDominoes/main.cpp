#include "header.h"

class Solution {
public:
    string pushDominoes(const string& s) {
        string dominoes = s;
        int n = dominoes.size();
        for(int i = 0; i < n;)
        {
            if(dominoes[i] == 'R')
            {
                int j = i + 1;
                while(j < n && dominoes[j] != 'L' && dominoes[j] != 'R') ++j;
                if(j == n || dominoes[j] == 'R')
                {
                    for(int k = i; k < j; ++k)
                        dominoes[k] = 'R';
                }
                else
                {
                    int k = 1;
                    while(i + k < j - k)
                    {
                        dominoes[i + k] = 'R';
                        dominoes[j - k] = 'L';
                        ++k;
                    }
                }
                i = j;
            }
            else
            {
                ++i;
            }
        }

        for(int i = n - 1; i >= 0;)
        {
            if(dominoes[i] == 'L')
            {
                int j = i - 1;
                while(j >= 0 && dominoes[j] != 'L' && dominoes[j] != 'R') --j;
                if(j == -1 || dominoes[j] == 'L')
                {
                    for(int k = i; k > j; --k)
                        dominoes[k] = 'L';
                }
                else
                {
                    int k = 1;
                    while(i - k > j + k)
                    {
                        dominoes[i - k] = 'L';
                        dominoes[j + k] = 'R';
                        ++k;
                    }
                }
                i = j;
            }
            else
            {
                --i;
            }
        }
        return dominoes;
    }
};

int main()
{
    Solution s;
    cout<<s.pushDominoes(".L.R...LR..L..")<<endl;
    cout<<s.pushDominoes("RR.L")<<endl;
}
