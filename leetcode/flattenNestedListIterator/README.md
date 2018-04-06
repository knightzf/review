Very good problem.

I was on the right direction that to use a stack and to keep the start and end iterator of parent lists.\
However the actualy logic to find if there's next is quite hard to write.\
I had duplicate logic in the constructor and the getNext() function.\
Also it doesn't handle empty list very well.\
Because empty list will require popping stack which I wrote as while loop inside while loop.\

The learned solution did it so well in that it handles the pair interator equal case very elegantly so that\
it's unnecessary to check if the list is empty and automatically keep going.\
In addition it puts the load of finding the next integer in the big while loop so that it eithe finds an integer or return false.

This is really great code, it's not that type of question that has an aha solution, \
rather it takes a lot of experience to come up with such a clean and easy code.
