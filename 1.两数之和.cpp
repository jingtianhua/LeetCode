/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */
// @lc code=start
typedef struct
{
    int a;
    int b;
}test;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); ++i) {
            int another = target - nums[i];
            if (hash.count(another) != 0) {
                return {hash[target - nums[i]], i};
            }
            hash[nums[i]] = i;
         
        }
		return {-1, -1};
	}
};
// @lc code=end

