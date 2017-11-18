
#include <iostream>
#include <string>
#include <vector>

void initBoard(std::vector<std::string>& board);
void processBoard(std::vector<std::string>& board);
void checkForMine(std::vector<std::string>& board, int row, int column);
void increment(std::vector<std::string>& board, int row, int col);
bool charIsMine(char character);
void printBoard(int field, std::vector<std::string> board);

#ifdef ONLINE_JUDGE
int main()
{
   int rows, columns;
   int field = 1;
	while(std::cin >> rows >> columns)
   {
      if(rows == 0 && columns == 0)
      {
         break;
      }

      std::vector<std::string> board;
      for(int i = 0; i < rows; i++)
      {
         std::string row;
         std::cin >> row;
         board.push_back(row);
      }

      initBoard(board);
      processBoard(board);
      printBoard(field, board); 
      field++;
   }

	return 0;
}
#endif

void initBoard(std::vector<std::string>& board)
{
   for(int row = 0; row < board.size(); row++)
   {
      for(int col = 0; col < board[0].size(); col++)
      {
         if(board[row][col] == '.')
         {
            board[row][col] = '0';
         }
      }
   }
}

void processBoard(std::vector<std::string>& board)
{
   for(int row = 0; row < board.size(); row++)
   {
      for(int column = 0; column < board[row].size(); column++)
      {
         checkForMine(board, row, column);
      }
   }
}

void checkForMine(std::vector<std::string>& board, int row, int column)
{
   if(board[row][column] == '*')
   {
      for(int rowOffset = -1; rowOffset <= 1; rowOffset++)
      {
         for(int colOffset = -1; colOffset <= 1; colOffset++)
         {
            increment(board, row+rowOffset, column+colOffset);
         }
      }
   }    
}

void increment(std::vector<std::string>& board, int row, int col)
{
   if(row >= 0 && row < board.size())
   {
      if(col >= 0 && col < board[0].size())
      {
         if(!charIsMine(board[row][col]))
         {
            board[row][col]++;
         }
      }
   }
}

bool charIsMine(char character)
{
   return (character == '*');
}

void printBoard(int field, std::vector<std::string> board)
{
   if(field != 1)
   {
      std::cout << std::endl;
   }

   std::cout << "Field #" << field << ":" << std::endl;
   for(auto row = board.begin(); row != board.end(); row++)
   {
      std::cout << *row << std::endl;
   }
}
