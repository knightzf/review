My solution is very naive which uses lower_bound to look up nearest heaters for each house.\
In discussion, there's a better solution.\
The difficulty has been how to locate nearest two heaters quickly?\
The genious point is to use two indexes to go over the list of houses and heaters.\
So that it will be limited look up and we don't need to search it over and over again.
```C++
        int i = 0, j = 0, res = 0;
        while (i < houses.length) {
            while (j < heaters.length - 1
                && Math.abs(heaters[j + 1] - houses[i]) <= Math.abs(heaters[j] - houses[i])) {
                j++;
            }
            res = Math.max(res, Math.abs(heaters[j] - houses[i]));
            i++;
        }
```
