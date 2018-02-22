I tried a few different solutions, basically try out next possible value from two vectors, if they happen to be the same, throw it to next recursion.\
It works but times out. The inefficiency is probably due to recursion.

The learned solution, on the other hand, try to get max vector of size i and k - i from two vectors.\
Then merge into a result vector, which is compared with a temp max vector.

The merge is a little tricky in which one to pick when two vectors have same value, which is not too bad.

The hardest part is how to find size k max vector from a given vector.\
The idea is use vector liks a stack. For a new value, try to put it into left most position because we want to find max vector.\
But the key is you need to check if the rest of the vector is long enough to fill the remaining result vector.

