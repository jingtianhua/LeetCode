/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0, j = i, k = nums.size() - 1;

        while (j <= k) {
            if (nums[j] == 0) {
                nums[j++] = nums[i];
                nums[i++] = 0;
            } else if (nums[j] == 1) {
                ++j;
            } else {
                nums[j] = nums[k];
                nums[k--] = 2;
            }
        }
    }
};
// @lc code=end