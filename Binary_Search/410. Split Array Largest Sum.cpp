#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    bool possibleSubArray(vector<int>& nums,int k,int mid){
        long long sum = 0;
        int subArr = 1;

        for(int i=0;i<nums.size();i++){
             if(sum + nums[i] > mid){
                subArr++;
                sum = nums[i];
             }else{
                sum += nums[i];
             }
        }

        return subArr <= k;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);
        int answer = low;

        while(low<=high){
            int mid = low + (high-low)/2;

            if(possibleSubArray(nums,k,mid)){
                 answer = mid;
                 high = mid  - 1;
            }else{
                low = mid + 1;
            }
        }

        return answer;
        
    }
};