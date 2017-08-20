I spent at least 1 full day's time on this problem, shame on me if you will.

My initial thoughts are in the myincompletesolution.cpp, which first breaks regex into a vector of smaller units of different types and go through the string to match.

For simple cases it's easy to handle such as when the regex is just text string or dot.

However when I try to write the case when the regex is format of "a*", it starts to complicate that it need to know the regex after itself to see how agressive the match should be (e.g. regex is a*aa. and string is aaaaaa)

It wasn't long before I found out you sometimes even need to know the regex after next regex to determine the matching agreesiveness (e.g. regex is a*a.aa*a. and string is aaaaaa)

It becomes obvious that linear search hardly does any good and I haven't even started the .* case for which the aggressiveness of matching feels even a large problem.

Then I looked at the solutions provided by other people. It tackles the problem using a dp algorithm, basically it checks the current matching result by checking on a few conditions and previous matching results. It's much easier to think of different cases as there are only a few. This means even if s.subtr(0, i -1) doesn't match p.substr(0, j - 1), s.subtr(0, i -1) could match p.substr(0, j). For example s is ab and p is abc*, when look at ab and abc, they don't match but ab can be matched to abc*.

The heart of the dp solution is to define the initial states, why match[0][0] is true I haven't figured out but that's the only really prerequisite of the solution.
