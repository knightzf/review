My solution is straighforward but it can be done by bucket sorting.\
The idea is the h index can not be more than n given total n papers.\
So we first count number of papers in each bucket and then from end to beginning check where the count in bucket\
is >= the bucket id.