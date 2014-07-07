
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

typedef vector<char> vc;

int totalScore(vc scoreCard);
int scoreCardValueToInt(char roll);

#ifdef ONLINE_JUDGE
int main()
{

   while(1)
   {
      char scores[100];
      scanf("%[^\n]\n", scores);

      if(strcmp(scores, "Game Over") == 0)
      {
         break;
      }

      vc scoreCard;
      for(int i = 0; i < strlen(scores); i++)
      {
         if(scores[i] != ' ')
         {
            scoreCard.push_back(scores[i]);
         }
      }

      printf("%d\n", totalScore(scoreCard));
   }
   return 0;
}
#endif

int totalScore(vc scoreCard)
{
   int frame = 1;
   int roll = 0;
   int total = 0;

   while(frame <= 10)
   {
      if('0' <= scoreCard[roll] && scoreCard[roll] <= '9')
      {
         if(scoreCard[roll + 1] == '/')
         {
            total += 10 + scoreCardValueToInt(scoreCard[roll + 2]);
         }
         else
         {
            total += scoreCardValueToInt(scoreCard[roll]) + scoreCardValueToInt(scoreCard[roll + 1]);
         }
         roll += 2;
      }
      else if(scoreCard[roll] == 'X')
      {
         total += 10;
         if(scoreCard[roll + 2] == '/')
         {
            total += 10;
         }
         else
         {
            total += scoreCardValueToInt(scoreCard[roll + 1]) + scoreCardValueToInt(scoreCard[roll + 2]);
         }

         roll++;
      }

      frame++;
   }

   return total;
}

int scoreCardValueToInt(char roll)
{
   if(roll == 'X' || roll == '/')
   {
      return 10;
   }

   return roll - '0';
}

