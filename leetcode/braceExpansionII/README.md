I found this problem hard to do, it's very similar to the calculator but actually different.\
We can try to do the same by using a carry but given we only need unique values, subtraction is hard\
as we may remove expressions that we need.

The key idea is to use a list of sets instead of a single set so that when it's a union, we'll have a list of\
sets, which can then be unioned later; otherwise we'll always multiple current expression with last element in\
the list.