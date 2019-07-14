I thought for a long time and came up with an ugly solution.\
The learned solution from discussion is basically same idea, the only diff is when we see a negative number,\
we want to find index for x - 1, or any x - y where y > 1, however x - 1 should happen before any x - y since\
we have to get to x - 1 before getting x - 2, x - 3 and etc.

```C++
    int longestWPI(vector<int>& hours) {
        int res = 0, score = 0, n = hours.size();
        unordered_map<int, int> seen = {{0, -1}};
        for (int i = 0; i < n; ++i) {
            score += hours[i] > 8 ? 1 : -1;
            if (score > 0) {
                res = i + 1;
            } else {
                if (seen.find(score) == seen.end())
                    seen[score] = i;
                if (seen.find(score - 1) != seen.end())
                    res = max(res, i - seen[score - 1]);
            }
        }
        return res;
    }
```