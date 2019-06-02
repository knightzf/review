I thought it was impossible to do everything O(1).\
The difficulty lies in how to know the second smallest number if we pop the smallest number.\
The solution is for incoming number <= current min, push current min before push the number.\
Essentially for each smallest number, it remembers the smallest number before itself.\
Genius!