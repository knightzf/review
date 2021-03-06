Problems worth revisiting:
* #### 4 binary search, need to know the range of i is [0, m] instead of [0, m - 1]
* 5
* 10
* #### 11 from two sides to middle
* #### 15 also two side to middle
* 22
* 25
* #### 28 kmp is tricky to get right
* 30
* 31
* 33
* 34
* 37
* 44
* 48
* 55
* 68
* 69
* 71
* 72
* 75
* 81
* 92
* 98
* 99 Tricky in locating the two nodes, choose first one or second?
* 111 Easy but also easy to get wrong
* #### 117 level traversal algo
* 122  
* #### 128 my solution isn't optimal
* #### 145 do preorder and reverse or use a flag for each node state, good to know [two stack solution](https://leetcode.com/problems/binary-tree-postorder-traversal/discuss/45648/three-ways-of-iterative-postorder-traversing-easy-explanation)
* #### 148 merge sort, trick in how to find middle and use dummy head 
* 153 if need to compare right half of binary search, need to use h = n - 1
* 154
* #### 155 a bit tricky, only need one stack
* 161
* 162
* #### 168 tricky in terms of the 26-nary number doesn't contain 0
* #### 179 need to sort properly and corner case
* #### 188 classic buy/sell stock problem
* 198 dp definition doesn't require it rob nums[i]
* 207
* 208
* 212 use trie and dfs
* 215 binary search with partition
* #### 220 bucket sorting to get O(N) while maintain windows size <=k, smart
* #### 221 can be done in one loop using dp
* 222 check depth of left most and right most see if they equal
* 238 multiply from left to right and right to left
* #### 239 deque or monoqueue(hard to get right)
* 240
* 259
* #### 260 bit operation, i & -i gives last 1 bit. only one number has 1 at here.
* #### 261 dfs or union find
* 269
* 275 binary search always a little tricky
* #### 277 one pass to find candidate by only checking larger ids
* #### 281 use iterator pair is very smart
* #### 282 dfs but learned solution is very elegant
* #### 287 two pointer solution hard to understand
* #### 296 the solution needs to find the essense of the problem
* #### 300 dp is natual to get, increasing minimal tail size solution is hard to understand
* #### 301 dfs but hard to write
* #### 307 segment tree
* #### 308 2d binary indexed tree
* #### 310 bfs from leaves until it reaches the middle node/s
* 314 can do bfs from root
* #### 315 binary search tree or merge sort
* #### 316 idea is simple, need to think of actual complexity
* 322 performance between vector and unordered_map is huge
* #### 324 nth_element is easy to think about, rearrange indx is really hard 
* 326 not much, a little tricky
* #### 327 segment tree or merge sort solution (think of the prob differently)
* #### 336 tricky, find rest of string instead of concat
* 337 point is how to define the problem
* #### 341 elegant code with pair of iterators
* 347 nth_element or bucket sort
* 348 easy O(n) but can keep count in each row/col(use 1 for p1 and -1 for p2)
* #### 358 priority queue (need to handle unsolvable case) or seemingly dumb algo but actually works
* #### 371 bit oper very smart (a & b << 1 is the carry value)
* 377 medium, thought for a while
* 378 merge n sorted arrays or binary search
* #### 380 very brilliant solution
* 394 use stack isn't too bad
* #### 395 sliding window * 26 or divide and conquer
* 399 dfs
* #### 402 should use stack and pop out number > current number
* #### 407 priority queue solution is hard to think of
* 410 dp is slow, binary search is a great idea
* #### 416 knapsack problem
* 426 inorder
* 430 not difficult, but hard to get it all correct
* #### 432 hard to think of the data structure
* #### 435 greedy solution is hard
* #### 437 record accumulative sum, not all possible sum values
* #### 440 treat is like a tree, but quite hard to understand
* 445 easy, but can use a stack
* #### 446 n^2 but hard to model the problem beautifully
* 448 easy but there's a great way to do it
* 450 hard to find a elegant recursive sol (the essense of recursion)
* #### 478 math prob
* #### 491 smart way to avoid using set 
* #### 494 great way to convert the prob and how to avoid duplicates using same dp array during iteration
* 496 use stack
* #### 518 knapsack mind the difference from 494 (unlimited vs binary)
* #### 535 base62 encode number to 6 digit string (similar to decimal to binary conversion)
* 554 no need for merge sort, just count most common brick ending index
* #### 564 prefix to number and add [-1, 0, 1] as possible results
* 593 great thinking
* #### 621 after tasks with maxcnt, rest fit in empty or append to each section
* #### 652 need the correct traversal
* #### 654 iterative sol is brilliant
* 673 tried to avoid n^2 but there's no better sol
* #### 686 kmp 
* #### 687 tricky to differ total length and longer length, brilliang sol
* #### 689 fix mid section and get max from left and right, idx tricky to get right
* #### 691 dfs but hard to have elegant impl, the optimization is tricky
* 692 simple priority queue
* #### 699 it can be better than N^2, but need to be careful dealing with edge cases
* 713 took me a while to find this is a sliding window prob
* 750 solve rectangle problem by counting number of lines
* 764 simple problem 
* #### 766 simple yet clever sol
* #### 801 similar to buy sell stock
* #### 862 store index instead of value and the deque solution is so smart
* 863 can build a graph and do bfs, which is cleaner than my sol
* #### 886 actually dfs/bfs prob
* #### 889 great way to construct tree from array
* #### 918 simple problem, great solution or similar to 862
* #### 958 bfs is easy but in order is tricky to write elegant
* #### 968 dfs with mem works but the greedy sol is much better 
* #### 1008 actually direct insertion works however there's greedy sol (but how to prove?)
