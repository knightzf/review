#include "header.h"

using List = list<pair<list<int>::iterator, int>>;

class FreqStack {
    unordered_map<int, int> numCnt;
    map<int, unordered_map<int, List*>> cntListMap;
    list<int> s;
    int id = 0;
public:
    FreqStack() {
        
    }
    
    void push(int x) {
        auto iter = s.insert(s.end(), x);
        ++numCnt[x];
        List* lst;
        if(numCnt[x] == 1)
        {
            lst = new List();            
        }
        else
        {
            lst = cntListMap[numCnt[x] - 1][x];
            cntListMap[numCnt[x] - 1].erase(x);
            if(cntListMap[numCnt[x] - 1].empty()) cntListMap.erase(numCnt[x] - 1);
        }
        lst->push_back(make_pair(iter, ++id));
        cntListMap[numCnt[x]][x] = lst;
    }
    
    int pop() {
        int cnt = cntListMap.rbegin()->first;
        auto iter = cntListMap.rbegin();
        int lastId = iter->second.begin()->second->rbegin()->second;
        int num = iter->second.begin()->first;
        for(auto& p : iter->second)
        {
            if(p.second->rbegin()->second > lastId)
            {
                lastId = p.second->rbegin()->second;
                num = p.first;
            }
        }

        List* lst = cntListMap[cnt][num];
        s.erase(lst->rbegin()->first);
        --numCnt[num];
        lst->pop_back();
        cntListMap[cnt].erase(num);
        if(cntListMap[cnt].empty()) cntListMap.erase(cnt);
        if(cnt > 1)
        {
            cntListMap[cnt - 1][num] = lst;
        }
        else
        {
            delete lst;
        }
        return num;
    }
};

int main()
{
    //Solution s;
    FreqStack s;
    s.push(5);
    s.push(7);
    s.push(5);
    s.push(7);
    s.push(4);
    s.push(5);
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
}
