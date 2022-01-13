/*
 * @lc app=leetcode.cn id=633 lang=cpp
 *
 * [633] 平方数之和
 */
#include <math.h>
// @lc code=start
class Solution {
public:
    bool judgeSquareSum(int c) {
        //缩短问题规模，时间复杂度位O(根号n)
        long low = 0, high = floor(sqrt(c) + 0.5);
        while (low <= high) {
            long sum = low * low + high * high;
            if (sum == c) {
                return true;
            } else if (sum < c) {
                ++low;
            } else {
                --high;
            }
        }
        return false;
    }
};
// @lc code=end

