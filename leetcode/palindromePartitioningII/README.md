My solutions all timed out, I think it's due to the fact that the checking of substrings taking too much time.

The learned solution is a dp method using this fact that if

s[j] == s[i] and palinGrid[i + 1][j - 1] is true, palinGrid[i][j] is also true

and

minCutV[j + 1] is the min of its original value and minCutV[i] + 1

Besides minCutV is initialized to the max possible cuts that cut the string into individual letters which are palindromes

why minCutV[0] needs to be -1? Because we always add + 1 in the dp formula


This requires a lot of thinking which I found to be rather hard to comprehend and truely learned
