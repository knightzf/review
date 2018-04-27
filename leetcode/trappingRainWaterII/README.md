Great learing experience!\
I don't remember the solution to the 1d problem so had little idea of this problem.\
My original thought was to try to pour water at each position and see where the water will flow to.\
If it flows to boarder, meaning it can't hold water; else keep doing it.\
The idea is simple yet inefficient but also non-trivial to write.

The learned solution uses a priority queue so that we always check the lowest point.\
If neighor is no lower than this point, no water can be added.\
Otherwise add water so that it will be flat with current point.\
Why this works?\
* For points evetually connects to borader, they need to have same height so water won't hold, using above method will pick them out because we always pick the next lowest point.
* For other points that can hold water, they will add enough water to be flat with its neighbor.
* Can the above case need to add more water later? No, because one point can hold water as high as its lowest neighbor and becauwe we start from boarders to center so if boarder is low, center can't be higher than immediate boarders.
