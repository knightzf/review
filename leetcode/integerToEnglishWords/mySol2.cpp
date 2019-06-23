#include "header.h"

class Solution {
public:
    string numberToWords(int num) {
        static map<int, string> m {
            {int(1e9), "Billion"}, {int(1e6), "Million"},
            {int(1e3), "Thousand"}, {int(1e2), "Hundred"},
            {90, "Ninety"}, {80, "Eighty"}, {70, "Seventy"},
            {60, "Sixty"}, {50, "Fifty"}, {40, "Forty"},
            {30, "Thirty"}, {20, "Twenty"}, {19, "Nineteen"},
            {18, "Eighteen"}, {17, "Seventeen"}, {16, "Sixteen"},
            {15, "Fifteen"}, {14, "Fourteen"}, {13, "Thirteen"},
            {12, "Twelve"}, {11, "Eleven"}, {10, "Ten"},
            {9, "Nine"}, {8, "Eight"}, {7, "Seven"},
            {6, "Six"}, {5, "Five"}, {4, "Four"},
            {3, "Three"}, {2, "Two"}, {1, "One"}, {0, "Zero"}
        };

        auto iter = m.upper_bound(num);
        --iter;
        int cnt = iter->first >= 100 ? num / iter->first : 1;
        int res = iter->first >= 100 ? num % iter->first : (num - iter->first);
        return (iter->first >= 100 ? numberToWords(cnt) + " " : "")
            + iter->second + (res ? " " + numberToWords(res) : "");       
    }
};

int main()
{
    //Solution s;
}