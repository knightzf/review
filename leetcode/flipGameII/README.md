This problem is tricky, not because the problem itself is hard, rather it's because the recursion function definition is tricky.

In my understanding, if one is definitely going to win, doesn't mean he's going to win no matter how he plays; it actually means the rival will lose no matter how hard he tries.

My original thoughts is to use player id and always check when there's no choice, which player id it is.

However as Sheng pointed out, it should not be thought like this.

For recursion problem, you only thin one step and for this particular problem, you need to think it as two players.

One is going to win means the other exhausts all possible play and still loses.

Because we are going to loop through all possible plays at each recursion, it will definitely include the optimal play.

So the problem is actually competing against optimal plays in the call stack.

One is going to win and the other is going to lose on all optimal plays are complementary.

It is a very important concept in statistics because unless your definition is very accurate you are not going to get correct answer.
