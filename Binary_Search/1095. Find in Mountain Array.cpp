#include "bits/stdc++.h"
using namespace std;

/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    // TC - O(3 * log(n)) SC - O(1)
    int findPeakElement(MountainArray &mountainArr,int n){
        int low = 0;
        int high = n -1;

        while(low<high){
            int mid = low + (high-low)/2;
            if(mountainArr.get(mid)>mountainArr.get(mid+1)){
                high = mid;  
            }else{
                low = mid + 1;
            }
        }

        return low;
    }
    
    int findTargetAsc(MountainArray &mountainArr, int target, int low,int high){
        while(low<=high){
            int mid = low + (high-low)/2;
            int val = mountainArr.get(mid);

            if(val==target){
                return mid;
            }else if(val<target){
                  low = mid + 1;
            }else{
                  high = mid - 1;
            }
        }

        return -1;
    }


    int findTargetDesc(MountainArray &mountainArr, int target, int low,int high){
           while(low<=high){
            int mid = low + (high-low)/2;
            int val = mountainArr.get(mid);

            if(val==target){
                return mid;
            }else if(val<target){
                  high = mid - 1;
            }else{
                  low = mid + 1;
            }
        }

        return -1;
    }

    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        
        int peakElement = findPeakElement(mountainArr,n);
        

        int leftAns = findTargetAsc(mountainArr,target,0,peakElement);

        if(leftAns!= -1){
            return leftAns;
        }

        return findTargetDesc(mountainArr,target,peakElement+1,n-1);
    }
};