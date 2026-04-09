class Solution {
public:
    bool isPerfectSquare(int num) {
        long long low = 1, high = num -1;

        while(low<=high){
            long long mid = low + (high-low)/2;
            long long midAns = mid * mid;

            if(midAns==num){
                return true;
            }else if(midAns > num){
                 high = mid - 1;
            }else{
                 low = mid + 1;
            }
        }
        
        if(num==1) return true;

        return false;
    }
};