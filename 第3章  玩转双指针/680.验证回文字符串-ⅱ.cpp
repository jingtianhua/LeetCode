/*
 * @lc app=leetcode.cn id=680 lang=cpp
 *
 * [680] 验证回文字符串 Ⅱ
 */

// @lc code=start
class Solution {
public:
    bool validPalindrome(string s) {
        int head = 0, rear = s.size() - 1;
        //第一次从两边遍历，如果遇到不匹配回文，记录
        while (head < rear) {
            if (s.at(head) != s.at(rear)) {
                return validPalindrome(s, head + 1, rear) ||
                    validPalindrome(s, head, rear - 1);
            } else {
                ++head;
                --rear;
            }
        }
        return true;
    }

private:
    bool validPalindrome(string s, int head, int rear) {
        while (head < rear) {
            if (s.at(head) != s.at(rear)) {
                return false;
            } else {
                ++head;
                --rear;
            }
        }
        return true;
    }
};
// @lc code=end

