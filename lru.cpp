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

  CacheNode():key(0),val(0),next(NULL) {}
  CacheNode(int x, int y): key(x), val(y), prev(NULL), next(NULL) {}
  CacheNode(int x, int y, CacheNode *p, CacheNode *n): key(x), val(y), prev(p), next(n) {}
};

class LRUCache {
  private:
    CacheNode *head, *tail;
    int capacity;
    int size;
  public:
    LRUCache(int capacity):capacity(capacity), size(0), head(NULL), tail(NULL) {
    }

    CacheNode *getNode(int key) {
      if (NULL == head)
        return NULL;
      if (head  && head->key == key)
        return head;
      CacheNode *n;
      for (n = head; head->next && head->next->key != key; head = head->next);
      if (n->next == NULL)
        return NULL;
      CacheNode *tmp = n->next;
      n->next = n->next->next;
      tmp->next = head;
      head = tmp;
      return head;
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
        if (size == 0) {
          head = tail = new CacheNode(key, value, NULL, NULL);
          size++;
        } else if (size == capacity) {
          tail->key = key;
          tail->val = value;

          tail->prev->next = NULL;
          node = tail->prev;
          tail->prev = NULL;
          tail->next = head;
          head->prev = tail;
          head = tail;
          tail = node;
        } else {
          node = new CacheNode(key, value, NULL, head);
          head->prev = node;
          head = node;
          size++;
        }
      }
    }
};
