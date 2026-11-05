class Solution {
public:
    int characterReplacement(string s, int k) {
        int letters[26] = {0};

        int l = 0, ans = 0, maxF = 0, n = s.length();
        for(int r = 0; r < n; r++) {
            maxF = max(maxF, ++letters[s[r]-'A']);

            while(r - l + 1 - maxF > k) {
                letters[s[l++]-'A']--;
            }

            ans = max(ans, r-l+1);
        }
        return ans;
    }
};
