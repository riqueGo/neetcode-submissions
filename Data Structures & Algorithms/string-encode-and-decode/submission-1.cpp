class Solution {
public:

    string encode(vector<string>& strs) {
        stringstream ss;
        for(string s : strs) {
            ss << to_string(s.length()) << '\x1F' << s;
        }
        return ss.str();
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int i = 0;
        while(i < s.length()) {
            int j = i;
            while(s[j] != '\x1F') {
                j++;
            }
            int len = stoi(s.substr(i,j-i));
            j++;

            ans.push_back(s.substr(j, len));
            i = j + len;
        }

        return ans;
    }
};
