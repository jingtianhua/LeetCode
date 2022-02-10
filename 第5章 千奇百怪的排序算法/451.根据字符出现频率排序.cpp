/*
 * @lc app=leetcode.cn id=451 lang=cpp
 *
 * [451] 根据字符出现频率排序
 */
#include<unordered_map>
#include<map>
#include<string.h>
// @lc code=start
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> counts;
        for (const char & ch : s) {
            ++counts[ch];
        }
        multimap<int, char> buckets;
        for (const auto & p : counts) {
            buckets.insert({p.second, p.first});
        }
        auto rlt = buckets.rbegin();
        string str;
        while (rlt != buckets.rend()) {
            string str_temp(rlt->first, rlt->second);
            str += str_temp;
            ++rlt;
        }
        return str;
    }
};
// @lc code=end

