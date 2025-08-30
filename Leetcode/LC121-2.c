int max(int a, int b) {
    return (a > b) ? a:b;
}

int maxProfit(int* prices, int pricesSize) {
    if (pricesSize == 1) return 0;
    int sellPrice = prices[pricesSize - 1];
    int profit = 0;

    for (int i = pricesSize - 2; i >= 0; i--) {
        if (sellPrice > prices[i]) {
            profit = max(profit, sellPrice - prices[i]);
            continue;
        }
        sellPrice = prices[i];
    }
    return profit;
}

/*
Time complexity:
    loop -- O(n) -> solution on extreme ends
    max(a, b) -- O(1)
    others -- O(1) (at least negligible, just overhead)

    Overall: O(n)

Space complexity:
    profit, sellPrice -- O(1)
    
    Overall: O(1)

Basic Proof: at the Cpp solution.
*/