class RandomizedSet {
     vector<int> vec;
     unordered_map<int , int> map;    // store value and Index
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(map.find(val) != map.end())
            return false;  // it means value is present in the map

            vec.push_back(val);
            map[val] = vec.size()-1; // assigning the index of the val in the map
            return true;   // successfully inserted
        
    }
    
    bool remove(int val) {
        if(map.find(val) == map.end())
            return false;   // did not find the value in the map

           int idx = map[val];
           int lastElement  = vec.back(); // get the last element
           
           // put it in the back which is deleting
           vec.back() = val;

           vec[idx] = lastElement;
           map[lastElement] = idx;  //change it in the map

           vec.pop_back();
           map.erase(val);
           return true;
    }
    
    int getRandom() {
        int n = vec.size();
        int randomElement = rand()%n;  // 0 --- (n-1)
        return vec[randomElement];

    }
};