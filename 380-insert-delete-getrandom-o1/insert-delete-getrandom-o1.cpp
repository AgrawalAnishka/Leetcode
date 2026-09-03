class RandomizedSet {
public:
    unordered_map<int,bool> mp ; 
    RandomizedSet() {

    }
    
    bool insert(int val) {
        if(mp.find(val)!=mp.end()){
            return false;
        }
        mp[val]  = true;
        return true;
    }
    
    bool remove(int val) {
        if(mp.find(val)!=mp.end()){
             mp.erase(val);
            return true;
        }else{
            return false;
        }
       

    }
    
    int getRandom() {
        int size = mp.size() ;
         mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
          int randN = rng() % size ; 
        auto it = mp.begin() ;

        advance(it , randN);
        return it->first ; 
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */