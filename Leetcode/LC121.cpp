class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 1) return 0;
        int buy_price = prices.front();
        int profit = 0;

        for (int i = 0; i < prices.size(); i++) {
            if (buy_price < prices.at(i)) {
                profit = max(profit, prices.at(i) - buy_price);
                continue;
            }
            buy_price = prices.at(i);
        }
        return profit;
    }
};

/*
Time complexity:
    O(n) -- look at the solution in C.
Space complexity:
    O(1) -- look at the solution in C.

Basic Proof that the solution works:
    Core idead: least buy price, max sell price.
    Task: track least buy price

    Algorithm:
        In every cycle, check if the element
        is smaller than buy_price. This helps
        us to ensure we're buying at the
        least price.

        Next, if it is not the case, then get
        the profit and update profit variable
        accordingly.

    Given an array [a1, a2, ..., an] and not
    all numbers are equal,
    there exists ai such that ai < aj for all j != i
    and there exists ak such that ak > aj for all j != k.

    Therefore, there exist intermediate values
    ax and ay, such that x != y and ay > ax and
    ay - ax > aj - ai for all j not in {i, y} and
    i not in {x, j}.

    The algorithm starts from larger number for buy price
    which eventually gets to minimum number.
    As it traverses all possible choices, the final
    profit is the max one of ay - ax.
*/