
#include <iostream>

using namespace std;

string doesTheNameMakeIt(int wellHeight, int travelDist, 
                         int slideDist, int fatigue);
#ifdef ONLINE_JUDGE
int main()
{
   while(1)
   {
      int wellHeight, travelDist, slideDist, fatigue;
      scanf("%d %d %d %d", &wellHeight, &travelDist, &slideDist, &fatigue);

      if(wellHeight == 0)
      {
         break;
      }

      printf("%s\n", doesTheNameMakeIt(wellHeight, travelDist, slideDist, fatigue).c_str());
   }

   return 0;
}
#endif

string doesTheNameMakeIt(int wellHeight, int travelDist, 
                         int slideDist, int fatiguePercent)
{
   int day = 1;
   double currentDist = 0.0;
   double dayTravel = travelDist;
   double nightTravel = slideDist;
   double fatigue = (dayTravel * (fatiguePercent / 100.0));

   while(1)
   {
      currentDist += dayTravel;
      if(currentDist > wellHeight)
      {
         return "success on day " + to_string(day);
      }

      currentDist -= nightTravel;
      if(currentDist < 0)
      {
         return "failure on day " + to_string(day);
      }

      dayTravel -= fatigue;
      dayTravel = (dayTravel < 0.0) ? 0.0 : dayTravel;
      day++;
   }

   return "";
}