Recap:\
1. First thought of brute force, no way\
2. Then thought about finding a mathematical solution, couldn't find a good one.\
3. I then found the max k is n - 1 but we need to know the minimum k.\
4. The difficulty was there's 2 uncertainties, k and length of k-based number.\
5. The solution solves the problem in a way that is easy to understand but not obvious.\
6. Given the max number, we can use long long to represent.\
7. We need to find smallest k, which is also the time the length is largest.\
8. If we know the length, how to find k?\
9. It turns out we can do binary search from 2 to n - 1 for given length.\
10. What's the max length? 60 by a simple calculation.\
11. This is the blind spot in my process.
