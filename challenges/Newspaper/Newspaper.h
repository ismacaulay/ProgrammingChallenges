
#include <iostream>
#include <map>

using namespace std;

typedef map<char, int> mci;

#ifdef ONLINE_JUDGE
int main()
{
   int cases;
   scanf("%d", &cases);

   while(cases > 0)
   {
      int numPaidChars;
      cin >> numPaidChars;

      mci charMap;
      for(int i = 0; i < numPaidChars; i++)
      {
         char ch;
         int value;
         cin >> ch >> value;
         charMap[ch] = value;
      }

      int numLines;
      cin >> numLines;
      string tmp;
      getline(cin, tmp); // clear \n after numlines

      int value = 0;
      for(int i = 0; i < numLines; i++)
      {
         string line;
         getline(cin, line);
         for(int i = 0; i < line.size(); i++)
         {
            if(charMap.find(line[i]) != charMap.end())
            {
               value += charMap[line[i]];
            }
         }
      }

      double cost = value / 100.0;
      printf("%.2f$\n", cost);
      cases--;
   }

	return 0;
}
#endif

