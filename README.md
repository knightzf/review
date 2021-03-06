* divide and conquer
* dfs/bfs
* Dependency related problems
    * union find  
    * keep track of a set of elements with degree of 0, until the set is empty
* Think from end state and reverse to start state (e.g. remove -> add)
* Two player game, each player tries out all possible moves, in order to find maximum or minimum result depends on which side the player is.
* Sometimes we can extend the string by duplicating it or add a reversed version to the end.
* Typical toplogical sort
    * Get all items
    * Create indegree and outdegree maps
    * Find 0 outdegree items
    * Iteratively update the outdegree map by referring to indegree map and insert new free items
* knapsack problem or set cover problem, use dp for all problem space
* Great article about range problems
    * https://leetcode.com/problems/reverse-pairs/discuss/97268/General-principles-behind-problems-similar-to-%22Reverse-Pairs%22
* Solve rectangle problem by counting number of lines
* Convert array into increasing array using deque by poping out elements >= incoming element
* Bit operations
    * Negative number is get the opposite then + 1
    * i & -1 keeps last 1 bit
* Two ways to partition
    * One: result will have elements < condition first, >= condition rest. For duplicates, it will either contain all duplicates or none, such as 1 ~ 2 2 2 3. We'll need another partition that have element <= condition first, > condition reset. e.g. 1 2 2 2 ~ 3 in order to sort or find kth. 
    * Two: result will have elements <= conditions first, >= conditions rest, such as 2 1 1 ~ 2 2, so that first k elements will be the k elements if sorted
