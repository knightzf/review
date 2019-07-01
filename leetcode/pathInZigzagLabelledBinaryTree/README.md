Without zigzag, we can always find label/2 as previous node.\
With zigzag, tt's a little tricky to determine the label.\
Given we know what the label for non-zigzag, we only need to find the mirror number.\
Which for a given range, is defined by left + right - label.\
This is because x + label = left + right due to the mirrorness.