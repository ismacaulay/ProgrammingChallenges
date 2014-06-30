
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int cardFaceToInt(char card);

#ifdef ONLINE_JUDGE
int main()
{
   int cases;
   scanf("%d\n", &cases);

   for (int i = 1; i <= cases; ++i)
   {

      vector<string> cards;
      for (int card = 0; card < 52; ++card)
      {
         string c;
         cin >> c;
         cards.push_back(c);
      }

      // Cards are given back to front
      reverse(cards.begin(), cards.end());

      int y = 0;
      for(int c = 0; c < 3; c++)
      {
         int x = cardFaceToInt(cards[25][0]);
         y += x;

         // erase the cards from the pile
         cards.erase(cards.begin()+25, cards.begin() + 26 + (10 - x));
      }

      // cards are currently front to back and we want to count from the back
      reverse(cards.begin(), cards.end());

      printf("Case %d: %s\n", i, cards[y-1].c_str());
   }

   return 0;
}
#endif

int cardFaceToInt(char c)
{
   int value = 10;
   switch(c)
   {
      case '2':
      case '3':
      case '4':
      case '5':
      case '6':
      case '7':
      case '8':
      case '9':
      {
         value = c - '0';
         break;
      }
   }

   return value;
}