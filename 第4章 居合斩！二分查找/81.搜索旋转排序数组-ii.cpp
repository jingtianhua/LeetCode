/*
 * @lc app=leetcode.cn id=81 lang=cpp
 *
 * [81] 搜索旋转排序数组 II
 */

// @lc code=start
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (nums[mid] == target) {
                return true;
            }
            //判断当前分开的俩个区域，谁是子有序数组
            if (nums[low] == nums[mid]) {
                //判断不出来，把底位指针前移
                ++low;
            } else if (nums[mid] <= nums[high]) {
                //右区间有序
                if (nums[high] >= target && target >= nums[mid]) {
                    return binarySearch(nums, mid + 1, high, target);
                } else {
                    high = mid -1;
                }
            } else {
                //左区间有序
                if (nums[low] <= target && nums[mid] > target) {
                    return binarySearch(nums, low, mid - 1, target);
                } else {
                    low = mid + 1;
                }
            }
        }
        return false;
    }

private:
    //单调不减序列中查找目标值 二分法
    bool binarySearch(vector<int>& nums, int low, int high, int target) {
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (nums[mid] == target) {
                return true;
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return false;
    } 
};
// @lc code=end

