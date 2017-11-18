
#include <gtest/gtest.h>
#include "WheresWaldorf.h"

class TestWheresWaldorf : public ::testing::Test
{
protected:
   virtual void SetUp()
   {
      init(board_, words_);
   }

   virtual void TearDown()
   {
   }

   std::vector<std::string> board_ = { 
      "OjdslLkswsdnf",
      "slthissgOskfh",
      "SDlkjdifRSLdt",
      "SDfEjIhsldnaS",
      "OPKSHmtjddlsE",
      "SdlkpsJSDLsMt",
      "SLDKjmhELlofs"
   };
   std::vector<std::string> words_ = {
      "Hello", "World", "This", "Test", "Tall"
   };
};

TEST_F(TestWheresWaldorf, testConvertToLower)
{
   std::string s = "AbCdefgHIJKLMNOpQrStUVWxyz";
   std::string expectedString = "abcdefghijklmnopqrstuvwxyz";

   EXPECT_EQ(expectedString, convertStringToLower(s));
}

TEST_F(TestWheresWaldorf, testInitSetsAllCharsToLowerCase)
{
   board_ = { "aHJjdsKJlks",
              "PkjfkldsMkg",
              "LKJgdlsdSDF" };
   words_ = { "HeLlO", "WORld"};

   std::vector<std::string> expectedBoard = { "ahjjdskjlks",
                                              "pkjfkldsmkg",
                                              "lkjgdlsdsdf" };
   std::vector<std::string> expectedWords = { "hello",
                                              "world"};  

   init(board_, words_);
   EXPECT_EQ(expectedBoard, board_);
   EXPECT_EQ(expectedWords, words_);
}

TEST_F(TestWheresWaldorf, testFindWordsFindsAllWordsCorrectly)
{
   std::map<std::string, std::pair<int, int>> expectedLocations;
   expectedLocations["hello"] = std::make_pair(5, 5);
   expectedLocations["world"] = std::make_pair(1, 9);
   expectedLocations["this"] = std::make_pair(2, 3);
   expectedLocations["test"] = std::make_pair(6, 13);
   expectedLocations["tall"] = std::make_pair(3, 13);

   EXPECT_EQ(expectedLocations, findWords(board_, words_));
}

TEST_F(TestWheresWaldorf, testSearchForWordFindsWordsCorrectly)
{
   EXPECT_EQ(std::make_pair(5, 5), searchForWord(board_, words_[0]));
   EXPECT_EQ(std::make_pair(1, 9), searchForWord(board_, words_[1]));
   EXPECT_EQ(std::make_pair(2, 3), searchForWord(board_, words_[2]));
   EXPECT_EQ(std::make_pair(6, 13), searchForWord(board_, words_[3]));
   EXPECT_EQ(std::make_pair(3, 13), searchForWord(board_, words_[4]));
}

TEST_F(TestWheresWaldorf, testCheckChar)
{
   board_ = { "a" };

   EXPECT_TRUE(checkChar(board_, 'a', 0, 0));
   EXPECT_FALSE(checkChar(board_, 'b', 0, 0));
   EXPECT_FALSE(checkChar(board_, 'a', -1, 0));
   EXPECT_FALSE(checkChar(board_, 'a', 1, 0));
   EXPECT_FALSE(checkChar(board_, 'a', 0, -1));
   EXPECT_FALSE(checkChar(board_, 'a', 0, 1));
}

TEST_F(TestWheresWaldorf, testSearchForWordAroundChar)
{
   board_ = { "oghello",
              "glderll",
              "kglhltl",
              "asdegde",
              "nmhlheh",
              "hholleh",
              "eedlhek",
              "fgloljs",
              "bjgldje",
              "ghodode" };

   EXPECT_TRUE(searchForWordAroundChar(board_, "hello", 4, 4));
   EXPECT_TRUE(searchForWordAroundChar(board_, "hello", 4, 6));
   EXPECT_TRUE(searchForWordAroundChar(board_, "hello", 4, 2));
   EXPECT_TRUE(searchForWordAroundChar(board_, "hello", 4, 2));
   EXPECT_TRUE(searchForWordAroundChar(board_, "hello", 5, 6));
   EXPECT_TRUE(searchForWordAroundChar(board_, "hello", 5, 0));
}

TEST_F(TestWheresWaldorf, testCheckForWordInDirection_DiagUpBack)
{
   board_ = { "orsdg", 
              "klfjh",
              "duloe",
              "wijep",
              "werth" };

   EXPECT_TRUE(checkForWordInDirection(Direction::DiagUpBack, board_, "o", 0, 0, 0)); 
   EXPECT_TRUE(checkForWordInDirection(Direction::DiagUpBack, board_, "lo", 0, 1, 1)); 
   EXPECT_TRUE(checkForWordInDirection(Direction::DiagUpBack, board_, "llo", 0, 2, 2)); 
   EXPECT_TRUE(checkForWordInDirection(Direction::DiagUpBack, board_, "ello", 0, 3, 3)); 
   EXPECT_TRUE(checkForWordInDirection(Direction::DiagUpBack, board_, "hello", 0, 4, 4)); 
   EXPECT_FALSE(checkForWordInDirection(Direction::DiagUpBack, board_, "hello", 0, 1, 4)); 
}

TEST_F(TestWheresWaldorf, testCheckForWordInDirection_Up)
{
   board_ = { "orodg", 
              "klljh",
              "duloe",
              "wieep",
              "wehth" };

   EXPECT_TRUE(checkForWordInDirection(Direction::Up, board_, "o", 0, 0, 2)); 
   EXPECT_TRUE(checkForWordInDirection(Direction::Up, board_, "lo", 0, 1, 2)); 
   EXPECT_TRUE(checkForWordInDirection(Direction::Up, board_, "llo", 0, 2, 2)); 
   EXPECT_TRUE(checkForWordInDirection(Direction::Up, board_, "ello", 0, 3, 2)); 
   EXPECT_TRUE(checkForWordInDirection(Direction::Up, board_, "hello", 0, 4, 2)); 
   EXPECT_FALSE(checkForWordInDirection(Direction::Up, board_, "hello", 0, 4, 4)); 
}

TEST_F(TestWheresWaldorf, testCheckForWordInDirection_DiagUpFwd)
{
   board_ = { "orodo", 
              "klllh",
              "duloe",
              "weeep",
              "hehth" };

   EXPECT_TRUE(checkForWordInDirection(Direction::DiagUpFwd, board_, "o", 0, 0, 4)); 
   EXPECT_TRUE(checkForWordInDirection(Direction::DiagUpFwd, board_, "lo", 0, 1, 3)); 
   EXPECT_TRUE(checkForWordInDirection(Direction::DiagUpFwd, board_, "llo", 0, 2, 2)); 
   EXPECT_TRUE(checkForWordInDirection(Direction::DiagUpFwd, board_, "ello", 0, 3, 1)); 
   EXPECT_TRUE(checkForWordInDirection(Direction::DiagUpFwd, board_, "hello", 0, 4, 0)); 
   EXPECT_FALSE(checkForWordInDirection(Direction::DiagUpFwd, board_, "hello", 0, 4, 2)); 
}

TEST_F(TestWheresWaldorf, testCheckForWordInDirection_Back)
{
   board_ = { "orodo", 
              "olleh",
              "duloe",
              "weeep",
              "hehth" };

   EXPECT_TRUE(checkForWordInDirection(Direction::Back, board_, "o", 0, 1, 0)); 
   EXPECT_TRUE(checkForWordInDirection(Direction::Back, board_, "lo", 0, 1, 1)); 
   EXPECT_TRUE(checkForWordInDirection(Direction::Back, board_, "llo", 0, 1, 2)); 
   EXPECT_TRUE(checkForWordInDirection(Direction::Back, board_, "ello", 0, 1, 3)); 
   EXPECT_TRUE(checkForWordInDirection(Direction::Back, board_, "hello", 0, 1, 4)); 
   EXPECT_FALSE(checkForWordInDirection(Direction::Back, board_, "hello", 0, 4, 4)); 
}

TEST_F(TestWheresWaldorf, testCheckForWordInDirection_Fwd)
{
   board_ = { "orodo", 
              "klllh",
              "duloe",
              "hello",
              "hehth" };

   EXPECT_TRUE(checkForWordInDirection(Direction::Fwd, board_, "o", 0, 3, 4)); 
   EXPECT_TRUE(checkForWordInDirection(Direction::Fwd, board_, "lo", 0, 3, 3)); 
   EXPECT_TRUE(checkForWordInDirection(Direction::Fwd, board_, "llo", 0, 3, 2)); 
   EXPECT_TRUE(checkForWordInDirection(Direction::Fwd, board_, "ello", 0, 3, 1)); 
   EXPECT_TRUE(checkForWordInDirection(Direction::Fwd, board_, "hello", 0, 3, 0)); 
   EXPECT_FALSE(checkForWordInDirection(Direction::Fwd, board_, "hello", 0, 4, 0)); 
}

TEST_F(TestWheresWaldorf, testCheckForWordInDirection_DiagDownBack)
{
   board_ = { "orodh", 
              "klleh",
              "duloe",
              "hlllo",
              "oehth" };

   EXPECT_TRUE(checkForWordInDirection(Direction::DiagDownBack, board_, "o", 0, 4, 0)); 
   EXPECT_TRUE(checkForWordInDirection(Direction::DiagDownBack, board_, "lo", 0, 3, 1)); 
   EXPECT_TRUE(checkForWordInDirection(Direction::DiagDownBack, board_, "llo", 0, 2, 2)); 
   EXPECT_TRUE(checkForWordInDirection(Direction::DiagDownBack, board_, "ello", 0, 1, 3)); 
   EXPECT_TRUE(checkForWordInDirection(Direction::DiagDownBack, board_, "hello", 0, 0, 4)); 
   EXPECT_FALSE(checkForWordInDirection(Direction::Fwd, board_, "hello", 0, 1, 4)); 
}

TEST_F(TestWheresWaldorf, testCheckForWordInDirection_Down)
{
   board_ = { "oroho", 
              "klleh",
              "dulle",
              "hello",
              "hehoh" };

   EXPECT_TRUE(checkForWordInDirection(Direction::Down, board_, "o", 0, 4, 3)); 
   EXPECT_TRUE(checkForWordInDirection(Direction::Down, board_, "lo", 0, 3, 3)); 
   EXPECT_TRUE(checkForWordInDirection(Direction::Down, board_, "llo", 0, 2, 3)); 
   EXPECT_TRUE(checkForWordInDirection(Direction::Down, board_, "ello", 0, 1, 3)); 
   EXPECT_TRUE(checkForWordInDirection(Direction::Down, board_, "hello", 0, 0, 3)); 
   EXPECT_FALSE(checkForWordInDirection(Direction::Down, board_, "hello", 0, 1, 4)); 
}

TEST_F(TestWheresWaldorf, testCheckForWordInDirection_DiagDownFwd)
{
   board_ = { "hrodo", 
              "kellh",
              "duloe",
              "hello",
              "hehto" };

   EXPECT_TRUE(checkForWordInDirection(Direction::DiagDownFwd, board_, "o", 0, 4, 4)); 
   EXPECT_TRUE(checkForWordInDirection(Direction::DiagDownFwd, board_, "lo", 0, 3, 3)); 
   EXPECT_TRUE(checkForWordInDirection(Direction::DiagDownFwd, board_, "llo", 0, 2, 2)); 
   EXPECT_TRUE(checkForWordInDirection(Direction::DiagDownFwd, board_, "ello", 0, 1, 1)); 
   EXPECT_TRUE(checkForWordInDirection(Direction::DiagDownFwd, board_, "hello", 0, 0, 0)); 
   EXPECT_FALSE(checkForWordInDirection(Direction::DiagDownFwd, board_, "hello", 0, 3, 0)); 
}  

TEST_F(TestWheresWaldorf, testSampleBoardAndWords)
{
   board_ = {
      "abcDEFGhigg",
      "hEbkWalDork",
      "FtyAwaldORm",
      "FtsimrLqsrc",
      "byoArBeDeyv",
      "Klcbqwikomk",
      "strEBGadhrb",
      "yUiqlxcnBjf"
   };
   words_ = {
      "Waldorf",
      "Bambi",
      "Betty",
      "Dagbert"
   };
   
   std::map<std::string, std::pair<int, int>> expectedValues;
   expectedValues["waldorf"] = std::make_pair(2, 5);
   expectedValues["bambi"] = std::make_pair(2, 3);
   expectedValues["betty"] = std::make_pair(1, 2);
   expectedValues["dagbert"] = std::make_pair(7, 8);

   init(board_, words_);
   EXPECT_EQ(expectedValues, findWords(board_, words_));

}