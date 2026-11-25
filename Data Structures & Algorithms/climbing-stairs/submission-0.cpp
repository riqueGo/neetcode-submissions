class Solution {
public:
    int climbStairs(int n) {
        int x = 1, y = 1, z;
        for(int i = 1; i < n; i++) {
            z = y;
            y += x;
            x = z;
        }
        return y;
    }
};
