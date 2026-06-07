#include "bits/stdc++.h"
using namespace std;


// TC - O(m+n) and SC - O(1)

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int left = m-1;
        int right = n -1;
        int lastIdx = m+n-1;

        while(left>=0 && right>=0){
            if(nums1[left]>nums2[right]){
                 nums1[lastIdx] = nums1[left];
                 left--;
            }else{
                 nums1[lastIdx] = nums2[right];
                 right--;
            }

            lastIdx--;
        }

        while(right>=0){
            nums1[lastIdx] = nums2[right];
            right--;
            lastIdx--;
        } 
    }
};