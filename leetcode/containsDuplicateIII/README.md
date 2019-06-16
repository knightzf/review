6/19\
My solution is still log(N) complexity as it's a rolling window and we need to know if numbers within the range\
exists, which requires two look up and even worse a distance between two iterators.

I couldn't figure out the bucketing solution as no matter how large the bucket size is, the numbers may be in two\
neighboring buckets. The learned solution geniously solved the issue by checking the neighboring bucket element,\
which seems simple when look back but really hard to come by.