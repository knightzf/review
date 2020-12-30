My solution uses a multiset and then go throug the numbers and find rest of number by using some properties of the map which is slightly improved than the brute force way.

The learned solution uses left and right indices and if the sum if less than target, we know there are right - left triplets that satisfies the request.

6/19\
Took some thoughts and figured out.

12/29/20\
The learned sol has a bug, it should be `res += right - left;`
