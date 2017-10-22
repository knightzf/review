It's the first question of weekly contest and I spent the whole 90 minutes try to solve it but didn't.

The solution is from https://discuss.leetcode.com/topic/107998/most-consistent-ways-of-dealing-with-the-series-of-stock-problems

My own attemp was from the orignal best time to buy and sell stock without fee.

When there's no fee, the idea is much simpler, you simply buy low and sell high. With fee, it's much more trickier.

My solution couldn't pass one of the tests which has like 1000 prices, which is impossible to debug.

Looking at the dicussion above. It's now much more clear.

It is basically a dp problem. How to achieve max profit with fee, really depends on the input, there's no simple rule that says you should buy or sell.

The most important thing is for a given day, there are two states: you have stock or you don't.

1. If you have stock, you can

    1. Sell stock
    2. Do nothing

2. If you don't have stock, you can

    1. Buy stock
    2. Do nothing

Then we have two arrays storing profit for day i for two situations having stock or not.

The i to i + 1 logic is easy, but value depends on the other array because buy or sell changes the state.

The thing left is to define start condition.

For no stock case, it's simple, on day 0, the max profit is do thing which is 0.

For having stock case, on day 0, because it's impossible to know day -1. The only possibility is to buy stock on day 0, causing profit of -prices[0].
