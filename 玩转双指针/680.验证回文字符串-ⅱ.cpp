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
        return validPalindrome(s, head, rear);
    }
private:
    bool validPalindrome(string s, int head, int rear) {
        while (head < rear) {
            if (s[head] != s[rear]) {
                if (isDeleteOnechar) {
                    return false;
                } else {
                    isDeleteOnechar = true;
                    if (validPalindrome(s, head + 1, rear)) {
                        return true;
                    } 
                    if (validPalindrome(s, head, rear - 1)) {
                        return true;
                    }
                    return false;
                }
            }
            ++head;
            --rear;
        }
        return true;
    }

private:
    bool isDeleteOnechar = false;
};
// @lc code=end

