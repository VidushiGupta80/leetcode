//LRU Cache -> 08/25/2020 18:31
// class LRUCache {
// map<int, int> cache;
// queue<int> freq;
// int c = 0;
// multiset<int> keeper;
// public:
//     LRUCache(int capacity) {
//         c = capacity;
//     }
    
//     int get(int key) {
//         if(cache.find(key) == cache.end())
//             return -1;
//         int ans = cache[key];
//         if(ans != -1)
//         {
//             freq.push(key);
//             c++;
//             keeper.insert(key);
//         }
//         return ans;
//     }
    
//     void put(int key, int value) {
//         if(cache.find(key) != cache.end() && cache[key] != -1)
//         {
//             cache[key] = value;
//             freq.push(key);
//             c++;
//             keeper.insert(key);
//         }
//         else if(freq.size() < c)
//         {
//             cache[key] = value;
//             freq.push(key);
//             keeper.insert(key);
//         }
//         else if(freq.size() == c)
//         {
//             while(freq.size() == c){
//                 int keyRemove = freq.front();
//                 int num = keeper.count(keyRemove);
//                 keeper.erase(keyRemove);
//                 if(num == 1)
//                 {
//                     cache[keyRemove] = -1;
//                     freq.pop();
//                     break;
//                 }
//                 else
//                 {
//                     for(int i = 0; i < num - 1; i++)
//                         keeper.insert(keyRemove);
//                     c--;
//                 }
//                 freq.pop();
//             }
            
//             cache[key] = value;
//             freq.push(key);
//         }
//     }
// };

// /**
//  * Your LRUCache object will be instantiated and called as such:
//  * LRUCache* obj = new LRUCache(capacity);
//  * int param_1 = obj->get(key);
//  * obj->put(key,value);
//  */

class LRUCache {
    unordered_map<int, pair<int, list<int>::iterator>> cache;
    list<int> dq;                         // acting like time stamps
    int capacity;

    void add(int key){
        if(cache.size() == capacity){    
            cache.erase(dq.back());       // erase last node from cache
            dq.pop_back();                // erase last key from back of ll
        }

        dq.push_front(key);               // add new key to front of ll
    }

public:
    LRUCache(int capacity){
        this->capacity = capacity;
    }

    int get(int key) {
        if(!cache.count(key))         // if key doesnt exist
            return -1;

        auto &[val, it] = cache[key];
        dq.erase(it);                 // erase old node
        dq.push_front(key);           // insert new node to front of ll
        it = dq.begin();              // change its cache ptr to head of ll

        return val;
    }

    void put(int key, int value) {
        if(cache.count(key))
            this->get(key);
        else
            this->add(key);

        cache[key] = {value, dq.begin()};
    }
};
