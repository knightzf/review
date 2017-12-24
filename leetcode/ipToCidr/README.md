The problem really got me in a unfamiliar place.

I first tried to break ip into 4 ints and increase the vector of ints, turns out to be really hard.

Then I looked at other people's solution, the idea is to convert ip into one number and try to 2 to the power of n each time to the ip.

It becomes much easier as we can easily know how many zeros on the right size of each number.

We only need to increase ip number each time and decrease range each time.

Also I should replace the pow() function with << operator. Again binary problems are really new to me.
