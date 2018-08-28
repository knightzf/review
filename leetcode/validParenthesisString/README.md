So happy I did it!\
The brute force solution is to try all possibilities of \* and see if any of the resulting string is good.\
Then I thought maybe it's a dp solution, by checking if a given range is valid, which then seems to lead to\
counting open and close parenthesis.\
Then I realized I can just count parenthesis but need to take into account of stars.\
Then there's cases like ()))) so that the sum of count need to be <= 0 when counting from left.\
Then I realized same restriction applies when counting from right.\
Checked discussion, idea is same, they are using a even smarter solution which mantains a range by checking\
each character.