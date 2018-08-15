Thought for a long time, tried to find dp relationship but the difficulty is in the multiple possible states at\
each operation given previous states.\

Finally pulled off using a greedy solution.\
My thought was correct at beginning, it should start at some point then do select, copy, paste as much as possible,\
then only do paste.\
But originally I didn't realized I should start from recursive call return values, which I had to write a dummy\
program to check the states.

