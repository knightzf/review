My two attemps both fail on time limit.\
Their ideas are similar by checking the total area and if two rectangles overlap each other.

The learned solution is much better in that it's an O(N) solution, mine's best at O(N^2).\
The idea is same in counting total area, but the key is how to check overlap.\
It saves all 4 corners of each rectangle, if they would combine into a perfect rectangle, all corner points should appear even times except four corners of the final rectangle.

It is one of the questions that you can solve by normal thinking but slow,\
or you can find the actual meaning of the requirement and make it really simple.

Again, practice doesn't increase IQ.
