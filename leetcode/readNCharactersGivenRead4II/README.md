Similar to previous question, need to keep track of remaining data from last read

5/19\
Took me a while to understand the problem, this time I used a long buffer.\
There's more efficient way to use a 4 byte buffer and keep comparing if the\
required read is >= 4 to decide whether we read int result or the buffer.
