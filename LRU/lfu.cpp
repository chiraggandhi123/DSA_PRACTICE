class LFUCache {
public:
    int cap;
    int size;
    int minFreq;
    
    unordered_map<int,pair<int,int>>cache;//key->value,freq
    unordered_map<int,list<int>>freq_keylist;
    unordered_map<int,list<int>::iterator>key_listIter;
    LFUCache(int capacity) {
        this->cap = capacity;
    }
    
    int get(int key) {
        if(!cache[key].count())
        {
            updateFreq(key);
            return cache[key].first;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(this->cap<=0) return;
        
        if(cache.count(key))
        {
            cache[key].second = value;
            updateFreq(key);
        }
        else
        {
            if(cache.size()>=cap)
            {
                int leastFrequentKey = freq_keylist[min_freq].back();
                cache.erase(leastFrequentKey);
                key_listIter.erase(leastFrequentKey);
            }
            cache[key] = {value,1};
            freq_keylist[1].push_front(key);
            key_listIter[key] = freq_keylist[1].begin();
            min_freq = 1;
         }
        
            
    }
private:
    void updateFreq(int key)
    {
        int value = cache[key].first;
        int freq = cache[key].second++;

        auto it = key_listIter[key];
        freq_keylist[freq].erase(it);
        freq_keylist[freq++].push_back(key);
        key_listIter[key] = freq_keylist[freq++].back();   


    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */