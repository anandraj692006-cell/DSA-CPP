class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);

        int m = nums1.size(), n = nums2.size();
        int lo = 0, hi = m, half = (m + n + 1) / 2;

        while (lo <= hi) {
            int i = (lo + hi) >> 1;
            int j = half - i;

            int l1 = i ? nums1[i - 1] : INT_MIN;
            int r1 = i < m ? nums1[i] : INT_MAX;
            int l2 = j ? nums2[j - 1] : INT_MIN;
            int r2 = j < n ? nums2[j] : INT_MAX;

            if (l1 > r2) hi = i - 1;
            else if (l2 > r1) lo = i + 1;
            else {
                if ((m + n) & 1) return max(l1, l2);
                return (max(l1, l2) + min(r1, r2)) / 2.0;
            }
        }
        return 0.0;
    }
};