class Node {
public:
	int key;
	Node *pre, *nxt;
	Node (int k): key(k), pre(nullptr), nxt(nullptr) {}
};

class LRUCache{
public:
	deque<int> que;
	unordered_map<int, int> cache;
	unordered_map<int, Node*> key2node;
	int cap, curSize;
	Node *head, *tail;

    LRUCache(int capacity) {
		curSize = 0;
		cap = capacity;
        que.clear();
		cache.clear();
		head = tail = nullptr;
    }
    
	void renew(int key) {
		Node *toDel = key2node[key];
		if (toDel == head) return;
		toDel->pre->nxt = toDel->nxt;
		if (tail == toDel) {
			tail = toDel->pre;
		} else {
			toDel->nxt->pre = toDel->pre;
		}
		toDel->nxt = head;
		head->pre = toDel;
		head = toDel;
		head->pre = nullptr;
	}

    int get(int key) {
        if (cache.find(key) == cache.end()) {
			return -1;
		} else {
			renew(key);
			return cache[key];
		}
    }
    
    void set(int key, int value) {
        if (get(key) == -1) {
			if (curSize >= cap) {
				Node *tmp = tail;
				if (head == tail) {
					head = tail = nullptr;
				} else {
					tail = tail->pre;
					tail->nxt = nullptr;
					curSize --;
				}
				cache.erase(tmp->key);
				key2node.erase(tmp->key);
				delete tmp;
			}
			Node *newOne = new Node(key);
			if (head != nullptr) {
				head->pre = newOne;
			}
			newOne->nxt = head;
			head = newOne;
			if (tail == nullptr) tail = head;
			curSize ++;
			cache[key] = value;
			key2node[key] = newOne;
		} else {
			cache[key] = value;
			renew(key);
		}
    }
};