/*
Questions: Coin Change – Given coin denominations, find the minimum number required to make a given amount. Return -1 if not possible.

Approach:
Use recursion with memoization. Try every coin that doesn't exceed the current amount, subtract it, and recursively compute the minimum coins needed. Store results to avoid recomputation. If no coin leads to a valid solution, return -1.

Time Complexity: O(amount × number_of_coins)
Space Complexity: O(amount) (for dp array and recursion stack)
*/

class Solution {
public:
    int solve(int amount, vector<int> &coins, vector<int> &dp) {
        if(amount == 0) return 0;
        if(amount < 0) return INT_MAX;

        if(dp[amount] != -1) return dp[amount];

        int ans = INT_MAX;
        for(auto coin : coins) {
            int res = solve(amount - coin, coins, dp);
            if(res != INT_MAX) {
                ans = min(ans, res + 1);
            }
        }
        return dp[amount] = ans;
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        int ans = solve(amount, coins, dp);
        return ans == INT_MAX ? -1 : ans;
    }
};
