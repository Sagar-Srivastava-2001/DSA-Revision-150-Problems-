/*
Questions: Frog Jump with K steps – Minimize energy required to reach the last step where frog can jump up to K steps ahead.

Approach:
Use recursion with memoization. From each step, try jumping to all possible next steps in range 1 to k and compute the energy cost (absolute height difference). Among all valid jumps, choose the minimum. Stop when you reach the last step.

Time Complexity: O(n × k)
*/

class Solution {
public:
    int solve(int idx, vector<int> &heights, int k, vector<int> &dp) {
        if(idx == heights.size() - 1) return 0;
        if(dp[idx] != -1) return dp[idx];

        int ans = INT_MAX;
        for(int j = 1; j <= k; j++) {
            if(idx + j < heights.size()) {
                int jump = abs(heights[idx + j] - heights[idx]) + solve(idx + j, heights, k, dp);
                ans = min(ans, jump);
            }
        }
        return dp[idx] = ans;
    }

    int frogJump(vector<int>& heights, int k) {
        vector<int> dp(heights.size(), -1);
        return solve(0, heights, k, dp);
    }
};
