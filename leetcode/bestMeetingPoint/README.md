My solution is pretty simple, just find min sum distance for two sorted arrays.\
There's better solution in how to find min sum distance in the discussion.\
The code looks like this

```java
private int getMin(List<Integer> list){
    int ret = 0;

    Collections.sort(list);

    int i = 0;
    int j = list.size() - 1;
    while(i < j){
        ret += list.get(j--) - list.get(i++);
    }

    return ret;
}
```

Why this that?\
It's easy to proof the point that gets min sum distance is somewhere in the range, anything out of the range is going to produce larger result.

If we look at the points in pairs, for a given pair, the optimal point is between the pair. The total distance is then the distance between the pair.

For any other pairs, the optimal point is also between them, anything out of the range will produce larger result.

For total sum of distance to be minimum, we want the optimal point to be between all pairs from two sides. Thus the code above.
