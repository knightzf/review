Awkward way to do this problem, a litle trick to increase nums1 size after merging from nums2.

5/19\
It feels awkward, as insertion from left will need to insert into vector which\
is really bad.\
Figured out another solution by using the std::rotate() function to move 0's\
to the beginning.\
Checked discussion, the better idea is to fill from the right, so simple and so\
smart!
