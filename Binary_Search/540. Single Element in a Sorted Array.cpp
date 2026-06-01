#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int singleElementInASortedArray(vector<int>& nums) {
        
        // TC - O(log(n)) and SC - O(1)

        // int n = nums.size();
        // int low = 1;
        // int high = n - 2;

        // if(nums[0]!=nums[1]) return nums[0];
        // if(nums[n-1]!= nums[n-2]) return nums[n-1];

        // while(low<=high){
        //     int mid = low + (high-low)/2;
            
        //     if((nums[mid]!= nums[mid-1] && nums[mid]!= nums[mid+1])
        //      ){
        //         return nums[mid];
        //     }
        //     else if((mid%2==0 && nums[mid]==nums[mid+1] || (mid%2!=0 && nums[mid]==nums[mid-1]))){
        //          low = mid +1;
        //     }else if((mid%2 != 0 && nums[mid]==nums[mid+1]) || (mid%2==0 && nums[mid] == nums[mid-1])){
        //           high = mid - 1;
        //     }
        // }

        // return -1;



        int low = 0;
        int high = nums.size() -1;

        while(low<high){
             int mid = low + (high-low)/2;

             if(mid%2 == 1){
                 mid--;
             }

             if(nums[mid]==nums[mid+1]){
                 low = mid + 2;
             }else{
                 high = mid;
             }
        }

        return nums[low];
    }
};