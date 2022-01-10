/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        /*双指针思想，分别用两个指针指向两个数组的有效数字末尾，然后依次向前遍历
        把大的数放在num1数组的末尾*/
        int pos = m-- + n-- - 1;
        while (m >= 0 &&  n >= 0)
        {
            nums1[pos--] = nums1[m] > nums2[n] ? nums1[m--] : nums2[n--];
        }
        while (n >= 0)
        {
            nums1[pos--] = nums2[n--];
        }
    }
};
// @lc code=end

