
#include <gtest/gtest.h>
#include "Minesweeper.h"

TEST(TestMinesweeper, testInitBoardSetsNonMinesToZero)
{
   {
      std::vector<std::string> board{"...","...","..."};
      std::vector<std::string> expectedBoard{"000","000","000"};
      initBoard(board);
      EXPECT_EQ(board, expectedBoard);
   }
   {
      std::vector<std::string> board{"*..","..*","*.."};
      std::vector<std::string> expectedBoard{"*00","00*","*00"};
      initBoard(board);
      EXPECT_EQ(board, expectedBoard);
   }
   {
      std::vector<std::string> board{"..*","*..","..*"};
      std::vector<std::string> expectedBoard{"00*","*00","00*"};
      initBoard(board);
      EXPECT_EQ(board, expectedBoard);
   }
   {
      std::vector<std::string> board{".*.",".*.",".*."};
      std::vector<std::string> expectedBoard{"0*0","0*0","0*0"};
      initBoard(board);
      EXPECT_EQ(board, expectedBoard);
   }
   {
      std::vector<std::string> board{"***","***","***"};
      std::vector<std::string> expectedBoard{"***","***","***"};
      initBoard(board);
      EXPECT_EQ(board, expectedBoard);
   }
   
}

TEST(TestMinesweeper, testCheckForMine)
{
   {
      std::vector<std::string> board{"*00", "000", "000"};
      std::vector<std::string> expectedBoard{"*10", "110", "000"};
      checkForMine(board, 0, 0);
      EXPECT_EQ(board, expectedBoard);
   }
   {
      std::vector<std::string> board{"0*0", "000", "000"};
      std::vector<std::string> expectedBoard{"1*1", "111", "000"};
      checkForMine(board, 0, 1);
      EXPECT_EQ(board, expectedBoard);
   }
   {
      std::vector<std::string> board{"00*", "000", "000"};
      std::vector<std::string> expectedBoard{"01*", "011", "000"};
      checkForMine(board, 0, 2);
      EXPECT_EQ(board, expectedBoard);
   }
   {
      std::vector<std::string> board{"000", "*00", "000"};
      std::vector<std::string> expectedBoard{"110", "*10", "110"};
      checkForMine(board, 1, 0);
      EXPECT_EQ(board, expectedBoard);
   }
   {
      std::vector<std::string> board{"000", "0*0", "000"};
      std::vector<std::string> expectedBoard{"111", "1*1", "111"};
      checkForMine(board, 1, 1);
      EXPECT_EQ(board, expectedBoard);
   }
   {
      std::vector<std::string> board{"000", "00*", "000"};
      std::vector<std::string> expectedBoard{"011", "01*", "011"};
      checkForMine(board, 1, 2);
      EXPECT_EQ(board, expectedBoard);
   }
   {
      std::vector<std::string> board{"000", "000", "*00"};
      std::vector<std::string> expectedBoard{"000", "110", "*10"};
      checkForMine(board, 2, 0);
      EXPECT_EQ(board, expectedBoard);
   }
   {
      std::vector<std::string> board{"000", "000", "0*0"};
      std::vector<std::string> expectedBoard{"000", "111", "1*1"};
      checkForMine(board, 2, 1);
      EXPECT_EQ(board, expectedBoard);
   }
   {
      std::vector<std::string> board{"000", "000", "00*"};
      std::vector<std::string> expectedBoard{"000", "011", "01*"};
      checkForMine(board, 2, 2);
      EXPECT_EQ(board, expectedBoard);
   }
}

TEST(TestMinesweeper, testProcessBoardWithSingleMine)
{
   {
      std::vector<std::string> board{"*..", "...", "..."};
      std::vector<std::string> expectedBoard{"*10", "110", "000"};
      initBoard(board);
      processBoard(board);
      EXPECT_EQ(board, expectedBoard);
   }
   {
      std::vector<std::string> board{".*.", "...", "..."};
      std::vector<std::string> expectedBoard{"1*1", "111", "000"};
      initBoard(board);
      processBoard(board);
      EXPECT_EQ(board, expectedBoard);
   }
   {
      std::vector<std::string> board{"..*", "...", "..."};
      std::vector<std::string> expectedBoard{"01*", "011", "000"};
      initBoard(board);
      processBoard(board);
      EXPECT_EQ(board, expectedBoard);
   }
   {
      std::vector<std::string> board{"...", "*..", "..."};
      std::vector<std::string> expectedBoard{"110", "*10", "110"};
      initBoard(board);
      processBoard(board);
      EXPECT_EQ(board, expectedBoard);
   }
   {
      std::vector<std::string> board{"...", ".*.", "..."};
      std::vector<std::string> expectedBoard{"111", "1*1", "111"};
      initBoard(board);
      processBoard(board);
      EXPECT_EQ(board, expectedBoard);
   }
   {
      std::vector<std::string> board{"...", "..*", "..."};
      std::vector<std::string> expectedBoard{"011", "01*", "011"};
      initBoard(board);
      processBoard(board);
      EXPECT_EQ(board, expectedBoard);
   }
   {
      std::vector<std::string> board{"...", "...", "*.."};
      std::vector<std::string> expectedBoard{"000", "110", "*10"};
      initBoard(board);
      processBoard(board);
      EXPECT_EQ(board, expectedBoard);
   }
   {
      std::vector<std::string> board{"...", "...", ".*."};
      std::vector<std::string> expectedBoard{"000", "111", "1*1"};
      initBoard(board);
      processBoard(board);
      EXPECT_EQ(board, expectedBoard);
   }
   {
      std::vector<std::string> board{"...", "...", "..*"};
      std::vector<std::string> expectedBoard{"000", "011", "01*"};
      initBoard(board);
      processBoard(board);
      EXPECT_EQ(board, expectedBoard);
   }
}

TEST(TestMinesweeper, testProcessBoardWithMultipleMines)
{
   {
      std::vector<std::string> board{"*..", 
                                     "...", 
                                     "..*"};
      std::vector<std::string> expectedBoard{"*10", "121", "01*"};
      initBoard(board);
      processBoard(board);
      EXPECT_EQ(board, expectedBoard);
   }
   {
      std::vector<std::string> board{"*..", 
                                     ".*.", 
                                     "..*"};
      std::vector<std::string> expectedBoard{"*21", "2*2", "12*"};
      initBoard(board);
      processBoard(board);
      EXPECT_EQ(board, expectedBoard);
   }
   {
      std::vector<std::string> board{"..*", 
                                     "...", 
                                     "*.."};
      std::vector<std::string> expectedBoard{"01*", "121", "*10"};
      initBoard(board);
      processBoard(board);
      EXPECT_EQ(board, expectedBoard);
   }
   {
      std::vector<std::string> board{"*.*", 
                                     "...", 
                                     "*.*"};
      std::vector<std::string> expectedBoard{"*2*", "242", "*2*"};
      initBoard(board);
      processBoard(board);
      EXPECT_EQ(board, expectedBoard);
   }
   {
      std::vector<std::string> board{"***", 
                                     "*.*", 
                                     "***"};
      std::vector<std::string> expectedBoard{"***", "*8*", "***"};
      initBoard(board);
      processBoard(board);
      EXPECT_EQ(board, expectedBoard);
   }
   {
      std::vector<std::string> board{"........*.*.*...."};
      std::vector<std::string> expectedBoard{"00000001*2*2*1000"};
      initBoard(board);
      processBoard(board);
      EXPECT_EQ(board, expectedBoard);
   }
   {
      std::vector<std::string> board{"*....*...",
                                     "*.*..**..",
                                     "..*.....*",
                                     "***....*."};
      std::vector<std::string> expectedBoard{"*3112*310",
                                             "*4*22**21",
                                             "36*31233*",
                                             "***2001*2"};
      initBoard(board);
      processBoard(board);
      EXPECT_EQ(board, expectedBoard);
   }
   {
      std::vector<std::string> board{"*"};
      std::vector<std::string> expectedBoard{"*"};
      initBoard(board);
      processBoard(board);
      EXPECT_EQ(board, expectedBoard);
   }
   {
      std::vector<std::string> board{"*...**..*",
                                     "*.*.***.."};
      std::vector<std::string> expectedBoard{"*313**32*",
                                             "*3*3***21"};
      initBoard(board);
      processBoard(board);
      EXPECT_EQ(board, expectedBoard);
   }
   {
      std::vector<std::string> board{"....",
                                     "**..",
                                     "..*.",
                                     "...."};
      std::vector<std::string> expectedBoard{"2210",
                                             "**21",
                                             "23*1",
                                             "0111"};
      initBoard(board);
      processBoard(board);
      EXPECT_EQ(board, expectedBoard);
   }

}
