Almost gave up before I figured out the solution. Happy about it!

From the beginning, there was no brute force solution, it's impossible to write them down and count.\
So there must be a way to calculate this result.

It was easy to know at most how many reverse pairs can one number create, but we want total pairs of k, how to allocate the numbers?\
It took me long time to think about the allocation strategy as it feels impossible to allocation from smallest number.\
I then thought about range, there must be a range of numbers that produces the pairs and rest numbers must be in order.

Finally I realized I can start from the end and there's a perfect sub problem after trying all possible pairs from largest number.\
So it's a top down dp problem which is a little hard to think about.

Looked at discussion, realized it's possible to do bottom up approach.\
Created a slightly improved version.

Then I tried to further improve this solution by suming up counts of each row.\
There's case where it only takes a sum of sub array from previous row in the dp array, which involves substraction.\
Due to the nature of mod, the subtraction may generate negative value, thus it need to add the mod number before subtraction.\
This part is quite tricky and had me spent a lot of time.

Very happy about the whole process and did trained myself in various parts of algorithm programming.

