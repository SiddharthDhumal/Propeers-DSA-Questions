#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
          int n = asteroids.size();
          stack<int>st;

          for(int i=0;i<n;i++){
              int curr = asteroids[i];
              bool destroyed = false;
              while(!st.empty() && st.top()>0 && curr<0){
                  if(abs(st.top()) < abs(curr)){
                      st.pop();
                      continue;
                  }else if(abs(st.top())==abs(curr)){
                      st.pop();
                  }

                  destroyed = true;
                  break;
              }

              if(!destroyed){
                  st.push(curr);
              }
          }

          vector<int>result(st.size());
          for(int i=st.size()-1;i>=0;i--){
               result[i] = st.top();
               st.pop();
          }

          return result;
    }
};