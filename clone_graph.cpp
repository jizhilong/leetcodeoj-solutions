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

      UndirectedGraphNode tmp(0);
      unordered_set<int> set;
      queue<UndirectedGraphNode *> q;
      queue<UndirectedGraphNode *> qs;

      q.push(node);
      qs.push(&tmp);

      while (!q.empty()) {
        UndirectedGraphNode *node = q.front(); q.pop();
        UndirectedGraphNode *father = qs.front(); qs.pop();
        UndirectedGraphNode *clone = new UndirectedGraphNode(node->label);
        clone->neighbors.push_back(father);
        father->neighbors.push_back(clone);
        set.insert(node->label);

        for (int i = 0; i < node->neighbors.size(); i++) {
          UndirectedGraphNode *nb = node->neighbors[i];
          if (set.find(nb->label) != set.end()) {
              q.push(nb);
              qs.push(clone);
          }
        }
      }

      return tmp.neighbors[0];
    }
};

int
main()
{
  UndirectedGraphNode node(-1);
  Solution solution;
  UndirectedGraphNode *res = solution.cloneGraph(&node);
  cout << res->label << endl;
}
