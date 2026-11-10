class LRUNode {
public:
    LRUNode* next;
    LRUNode* prev;
    int key;
    int val;

    LRUNode(int key, int val) {
        next = nullptr;
        prev = nullptr;
        this->key = key;
        this->val = val;
    }
};

class LRUCache {
private:
    unordered_map<int, LRUNode*> umap;
    LRUNode* head;
    LRUNode* tail;
    int capacity;

void removeNode(LRUNode*& node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
}

void appendNode(LRUNode*& node) {
    head->prev->next = node;
    node->prev = head->prev;

    node->next = head;
    head->prev = node;
}

public:
    LRUCache(int capacity) {
        head = new LRUNode(-1, -1);
        tail = new LRUNode(-1, -1);
        head->prev = tail;
        tail->next = head;
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(umap.find(key) == umap.end()) return -1;

        LRUNode* node = umap[key];
        removeNode(node);
        appendNode(node);

        return node->val;
    }
    
    void put(int key, int value) {
        LRUNode* node;
        if(umap.find(key) == umap.end()) {
            node = new LRUNode(key, value);
        } else {
            node = umap[key];
            removeNode(node);
        }

        node->val = value;
        appendNode(node);
        umap[key] = node;

        if(umap.size() > capacity) {
            LRUNode* toRemove = umap[tail->next->key];
            removeNode(toRemove);
            umap.erase(toRemove->key);
            delete toRemove;
        }
    }
};
