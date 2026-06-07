#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        if(n<3) return 0;
        int i = 1;
        int start = 0, end = 0;
        int maxSubArray = 0;
        while(i<n-1){
            if(arr[i]>arr[i+1] && arr[i]>arr[i-1]){
                int j = i;
                while(j>0 && arr[j]>arr[j-1]){
                    j--;
                }
                
                start = j;
                j = i;
                while(j<n-1 && arr[j]>arr[j+1]){
                    j++;
                }
                end = j;
                maxSubArray = max(end-start+1,maxSubArray);
                i = end + 1;
            }else{
                i++;
            }
        }

        return  maxSubArray; 
        
    }
};