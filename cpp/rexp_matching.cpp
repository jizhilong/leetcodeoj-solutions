/*
 * =====================================================================================
 *
 *       Filename:  rexp_matching.cpp
 *
 *    Description:  Implement regular expression matching with support for '.' and '*'
 *
 *        Version:  1.0
 *        Created:  04/05/2014 12:51:40 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ji.Zhilong (), zhilongji@gmail.com
 *   Organization:  SJTU
 *
 * =====================================================================================
 */

#include <assert.h>
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>

using namespace std;

class State {
protected:
  int lastlist;
public:
  State *out;

  State() {
    lastlist = -1;
  }

  virtual bool accept(char c) {
    return false;
  }

  virtual void setOut(State *node) {
    out = node;
  }

  virtual void setOut(State *node, State *node1) {
  }

  virtual bool isMatch() {
    return false;
  }

  virtual void addState(vector<State *> &list, int listid) {
    if (lastlist == listid)
      return;
     lastlist = listid;
     list.push_back(this);
  }
};

class Dot : public State {
public:
  virtual bool accept(char c) {
    return true;
  }
};

class Normal : public State {
protected:
  char ch;

public:
  Normal(char c): ch(c) {}

  virtual bool accept(char c) {
    return c == ch;
  }
};

class Start : public State {
};

class Split : public State {
public:
  State *out1;
  Split (State *node) {
    out = node;
  }

  virtual void setOut(State *node) {
    out1 = node;
  }
  virtual void addState(vector<State *> &list, int listid) {
    if (lastlist == listid)
      return;
   out->addState(list, listid);
   out1->addState(list, listid);
  }
};

class Match : public State {
public:
  virtual bool isMatch() {
    return true;
  }
};

class RE {
  private:
    State *start, *end;
    int numStates;
  public:
    RE(const char *p) {
      start = new Start();
      end = new Match();
      numStates = 0;
      compile(p);
    }

    void compile(const char *s) {
      stack<vector<State *> > stk;
      stk.push(vector<State *>(1, start));

#define fix_hanglings(node, tail)  for_each (hanglings.begin(), hanglings.end(), [node](State *s){ s->setOut(node);});\
                                  hanglings.clear();\
                                  hanglings.push_back(tail);\
                                  stk.push(hanglings);
      const char *p = s;

      while (*p != '\0') {
        vector<State *> hanglings = stk.top(); stk.pop();
        State *node, *tmp;
        switch (p[1]) {
          case '*':
            if ((p >= s+2) && 
                ((*(p-2) == '.' || *(p-2) == *p) && 
                 (*(p-1) == '*' || *(p-1) == '+'))) {
              stk.push(hanglings);
            } else {
              tmp = p[0] == '.' ? (State *)new Dot() : (State *)new Normal(p[0]);
              node= new Split(tmp);
              tmp->setOut(node);
              fix_hanglings(node, node);
            }
            p += 2;
            break;
          case '+':
            tmp = p[0] == '.' ? (State *)new Dot() : (State *)new Normal(p[0]);
            node= new Split(tmp);
            tmp->setOut(node);
            fix_hanglings(tmp, node);
            p += 2;
            break;
          default:
            switch (p[0]) {
              case '.':
                node = (State *)new Dot();
                fix_hanglings(node, node);
                p++;
                break;
              default:
                node = (State *)new Normal(p[0]);
                fix_hanglings(node, node);
                p++;
                break;
            }
        }
      }
#undef fix_hanglings
      vector<State *> hanglings = stk.top(); stk.pop();
      for_each (hanglings.begin(), hanglings.end(), [this](State *s){ s->setOut(this->end);});
      start = start->out;
    }

    bool match(const char *s) {
      vector<vector<State *> > cache(2, vector<State *>());
      int id = 0;
      int listid = 1;
      start->addState(cache[id], 0);
      for (const char *t = s; *t != '\0'; t++, listid++) {
        int newid = id ^ 1;
        cache[newid].clear();

        for (int i = 0; i < cache[id].size(); i++) {
          State *state = cache[id][i];
          if (state->accept(*t) && state->out) {
            state->out->addState(cache[newid], listid);
          }
        }
        id = newid;
      }

      for (int i = 0; i < cache[id].size(); i++) {
        if (cache[id][i]->isMatch())
          return true;
      }

      return false;
  }
};


class Solution {
  public:
    bool isMatch(const char *s, const char *p) {
      RE re(p);
      return re.match(s);
    }
};

int
main()
{
  Solution solution;
  assert(!solution.isMatch("aa", "a"));
  assert(solution.isMatch("aa", "aa"));
  assert(!solution.isMatch("aaa", "a"));
  assert(solution.isMatch("aa", "a*"));
  assert(solution.isMatch("aa", ".*"));
  assert(solution.isMatch("ab", ".*"));
  assert(solution.isMatch("aab", "c*a*b"));
  assert(solution.isMatch("a", "ab*"));
  assert(solution.isMatch("aa", "a*c*a"));
  assert(solution.isMatch("aaaaaaaaaaaaab", "a*a*b"));
  assert(!solution.isMatch("aaaaaaaaaaaaab", "a*a*a*a*a*a*a*a*a*a*c"));
  assert(solution.isMatch("", ".*"));
  assert(!solution.isMatch("", "b"));
  assert(solution.isMatch("bca", "b+a*c*a"));
  assert(!solution.isMatch("ca", "b+a*c*a"));
  assert(!solution.isMatch("", "."));
}
