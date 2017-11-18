
#include <iostream>
#include <map>
#include <set>
#include <cstring>

using namespace std;

#ifdef ONLINE_JUDGE
int main()
{
   while(1)
   {
      int r;
      scanf("%d\n", &r);

      if(r == -1)
      {
         break;
      }

      char tmp[1000];
      scanf("%[^\n]\n", tmp);
      int l = strlen(tmp);

      map<char, bool> word;
      for(int i = 0; i < l; i++)
      {
         if('a' <= tmp[i] && tmp[i] <= 'z')
         {
            word[tmp[i]] = false;
         }
      }

      char guessedChars[1000];
      scanf("%[^\n]\n", guessedChars);
      l = strlen(guessedChars);

      int wrongGuesses = 0;
      set<char> guesses;
      bool correct = false;
      for(int i = 0; i < strlen(guessedChars); i++)
      {
         char guess = guessedChars[i];
         if(guesses.find(guess) == guesses.end())
         {
            guesses.insert(guess);

            if(word.find(guess) != word.end())
            {
               for(auto it = word.begin(); it != word.end(); it++)
               {
                  if(it->first == guess)
                  {
                     it->second = true;
                  }
               }

               correct = true;
               for(auto it = word.begin(); it != word.end(); it++)
               {
                  if(!it->second)
                  {
                     correct = false;
                     break;
                  }
               }

               if(correct)
               {
                  break;
               }
            }
            else
            {
               wrongGuesses++;

               if(wrongGuesses >= 7)
               {
                  break;
               }
            }
         }
      }

      printf("Round %d\n", r);
      if(correct)
      {
         printf("You win.\n");
      }
      else if(wrongGuesses >= 7)
      {
         printf("You lose.\n");
      }
      else
      {
         printf("You chickened out.\n");
      }
   }

   return 0;
}
#endif
