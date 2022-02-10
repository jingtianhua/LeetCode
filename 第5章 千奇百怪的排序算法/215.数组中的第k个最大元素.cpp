/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int l = 0, r = nums.size() - 1, target = nums.size() - k;
        while (l < r) {
            int mid = quickSelection(nums, l, r);
            if (mid == target) {
                return nums[mid];
            } else if (mid < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return nums[l];
    }

private:
    int quickSelection(vector<int>& nums, int l, int r) {
        int i = l + 1, j = r, key = nums[l];
        while (i < j) {
            while (i < j && nums[j] >= key) {
                --j;
            }
            nums[i] = nums[j];
            while (i < j && nums[i] <= key) {
                ++i;
            }
            nums[j] = nums[i];
        }
        nums[i] = key;
        return i;
    }
};
// @lc code=end

