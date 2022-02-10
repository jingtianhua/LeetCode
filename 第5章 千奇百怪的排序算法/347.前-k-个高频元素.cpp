/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */
#include <unordered_map>
#include <map>
#include <vector>
#include <math.h>
// @lc code=start
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        for (const int & num : nums) {
            ++counts[num];
        }
        multimap<int, int> buckets;
        for (const auto & p : counts) {
            buckets.insert({p.second, p.first});
        }
        vector<int> ans;
        auto rlt = buckets.rbegin();
        while (k > 0 && rlt != buckets.rend()) {
            ans.push_back(rlt->second);
            --k;
            ++rlt;
        }
        return ans;
    }
};
// @lc code=end

