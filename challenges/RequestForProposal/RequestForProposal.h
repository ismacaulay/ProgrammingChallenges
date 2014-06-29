
#include <iostream>
#include <string>

using namespace std;

struct Proposal
{
   char name[85];
   double value;
   int metRequirements;
};

#ifdef ONLINE_JUDGE
int main()
{
   int rfp = 1;
   while(1)
   {
      int numReqs, numProposals;
      scanf("%d %d\n", &numReqs, &numProposals);

      if(numReqs == 0 && numProposals == 0)
      {
         break;
      }

      // Blank line between rfps
      if(rfp > 1)
      {
         printf("\n");
      }

      // Get the requirements, but we dont care about them
      for (int i = 0; i < numReqs; ++i)
      {
         char tmp[85];
         scanf("%[^\n]\n", tmp);
      }

      Proposal bestProposal;
      scanf("%[^\n]\n", bestProposal.name);
      scanf("%f %d\n", &bestProposal.value, &bestProposal.metRequirements);
      for (int i = 0; i < bestProposal.metRequirements; ++i)
      {
         char tmp[85];
         scanf("%[^\n]\n", tmp);
      }

      for (int i = 1; i < numProposals; ++i)
      {
         Proposal p;
         scanf("%[^\n]\n", p.name);
         scanf("%f %d\n", &p.value, &p.metRequirements);

         if(p.metRequirements > bestProposal.metRequirements)
         {
            bestProposal = p;
         }
         else if(p.metRequirements == bestProposal.metRequirements)
         {
            if(p.value < bestProposal.value)
            {
               bestProposal = p;
            }
         }
         
         for (int i = 0; i < p.metRequirements; ++i)
         {
            char tmp[85];
            scanf("%[^\n]\n", tmp);
         }
      }

      printf("RFP #%d\n", rfp++);
      printf("%s\n", bestProposal.name);
   }

   return 0;
}
#endif
