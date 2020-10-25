//Longest Substring Without Repeating Characters -> 08/08/2020 11:49
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       // // cout << s.size() << endl;
       //  if(s.size() == 0)
       //     return 0;
       //  if(s.size() == 1)
       //      return 1;
       //  int countSub = 0;
       //  int loop = 0;
       //  map<char, int> mymap;
       //  mymap.clear();
       //  for(int i = 0; i < s.size(); i++)
       //  {
       //      char c = (char)s[i];
       //      map<char, int> :: iterator it1;
       //      it1 = mymap.find(c);
       //      if(it1 != mymap.end() && it1->second != -1)
       //      {
       //          cout << c << "index: " << i <<" " <<loop << endl;
       //          int j = mymap[c];
       //          cout << "j = " << j << endl;
       //          countSub = max(countSub, loop);
       //          map<char, int> :: iterator it = mymap.begin();
       //          for(; it != mymap.end(); it++)
       //          {
       //              if(it->second <= j)
       //                  it->second = -1;
       //          }
       //          mymap[c] = i;
       //          loop = i - j;
       //      }
       //      else if(it1 == mymap.end())
       //      {
       //          mymap[c] = i;
       //          loop++;
       //      }
       //  }
       //  countSub = max(countSub, loop);
       //  return countSub;
        
        
        if(s.size()==0)
            return 0;
        
        //Step 2: create a set
        unordered_set<char> set;
        int i=0,j=0,maxi=-1;
        
        //Step 3: Apply the usual sliding window technique
        //insert form the right and erase from left 
        //also keeping record of maximum window size 
        while(i<s.size() and j<s.size())
        {
            if(!(set.find(s[j])!=set.end()))
            {
                set.insert(s[j++]);
                maxi=max(maxi,j-i);
            }
            else
            {
                set.erase(s[i++]);
            }
        }
        return maxi;
    }
};
