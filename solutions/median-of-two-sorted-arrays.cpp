//Median of Two Sorted Arrays -> 05/21/2020 19:00
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        
    int n = nums1.size();
    int m = nums2.size();
    
    if(nums1.size()==0 && nums2.size()==0)return 0.0;
    
    if(nums1.size()==0){
        int mid = (nums2.size()-1)/2;
        if(nums2.size()%2==0){
            return (double)(nums2[mid]+nums2[(mid+1)])/2;
        }
        return (double)nums2[mid];
    }
    else if(nums2.size()==0)
    {
        int mid = (nums1.size()-1)/2;
        if(nums1.size()%2==0){
            return (double)(nums1[mid]+nums1[(mid+1)])/2;
        }
        return (double)nums1[mid];
    }
    if(n>m){
        return findMedianSortedArrays(nums2,nums1);
    }
    
    int low = 0;
    int high = n;
    //appling binary search on smaller arrays finding the correct place where 
    //median elements can found by partioning the arrays at different positions
    double median;
    while(low<=high){
        int partitionX = (low+high)/2;
        int partitionY = (n+m+1)/2- partitionX;
        
        int maxleftx = (partitionX==0)?INT_MIN:nums1[partitionX-1];
        int minrightx = (partitionX==n)?INT_MAX:nums1[partitionX];
        
        int maxlefty = (partitionY==0)?INT_MIN:nums2[partitionY-1];
        int minrighty = (partitionY==m)?INT_MAX:nums2[partitionY];
        
        if(maxleftx<=minrighty && maxlefty<=minrightx){
            //found the correct place
            if((n+m)%2==0){
                median = (double)(max(maxleftx,maxlefty)+min(minrighty,minrightx))/2;
            }
            else{
                median = (double)max(maxleftx,maxlefty);
            }
            break;
        }
        else if(maxleftx>minrighty){
            high = partitionX - 1;
            
        }
        else{
           low = partitionX + 1;
        }
    }
    
    return median;
    }
};
