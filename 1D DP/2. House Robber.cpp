/*
Questions: House Robber – Maximize the total amount stolen without robbing two adjacent houses.

Approach:
At each index, choose whether to rob the current house (and skip the next one) or skip it and move to the next house. Use recursion with memoization to store results per index and avoid recomputation. Return the maximum amount achievable starting from index 0.

Time Complexity: O(n)
Space Complexity: O(n) (for dp array and recursion stack)
*/

class Solution {
public:
    int solve(int idx, vector<int> &nums, vector<int> &dp) {
        if(idx >= nums.size()) {
            return 0;
        }

        if(dp[idx] != -1) {
            return dp[idx];
        }

        int pick = nums[idx] + solve(idx+2, nums, dp);
        int nonPick = solve(idx+1, nums, dp);

        return dp[idx] = max(pick, nonPick);
    }

    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return solve(0, nums, dp);
    }
};
