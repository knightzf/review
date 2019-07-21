Expanded the formula and get all possible cases.
```c++
(a1-b1) + (a2-b2) + (i-j)
(a1-b1) + (b2-a2) + (i-j)
(b1-a1) + (a2-b2) + (i-j)
(b1-a1) + (b2-a2) + (i-j)
```
Which can be rewritten as
```c++
(+a1+a2+i) - (+b1+b2+j)
(+a1-a2+i) - (+b1-b2+j)
(-a1+a2+i) - (-b1+b2+j)
(-a1-a2+i) - (-b1-b2+j)
```
Which means for each case, we only need to find the diff between max and min.