//Top K Frequent Elements -> 08/13/2020 13:22
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> freq;
        for(int i = 0; i < nums.size(); i++)
        {
            freq[nums[i]]++;
        }
        multimap<int, int> revFreq;        
        map<int, int> :: iterator it = freq.begin();
        vector<int> ans;
        
        for(; it != freq.end(); it++)
        {
            revFreq.insert(make_pair(it->second, it->first));
        }
        multimap<int, int> :: reverse_iterator itr = revFreq.rbegin();
        while(k > 0)
        {
            ans.push_back(itr->second);
            itr++; 
            k--;
        }
        return ans;
    }
};
