#include <bits/stdc++.h>
using namespace std;

// TC - O(n) and SC - O(1)
class Solution {
private:
    bool isVowel(char& ch){
        if(ch=='a'||ch=='e' || ch=='i' || ch=='o' || ch=='u'){
             return true;
        }

        return false;
    }
public:
    int maxVowels(string s, int k) {
        int ans = 0;
        int i = 0, j = i;
        int n = s.size();
        int cnt = 0;
        for(int j =0;j<n;j++){

            if(isVowel(s[j]))
               cnt++;
            
            if(j-i+1==k){
                ans = max(ans,cnt);

                if(isVowel(s[i])){
                     cnt--;
                }
                i++;
            }
        }

        return ans;
    }
};