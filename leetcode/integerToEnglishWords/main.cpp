#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <sstream>
#include <cmath>
#include <queue>
#include <map>
#include <list>
#include <string>
#include <cstdlib>
#include <cctype>
#include <stdexcept>
#include <climits>
#include <utility>
#include <bitset>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <memory>
#include <iterator>

using namespace std;

class Solution {
public:
    string numberToWords(int num) {
        std::string res;
        if(num >= 1000000000)
        {
            return numberToWords(num / 1000000000) + " Billion" +
                (num % 1000000000 ? " " + numberToWords(num % 1000000000) : "");
        }
        else if(num >= 1000000)
        {
            return numberToWords(num / 1000000) + " Million" +
                (num % 1000000 ? " " + numberToWords(num % 1000000) : "");
        }
        else if(num >= 1000)
        {
            return numberToWords(num / 1000) + " Thousand" +
                (num % 1000 ? " " + numberToWords(num % 1000) : "");
        }
        else if(num >= 100)
        {
            return numberToWords(num / 100) + " Hundred" +
                (num % 100 ? " " + numberToWords(num % 100) : "");
        }
        else if(num >= 90)
        {
            return "Ninety" + (num > 90 ? " " + numberToWords(num - 90) : "");
        }
        else if(num >= 80)
        {
            return "Eighty" + (num > 80 ? " " + numberToWords(num - 80) : "");
        }
        else if(num >= 70)
        {
            return "Seventy" + (num > 70 ? " " + numberToWords(num - 70) : "");
        }
        else if(num >= 60)
        {
            return "Sixty" + (num > 60 ? " " + numberToWords(num - 60) : "");
        }
        else if(num >= 50)
        {
            return "Fifty" + (num > 50 ? " " + numberToWords(num - 50) : "");
        }
        else if(num >= 40)
        {
            return "Forty" + (num > 40 ? " " + numberToWords(num - 40) : "");
        }
        else if(num >= 30)
        {
            return "Thirty" + (num > 30 ? " " + numberToWords(num - 30) : "");
        }
        else if(num >= 20)
        {
            return "Twenty" + (num > 20 ? " " + numberToWords(num - 20) : "");
        }
        else
        {
            switch(num)
            {
                case 19 : return "Nineteen";
                case 18 : return "Eighteen";
                case 17 : return "Seventeen";
                case 16 : return "Sixteen";
                case 15 : return "Fifteen";
                case 14 : return "Fourteen";
                case 13 : return "Thirteen";
                case 12 : return "Twelve";
                case 11 : return "Eleven";
                case 10 : return "Ten";
                case 9 : return "Nine";
                case 8 : return "Eight";
                case 7 : return "Seven";
                case 6 : return "Six";
                case 5 : return "Five";
                case 4 : return "Four";
                case 3 : return "Three";
                case 2 : return "Two";
                case 1 : return "One";
                case 0 : return "Zero";
                default: return "";
            }
        }
    }
};

int main() {
    Solution s;
    std::cout<<s.numberToWords(123)<<std::endl;
    std::cout<<s.numberToWords(12345)<<std::endl;
    std::cout<<s.numberToWords(1234567)<<std::endl;
}
