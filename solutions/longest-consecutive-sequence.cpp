//Longest Consecutive Sequence -> 09/04/2020 12:57
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,bool> m;
        for(int i=0;i<nums.size();i++){
            if(m.count(nums[i])==0)
            m[nums[i]] = true;
        }
        int longestSub=0;
        for(pair p:m){
            //If already taken into consideration,skip it
            if(m.count(p.first-1))
                continue;
            int count=1;
            //check if the next no. exist or not
            while(m.count(count+p.first)){
                count++;
            }
            //updates the longest subseq value
            longestSub = max(longestSub,count);
        }
        return longestSub;
    }
};
