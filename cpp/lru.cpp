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
#include <map>
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
    map<int, CacheNode *> cache;
    int capacity;
    int size;
  public:
    LRUCache(int capacity):capacity(capacity), size(0) {
      head = new CacheNode();
      head->next = head->prev = head;
    }

    int get(int key) {
      map<int, CacheNode *>:: iterator it = cache.find(key);
      if (it == cache.end())
        return -1;
      CacheNode *node = it->second;
      head->append(node->drop());
      return it->second->val;
    }

    void set(int key, int value) {
      map<int, CacheNode *>:: iterator it = cache.find(key);
      CacheNode *node;
      if (it != cache.end()) {
        node = it->second;
        node->val = value;
        head->append(node->drop());
      } else {
        if (size == capacity) {
          node = head->prev;
          cache.erase(cache.find(node->key));
          node->drop();
          node->key = key;
          node->val = value;
          head->append(node);
          cache[key] = node;
        } else {
          head->append(new CacheNode(key, value));
          size++;
          cache[key] = head->next;
        }
      }
    }
};


int
main(int argc, char *argv[])
{
  LRUCache lru(2);
  lru.set(2, 1);
  lru.set(1, 1);
  lru.set(2, 3);
  lru.set(4, 1);
  cout << lru.get(1) << endl;
  cout << lru.get(2) << endl;
}
