My solution is very slow because it's a recursive call.\
In discussion there's a very smart algo basically it finds next number by checking a few things:
* If x * 10 <= n, x = x * 10
* If x last digit != 9 and x + 1 <=n, x = x + 1
* Remove all 9s from right of the number, then add 1.

Algorithm is here https://leetcode.com/problems/lexicographical-numbers/discuss/86242/Java-O(n)-time-O(1)-space-iterative-solution-130ms
