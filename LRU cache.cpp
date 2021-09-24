class LRUCache {
public:
    
    int i;
    int n;
    unordered_map<int, pair<int, int>> m;
    set<pair<int, int>> s;
    
    LRUCache(int capacity) {
        
        i = 0;
        n = capacity;
    }
    
    int get(int key) { 
        if (m.find(key) == m.end()) {
            return -1;
        }
        s.insert({i, key});
        pair<int,int> p = m[key];
        s.erase({p.first, key});
        p.first = i++;
        m[key] = p;
        return p.second;
    }
    
    void put(int key, int value) {
        if (m.find(key) != m.end()) {
            s.erase({m[key].first, key});
        } 
        else if (s.size() == n) {
            auto it = s.begin();
            m.erase(it->second);
            s.erase(it);
        }
        s.insert({i, key});
        m[key] = {i, value};
        i++;
    }
};

