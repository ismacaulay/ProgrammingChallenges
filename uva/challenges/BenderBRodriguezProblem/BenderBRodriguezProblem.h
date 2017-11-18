
#include <iostream>
#include <vector>

using namespace std;

typedef std::vector<string> vs;

string bendWire(vs bends);
string bendWire(string currentDirection, string bend);

#ifdef ONLINE_JUDGE
int main()
{
   while(1)
   {
      int wireLength;
      scanf("%d\n", &wireLength);

      if(wireLength == 0)
      {
         break;
      }

      vs bends;
      for (int i = 0; i < wireLength-1; ++i)
      {
         string bend;
         cin >> bend;
         bends.push_back(bend);
      }

      printf("%s\n", bendWire(bends).c_str());

   }
   return 0;
}
#endif

string bendWire(vs bends)
{
   string currentDirection = "+x";
   for(int i = 0; i < bends.size(); i++)
   {
      currentDirection = bendWire(currentDirection, bends[i]);
   }

   return currentDirection;
}

string bendWire(string currentDirection, string bend)
{
   if(currentDirection == "+x")
   {
      if(bend == "+y")
      {
         return "+y";
      }
      else if(bend == "-y")
      {
         return "-y";
      }
      else if(bend == "+z")
      {
         return "+z";
      }
      else if(bend == "-z")
      {
         return "-z";
      }
   }
   else if(currentDirection == "-x")
   {
      if(bend == "+y")
      {
         return "-y";
      }
      else if(bend == "-y")
      {
         return "+y";
      }
      else if(bend == "+z")
      {
         return "-z";
      }
      else if(bend == "-z")
      {
         return "+z";
      }
   }
   else if(currentDirection == "+y")
   {
      if(bend == "+y")
      {
         return "-x";
      }
      else if(bend == "-y")
      {
         return "+x";
      }
      else if(bend == "+z")
      {
         return "+y";
      }
      else if(bend == "-z")
      {
         return "+y";
      }
   }
   else if(currentDirection == "-y")
   {
      if(bend == "+y")
      {
         return "+x";
      }
      else if(bend == "-y")
      {
         return "-x";
      }
      else if(bend == "+z")
      {
         return "-y";
      }
      else if(bend == "-z")
      {
         return "-y";
      }
   }
   else if(currentDirection == "+z")
   {
      if(bend == "+y")
      {
         return "+z";
      }
      else if(bend == "-y")
      {
         return "+z";
      }
      else if(bend == "+z")
      {
         return "-x";
      }
      else if(bend == "-z")
      {
         return "+x";
      }
   }
   else if(currentDirection == "-z")
   {
      if(bend == "+y")
      {
         return "-z";
      }
      else if(bend == "-y")
      {
         return "-z";
      }
      else if(bend == "+z")
      {
         return "+x";
      }
      else if(bend == "-z")
      {
         return "-x";
      }
   }
   return currentDirection;
}
