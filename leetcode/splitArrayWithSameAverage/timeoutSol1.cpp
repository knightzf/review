#include "header.h"

class Solution {
public:
    bool splitArraySameAverage(vector<int>& A) {
        if(A.empty()) return false;

        int totalSum = 0;
        int n = A.size();
        for(auto i : A) totalSum += i;

        return impl(0, 0, 0, A, totalSum, n);
    }

    bool impl(int sum, int cnt, int idx, vector<int>& A, int totalSum, int n)
    {
        if(cnt > n / 2) return false;
        if(m.find(std::make_pair(sum, cnt)) != m.end()) return false;
        //std::cout<<sum<<" "<<cnt<<" "<<idx<<std::endl;
        if(cnt > 0 && cnt < n && (totalSum * cnt) % n == 0 && totalSum * cnt / n == sum) return true;
        if(idx < n && (
                       impl(sum + A[idx], cnt + 1, idx + 1, A, totalSum, n) ||
                       impl(sum, cnt, idx + 1, A, totalSum, n)
                      )
          )
            return true;
        m.emplace(sum, cnt);
        return false;
    }
private:
    std::set<std::pair<int, int>> m;
};

int main()
{
    Solution s;
    //vector<int> a{1, 2, 3, 4, 5, 6, 7, 8};
    //vector<int> a{3, 1};
    //vector<int> a{17, 3, 7, 12, 1};
    //vector<int> a{12, 1, 17, 8, 2};
    //vector<int> a{72,56,81,54,15,96,80,90,8};
    //vector<int> a{84,44,32,42,26,26,87,65,12,95,68,41,6,72,8,15,66,55,71,79,6};
    //vector<int> a{33,86,88,78,21,76,19,20,88,76,10,25,37,97,58,89,65,59,98,57,50,30,58,5,61,72,23,6};
    vector<int> a{904,8738,6439,1889,138,5771,8899,5790,662,8402,3074,1844,5926,8720,7159,6793,7402,9466,1282,1748,434,842,22};
    //vector<int> a{3863,703,1799,327,3682,4330,3388,6187,5330,6572,938,6842,678,9837,8256,6886,2204,5262,6643,829,745,8755,3549,6627,1633,4290,7};
    std::cout<<s.splitArraySameAverage(a)<<std::endl;
}
