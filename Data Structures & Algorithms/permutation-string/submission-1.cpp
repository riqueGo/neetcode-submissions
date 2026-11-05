class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()) return false;

        unordered_map<char,int> umapS1;
        unordered_map<char,int> umapS2;

        for(char ch : s1) umapS1[ch]++;

        int l = 0, r = 0;
        for(;r < s1.length(); r++) umapS2[s2[r]]++;

        while(true) {
            bool isEqual = true;
            for(auto &[ch,freq] : umapS1) {

                if(umapS2[ch] != freq) {
                    isEqual = false;
                    break;
                }
            }

            if(isEqual) return true;
            if(r >= s2.length()) break;

            umapS2[s2[l++]]--;
            umapS2[s2[r++]]++;
        }

        return false;
    }
};
