#include "header.h"

struct TrieNode
{
    TrieNode* children[27];
    unordered_map<int, int> idxHeatMap;
    int endStrIdx = -1;
};

class AutocompleteSystem {
private:
    vector<string> data;
    string inputStr;
    TrieNode* root;
    int dataIdx = 0;
    TrieNode* currNode;

public:
    AutocompleteSystem(vector<string> sentences, vector<int> times) {
        root = new TrieNode();
        for(int i = 0; i < sentences.size(); ++i)
        {
            add(sentences[i], times[i]);
        }
        currNode = root;
    }

    vector<string> input(char c) {
        vector<string> res;
        if(c == '#')
        {
            setHeat(currNode, inputStr);
            currNode = root;
            inputStr.clear();
        }
        else
        {
            inputStr += c;
            addChar(currNode, c);
            vector<pair<int, int>> v;
            for(const auto& p : currNode->idxHeatMap)
                v.emplace_back(p.first, p.second);
            sort(v.begin(), v.end(), [&](const pair<int, int>& a, const pair<int, int>& b){
                    if(a.second > b.second) return true;
                    else if(a.second == b.second){
                        return data[a.first] < data[b.first];
                    }
                    return false;
                });

            for(int i = 0; i < 3 && i < v.size(); ++i)
            {
                res.push_back(data[v[i].first]);
            }
        }
        return res;
    }

private:
    int idx(char c)
    {
        return c == ' ' ? 26 : (c - 'a');
    }

    void add(const std::string& str, int heat)
    {
        TrieNode* node = root;
        for(int i = 0; i < str.size(); ++i)
        {
            addChar(node, str[i]);
        }

        setHeat(node, str, heat);
    }

    void setHeat(TrieNode* currNode, const string& inputStr, int heat = 1)
    {
        int& correctIdx = currNode->endStrIdx;
        currNode = root;
        for(int i = 0; i < inputStr.size(); ++i)
        {
            int index = idx(inputStr[i]);
            auto* p = currNode->children[index];
            if(correctIdx != -1)
                p->idxHeatMap[correctIdx] += heat;
            else
                p->idxHeatMap.emplace(dataIdx, heat);
            currNode = p;
        }

        if(correctIdx == -1)
        {
            correctIdx = dataIdx;
            data.push_back(inputStr);
            ++dataIdx;
        }
    }

    void addChar(TrieNode*& node, char c)
    {
        int index = idx(c);
        if(node->children[index] == nullptr)
        {
            TrieNode* p = new TrieNode();
            node->children[index] = p;
        }

        node = node->children[index];
    }
};

int main()
{
    //Solution s;
    vector<string> a{"i love you", "island","ironman", "i love leetcode"};
    vector<int> b{5, 3, 2, 2};
    AutocompleteSystem s(a, b);
    {
        const auto& r = s.input('i');
        for(const auto& i : r) std::cout<<i<<std::endl;
    }
    {
        const auto& r = s.input(' ');
        for(const auto& i : r) std::cout<<i<<std::endl;
    }//*/

}
