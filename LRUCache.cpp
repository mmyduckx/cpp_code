#include <unordered_map>
#include <iostream>
using namespace std;
class LRUCache {
public:
	LRUCache(int capacity) {
		cap = capacity;
	}

	int get(int key) {
		auto item = cache.find(key);
		if (item == cache.end())
			return -1;
		else {
			update(item);
			return item->second.first;
		}
	}

	void put(int key, int value) {

		auto item = cache.find(key);
		//if find

		if (item != cache.end()) {
			//update lru
			update(item);
			cache[key] = { value, lru.begin() };

		}
		//if not find
		else {
			//if reach capacity
			//evict lru
			if (cache.size() == cap) {
				cache.erase(lru.back());
				lru.pop_back();
			}
			// push_front
			lru.push_front(key);
			cache.insert({ key, {value, lru.begin()} });
		}
	}

	//if find, move to head
	void update(unordered_map<int, pair<int, list<int>::iterator>>::iterator& it) {
		lru.erase(it->second.second);
		lru.push_front(it->first);
		it->second.second = lru.begin();
	}

private:
	int cap;
	// unordered_map<key, <value, key iterator> >
	unordered_map<int, pair<int, list<int>::iterator>> cache;
	//head is MRU tail is LRU
	list<int> lru;

};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */


int main() {

	LRUCache * cache = new LRUCache(2 /* capacity */);

	cache->put(1, 1);
	cache->put(2, 2);

	cout << cache->get(1) << endl;       // returns 1
	cache->put(3, 3);    // evicts key 2
	cache->get(2);       // returns -1 (not found)
	cache->put(4, 4);    // evicts key 1
	cout << cache->get(1) << endl;             // returns -1 (not found)
	cout << cache->get(3) << endl;              // returns 3
	cout << cache->get(4) << endl;            // returns 4
	cin.get();
}
