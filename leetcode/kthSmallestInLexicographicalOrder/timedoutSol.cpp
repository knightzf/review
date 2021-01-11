class Solution {
public:
    int findKthNumber(int n, int k) {
        stack<int> s;
        int count = 1, res = 1;
        bool canGoDown = true;
        s.push(1);
        while(count < k) {
            //cout<<s.top()<<endl;
            int curr = s.top();
            if(canGoDown && curr * 10 <= n) {
                ++count;
                res = curr * 10;
                s.push(curr * 10);                
            }
            else if(curr % 10 != 9 && curr + 1 <= n) {
                ++count;
                s.pop();
                res = curr + 1;
                s.push(curr + 1);
                canGoDown = true;
            } else {
                s.pop();
                canGoDown = false;
            }
        }
        return res;
    }
};
