#include "bits/stdc++.h"
using namespace std;


// Final Complexity

// Let

// M = modulus (100000)
// N = arr.size()
// Complexity	Value
// Time	O(M × N)
// Space	O(M)

class Solution {
  public:
    int minSteps(vector<int>& arr, int start, int end) {
        // code here
        
        if(start==end) return 0;
        
        int mod = 1000;
        
        queue<pair<int,int>>q;
        
        
        vector<int>distance(mod,INT_MAX);
        
        distance[start] = 0;
        
        q.push({0,start});
        
        
        while(!q.empty()){
            int step = q.front().first;
            int node = q.front().second;
            q.pop();
            
            if(node==end) return step;
            
            if(step>distance[node])
                continue;
            
            for(int i=0;i<arr.size();i++){
                int nextStep = step+1;
                int newVal = (node * arr[i])%mod;
                
                if(nextStep < distance[newVal]){
                    q.push({nextStep,newVal});
                
                    distance[newVal] = nextStep;
                }
                
           
            }
        }
        
        return -1;
    }
};