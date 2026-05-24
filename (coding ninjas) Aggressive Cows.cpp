#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    bool isDistancePossible(vector<int>& nums,int k,int maxDist){
         int lastPlaced = nums[0];
         int cow = 1;

         for(int i=1;i<nums.size();i++){
             if(nums[i] - lastPlaced >= maxDist){
                 lastPlaced = nums[i];
                 cow++;
             }

             if(cow>=k) return true;
         }

         return false;
    }
    
    int aggressiveCows(vector<int>& nums,int k) {
        sort(nums.begin(),nums.end());
        int low = 1;
        int high = nums.back() - nums.front();
        int answer = 0;

        while(low<=high){
            int mid = low + (high-low)/2;

            if(isDistancePossible(nums,k,mid)){
                 answer = mid;
                 low = mid + 1;
            }else{
                 high = mid - 1;
            }
        }

        return answer;
    }
};