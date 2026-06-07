#include "bits/stdc++.h"
using namespace std;

// TC - O(2 * n) and SC - O(1)

// class Solution {
// public:
//     void sortColors(vector<int>& nums) {
//          int zeroes = 0;
//          int ones = 0;
//          int twoes = 0;

//          for(int i=0;i<nums.size();i++){
//              if(nums[i]==0) zeroes++;
//              else if(nums[i]==1) ones++;
//              else twoes++;
//          }

//          int it = 0;

//             while(zeroes>0){
//                  nums[it] = 0;
//                  zeroes--;
//                  it++;
//             }

//             while(ones>0){
//                  nums[it] = 1;
//                  ones--;
//                  it++;
//             }

//             while(twoes>0){
//                 nums[it] = 2;
//                 twoes--;
//                 it++;
//             }
//     }
// };


// TC - O(n) and SC - O(1)

// Dutch National Flag Algorithm

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0;
        int mid = 0;
        int high = nums.size() -1;

        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[low],nums[mid]);
                low++;
                mid++;
            }else if(nums[mid]==1){
                mid++;
            }else{
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
};