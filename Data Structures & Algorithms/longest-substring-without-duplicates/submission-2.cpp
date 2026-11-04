class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        bool letters [256] = {false};

        int l = 0, r = 0, ans = 0;
        for(; r < s.length(); r++) {
            if(!letters[s[r]]) {
                letters[s[r]] = true;
            } else {
                while(l<r && s[l] != s[r]) {
                    letters[s[l++]] = false;
                }
                l++;
            }
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};
