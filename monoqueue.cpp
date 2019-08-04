#include <deque>
#include <utility>

using namespace std;

class Monoqueue {
    public:
        int max() {
            return q.front().first;
        }

        void push(int val) {
            int cnt = 0;
            while(!q.empty() && val > q.back().first) {
                cnt += q.back().second + 1;
                q.pop_back();
            }
            q.push_back({val, cnt});
        }

        void pop() {
            if(q.front().second--) return;
            q.pop_front();
        }
    private:
        deque<pair<int, int>> q;
};
