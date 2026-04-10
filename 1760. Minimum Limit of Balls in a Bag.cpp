#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    // Check if we can make every bag size <= mid using at most maxOperations splits.
    // Think of 'mid' as our "target penalty" — the maximum bag size we allow.
    bool isPossible(vector<int>& nums,int maxOperations, int mid){
         long long totalOps = 0; // total number of operations needed

         
         for(int& num:nums){
            // If a bag has 'num' balls, how many splits are needed so that
            // no resulting bag exceeds 'mid'?
            // Example: num = 9, mid = 3 → we need 2 splits (9 → 6+3 → 3+3+3).
            int ops = num/mid;
            
            // If num divides evenly by mid, we overcount by one split,
            // so subtract 1. (Because splitting into equal parts doesn't
            // require that last extra cut.)
            if(num%mid==0){
                ops -= 1;
            }

            totalOps += ops;
            
            // If we already exceed the allowed operations, no need to continue.
            if(totalOps>maxOperations) return false;
         }
         // If total required splits fit within our budget, 'mid' is achievable.
         return totalOps <= maxOperations;
    }
  
    int minimumSize(vector<int>& nums, int maxOperations) {
        // Search space: penalty can range from 1 to max(nums)

        int low = 1;
        int high = *max_element(nums.begin(),nums.end());

        int result = 0; // store the best (minimum) penalty found

        // Binary search to find the smallest penalty that is achievable
        while(low<=high){
            int mid = low + (high-low)/2; // candidate penalty

            // Check if penalty 'mid' is achievable
            if(isPossible(nums,maxOperations,mid)==true){
                result = mid; // record this as a valid answer
                high = mid -1; // try to find an even smaller penalty

            }else{
                low = mid + 1; // penalty too small, increase it

            }
        }

        return result;  // smallest achievable penalty
    }
};