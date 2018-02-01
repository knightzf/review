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
    string alienOrder(vector<string>& words) {
        std::unordered_map<char, int> order;
        //if(!buildRelation(words, order)) return "";

        std::cout<<buildRelation(words, order)<<std::endl;

        std::cout<<"---ordering--"<<std::endl;
        for(auto& p : order)
        {
            std::cout<<p.first<<" "<<p.second<<std::endl;
        }

        return "";
    }

    bool buildRelation(vector<string>& words, std::unordered_map<char, int>& order)
    {
        char last = 0;
        int n = words.size();
        std::cout<<"--incoming--"<<std::endl;
        for(int i = 0; i < n; ++i)
        {
            std::cout<<words[i]<<" ";
        }
        std::cout<<std::endl;
        std::vector<string> subwords;
        for(int i = 0; i < n; ++i)
        {
            char c = words[i][0];
            std::cout<<"word "<<words[i]<<std::endl;

            if(c != last && last != 0)
            {
                std::cout<<"-add "<<words[i]<<" "<<c<<" "<<last<<std::endl;
                if(order.find(c) != order.end() && order.find(last) != order.end())
                {
                    if(order[c] < order[last]) return false;
                    if(order[c] == order[last])
                    {
                        int weight = order[last];
                        for(auto& p : order)
                        {
                            if(p.second > order[last])
                            {
                                if(p.second < weight)
                                {
                                    weight = p.second;
                                }
                            }
                        }

                        order[c] = weight == order[last] ? weight + 1 : weight;
                    }

                    if(order[c] > order[last]) continue;
                }
                else if(order.find(c) != order.end())
                {
                    order[last] = order[c] - 1;
                }
                else if(order.find(last) != order.end())
                {
                    order[c] = order[last] + 1;
                }
                else
                {
                    order[last] = 0;
                    order[c] = 1;
                }

                if(subwords.size() > 1 && !buildRelation(subwords, order)) return false;
                subwords.clear();

                if(words[i].size() > 1) subwords.push_back(words[i].substr(1));
            }
            else if(i == n - 1)
            {
                if(words[i].size() > 1) subwords.push_back(words[i].substr(1));
                if(subwords.size() > 1 && !buildRelation(subwords, order)) return false;
            }
            else
            {
                if(words[i].size() > 1) subwords.push_back(words[i].substr(1));
            }


            last = c;
        }

        return true;
    }
};

int main() {
    Solution s;
    vector<string> a{"wrt","wrf","er","ett","rftt"};
    s.alienOrder(a);
}
