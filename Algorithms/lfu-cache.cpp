// Link : https://leetcode.com/problems/lfu-cache

class LFUCache {
public:
    int capacity;
    unordered_map<int, int> cache;
    unordered_map<int, int> freq;
    unordered_map<int, int> recentTag;
    int nowKi = 1;
    LFUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(cache.find(key) == cache.end()) return -1;
        recentTag[key] = nowKi++;
        freq[ key ]++;
        return cache[ key ];
    }
    
    void put(int key, int value) {
        if(this->capacity == 0) return;
        recentTag[key] = nowKi++;
        if(cache.find(key) != cache.end()) {
            cache[key] = value;
            freq[ key ]++;
            return;
        }
        if(cache.size() < this->capacity) {
            cache[ key ] = value;
            freq[ key ] = 0;
        }
        else if(cache.size() == this->capacity) {
            int leastFreq = 1000000001, keys, recent;
            for(auto it = freq.begin(); it != freq.end(); it++) {
                if(leastFreq > it->second) {
                    leastFreq = it->second;
                    keys = it->first;
                    recent = recentTag[keys];
                }
                else if(leastFreq == it->second && recentTag[it->first] < recent) {
                    keys = it->first;
                    recent = recentTag[it->first];
                }
            }
            cache.erase(keys);
            freq.erase(keys);
            recentTag.erase(keys);
            cache[key] = value;
            freq[key] = 0;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
