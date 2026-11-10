class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> rightToLeft (n);
        rightToLeft[n-1] = height.back();
        for(int i = n-2; i >= 0; i--) rightToLeft[i] = max(height[i], rightToLeft[i+1]);

        int maxLeftToRight = height[0];
        int ans = min(maxLeftToRight, rightToLeft[0]) - height[0];
        for(int i = 1; i < n; i++) {
            maxLeftToRight = max(maxLeftToRight, height[i]);
            ans += min(maxLeftToRight, rightToLeft[i]) - height[i];
        }

        return ans;
    }
};
