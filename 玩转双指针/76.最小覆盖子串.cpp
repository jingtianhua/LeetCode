/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string.h>
using namespace std;
// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> charsCount;
        unordered_set<char> charsFlag;
        for (size_t i = 0; i < t.size(); ++i)
        {
            ++charsCount[t[i]];
            charsFlag.insert(t[i]);
        }
        //滑动窗口
        int cnt = 0, l = 0, min_l = 0, min_size = s.size() + 1;
        for (size_t i = 0; i < s.size(); ++i)
        {
            if (charsFlag.find(s[i]) != charsFlag.end()) {
                if (--charsCount[s[i]] >= 0) {
                    ++cnt;
                }
                //如果已经包含全部字符，移动
                while (cnt == t.size())
                {
                    if (i - l + 1 < min_size) {
                        min_l = l;
                        min_size = i - l + 1;
                    }
                    if (charsFlag.find(s[l]) != charsFlag.end()
                    && ++charsCount[s[l]] > 0) {
                        --cnt;
                    }
                    ++l;
                }
            }
        }
        return min_size > s.size() ? "" : s.substr(min_l, min_size);
    }
};
// @lc code=end

