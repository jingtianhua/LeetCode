/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */

// @lc code=start
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        unsigned int child = 0;
        unsigned int cookie = 0;
        auto const &gSize = g.size();
        auto const &sSize = s.size();
        while (child < gSize && cookie < sSize) {
            if (g[child] <= s[cookie]) {
                ++child;
            }
            ++cookie;
        }
        return child;
        
    }
};
// @lc code=end

