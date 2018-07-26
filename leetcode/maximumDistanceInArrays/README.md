First version is simple N^2 as the diff must be from elements on either side from two arrays.\
Improved version stores all side elements and find all diffs in the final map.

Actually in discussion there's better O(N) solution that loops through the arrays and keep track of min and max,\
while use current array's values to check distance to min/max.
