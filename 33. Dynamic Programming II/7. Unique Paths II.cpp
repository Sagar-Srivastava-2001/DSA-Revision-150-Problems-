/*
Questions: Unique Paths II – Count the number of ways to reach the bottom-right cell when certain cells are blocked (marked as 1). Movement allowed only right or down.

Approach:
Use recursion with memoization. If a cell is blocked or out of bounds, return 0. If you reach the destination, return 1. From each valid cell, explore both possible moves (down and right) and store results in dp to avoid recalculation.

Time Complexity: O(m × n)

*/

class Solution {
public:
    int solve(int i, int j, int m, int n, vector<vector<int>> &matrix, vector<vector<int>> &dp) {
        if(i >= m || j >= n || matrix[i][j] == 1) return 0;
        if(i == m - 1 && j == n - 1) return 1;

        if(dp[i][j] != -1) return dp[i][j];

        int down = solve(i + 1, j, m, n, matrix, dp);
        int right = solve(i, j + 1, m, n, matrix, dp);

        return dp[i][j] = down + right;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));

        return solve(0, 0, m, n, matrix, dp);
    }
};


