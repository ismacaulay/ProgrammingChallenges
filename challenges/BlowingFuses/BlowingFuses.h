
#include <iostream>
#include <vector>

using namespace std;

typedef vector<bool> vb;
typedef vector<int> vi;

bool operationBlowsFuse(int operation, vb& states, vi consumptions, 
                        int fuseCapacity, int& maxConsumption);
void toggleDevice(int device, vb& states, vi consumptions);
int calculateCurrentConsumption(vb states, vi consumptions);

#ifdef ONLINE_JUDGE
int main()
{
   int sequence = 1;
   int numDevices, numOperations, fuseCapacity;
   while(cin >> numDevices >> numOperations >> fuseCapacity)
   {
      if((numDevices == 0) && (numOperations == 0) && (fuseCapacity == 0))
      {
         break;
      }

      if(sequence > 1)
      {
         cout << endl << endl;
      }

      cout << "Sequence " << sequence << endl;
      
      vi consumptions;
      vb states;
      int deviceConsumption;
      for(int i = 0; i < numDevices; i++)
      {
         cin >> deviceConsumption;
         consumptions.push_back(deviceConsumption);
         states.push_back(0);
      }

      int operation;
      int maxConsumption = 0;
      bool fuseBlown;
      for(int i = 0; i < numOperations; i++)
      {
         cin >> operation;
         fuseBlown = operationBlowsFuse(operation - 1, states, consumptions,
                                        fuseCapacity, maxConsumption);

         if(fuseBlown)
         {
            break;
         }
      }

      if(fuseBlown)
      {
         cout << "Fuse was blown.";
      }
      else
      {
         cout << "Fuse was not blown." << endl;
         cout << "Maximal power consumption was " << maxConsumption << " amperes.";
      }

      sequence++;
   }

	return 0;
}
#endif

bool operationBlowsFuse(int operation, vb& states, vi consumptions, 
                        int fuseCapacity, int& maxConsumption)
{
   toggleDevice(operation, states, consumptions);
   int currentConsumption = calculateCurrentConsumption(states, consumptions);
   maxConsumption = max(currentConsumption, maxConsumption);

   return maxConsumption > fuseCapacity;
}

void toggleDevice(int device, vb& states, vi consumptions)
{
   states[device] = !states[device];
}

int calculateCurrentConsumption(vb states, vi consumptions)
{
   int currentConsumption = 0;
   for(int i = 0; i < states.size(); i++)
   {
      currentConsumption += (states[i] ? consumptions[i] : 0);
   }
   return currentConsumption;
}