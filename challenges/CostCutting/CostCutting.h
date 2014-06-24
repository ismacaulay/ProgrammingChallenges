
#include <iostream>
#include <algorithm>

using namespace std;

typedef std::vector<int> vi;

int keep(int first, int second, int third);

#ifdef ONLINE_JUDGE
int main()
{
   int cases;
   cin >> cases;

   for (int i = 1; i <= cases; ++i)
   {
      int first, second, third;
      cin >> first >> second >> third;

      cout << "Case " << i << ": " << keep(first, second, third) << endl;
   }
   return 0;
}
#endif

int keep(int first, int second, int third)
{
   vi all = { first, second, third };
   sort(all.begin(), all.end());
   return all[1];
}
