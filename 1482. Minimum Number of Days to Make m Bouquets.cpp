#include "bits/stdc++.h"
using namespace std;


class Solution {
public:
    bool isBoquetPossible(vector<int>& bloomDay,int m,int k,int mid){
          long long boquet = 0;
          long long consecutive = 0;
          for(int i=0;i<bloomDay.size();i++){
             
             if(bloomDay[i]<=mid){
                 consecutive++;
                 if(consecutive==k){
                     boquet++;
                     consecutive = 0;
                 }
             }else{
                consecutive = 0;
             }
          }

          return boquet >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if(1LL * m * k > n) return -1;
        

        int low = *min_element(bloomDay.begin(),bloomDay.end());
        int high = *max_element(bloomDay.begin(),bloomDay.end());
        int lowestBloomDayPossible = -1; 

        while(low<=high){
            int mid = low + (high-low)/2;

            if(isBoquetPossible(bloomDay,m,k,mid)){
                lowestBloomDayPossible = mid;
                high = mid -1;
            }else{
                low = mid + 1;
            }
        }

        return lowestBloomDayPossible;
    }
};