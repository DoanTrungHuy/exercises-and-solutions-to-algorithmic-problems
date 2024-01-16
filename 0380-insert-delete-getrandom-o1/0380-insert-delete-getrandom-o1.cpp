class RandomizedSet {
private:
    unordered_map<int, int> um;
    vector<int> v;
    
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (um.find(val) != um.end()) {
            return false;
        }
        v.push_back(val);
        um[val] = v.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if (um.find(val) == um.end()) {
            return false;
        }
        int last = v.back();
        um[last] = um[val];
        v[um[val]] = last;
        v.pop_back();
        um.erase(val);
        return true;
    }
    
    int getRandom() {
        int n = v.size();
        return v[rand() % n];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */