/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int m = nums1.size(), n = nums2.size();
        int low1 = 0, high1 = m - 1, low2 = 0, high2 = n - 1;
        if ((m + n) % 2 == 1) {
            return (double)findIndexN(nums1, nums2, low1, high1, low2, high2, (m + n)/2);
        } else {
            int n1 = (m + n - 2) / 2;
            int n2 = (m + n - 2) / 2 + 1;
            return (double)(findIndexN(nums1, nums2, low1, high1, low2, high2, n1) + 
            findIndexN(nums1, nums2, low1, high1, low2, high2, n2)) / 2;  
        }
    }

private:
    //关键算法，从两个数组中选出第n大的数  
    double findIndexN (vector<int>& nums1, vector<int>& nums2, int low1, int high1,
        int low2, int high2, int n) {
        //要从数组中减去n个数，每次至少减去二分之n个数，时间复杂度为O(log n)
        int point1, point2;
        //num[1]此时最多可以减去的数
        int length1 = high1 - low1 + 1;
        //num[2]此时最多可以减去的数
        int length2 = high2 - low2 + 1;

        int halfN = n / 2;
        halfN = halfN == 0 ? 1 : halfN;

        if (n == 0) {
            if (low1 > high1) { //num1删除完了
                return nums2[low2];
            } else if (low2 > high2) { //num2删除完了
                return nums1[low1];
            } else {
                return nums1[low1] < nums2[low2] ? nums1[low1] : nums2[low2];
            }
        }

        if (length1 < halfN) {
            point1 = high1;
        } else {
            point1 = low1 + halfN - 1;
        }

        if (length2 < halfN) {
            point2 = high2;
        } else {
            point2 = low2 + halfN - 1;
        }
        length1 = point1 - low1 + 1;
        length2 = point2 - low2 + 1;

        if (low1 > high1) {
            return nums2[low2 + n];
        } else if (low2 > high2) {
            return nums1[low1 + n];
        } else if (nums1[point1] <= nums2[point2]) {
            return findIndexN(nums1, nums2, point1 + 1, high1, low2, high2, n - length1);
        } else {
            return findIndexN(nums1, nums2, low1, high1, point2 + 1, high2, n - length2);
        }
    }
};
// @lc code=end

