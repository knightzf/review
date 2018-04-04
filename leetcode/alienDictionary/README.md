This is a problem that demonstrates the way to think of a problem is the most important, otherwise you are trying to solve a much harder question.

My attempt is straightfoward, it's easy to find single letter relationship and my problem is how to store this relationship so that it can link to a chain and also how to find out if there's a new relationship that break the chain.

I thought for very long time and tried, failed badly.

The learned solution is much smarter as it converts the problem into a similar problem and used similar approach.

It defines a degree of words, basically if a > b, then degree of a is increased by 1.

This is the key point here as we start from any letter that has degree of 0, find those that are larger than it, reduce their degree by 1.

Keep doing this and keep picking the remaining letters with degree 0.

How do we know if there's contradictions?

Thoese with degrees that can never be 0.

For example, suppose a < b and b < a, they both have degree 1. And there's no chance to reduce it.

It's very similar to the lexicographical order problem solution.

4/3\
Saw this problem again, still got to the same issue.\
Easy to find pair relations, but hard to trace the chain.\
The idea of having a degree is key.
