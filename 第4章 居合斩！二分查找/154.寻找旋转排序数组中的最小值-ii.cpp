/*
 * @lc app=leetcode.cn id=154 lang=cpp
 *
 * [154] 寻找旋转排序数组中的最小值 II
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        min = nums[high];
        findMin(nums, low, high);
        return min;
    }

private:
    void findMin(vector<int>& nums, int low, int high) {
        while (low < high)
        {
            int mid = (low + high) / 2;
            if (nums[mid] == nums[low]) {
                min = min < nums[mid] ? min : nums[mid];
                ++low;
            } else if (nums[mid] < nums[low]) {
                //如果右有序
                min = min < nums[mid] ? min : nums[mid];
                findMin(nums, low, mid - 1);
                return;
            } else {
                //如果左有序
                min = min < nums[low] ? min : nums[low];
                findMin(nums, mid + 1, high);
                return;
            }
        }
        min = min < nums[low] ? min : nums[low];
        return;
    }

private:
    int min;
};
// @lc code=end

