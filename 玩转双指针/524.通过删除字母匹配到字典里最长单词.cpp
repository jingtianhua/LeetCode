/*
 * @lc app=leetcode.cn id=524 lang=cpp
 *
 * [524] 通过删除字母匹配到字典里最长单词
 */
#include <unordered_map>
#include <unordered_set>
// @lc code=start
class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        int max_size = 0;
        int dicSize = dictionary.size();
        int max_index = dicSize + 1;
        for (size_t i = 0; i < dicSize; ++i) {
            if (judgeLongestWord(s, dictionary[i])) {
                int dicSizeTemp = dictionary[i].size();
                if (max_size > dicSizeTemp) {
                    continue;
                } else if (max_size < dicSizeTemp) {
                    max_size = dicSizeTemp;
                    max_index = i;
                } else if (max_size == dicSizeTemp) {
                    max_index = dictionary[max_index] < dictionary[i] ?
                        max_index : i;
                }
            }
        }
        return max_index > dicSize ? "" : dictionary[max_index];
    }

private:
    bool judgeLongestWord(string s, string t) {
        if (s.size() < t.size()) {
            return false;
        }
        int sHead = 0, tHead = 0;
        int sRear = s.size(), tRear = t.size();
        while (tHead != tRear && sHead != sRear) {
            if (s.at(sHead) == t.at(tHead)) {
                ++sHead;
                ++tHead;
            } else {
                ++sHead;
            }
        }
        if (tHead == tRear) {
            return true;
        }
        return false;
    }
};
// @lc code=end

