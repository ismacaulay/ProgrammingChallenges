
#include <iostream>
#include <vector>
#include <set>

bool isJolly(std::vector<int> elements);

#ifdef ONLINE_JUDGE
int main()
{
   int numberOfElements;
   while(std::cin >> numberOfElements)
   {
      std::vector<int> elements;
      for(int i = 0; i < numberOfElements; i++)
      {
         int element;
         std::cin >> element;

         elements.push_back(element);
      }

      if(isJolly(elements))
      {
         std::cout << "Jolly" << std::endl;;
      }
      else
      {
         std::cout << "Not jolly" << std::endl;
      }
   }

   return 0;
}
#endif

bool isJolly(std::vector<int> elements)
{
   std::set<int> differences;

   for(int i = 1; i < elements.size(); i++)
   {
      int elementOne = elements[i-1];
      int elementTwo = elements[i];

      int difference = abs(elementOne - elementTwo);
      if(0 < difference && difference < elements.size())
      {
         differences.insert(difference);
      }
   }

   return (differences.size() == (elements.size() - 1));
}