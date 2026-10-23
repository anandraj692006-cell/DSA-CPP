class Solution {
public:
    int maxArea(vector<int>& height) {
        int lo = 0, hi = height.size() - 1, best = 0;

        while (lo < hi) {
            int h = height[lo] < height[hi] ? height[lo] : height[hi];
            int area = h * (hi - lo);
            if (area > best) best = area;

            if (height[lo] == h) while (lo < hi && height[lo] <= h) lo++;
            else                 while (lo < hi && height[hi] <= h) hi--;
        }
        return best;
    }
};