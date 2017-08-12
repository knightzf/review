This question is a mental exercise on logical reasoning.

The core idea is to think of the question of find i, j in array A and B, so that 

    1. A[i-i] <= B[j] and B[j-1] <= A[i]

    2. element count of A[0] to A[i-1] plus B[0] to B[j-1] is equal to element count of A[i] to A[m-1] plus B[j] to B[n-1]

    3. From 2, the equatio is

        i + j = m -i + n - j

        so that

        j = (m + n + 1)/2 - i

        Adding 1 here in case m+n is odd, if m+n is even, then j is still the same result because of integer dividing 2 is still integer.

    4. Make sure m <= n, to ensure the range of j is larger than 0.

    5. Now loop i in the range of [0, m], using a binary search.

    6. The binary search and condition check is a little tricky but not the end of day.

The link to the full explain is https://discuss.leetcode.com/topic/4996/share-my-o-log-min-m-n-solution-with-explanation
