#include <bits/stdc++.h>
using namespace std;


// TC - O(n) and SC - O(1)
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
         int maxLength = INT_MIN;
         int left =0 , right = 0;
         int zeroes = 0;

         while(right<nums.size()){
             if(nums[right]==0){
                 zeroes++;
                 while(zeroes>k){ 
                     if(nums[left]==0) zeroes--;
                     left++;
                 }
             }

             maxLength = max(maxLength,right-left+1);
             right++;
         }

         return maxLength;
    }
};