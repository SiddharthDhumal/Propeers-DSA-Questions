#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    bool isDistributionPossible(vector<int>& position,int m,int minDist){
        int lastPlaced  = position[0];
        int ballsPlaced = 1;

        for(int i=1;i<position.size();i++){
                if(position[i] - lastPlaced >= minDist){
                     ballsPlaced++;
                     lastPlaced  = position[i];

                     if(ballsPlaced >= m){
                         return true;
                     }
                }
        }

        return false;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());

        int low = 1;
        int high = position.back() - position.front();
        int answer = 0;



        while(low<=high){
            int mid = low + (high-low)/2;

            if(isDistributionPossible(position,m,mid)){
                 answer = mid;
                 low = mid + 1;
            }else{
                 high = mid - 1;
            }
        }

        return answer;
    }
};