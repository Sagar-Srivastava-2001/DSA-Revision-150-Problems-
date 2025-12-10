/*
Questions: Minimum Falling Path Sum – Find the minimum sum path from any cell in the top row to any cell in the bottom row. From a cell, you can move down, down-left, or down-right.

Approach:
Use recursion with memoization. From each cell in the top row, explore all three valid downward directions and accumulate cost. If you step out of bounds, return a large number so it never gets chosen. Cache results in dp. The answer is the minimum among all paths starting from row 0.

Time Complexity: O(m × n)

*/

class Solution {
public:
    long long int solve(int i, int j, int m, int n, vector<vector<int>> &matrix, vector<vector<int>> &dp) {
        if(i < 0 || j < 0 || i >= m || j >= n) return INT_MAX;
        if(i == m - 1) return matrix[i][j];

        if(dp[i][j] != -1) return dp[i][j];

        long long down  = matrix[i][j] + solve(i + 1, j, m, n, matrix, dp);
        long long left  = matrix[i][j] + solve(i + 1, j - 1, m, n, matrix, dp);
        long long right = matrix[i][j] + solve(i + 1, j + 1, m, n, matrix, dp);

        return dp[i][j] = min({left, down, right});
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        long long ans = INT_MAX;
        vector<vector<int>> dp(m, vector<int>(n, -1));

        for(int j = 0; j < n; j++) {
            ans = min(ans, (long long) solve(0, j, m, n, matrix, dp));
        }

        return ans;
    }
};


