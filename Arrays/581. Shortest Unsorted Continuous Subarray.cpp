#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        // TC - O(nlogn) SC - O(n)
        
        // int n = nums.size();
        // vector<int> sortedNums = nums;
        // sort(sortedNums.begin(),sortedNums.end());

        // int left = 0;
        // int right = n - 1;

        // while(left<n && sortedNums[left]==nums[left]){
        //      left++;
        // }

        // while(right>left && sortedNums[right]==nums[right]){
        //      right--;
        // }

        // return (left==n) ? 0 : right-left+1;

    
//----------------------------------------------------------------------------------------
        
        // TC - O(n) and SC - O(1)

        int left = -1;
        int right = -1;
        int n = nums.size();
        int maxSeen = nums[0];

        for(int i=1;i<n;i++){
            maxSeen = max(nums[i],maxSeen);
            
            if(nums[i]<maxSeen){
                 right = i;
            }
        }

        if(right==-1) return 0;

        int minSeen = nums[n-1];

        for(int i=n-2;i>=0;i--){
            minSeen = min(nums[i],minSeen);

            if(nums[i]>minSeen){
                left = i;
            }
        }

        return right - left + 1;     
    }
};