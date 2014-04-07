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
public:
  int lastlist;
  vector<State *> outs;

  State() {
    lastlist = -1;
  }

  virtual bool accept(char c) {
    return true;
  }

  virtual void setOut(State *node) {
    outs.push_back(node);
  }

  virtual bool isMatch() {
    return false;
  }

  virtual void clearOuts() {
    outs.clear();
  }

  virtual char getChar() {
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
  virtual char getChar() {
    return '.';
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
  virtual char getChar() {
    return ch;
  }
};

class Start : public Dot {
public:
  virtual char getChar() {
    return '^';
  }
};

class Split : public Dot {
public:
  Split (State *node) {
    outs.push_back(node);
  }

  virtual char getChar() {
    return '@';
  }

  virtual void addState(vector<State *> &list, int listid) {
    if (lastlist == listid)
      return;
    for (int i = 0; i < outs.size(); i++) {
      outs[i]->addState(list, listid);
    }
  }
};

class Match : public Dot {
public:
  virtual bool isMatch() {
    return true;
  }

  virtual char getChar() {
    return '$';
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

    void compile(const char *p) {
      start->clearOuts();
      stack<vector<State *> > stk;
      stk.push(vector<State *>(1, start));

      while (*p != '\0') {
        vector<State *> hanglings = stk.top(); stk.pop();
        switch (p[1]) {
          case '*':
            {
              State *node = p[0] == '.' ? (State *)new Dot() : (State *)new Normal(p[0]);
              State *split = new Split(node);
              node->outs.push_back(split);
              for_each (hanglings.begin(), hanglings.end(), [split](State *s){ s->setOut(split);});
              hanglings.clear();
              hanglings.push_back(split);
              stk.push(hanglings);
              p += 2;
            }
            break;
          default:
            switch (p[0]) {
              case '.':
                {
                  State *dot = (State *)new Dot();
                  for_each (hanglings.begin(), hanglings.end(), [dot](State *s){ s->setOut(dot);});
                  hanglings.clear();
                  hanglings.push_back(dot);
                  stk.push(hanglings);
                  p++;
                }
                break;
              default:
                {
                  State *normal = (State *)new Normal(p[0]);
                  for_each (hanglings.begin(), hanglings.end(), [normal](State *s){ s->setOut(normal);});
                  hanglings.clear();
                  hanglings.push_back(normal);
                  stk.push(hanglings);
                  p++;
                }
                break;
            }
        }
      }
      vector<State *> hanglings = stk.top(); stk.pop();
      for_each (hanglings.begin(), hanglings.end(), [this](State *s){ s->setOut(this->end);});
    }

    bool match(const char *s) {
      vector<vector<State *> > cache(2, vector<State *>());
      int id = 0;
      int listid = 0;
      start->outs[0]->addState(cache[id], listid);
      listid++;
      for (const char *t = s; *t != '\0'; t++, listid++) {
        int newid = id ^ 1;
        cache[newid].clear();

        for (int i = 0; i < cache[id].size(); i++) {
          State *state = cache[id][i];
          if (state->accept(*t)) {
            for (int j = 0; j < state->outs.size(); j++)
              state->outs[j]->addState(cache[newid], listid);
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
  assert(solution.isMatch("aaaaaaaaaaaaab", "a*a*a*a*a*a*a*a*a*a*a*a*b"));
  assert(!solution.isMatch("aaaaaaaaaaaaab", "a*a*a*a*a*a*a*a*a*a*c"));
  assert(solution.isMatch("", ".*"));
  assert(!solution.isMatch("", "b"));
//  assert(solution.isMatch("bca", "b+a*c*a$"));
//  assert(!solution.isMatch("ca", "b+a*c*a$"));
  assert(!solution.isMatch("", "."));
}
