class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        if (n < 4) return {};

        sort(nums.begin(), nums.end());
        long long t = target;
        vector<vector<int>> res;

        for (int i = 0; i < n - 3; i++) {
            long long a = nums[i];
            if (i > 0 && a == nums[i - 1]) continue;
            if (a + nums[i + 1] + nums[i + 2] + nums[i + 3] > t) break;
            if (a + nums[n - 3] + nums[n - 2] + nums[n - 1] < t) continue;

            for (int j = i + 1; j < n - 2; j++) {
                long long b = nums[j];
                if (j > i + 1 && b == nums[j - 1]) continue;
                if (a + b + nums[j + 1] + nums[j + 2] > t) break;
                if (a + b + nums[n - 2] + nums[n - 1] < t) continue;

                long long need = t - a - b;
                int lo = j + 1, hi = n - 1;
                while (lo < hi) {
                    long long s = (long long)nums[lo] + nums[hi];
                    if (s < need) lo++;
                    else if (s > need) hi--;
                    else {
                        res.push_back({nums[i], nums[j], nums[lo], nums[hi]});
                        int x = nums[lo], y = nums[hi];
                        while (lo < hi && nums[lo] == x) lo++;
                        while (lo < hi && nums[hi] == y) hi--;
                    }
                }
            }
        }
        return res;
    }
};