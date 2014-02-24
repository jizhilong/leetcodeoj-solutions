/*
 * =====================================================================================
 *
 *       Filename:  lru.cpp
 *
 *    Description:  Design and implement a data structure for Least Recently Used(LRU) cache.
 *                  It should support the following operations: get and set.
 *                  ----------------------------------------------------------------------
 *                  get(key) - Get the value (will always be positive) of the key if the key
 *                  exists in the cache, otherwise return -1.
 *                  set(key, value) - Set or insert the value if the key is not already present
 *                  When the cache reached its capacity, it should invalidate the least recently
 *                  used item before inserting a new item.
 *                  -----------------------------------------------------------------------
 *
 *        Version:  1.0
 *        Created:  02/23/2014 11:38:46 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ji.Zhilong (), zhilongji@gmail.com
 *   Organization:  SJTU
 *
 * =====================================================================================
 */

#include <iostream>
using namespace std;

struct CacheNode {
  int key;
  int val;
  CacheNode *prev;
  CacheNode *next;

  CacheNode():key(0),val(0),prev(NULL), next(NULL) {}
  CacheNode(int x, int y): key(x), val(y), prev(NULL), next(NULL) {}
  CacheNode(int x, int y, CacheNode *p, CacheNode *n): key(x), val(y), prev(p), next(n) {}

  void append(CacheNode *node) {
    next->prev = node;
    node->next = next;
    node->prev= this;
    next = node;
  }

  CacheNode *drop() {
     prev->next = next;
     next->prev = prev;
     return this;
  }

};

class LRUCache {
  private:
    CacheNode *head;
    int capacity;
    int size;
  public:
    LRUCache(int capacity):capacity(capacity), size(0) {
      head = new CacheNode();
      head->next = head->prev = head;
    }

    CacheNode *getNode(int key) {
      CacheNode *h = head->next;
      if (head == h)
        return NULL;
      if (h->key == key)
        return h;
      for (; h != head && h->key != key; h = h->next);

      if (h == head)
        return NULL;
      head->append(h->drop());
      return h;
    }

    int get(int key) {
      CacheNode *node = getNode(key);
      if (node)
        return node->val;
      return -1;
    }

    void set(int key, int value) {
      CacheNode *node = getNode(key);
      if (node) {
        node->val = value;
      } else {
        if (size == capacity) {
          node = head->prev;
          node->drop();
          node->key = key;
          node->val = value;
          head->append(node);
        } else {
          head->append(new CacheNode(key, value));
          size++;
        }
      }
    }
};


int
main(int argc, char *argv[])
{
  LRUCache lru(1);
  lru.set(2, 1);
  cout << lru.get(2) << endl;
  lru.set(3, 2);
  cout << lru.get(2) << endl;
  cout << lru.get(3) << endl;
}
