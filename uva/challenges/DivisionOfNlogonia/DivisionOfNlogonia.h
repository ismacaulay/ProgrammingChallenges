
#include <iostream>

using namespace std;

string checkQuery(int x, int y, int divX, int divY);

#ifdef ONLINE_JUDGE
int main()
{
   while(true)
   {
      int numQueries;
      cin >> numQueries;

      if(numQueries == 0)
      {
         break;
      }

      int divX, divY;
      cin >> divX >> divY;

      for(int i = 0; i < numQueries; i++)
      {
         int x, y;
         cin >> x >> y;
         cout << checkQuery(x, y, divX, divY) << endl;
      }
   }

   return 0;
}
#endif

string checkQuery(int x, int y, int divX, int divY)
{
   if((x == divX) || (y == divY))
   {
      return "divisa";
   }

   if(x < divX)
   {
      if(y > divY)
      {
         return "NO";
      }
      else
      {
         return "SO";
      }
   }
   else
   {
      if(y > divY)
      {
         return "NE";
      }
      else
      {
         return "SE";
      }
   }
}