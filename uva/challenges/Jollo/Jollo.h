
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef std::vector<int> vi;

int findNextPrinceCard(int start, vi princessCards, vi princeCards);

#ifdef ONLINE_JUDGE
int main()
{
   while(1)
   {
      int princess1, princess2, princess3;
      int prince1, prince2;
      scanf("%d %d %d %d %d\n", &princess1, &princess2, &princess3, &prince1, &prince2);

      if(princess1 == 0)
      {
         break;
      }

      vi princessCards;
      princessCards.push_back(princess1);
      princessCards.push_back(princess2);
      princessCards.push_back(princess3);

      vi princeCards;
      princeCards.push_back(prince1);
      princeCards.push_back(prince2);

      sort(princessCards.begin(), princessCards.end());
      sort(princeCards.begin(), princeCards.end());

      int nextPrinceCard = -1;
      if(princeCards[0] > princessCards[2])
      {
         nextPrinceCard = findNextPrinceCard(1, princessCards, princeCards);
      }
      else if(princeCards[0] < princessCards[1])
      {
         if(princeCards[1] > princessCards[2])
         {
            nextPrinceCard = findNextPrinceCard(princessCards[2] + 1, princessCards, princeCards);
         }
      }
      else
      {
         nextPrinceCard = findNextPrinceCard(princessCards[1] + 1, princessCards, princeCards);
      }

      printf("%d\n", nextPrinceCard);
   }

   return 0;
}
#endif

int findNextPrinceCard(int start, vi princessCards, vi princeCards)
{
   int nextPrinceCard = start;
   while(find(princessCards.begin(), princessCards.end(), nextPrinceCard) != princessCards.end() ||
         find(princeCards.begin(), princeCards.end(), nextPrinceCard) != princeCards.end())
   {
      nextPrinceCard++;
      if(nextPrinceCard > 52)
      {
         nextPrinceCard = -1;
         break;
      }
   }
   return nextPrinceCard;
}