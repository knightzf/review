Without too much thinking, this question is nothing worth talking about.\
However brute force search substring is very inefficient, thus I learned the KMP algorithm.\
Which took me very long time, plus in discussion somebody wrote very concise and hard to understand code.

The idea of KMP is to build a prefix table, where each value means longest common true prefix and postfix length.\
Remember we are looking at prefix which always starts from index 0 and posfix which ends at index i,\
we don't need to actually compare substrings, we only need to compare last character of prefix and posfix\ substring to see if we can find a longer common substring length, otherwise we check if we can match shorter\
substring by using the prefix table.

The lookup is then very similar, when we have a mismatch, we check from which index of the pattern we should\
start to compare, thus reducing number of comparisons.