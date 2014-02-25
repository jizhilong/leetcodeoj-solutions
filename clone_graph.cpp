/*
 * =====================================================================================
 *
 *       Filename:  clone_graph.cpp
 *
 *    Description:  Clone an undirected graph.Each node in the graph contains a label and
 *                  a list of its neighbors.
 *
 *        Version:  1.0
 *        Created:  02/25/2014 10:47:27 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ji.Zhilong (), zhilongji@gmail.com
 *   Organization:  SJTU
 *
 * =====================================================================================
 */

#include <queue>
#include <unordered_set>
#include <vector>
#include <iostream>

using namespace std;

struct UndirectedGraphNode {
  int label;
  vector<UndirectedGraphNode *> neighbors;
  UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
  public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
      if (node == NULL)
        return NULL;

      unordered_set<int> set;
      queue<UndirectedGraphNode *> q;

      q.push(node);
      set.insert(node->label);

      while (!q.empty()) {                      /* clone node */
        UndirectedGraphNode *node = q.front(); q.pop();
        UndirectedGraphNode *clone = new UndirectedGraphNode(node->label);
        node->neighbors.push_back(clone);
        clone->neighbors.push_back(node);
        for (int i = 0; i < node->neighbors.size() - 1; i++) {
          UndirectedGraphNode *nb = node->neighbors[i];
          if (set.find(nb->label) == set.end()) {
              q.push(nb);
              set.insert(nb->label);
          }
        }
      }

      q.push(node);
      set.clear();
      set.insert(node->label);

      while (!q.empty()) {                    /* add edge */
        UndirectedGraphNode *node = q.front(); q.pop();
        UndirectedGraphNode *clone = node->neighbors.back();

        for (int i = 0; i < node->neighbors.size() - 1; i++) {
          UndirectedGraphNode *nb = node->neighbors[i];
          clone->neighbors.push_back(nb->neighbors.back());
          if (set.find(nb->label) == set.end()) {
              q.push(nb);
              set.insert(nb->label);
          }
        }
      }

      q.push(node);
      set.clear();
      set.insert(node->label);
      UndirectedGraphNode *res = node->neighbors.back();

      while (!q.empty()) {                    /* remove additional neighbors */
        UndirectedGraphNode *node = q.front(); q.pop();
        UndirectedGraphNode *clone = node->neighbors.back();
        node->neighbors.erase(node->neighbors.end() - 1);
        clone->neighbors.erase(clone->neighbors.begin());

        for (int i = 0; i < node->neighbors.size(); i++) {
          UndirectedGraphNode *nb = node->neighbors[i];
          if (set.find(nb->label) == set.end()) {
              q.push(nb);
              set.insert(nb->label);
          }
        }
      }

      return res;
    }

    void printGraph(UndirectedGraphNode *node) {
      queue<UndirectedGraphNode *> q;
      unordered_set<int> set;
      q.push(node);
      set.insert(node->label);

      while (!q.empty()) {
        UndirectedGraphNode *n = q.front(); q.pop();
        cout << n->label << " : ";

        for (int i = 0; i < n->neighbors.size(); i++) {
          UndirectedGraphNode *nb = n->neighbors[i];
          cout << nb->label << " ";
          if (set.find(nb->label) == set.end()) {
              q.push(nb);
              set.insert(nb->label);
          }
        }
        cout << endl;
      }
    }
};

int
main()
{
  UndirectedGraphNode *n0 = new UndirectedGraphNode(0);
  UndirectedGraphNode *n1 = new UndirectedGraphNode(1);
  UndirectedGraphNode *n2 = new UndirectedGraphNode(2);
  UndirectedGraphNode *n3 = new UndirectedGraphNode(3);
  UndirectedGraphNode *n4 = new UndirectedGraphNode(4);
  UndirectedGraphNode *n5 = new UndirectedGraphNode(5);
  
  n0->neighbors.push_back(n1);
  n1->neighbors.push_back(n0);
  n0->neighbors.push_back(n5);
  n5->neighbors.push_back(n0);
  n1->neighbors.push_back(n2);
  n2->neighbors.push_back(n1);
  n1->neighbors.push_back(n5);
  n5->neighbors.push_back(n1);
  n2->neighbors.push_back(n3);
  n3->neighbors.push_back(n2);
  n3->neighbors.push_back(n4);
  n4->neighbors.push_back(n3);
  n3->neighbors.push_back(n4);
  n4->neighbors.push_back(n3);
  n4->neighbors.push_back(n5);
  n5->neighbors.push_back(n4);
  n4->neighbors.push_back(n5);
  n5->neighbors.push_back(n4);

  Solution solution;
  solution.printGraph(n0);
  UndirectedGraphNode *res = solution.cloneGraph(n0);
  cout << endl;
  solution.printGraph(res);
}
