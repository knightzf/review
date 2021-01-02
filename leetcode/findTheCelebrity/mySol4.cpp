// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    /**
     * @param n a party with n people
     * @return the celebrity's label or -1
     */
    int findCelebrity(int n) {
        int l = 0, r = n - 1;
        while(l < r) {
            if(knows(l, r)) ++l;
            else --r;
        }
        int candidate = r;
        for(int i = 0; i < n; ++i) {
            if(i != candidate && (!knows(i, candidate) || knows(candidate, i))) return -1;
        }
        return candidate;
    }
};
