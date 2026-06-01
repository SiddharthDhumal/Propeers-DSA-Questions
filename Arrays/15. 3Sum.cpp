#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    // TC - > O(nlogn) + O(n^2) and SC -> O(1)
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());

        vector<vector<int>>result;

        for(int i=0;i<n-2;i++){
             // Skip duplicate first elements
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int j = i+1;
            int k = n -1;
            int target = -nums[i];

            while(j<k){
                 int sum = nums[j] + nums[k];
                 if(sum==target){
                     result.push_back({nums[i],nums[j],nums[k]});
                     j++;
                     k--;

                     while(j<k && nums[j]==nums[j-1]){
                         j++;
                     }

                     while(j<k && nums[k]==nums[k+1]){
                         k--;
                     }
                 }else if(sum > target){
                      k--;
                 }else{
                      j++;
                 }
            }
        }
        
        return result;
    }
};