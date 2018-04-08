It apperas impossible at beginning.\
The learned solution uses a LRU like algo but this time uses a vector instead of list.\
The trick is in the remove, because we store vector index in the map, we need to remove the value from vector\
without affecting other elements.\
The solution is to swap with the end element and remove the end.

Very smart!
