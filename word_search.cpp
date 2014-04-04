/*
 * =====================================================================================
 *
 *       Filename:  word_search.cpp
 *
 *    Description:  Given a 2D board and a word, find if the word exists in the grid
 *                  The word can be constructed from letters of sequentially adjacent cell,
 *                  where "adjacent" cells are those horizontally or vertically 
 *                  neighboring.The same letter cell may not be used more than once.
 *                  For example.
 *                  Given board = 
 *                      [
 *                        ["ABCE"],
 *                        ["SFCS"],
 *                        ["ADEE"]
 *                      ]
 *                  word = "ABCCED", -> returns true,
 *                  word = "SEE", -> returns true,
 *                  word = "ABCB", -> return false.
 *
 *        Version:  1.0
 *        Created:  04/04/2014 03:55:48 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ji.Zhilong (), zhilongji@gmail.com
 *   Organization:  SJTU
 *
 * =====================================================================================
 */

#include <iostream>
#include <string>
#include <queue>

using namespace std;

class Solution {
  public:
    bool exist(vector<string> &board, string word) {
      vector<vector<bool> > mark(board.size(), vector<bool>(board[0].length(), false));
      queue<int> is;
      queue<int> js;
      queue<int> lens;
      queue<vector<vector<bool> > > marks;

      for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].length(); j++) {
          if (board[i][j] == word[0]) {
            is.push(i);
            js.push(j);
            lens.push(1);
            vector<vector<bool> > tmpmark = mark;
            tmpmark[i][j] = true;
            marks.push(tmpmark);
          }
        }
      }

      while (!is.empty()) {
        int i = is.front(); is.pop();
        int j = js.front(); js.pop();
        int len = lens.front(); lens.pop();
        vector<vector<bool> > tmpmark = marks.front(); marks.pop();

        if (len == word.length())
          return true;

        if (j-1>=0 && board[i][j-1] == word[len] && !tmpmark[i][j-1]) {
          is.push(i); js.push(j-1);lens.push(len+1);
          vector<vector<bool> > tmp = tmpmark;
          tmp[i][j-1] = true;
          marks.push(tmp);
        }

        if (j+1<board[0].size() && board[i][j+1] == word[len] && !tmpmark[i][j+1]) {
          is.push(i); js.push(j+1);lens.push(len+1);
          vector<vector<bool> > tmp = tmpmark;
          tmp[i][j+1] = true;
          marks.push(tmp);
        }

        if (i-1>=0 && board[i-1][j] == word[len] && !tmpmark[i-1][j]) {
          is.push(i-1); js.push(j);lens.push(len+1);
          vector<vector<bool> > tmp = tmpmark;
          tmp[i-1][j] = true;
          marks.push(tmp);
        }

        if (i+1<board.size() && board[i+1][j] == word[len] && !tmpmark[i+1][j]) {
          is.push(i+1); js.push(j);lens.push(len+1);
          vector<vector<bool> > tmp = tmpmark;
          tmp[i+1][j] = true;
          marks.push(tmp);
        }
      }

      return false;
    }
};

int
main()
{
  vector<string> board = {"ABCE", "SFCS", "ADEE"};
  Solution solution;
  cout << solution.exist(board, "ABCCED") << endl;
  cout << solution.exist(board, "SEE") << endl;
  cout << solution.exist(board, "ABCB") << endl;
}

