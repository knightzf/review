At first glance, rectangle' area is of point a to point b is the min height of all points times the span.

However it's very inefficient to calculate all possible rectangles.

A better idea will be, given any point, find the rectangle area that has the height of this point's height.

For each point, look at left and right to find respective first point which has lower height than current point because points lower than current will not in the rectangle we look for.

The solution is a very genious idea from the idea above.

Loop through the list of points, push index to stack if the points are equal or ascending.

If we see a point that is smaller than top stack element it points to, as discussed above, smaller points will not be included in areas of higher heights.

So we pop elements from stack, calculate area of respective height. There's some subtle tricks to make it work which are hard to see.
