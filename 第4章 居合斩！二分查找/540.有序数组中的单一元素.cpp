/*
 * @lc app=leetcode.cn id=540 lang=cpp
 *
 * [540] 有序数组中的单一元素
 */

// @lc code=start
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        //注意出现独立数前后，奇偶位的变化
        int low = 0, high = nums.size() - 1;
        while (low < high)
        {
            int mid = (low + high) / 2;
            if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]) {
                return nums[mid];
            }
            //mid 是奇数位
            if (judgeOdd(mid)) {
                if (nums[mid - 1] == nums[mid]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            } else {
                //如果是偶数位
                if (nums[mid - 1] == nums[mid]) {
                    high = mid - 2;
                } else {
                    low = mid + 2;
                }
            }
        }
        return nums[low];
    }

private:
    inline bool judgeOdd (int x) {
        return (x % 2) == 1 ? true : false;
    }
};
// @lc code=end