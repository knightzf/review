My solution is slow due to the fact for a pair of points, I find the mid coordinates and then try to find if\
there's another pair of points that also has the same mid coordinates. Then I have to check they can actually\
form a rectangle by checking 3 points forms a 90 degree angle (otherwise they may be on the same line.)

The better way is to use mid coordinates and length between two points as key, then every two pairs with the same\
key is going to be able to form a rectangle (no need to check the 90 degree because length is part of the key.)