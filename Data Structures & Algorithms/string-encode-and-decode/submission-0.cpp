class Solution {
public:

    string encode(vector<string>& strs) {
        stringstream ss;
        for(string s : strs) {
            ss << s << '\x1F';
        }
        return ss.str();
    }

    vector<string> decode(string s) {
        vector<string> ans;
        stringstream ss;
        for(char ch : s) {
            if(ch == '\x1F') {
                ans.push_back(ss.str());
                ss.str(""); ss.clear(); //reset
            } else {
                ss << ch;
            }
        }

        return ans;
    }
};
