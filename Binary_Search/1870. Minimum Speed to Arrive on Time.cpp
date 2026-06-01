#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    bool isSpeedPossible(vector<int>& dist,double hour, int speed){
         double possibleHrs = 0.0;
         
         // all except last train
         for(int i=0;i<dist.size()-1;i++){
             possibleHrs += ceil((double)dist[i]/speed);
         }

         // last train
         possibleHrs += (double)dist.back()/speed;

         return possibleHrs <= hour;
    }

    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();
        int low = 1;
        int high = 1e7;
        
        int possibleSpeed = -1;

        while(low<=high){
           int mid = low + (high-low)/2;

           if(isSpeedPossible(dist,hour,mid)){
              possibleSpeed = mid;
              high = mid -1;
           }else{
              low = mid + 1;
           }
        }

        return possibleSpeed;
    }
};