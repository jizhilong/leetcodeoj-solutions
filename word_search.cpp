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

#define update(condition1) if (condition1 && board[i][j] == word[len] && !mark[i][j]) {\
                                mark[i][j] = true; \
                                if (exist(board, i, j, len+1)) \
                                    return true; \
                                mark[i][j] = false;}

class Solution {
  private:
    string word;
    vector<vector<bool> > mark;
    bool exist(vector<string> &board, int i, int j, int len) {
      if (len == word.length())
        return true;

      j--;
      update(j>=0);
      j += 2;
      update(j<board[0].size());
      j--;
      i--;
      update(i>=0);
      i+=2;
      update(i<board.size());

      return false;
    }

  public:
    bool exist(vector<string> &board, string word) {
      if (word.size() == 0)
        return true;
      if (board.empty())
        return false;

      mark = vector<vector<bool> >(board.size(), vector<bool>(board[0].length(), false));
      this->word = word;

      for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].length(); j++) {
          if (board[i][j] == word[0]) {
            mark[i][j] = true;
            if (exist(board, i, j, 1))
              return true;
            mark[i][j] = false;
          }
        }
      }

      return false;
    }
};

int
main()
{
  vector<string> board = {"ABCE","SFCS", "ADEE"};
  Solution solution;
  cout << solution.exist(board, "ABCCED") << endl;
}

