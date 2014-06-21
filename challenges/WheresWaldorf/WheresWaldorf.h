
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>

using namespace std;

enum class Direction
{
   DiagUpBack, 
   Up, 
   DiagUpFwd,
   Back, 
   Fwd,
   DiagDownBack, 
   Down, 
   DiagDownFwd
};
vector<Direction> allDirections = { 
   Direction::DiagUpBack, Direction::Up, Direction::DiagUpFwd,
   Direction::Back, Direction::Fwd,
   Direction::DiagDownBack, Direction::Down, Direction::DiagDownFwd
};

void init(vector<string>& board, vector<string>& words);
map<string, pair<int, int>> findWords(vector<string> board, 
                                      vector<string> words);
pair<int, int>  searchForWord(vector<string> board, string word);
bool searchForWordAroundChar(vector<string> board, string word, int row, int col);
bool checkForWordInDirection(Direction d, vector<string> b, string w, 
                             int i, int r, int c);
bool checkChar(vector<string> board, char c, int row, int col);
string convertStringToLower(string s);

#ifdef ONLINE_JUDGE
int main()
{
   int cases = 0;
   cin >> cases;

   while(cases > 0)
   {
      int rows, columns;
      cin >> rows >> columns;

      vector<string> board;
      for(int row = 0; row < rows; row++)
      {
         string s;
         cin >> s;
         board.push_back(s);
      }

      int numWords;
      cin >> numWords;

      vector<string> words;
      for(int i = 0; i < numWords; i++)
      {
         string w;
         cin >> w;
         words.push_back(w);
      }

      init(board, words);
      map<string, pair<int, int>> locations = findWords(board, words);

      for(auto w : words)
      {
         cout << locations[w].first << " " << locations[w].second << endl;
      }

      cases--;

      if(cases != 0)
      {
         cout << endl;
      }
   }

	return 0;
}
#endif

void init(vector<string>& board, vector<string>& words)
{
   for_each(board.begin(), board.end(), [&](string& s){ s = convertStringToLower(s); });
   for_each(words.begin(), words.end(), [&](string& s){ s = convertStringToLower(s); });
}

map<string, pair<int, int>> findWords(vector<string> board, 
                                      vector<string> words)
{
   map<string, pair<int, int>> locations;

   for(auto w : words)
   {
      locations[w] = searchForWord(board, w);
   }

   return locations;
}

pair<int, int> searchForWord(vector<string> board, string word)
{
   int rows = board.size();
   int cols = board[0].size();

   for(int r = 0; r < rows; r++)
   {
      for(int c = 0; c < cols; c++)
      {
         char firstChar = word[0];
         if (board[r][c] == firstChar)
         {
            if(searchForWordAroundChar(board, word, r, c))
            {
               return make_pair(r+1, c+1);
            }
         }
      }
   }

   return make_pair(0, 0);
}

bool searchForWordAroundChar(vector<string> board, string word,
                             int row, int col)
{
   for(auto d : allDirections)
   {
      if(checkForWordInDirection(d, board, word, 0, row, col))
      {
         return true;
      }
   } 

   return false;
}

bool checkForWordInDirection(Direction d, vector<string> b, string w, 
                             int i, int r, int c)
{
   if(i < w.size())
   {
      if(checkChar(b, w[i], r, c))
      {
         switch(d)
         {
            case Direction::DiagUpBack:
            {
               return checkForWordInDirection(d, b, w, i+1, r-1, c-1);
               break;
            }
            case Direction::Up:
            {
               return checkForWordInDirection(d, b, w, i+1, r-1, c);
               break;
            }
            case Direction::DiagUpFwd:
            {
               return checkForWordInDirection(d, b, w, i+1, r-1, c+1);
               break;
            }
            case Direction::Back:
            {
               return checkForWordInDirection(d, b, w, i+1, r, c-1);
               break;
            }
            case Direction::Fwd:
            {
               return checkForWordInDirection(d, b, w, i+1, r, c+1);
               break;
            }
            case Direction::DiagDownBack:
            {
               return checkForWordInDirection(d, b, w, i+1, r+1, c-1);
               break;
            }
            case Direction::Down:
            {
               return checkForWordInDirection(d, b, w, i+1, r+1, c);
               break;
            }
            case Direction::DiagDownFwd:
            {
               return checkForWordInDirection(d, b, w, i+1, r+1, c+1);
               break;
            }
         }
      }
   }
   else
   {
      return true;
   }

   return false;
}

bool checkChar(vector<string> board, char c, int row, int col)
{
   if(0 <= row && row < board.size())
   {
      if(0 <= col && col < board[0].size())
      {
         return (c == board[row][col]);
      }
   }
   return false;
}

string convertStringToLower(string s)
{
   transform(s.begin(), s.end(), s.begin(), ::tolower);
   return s;
}