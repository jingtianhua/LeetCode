/*
 * @lc app=leetcode.cn id=695 lang=cpp
 *
 * [695] 岛屿的最大面积
 */
#include<vector>
// @lc code=start
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int max_area = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    max_area = max(max_area, dfs(grid, i, j));
                }
            }
        }
        return max_area;
    }

private:
    vector<int> derection{-1, 0, 1, 0, -1};

private:
    int dfs(vector<vector<int>>& grid, int r, int c) {
        if (grid[r][c] == 0) return 0;
        grid[r][c] = 0;
        int x, y, area = 1;
        for (int i = 0; i < 4; ++i) {
            x = r + derection[i], y = c + derection[i + 1];
            if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size()) {
                area += dfs(grid, x, y);
            }
        }
        return area;
    }
};

// @lc code=end

