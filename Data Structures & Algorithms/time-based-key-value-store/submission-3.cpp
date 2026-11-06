class TimeMap {
private:
    unordered_map <string, vector<pair<int, string>>> umap;

public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        umap[key].emplace_back(timestamp, value);
    }
    
    string get(string key, int timestamp) {
        auto& valueByTime = umap[key];
        int l = 0, r = valueByTime.size()-1, m;
        string ans = "";

        while(l <= r) {
            m = l + (r-l)/2;

            if(timestamp >= valueByTime[m].first) {
                ans = valueByTime[m].second;
                l = m+1;
            } else r = m-1;
        }

        return ans;
    }
};
