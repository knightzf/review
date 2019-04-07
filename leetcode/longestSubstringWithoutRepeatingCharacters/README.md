Learned solution is better than mine in the sense that it doesn't need to slide start index one by one.\
Rather if we hit a char that is left of the current substring, it's OK because the start index will comapre\
with the index left of range, and do nothing, really brilliant!
https://leetcode.com/problems/longest-substring-without-repeating-characters/discuss/1729/11-line-simple-Java-solution-O(n)-with-explanation

However from an interview point of view, using a set and keep track of sliding window is more straight forward.