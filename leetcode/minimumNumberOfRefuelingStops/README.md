I couldn't figure out a good solution in an hour.\
I feel more and more important that solving algo problems is more about change the way you see the problem.

My first reaction: dfs is not going to work given the input size.\
Then I tried to find a recursive solution which will break the problem into subproblems.\
However I got stuck with the problem that fuel tank could have different value at station i depends on the path.\
Then I tried bfs using a queue which timed out with little surprise.

Looked at other people's solution, it's using a priority queue.\
The key is not about priority queue, but about how you see the problem.\
The key idea is fuel can be added which can then be seen as maximum distance the car can travel.\
So at start, it look at all stations it can reach and push the station's fuels into a priority queue.\
Then at each step, we only need to try to refuel at the station with most fuel, thus extending possible distance.\
In this case, we always try to fuel at the most fuel station, and it will surely reach destination as quickly as possible.
