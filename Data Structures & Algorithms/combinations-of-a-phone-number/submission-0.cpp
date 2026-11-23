class Solution {
private:
    string phone [8] = {
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };

    vector<string> ans;

    void solve(const string& digits, string& curr, int idx) {
        if(idx == digits.length()) {
            ans.push_back(curr);
            return;
        }

        for(char ch : phone[digits[idx]-'2']) {
            curr+=ch;
            solve(digits, curr, idx+1);
            curr.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        if(digits.length() > 0) {
            string curr = "";
            solve(digits, curr, 0);
        }
        return ans;
    }
};
