
#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

typedef std::set<char> sc;
typedef std::map<char, sc> msc;

string placeBid(msc cards);
bool allSuitsStopped(msc cards);
int checkRule1(msc cards);
int checkRule2(msc cards);
int checkRule3(msc cards);
int checkRule4(msc cards);
int checkRule5(msc cards);
int checkRule6(msc cards);
int checkRule7(msc cards);
string bidSuit(msc cards);

#ifdef ONLINE_JUDGE
int main()
{
   char cards[13][3];
   while(scanf("%s %s %s %s %s %s %s %s %s %s %s %s %s\n",
         cards[0], cards[1], cards[2], cards[3], cards[4],
         cards[5], cards[6], cards[7], cards[8], cards[9],
         cards[10], cards[11], cards[12]) == 13)
   {
      sc spades, hearts, clubs, diamonds;
      for (int i = 0; i < 13; ++i)
      {
         if(cards[i][1] == 'S')
         {
            spades.insert(cards[i][0]);
         }
         else if(cards[i][1] == 'H')
         {
            hearts.insert(cards[i][0]);
         }
         else if(cards[i][1] == 'C')
         {
            clubs.insert(cards[i][0]);
         }
         else if(cards[i][1] == 'D')
         {
            diamonds.insert(cards[i][0]);
         }
      }

      msc suitMap;
      suitMap['S'] = spades;
      suitMap['H'] = hearts;
      suitMap['C'] = clubs;
      suitMap['D'] = diamonds;

      printf("%s\n", placeBid(suitMap).c_str());
   }

   return 0;
}
#endif

string placeBid(msc cards)
{
   int points = 0;
   points += checkRule1(cards);
   points += checkRule2(cards);
   points += checkRule3(cards);
   points += checkRule4(cards);

   if(points >= 16)
   {
      if(allSuitsStopped(cards))
      {
         return "BID NO-TRUMP";
      }
   }

   points += checkRule5(cards);
   points += checkRule6(cards);
   points += checkRule7(cards);

   if(points < 14)
   {
      return "PASS";
   }

   return bidSuit(cards);
}

bool allSuitsStopped(msc cards)
{
   map<char, bool> suits;
   suits['S'] = false;
   suits['H'] = false;
   suits['C'] = false;
   suits['D'] = false;
   
   for(auto suit = cards.begin(); suit != cards.end(); suit++)
   {
      char s = suit->first;
      if(suit->second.find('A') != suit->second.end())
      {
         suits[s] = true;
         continue;
      }
      if(suit->second.find('K') != suit->second.end())
      {
         if(suit->second.size() >= 2)
         {
            suits[s] = true;
            continue;
         }
      }
      if(suit->second.find('Q') != suit->second.end())
      {
         if(suit->second.size() >= 3)
         {
            suits[s] = true;
            continue;
         }
      }
   }
   return suits['S'] && suits['H'] && suits['C'] && suits['D'];
}

int checkRule1(msc cards)
{
   int points = 0;
   for(auto suit = cards.begin(); suit != cards.end(); suit++)
   {
      sc s = suit->second;
      if(s.find('A') != s.end())
      {
         points += 4;
      }
      if(s.find('K') != s.end())
      {
         points += 3;
      }
      if(s.find('Q') != s.end())
      {
         points += 2;
      }
      if(s.find('J') != s.end())
      {
         points += 1;
      }
   }
   return points;
}

int checkRule2(msc cards)
{
   int points = 0;
   for(auto suit = cards.begin(); suit != cards.end(); suit++)
   {
      sc s = suit->second;
      if(s.find('K') != s.end())
      {
         if(s.size() == 1)
         {
            points -= 1;
         }
      }
   }

   return points;
}

int checkRule3(msc cards)
{
   int points = 0;
   for(auto suit = cards.begin(); suit != cards.end(); suit++)
   {
      sc s = suit->second;
      if(s.find('Q') != s.end())
      {
         if(s.size() <= 2)
         {
            points -= 1;
         }
      }
   }

   return points;
}

int checkRule4(msc cards)
{
   int points = 0;
   for(auto suit = cards.begin(); suit != cards.end(); suit++)
   {
      sc s = suit->second;
      if(s.find('J') != s.end())
      {
         if(s.size() <= 3)
         {
            points -= 1;
         }
      }
   }

   return points;
}

int checkRule5(msc cards)
{
   int points = 0;
   for(auto suit = cards.begin(); suit != cards.end(); suit++)
   {
      sc s = suit->second;
      if(s.size() == 2)
      {
         points += 1;
      }
   }

   return points;
}

int checkRule6(msc cards)
{
   int points = 0;
   for(auto suit = cards.begin(); suit != cards.end(); suit++)
   {
      sc s = suit->second;
      if(s.size() == 1)
      {
         points += 2;
      }
   }

   return points;
}

int checkRule7(msc cards)
{
   int points = 0;
   for(auto suit = cards.begin(); suit != cards.end(); suit++)
   {
      sc s = suit->second;
      if(s.size() == 0)
      {
         points += 2;
      }
   }

   return points;
}

string bidSuit(msc cards)
{
   int numSpades = cards['S'].size();
   int numHearts = cards['H'].size();
   int numClubs = cards['C'].size();
   int numDiamonds = cards['D'].size();

   if(numSpades >= numHearts && numSpades >= numClubs && numSpades >= numDiamonds)
   {
      return "BID S";
   }

   if(numHearts > numSpades && numHearts >= numClubs && numHearts >= numDiamonds)
   {
      return "BID H";
   }

   if(numDiamonds > numSpades && numDiamonds > numHearts && numDiamonds >= numClubs)
   {
      return "BID D";
   }

   return "BID C";

}
