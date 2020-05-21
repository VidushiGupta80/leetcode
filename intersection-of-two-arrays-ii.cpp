//Intersection of Two Arrays II -> 05/21/2020 17:59
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
         int n=nums1.size(),m=nums2.size();
        map<int,int> mp;
        
        for(int i=0;i<m;i++)
            mp[nums2[i]]++;
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            if(mp.find(nums1[i])!=mp.end()&&mp[nums1[i]]>0)
            {
                ans.push_back(nums1[i]); mp[nums1[i]]--;
            }
        }
        
        return ans;
    }
};
