class Solution {
public:
    string longestPalindrome(string s) {
        int longest = 0, left, right, resultLeft, resultRight;

        for(int i = 0; i < s.length(); i++)
        {
            left = i;
            right = i;
            while(left >= 0 && right < s.length() && s[left] == s[right])
            {
                left--;
                right++;
            }

            left++;
            right--;

            if(right-left+1 > longest)
            {
                resultLeft = left;
                resultRight = right;
                longest = right-left+1;
            }

            left = i;
            right = i+1;
            while(left >= 0 && right < s.length() && s[left] == s[right])
            {
                left--;
                right++;
            }

            left++;
            right--;

            if(right-left+1 > longest)
            {
                resultLeft = left;
                resultRight = right;
                longest = right-left+1;
            }
        }

        string result = s.substr(resultLeft, longest);
        return result;
    }
};
