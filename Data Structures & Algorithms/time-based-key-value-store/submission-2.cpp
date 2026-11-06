class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> umap;

public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        if(umap.find(key) == umap.end()) umap[key] = {};

        umap[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(umap.find(key) == umap.end()) return "";

        pair<int, string> prev = {-1, ""};
        for(auto &[time, val] : umap[key]) {
            if(time > timestamp) break;
            prev = {time, val};
        }

        return prev.second;
    }
};
