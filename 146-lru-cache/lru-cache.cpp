class Node {
    public:
        int key;
        int value;
        Node* next;
        Node* prev;
        Node(int key, int value){
            this->key = key;
            this->value = value;
            this->next = NULL;
            this->prev = NULL;
        }
};

class LRUCache {
    int capacity;
    unordered_map<int, Node*> cache;
    Node* head;
    Node* tail;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(cache.find(key) != cache.end()){
            Node* resultNode = cache[key];
            int resultValue = resultNode->value;

            cache.erase(key);
            remove(resultNode);
            insertAtFront(resultNode);
            cache[key] = head->next;
            return resultValue;
        }
        return -1;
    }

    void insertAtFront(Node* newNode){
        Node* temp = head->next;

        newNode->next = temp;
        newNode->prev = head;

        head->next = newNode;
        temp->prev = newNode;
    }

    void remove(Node* existingNode){
        Node* prevv = existingNode->prev;
        Node* nextt = existingNode->next;

        prevv->next = nextt;
        nextt->prev = prevv;
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end()){
            Node* alreadyExistingNode = cache[key];
            cache.erase(key);
            remove(alreadyExistingNode);
        }

        if(cache.size() == capacity){
            Node* nodeToRemove = tail->prev;
            cache.erase(nodeToRemove->key);
            remove(nodeToRemove);
        }

        Node* newNode = new Node(key,value);
        insertAtFront(newNode);
        cache[key] = head->next;
    }
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */