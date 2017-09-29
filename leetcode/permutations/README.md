It took me a while to implement permutation because it's something I've never done before.

What is permutation? It's a nested loop by instinct. However we don't know the size of array thus can't just write multiple loops.

Recursion is the natual choice.

So we start from first element and try to arrange rest elements.

For each recursion call, we are left with one less element to use. How to know which elements are left to use?

Natually I think of a set to keep track of used indices, which works but involves a lot of copies.

After looking at the discussion and talking to Sheng, I know understand it much better.

Instead of using a set to keep track of used indices, swapping used elements to the beginning is a much more efficient way of doing the recursion and it's concise to write.
