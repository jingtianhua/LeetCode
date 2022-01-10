/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 */

// @lc code=start
class Solution {
public:
    int candy(vector<int>& ratings) {
        auto const &ratingsSize = ratings.size();
        if (ratingsSize < 2) {
            return ratingsSize;
        }
        vector<int> candies(ratingsSize, 1);
        for (size_t i = 0; i < ratingsSize - 1; i++) {
            if (ratings[i] < ratings[i + 1]) {
                candies[i + 1] = candies[i] + 1;   
            }
        }
        int candiesTotal = 0;
        for (size_t i = ratingsSize - 1; i > 0; i--) {
            candiesTotal += candies[i]; 
            if (ratings[i - 1] > ratings[i]
                && candies[i - 1] <= candies[i]) {
                candies[i - 1] =  candies[i] + 1;
            }
        }
        candiesTotal += candies[0];
        return candiesTotal;
    }
};
// @lc code=end

