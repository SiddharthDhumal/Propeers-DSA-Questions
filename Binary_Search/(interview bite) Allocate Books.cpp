#include "bits/stdc++.h"
using namespace std;

bool maxPagesCanbeAllocated(vector<int>& A,int B,int mid){
    int studentsAllocated = 1;
    int pagesPerStudent = 0;
    
    for(int i=0;i<A.size();i++){
        
        
        
        if(pagesPerStudent + A[i]> mid){
            studentsAllocated++;
            pagesPerStudent = A[i];
        }else{
            pagesPerStudent += A[i];
        }
    }
    
    return studentsAllocated <=B;
} 


int books(vector<int> &A, int B) {
    
    if(B>A.size())
       return -1;
    
    int low = *max_element(A.begin(), A.end());
    int high = accumulate(A.begin(), A.end(), 0);
    int result = 0;
    
    while(low<=high){
        int mid = low + (high-low)/2;
        
        if(maxPagesCanbeAllocated(A,B,mid)){
             result = mid;
             high = mid - 1;
        }else{
             low = mid + 1;
        }
    }
    
    return result;
}
 



