#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>freq;
        int cnt = 0;

        for(int num:nums){
            int need = k - num;

            if(freq[need]>0){
               cnt++;
               freq[need]--;
            }else{
                freq[num]++;
            }
        }

        return cnt;

        
    }
};