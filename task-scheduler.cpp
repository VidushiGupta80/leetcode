//Task Scheduler -> 05/29/2020 21:25
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
//         int start = 0, index = 0, i = 0, end;
//         vector<pair<int, char> > freq;
//         int lenTasks = tasks.size();
//         vector<char> schedule(lenTasks * n);
//         map<int, bool> freeSlot;
//         freeSlot.insert(make_pair(0, true));
//         vector<int> filledSlot;
        
//         sort(tasks.begin(), tasks.end());
//         int count = 1;
//         for(i = 1; i < lenTasks; i++)
//         {
//             if(tasks[i] == tasks[i - 1])
//                 count++;
//             else
//             {
//                 freq.push_back(make_pair(count, tasks[i - 1]));
//                 count = 1;
//             }
//         }
//         int lenFreq = freq.size();
//         sort(freq.begin(), freq.end());
//         for(i = 0; i < lenFreq; i++)
//         {
//             index = i;
//             while(freq[i].first > 0)
//             {
//                 if(!freeSlot[index])
//                 {
//                     while(!freeSlot[index])
//                         index++;
//                 }
//                 schedule[index] = freq[i].second;
//                 freq[i].first--;
//                 filledSlot.push_back(index);
//                 freeSlot[index] = false;
//                 int next = index + n;
//                 index++;
//                 while(index <= next)
//                 {
//                     if(freeSlot.find(index) == freeSlot.end())
//                         freeSlot.insert(make_pair(index, true));
//                     index++;
//                 }
//             }
//         }
//         map<int, bool> :: iterator it = freeSlot.begin();
//         while(it != freeSlot.end())
//         {
//             while(it->second == false)
//                 it++;
//             char c = schedule[start];
//             int check = it->first - (n + 1);
//             while(check < it->first && schedule[check] != c)
//             {
//                check++;
//             }
            
//             if(check == it->first && schedule[(it->first) - (n + 1)] != c)
//             {
//                 schedule[it->first] = c;
//                 it->second = false;
//                 start++;
//                 while(freeSlot[start])
//                     start++;
//                 it = freeSlot.begin();
                
//             }
//             else
//                 it++;
//         }
//         sort(filledSlot.begin(), filledSlot.end());
//         end = filledSlot[filledSlot.size() - 1];
//         return end - start + 1;
        
        
        
        
        vector<int> count(26,0);
        int i;
        int size = tasks.size(), intervals = 0;
        for(i = 0; i < size; i++){
            count[tasks[i] - 'A']++;
        }
        sort(count.begin(), count.end());
        //we will create slots where each slot will have different activities so that cooling period is utilized as much as possible if 
            still there will not be any different tasks then we will fill the slot with idle time
        //number of slots required to keep similar task in different slots will be 
        //maximum occuring task that will be at count[25] after sorting - 1 because we need not to worry about last exection cooling;
        int noOfSlots = count[25] - 1;
        int noOfIdleSlots = noOfSlots * n;
        //noOfIdleSlots is the gap to be filled with other tasks or idle state of the processor for eg :  A_ _ A _ _ A(if A is maxM 
            occuring then remaining blank space will be filled with B C etc tasks or idle )
        for( i = 24 ; i >= 0; i--){
            if(count[i] == 0) break;
            noOfIdleSlots -= (min(count[i], noOfSlots));
            //in case a tasks occurs as many time as max task then we again need not to worry about last time it will get executed
        }
        return noOfIdleSlots > 0 ? noOfIdleSlots + tasks.size() : tasks.size();
    }
};
