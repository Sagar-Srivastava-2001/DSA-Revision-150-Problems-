/*
Questions: Climbing Stairs – Count number of distinct ways to reach the top when you can climb 1 or 2 steps at a time.

Approach:
Use recursion with memoization to avoid redundant calculations. At each index, either move 1 step or 2 steps forward and sum the total ways to reach exactly step n. Base case: if index equals n, return 1 (valid way); if index exceeds n, return 0.

Time Complexity: O(n) (each state computed once due to memoization)
Space Complexity: O(n) (for dp array and recursion stack)
*/

class Solution {
public:
    int solve(int idx, int n, vector<int> &dp) {
        if(idx > n) {
            return 0;
        }

        if(idx == n) {
            return 1;
        }

        if(dp[idx] != -1) {
            return dp[idx];
        }

        return dp[idx] = solve(idx+1, n, dp) + solve(idx+2, n, dp);
    }

    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return solve(0, n, dp);
    }
};
