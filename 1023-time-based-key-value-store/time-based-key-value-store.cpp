class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> mp;

    TimeMap() {}

    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {
        auto it = mp.find(key);
        if (it == mp.end()) return "";

        auto &vec = it->second; // sorted by timestamp
        // 找第一个 timestamp > 给定 timestamp 的位置
        int l = 0, r = (int)vec.size(); // [l, r)
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (vec[mid].first <= timestamp) l = mid + 1;
            else r = mid;
        }
        // l 是第一个 > timestamp 的位置
        if (l == 0) return "";
        return vec[l - 1].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */