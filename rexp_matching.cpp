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

using namespace std;

enum RE_TYPE {
  NORMAL,
  DOT,
  STAR,
  PLUS,
  QUES,
  END
};

struct RE {
  RE_TYPE type;
  char  ch;
  RE(RE_TYPE t, char c) : type(t), ch(c) {};
};


class Solution {
  private:
    vector<RE> re;
    void compile2re(const char *s) {
      re.clear();
      while (*s != '\0') {
        switch (s[1]) {
          case '*':
            if (re.empty() || 
                !(re.back().ch == s[0] && 
                  (re.back().type == STAR || re.back().type == PLUS)))
              re.push_back(RE(STAR, s[0]));
            s += 2;
            break;
          case '+':
            re.push_back(RE(PLUS, s[0]));
            s += 2;
            break;
          case '?':
            re.push_back(RE(QUES, s[0]));
            s += 2;
            break;
          default:
            switch (s[0]) {
              case '.':
                re.push_back(RE(DOT, '.'));
                break;
              case '$':
                re.push_back(RE(END, '$'));
                break;
              default:
                re.push_back(RE(NORMAL, s[0]));
                break;
            }
            s++;
            break;
        }
      }
    }

    bool matchStar(char c, const char *s, int ri) {
      const char *t;
      for (t = s; *t != '\0' && (*t == c || c == '.'); t++);
      do {
        if (match(t, ri))
          return true;
      } while (t-- > s);
      return false;
    }

  bool match(const char *s, int ri) {
    if (ri == re.size())
      return s[0] == '\0';
    switch (re[ri].type) {
      case STAR:
        return matchStar(re[ri].ch, s, ri+1);
        break;
      case PLUS:
        return (s[0] == re[ri].ch || re[ri].ch == '.') && matchStar(re[ri].ch, s+1, ri+1);
        break;
      case QUES:
        return match(s, ri+1) || \
          ((s[0] == re[ri].ch || re[ri].ch == '.') ? match(s+1, ri+1) : true);
        break;
      case END:
        return s[0] == '\0';
        break;
      case NORMAL:
        if (s[0] == re[ri].ch)
      case DOT:
        return s[0] != '\0' && match(s+1, ri+1);
        break;
    }
  }

  public:
    bool isMatch(const char *s, const char *p) {
      compile2re(p);
      return match(s, 0);
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
  assert(solution.isMatch("bca", "b+a*c*a$"));
  assert(!solution.isMatch("ca", "b+a*c*a$"));
  assert(!solution.isMatch("", "."));
}
