
#include <iostream>

int maxCyclesForRange(int start, int end);
int numberOfCycles(int number);
bool isOdd(int number);
int maxNumber(int num1, int num2);

#ifdef ONLINE_JUDGE
int main()
{
   int start, end;
	while(std::cin >> start >> end)
   {
      std::cout << start << " " << end << " " << maxCyclesForRange(start, end) << std::endl;
   }

	return 0;
}
#endif

int maxCyclesForRange(int start, int end)
{
   int lowest = start;
   int highest = end;
   if(start > end)
   {
      lowest = end;
      highest = start;
   }

   int maxCycles = 1;
   while(lowest < highest)
   {
      int numCycles = numberOfCycles(lowest);
      maxCycles = maxNumber(maxCycles, numCycles);
      lowest++;
   }

   return maxCycles;
}

int numberOfCycles(int number)
{
   int count = 1;
   while(number > 1)
   {
      if(isOdd(number))
      {
         number = (3 * number) + 1;
      }
      else
      {
         number = (number / 2);
      }
      count++;
   }
   return count;
}

bool isOdd(int number)
{
   return (number % 2) != 0;
}

int maxNumber(int num1, int num2)
{
   return (num1 > num2) ? num1 : num2;
}