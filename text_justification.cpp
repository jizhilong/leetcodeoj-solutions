/*
 * =====================================================================================
 *
 *       Filename:  text_justification.cpp
 *
 *    Description:  Given an array of words and a length L, format the text such
 *                  that each line has exactly L characters and is fully justified
 *                  You should pack your words in a greedy approach;that is, pack
 *                  as many words as you can in each line. Pad extra spaces when
 *                  necessary so that each line has exactly L characters.
 *                  Extra spaces between words should be distributed as evenly
 *                  as possible.If the number of spaces on a line do not divide
 *                  evenly between words, the empty slots on the left will be 
 *                  assigned more spaces than the slots on the right.
 *                  For the last line of text, it should be left justified and  
 *                  no extra space is inserted between words.
 *                  For example:
 *                  words: ["This", "is", "an", "example", "of", "text", "justification."].
 *                  L: 16.
 *                  Return the formatted lines as:
 *                  [
 *                    "This    is    an",
 *                    "example  of text",
 *                    "justification.  "
 *                  ]
 *
 *        Version:  1.0
 *        Created:  04/12/2014 06:19:45 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ji.Zhilong (), zhilongji@gmail.com
 *   Organization:  SJTU
 *
 * =====================================================================================
 */

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
  public:
    vector<string> fullJustify(vector<string> &words, int L) {
      int start = 0;
      int end;
      vector<string> ret;
      while (start < words.size()) {
        int l = 0;

        for (end = start;end < words.size() && (l+words[end].length()+end-start) <= L; l += words[end].length(), end++);
        end--;

        if (end == start) {
          string tmp = words[start] + string(L-words[start].length(), ' ');
          ret.push_back(tmp);
        } else if (end == words.size() - 1) {
          string tmp;
          for (int i = start; i < end; i++)
            tmp += words[i] + " ";
          tmp += words[end] + string(L - l - end + start, ' ');
          ret.push_back(tmp);
        } else {
          int len_space = (L - l) / (end - start);
          int len_long = (L - l) % (end - start);
          string tmp;
          for (int i = 0; i < len_long; i++) {
            tmp += words[start+i] + string(len_space+1, ' ');
          }
          for (int i = start + len_long; i < end; i++) {
            tmp += words[i] + string(len_space, ' ');
          }
          tmp += words[end];
          ret.push_back(tmp);
        }
        start = end+1;
      }

      return ret;
    }
};

int
main()
{
  Solution solution;
  vector<string> strs = {"This", "is", "an", "example", "of", "justification."};
  vector<string> res = solution.fullJustify(strs, 16);

  for (int i = 0; i < res.size(); i++)
    cout << res[i] << endl;
}
