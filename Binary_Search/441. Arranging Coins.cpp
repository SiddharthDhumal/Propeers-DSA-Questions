#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    bool isCompleteRow(int n,int mid){
        long long row = (long long)mid * (mid + 1) / 2;

         return row <= n;     
    }

    int arrangeCoins(int n) {
         int low = 1, high = n;
         int completeRows = 0;

         while(low<=high){
            int mid = low + (high - low)/2;

            if(isCompleteRow(n,mid)==true){
                 completeRows = mid;
                 low = mid + 1;        
            }else{
                high = mid - 1;
            }
         }

         return completeRows;
    }
};