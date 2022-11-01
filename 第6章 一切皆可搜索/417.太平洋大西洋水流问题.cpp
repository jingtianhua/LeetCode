/*
 * @lc app=leetcode.cn id=417 lang=cpp
 *
 * [417] 太平洋大西洋水流问题
 */
#include<vector>
// @lc code=start
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int size = heights.size();
        vector<vector<int>> visited(size, vector<int> (size));
        
        //从上面进行dfs

        return visited;
    }

private:
    vector<int> derection{-1, 0, 1, 0, -1};
    vector<int> location{0, 1, 2, 3, 4};

private:
    void dfs() {
        
    }
};
// @lc code=end

