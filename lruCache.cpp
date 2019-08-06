#include <bits/stdc++.h>
using namespace std;

class Node {
public:
  int key;
  int value;
  Node *next, *prev;

  Node(int key, int value) {
    this->key = key;
    this->value = value;
    this->prev = this->next = NULL;
  }
};

class LRUCache {
private:
  int size, capacity;
  unordered_map<int, Node*> lookup;
  Node *head, *tail;
  
  void insertNew(int key, int value) {
    Node *temp = new Node(key, value);
    
    if(head==NULL && tail==NULL) {
      head = tail = temp;
    } else {
      temp->next = head;
      head->prev = temp;
      head = temp;
    }
    
    // Now making entry in lookup table
    lookup[key] = temp;
    
    return;
  }

  void updateOld(Node *addr, int value) {
    // Update value for the key
    addr->value = value;

    // Move to first position
    // 1. Link Previous and Next of our target node
    if(addr == head) return;

    if(addr == tail) {
      tail = addr->prev;
      tail->next = NULL;
    } else {
      addr->prev->next = addr->next;
      addr->next->prev = addr->prev;
    }

    // 2. Insert target node at head
    addr->next = head;
    head->prev = addr;
    head = addr;
    head->prev = NULL;

    return;
  }
public:
    LRUCache(int capacity) {
      this->capacity = capacity;
      size = 0;
      head = tail = NULL;  
    }
    
    int get(int key) {
      auto it = lookup.find(key);

      if(it == lookup.end()) return -1;

      Node *temp = it->second;

      // Moving the node to first position and keeping same value;
      updateOld(temp, temp->value);

      return temp->value;  
    }
    
    void put(int key, int value) {
      auto it = lookup.find(key);

      // Check if key exists in lookup table
      if(it != lookup.end()) {
        updateOld(it->second, value);
      } else {
        // Check if List is full
        if(size == capacity) {
          // Remove from lookup table
          lookup.erase(tail->key);

          // Remove from tail
          Node *temp = tail;
					
          // If the capacity of LRU Cache is 1
          if(head == tail) {
            head = tail = NULL;
          } else {
            tail = tail->prev;  
            tail->next = NULL;
          }
          
          delete temp;

          // Insert the new node
          insertNew(key, value);
        } else {
          insertNew(key, value);
          size += 1;
        }
      }        
    }
};

int main() {
  LRUCache cache(2);

  cache.put(1, 1);
  cache.put(2, 2);
  cout << cache.get(1) << endl;       // returns 1
  cache.put(3, 3);    // evicts key 2
  cout << cache.get(2) << endl;       // returns -1 (not found)
  cache.put(4, 4);    // evicts key 1
  cout << cache.get(1) << endl;       // returns -1 (not found)
  cout << cache.get(3) << endl;       // returns 3
  cout << cache.get(4) << endl;       // returns 4

  return 0;
}