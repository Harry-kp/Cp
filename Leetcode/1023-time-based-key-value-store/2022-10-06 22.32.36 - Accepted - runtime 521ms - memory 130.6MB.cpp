class TimeMap {
public:
    unordered_map<string, map<int, string>> m1;
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        m1[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if (m1.find(key) == m1.end()) {
            return "";
        }
        
        auto it = m1[key].upper_bound(timestamp);
        if (it == m1[key].begin()) {
            return "";
        }
        
        return (--it)->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */