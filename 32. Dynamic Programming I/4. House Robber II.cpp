/*
Questions: House Robber II – Maximize money stolen from circular houses where adjacent houses cannot both be robbed.

Approach:
Since the first and last houses are adjacent due to circular arrangement, split the problem into two linear cases: rob from house 0 to n-2 and rob from house 1 to n-1. Solve both using the standard House Robber DP (skip adjacent), and return the maximum of the two.

Time Complexity: O(n)
*/

class Solution {
public:
    int solve(int idx, int n, vector<int> &nums, vector<int> &dp) {
        if(idx >= n) return 0;
        if(dp[idx] != -1) return dp[idx];

        int pick = nums[idx] + solve(idx+2, n, nums, dp);
        int nonPick = solve(idx+1, n, nums, dp);
        return dp[idx] = max(pick, nonPick);
    }

    int nonAdjacent(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return solve(0, n, nums, dp);
    }

    int houseRobber(vector<int>& money) {
        int n = money.size();
        if(n == 0) return 0;
        if(n == 1) return money[0];

        vector<int> a, b;
        for(int i = 0; i < n - 1; i++) a.push_back(money[i]);
        for(int i = 1; i < n; i++) b.push_back(money[i]);

        return max(nonAdjacent(a), nonAdjacent(b));
    }
};
