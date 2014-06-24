
#include <iostream>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

bool validCommand(vvi blocks, int a, int b);
void performCommand(vvi& blocks, string command, int a, string action, int b);
void moveAOntoB(vvi& blocks, int a, int b);
void moveAOverB(vvi& blocks, int a, int b);
void pileAOntoB(vvi& blocks, int a, int b);
void pileAOverB(vvi& blocks, int a, int b);

void printBlocks(vvi blocks);

#ifdef ONLINE_JUDGE
int main()
{
   int numBlocks;
   cin >> numBlocks;

   vvi blocks(numBlocks);
   for(int i = 0; i < numBlocks; i++)
   {
      blocks[i].push_back(i);
   }

   while(1)
   {
      string command;
      cin >> command;

      if(command == "quit")
      {
         printBlocks(blocks);
         break;
      }

      int blockA, blockB;
      string action;
      cin >> blockA >> action >> blockB;

      performCommand(blocks, command, blockA, action, blockB);
      
   }
   return 0;
}
#endif

void performCommand(vvi& blocks, string command, int a, string action, int b)
{
   if(!validCommand(blocks, a, b))
   {
      return;
   }

   if(command == "move")
   {
      if(action == "onto")
      {
         moveAOntoB(blocks, a, b);
      }
      else if(action == "over")
      {
         moveAOverB(blocks, a, b);
      }
   }
   else if(command == "pile")
   {
      if(action == "onto")
      {
         pileAOntoB(blocks, a, b);
      }
      else if(action == "over")
      {
         pileAOverB(blocks, a, b);
      }
   }
}

bool validCommand(vvi blocks, int a, int b)
{
   if(a != b)
   {
      for(int i = 0; i < blocks.size(); i++)
      {
         vi pile = blocks[i];
         auto resultA = find(pile.begin(), pile.end(), a);
         auto resultB = find(pile.begin(), pile.end(), b);
         if((resultA != pile.end()) && (resultB != pile.end()))
         {
            return false;
         }
      }

      return true;
   }

   return false;
}

void moveAOntoB(vvi& blocks, int a, int b)
{
   for (int i = 0; i < blocks.size(); i++)
   {
      vi pile = blocks[i];
      auto blockA = find(pile.begin(), pile.end(), a);
      if(blockA != pile.end())
      {
         for(auto blockIt = blockA+1; blockIt != pile.end(); blockIt++)
         {
            blocks[*blockIt].push_back(*blockIt);
         }
         pile.erase(blockA, pile.end());
         blocks[i] = pile;
         break;
      }
   }

   for (int i = 0; i < blocks.size(); i++)
   {
      auto pile = blocks[i];
      auto blockB = find(pile.begin(), pile.end(), b);

      if(blockB != pile.end())
      {
         for(auto blockIt = blockB+1; blockIt != pile.end(); blockIt++)
         {
            blocks[*blockIt].push_back(*blockIt);
         }
         pile.erase(blockB+1, pile.end());
         pile.push_back(a);
         blocks[i] = pile;
         break;
      }
   }
}

void moveAOverB(vvi& blocks, int a, int b)
{
   for (int i = 0; i < blocks.size(); i++)
   {
      vi pile = blocks[i];
      auto blockA = find(pile.begin(), pile.end(), a);
      if(blockA != pile.end())
      {
         for(auto blockIt = blockA+1; blockIt != pile.end(); blockIt++)
         {
            blocks[*blockIt].push_back(*blockIt);
         }
         pile.erase(blockA, pile.end());
         blocks[i] = pile;
         break;
      }
   }

   for (int i = 0; i < blocks.size(); i++)
   {
      auto pile = blocks[i];
      auto blockB = find(pile.begin(), pile.end(), b);

      if(blockB != pile.end())
      {
         pile.push_back(a);
         blocks[i] = pile;
         break;
      }
   }
}

void pileAOntoB(vvi& blocks, int a, int b)
{
   for (int i = 0; i < blocks.size(); i++)
   {
      vi pileA = blocks[i];
      auto blockA = find(pileA.begin(), pileA.end(), a);
      if(blockA != pileA.end())
      {
         for (int j = 0; j < blocks.size(); j++)
         {
            auto pileB = blocks[j];
            auto blockB = find(pileB.begin(), pileB.end(), b);

            if(blockB != pileB.end())
            {
               for(auto blockIt = blockB+1; blockIt != pileB.end(); blockIt++)
               {
                  blocks[*blockIt].push_back(*blockIt);
               }
               pileB.erase(blockB+1, pileB.end());
               for(auto blockAIt = blockA; blockAIt != pileA.end(); blockAIt++)
               {
                  pileB.push_back(*blockAIt);
               }
               blocks[j] = pileB;
               break;
            }
         }

         pileA.erase(blockA, pileA.end());
         blocks[i] = pileA;
         break;
      }
   }
}

void pileAOverB(vvi& blocks, int a, int b)
{
   for (int i = 0; i < blocks.size(); i++)
   {
      vi pileA = blocks[i];
      auto blockA = find(pileA.begin(), pileA.end(), a);
      if(blockA != pileA.end())
      {
         for (int j = 0; j < blocks.size(); j++)
         {
            auto pileB = blocks[j];
            auto blockB = find(pileB.begin(), pileB.end(), b);

            if(blockB != pileB.end())
            {
               for(auto blockAIt = blockA; blockAIt != pileA.end(); blockAIt++)
               {
                  pileB.push_back(*blockAIt);
               }
               blocks[j] = pileB;
               break;
            }
         }

         pileA.erase(blockA, pileA.end());
         blocks[i] = pileA;
         break;
      }
   }
}

void printBlocks(vvi blocks)
{
   for(int i = 0; i < blocks.size(); i++)
   {
      vi pile = blocks[i];
      cout << i << ":";

      for(int j = 0; j < pile.size(); j++)
      {
         cout << " " << pile[j];
      }
      cout << endl;
   }
}

