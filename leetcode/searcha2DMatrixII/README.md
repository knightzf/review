My solution only beats 12% even though I used binary search.

There's much better solution in the discussion.

Start from top right of matrix, if target is larger than the value, means it can't be on this row, if target is smaller than this alue, means it can't be in this column.

So each time it eliminates one row or one column, thus O(m + n)
