#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    bool isPossibleToFinish(vector<int>& piles,int h,int speed){
        
        long long hours = 0;

        for(int bananas : piles){
            hours += (bananas + speed - 1) / speed;
        }


        return hours <= h;
        
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();

        int high = *max_element(piles.begin(), piles.end());

        int bananasPerHour = 0;
        
        int low = 1;
        
        while(low<=high){
            int mid = low + (high-low)/2;

            if(isPossibleToFinish(piles,h,mid)){
                 high = mid -1;
                 bananasPerHour = mid;
            }else{
                low = mid + 1;
            }
        }

        return bananasPerHour;
    }
};