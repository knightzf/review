Here's my thought process which I think its valuable to write down.\
1. First reaction: the optimal value every element should be converted to must be between min and max.\
2. Then I thought, could it be the middle value (without considering count of each element)? Then I found it's not true.\
3. Then I thought maybe we just go from min to max, increment 1 each time, which will require sorting first.\
4. Then I realized even though the size of array is limited, the range could be very large.\
5. Then I came to think of the optimal point, what property does it have?
* choose smaller number will result in larger sum of moves.
* choose larger number will also result in larger sum of moves.
* assume there's x numbers smaller than this value and n - x numvers equal or larger
* choose val - 1 will cause the sum to increase by n - 2x
* choose val + 1 will cause sum to increase by 2x - n
* since val is the optimal, n - 2x and 2x - n must be >= 0
* then we realize x should be n / 2, thus we are looking for the median
6. To find median, there's a few ways, but no O(N) solution, quick selection has average of O(N)
