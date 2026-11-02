class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s;

        for(int num : nums) s.insert(num);

        int prev, ans = 0, curr = 0;
        for(auto &next : s) {
            if(ans == 0) {
                prev = next;
                curr = 1;
                ans = 1;
                continue;
            }

            if(next - prev == 1) {
                curr++;
            } else {
                ans = max(ans, curr);
                curr = 1;
            }
            
            prev = next;
        }

        return max(ans, curr);
    }
};
